// OpenGl
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// classes
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "ErrorChecker.h"
// glm
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>
// stb_image
#include "stb_image.h"
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

// screen
int SCR_WIDTH = 640;
int SCR_HEIGHT = 480;
// camera
glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 20.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
float pitch = 0.0f;
float yaw = -90.0f;
//float roll = 0.0f;
float theta = 45;
float phi = 45;
// mouse button is pressed first time
bool firstPressed = true;
// cursor position
float lastX = float(SCR_WIDTH) / 2.0f;
float lastY = float(SCR_HEIGHT) / 2.0f;
// frame time
float deltaTime = 0.0f;
float lastFrame = 0.0f;
// scaling
float fov = 45.0f;
// projection mode
bool perspective = false;
// move mode
bool move = false;

float func(float x, float y)
{
    return sinf(y) * sqrtf(x);
}

std::vector<glm::vec3> drawSphere(float fRadius, int iSlices, int iStacks)
{
    std::vector<glm::vec3> verte_sa;
    float drho = (float)(3.141592653589) / (GLfloat) iStacks;
    float dtheta = 2.0f * (GLfloat)(3.141592653589) / (GLfloat) iSlices;
    float ds = 1.0f / (GLfloat) iSlices;
    float dt = 1.0f / (GLfloat) iStacks;
    float t = 1.0f;
    float s = 0.0f;
    int i, j;

    for (i = 0; i < iStacks; i++)
    {
        GLfloat rho = (GLfloat)i * drho;
        float srho = sinf(rho);
        float crho = cosf(rho);
        float srhodrho = sinf(rho + drho);
        float crhodrho = cosf(rho + drho);

        s = 0.0f;
        for ( j = 0; j <= iSlices; j++)
        {
            float ltheta = (j == iSlices) ? 0.0f : j * dtheta;
            float stheta = -sinf(ltheta);
            float ctheta = cosf(ltheta);

            GLfloat x = stheta * srho;
            GLfloat y = ctheta * srho;
            GLfloat z = crho;

            verte_sa.emplace_back(glm::vec3(x * fRadius, y * fRadius, z * fRadius));
            verte_sa.emplace_back(glm::normalize(glm::vec3(x * fRadius, y * fRadius, z * fRadius)));

            x = stheta * srhodrho;
            y = ctheta * srhodrho;
            z = crhodrho;
            s += ds;

            verte_sa.emplace_back(glm::vec3(x * fRadius, y * fRadius, z * fRadius));
            verte_sa.emplace_back(glm::normalize(glm::vec3(x * fRadius, y * fRadius, z * fRadius)));
        }
        t -= dt;
    }

    return verte_sa;
}

std::vector<glm::vec3> drawSurface(float step)
{
    std::vector<glm::vec3> vertices;
    float min = -10.0f, max = 10.0f;
    float x = min, z = min;
    float y;

    while (x <= max)
    {
        z = min;
        while (z <= max)
        {
            y = func(z, x);
            vertices.emplace_back(glm::vec3(x, y, z));
            y = func(z, x + step);
            vertices.emplace_back(glm::vec3(x + step, y, z));
            z += step;
        }

        x += step;
    }

    return vertices;
}

std::vector<glm::vec3> drawTorus(float majorRadius, float minorRadius, int numMajor, int numMinor)
{
    std::vector<glm::vec3> vertices;
    float majorStep = 2.0f * 3.141592653589 / numMajor;
    float minorStep = 2.0f * 3.141592653589 / numMinor;
    float a0, a1, x0, x1, y0, y1, b, c, r, z;
    int i, j;

    for (i = 0; i < numMajor; ++i)
    {
        a0 = float(i) * majorStep;
        a1 = a0 + majorStep;
        x0 = cosf(a0);
        y0 = sinf(a0);
        x1 = cosf(a1);
        y1 = sinf(a1);

        for (j = 0; j <= numMinor; ++j)
        {
            b = float(j) * minorStep;
            c = (GLfloat) cosf(b);
            r = minorRadius * c + majorRadius;
            z = minorRadius * (GLfloat) sinf(b);

            vertices.emplace_back(glm::vec3(x0*r, y0*r, z));
            vertices.emplace_back(glm::vec3(x1*r, y1*r, z));
        }
    }

    return vertices;
}

int main() {
    // glfw init
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // create window
    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Solar system", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    // callback functions
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetKeyCallback(window, key_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad init
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // init models
    GLCall(glEnable(GL_DEPTH_TEST););
    GLCall(glEnable(GL_LINE_SMOOTH););
    GLCall(glLineWidth(4););

    // spheres
    VertexArray EarthVAO, SunVAO;
    EarthVAO.Unbind();
    SunVAO.Unbind();

    static std::vector<glm::vec3> spherePos;
    const float radius = 1.0f;
    spherePos = drawSphere(radius, int(30 * radius), int(30 * radius));
    VertexBuffer sphereVBO(&spherePos[0], spherePos.size() * sizeof(glm::vec3));

    EarthVAO.Bind();
    {
        // use 2 properties (coordinates and normals)
        GLCall( glEnableVertexAttribArray(0); );
        GLCall( glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*) 0); );
        GLCall( glEnableVertexAttribArray(1); );
        GLCall( glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*) (3*sizeof(float))); );
    }
    EarthVAO.Unbind();

    SunVAO.Bind();
    {
        // use only coordinates, so step
        GLCall( glEnableVertexAttribArray(0); );
        GLCall( glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*) 0); );
    }
    SunVAO.Unbind();

    sphereVBO.Unbind();

    // read and create shader
    ShaderProgramSource source1 = ParseShader("../res/Earth.shader");
    std::cout << "VERTEX 1" << std::endl << source1.VertexSource << std::endl;
    std::cout << "FRAGMENT 1" << std::endl << source1.FragmentSource << std::endl;
    unsigned int EarthShader = CreateShader(source1.VertexSource, source1.FragmentSource);

    // read and create shader
    ShaderProgramSource source2 = ParseShader("../res/Sun.shader");
    std::cout << "VERTEX 2" << std::endl << source2.VertexSource << std::endl;
    std::cout << "FRAGMENT 2" << std::endl << source2.FragmentSource << std::endl;
    unsigned int SunShader = CreateShader(source2.VertexSource, source2.FragmentSource);

    // uniforms
    unsigned int projectionLoc;
    unsigned int viewPosLoc;
    unsigned int viewLoc;
    unsigned int modelLoc;
    unsigned int ourColorLoc;
    unsigned int lightColorLoc;
    unsigned int lightPosLoc;

    // bind shader for 1 time
    GLCall( glUseProgram(EarthShader) );
    GLCall( glUseProgram(0) );
    float EarthRotationAngle = 0.0f;

    glm::vec3 lightColor(1.0f);

    // render loop
    while (!glfwWindowShouldClose(window))
    {
        // use time for 1 frame for static camera speed
        auto currentFrame = float(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        // input
        processInput(window);

        // render
        GLCall(glClearColor(0.12f, 0.08f, 0.11f, 1.0f); );
        GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); );

        // transform matrix depends on projection type
        // projection matrix is one for all shaders
        glm::mat4 projection = glm::mat4(1.0f);
        float len = move ? glm::length(cameraPos - glm::vec3(0.0f, 0.0f, 0.0f)) : 20.0f;
        if (perspective) {
            projection = glm::perspective(glm::radians(fov),
                                          (float) SCR_WIDTH / (float) SCR_HEIGHT,
                                          0.1f,
                                          100.0f );
        } else {
            float coef = float(SCR_WIDTH)/float(SCR_HEIGHT);
            projection = glm::ortho(-len*coef, len*coef, -len, len, -100.f, 100.f);
        }

        // view matrix depends on move type
        // view matrix is one for all shaders
        glm::mat4 view;

        if (!move) {
            float camZ = len*sinf(glm::radians(float(theta)))*cosf(glm::radians(float(phi)));
            float camX = len*sinf(glm::radians(float(theta)))*sinf(glm::radians(float(phi)));
            float camY = len*cosf(glm::radians(float(theta)));
            float upY = (theta >= 180) ? -1.0f : 1.0f;
            view = glm::lookAt(glm::vec3(camX, camY, camZ),
                               glm::vec3(0.0f, 0.0f, 0.0f),
                               glm::vec3(0.0f, upY, 0.0f) );
        }
        else {
            view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
        }

        // one VBO for all objects
        sphereVBO.Bind();
        {
            glm::vec3 lightPos(0.0f, 0.0f, 0.0f);
            // use Sun shader
            GLCall(glUseProgram(SunShader););
            {
                // push changes to shader
                projectionLoc = glGetUniformLocation(SunShader, "projection");
                modelLoc = glGetUniformLocation(SunShader, "model");
                viewLoc = glGetUniformLocation(SunShader, "view");
                lightColorLoc = glGetUniformLocation(SunShader, "lightColor");

                GLCall(glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection)); );
                GLCall(glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view)); );

                SunVAO.Bind();
                {
                    glm::mat4 model = glm::mat4(1.0f);
                    model = glm::scale(model, glm::vec3(5.0f));
                    model = glm::translate(model, lightPos);
                    GLCall(glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model)); );

                    GLCall(glUniform3f(lightColorLoc, 1.0f, 1.0f, 1.0f); );
                    GLCall(glDrawArrays(GL_TRIANGLE_STRIP, 0, (spherePos.size() / 2)); );
                }
                SunVAO.Unbind();
            }

            // use Earth shader
            GLCall(glUseProgram(EarthShader););
            {
                // push changes to shader
                projectionLoc = glGetUniformLocation(EarthShader, "projection");
                modelLoc = glGetUniformLocation(EarthShader, "model");
                viewLoc = glGetUniformLocation(EarthShader, "view");
                ourColorLoc = glGetUniformLocation(EarthShader, "ourColor");
                lightColorLoc = glGetUniformLocation(EarthShader, "lightColor");
                lightPosLoc = glGetUniformLocation(EarthShader, "lightPos");
                viewPosLoc = glGetUniformLocation(EarthShader, "viewPos");

                // set projection and view to shader
                GLCall(glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection)); );
                GLCall(glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view)); );
                // GLCall(glUniform3fv(viewPosLoc, 1, glm::value_ptr(glm::normalize(lightPos))); );

                // set light pos and color
                GLCall(glUniform3fv(lightColorLoc, 1, glm::value_ptr(lightColor)); );
                GLCall(glUniform3fv(lightPosLoc, 1, glm::value_ptr(lightPos)); );

                // Earth correction
                float EarthRadius = 20.0f;
//                glm::vec3 EarthPos(EarthRadius*sin(glfwGetTime()), 0.0f, EarthRadius*cos(glfwGetTime()));
                glm::vec3 EarthPos(EarthRadius, glm::vec2(0.0f));
                EarthRotationAngle += 50.0f*deltaTime;

                EarthVAO.Bind();
                {
                    glm::mat4 model = glm::mat4(1.0f);
                    model = glm::rotate(model, glm::radians(EarthRotationAngle), glm::normalize(glm::vec3(EarthPos.x, 1.0, EarthPos.z))); // glm::vec3(0.0f, 1.0f, 0.0f));
                    model = glm::translate(model, EarthPos);
                    GLCall(glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model)); );
                    GLCall(glUniform3f(ourColorLoc, 0.3f, 0.5f, 0.5f); );

                    GLCall(glDrawArrays(GL_TRIANGLE_STRIP, 0, (spherePos.size() / 2)); );
                }
                EarthVAO.Unbind();
            }
        }
        sphereVBO.Unbind();

        GLCall( glUseProgram(0) );

        glfwSwapBuffers(window);
        glfwPollEvents();

        lastFrame = currentFrame;
    }

    // glfw end
    glfwTerminate();

    return 0;
}

void recalculateCameraPos() {
    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(direction);
}

void processInput(GLFWwindow *window)
{
    float moveCameraSpeed = 5.0f*deltaTime;
    float rotateCameraSpeed = 100.0f*deltaTime;
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        theta = fmod((theta - rotateCameraSpeed + 360.0f), 360.0f);
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        theta = fmod((theta + rotateCameraSpeed), 360.0f);
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        phi = fmod((phi - rotateCameraSpeed), 360.0f);
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        phi = fmod((phi + rotateCameraSpeed), 360.0f);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPos += moveCameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPos -= moveCameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * moveCameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * moveCameraSpeed;

    recalculateCameraPos();

    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
        perspective = true;
    if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
        perspective = false;
    if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
        move = !move;
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstPressed)
    {
        lastX = float(xpos);
        lastY = float(ypos);
        firstPressed = false;
    }
    float sensitivity = 0.05f;
    float deltaX = float(xpos) - lastX;
    float deltaY = lastY - float(ypos);
    lastX = float(xpos);
    lastY = float(ypos);

    pitch += deltaY*sensitivity;
    yaw += deltaX*sensitivity;

    if(pitch > 89.0f)
        pitch = 89.0f;
    if(pitch < -89.0f)
        pitch = -89.0f;

    recalculateCameraPos();
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    if (fov >= 1.0f && fov <= 45.0f)
        fov -= float(yoffset);
    if (fov <= 1.0f)
        fov = 1.0f;
    if (fov >= 45.0f)
        fov = 45.0f;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    SCR_HEIGHT = height;
    SCR_WIDTH = width;
    glViewport(0, 0, width, height);
}

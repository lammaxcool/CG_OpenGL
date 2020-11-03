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

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

// screen
unsigned int SCR_WIDTH = 1920;
unsigned int SCR_HEIGHT = 1080;
// camera
glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 20.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
float pitch = 0.0f;
float yaw = -90.0f;
//float roll = 0.0f;
int theta = 45;
int phi = 45;
// mouse button is pressed first time
bool firstPressed = true;
// cursor position
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
// frame time
float deltaTime = 0.0f;
float lastFrame = 0.0f;
// scaling
float fov = 89.0f;
// projection mode
bool perspective = true;
// move mode
bool move = false;

float func(float x, float y)
{
    return sinf(y) * sqrtf(x);
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

            vertices.push_back(glm::vec3(x0*r, y0*r, z));
            vertices.push_back(glm::vec3(x1*r, y1*r, z));
        }
    }

    return vertices;
}

int main()
{
    // glfw init
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // create window
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "3D", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    // callback functions
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad init
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // init models
    GLCall( glEnable(GL_DEPTH_TEST); );
    GLCall( glEnable(GL_LINE_SMOOTH); );
    GLCall( glLineWidth(4); );

    // cube
    float cubePositions[] = {
            -5.0f, -5.0f, -5.0f,  // 1
             5.0f, -5.0f, -5.0f,  // 2
             5.0f,  5.0f, -5.0f,  // 3
            -5.0f,  5.0f, -5.0f,  // 4

            -5.0f, -5.0f,  5.0f,  // 5
             5.0f, -5.0f,  5.0f,  // 6
             5.0f,  5.0f,  5.0f,  // 7
            -5.0f,  5.0f,  5.0f,  // 8
    };

    unsigned int cubeIndices[] = {
            // cube indices
            0, 1, 2,
            2, 3, 0,

            4, 5, 6,
            6, 7, 4,

            5, 1, 2,
            2, 6, 5,

            0, 4, 7,
            7, 3, 0,

            7, 6, 2,
            2, 3, 7,

            0, 2, 5,
            5, 4, 0,

            // line indices
            0, 1, 1, 2, 2, 3, 3, 0,

            4, 5, 5, 6, 6, 7, 7, 4,

            5, 1, 1, 2, 2, 6, 6, 5,

            4, 0, 0, 3, 3, 7, 7, 4,

            0, 1, 1, 5, 5, 4, 4, 0,

            3, 2, 2, 6, 6, 7, 7, 3
    };

    VertexArray cubeVa;
    VertexBuffer cubeVb(cubePositions, 6 * 6 * 3 * sizeof(float));
    IndexBuffer ib(cubeIndices, 6*6 + 6*8);
    GLCall( glEnableVertexAttribArray(0); );
    GLCall( glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL); );
    cubeVa.Unbind();

    VertexArray torusVa;
    std::vector<glm::vec3> torusPositions;
    torusPositions = drawTorus(5.0f, 3.0f, 40, 20);
    VertexBuffer torusVb( &torusPositions[0], torusPositions.size()*sizeof(glm::vec3) );
    GLCall( glEnableVertexAttribArray(0); );
    GLCall( glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL); );
    torusVa.Unbind();

    VertexArray surfaceVa;
    std::vector<glm::vec3> surfacePositions;
    surfacePositions = drawSurface(0.1f);
    VertexBuffer surfaceVb(&surfacePositions[0], surfacePositions.size()*sizeof(glm::vec3));
    GLCall( glEnableVertexAttribArray(0); );
    GLCall( glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL); );
    surfaceVa.Unbind();

    ShaderProgramSource source = ParseShader("../res/shader1.shader");
    std::cout << "VERTEX" << std::endl << source.VertexSource << std::endl;
    std::cout << "FRAGMENT" << std::endl << source.FragmentSource << std::endl;
    unsigned int shader = CreateShader(source.VertexSource, source.FragmentSource);

    // uniforms
    unsigned int projectionLoc;
    unsigned int viewLoc;
    unsigned int modelLoc;
    unsigned int ourColorLoc;

    GLCall( glUseProgram(shader) );
    GLCall( glUseProgram(0) );

    // render loop
    while (!glfwWindowShouldClose(window))
    {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        // input
        processInput(window);

        // use shader
        GLCall( glUseProgram(shader); );

        // transform
        glm::mat4 projection = glm::mat4(1.0f);

        float len = move ? glm::length(cameraPos - glm::vec3(0.0f, 0.0f, 0.0f)) : 20.0f;

        if (perspective) {
            projection = glm::perspective(glm::radians(fov), (float) SCR_WIDTH / (float) SCR_HEIGHT, 0.1f, 100.0f);
        }
        else {
            float coef = float(SCR_WIDTH)/float(SCR_HEIGHT);
            projection = glm::ortho(-len*coef, len*coef, -len, len, -100.f, 100.f);
        }
        glm::mat4 view;
        if (!move) {
            float camZ = len*sinf(glm::radians(float(theta)))*cosf(glm::radians(float(phi)));
            float camX = len*sinf(glm::radians(float(theta)))*sinf(glm::radians(float(phi)));
            float camY = len*cosf(glm::radians(float(theta)));
            float upY = (theta >= 180) ? -1.0f : 1.0f;
            view = glm::lookAt(glm::vec3(camX, camY, camZ),
                                         glm::vec3(0.0f, 0.0f, 0.0f),
                                         glm::vec3(0.0f, upY, 0.0f));
        }
        else {
            view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
        }
        // push changes to shader
        projectionLoc = glGetUniformLocation(shader, "projection");
        modelLoc = glGetUniformLocation(shader, "model");
        viewLoc = glGetUniformLocation(shader, "view");
        GLCall( glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection)); );
        GLCall( glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view)); );

        // render
        GLCall( glClearColor(0.2f, 0.3f, 0.3f, 1.0f); );
        GLCall( glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); );
        ourColorLoc = glGetUniformLocation(shader, "ourColor");

        cubeVa.Bind();
        {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3( 0.0f, 10.0f, 0.0f));
            GLCall( glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model)); );
            GLCall( glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); );
            // red
            GLCall( glUniform3f(ourColorLoc, 0.5, 0.0, 0.0););
            GLCall( glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, NULL););
            // black
            GLCall( glUniform3f(ourColorLoc, 0.0, 0.0, 0.0););
            GLCall( glDrawElements(GL_LINES, 48, GL_UNSIGNED_INT, (void *) (6 * 6 * sizeof(unsigned int))););
        }
        cubeVa.Unbind();

        torusVa.Bind();
        {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3( 0.0f, -10.0f, 0.0f));
            GLCall( glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model)); );
            // green
            GLCall( glUniform3f(ourColorLoc, 0.0f, 0.5f, 0.0f););
            GLCall( glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); );
            GLCall( glDrawArrays(GL_TRIANGLE_STRIP, 0, torusPositions.size()); );
            // black
            GLCall( glUniform3f(ourColorLoc, 0.0f, 0.0f, 0.0f););
            GLCall( glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); );
            GLCall( glDrawArrays(GL_TRIANGLE_STRIP, 0, torusPositions.size()); );
        }
        torusVa.Unbind();

        surfaceVa.Bind();
        {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3( 0.0f, 0.0f, 0.0f));
            GLCall( glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model)); );
            // green
            GLCall( glUniform3f(ourColorLoc, 0.0f, 0.0f, 0.5f););
            GLCall( glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); );
            GLCall( glDrawArrays(GL_TRIANGLE_STRIP, 0, surfacePositions.size()); );
            // black
            GLCall( glUniform3f(ourColorLoc, 0.0f, 0.0f, 0.0f););
            GLCall( glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); );
            GLCall( glDrawArrays(GL_TRIANGLE_STRIP, 0, surfacePositions.size()); );
        }
        surfaceVa.Unbind();

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
    int rotateCameraSpeed = 5;
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        theta = (theta - rotateCameraSpeed + 360) % 360;
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        theta = (theta + rotateCameraSpeed) % 360;
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        phi = (phi - rotateCameraSpeed) % 360;
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        phi = (phi + rotateCameraSpeed) % 360;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPos += moveCameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPos -= moveCameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * moveCameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * moveCameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
        perspective = true;
    if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
        perspective = false;
    if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
        move = !move;

    recalculateCameraPos();

    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
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

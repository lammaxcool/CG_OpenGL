#shader vertex
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
// layout (location = 2) in vec2 aTexCoord;

out vec3 FragPos;
out vec3 Normal;
// out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    FragPos = vec3(model * vec4(aPos, 1.0));
    Normal = mat3(transpose(inverse(model))) * aNormal;
    // Normal = aNormal;
    // TexCoord = aTexCoord;
    gl_Position = projection * view * model * vec4(aPos, 1.0);
};

#shader fragment
#version 330 core
out vec4 FragColor;

in vec3 Normal;
in vec3 FragPos;
// in vec2 TexCoord;

uniform vec3 lightPos;
// uniform vec3 viewPos;
uniform vec3 ourColor;
uniform vec3 lightColor;

void main()
{
    // ambient
    float ambientStrength = 0.4;
    vec3 ambient = ambientStrength * lightColor;

    // diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

//     // specular
//     float specularStrength = 0.5;
//     vec3 viewDir = normalize(viewPos - FragPos);
//     vec3 reflectDir = reflect(-lightDir, norm);
//     float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
//     vec3 specular = specularStrength * spec * lightColor;

//     vec3 result = (ambient + diffuse + specular) * ourColor;
    vec3 result = (ambient + diffuse) * ourColor;

    FragColor = vec4(result, 1.0);
};
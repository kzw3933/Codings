#version 330 core

struct Material {
   sampler2D diffuse;
   sampler2D specular;
   float shininess;
};

uniform Material material;

struct DirLight {
   vec3 direction;
   vec3 ambient;
   vec3 diffuse;
   vec3 specular;
};

uniform DirLight dirLight;
vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir);

struct PointLight {
   vec3 position;
   
   float constant;
   float linear;
   float quadratic;

   vec3 ambient;
   vec3 diffuse;
   vec3 specular;
};

#define NR_POINT_LIGHTS 4
uniform PointLight pointLights[NR_POINT_LIGHTS];

vec3 CalcPointLight(PointLight light, vec3 normal, vec3 viewDir);

struct SpotLight {
   vec3 position;
   vec3 direction;
   float cutOff;
   float outerCutOff;

   float constant;
   float linear;
   float quadratic;

   vec3 ambient;
   vec3 diffuse;
   vec3 specular;
};

uniform SpotLight spotLight;
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 viewDir);

in vec2 TexCoords;
in vec3 Normal;
in vec3 FragPos;

out vec4 FragColor;
uniform vec3 viewPos;

void main() {
   // 定义一个输出颜色值
   vec3 result = vec3(0.0f, 0.0f, 0.0f);
   vec3 normal = normalize(Normal);
   vec3 viewDir = normalize(viewPos - FragPos);
   // 将定向光的贡献加到输出中
   result += CalcDirLight(dirLight, normal, viewDir);
   for(int i = 0; i < NR_POINT_LIGHTS; i++) {
      // 将所有点光源的输出加到输出中
      result += CalcPointLight(pointLights[i], normal, viewDir);
   }
   // 也加上其他的光源(比如聚光)
   result += CalcSpotLight(spotLight, normal, viewDir);
   FragColor = vec4(result, 1.0f);
}



vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir) {
   vec3 lightDir = normalize(-light.direction);
   // 漫反射着色
   float diff = max(dot(normal, lightDir), 0.0);
   // 镜面光着色
   vec3 reflectDir = reflect(-lightDir, normal);
   float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
   // 合并结果
   vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));
   vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));
   vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));

   return ambient + diffuse + specular;
}

vec3 CalcPointLight(PointLight light, vec3 normal, vec3 viewDir) {
   vec3 lightDir = normalize(light.position - FragPos);
   // 漫反射着色
   float diff = max(dot(normal, lightDir), 0.0);
   // 镜面光着色
   vec3 reflectDir = reflect(-lightDir, normal);
   float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
   // 衰减
   float distance = length(light.position - FragPos);
   float attenuation = 1.0 / (light.constant + light.linear*distance + light.quadratic * distance * distance);
   vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));
   vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));
   vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));

   ambient *= attenuation;
   diffuse *= attenuation;
   specular *= attenuation;

   return ambient + diffuse + specular;
}


vec3 CalcSpotLight(SpotLight light, vec3 normal,vec3 viewDir) {
   vec3 lightDir = normalize(light.position - FragPos);
   // 漫反射着色
   float diff = max(dot(normal, lightDir), 0.0);
   // 镜面光着色
   vec3 reflectDir = reflect(-lightDir, normal);
   float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
   // 衰减
   float distance = length(light.position - FragPos);
   float attenuation = 1.0 / (light.constant + light.linear*distance + light.quadratic * distance * distance);
   vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));
   vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));
   vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));

   ambient *= attenuation;
   diffuse *= attenuation;
   specular *= attenuation;

   float theta = dot(lightDir, normalize(-light.direction));
   float epsilon = light.cutOff - light.outerCutOff;
   float intensity = clamp((theta - light.outerCutOff)/epsilon, 0.0, 1.0);

   diffuse *= intensity;
   specular *= intensity;

   return ambient + diffuse + specular;

}
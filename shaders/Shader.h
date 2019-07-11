#pragma once
#include <GL\glew.h>
#include <string>
#include <fstream>
#include <iostream>

enum class ShaderParams {shader_type, delete_status, compile_status};

class Shader
{
  public:
    uint shader_id;
    int status;
    std::string shader_code;
    std::string log_info;
    std::string file_name;

    Shader();
    void loadShaderCode(const std::string &filename);
    void initShader();

    void checkStatus(const ShaderParams& p = compile_status);

    void print_status() const;
    ~Shader();
};

#include "Shader.h"

Shader::Shader() {
  shader_code = "";
  shader_id = 0;
  status = 1;
  log_info = "";
}

void Shader::loadShaderCode(string filename) {
  file_name = filename;
  ifstream is(filename);
  string tmp;
  while (getline(is, tmp))
    shader_code += tmp + "\n";
  is.close();
}

void Shader::initShader() {
  const GLchar *str = shader_code.c_str();
  glShaderSource(shader_id, 1, &str, NULL);
  glCompileShader(shader_id);
}

void Shader::checkStatus() {
  GLchar *loginfo;
  glGetShaderiv(shader_id, GL_COMPILE_STATUS, &status);
  if (!status) {
    int length = 0;
    glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &length);
    if (length) {
      loginfo = new GLchar[length];
      glGetShaderInfoLog(shader_id, length, NULL, loginfo);
      log_info = loginfo;
      delete[] loginfo;
    }
  };
}

void Shader::printStatus() const {
  if (!log_info.empty()) {
    cout << "Log in  " << file_name << endl << log_info << endl;
  }
}

Shader::~Shader() { glDeleteShader(shader_id); }

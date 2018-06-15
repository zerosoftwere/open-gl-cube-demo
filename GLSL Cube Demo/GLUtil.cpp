#include "GLUtil.h"

void ShaderCompileCheck(GLuint id)
{
	GLint result = GL_FALSE;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		GLchar error[256];
		glGetShaderInfoLog(id, sizeof(error), 0, error);
		MessageBox(NULL, error, "Shader Error", MB_OK);
	}
}

void ShaderLinkCheck(GLuint id)
{
	GLint  result = GL_FALSE;
	GLchar error[256];
	glGetProgramiv(id, GL_LINK_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(id, sizeof(error), 0, error);
		MessageBox(NULL, error, "Program Error", MB_OK);
	}

	glValidateProgram(id);
	glGetProgramiv(id, GL_VALIDATE_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(id, sizeof(error), 0, error);
		MessageBox(NULL, error, "Program Error", MB_OK);
	}

	GLint attrCount, uniCount, varyCount;
	glGetProgramiv(id, GL_ACTIVE_ATTRIBUTES, &attrCount);
	glGetProgramiv(id, GL_ACTIVE_UNIFORMS, &uniCount);

	std::ostringstream out;
	out.precision(6);
	out << "Attribute Count: " << attrCount << std::endl;
	out << "Uniform   Count: " << uniCount << std::endl;
	OutputDebugString(out.str().c_str());
}

GLuint LoadShaders(const char* vert, const char* frag)
{
	GLuint progID = glCreateProgram();
	GLuint vertID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragID = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertID, 1, &vert, 0);
	glCompileShader(vertID);
	ShaderCompileCheck(vertID);
	glAttachShader(progID, vertID);

	glShaderSource(fragID, 1, &frag, 0);
	glCompileShader(fragID);
	ShaderCompileCheck(fragID);
	glAttachShader(progID, fragID);

	glLinkProgram(progID);
	ShaderLinkCheck(progID);

	glDetachShader(progID, fragID);
	glDetachShader(progID, vertID);
	glDeleteShader(fragID);
	glDeleteShader(vertID);

	return progID;
}
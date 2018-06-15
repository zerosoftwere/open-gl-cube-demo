#pragma once
#include <glm/glm.hpp>

using namespace glm;

struct VertexPos
{
	VertexPos()
		: pos(0.0f, 0.0f, 0.0f) { }
	VertexPos(float x, float y, float z)
		: pos(x, y, z) { }
	VertexPos(const vec3& pos) 
		: pos(pos) { }

	vec3 pos;
};

struct VertexCol
{
	VertexCol()
		: pos(0.0f, 0.0f, 0.0f), col(1.0f, 0.0f, 0.0f, 1.0f) { }
	VertexCol(float x, float y, float z, float r, float g, float b, float a) 
		: pos(x, y, z), col(r, g, b, a) { }
	VertexCol(const vec3& pos, const vec4& col) : pos(pos), col(col) { }

	vec3 pos;
	vec4 col;
};
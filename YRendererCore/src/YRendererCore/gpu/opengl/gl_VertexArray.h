#pragma once

#include<glad/gl.h> 
#include "gl_VertexBuffer.h"
#include "gl_VertexBufferLayout.h"

class VertexArray
{
private:
	unsigned int va_ID;
public:
	VertexArray();
	~VertexArray();

	void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

	void Bind() const;
	void Unbind() const;
};


#pragma once

#include<glad/gl.h> 
#include "gl_VertexBuffer.h"
#include "gl_VertexBufferLayout.h"


namespace YRenderer {
	
	class VertexArray
	{
	private:
		GLuint va_ID;
	public:
		VertexArray();
		~VertexArray();

		void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
		operator GLuint() const;

		void Bind() const;
		void Unbind() const;
	};

}
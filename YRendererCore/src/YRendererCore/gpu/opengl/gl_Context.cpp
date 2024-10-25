#if 0
#include "gl_Context.h"
//#include <GL/GL/Extensions.hpp>

namespace YRenderer
{
	void Context::Enable( Capability::capability_t capability )
	{
		glEnable( capability );
	}

	void Context::Disable( Capability::capability_t capability )
	{
		glDisable( capability );
	}

	void Context::ClearColor( const glm::vec4 color_v)
	{
		glClearColor(color_v.x, color_v.y, color_v.z, color_v.w );
	}

	void Context::Clear( Buffer::buffer_t buffers )
	{
		glClear( buffers );
	}

	void Context::DepthMask( bool writeEnabled )
	{
		glDepthMask( writeEnabled ? GL_TRUE : GL_FALSE );
	}

	void Context::StencilMask( bool writeEnabled )
	{
		glStencilMask( writeEnabled ? ~0 : 0 );
	}

	void Context::StencilMask(unsigned int mask )
	{
		glStencilMask( mask );
	}

	void Context::StencilFunc( TestFunction::test_function_t function, int reference, unsigned int mask )
	{
		glStencilFunc( function, reference, mask );
	}

	void Context::StencilOp( StencilAction::stencil_action_t fail, StencilAction::stencil_action_t zfail, StencilAction::stencil_action_t pass )
	{
		glStencilOp( fail, zfail, pass );
	}

	void Context::UseProgram( const Program& program )
	{
		glUseProgram( program );
	}

	void Context::BindTexture( const Texture& texture, uchar unit )
	{
		glActiveTexture( GL_TEXTURE0 + unit );
		glBindTexture( GL_TEXTURE_2D, texture );
	}

	void Context::BindFramebuffer( const Framebuffer& framebuffer )
	{
		glBindFramebuffer( GL_DRAW_FRAMEBUFFER, framebuffer );
		
		// Set viewport to frame buffer size
		GLint obj, width, height;
		glGetFramebufferAttachmentParameteriv( GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME, &obj );

		GLint res; glGetIntegerv( GL_TEXTURE_BINDING_2D, &res );
			glBindTexture( GL_TEXTURE_2D, obj );
			glGetTexLevelParameteriv( GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &width );
			glGetTexLevelParameteriv( GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &height );
		glBindTexture( GL_TEXTURE_2D, res );

		glViewport( 0, 0, width, height );
	}

	void Context::BindFramebuffer()
	{
		glBindFramebuffer( GL_DRAW_FRAMEBUFFER, 0 );

		// Set viewport to default frame buffer size
		glViewport( defaultViewport[0], defaultViewport[1], defaultViewport[2], defaultViewport[3] );
	}

	void Context::BeginTransformFeedback( Primitive::primitive_t mode )
	{
		glBeginTransformFeedback( mode );
	}

	void Context::EndTransformFeedback()
	{
		glEndTransformFeedback();
	}

	void Context::DrawArrays( const VertexArray& vao, Primitive::primitive_t mode, uint offset, uint vertices )
	{
		glBindVertexArray( vao );
		glDrawArrays( mode, offset, vertices );
	}

	void Context::DrawElements( const VertexArray& vao, Primitive::primitive_t mode, intptr_t offset, uint count, uint type )
	{
		glBindVertexArray( vao );
		glDrawElements( mode, count, type, (const GLvoid*)offset );
	}

	Context Context::UseExistingContext()
	{
		return Context();
	}
}

#endif
// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/29 11:10)

#ifndef RENDERING_RENDERERS_OPENGL_VERTEX_BUFFER_H
#define RENDERING_RENDERERS_OPENGL_VERTEX_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/Detail/PlatformVertexBufferImpl.h"
#include "System/OpenGL/OpenGLAPI.h"

namespace Rendering
{
    class Renderer;
    class VertexBuffer; 

	class RENDERING_HIDDEN_DECLARE OpenGLVertexBuffer : public PlatformVertexBufferImpl
    {
	public:
		using ClassType = OpenGLVertexBuffer;
		using ParentType = PlatformVertexBufferImpl;
		using UInt = System::OpenGLUInt;

	public:
        OpenGLVertexBuffer (Renderer* renderer, const VertexBuffer* vertexBuffer);
          ~OpenGLVertexBuffer ();
		  OpenGLVertexBuffer(const OpenGLVertexBuffer&) =default;
		  OpenGLVertexBuffer& operator=(const OpenGLVertexBuffer&) =default;
		   OpenGLVertexBuffer( OpenGLVertexBuffer&&) =default;
		  OpenGLVertexBuffer& operator=( OpenGLVertexBuffer&&) =default;

	   CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

	    // ¶¥µã»º³åÇø²Ù×÷¡£
		  void Enable (Renderer* renderer, unsigned int vertexSize,unsigned int streamIndex, unsigned int offset) noexcept override;
		  void Disable (Renderer* renderer, unsigned int streamIndex) noexcept override;
		  void* Lock (BufferLocking mode) noexcept override;
		  void Unlock () noexcept override;
        
    private:
		void Init(const VertexBuffer* vertexBuffer);

    private:
        UInt m_Buffer;
    };
}

#endif // RENDERING_RENDERERS_OPENGL_VERTEX_BUFFER_H

// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/29 10:59)

#ifndef RENDERING_RENDERERS_OPENGL_INDEX_BUFFER_H
#define RENDERING_RENDERERS_OPENGL_INDEX_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "System/Windows/Using/WindowsUsing.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Renderers/Detail/PlatformIndexBufferImpl.h"

namespace Rendering
{
    class Renderer;
    class IndexBuffer;
    
	class RENDERING_HIDDEN_DECLARE OpenGLIndexBuffer : public PlatformIndexBufferImpl
    {
	public:
		using ClassType = OpenGLIndexBuffer;
		using ParentType = PlatformIndexBufferImpl;
		using UInt = System::OpenGLUInt;
        
	public:
        OpenGLIndexBuffer (Renderer* renderer,const IndexBuffer* indexBuffer);
          ~OpenGLIndexBuffer ();
		  OpenGLIndexBuffer(const OpenGLIndexBuffer&) = default;
		  OpenGLIndexBuffer& operator=(const OpenGLIndexBuffer&) = default;
		  OpenGLIndexBuffer(OpenGLIndexBuffer&&) = default;
		  OpenGLIndexBuffer& operator=(OpenGLIndexBuffer&&) = default;
        
        CLASS_INVARIANT_OVERRIDE_DECLARE;

		// »º³åÇø²Ù×÷
		 void Enable(Renderer* renderer) noexcept override;
		 void Disable(Renderer* renderer) noexcept override;
		 void* Lock(BufferLocking mode) noexcept override;
		 void Unlock() noexcept override;
        
    private:
		void Init(const IndexBuffer* indexBuffer);
        
    private:
        UInt m_Buffer;
    };
}

#endif // RENDERING_RENDERERS_OPENGL_INDEX_BUFFER_H

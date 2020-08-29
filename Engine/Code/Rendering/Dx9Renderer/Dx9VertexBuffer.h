// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/29 11:39)

#ifndef RENDERING_RENDERERS_DX9_VERTEX_BUFFER_H
#define RENDERING_RENDERERS_DX9_VERTEX_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/Detail/PlatformVertexBufferImpl.h"
#include "System/OpenGL/OpenGLAPI.h"

namespace Rendering
{
    class Renderer;
    class VertexBuffer; 

	class RENDERING_HIDDEN_DECLARE Dx9VertexBuffer : public PlatformVertexBufferImpl
    {
	public:
		using ClassType = Dx9VertexBuffer;
		using ParentType = PlatformVertexBufferImpl;
		using UInt = System::OpenGLUInt;

	public:
        Dx9VertexBuffer (Renderer* renderer,const VertexBuffer* vertexBuffer) noexcept;
 

	   CLASS_INVARIANT_OVERRIDE_DECLARE;

	    // ¶¥µã»º³åÇø²Ù×÷¡£
		 void Enable (Renderer* renderer, unsigned int vertexSize,unsigned int streamIndex, unsigned int offset) override;
		 void Disable (Renderer* renderer, unsigned int streamIndex) override;
		 void* Lock (BufferLocking mode) override;
		 void Unlock () override;
 
    };
}

#endif // RENDERING_RENDERERS_DX9_VERTEX_BUFFER_H


/*

#ifndef WM5DX9VERTEXBUFFER_H
#define WM5DX9VERTEXBUFFER_H

#include "Wm5Dx9RendererLIB.h"
#include "Wm5VertexBuffer.h"

namespace Wm5
{

class Renderer;

class PdrVertexBuffer
{
public:
    // Construction and destruction.
    PdrVertexBuffer (Renderer* renderer, const VertexBuffer* vbuffer);
    ~PdrVertexBuffer ();

    // Vertex buffer operations.
    void Enable (Renderer* renderer, unsigned int vertexSize,
        unsigned int streamIndex, unsigned int offset);
    void Disable (Renderer* renderer, unsigned int streamIndex);
    void* Lock (Buffer::Locking mode);
    void Unlock ();

private:
    IDirect3DVertexBuffer9* mBuffer;
};

}

#endif
*/
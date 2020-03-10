// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/29 11:10)

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
        virtual ~OpenGLVertexBuffer ();

	   CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

	    // ���㻺����������
		virtual void Enable (Renderer* renderer, unsigned int vertexSize,unsigned int streamIndex, unsigned int offset) override;
		virtual void Disable (Renderer* renderer, unsigned int streamIndex) override;
		virtual void* Lock (BufferLocking mode) override;
		virtual void Unlock () override;
        
    private:
		void Init(const VertexBuffer* vertexBuffer);

    private:
        UInt m_Buffer;
    };
}

#endif // RENDERING_RENDERERS_OPENGL_VERTEX_BUFFER_H

// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/26 14:26)

#ifndef RENDERING_RENDERERS_PLATFORM_VERTEX_BUFFER_IMPL_H
#define RENDERING_RENDERERS_PLATFORM_VERTEX_BUFFER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Flags/BufferFlags.h"

#include <memory>

namespace Rendering
{
	class Renderer;
	class VertexBuffer;
	
	class RENDERING_HIDDEN_DECLARE PlatformVertexBufferImpl
	{
	public:
		using ClassType = PlatformVertexBufferImpl;
		using PlatformVertexBufferPtr = std::shared_ptr<ClassType>;

	public:
		PlatformVertexBufferImpl () noexcept;
		virtual ~PlatformVertexBufferImpl ();
		PlatformVertexBufferImpl(const PlatformVertexBufferImpl&) = default;
		PlatformVertexBufferImpl& operator=(const PlatformVertexBufferImpl&) = default;
		PlatformVertexBufferImpl(PlatformVertexBufferImpl&&) = default;
		PlatformVertexBufferImpl& operator=(PlatformVertexBufferImpl&&) = default;

		CLASS_INVARIANT_VIRTUAL_DECLARE;
		
		// ���㻺����������
		virtual void Enable (Renderer* renderer, unsigned int vertexSize,unsigned int streamIndex, unsigned int offset) = 0;
		virtual void Disable (Renderer* renderer, unsigned int streamIndex) = 0;
		virtual void* Lock (BufferLocking mode) = 0;
		virtual void Unlock () = 0;		

		static PlatformVertexBufferPtr Create(Renderer* renderer, const VertexBuffer* vertexBuffer);

    private:
        static PlatformVertexBufferPtr CreateDefault(Renderer* renderer,const VertexBuffer* vertexBuffer);
	};
}

#endif // RENDERING_RENDERERS_PLATFORM_VERTEX_BUFFER_IMPL_H

// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/29 11:34)

#ifndef RENDERING_RENDERERS_DX9_INDEX_BUFFER_H
#define RENDERING_RENDERERS_DX9_INDEX_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/Detail/PlatformIndexBufferImpl.h"
#include "System/Window/Flags/WindowFlags.h"

namespace Rendering
{
	class Renderer;
	class IndexBuffer;

	class RENDERING_HIDDEN_DECLARE Dx9IndexBuffer : public PlatformIndexBufferImpl
	{
	public:
		using ClassType = Dx9IndexBuffer;
		using ParentType = PlatformIndexBufferImpl;

	public:
                Dx9IndexBuffer(Renderer* renderer, const IndexBuffer* indexBuffer) noexcept;
 

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		// ����������
		 void Enable(Renderer* renderer) override;
		 void Disable(Renderer* renderer) override;
		 void* Lock(BufferLocking mode) override;
		 void Unlock() override;
	};
}

#endif // RENDERING_RENDERERS_DX9_INDEX_BUFFER_H
 
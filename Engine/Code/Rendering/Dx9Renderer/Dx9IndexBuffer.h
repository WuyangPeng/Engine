// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/29 11:34)

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
		Dx9IndexBuffer(Renderer* renderer,const IndexBuffer* indexBuffer);
		virtual ~Dx9IndexBuffer();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		// »º³åÇø²Ù×÷
		virtual void Enable(Renderer* renderer) override;
		virtual void Disable(Renderer* renderer) override;
		virtual void* Lock(BufferLocking mode) override;
		virtual void Unlock() override;
	};
}

#endif // RENDERING_RENDERERS_DX9_INDEX_BUFFER_H
 
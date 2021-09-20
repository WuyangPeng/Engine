// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/26 14:28)

#ifndef RENDERING_RENDERERS_PLATFORM_VERTEX_FORMAT_IMPL_H
#define RENDERING_RENDERERS_PLATFORM_VERTEX_FORMAT_IMPL_H

#include "Rendering/RenderingDll.h"

#include <memory>

namespace Rendering
{
    class Renderer;
    class VertexFormat;

	class RENDERING_HIDDEN_DECLARE PlatformVertexFormatImpl
    {
	public:
		using ClassType = PlatformVertexFormatImpl;
		using PlatformVertexFormatPtr = std::shared_ptr<ClassType>;
        using FactoryType = ClassType;
    public:
        PlatformVertexFormatImpl () noexcept;
        virtual ~PlatformVertexFormatImpl ();
		PlatformVertexFormatImpl(const PlatformVertexFormatImpl&) = default;
		PlatformVertexFormatImpl& operator=(const PlatformVertexFormatImpl&) = default;
		PlatformVertexFormatImpl(PlatformVertexFormatImpl&&) = default;
		PlatformVertexFormatImpl& operator=(PlatformVertexFormatImpl&&) = default;
		
		CLASS_INVARIANT_VIRTUAL_DECLARE;

        // 顶点格式操作。
        virtual void Enable (Renderer* renderer) = 0;
        virtual void Disable (Renderer* renderer) = 0;

        static PlatformVertexFormatPtr Create(Renderer* renderer,const VertexFormat* vertexFormat);

    private:
        static PlatformVertexFormatPtr CreateDefault(Renderer* renderer, const VertexFormat* vertexFormat);
    };
}

#endif // RENDERING_RENDERERS_PLATFORM_VERTEX_FORMAT_IMPL_H

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:49)

#ifndef RENDERING_RENDERERS_DX9_VERTEX_FORMAT_H
#define RENDERING_RENDERERS_DX9_VERTEX_FORMAT_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/Detail/PlatformVertexFormatImpl.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE Dx9VertexFormat : public PlatformVertexFormatImpl
    {
    public:
        using ClassType = Dx9VertexFormat;
        using ParentType = PlatformVertexFormatImpl;

    public:
        Dx9VertexFormat(Renderer* renderer, const VertexFormat* vertexFormat) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // 顶点格式操作。
        void Enable(Renderer* renderer) noexcept override;
        void Disable(Renderer* renderer) noexcept override;
    };
}

#endif  // RENDERING_RENDERERS_DX9_VERTEX_FORMAT_H

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:42)

#ifndef RENDERING_RENDERERS_FONT_H
#define RENDERING_RENDERERS_FONT_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/LocalEffects/LocalEffectsFwd.h"
#include "Rendering/RendererEngine/Detail/BaseRendererImpl.h"
#include "Rendering/RendererEngine/Viewport.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Font
    {
    public:
        using ClassType = Font;

    public:
        NODISCARD std::shared_ptr<const VertexBuffer> GetVertexBuffer() const noexcept;
        NODISCARD std::shared_ptr<const IndexBuffer> GetIndexBuffer() const noexcept;
        NODISCARD std::shared_ptr<const TextEffect> GetTextEffect() const noexcept;

        NODISCARD std::shared_ptr<VertexBuffer> GetVertexBuffer() noexcept;
        NODISCARD std::shared_ptr<IndexBuffer> GetIndexBuffer() noexcept;
        NODISCARD std::shared_ptr<TextEffect> GetTextEffect() noexcept;

        void Typeset(int getWidth, int getHeight, int i, int y, const Colour<float>& color, const std::string& string) noexcept;
    };
}

#endif  // RENDERING_RENDERERS_FONT_H

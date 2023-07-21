///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/14 14:13)

#ifndef RENDERING_RENDERERS_FONT_H
#define RENDERING_RENDERERS_FONT_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/LocalEffects/LocalEffectsFwd.h"
#include "Rendering/RendererEngine/Detail/BaseRendererImpl.h"
#include "Rendering/RendererEngine/Viewport.h"
#include "Rendering/Resources/ResourcesFwd.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(Font, FontImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Font
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(Font);

        using ProgramFactorySharedPtr = std::shared_ptr<ProgramFactory>;
        using VertexBufferSharedPtr = std::shared_ptr<VertexBuffer>;
        using IndexBufferSharedPtr = std::shared_ptr<IndexBuffer>;
        using TextEffectSharedPtr = std::shared_ptr<TextEffect>;
        using ConstVertexBufferSharedPtr = std::shared_ptr<const VertexBuffer>;
        using ConstIndexBufferSharedPtr = std::shared_ptr<const IndexBuffer>;
        using ConstTextEffectSharedPtr = std::shared_ptr<const TextEffect>;
        using Colour = Colour<float>;

    public:
        Font(FontType fontType, ProgramFactory& factory, int maxMessageLength);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstVertexBufferSharedPtr GetVertexBuffer() const noexcept;
        NODISCARD ConstIndexBufferSharedPtr GetIndexBuffer() const noexcept;
        NODISCARD ConstTextEffectSharedPtr GetTextEffect() const noexcept;

        NODISCARD int GetHeight() const;
        NODISCARD int GetWidth(const std::string& message) const;

        void Typeset(int viewportWidth,
                     int viewportHeight,
                     int x,
                     int y,
                     const Colour& color,
                     const std::string& message) const;

        NODISCARD VertexBufferSharedPtr GetVertexBuffer() noexcept;
        NODISCARD IndexBufferSharedPtr GetIndexBuffer() noexcept;
        NODISCARD TextEffectSharedPtr GetTextEffect() noexcept;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RENDERERS_FONT_H

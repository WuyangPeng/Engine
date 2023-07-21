///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/12 15:01)

#ifndef RENDERING_LOCAL_EFFECTS_FONT_IMPL_H
#define RENDERING_LOCAL_EFFECTS_FONT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/DataTypes/Colour.h"
#include "Rendering/LocalEffects/LocalEffectsInternalFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/Shaders/ShadersFwd.h"

#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE FontImpl
    {
    public:
        using ClassType = FontImpl;
        using FactoryType = FontFactory;

        using FontSharedPtr = std::shared_ptr<FontImpl>;
        using VertexBufferSharedPtr = std::shared_ptr<VertexBuffer>;
        using IndexBufferSharedPtr = std::shared_ptr<IndexBuffer>;
        using TextEffectSharedPtr = std::shared_ptr<TextEffect>;
        using ConstVertexBufferSharedPtr = std::shared_ptr<const VertexBuffer>;
        using ConstIndexBufferSharedPtr = std::shared_ptr<const IndexBuffer>;
        using ConstTextEffectSharedPtr = std::shared_ptr<const TextEffect>;
        using ProgramFactorySharedPtr = std::shared_ptr<ProgramFactory>;
        using Texture2DSharedPtr = std::shared_ptr<Texture2D>;

        using Colour = Colour<float>;
        using TexelsType = std::vector<uint8_t>;
        using CharacterDataType = std::array<float, 257>;

    public:
        FontImpl(ProgramFactory& factory,
                 int width,
                 int height,
                 const TexelsType& texels,
                 const CharacterDataType& characterData,
                 int maxMessageLength);
        virtual ~FontImpl() noexcept = default;
        FontImpl(const FontImpl& rhs) = default;
        FontImpl& operator=(const FontImpl& rhs) = default;
        FontImpl(FontImpl&& rhs) noexcept = default;
        FontImpl& operator=(FontImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD ConstVertexBufferSharedPtr GetVertexBuffer() const noexcept;
        NODISCARD ConstIndexBufferSharedPtr GetIndexBuffer() const noexcept;
        NODISCARD ConstTextEffectSharedPtr GetTextEffect() const noexcept;

        NODISCARD VertexBufferSharedPtr GetVertexBuffer() noexcept;
        NODISCARD IndexBufferSharedPtr GetIndexBuffer() noexcept;
        NODISCARD TextEffectSharedPtr GetTextEffect() noexcept;

        NODISCARD int GetHeight() const;
        NODISCARD int GetWidth(const std::string& message) const;

        void Typeset(int viewportWidth,
                     int viewportHeight,
                     int x,
                     int y,
                     const Colour& color,
                     const std::string& message) const;

        NODISCARD virtual FontSharedPtr Clone() const = 0;

    private:
        int maxMessageLength;
        VertexBufferSharedPtr vertexBuffer;
        IndexBufferSharedPtr indexBuffer;
        Texture2DSharedPtr texture;
        TextEffectSharedPtr textEffect;
        CharacterDataType characterData;
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_FONT_IMPL_H

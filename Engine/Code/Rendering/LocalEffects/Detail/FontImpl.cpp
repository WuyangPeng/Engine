///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:43)

#include "Rendering/RenderingExport.h"

#include "FontImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Rendering/LocalEffects/TextEffect.h"
#include "Rendering/Resources/Buffers/IndexBuffer.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"
#include "Rendering/Resources/Flags/DataFormatType.h"
#include "Rendering/Resources/Flags/UsageType.h"
#include "Rendering/Resources/Textures/Texture2D.h"

#include <stdexcept>

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26418)

Rendering::FontImpl::FontSharedPtr Rendering::FontImpl::Create(MAYBE_UNUSED const ProgramFactorySharedPtr& factory, MAYBE_UNUSED int width, MAYBE_UNUSED int height, MAYBE_UNUSED const TexelsType& texels, MAYBE_UNUSED const CharacterDataType& characterData, MAYBE_UNUSED int maxMessageLength)
{
    throw std::logic_error("The method or operation is not implemented.");
}

#include STSTEM_WARNING_POP

Rendering::FontImpl::FontImpl(const ProgramFactorySharedPtr& factory, int width, int height, const TexelsType& texels, const CharacterDataType& characterData, int maxMessageLength)
    : maxMessageLength{ maxMessageLength },
      vertexBuffer{},
      indexBuffer{},
      texture{},
      textEffect{},
      characterData{ characterData }
{
    auto vformat = VertexFormat::Create();
    vformat->Bind(VertexFormatFlags::Semantic::Position, DataFormatType::R32G32Float, 0);
    vformat->Bind(VertexFormatFlags::Semantic::TextureCoord, DataFormatType::R32G32Float, 0);
    const auto numVertices = 4 * maxMessageLength;
    vertexBuffer = VertexBuffer::Create(*vformat, numVertices);
    vertexBuffer->SetUsage(UsageType::DynamicUpdate);

    auto vertices = vertexBuffer->GetData();
    for (auto i = 0; i < numVertices; ++i)
    {
        vertices.Increase<float>(0.0f);
        vertices.Increase<float>(0.0f);

        vertices.Increase<float>(0.0f);
        vertices.Increase<float>(0.0f);
    }

    vertices = vertexBuffer->GetData();
    for (auto i = 0; i < maxMessageLength; ++i)
    {
        vertices.Increase<float>(0.0f);
        vertices.Increase<float>(0.0f);

        vertices.Increase<float>(0.0f);
        vertices.Increase<float>(0.0f);

        vertices.Increase<float>(0.0f);
        vertices.Increase<float>(0.0f);

        vertices.Increase<float>(0.0f);
        vertices.Increase<float>(1.0f);

        vertices.Increase<float>(0.0f);
        vertices.Increase<float>(0.0f);

        vertices.Increase<float>(0.0f);
        vertices.Increase<float>(0.0f);

        vertices.Increase<float>(0.0f);
        vertices.Increase<float>(0.0f);

        vertices.Increase<float>(0.0f);
        vertices.Increase<float>(1.0f);
    }

    const auto numTriangles = 2 * maxMessageLength;
    indexBuffer = IndexBuffer::Create(IndexFormatType::Trimesh, numTriangles, sizeof(uint32_t));
    const auto indices = indexBuffer->GetData();
    for (auto i = 0; i < maxMessageLength; ++i)
    {
        vertices.Increase<uint32_t>(4 * i);
        vertices.Increase<uint32_t>(4 * i + 3);
        vertices.Increase<uint32_t>(4 * i + 1);

        vertices.Increase<uint32_t>(4 * i);
        vertices.Increase<uint32_t>(4 * i + 2);
        vertices.Increase<uint32_t>(4 * i + 3);
    }

    texture = std::make_shared<Texture2D>(DataFormatType::R8UNorm, width, height, false);
    texture->SetNewData(texels);

    textEffect = std::make_shared<TextEffect>(factory, texture);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, FontImpl)

Rendering::FontImpl::ConstVertexBufferSharedPtr Rendering::FontImpl::GetVertexBuffer() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return vertexBuffer;
}

Rendering::FontImpl::ConstIndexBufferSharedPtr Rendering::FontImpl::GetIndexBuffer() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return indexBuffer;
}

Rendering::FontImpl::ConstTextEffectSharedPtr Rendering::FontImpl::GetTextEffect() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textEffect;
}

int Rendering::FontImpl::GetHeight() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return (texture != nullptr ? texture->GetHeight() : 0);
}

int Rendering::FontImpl::GetWidth(const std::string& message) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto tw = boost::numeric_cast<float>(texture->GetWidth());

    auto width = 0.0f;
    const auto length = std::min(boost::numeric_cast<int>(message.length()), maxMessageLength);
    for (auto i = 0; i < length; ++i)
    {
        const auto c = message.at(i);
        const auto tx0 = characterData.at(c);
        const auto next = c + 1;
        const auto tx1 = characterData.at(next);
        const auto charWidthM1 = (tx1 - tx0) * tw - 1.0f;

        width += charWidthM1;
    }

    return boost::numeric_cast<int>(std::ceil(width));
}

void Rendering::FontImpl::Typeset(int viewportWidth, int viewportHeight, int x, int y, const Colour& color, const std::string& message) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto vdx = 1.0f / boost::numeric_cast<float>(viewportWidth);
    const auto vdy = 1.0f / boost::numeric_cast<float>(viewportHeight);

    auto tw = boost::numeric_cast<float>(texture->GetWidth());
    auto th = boost::numeric_cast<float>(texture->GetHeight());

    auto vertexSize = vertexBuffer->GetFormat().GetStride();
    auto data = vertexBuffer->GetData();

    auto x0 = 0.0f;
    const auto length = std::min(boost::numeric_cast<int>(message.length()), maxMessageLength);
    const auto stepSize = boost::numeric_cast<int>(vertexSize - sizeof(float) * 3);
    for (auto i = 0; i < length; ++i)
    {
        auto c = boost::numeric_cast<int>(message.at(i));
        const auto tx0 = characterData.at(c);
        const auto nextIndex = c + 1;
        const auto tx1 = characterData.at(nextIndex);
        auto charWidthM1 = (tx1 - tx0) * tw - 1.0f;

        const auto fourI = 4 * boost::numeric_cast<size_t>(i);

        const auto x1 = x0 + charWidthM1 * vdx;

        data.Increase<float>(x0);
        data.Increase<float>(0.0f);
        data.Increase<float>(tx0);
        if (0 < stepSize)
            data += stepSize;

        data.Increase<float>(x0);
        data.Increase<float>(vdy * th);
        data.Increase<float>(tx0);
        if (0 < stepSize)
            data += stepSize;

        data.Increase<float>(x1);
        data.Increase<float>(0.0f);
        data.Increase<float>(tx1);
        if (0 < stepSize)
            data += stepSize;

        data.Increase<float>(x1);
        data.Increase<float>(vdy * th);
        data.Increase<float>(tx1);
        if (0 < stepSize)
            data += stepSize;

        x0 = x1;
    }

    vertexBuffer->SetNumActiveElements(4 * length);
    indexBuffer->SetNumActivePrimitives(2 * length);

    const auto trnX = vdx * boost::numeric_cast<float>(x);
    const auto trnY = 1.0f - vdy * boost::numeric_cast<float>(y);
    textEffect->SetTranslate(trnX, trnY);
    textEffect->SetColor(color);
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/12 15:11)

#include "Rendering/RenderingExport.h"

#include "FontImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Rendering/LocalEffects/TextEffect.h"
#include "Rendering/Resources/Buffers/IndexBuffer.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"
#include "Rendering/Resources/Flags/DataFormatType.h"
#include "Rendering/Resources/Flags/UsageType.h"
#include "Rendering/Resources/Textures/Texture2D.h"

Rendering::FontImpl::FontImpl(ProgramFactory& factory, const std::string& shaderExtendName, int width, int height, const TexelsType& texels, const CharacterDataType& characterData, int maxMessageLength)
    : maxMessageLength{ maxMessageLength },
      vertexBuffer{},
      indexBuffer{},
      texture{},
      textEffect{},
      characterData{ characterData }
{
    const auto vertexFormat = VertexFormat::Create("VertexFormat");
    vertexFormat->Bind(DataFormatType::R32G32Float, VertexFormatFlags::Semantic::Position, 0);
    vertexFormat->Bind(DataFormatType::R32G32Float, VertexFormatFlags::Semantic::TextureCoord, 0);
    const auto numVertices = 4 * maxMessageLength;
    vertexBuffer = VertexBuffer::Create("VertexBuffer", *vertexFormat, numVertices);
    vertexBuffer->SetUsage(UsageType::DynamicUpdate);

    auto vertices = vertexBuffer->GetStorage();
    for (auto i = 0; i < maxMessageLength; ++i)
    {
        vertices.SetValue<float, 4>((4 * i + 0) * CoreTools::GetStreamSize<float>(), { 0.0f, 0.0f, 0.0f, 0.0f });
        vertices.SetValue<float, 4>((4 * i + 1) * CoreTools::GetStreamSize<float>(), { 0.0f, 0.0f, 0.0f, 1.0f });
        vertices.SetValue<float, 4>((4 * i + 2) * CoreTools::GetStreamSize<float>(), { 0.0f, 0.0f, 0.0f, 1.0f });
        vertices.SetValue<float, 4>((4 * i + 3) * CoreTools::GetStreamSize<float>(), { 0.0f, 0.0f, 0.0f, 1.0f });
    }

    const auto numTriangles = 2 * maxMessageLength;
    indexBuffer = IndexBuffer::Create("IndexBuffer", IndexFormatType::TriangleMesh, numTriangles, sizeof(int32_t));
    auto indices = indexBuffer->GetStorage();
    for (auto i = 0; i < maxMessageLength; ++i)
    {
        indices.Increase<int32_t>(4 * i);
        indices.Increase<int32_t>(4 * i + 3);
        indices.Increase<int32_t>(4 * i + 1);

        indices.Increase<int32_t>(4 * i);
        indices.Increase<int32_t>(4 * i + 2);
        indices.Increase<int32_t>(4 * i + 3);
    }

    texture = std::make_shared<Texture2D>("R8UNorm", DataFormatType::R8UNorm, width, height, false);

    Texture2D::StorageType storageType{};
    for (auto value : texels)
    {
        storageType.emplace_back(value);
    }
    texture->SetStorage(storageType);

    textEffect = std::make_shared<TextEffect>(factory, shaderExtendName, texture);

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

Rendering::FontImpl::VertexBufferSharedPtr Rendering::FontImpl::GetVertexBuffer() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return vertexBuffer;
}

Rendering::FontImpl::IndexBufferSharedPtr Rendering::FontImpl::GetIndexBuffer() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return indexBuffer;
}

Rendering::FontImpl::TextEffectSharedPtr Rendering::FontImpl::GetTextEffect() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

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

    const auto textureWidth = boost::numeric_cast<float>(texture->GetWidth());

    auto width = 0.0f;
    const auto length = std::min(boost::numeric_cast<int>(message.length()), maxMessageLength);
    for (auto i = 0; i < length; ++i)
    {
        const auto c = message.at(i);
        const auto tx0 = characterData.at(c);
        const auto next = c + 1;
        const auto tx1 = characterData.at(next);
        const auto charWidthM1 = (tx1 - tx0) * textureWidth - 1.0f;

        width += charWidthM1;
    }

    return boost::numeric_cast<int>(std::ceil(width));
}

void Rendering::FontImpl::Typeset(int viewportWidth, int viewportHeight, int x, int y, const ColourType& color, const std::string& message) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto viewportDX = 1.0f / boost::numeric_cast<float>(viewportWidth);
    const auto viewportDY = 1.0f / boost::numeric_cast<float>(viewportHeight);

    const auto tw = boost::numeric_cast<float>(texture->GetWidth());
    const auto th = boost::numeric_cast<float>(texture->GetHeight());

    const auto vertexSize = vertexBuffer->GetFormat().GetVertexSize();
    auto data = vertexBuffer->GetStorage();

    auto x0 = 0.0f;
    const auto length = std::min(boost::numeric_cast<int>(message.length()), maxMessageLength);
    const auto stepSize = vertexSize - 4 * CoreTools::GetStreamSize<float>();
    for (auto i = 0; i < length; ++i)
    {
        const auto c = boost::numeric_cast<int>(message.at(i));
        const auto tx0 = characterData.at(c);
        const auto nextIndex = c + 1;
        const auto tx1 = characterData.at(nextIndex);
        const auto charWidthM1 = (tx1 - tx0) * tw - 1.0f;

        const auto x1 = x0 + charWidthM1 * viewportDX;

        data.Increase<float>(x0);
        data += sizeof(float);
        data.Increase<float>(tx0);
        data += sizeof(float);

        if (0 < stepSize)
        {
            data += stepSize;
        }

        data.Increase<float>(x0);
        data.Increase<float>(viewportDY * th);
        data.Increase<float>(tx0);
        data += sizeof(float);

        if (0 < stepSize)
        {
            data += stepSize;
        }

        data.Increase<float>(x1);
        data += sizeof(float);
        data.Increase<float>(tx1);
        data += sizeof(float);

        if (0 < stepSize)
        {
            data += stepSize;
        }

        data.Increase<float>(x1);
        data.Increase<float>(viewportDY * th);
        data.Increase<float>(tx1);
        data += sizeof(float);

        if (0 < stepSize)
        {
            data += stepSize;
        }

        x0 = x1;
    }

    vertexBuffer->SetNumActiveElements(4 * length);
    indexBuffer->SetNumActivePrimitives(2 * length);

    const auto trnX = viewportDX * boost::numeric_cast<float>(x);
    const auto trnY = 1.0f - viewportDY * boost::numeric_cast<float>(y);
    textEffect->SetTranslate(trnX, trnY);
    textEffect->SetColor(color);
}

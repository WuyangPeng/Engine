/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:41)

#include "Rendering/RenderingExport.h"

#include "MeshVertexBuffer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Resources/Flags/DataFormatType.h"

Rendering::MeshVertexBuffer::MeshVertexBuffer(VertexBufferSharedPtr vertexBuffer) noexcept
    : vertexBuffer{ std::move(vertexBuffer) },
      semantic{},
      textureCoords{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, MeshVertexBuffer)

Rendering::VertexBufferSharedPtr Rendering::MeshVertexBuffer::GetVertexBuffer() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return vertexBuffer;
}

bool Rendering::MeshVertexBuffer::HasChannel(Semantic aSemantic) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return semantic.contains(aSemantic);
}

void Rendering::MeshVertexBuffer::SetPosition(int index, const Vector3& position, int vertexSize)
{
    RENDERING_CLASS_IS_VALID_9;

    if (const auto iter = semantic.find(Semantic::Position);
        iter != semantic.cend())
    {
        iter->second.SetValue(index * vertexSize, position.GetCoordinate());
    }
}

void Rendering::MeshVertexBuffer::SetNormal(int index, const Vector3& normal, int vertexSize)
{
    RENDERING_CLASS_IS_VALID_9;

    if (const auto iter = semantic.find(Semantic::Normal);
        iter != semantic.cend())
    {
        iter->second.SetValue(index * vertexSize, normal.GetCoordinate());
    }
}

void Rendering::MeshVertexBuffer::SetTangent(int index, const Vector3& tangent, int vertexSize)
{
    RENDERING_CLASS_IS_VALID_9;

    if (const auto iter = semantic.find(Semantic::Tangent);
        iter != semantic.cend())
    {
        iter->second.SetValue(index * vertexSize, tangent.GetCoordinate());
    }
}

void Rendering::MeshVertexBuffer::SetBitangent(int index, const Vector3& bitangent, int vertexSize)
{
    RENDERING_CLASS_IS_VALID_9;

    if (const auto iter = semantic.find(Semantic::Binormal);
        iter != semantic.cend())
    {
        iter->second.SetValue(index * vertexSize, bitangent.GetCoordinate());
    }
}

void Rendering::MeshVertexBuffer::SetTextureCoordinate(int unit, int index, const Vector2& textureCoordinate, int vertexSize)
{
    RENDERING_CLASS_IS_VALID_9;

    if (const auto iter = textureCoords.find(unit);
        iter != textureCoords.cend())
    {
        iter->second.SetValue(unit + index * vertexSize, textureCoordinate.GetCoordinate());
    }
}

Rendering::MeshVertexBuffer::Vector3 Rendering::MeshVertexBuffer::GetPosition(int index, int vertexSize) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (const auto iter = semantic.find(Semantic::Position);
        iter != semantic.cend())
    {
        return Vector3{ iter->second.GetValue<float, 3>(index * vertexSize) };
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("不存在Position。"))
    }
}

Rendering::MeshVertexBuffer::Vector3 Rendering::MeshVertexBuffer::GetNormal(int index, int vertexSize) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (const auto iter = semantic.find(Semantic::Normal);
        iter != semantic.cend())
    {
        return Vector3{ iter->second.GetValue<float, 3>(index * vertexSize) };
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("不存在Normal。"))
    }
}

Rendering::MeshVertexBuffer::Vector3 Rendering::MeshVertexBuffer::GetTangent(int index, int vertexSize) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (const auto iter = semantic.find(Semantic::Tangent);
        iter != semantic.cend())
    {
        return Vector3{ iter->second.GetValue<float, 3>(index * vertexSize) };
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("不存在Tangent。"))
    }
}

Rendering::MeshVertexBuffer::Vector3 Rendering::MeshVertexBuffer::GetBitangent(int index, int vertexSize) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (const auto iter = semantic.find(Semantic::Binormal);
        iter != semantic.cend())
    {
        return Vector3{ iter->second.GetValue<float, 3>(index * vertexSize) };
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("不存在Binormal。"))
    }
}

Rendering::MeshVertexBuffer::Vector2 Rendering::MeshVertexBuffer::GetTextureCoordinate(int unit, int index, int vertexSize) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (const auto iter = textureCoords.find(unit);
        iter != textureCoords.cend())
    {
        return Vector2{ iter->second.GetValue<float, 2>(unit + index * vertexSize) };
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("不存在TextureCoordinate。"))
    }
}

void Rendering::MeshVertexBuffer::AddChannel(VertexFormatFlags::Semantic aSemantic, const SpanIterator& channel)
{
    RENDERING_CLASS_IS_VALID_9;

    semantic.emplace(aSemantic, channel);
}

void Rendering::MeshVertexBuffer::AddTextureCoords(int unit, const SpanIterator& channel)
{
    RENDERING_CLASS_IS_VALID_9;

    textureCoords.emplace(unit, channel);
}

void Rendering::MeshVertexBuffer::SetGeometricChannel(Semantic aSemantic, float w, const VertexFormat& vertexFormat)
{
    RENDERING_CLASS_IS_VALID_9;

    if (const auto index = vertexFormat.GetIndex(aSemantic, 0);
        0 <= index)
    {
        auto channel = vertexBuffer->GetChannel(aSemantic, 0, VertexBuffer::DataFormatTypeContainer{});

        if (vertexFormat.GetAttributeType(index) == DataFormatType::R32G32B32A32Float)
        {
            const auto numVertices = vertexBuffer->GetNumElements();
            for (auto i = 0; i < numVertices; ++i)
            {
                channel.SetValue(i * vertexFormat.GetVertexSize(), w);
            }
        }

        AddChannel(aSemantic, channel);
    }
}

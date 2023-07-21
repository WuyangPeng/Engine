///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/07 13:40)

#include "Rendering/RenderingExport.h"

#include "BumpMapEffectImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix4Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"
#include "Rendering/SceneGraph/Visual.h"
#include "Rendering/State/SamplerState.h"

Rendering::BumpMapEffectImpl::BumpMapEffectImpl() noexcept
    : baseTexture{},
      normalTexture{},
      commonSampler{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::BumpMapEffectImpl::BumpMapEffectImpl(SamplerStateFilter filter, SamplerStateMode mode0, SamplerStateMode mode1, Texture2DSharedPtr baseTexture, Texture2DSharedPtr normalTexture)
    : baseTexture{ std::move(baseTexture) },
      normalTexture{ std::move(normalTexture) },
      commonSampler{ std::make_shared<SamplerState>(filter, mode0, mode1) }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, BumpMapEffectImpl)

Rendering::BumpMapEffectImpl::ConstTexture2DSharedPtr Rendering::BumpMapEffectImpl::GetBaseTexture() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return baseTexture;
}

Rendering::BumpMapEffectImpl::ConstTexture2DSharedPtr Rendering::BumpMapEffectImpl::GetNormalTexture() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return normalTexture;
}

Rendering::BumpMapEffectImpl::ConstSamplerStateSharedPtr Rendering::BumpMapEffectImpl::GetCommonSampler() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return commonSampler;
}

Rendering::BumpMapEffectImpl::Texture2DSharedPtr Rendering::BumpMapEffectImpl::GetBaseTexture() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return baseTexture;
}

Rendering::BumpMapEffectImpl::Texture2DSharedPtr Rendering::BumpMapEffectImpl::GetNormalTexture() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return normalTexture;
}

Rendering::BumpMapEffectImpl::SamplerStateSharedPtr Rendering::BumpMapEffectImpl::GetCommonSampler() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return commonSampler;
}

void Rendering::BumpMapEffectImpl::ComputeLightVectors(const VisualSharedPtr& mesh, const Vector4& worldLightDirection)
{
    struct Vertex
    {
        Vector3 position;
        Vector3 normal;
        Vector3 lightDirection;
        Vector2 baseTextureCoordinate;
        Vector2 normalTextureCoordinate;
    };

    constexpr auto vertexSize = Vector3::pointSize * sizeof(float) * 3 + Vector2::pointSize * sizeof(float) * 2;
    constexpr auto normalShifting = Vector3::pointSize * sizeof(float);
    constexpr auto lightDirectionShifting = Vector3::pointSize * sizeof(float) * 2;
    constexpr auto baseTextureCoordinateShifting = Vector3::pointSize * sizeof(float) * 3;

    const auto rowMajor = mesh->GetWorldTransform().GetInverseMatrix().GetRowMajor();
    const Mathematics::Matrix4<float> inverseWorldMatrix{ Mathematics::Matrix4<float>::ContainerType{ rowMajor.cbegin(), rowMajor.cend() }, Mathematics::MatrixMajorFlags::Row };
    const auto tempDirection = -(inverseWorldMatrix * worldLightDirection);
    const auto modelLightDirection = Mathematics::Vector4Tools<float>::ProjectHomogeneous(tempDirection);

    const auto vertexBuffer = mesh->GetVertexBuffer();
    const auto numVertices = vertexBuffer->GetNumElements();

    for (auto i = 0; i < numVertices; ++i)
    {
        auto vertices = vertexBuffer->GetData(vertexSize * i + lightDirectionShifting);
        vertices.Increase(0.0f);
        vertices.Increase(0.0f);
        vertices.Increase(0.0f);
    }

    const auto indexBuffer = mesh->GetIndexBuffer();
    const auto numTriangles = indexBuffer->GetNumPrimitives();
    auto indices = indexBuffer->GetData();

    for (auto t = 0; t < numTriangles; ++t)
    {
        std::array<int32_t, 3> v{};
        v.at(0) = indices.Increase<int32_t>();
        v.at(1) = indices.Increase<int32_t>();
        v.at(2) = indices.Increase<int32_t>();

        for (auto i = 0; i < 3; ++i)
        {
            auto v0 = v.at(i);
            auto vertices = vertexBuffer->GetData(vertexSize * v0 + lightDirectionShifting);
            const auto vertices0 = vertices.Increase<float>();
            const auto vertices1 = vertices.Increase<float>();
            const auto vertices2 = vertices.Increase<float>();
            if (!Mathematics::MathF::Approximate(vertices0, 0.0f) ||
                !Mathematics::MathF::Approximate(vertices1, 0.0f) ||
                !Mathematics::MathF::Approximate(vertices2, 0.0f))
            {
                continue;
            }

            const auto iP = (i == 0) ? 2 : i - 1;
            const auto iN = (i + 1) % 3;
            const auto v1 = v.at(iN);
            const auto v2 = v.at(iP);

            auto position = vertexBuffer->GetData(vertexSize * v0);
            auto position0 = position.Increase<float>();
            auto position1 = position.Increase<float>();
            auto position2 = position.Increase<float>();
            const Vector3 pos0{ position0, position1, position2 };

            auto baseTextureCoordinate = vertexBuffer->GetData(vertexSize * v0 + baseTextureCoordinateShifting);
            auto baseTextureCoordinate0 = baseTextureCoordinate.Increase<float>();
            auto baseTextureCoordinate1 = baseTextureCoordinate.Increase<float>();
            const Vector2 tcd0{ baseTextureCoordinate0, baseTextureCoordinate1 };

            position = vertexBuffer->GetData(vertexSize * v1);
            position0 = position.Increase<float>();
            position1 = position.Increase<float>();
            position2 = position.Increase<float>();
            const Vector3 pos1{ position0, position1, position2 };

            baseTextureCoordinate = vertexBuffer->GetData(vertexSize * v1 + baseTextureCoordinateShifting);
            baseTextureCoordinate0 = baseTextureCoordinate.Increase<float>();
            baseTextureCoordinate1 = baseTextureCoordinate.Increase<float>();
            const Vector2 tcd1{ baseTextureCoordinate0, baseTextureCoordinate1 };

            position = vertexBuffer->GetData(vertexSize * v2);
            position0 = position.Increase<float>();
            position1 = position.Increase<float>();
            position2 = position.Increase<float>();
            const Vector3 pos2{ position0, position1, position2 };

            baseTextureCoordinate = vertexBuffer->GetData(vertexSize * v2 + baseTextureCoordinateShifting);
            baseTextureCoordinate0 = baseTextureCoordinate.Increase<float>();
            baseTextureCoordinate1 = baseTextureCoordinate.Increase<float>();
            const Vector2 tcd2{ baseTextureCoordinate0, baseTextureCoordinate1 };

            auto normalData = vertexBuffer->GetData(vertexSize * v0 + normalShifting);
            auto normal0 = normalData.Increase<float>();
            auto normal1 = normalData.Increase<float>();
            auto normal2 = normalData.Increase<float>();
            const Vector3 normal{ normal0, normal1, normal2 };

            Vector3 tangent{};
            if (!ComputeTangent(pos0, tcd0, pos1, tcd1, pos2, tcd2, tangent))
            {
                auto data = vertexBuffer->GetData(vertexSize * v0 + lightDirectionShifting);
                data.Increase<float>(normal.GetX());
                data.Increase<float>(normal.GetY());
                data.Increase<float>(normal.GetZ());

                continue;
            }

            tangent -= Mathematics::Vector3Tools<float>::DotProduct(normal, tangent) * normal;
            tangent.Normalize();

            const auto bitangent = Mathematics::Vector3Tools<float>::UnitCrossProduct(normal, tangent);

            const auto dotUT = Mathematics::Vector3Tools<float>::DotProduct(modelLightDirection, tangent);
            const auto dotUB = Mathematics::Vector3Tools<float>::DotProduct(modelLightDirection, bitangent);
            const auto dotUN = Mathematics::Vector3Tools<float>::DotProduct(modelLightDirection, normal);

            auto data = vertexBuffer->GetData(vertexSize * v0 + lightDirectionShifting);
            data.Increase<float>(0.5f * (dotUT + 1.0f));
            data.Increase<float>(0.5f * (dotUB + 1.0f));
            data.Increase<float>(0.5f * (dotUN + 1.0f));
        }
    }
}

bool Rendering::BumpMapEffectImpl::ComputeTangent(const Vector3& position0,
                                                  const Vector2& textureCoordinate0,
                                                  const Vector3& position1,
                                                  const Vector2& textureCoordinate1,
                                                  const Vector3& position2,
                                                  const Vector2& textureCoordinate2,
                                                  Vector3& tangent)
{
    const auto deltaPosition1 = position1 - position0;
    const auto deltaPosition2 = position2 - position0;

    constexpr auto epsilon = 1e-08f;
    if (Mathematics::Vector3Tools<float>::GetLength(deltaPosition1) <= epsilon || Mathematics::Vector3Tools<float>::GetLength(deltaPosition2) <= epsilon)
    {
        return false;
    }

    const auto du1 = textureCoordinate1[0] - textureCoordinate0[0];
    const auto dv1 = textureCoordinate1[1] - textureCoordinate0[1];
    if (Mathematics::MathF::FAbs(dv1) <= epsilon)
    {
        if (Mathematics::MathF::FAbs(du1) <= epsilon)
        {
            return false;
        }

        tangent = deltaPosition1 / du1;
        return true;
    }

    const auto du2 = textureCoordinate2[0] - textureCoordinate0[0];
    const auto dv2 = textureCoordinate2[1] - textureCoordinate0[1];
    const auto det = dv1 * du2 - dv2 * du1;
    if (Mathematics::MathF::FAbs(det) <= epsilon)
    {
        return false;
    }

    tangent = (dv1 * deltaPosition2 - dv2 * deltaPosition1) / det;

    return true;
}

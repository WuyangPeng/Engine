/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 10:22)

#include "Rendering/RenderingExport.h"

#include "BumpMapEffectImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix4Detail.h"
#include "Mathematics/Algebra/TransformDetail.h"
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
    System::UnusedFunction(mesh);

    struct Vertex
    {
        Vector3 position;
        Vector3 normal;
        Vector3 lightDirection;
        Vector2 baseTextureCoordinate;
        Vector2 normalTextureCoordinate;
    };

    const auto vertexSize = Vector3::pointSize * CoreTools::GetStreamSize<float>() * 3 + Vector2::pointSize * CoreTools::GetStreamSize<float>() * 2;
    const auto normalShifting = Vector3::pointSize * CoreTools::GetStreamSize<float>();
    const auto lightDirectionShifting = Vector3::pointSize * CoreTools::GetStreamSize<float>() * 2;
    const auto baseTextureCoordinateShifting = Vector3::pointSize * CoreTools::GetStreamSize<float>() * 3;

    const auto inverseMatrix = mesh->GetWorldTransform().GetInverseMatrix().GetMatrix4();
    const auto tempDirection = -(inverseMatrix * worldLightDirection);
    const auto modelLightDirection = Mathematics::Vector4Tools<float>::ProjectHomogeneous(tempDirection);

    const auto vertexBuffer = mesh->GetVertexBuffer();
    const auto numVertices = vertexBuffer->GetNumElements();

    constexpr std::array zero{ 0.0f, 0.0f, 0.0f };
    for (auto i = 0; i < numVertices; ++i)
    {
        auto vertices = vertexBuffer->GetStorage(vertexSize * i + lightDirectionShifting);
        vertices.SetValue(0, zero);
    }

    const auto indexBuffer = mesh->GetIndexBuffer();
    const auto numTriangles = indexBuffer->GetNumPrimitives();
    auto indices = indexBuffer->GetStorage();

    for (auto t = 0; t < numTriangles; ++t)
    {
        auto i = 0;
        for (const auto vertices = indices.Increase<int32_t, 3>();
             const auto& vertex : vertices)
        {
            const auto lightDirection = vertexBuffer->GetStorage(vertexSize * vertex + lightDirectionShifting);

            if (const auto lightVertices = lightDirection.GetValue<float, 3>(0);
                !Mathematics::MathF::Approximate(lightVertices.at(0), 0.0f) ||
                !Mathematics::MathF::Approximate(lightVertices.at(1), 0.0f) ||
                !Mathematics::MathF::Approximate(lightVertices.at(2), 0.0f))
            {
                continue;
            }

            const auto iP = (i == 0) ? 2 : i - 1;
            const auto iN = (i + 1) % 3;
            const auto v1 = vertices.at(iN);
            const auto v2 = vertices.at(iP);

            auto position = vertexBuffer->GetStorage(vertexSize * vertex);
            const Vector3 pos0{ position.Increase<float, 3>() };

            auto baseTextureCoordinate = vertexBuffer->GetStorage(vertexSize * vertex + baseTextureCoordinateShifting);
            const Vector2 tcd0{ baseTextureCoordinate.Increase<float, 2>() };

            position = vertexBuffer->GetStorage(vertexSize * v1);
            const Vector3 pos1{ position.Increase<float, 3>() };

            baseTextureCoordinate = vertexBuffer->GetStorage(vertexSize * v1 + baseTextureCoordinateShifting);
            const Vector2 tcd1{ baseTextureCoordinate.Increase<float, 2>() };

            position = vertexBuffer->GetStorage(vertexSize * v2);
            const Vector3 pos2{ position.Increase<float, 3>() };

            baseTextureCoordinate = vertexBuffer->GetStorage(vertexSize * v2 + baseTextureCoordinateShifting);
            const Vector2 tcd2{ baseTextureCoordinate.Increase<float, 2>() };

            auto normalData = vertexBuffer->GetStorage(vertexSize * vertex + normalShifting);
            const Vector3 normal{ normalData.Increase<float, 3>() };

            Vector3 tangent{};
            if (!ComputeTangent(pos0, tcd0, pos1, tcd1, pos2, tcd2, tangent))
            {
                auto data = vertexBuffer->GetStorage(vertexSize * vertex + lightDirectionShifting);
                data.SetValue(0, normal.GetCoordinate());

                continue;
            }

            tangent -= Mathematics::Vector3Tools<float>::DotProduct(normal, tangent) * normal;
            tangent.Normalize();

            const auto bitangent = Mathematics::Vector3Tools<float>::UnitCrossProduct(normal, tangent);

            const auto dotUT = Vector3Tools::DotProduct(modelLightDirection, tangent);
            const auto dotUB = Vector3Tools::DotProduct(modelLightDirection, bitangent);
            const auto dotUN = Vector3Tools::DotProduct(modelLightDirection, normal);

            auto data = vertexBuffer->GetStorage(vertexSize * vertex + lightDirectionShifting);
            data.Increase(0.5f * (dotUT + 1.0f));
            data.Increase(0.5f * (dotUB + 1.0f));
            data.Increase(0.5f * (dotUN + 1.0f));

            ++i;
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

    constexpr auto epsilon = Math::GetZeroTolerance();
    if (Vector3Tools::GetLength(deltaPosition1) <= epsilon || Vector3Tools::GetLength(deltaPosition2) <= epsilon)
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

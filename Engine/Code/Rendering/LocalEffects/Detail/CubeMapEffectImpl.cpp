///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/11 16:24)

#include "Rendering/RenderingExport.h"

#include "CubeMapEffectImpl.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "Mathematics/Algebra/TransformDetail.h"
#include "Rendering/LocalEffects/Texture2DEffect.h"
#include "Rendering/RendererEngine/BaseRenderer.h"
#include "Rendering/Resources/Buffers/ConstantBuffer.h"
#include "Rendering/Resources/Flags/CopyType.h"
#include "Rendering/Resources/Textures/DrawTarget.h"
#include "Rendering/Resources/Textures/TextureCube.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/State/SamplerState.h"
#include "Rendering/Visibility/Culler.h"

Rendering::CubeMapEffectImpl::CubeMapEffectImpl() noexcept
    : worldMatrixConstant{},
      cameraWorldPositionConstant{},
      reflectivityConstant{},
      cubeTexture{},
      cubeSampler{},
      camera{},
      target{},
      depthRangeIs01{ false },
      dynamicUpdates{ false }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::CubeMapEffectImpl::CubeMapEffectImpl(TextureCubeSharedPtr texture, SamplerStateFilter filter, SamplerStateMode mode0, SamplerStateMode mode1, float reflectivity, bool depthRangeIs01, int numWorldMatrixConstantBytes, int numCameraWorldPositionConstantBytes, int numReflectivityConstantBytes)
    : worldMatrixConstant{ std::make_shared<ConstantBuffer>("worldMatrixConstant", numWorldMatrixConstantBytes, true) },
      cameraWorldPositionConstant{ std::make_shared<ConstantBuffer>("cameraWorldPositionConstant", numCameraWorldPositionConstantBytes, true) },
      reflectivityConstant{ std::make_shared<ConstantBuffer>("reflectivityConstant", numReflectivityConstantBytes, true) },
      cubeTexture{ std::move(texture) },
      cubeSampler{ std::make_shared<SamplerState>(filter, mode0, mode1) },
      camera{ std::make_shared<Camera>(true, depthRangeIs01 ? DepthType::ZeroToOne : DepthType::MinusOneToOne, Mathematics::MathF::GetZeroTolerance()) },
      target{ std::make_shared<DrawTarget>("target", 1, cubeTexture->GetFormat(), cubeTexture->GetLength(), cubeTexture->GetLength(), true) },
      depthRangeIs01{ depthRangeIs01 },
      dynamicUpdates{ false }
{
    SetWorldMatrix(Matrix4::GetIdentity());
    SetCameraWorldPosition(Vector4{ 1.0f, 1.0f, 1.0f, 0.0f });
    SetReflectivity(reflectivity);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, CubeMapEffectImpl)

void Rendering::CubeMapEffectImpl::SetReflectivity(float reflectivity)
{
    RENDERING_CLASS_IS_VALID_9;

    auto data = reflectivityConstant->GetStorage();

    data.Increase(reflectivity);
}

void Rendering::CubeMapEffectImpl::UseDynamicUpdates(float dMin, float dMax)
{
    RENDERING_CLASS_IS_VALID_9;

    camera = std::make_shared<Camera>(true, depthRangeIs01 ? DepthType::ZeroToOne : DepthType::MinusOneToOne, Mathematics::MathF::GetZeroTolerance());
    camera->SetFrustum(90.0f, 1.0f, dMin, dMax);

    target = std::make_shared<DrawTarget>("DrawTarget", 1, cubeTexture->GetFormat(), cubeTexture->GetLength(), cubeTexture->GetLength(), true);
    target->AutoGenerateRenderTargetMipMaps();
    target->GetRenderTargetTexture(0)->SetCopy(CopyType::StagingToCpu);

    dynamicUpdates = true;
}

void Rendering::CubeMapEffectImpl::SetWorldMatrix(const Matrix4& worldMatrix)
{
    RENDERING_CLASS_IS_VALID_9;

    auto data = worldMatrixConstant->GetStorage();

    for (const auto element : worldMatrix.GetContainer())
    {
        data.Increase(element);
    }
}

Rendering::CubeMapEffectImpl::Matrix4 Rendering::CubeMapEffectImpl::GetWorldMatrix() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    Matrix4 matrix4{};

    auto data = worldMatrixConstant->GetStorage();

    for (auto x = 0; x < Matrix4::vectorSize; ++x)
    {
        for (auto y = 0; y < Matrix4::vectorSize; ++y)
        {
            matrix4(x, y) = data.Increase<float>();
        }
    }

    return matrix4;
}

Rendering::CubeMapEffectImpl::ConstConstantBufferSharedPtr Rendering::CubeMapEffectImpl::GetWorldMatrixConstant() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return worldMatrixConstant;
}

Rendering::CubeMapEffectImpl::ConstantBufferSharedPtr Rendering::CubeMapEffectImpl::GetWorldMatrixConstant() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return worldMatrixConstant;
}

void Rendering::CubeMapEffectImpl::SetCameraWorldPosition(const Vector4& cameraWorldPosition)
{
    RENDERING_CLASS_IS_VALID_9;

    auto data = cameraWorldPositionConstant->GetStorage();

    for (const auto element : cameraWorldPosition.GetCoordinate())
    {
        data.Increase(element);
    }
}

Rendering::CubeMapEffectImpl::Vector4 Rendering::CubeMapEffectImpl::GetCameraWorldPosition() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    Vector4 vector4{};

    auto data = cameraWorldPositionConstant->GetStorage();

    for (auto x = 0; x < Vector4::pointSize; ++x)
    {
        vector4[x] = data.Increase<float>();
    }

    return vector4;
}

Rendering::CubeMapEffectImpl::ConstConstantBufferSharedPtr Rendering::CubeMapEffectImpl::GetCameraWorldPositionConstant() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraWorldPositionConstant;
}

Rendering::CubeMapEffectImpl::ConstantBufferSharedPtr Rendering::CubeMapEffectImpl::GetCameraWorldPositionConstant() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return cameraWorldPositionConstant;
}

float Rendering::CubeMapEffectImpl::GetReflectivity() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto data = reflectivityConstant->GetStorage();

    return data.Increase<float>();
}

Rendering::CubeMapEffectImpl::ConstConstantBufferSharedPtr Rendering::CubeMapEffectImpl::GetReflectivityConstant() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return reflectivityConstant;
}

Rendering::CubeMapEffectImpl::ConstantBufferSharedPtr Rendering::CubeMapEffectImpl::GetReflectivityConstant() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return reflectivityConstant;
}

void Rendering::CubeMapEffectImpl::UpdateFaces(const BaseRendererSharedPtr& baseRenderer,
                                               const SpatialSharedPtr& scene,
                                               Culler& culler,
                                               const APoint& envOrigin,
                                               const AVector& envDVector,
                                               const AVector& envUVector,
                                               const AVector& envRVector)
{
    RENDERING_CLASS_IS_VALID_9;

    const std::array<AVector, 6> dVector{ -envRVector, envRVector, envUVector, -envUVector, envDVector, -envDVector };

    const std::array<AVector, 6> uVector{ envUVector, envUVector, -envDVector, envDVector, envUVector, envUVector };

    const std::array<AVector, 6> rVector{ envDVector, -envDVector, envRVector, envRVector, envRVector, -envRVector };

    for (auto face = 0; face < 6; ++face)
    {
        camera->SetFrame(envOrigin, dVector.at(face), uVector.at(face), rVector.at(face));
        culler.ComputeVisibleSet(camera, scene);

        const auto pvMatrix = camera->GetProjectionViewMatrix();
        for (const auto& visual : culler)
        {
            if (const auto effect = boost::polymorphic_pointer_cast<Texture2DEffect>(visual->GetVisualEffect());
                effect != nullptr)
            {
                const auto wMatrix = visual->GetWorldTransform().GetMatrix();
                const auto pvwMatrix = (pvMatrix * wMatrix);
                effect->SetProjectionViewWorldMatrix(Matrix4{ pvwMatrix.GetColumnMajor(), Mathematics::MatrixMajorFlags::Row });
                if (!baseRenderer->Update(effect->GetProjectionViewWorldMatrixConstant()))
                {
                    LOG_SINGLETON_ENGINE_APPENDER(Info, Rendering, SYSTEM_TEXT("Update 失败"));
                }
            }
        }

        baseRenderer->Enable(target);
        baseRenderer->ClearBuffers();
        for (const auto& visual : culler)
        {
            if (!baseRenderer->Draw(*visual))
            {
                LOG_SINGLETON_ENGINE_APPENDER(Info, Rendering, SYSTEM_TEXT("Draw 失败"));
            }
        }
        baseRenderer->Disable(target);

        auto texture = target->GetRenderTargetTexture(0);
        if (!baseRenderer->CopyGpuToCpu(texture))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Info, Rendering, SYSTEM_TEXT("CopyGpuToCpu 失败"));
        };

        if (depthRangeIs01)
        {
            const auto numLevels = texture->GetNumLevels();
            for (auto level = 0; level < numLevels; ++level)
            {
                const auto uSize = texture->GetDimension(level, 0);
                const auto vSize = texture->GetDimension(level, 1);

                for (auto u = 0, uReflect = uSize - 1; u < uSize; ++u, --uReflect)
                {
                    for (auto v = 0; v < vSize; ++v)
                    {
                        const auto src = u + uSize * v;
                        const auto trg = uReflect + uSize * v;
                        auto input = texture->GetStorage(level + src * sizeof(int32_t));
                        const auto levelOffset = cubeTexture->GetLevelOffset(face, level);
                        auto output = cubeTexture->GetStorage(levelOffset + trg * sizeof(int32_t));

                        output.Increase(input.Increase<int32_t>());
                    }
                }
            }
        }
    }

    if (!baseRenderer->CopyCpuToGpu(cubeTexture))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Info, Rendering, SYSTEM_TEXT("CopyCpuToGpu 失败"));
    }
}

Rendering::CubeMapEffectImpl::TextureCubeSharedPtr Rendering::CubeMapEffectImpl::GetCubeTexture() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cubeTexture;
}

Rendering::CubeMapEffectImpl::SamplerStateSharedPtr Rendering::CubeMapEffectImpl::GetCubeSampler() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cubeSampler;
}

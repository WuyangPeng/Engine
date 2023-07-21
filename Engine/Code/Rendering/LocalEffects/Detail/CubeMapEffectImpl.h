///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/11 15:46)

#ifndef RENDERING_LOCAL_EFFECTS_CUBE_MAP_EFFECT_IMPL_H
#define RENDERING_LOCAL_EFFECTS_CUBE_MAP_EFFECT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Matrix4.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/SceneGraph/SceneGraphFwd.h"
#include "Rendering/State/StateFwd.h"

#include <memory>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE CubeMapEffectImpl
    {
    public:
        using ClassType = CubeMapEffectImpl;

        using ConstantBufferSharedPtr = std::shared_ptr<ConstantBuffer>;
        using ConstConstantBufferSharedPtr = std::shared_ptr<const ConstantBuffer>;

        using TextureCubeSharedPtr = std::shared_ptr<TextureCube>;
        using ConstTextureCubeSharedPtr = std::shared_ptr<const TextureCube>;

        using SamplerStateSharedPtr = std::shared_ptr<SamplerState>;
        using ConstSamplerStateSharedPtr = std::shared_ptr<const SamplerState>;

        using CameraSharedPtr = std::shared_ptr<Camera>;
        using ConstCameraSharedPtr = std::shared_ptr<const Camera>;

        using DrawTargetSharedPtr = std::shared_ptr<DrawTarget>;
        using ConstDrawTargetSharedPtr = std::shared_ptr<const DrawTarget>;

        using BaseRendererSharedPtr = std::shared_ptr<BaseRenderer>;

        using SpatialSharedPtr = std::shared_ptr<Spatial>;

        using Matrix4 = Mathematics::Matrix4F;
        using Vector4 = Mathematics::Vector4F;
        using AVector = Mathematics::AVectorF;
        using APoint = Mathematics::APointF;

    public:
        CubeMapEffectImpl() noexcept;
        CubeMapEffectImpl(TextureCubeSharedPtr texture,
                          SamplerStateFilter filter,
                          SamplerStateMode mode0,
                          SamplerStateMode mode1,
                          float reflectivity,
                          bool depthRangeIs01,
                          int numWorldMatrixConstantBytes,
                          int numCameraWorldPositionConstantBytes,
                          int numReflectivityConstantBytes);

        CLASS_INVARIANT_DECLARE;

        void UseDynamicUpdates(float dMin, float dMax);

        void SetWorldMatrix(const Matrix4& worldMatrix);
        NODISCARD Matrix4 GetWorldMatrix() const;

        NODISCARD ConstConstantBufferSharedPtr GetWorldMatrixConstant() const noexcept;
        NODISCARD ConstantBufferSharedPtr GetWorldMatrixConstant() noexcept;

        void SetCameraWorldPosition(const Vector4& cameraWorldPosition);
        Vector4 GetCameraWorldPosition() const;

        NODISCARD ConstConstantBufferSharedPtr GetCameraWorldPositionConstant() const noexcept;
        NODISCARD ConstantBufferSharedPtr GetCameraWorldPositionConstant() noexcept;

        NODISCARD float GetReflectivity() const;
        void SetReflectivity(float reflectivity);

        NODISCARD ConstConstantBufferSharedPtr GetReflectivityConstant() const noexcept;
        NODISCARD ConstantBufferSharedPtr GetReflectivityConstant() noexcept;

        void UpdateFaces(const BaseRendererSharedPtr& baseRenderer,
                         const SpatialSharedPtr& scene,
                         Culler& culler,
                         const APoint& envOrigin,
                         const AVector& envDVector,
                         const AVector& envUVector,
                         const AVector& envRVector);

        NODISCARD TextureCubeSharedPtr GetCubeTexture() const noexcept;
        NODISCARD SamplerStateSharedPtr GetCubeSampler() const noexcept;

    private:
        ConstantBufferSharedPtr worldMatrixConstant;
        ConstantBufferSharedPtr cameraWorldPositionConstant;
        ConstantBufferSharedPtr reflectivityConstant;
        TextureCubeSharedPtr cubeTexture;
        SamplerStateSharedPtr cubeSampler;
        CameraSharedPtr camera;
        DrawTargetSharedPtr target;
        bool depthRangeIs01;
        bool dynamicUpdates;
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_CUBE_MAP_EFFECT_IMPL_H

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/10 16:15)

#ifndef RENDERING_LOCAL_EFFECTS_CUBE_MAP_EFFECT_H
#define RENDERING_LOCAL_EFFECTS_CUBE_MAP_EFFECT_H

#include "VisualEffect.h"
#include "Rendering/RenderingDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Mathematics/Algebra/APoint.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/SceneGraph/SceneGraphFwd.h"
#include "Rendering/State/StateFwd.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(CubeMapEffect, CubeMapEffectImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE CubeMapEffect : public VisualEffect
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(CubeMapEffect);
        using ParentType = VisualEffect;

        using TextureCubeSharedPtr = std::shared_ptr<TextureCube>;

        using Matrix4 = Mathematics::Matrix4F;
        using Vector4 = Mathematics::Vector4F;
        using AVector = Mathematics::AVectorF;
        using APoint = Mathematics::APointF;

        using SpatialSharedPtr = std::shared_ptr<Spatial>;

    public:
        CubeMapEffect(ProgramFactory& factory,
                      const BaseRendererSharedPtr& baseRenderer,
                      const TextureCubeSharedPtr& texture,
                      SamplerStateFilter filter,
                      SamplerStateMode mode0,
                      SamplerStateMode mode1,
                      float reflectivity);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(CubeMapEffect);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        void SetProjectionViewWorldMatrixConstant(const ConstantBufferSharedPtr& buffer) override;

        void UseDynamicUpdates(float dMin, float dMax);

        void SetWorldMatrix(const Matrix4& worldMatrix);
        NODISCARD Matrix4 GetWorldMatrix() const;

        NODISCARD ConstConstantBufferSharedPtr GetWorldMatrixConstant() const noexcept;

        void SetCameraWorldPosition(const Vector4& cameraWorldPosition);
        Vector4 GetCameraWorldPosition() const;

        NODISCARD ConstConstantBufferSharedPtr GetCameraWorldPositionConstant() const noexcept;

        NODISCARD float GetReflectivity() const;
        void SetReflectivity(float reflectivity);

        NODISCARD ConstConstantBufferSharedPtr GetReflectivityConstant() const noexcept;

        void UpdateFaces(const BaseRendererSharedPtr& baseRenderer,
                         const SpatialSharedPtr& scene,
                         Culler& culler,
                         const APoint& envOrigin,
                         const AVector& envDVector,
                         const AVector& envUVector,
                         const AVector& envRVector);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_CUBE_MAP_EFFECT_H

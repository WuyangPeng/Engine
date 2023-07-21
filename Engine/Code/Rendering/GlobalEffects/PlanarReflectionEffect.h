///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/17 15:57)

#ifndef RENDERING_GLOBAL_EFFECTS_PLANAR_REFLECTION_EFFECT_H
#define RENDERING_GLOBAL_EFFECTS_PLANAR_REFLECTION_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Mathematics/Algebra/Vector4.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"
#include "Rendering/SceneGraph/SceneGraphFwd.h"
#include "Rendering/State/StateFwd.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(PlanarReflectionEffect, PlanarReflectionEffectImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE PlanarReflectionEffect
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(PlanarReflectionEffect);

        using NodeSharedPtr = std::shared_ptr<Node>;
        using VisualSharedPtr = std::shared_ptr<Visual>;
        using VisualContainer = std::vector<VisualSharedPtr>;
        using ReflectanceType = std::vector<float>;
        using Vector4 = Mathematics::Vector4<float>;
        using Vector4Container = std::vector<Vector4>;
        using BlendStateSharedPtr = std::shared_ptr<BlendState>;
        using RasterizerStateSharedPtr = std::shared_ptr<RasterizerState>;
        using DepthStencilStateSharedPtr = std::shared_ptr<DepthStencilState>;
        using BaseRendererSharedPtr = std::shared_ptr<BaseRenderer>;
        using SpatialSharedPtr = std::shared_ptr<Spatial>;

    public:
        PlanarReflectionEffect(const NodeSharedPtr& reflectionCaster,
                               const VisualContainer& planeVisuals,
                               const ReflectanceType& reflectances);

        CLASS_INVARIANT_DECLARE;

        void Draw(const BaseRendererSharedPtr& engine, ProjectionViewWorldUpdater& projectionViewWorldMatrices);

        NODISCARD VisualContainer GetPlaneVisuals() const;

        NODISCARD Vector4Container GetPlaneOrigins() const;

        NODISCARD Vector4Container GetPlaneNormals() const;

        void SetReflectance(int index, float reflectance);

        NODISCARD float GetReflectance(int index) const;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_GLOBAL_EFFECTS_PLANAR_REFLECTION_EFFECT_H

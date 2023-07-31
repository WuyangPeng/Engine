///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/17 15:59)

#ifndef RENDERING_GLOBAL_EFFECTS_PLANAR_SHADOW_EFFECT_H
#define RENDERING_GLOBAL_EFFECTS_PLANAR_SHADOW_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Rendering/GlobalEffects/GlobalEffectsFwd.h"
#include "Rendering/LocalEffects/LocalEffectsFwd.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"
#include "Rendering/SceneGraph/SceneGraphFwd.h"
#include "Rendering/Shaders/ShadersFwd.h"
#include "Rendering/State/StateFwd.h"

#include <vector>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(PlanarShadowEffect, PlanarShadowEffectImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE PlanarShadowEffect
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(PlanarShadowEffect);

        using NodeSharedPtr = std::shared_ptr<Node>;
        using VisualSharedPtr = std::shared_ptr<Visual>;
        using VisualContainer = std::vector<VisualSharedPtr>;
        using Vector4 = Mathematics::Vector4<float>;
        using Vector4Container = std::vector<Vector4>;
        using BlendStateSharedPtr = std::shared_ptr<BlendState>;
        using DepthStencilStateSharedPtr = std::shared_ptr<DepthStencilState>;
        using ConstantColorEffectSharedPtr = std::shared_ptr<ConstantColorEffect>;
        using ConstantColorEffectContainer = std::vector<ConstantColorEffectSharedPtr>;
        using VisualEffectSharedPtr = std::shared_ptr<VisualEffect>;
        using VisualEffectContainer = std::vector<VisualEffectSharedPtr>;
        using ModelSpaceTrianglesType = std::vector<std::array<Vector4, 3>>;
        using ProgramFactorySharedPtr = std::shared_ptr<ProgramFactory>;
        using BaseRendererSharedPtr = std::shared_ptr<BaseRenderer>;
        using Matrix4 = Mathematics::Matrix4<float>;
        using Matrix = Mathematics::Matrix<float>;
        using SpatialSharedPtr = std::shared_ptr<Spatial>;
        using LightProjectorSharedPtr = std::shared_ptr<LightProjector>;

    public:
        explicit PlanarShadowEffect(const BaseRendererSharedPtr& engine,
                                    const ProgramFactorySharedPtr& factory,
                                    const NodeSharedPtr& shadowCaster,
                                    const LightProjectorSharedPtr& lightProjector,
                                    const VisualContainer& planeVisuals,
                                    const Vector4Container& shadowColors);

        CLASS_INVARIANT_DECLARE;

        void Draw(const BaseRendererSharedPtr& engine, ProjectionViewWorldUpdater& projectionViewWorldMatrices);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_GLOBAL_EFFECTS_PLANAR_SHADOW_EFFECT_H

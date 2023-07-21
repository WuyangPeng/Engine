///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/17 15:55)

#ifndef RENDERING_GLOBAL_EFFECTS_PLANAR_REFLECTION_EFFECT_IMPL_H
#define RENDERING_GLOBAL_EFFECTS_PLANAR_REFLECTION_EFFECT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/Vector4.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"
#include "Rendering/SceneGraph/SceneGraphFwd.h"
#include "Rendering/State/StateFwd.h"

#include <memory>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE PlanarReflectionEffectImpl
    {
    public:
        using ClassType = PlanarReflectionEffectImpl;

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
        PlanarReflectionEffectImpl(const NodeSharedPtr& reflectionCaster,
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
        void GatherVisuals(const SpatialSharedPtr& spatial);
        void GetModelSpacePlanes();

    private:
        NodeSharedPtr reflectionCaster;
        VisualContainer planeVisuals;
        ReflectanceType reflectances;

        VisualContainer casterVisuals;
        Vector4Container planeOrigins;
        Vector4Container planeNormals;

        BlendStateSharedPtr noColorWrites;
        BlendStateSharedPtr reflectanceBlend;
        RasterizerStateSharedPtr cullReverse;
        DepthStencilStateSharedPtr dSPass0;
        DepthStencilStateSharedPtr dSPass1;
        DepthStencilStateSharedPtr dSPass2;
        DepthStencilStateSharedPtr dSPass3;
    };
}

#endif  // RENDERING_GLOBAL_EFFECTS_PLANAR_REFLECTION_EFFECT_IMPL_H

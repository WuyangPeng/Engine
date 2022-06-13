///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/15 14:14)

#ifndef RENDERING_GLOBAL_EFFECTS_PLANAR_SHADOW_EFFECT_H
#define RENDERING_GLOBAL_EFFECTS_PLANAR_SHADOW_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "GlobalEffect.h"
#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Mathematics/Base/Float.h"
#include "Rendering/LocalEffects/MaterialEffect.h"
#include "Rendering/SceneGraph/Light.h"
#include "Rendering/SceneGraph/Node.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"

namespace Rendering
{
    class PlanarShadowEffect : public GlobalEffect
    {
    public:
        using ClassType = PlanarShadowEffect;
        using ParentType = GlobalEffect;

    private:
        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(PlanarShadowEffect);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

    public:
        PlanarShadowEffect(int numPlanes, const NodeSharedPtr& shadowCaster);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Draw(Renderer& renderer, VisibleSet& visibleSet) override;

        NODISCARD int GetNumPlanes() const noexcept;
        void SetPlane(int i, const TrianglesMeshSharedPtr& plane);
        NODISCARD ConstTrianglesMeshSharedPtr GetPlane(int i) const;
        void SetProjector(int i, Light* projector);
        NODISCARD ConstLightSharedPtr GetProjector(int i) const;
        void SetShadowColor(int i, const Mathematics::Float4& shadowColor);
        NODISCARD const Mathematics::Float4& GetShadowColor(int i) const;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    protected:
        NODISCARD bool GetProjectionMatrix(int i, Mathematics::MatrixF& projection);

    private:
        int numPlanes;
        std::vector<CoreTools::ObjectAssociated<TrianglesMesh>> planes;
        std::vector<CoreTools::ObjectAssociated<Light>> projectors;
        std::vector<Mathematics::Float4> shadowColors;
        CoreTools::ObjectAssociated<Node> shadowCaster;

        AlphaStateSharedPtr alphaState;
        DepthStateSharedPtr depthState;
        StencilStateSharedPtr stencilState;

        MaterialSharedPtr material;
        MaterialEffectSharedPtr materialEffect;
        VisualEffectInstanceSharedPtr materialEffectInstance;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(PlanarShadowEffect);
}

#endif  // RENDERING_GLOBAL_EFFECTS_PLANAR_SHADOW_EFFECT_H

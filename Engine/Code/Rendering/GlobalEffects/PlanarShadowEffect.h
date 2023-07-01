///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:48)

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

        void Draw(BaseRenderer& renderer, VisibleSet& visibleSet) noexcept override;

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

        MaterialSharedPtr material;
        MaterialEffectSharedPtr materialEffect;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(PlanarShadowEffect);
}

#endif  // RENDERING_GLOBAL_EFFECTS_PLANAR_SHADOW_EFFECT_H

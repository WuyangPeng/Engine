///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/15 13:48)

#ifndef RENDERING_GLOBAL_EFFECTS_PLANAR_REFLECTION_EFFECT_H
#define RENDERING_GLOBAL_EFFECTS_PLANAR_REFLECTION_EFFECT_H

#include "GlobalEffect.h"
#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Mathematics/Algebra/Plane.h"
#include "Rendering/RenderingDll.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"

namespace Rendering
{
    class PlanarReflectionEffect : public GlobalEffect
    {
    public:
        using ClassType = PlanarReflectionEffect;
        using ParentType = GlobalEffect;

    private:
        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(PlanarReflectionEffect);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

    public:
        explicit PlanarReflectionEffect(int numPlanes);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Draw(Renderer& renderer, VisibleSet& visibleSet) override;

        NODISCARD int GetNumPlanes() const noexcept;
        void SetPlane(int i, const TrianglesMeshSharedPtr& plane);
        NODISCARD ConstTrianglesMeshSharedPtr GetPlane(int i) const;
        void SetReflectance(int i, float reflectance);
        NODISCARD float GetReflectance(int i) const;

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    protected:
        void GetReflectionMatrixAndModelPlane(int i, Mathematics::MatrixF& reflection, Mathematics::PlaneF& modelPlane);

    private:
        int numPlanes;
        std::vector<CoreTools::ObjectAssociated<TrianglesMesh>> planes;
        std::vector<float> reflectances;

        CoreTools::ObjectAssociated<AlphaState> alphaState;
        CoreTools::ObjectAssociated<DepthState> depthState;
        CoreTools::ObjectAssociated<StencilState> stencilState;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(PlanarReflectionEffect);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(PlanarReflectionEffect);
}

#endif  // RENDERING_GLOBAL_EFFECTS_PLANAR_REFLECTION_EFFECT_H

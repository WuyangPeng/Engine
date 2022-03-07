// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 15:27)

#ifndef RENDERING_GLOBAL_EFFECTS_PLANAR_REFLECTION_EFFECT_H
#define RENDERING_GLOBAL_EFFECTS_PLANAR_REFLECTION_EFFECT_H

#include "Rendering/RenderingDll.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "GlobalEffect.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Mathematics/Algebra/Plane.h"
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
        // Construction and destruction.  The number of planes supported depends
        // on the number of stencil bits (256 for an 8-bit stencil buffer).
        explicit PlanarReflectionEffect(int numPlanes);
        ~PlanarReflectionEffect();
        PlanarReflectionEffect(const PlanarReflectionEffect&) = default;
        PlanarReflectionEffect& operator=(const PlanarReflectionEffect&) = default;
        PlanarReflectionEffect( PlanarReflectionEffect&&) = default;
        PlanarReflectionEffect& operator=( PlanarReflectionEffect&&) = default;

        void Draw(std::shared_ptr<Renderer> renderer, VisibleSet& visibleSet) override;

        // Member access.
        int GetNumPlanes() const noexcept;
        void SetPlane(int i, TrianglesMeshSharedPtr plane);
        ConstTrianglesMeshSharedPtr GetPlane(int i) const noexcept;
        void SetReflectance(int i, float reflectance) noexcept;
        float GetReflectance(int i) const noexcept;

           ObjectInterfaceSharedPtr CloneObject() const override;

    protected:
        void GetReflectionMatrixAndModelPlane(int i, Mathematics::MatrixF& reflection, Mathematics::PlaneF& modelPlane);

        int mNumPlanes;
        TrianglesMeshSharedPtr* mPlanes;
        float* mReflectances;

        // Global render state for drawing.
        AlphaStateSharedPtr mAlphaState;
        DepthStateSharedPtr mDepthState;
        StencilStateSharedPtr mStencilState;
    };
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(PlanarReflectionEffect);
    CORE_TOOLS_SHARED_PTR_DECLARE( PlanarReflectionEffect);
#include STSTEM_WARNING_POP
}

#endif  // RENDERING_GLOBAL_EFFECTS_PLANAR_REFLECTION_EFFECT_H

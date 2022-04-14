// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/07 16:59)

#ifndef RENDERING_CURVES_SURFACES_SUITE_TEST_SURFACE_PATCH__H
#define RENDERING_CURVES_SURFACES_SUITE_TEST_SURFACE_PATCH__H

#include "Rendering/CurvesSurfaces/SurfacePatch.h"

namespace Rendering
{
    class TestSurfacePatch : public SurfacePatch
    {
    public:
        using ClassType = TestSurfacePatch;
        using ParentType = SurfacePatch;

    public:
        TestSurfacePatch(float uMin, float uMax, float vMin, float vMax, bool rectangular);
 

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(TestSurfacePatch);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
        [[nodiscard]] ObjectInterfaceSharedPtr CloneObject() const override;
        const APoint GetPosition(float u, float v) const override;
        const AVector GetDerivativesU(float u, float v) const override;
        const AVector GetDerivativesV(float u, float v) const override;
        const AVector GetDerivativesUU(float u, float v) const override;
        const AVector GetDerivativesUV(float u, float v) const override;
        const AVector GetDerivativesVV(float u, float v) const override;
    };

}

#endif  // RENDERING_CURVES_SURFACES_SURFACE_PATCH_H

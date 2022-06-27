///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/16 18:53)

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

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;
        NODISCARD APoint GetPosition(float u, float v) const override;
        NODISCARD AVector GetDerivativesU(float u, float v) const override;
        NODISCARD AVector GetDerivativesV(float u, float v) const override;
        NODISCARD AVector GetDerivativesUU(float u, float v) const override;
        NODISCARD AVector GetDerivativesUV(float u, float v) const override;
        NODISCARD AVector GetDerivativesVV(float u, float v) const override;
    };

}

#endif  // RENDERING_CURVES_SURFACES_SURFACE_PATCH_H

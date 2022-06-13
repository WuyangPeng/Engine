///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/15 17:15)

#ifndef RENDERING_CURVES_SURFACES_BSPLINE_SURFACE_PATCH_H
#define RENDERING_CURVES_SURFACES_BSPLINE_SURFACE_PATCH_H

#include "Rendering/RenderingDll.h"

#include "SurfacePatch.h"
#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/CurvesSurfacesVolumes/BSplineRectangle.h"

namespace Rendering
{
    class BSplineSurfacePatch : public SurfacePatch
    {
    private:
        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(BSplineSurfacePatch);

    public:
        using ClassType = BSplineSurfacePatch;
        using ParentType = SurfacePatch;

    public:
        // (OU,OU), (OU,PU), (PU,OU), or (PU,PU)
        BSplineSurfacePatch(int numUCtrlPoints, int numVCtrlPoints, const std::vector<std::vector<Mathematics::Vector3F>>& ctrlPoints, int uDegree, int vDegree, bool uLoop, bool vLoop, bool uOpen, bool vOpen);

        // (OU,ON) or (PU,ON)
        BSplineSurfacePatch(int numUCtrlPoints, int numVCtrlPoints, const std::vector<std::vector<Mathematics::Vector3F>>& ctrlPoints, int uDegree, int vDegree, bool uLoop, bool vLoop, bool uOpen, float* vKnots);

        // (ON,OU) or (ON,PU)
        BSplineSurfacePatch(int numUCtrlPoints, int numVCtrlPoints, const std::vector<std::vector<Mathematics::Vector3F>>& ctrlPoints, int uDegree, int vDegree, bool uLoop, bool vLoop, float* uKnots, bool vOpen);

        // (ON,ON)
        BSplineSurfacePatch(int numUCtrlPoints, int numVCtrlPoints, const std::vector<std::vector<Mathematics::Vector3F>>& ctrlPoints, int uDegree, int vDegree, bool uLoop, bool vLoop, float* uKnots, float* vKnots);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD APoint GetPosition(float u, float v) const override;
        NODISCARD AVector GetDerivativesU(float u, float v) const override;
        NODISCARD AVector GetDerivativesV(float u, float v) const override;
        NODISCARD AVector GetDerivativesUU(float u, float v) const override;
        NODISCARD AVector GetDerivativesUV(float u, float v) const override;
        NODISCARD AVector GetDerivativesVV(float u, float v) const override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        int constructor;

        std::shared_ptr<Mathematics::BSplineRectangle<float>> patch;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(BSplineSurfacePatch);
}

#endif  // RENDERING_CURVES_SURFACES_BSPLINE_SURFACE_PATCH_H

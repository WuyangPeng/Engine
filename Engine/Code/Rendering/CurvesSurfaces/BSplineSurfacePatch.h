// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/25 15:52)

#ifndef RENDERING_CURVES_SURFACES_BSPLINE_SURFACE_PATCH_H
#define RENDERING_CURVES_SURFACES_BSPLINE_SURFACE_PATCH_H

#include "Rendering/RenderingDll.h"

#include "SurfacePatch.h"
#include "Mathematics/Algebra/Vector3D.h"
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
        // Construction and destruction.   The caller is responsible for deleting
        // the input arrays if they were dynamically allocated.  Internal copies
        // of the arrays are made, so to dynamically change control points or
        // knots you must use the 'SetControlPoint' and 'SetKnot' member functions
        // of BSplineRectanglef.  Spline types for curves are
        //   open uniform (OU)
        //   periodic uniform (PU)
        //   open nonuniform (ON)
        // For tensor product surfaces, you have to choose a type for each of two
        // dimensions, leading to nine possible spline types for surfaces.  The
        // constructors below represent these choices.

        // (OU,OU), (OU,PU), (PU,OU), or (PU,PU)
        BSplineSurfacePatch(int numUCtrlPoints, int numVCtrlPoints, Mathematics::FloatVector3D** ctrlPoints, int uDegree, int vDegree, bool uLoop, bool vLoop, bool uOpen, bool vOpen);

        // (OU,ON) or (PU,ON)
        BSplineSurfacePatch(int numUCtrlPoints, int numVCtrlPoints, Mathematics::FloatVector3D** ctrlPoints, int uDegree, int vDegree, bool uLoop, bool vLoop, bool uOpen, float* vKnots);

        // (ON,OU) or (ON,PU)
        BSplineSurfacePatch(int numUCtrlPoints, int numVCtrlPoints, Mathematics::FloatVector3D** ctrlPoints, int uDegree, int vDegree, bool uLoop, bool vLoop, float* uKnots, bool vOpen);

        // (ON,ON)
        BSplineSurfacePatch(int numUCtrlPoints, int numVCtrlPoints, Mathematics::FloatVector3D** ctrlPoints, int uDegree, int vDegree, bool uLoop, bool vLoop, float* uKnots, float* vKnots);

        ~BSplineSurfacePatch();

        BSplineSurfacePatch(const BSplineSurfacePatch&) = default;
        BSplineSurfacePatch& operator=(const BSplineSurfacePatch&) = default;
        BSplineSurfacePatch(BSplineSurfacePatch&&) = default;
        BSplineSurfacePatch& operator=(BSplineSurfacePatch&&) = default;

        // Position and derivatives up to second order.
        const APoint GetPosition(float u, float v) const override;
        const AVector GetDerivativesU(float u, float v) const override;
        const AVector GetDerivativesV(float u, float v) const override;
        const AVector GetDerivativesUU(float u, float v) const override;
        const AVector GetDerivativesUV(float u, float v) const override;
        const AVector GetDerivativesVV(float u, float v) const override;
        ObjectInterfaceSharedPtr CloneObject() const override;
    protected:
        // The class has four constructors, not counting the default one used
        // for streaming.  The correct constructor needs to be called on a stream
        // load operation, so this data member stores that information.  The
        // value is 1, 2, 3, or 4 and refers to the order of the four nondefault
        // constructors listed previously.
        int mConstructor;

        Mathematics::BSplineRectanglef* mPatch;
    };
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(BSplineSurfacePatch);
    CORE_TOOLS_SHARED_PTR_DECLARE( BSplineSurfacePatch);
#include STSTEM_WARNING_POP
}

#endif  // RENDERING_CURVES_SURFACES_BSPLINE_SURFACE_PATCH_H

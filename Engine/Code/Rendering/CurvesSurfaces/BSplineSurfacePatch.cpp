// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/25 16:29)

#include "Rendering/RenderingExport.h"

#include "BSplineSurfacePatch.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/CurvesSurfacesVolumes/BSplineBasisDetail.h"
#include "Mathematics/CurvesSurfacesVolumes/BSplineRectangleDetail.h"
#include "Mathematics/CurvesSurfacesVolumes/ParametricSurfaceDetail.h"
#include "Mathematics/CurvesSurfacesVolumes/SurfaceDetail.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26451)
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
CORE_TOOLS_RTTI_DEFINE(Rendering, BSplineSurfacePatch);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, BSplineSurfacePatch);
CORE_TOOLS_FACTORY_DEFINE(Rendering, BSplineSurfacePatch);

Rendering::BSplineSurfacePatch ::BSplineSurfacePatch(int numUCtrlPoints, int numVCtrlPoints, Mathematics::FloatVector3D** ctrlPoints, int uDegree, int vDegree, bool uLoop, bool vLoop, bool uOpen, bool vOpen)
    : SurfacePatch(0.0f, 1.0f, 0.0f, 1.0f, true), mConstructor(1)
{
    mPatch = new Mathematics::BSplineRectanglef(numUCtrlPoints, numVCtrlPoints, ctrlPoints, uDegree, vDegree, uLoop, vLoop, uOpen, vOpen);
}

Rendering::BSplineSurfacePatch ::BSplineSurfacePatch(int numUCtrlPoints, int numVCtrlPoints, Mathematics::FloatVector3D** ctrlPoints, int uDegree, int vDegree, bool uLoop, bool vLoop, bool uOpen, float* vKnots)
    : SurfacePatch(0.0f, 1.0f, 0.0f, 1.0f, true), mConstructor(2)
{
    mPatch = new Mathematics::BSplineRectanglef(numUCtrlPoints, numVCtrlPoints, ctrlPoints, uDegree, vDegree, uLoop, vLoop, uOpen, vKnots);
}

Rendering::BSplineSurfacePatch ::BSplineSurfacePatch(int numUCtrlPoints, int numVCtrlPoints, Mathematics::FloatVector3D** ctrlPoints, int uDegree, int vDegree, bool uLoop, bool vLoop, float* uKnots, bool vOpen)
    : SurfacePatch(0.0f, 1.0f, 0.0f, 1.0f, true), mConstructor(3)
{
    mPatch = new Mathematics::BSplineRectanglef(numUCtrlPoints, numVCtrlPoints, ctrlPoints, uDegree, vDegree, uLoop, vLoop, uKnots, vOpen);
}

Rendering::BSplineSurfacePatch ::BSplineSurfacePatch(int numUCtrlPoints, int numVCtrlPoints, Mathematics::FloatVector3D** ctrlPoints, int uDegree, int vDegree, bool uLoop, bool vLoop, float* uKnots, float* vKnots)
    : SurfacePatch(0.0f, 1.0f, 0.0f, 1.0f, true), mConstructor(4)
{
    mPatch = new Mathematics::BSplineRectanglef(numUCtrlPoints, numVCtrlPoints, ctrlPoints, uDegree, vDegree, uLoop, vLoop, uKnots, vKnots);
}

Rendering::BSplineSurfacePatch ::~BSplineSurfacePatch()
{
    EXCEPTION_TRY
    {
        // DELETE1(mPatch);
    }
    EXCEPTION_ALL_CATCH(Rendering)
}

const Mathematics::FloatAPoint Rendering::BSplineSurfacePatch ::GetPosition(float u, float v) const
{
    Mathematics::FloatVector3D p = mPatch->P(u, v);
    return APoint(p[0], p[1], p[2]);
}

const Mathematics::FloatAVector Rendering::BSplineSurfacePatch ::GetDerivativesU(float u, float v) const
{
    Mathematics::FloatVector3D pu = mPatch->PU(u, v);
    return AVector(pu[0], pu[1], pu[2]);
}

const Mathematics::FloatAVector Rendering::BSplineSurfacePatch ::GetDerivativesV(float u, float v) const
{
    Mathematics::FloatVector3D pv = mPatch->PV(u, v);
    return AVector(pv[0], pv[1], pv[2]);
}

const Mathematics::FloatAVector Rendering::BSplineSurfacePatch ::GetDerivativesUU(float u, float v) const
{
    Mathematics::FloatVector3D puu = mPatch->PUU(u, v);
    return AVector(puu[0], puu[1], puu[2]);
}

const Mathematics::FloatAVector Rendering::BSplineSurfacePatch ::GetDerivativesUV(float u, float v) const
{
    Mathematics::FloatVector3D puv = mPatch->PUV(u, v);
    return AVector(puv[0], puv[1], puv[2]);
}

const Mathematics::FloatAVector Rendering::BSplineSurfacePatch ::GetDerivativesVV(float u, float v) const
{
    Mathematics::FloatVector3D pvv = mPatch->PVV(u, v);
    return AVector(pvv[0], pvv[1], pvv[2]);
}

// Streaming support.

Rendering::BSplineSurfacePatch ::BSplineSurfacePatch(LoadConstructor value)
    : SurfacePatch(value), mConstructor(0), mPatch(0)
{
}

void Rendering::BSplineSurfacePatch ::Load(CoreTools::BufferSource& source)
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    SurfacePatch::Load(source);

    source.Read(mConstructor);

    int numCtrlPoints0, numCtrlPoints1;
    source.Read(numCtrlPoints0);
    source.Read(numCtrlPoints1);
    Mathematics::FloatVector3D** ctrl = nullptr;  //    NEW2<Mathematics::FloatVector3D>(numCtrlPoints1, numCtrlPoints0);
    int i0 = 0, i1 = 0;
    for (i0 = 0; i0 < numCtrlPoints0; ++i0)
    {
        for (i1 = 0; i1 < numCtrlPoints1; ++i1)
        {
            source.ReadAggregate(ctrl[i0][i1]);
        }
    }

    int degree0, degree1;
    source.Read(degree0);
    source.Read(degree1);

    bool loop0 = false, loop1 = false;
    loop0 = source.ReadBool();
    loop1 = source.ReadBool();

    bool open0 = false, open1 = false;
//     float* knot0 = nullptr;
//     float* knot1 = nullptr;
    int numKnots0 = 0, numKnots1 = 0;

    switch (mConstructor)
    {
        case 1:
            open0 = source.ReadBool();
            open1 = source.ReadBool();

            mPatch = nullptr;  // new Mathematics::BSplineRectanglef(numCtrlPoints0, numCtrlPoints1, ctrl, degree0, degree1, loop0, loop1, open0, open1);
            break;
        case 2:
            open0 = source.ReadBool();
            numKnots1 = numCtrlPoints1 - degree1 - 1;
            //   source.Read(numKnots1, knot1);

            mPatch = nullptr;  // new Mathematics::BSplineRectanglef(numCtrlPoints0, numCtrlPoints1, ctrl, degree0, degree1, loop0, loop1, open0, knot1);

            //DELETE1(knot1);
            break;
        case 3:
            numKnots0 = numCtrlPoints0 - degree0 - 1;
            //    source.Read(numKnots0, knot0);
            open1 = source.ReadBool();

            mPatch = nullptr;  //  new Mathematics::BSplineRectanglef(numCtrlPoints0, numCtrlPoints1, ctrl, degree0, degree1, loop0, loop1, knot0, open1);

          //  DELETE1(knot0);
            break;
        case 4:
            numKnots0 = numCtrlPoints0 - degree0 - 1;
            //   source.Read(numKnots0, knot0);
            numKnots1 = numCtrlPoints1 - degree1 - 1;
            //   source.Read(numKnots1, knot1);

            mPatch = nullptr;  // new Mathematics::BSplineRectanglef(numCtrlPoints0, numCtrlPoints1, ctrl, degree0, degree1, loop0, loop1, knot0, knot1);

          //  DELETE1(knot0);
          //  DELETE1(knot1);
            break;
        default:
            RENDERING_ASSERTION_0(false, "Unexpected condition\n");
    }

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::BSplineSurfacePatch ::Link(CoreTools::ObjectLink& source)
{
    SurfacePatch::Link(source);
}

void Rendering::BSplineSurfacePatch ::PostLink()
{
    SurfacePatch::PostLink();
}

uint64_t Rendering::BSplineSurfacePatch ::Register(CoreTools::ObjectRegister& target) const
{
    return SurfacePatch::Register(target);
}

void Rendering::BSplineSurfacePatch ::Save(CoreTools::BufferTarget& target) const
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    SurfacePatch::Save(target);

    target.Write(mConstructor);

    const int numCtrlPoints0 = mPatch->GetNumCtrlPoints(0);
    const int numCtrlPoints1 = mPatch->GetNumCtrlPoints(1);
    target.Write(numCtrlPoints0);
    target.Write(numCtrlPoints1);
    int i0 = 0, i1 = 0;
    for (i0 = 0; i0 < numCtrlPoints0; ++i0)
    {
        for (i1 = 0; i1 < numCtrlPoints1; ++i1)
        {
            target.WriteAggregate(mPatch->GetControlPoint(i0, i1));
        }
    }

    const int degree0 = mPatch->GetDegree(0);
    const int degree1 = mPatch->GetDegree(1);
    target.Write(degree0);
    target.Write(degree1);

    const bool loop0 = mPatch->IsLoop(0);
    const bool loop1 = mPatch->IsLoop(1);
    target.Write(loop0);
    target.Write(loop1);

    bool open0 = false, open1 = false;
    int numKnots0 = 0, numKnots1 = 0;

    switch (mConstructor)
    {
        case 1:
            open0 = mPatch->IsOpen(0);
            target.Write(open0);
            open1 = mPatch->IsOpen(1);
            target.Write(open1);
            break;
        case 2:
            open0 = mPatch->IsOpen(0);
            target.Write(open0);
            numKnots1 = numCtrlPoints1 - degree1 - 1;
            for (i1 = 0; i1 < numKnots1; ++i1)
            {
                target.Write(mPatch->GetKnot(1, i1));
            }
            break;
        case 3:
            numKnots0 = numCtrlPoints0 - degree0 - 1;
            for (i0 = 0; i0 < numKnots0; ++i0)
            {
                target.Write(mPatch->GetKnot(0, i0));
            }

            open1 = mPatch->IsOpen(1);
            target.Write(open1);
            break;
        case 4:
            numKnots0 = numCtrlPoints0 - degree0 - 1;
            for (i0 = 0; i0 < numKnots0; ++i0)
            {
                target.Write(mPatch->GetKnot(0, i0));
            }

            numKnots1 = numCtrlPoints1 - degree1 - 1;
            for (i1 = 0; i1 < numKnots1; ++i1)
            {
                target.Write(mPatch->GetKnot(1, i1));
            }
            break;
        default:
            RENDERING_ASSERTION_0(false, "Unexpected condition\n");
    }

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::BSplineSurfacePatch ::GetStreamingSize() const
{
    int size = SurfacePatch::GetStreamingSize();
    size += sizeof(mConstructor);

    const int numCtrlPoints0 = mPatch->GetNumCtrlPoints(0);
    const int numCtrlPoints1 = mPatch->GetNumCtrlPoints(1);
    const int degree0 = mPatch->GetDegree(0);
    const int degree1 = mPatch->GetDegree(1);
    constexpr bool loop0 = false;
    size += sizeof(numCtrlPoints0);
    size += sizeof(numCtrlPoints1);
    size += sizeof(degree0);
    size += sizeof(degree1);
    size += 2 * CORE_TOOLS_STREAM_SIZE(loop0);  // loop0, loop1

    switch (mConstructor)
    {
        case 1:
            size += 2 * CORE_TOOLS_STREAM_SIZE(loop0);  // open0, open1
            break;
        case 2:
            size += CORE_TOOLS_STREAM_SIZE(loop0);  // open0
            size += (numCtrlPoints1 - degree1 - 1) * sizeof(float);  // knot1[]
            break;
        case 3:
            size += (numCtrlPoints0 - degree0 - 1) * sizeof(float);  // knot0[]
            size += CORE_TOOLS_STREAM_SIZE(loop0);  // open1
            break;
        case 4:
            size += (numCtrlPoints0 - degree0 - 1) * sizeof(float);  // knot0[]
            size += (numCtrlPoints1 - degree1 - 1) * sizeof(float);  // knot1[]
            break;
        default:
            RENDERING_ASSERTION_0(false, "Unexpected condition\n");
    }

    return size;
}

CoreTools::ObjectInterfaceSharedPtr Rendering::BSplineSurfacePatch::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

#include STSTEM_WARNING_POP
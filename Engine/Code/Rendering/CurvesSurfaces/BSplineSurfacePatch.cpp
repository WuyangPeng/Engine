// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/25 16:29)

#include "Rendering/RenderingExport.h"

#include "BSplineSurfacePatch.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/CurvesSurfacesVolumes/SurfaceDetail.h"
#include "Mathematics/CurvesSurfacesVolumes/BSplineRectangleDetail.h"
#include "Mathematics/CurvesSurfacesVolumes/ParametricSurfaceDetail.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, BSplineSurfacePatch);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, BSplineSurfacePatch);
CORE_TOOLS_FACTORY_DEFINE(Rendering, BSplineSurfacePatch); 

Rendering::BSplineSurfacePatch
	::BSplineSurfacePatch (int numUCtrlPoints, int numVCtrlPoints, Mathematics::Vector3Df** ctrlPoints, int uDegree, int vDegree, bool uLoop, bool vLoop, bool uOpen, bool vOpen)
    : SurfacePatch(0.0f, 1.0f, 0.0f, 1.0f, true),  mConstructor(1)
{
	mPatch = NEW0 Mathematics::BSplineRectanglef(numUCtrlPoints, numVCtrlPoints, ctrlPoints, uDegree, vDegree, uLoop, vLoop, uOpen, vOpen);
}

Rendering::BSplineSurfacePatch
	::BSplineSurfacePatch (int numUCtrlPoints, int numVCtrlPoints, Mathematics::Vector3Df** ctrlPoints, int uDegree, int vDegree, bool uLoop, bool vLoop, bool uOpen, float* vKnots)
    : SurfacePatch(0.0f, 1.0f, 0.0f, 1.0f, true), mConstructor(2)
{
	mPatch = NEW0 Mathematics::BSplineRectanglef(numUCtrlPoints, numVCtrlPoints, ctrlPoints, uDegree, vDegree, uLoop, vLoop, uOpen, vKnots);
}

Rendering::BSplineSurfacePatch
	::BSplineSurfacePatch (int numUCtrlPoints,int numVCtrlPoints, Mathematics::Vector3Df** ctrlPoints, int uDegree, int vDegree,bool uLoop, bool vLoop, float* uKnots, bool vOpen)
    :SurfacePatch(0.0f, 1.0f, 0.0f, 1.0f, true),mConstructor(3)
{
	mPatch = NEW0 Mathematics::BSplineRectanglef(numUCtrlPoints, numVCtrlPoints,ctrlPoints, uDegree, vDegree, uLoop, vLoop, uKnots, vOpen);
}

Rendering::BSplineSurfacePatch
	::BSplineSurfacePatch (int numUCtrlPoints, int numVCtrlPoints, Mathematics::Vector3Df** ctrlPoints, int uDegree, int vDegree, bool uLoop, bool vLoop, float* uKnots, float* vKnots)
    : SurfacePatch(0.0f, 1.0f, 0.0f, 1.0f, true), mConstructor(4)
{
	mPatch = NEW0 Mathematics::BSplineRectanglef(numUCtrlPoints, numVCtrlPoints,  ctrlPoints, uDegree, vDegree, uLoop, vLoop, uKnots, vKnots);
}

Rendering::BSplineSurfacePatch
	::~BSplineSurfacePatch ()
{
    DELETE1(mPatch);
}

const Mathematics::APointf Rendering::BSplineSurfacePatch
	::GetPosition(float u, float v) const
{
    Mathematics::Vector3Df p = mPatch->P(u, v);
    return APoint(p[0], p[1], p[2]);
}

const Mathematics::AVectorf Rendering::BSplineSurfacePatch
	::GetDerivativesU(float u, float v) const
{
    Mathematics::Vector3Df pu = mPatch->PU(u, v);
    return AVector(pu[0], pu[1], pu[2]);
}

const Mathematics::AVectorf Rendering::BSplineSurfacePatch
	::GetDerivativesV(float u, float v) const
{
    Mathematics::Vector3Df pv = mPatch->PV(u, v);
    return AVector(pv[0], pv[1], pv[2]);
}

const Mathematics::AVectorf Rendering::BSplineSurfacePatch
	::GetDerivativesUU(float u, float v) const
{
    Mathematics::Vector3Df puu = mPatch->PUU(u, v);
    return AVector(puu[0], puu[1], puu[2]);
}

const Mathematics::AVectorf Rendering::BSplineSurfacePatch
	::GetDerivativesUV(float u, float v) const
{
    Mathematics::Vector3Df puv = mPatch->PUV(u, v);
    return AVector(puv[0], puv[1], puv[2]);
}

const Mathematics::AVectorf Rendering::BSplineSurfacePatch
	::GetDerivativesVV(float u, float v) const
{
    Mathematics::Vector3Df pvv = mPatch->PVV(u, v);
    return AVector(pvv[0], pvv[1], pvv[2]);
}



// Streaming support.

Rendering::BSplineSurfacePatch
	::BSplineSurfacePatch (LoadConstructor value)
    :SurfacePatch(value), mConstructor(0), mPatch(0)
{
}

void Rendering::BSplineSurfacePatch
	::Load(CoreTools::BufferSource& source)
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    SurfacePatch::Load(source);

    source.Read(mConstructor);

    int numCtrlPoints0, numCtrlPoints1;
    source.Read(numCtrlPoints0);
    source.Read(numCtrlPoints1);
    Mathematics::Vector3Df** ctrl = NEW2<Mathematics::Vector3Df>(numCtrlPoints1, numCtrlPoints0);
    int i0, i1;
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

    bool loop0, loop1;
	loop0 = source.ReadBool();
	loop1 = source.ReadBool();

    bool open0, open1;
	float* knot0 = nullptr;
    float* knot1 = nullptr;
    int numKnots0, numKnots1;

    switch (mConstructor)
    {
    case 1:
		open0 =source.ReadBool();
		open1 =source.ReadBool();

        mPatch = NEW0 Mathematics::BSplineRectanglef(numCtrlPoints0, numCtrlPoints1,ctrl, degree0, degree1, loop0, loop1, open0, open1);
        break;
    case 2:
		open0 =source.ReadBool();
        numKnots1 = numCtrlPoints1 - degree1 - 1;
        source.Read(numKnots1, knot1);

        mPatch = NEW0 Mathematics::BSplineRectanglef(numCtrlPoints0, numCtrlPoints1,ctrl, degree0, degree1, loop0, loop1, open0, knot1);

        DELETE1(knot1);
        break;
    case 3:
        numKnots0 = numCtrlPoints0 - degree0 - 1;
		source.Read(numKnots0, knot0);
		open1 = source.ReadBool();

		mPatch = NEW0 Mathematics::BSplineRectanglef(numCtrlPoints0, numCtrlPoints1,ctrl, degree0, degree1, loop0, loop1, knot0, open1);

        DELETE1(knot0);
        break;
    case 4:
        numKnots0 = numCtrlPoints0 - degree0 - 1;
        source.Read(numKnots0, knot0);
        numKnots1 = numCtrlPoints1 - degree1 - 1;
		source.Read(numKnots1, knot1);

		mPatch = NEW0 Mathematics::BSplineRectanglef(numCtrlPoints0, numCtrlPoints1,ctrl, degree0, degree1, loop0, loop1, knot0, knot1);

        DELETE1(knot0);
        DELETE1(knot1);
        break;
    default:
        RENDERING_ASSERTION_0(false, "Unexpected condition\n");
    }

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::BSplineSurfacePatch
	::Link(CoreTools::ObjectLink& source)
{
    SurfacePatch::Link(source);
}

void Rendering::BSplineSurfacePatch
	::PostLink ()
{
    SurfacePatch::PostLink();
}

uint64_t Rendering::BSplineSurfacePatch
	::Register(CoreTools::ObjectRegister& target) const
{
    return SurfacePatch::Register(target);
}

void Rendering::BSplineSurfacePatch
	::Save(CoreTools::BufferTarget& target) const
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    SurfacePatch::Save(target);

    target.Write(mConstructor);

    int numCtrlPoints0 = mPatch->GetNumCtrlPoints(0);
    int numCtrlPoints1 = mPatch->GetNumCtrlPoints(1);
    target.Write(numCtrlPoints0);
    target.Write(numCtrlPoints1);
    int i0, i1;
    for (i0 = 0; i0 < numCtrlPoints0; ++i0)
    {
        for (i1 = 0; i1 < numCtrlPoints1; ++i1)
        {
            target.WriteAggregate(mPatch->GetControlPoint(i0, i1));
        }
    }

    int degree0 = mPatch->GetDegree(0);
    int degree1 = mPatch->GetDegree(1);
    target.Write(degree0);
    target.Write(degree1);

    bool loop0 = mPatch->IsLoop(0);
    bool loop1 = mPatch->IsLoop(1);
    target.WriteBool(loop0);
    target.WriteBool(loop1);

    bool open0, open1;
    int numKnots0, numKnots1;

    switch (mConstructor)
    {
    case 1:
        open0 = mPatch->IsOpen(0);
        target.WriteBool(open0);
        open1 = mPatch->IsOpen(1);
        target.WriteBool(open1);
        break;
    case 2:
        open0 = mPatch->IsOpen(0);
        target.WriteBool(open0);
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
        target.WriteBool(open1);
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

    CORE_TOOLS_END_DEBUG_STREAM_SAVE( target);
}

int Rendering::BSplineSurfacePatch
	::GetStreamingSize () const
{
    int size = SurfacePatch::GetStreamingSize();
    size += sizeof(mConstructor);

    int numCtrlPoints0 = mPatch->GetNumCtrlPoints(0);
    int numCtrlPoints1 = mPatch->GetNumCtrlPoints(1);
    int degree0 = mPatch->GetDegree(0);
    int degree1 = mPatch->GetDegree(1);
	bool loop0 =false;
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
        size += (numCtrlPoints1 - degree1 - 1)*sizeof(float);  // knot1[]
        break;
    case 3:
        size += (numCtrlPoints0 - degree0 - 1)*sizeof(float);  // knot0[]
		size += CORE_TOOLS_STREAM_SIZE(loop0);  // open1
        break;
    case 4:
        size += (numCtrlPoints0 - degree0 - 1)*sizeof(float);  // knot0[]
        size += (numCtrlPoints1 - degree1 - 1)*sizeof(float);  // knot1[]
        break;
    default:
        RENDERING_ASSERTION_0(false, "Unexpected condition\n");
    }

    return size;
}


// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/25 16:50)

#include "Rendering/RenderingExport.h"

#include "RevolutionSurface.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/VertexBufferAccessorDetail.h"
#include "Rendering/SceneGraph/StandardMesh.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26489)
#include SYSTEM_WARNING_DISABLE(26451)
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26493)
CORE_TOOLS_RTTI_DEFINE(Rendering, RevolutionSurface);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, RevolutionSurface);
CORE_TOOLS_FACTORY_DEFINE(Rendering, RevolutionSurface);

Rendering::RevolutionSurface ::RevolutionSurface(Mathematics::Curve2f* curve, float xCenter, TopologyType topology, int numCurveSamples,
                                                 int numRadialSamples, bool sampleByArcLength, bool outsideView, VertexFormatSmartPointer vformat)
    : ParentType(vformat, VertexBufferSmartPointer(), IndexBufferSmartPointer()), mCurve(curve), mXCenter(xCenter), mTopology(topology),
      mNumCurveSamples(numCurveSamples), mNumRadialSamples(numRadialSamples), mSin(0), mCos(0), mSamples(0), mSampleByArcLength(sampleByArcLength)
{
    ComputeSampleData();

    // The topology of the meshes is all that matters.  The vertices will be
    // modified later based on the curve of revolution.
    StandardMesh stdmesh(vformat, !outsideView);
    TrianglesMeshSmartPointer mesh;
    switch (mTopology)
    {
    case TopologyType::REV_DISK_TOPOLOGY:
        mesh = stdmesh.Disk(mNumCurveSamples, mNumRadialSamples, 1.0f);
        break;
    case TopologyType::REV_CYLINDER_TOPOLOGY:
        mesh = stdmesh.CylinderIncludedEndDisks(mNumCurveSamples, mNumRadialSamples, 1.0f,
                                                1.0f);
        break;
    case TopologyType::REV_SPHERE_TOPOLOGY:
        mesh = stdmesh.Sphere(mNumCurveSamples, mNumRadialSamples, 1.0f);
        break;
    case TopologyType::REV_TORUS_TOPOLOGY:
        mesh = stdmesh.Torus(mNumCurveSamples, mNumRadialSamples, 1.0f,
                             0.25f);
        break;
    default:
        RENDERING_ASSERTION_0(false, "Unexpected condition\n");
        break;
    }
    RENDERING_ASSERTION_0(mesh != 0, "Failed to construct mesh\n");

    SetVertexFormat(vformat);
    SetVertexBuffer(mesh->GetVertexBuffer());

    // Generate the actual surface by replacing the vertex values.  NOTE:
    // Setting mIBuffer to zero acts as a flag that tells UpdateSurface
    // *not* to call Renderer::UpdateVertexBuffer(mVBuffer).  Only when the
    // application has constructed a RevolutionSurface wlil the update occur.
    SetIndexBuffer(IndexBufferSmartPointer());
    UpdateSurface();

    SetIndexBuffer(mesh->GetIndexBuffer());
}

Rendering::RevolutionSurface ::~RevolutionSurface()
{
    EXCEPTION_TRY
    {
        DELETE1(mSin);
        DELETE1(mCos);
        DELETE1(mSamples);
    }
    EXCEPTION_ALL_CATCH(Rendering)
}

void Rendering::RevolutionSurface ::ComputeSampleData()
{
    // Compute slice vertex coefficients.  The first and last coefficients
    // are duplicated to allow a closed cross section that has two different
    // pairs of texture coordinates at the shared vertex.
    mSin = NEW1<float>(mNumRadialSamples + 1);
    mCos = NEW1<float>(mNumRadialSamples + 1);
    const float invNumRadialSamples = 1.0f / (float)mNumRadialSamples;
    for (int i = 0; i < mNumRadialSamples; ++i)
    {
        const float angle = Mathematics::Mathf::GetTwoPI() * invNumRadialSamples * i;
        mCos[i] = Mathematics::Mathf::Cos(angle);
        mSin[i] = Mathematics::Mathf::Sin(angle);
    }
    mSin[mNumRadialSamples] = mSin[0];
    mCos[mNumRadialSamples] = mCos[0];

    // Allocate storage for curve samples.
    mSamples = NEW1<Mathematics::Vector3Df>(mNumCurveSamples);
}

void Rendering::RevolutionSurface ::UpdateSurface()
{
    // Parameters for evaluating curve.
    const float tMin = mCurve->GetMinTime();
    const float tRange = mCurve->GetMaxTime() - tMin;

    // Sampling by arc length requires the total length of the curve.
    float totalLength = 0.0f;
    if (mSampleByArcLength)
    {
        totalLength = mCurve->GetTotalLength();
    }
    else
    {
        totalLength = 0.0f;
    }

    // Sample the curve of revolution.
    const float invNumCurveSamplesM1 = 1.0f / (float)(mNumCurveSamples - 1);
    for (int i = 0; i < mNumCurveSamples; ++i)
    {
        float t = 0.0f;
        if (mSampleByArcLength)
        {
            t = mCurve->GetTime(i * totalLength * invNumCurveSamplesM1);
        }
        else
        {
            t = tMin + i * tRange * invNumCurveSamplesM1;
        }

        const Mathematics::Vector2Df position = mCurve->GetPosition(t);
        mSamples[i][0] =(position.GetXCoordinate());
        mSamples[i][1] = (0.0f);
        mSamples[i][2] = (position.GetYCoordinate());
    }

    // Store the samples and their rotated equivalents.  The storage layout
    // is dependent on the topology of the mesh.
    switch (mTopology)
    {
    case TopologyType::REV_DISK_TOPOLOGY:
        UpdateDisk();
        break;
    case TopologyType::REV_CYLINDER_TOPOLOGY:
        UpdateCylinder();
        break;
    case TopologyType::REV_SPHERE_TOPOLOGY:
        UpdateSphere();
        break;
    case TopologyType::REV_TORUS_TOPOLOGY:
        UpdateTorus();
        break;
    default:
        RENDERING_ASSERTION_0(false, "Unexpected condition\n");
        break;
    }

    UpdateModelSpace(VisualUpdateType::Normals);

    // See the comments in the constructor about mIBuffer and the vertex
    // buffer update.
    if (GetIndexBuffer().get())
    {
        RENDERER_MANAGE_SINGLETON.UpdateAll(GetVertexBuffer().get());
    }
}

void Rendering::RevolutionSurface::UpdateDisk()
{
    VertexBufferAccessor vba(this);

    // Get the initial ray.
    int c = 0;
    for (c = 0; c < mNumCurveSamples; c++)
    {
        GetVertexBuffer()->SetPosition(vba, c, Mathematics::APoint{ mSamples[c] });
    }

    // The remaining rays are obtained by revolution.
    const int numCurveSamplesM1 = mNumCurveSamples - 1;
    for (int r = 1; r < mNumRadialSamples; ++r)
    {
        for (c = 1; c < mNumCurveSamples; ++c)
        {
            float radius = mSamples[c][0] - mXCenter;
            if (radius < 0.0f)
            {
                radius = 0.0f;
            }
            const int i = c + numCurveSamplesM1 * r;

         const   Mathematics::Vector3D position{ mXCenter + radius * mCos[r], radius * mSin[r], mSamples[c][2] };
            GetVertexBuffer()->SetPosition(vba, i, Mathematics::APoint{ position });
        }
    }
}

void Rendering::RevolutionSurface::UpdateSphere()
{
    VertexBufferAccessor vba(this);

    int numVertices = GetVertexBuffer()->GetNumElements();

    // Set the South pole.
    GetVertexBuffer()->SetPosition(vba, numVertices - 2, Mathematics::APoint{ mSamples[0] });

    // Set the north pole.
    GetVertexBuffer()->SetPosition(vba, numVertices - 1, Mathematics::APoint{ mSamples[mNumCurveSamples - 1] });

    // Set the initial and final ray.
    int c = 0, i = 0;
    for (c = 1; c <= mNumCurveSamples - 2; ++c)
    {
        i = (c - 1) * (mNumRadialSamples + 1);

        GetVertexBuffer()->SetPosition(vba, i, Mathematics::APoint{ mSamples[c] });

        i += mNumRadialSamples;

        GetVertexBuffer()->SetPosition(vba, i, Mathematics::APoint{ mSamples[c] });
    }

    // The remaining rays are obtained by revolution.
    for (int r = 1; r < mNumRadialSamples; ++r)
    {
        for (c = 1; c <= mNumCurveSamples - 2; ++c)
        {
            float radius = mSamples[c][0] - mXCenter;
            if (radius < 0.0f)
            {
                radius = 0.0f;
            }
            i = (c - 1) * (mNumRadialSamples + 1) + r;

const Mathematics::Vector3D position{ mXCenter + radius * mCos[r], radius * mSin[r], mSamples[c][2] };

            GetVertexBuffer()->SetPosition(vba, i, Mathematics::APoint{ position });
        }
    }
}

void Rendering::RevolutionSurface ::UpdateCylinder()
{
    VertexBufferAccessor vba(this);

    // Set the initial and final ray.
    int c = 0, i = 0;
    for (c = 0; c < mNumCurveSamples; ++c)
    {
        i = c * (mNumRadialSamples + 1);

        GetVertexBuffer()->SetPosition(vba, i, Mathematics::APoint{ mSamples[c] });

        i += mNumRadialSamples;

        GetVertexBuffer()->SetPosition(vba, i, Mathematics::APoint{ mSamples[c] });
    }

    // The remaining rays are obtained by revolution.
    for (int r = 1; r < mNumRadialSamples; ++r)
    {
        for (c = 0; c < mNumCurveSamples; ++c)
        {
            float radius = mSamples[c][0] - mXCenter;
            if (radius < 0.0f)
            {
                radius = 0.0f;
            }
            i = c * (mNumRadialSamples + 1) + r;

const Mathematics::Vector3D position{ mXCenter + radius * mCos[r], radius * mSin[r], mSamples[c][2] };

            GetVertexBuffer()->SetPosition(vba, i, Mathematics::APoint{ position });
        }
    }
}

void Rendering::RevolutionSurface ::UpdateTorus()
{
    VertexBufferAccessor vba(this);

    // Set the initial and final ray.
    int numVertices = GetVertexBuffer()->GetNumElements();
    int c = 0, i = 0;
    for (c = 0; c < mNumCurveSamples; ++c)
    {
        i = c * (mNumRadialSamples + 1);

        GetVertexBuffer()->SetPosition(vba, i, Mathematics::APoint{ mSamples[c] });

        i += mNumRadialSamples;

        GetVertexBuffer()->SetPosition(vba, i, Mathematics::APoint{ mSamples[c] });
    }

    // The remaining rays are obtained by revolution.
    int r;
    for (r = 1; r < mNumRadialSamples; ++r)
    {
        for (c = 0; c < mNumCurveSamples; ++c)
        {
            float radius = mSamples[c][0] - mXCenter;
            if (radius < 0.0f)
            {
                radius = 0.0f;
            }
            i = c * (mNumRadialSamples + 1) + r;

const Mathematics::Vector3D position{ mXCenter + radius * mCos[r], radius * mSin[r], mSamples[c][2] };

            GetVertexBuffer()->SetPosition(vba, i, Mathematics::APoint{ position });
        }
    }

    i = numVertices - (mNumRadialSamples + 1);
    for (r = 0; r <= mNumRadialSamples; ++r, ++i)
    {
        GetVertexBuffer()->SetPosition(vba, i, vba.GetPosition<Mathematics::APointf>(r));
    }
}

// Streaming support.

Rendering::RevolutionSurface ::RevolutionSurface(LoadConstructor value)
    : ParentType(value), mCurve(0), mXCenter(0.0f), mTopology(TopologyType::MAX_TOPOLOGY_TYPES), mNumCurveSamples(0),
      mNumRadialSamples(0), mSin(0), mCos(0), mSamples(0), mSampleByArcLength(false)
{
}

void Rendering::RevolutionSurface ::Load(CoreTools::BufferSource& source)
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    source.Read(mXCenter);
    source.ReadEnum(mTopology);
    source.Read(mNumCurveSamples);
    source.Read(mNumRadialSamples);
    source.Read(mNumRadialSamples + 1, mSin);
    source.Read(mNumRadialSamples + 1, mCos);
    mSampleByArcLength = source.ReadBool();

    // TODO.  See note in RevolutionSurface::Save.
    mCurve = 0;

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::RevolutionSurface ::Link(CoreTools::ObjectLink& source)
{
    ParentType::Link(source);
}

void Rendering::RevolutionSurface ::PostLink()
{
    ParentType::PostLink();
}

uint64_t Rendering::RevolutionSurface ::Register(CoreTools::ObjectRegister& target) const
{
    return ParentType::Register(target);
}

void Rendering::RevolutionSurface ::Save(CoreTools::BufferTarget& target) const
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    target.Write(mXCenter);
    target.WriteEnum(mTopology);
    target.Write(mNumCurveSamples);
    target.Write(mNumRadialSamples);
    target.WriteWithNumber(mNumRadialSamples + 1, mSin);
    target.WriteWithNumber(mNumRadialSamples + 1, mCos);
    target.WriteBool(mSampleByArcLength);

    // TODO.  The class Curve2 is abstract and does not know about the data
    // representation for the derived-class object that is passed to the
    // RevolutionSurface constructor.  Because of this, any loaded
    // RevolutionSurface object will require the application to manually set
    // the curve via the Curve() member.
    //
    // Streaming support should be added to the curve classes.

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::RevolutionSurface ::GetStreamingSize() const
{
    int size = ParentType::GetStreamingSize();
    size += sizeof(mXCenter);
    size += CORE_TOOLS_STREAM_SIZE(mTopology);
    size += sizeof(mNumCurveSamples);
    size += sizeof(mNumRadialSamples);
    size += (mNumRadialSamples + 1) * sizeof(mSin[0]);
    size += (mNumRadialSamples + 1) * sizeof(mCos[0]);
    size += CORE_TOOLS_STREAM_SIZE(mSampleByArcLength);
    return size;
}

int Rendering::RevolutionSurface ::GetCurveSamples() const noexcept
{
    return mNumCurveSamples;
}

int Rendering::RevolutionSurface ::GetRadialSamples() const noexcept
{
    return mNumRadialSamples;
}

void Rendering::RevolutionSurface ::SetCurve(Mathematics::Curve2f* curve) noexcept
{
    mCurve = curve;
}

const Mathematics::Curve2f* Rendering::RevolutionSurface ::GetCurve() const noexcept
{
    return mCurve;
}

Rendering::RevolutionSurface::TopologyType Rendering::RevolutionSurface ::GetTopology() const noexcept
{
    return mTopology;
}

void Rendering::RevolutionSurface ::SetSampleByArcLength(bool sampleByArcLength) noexcept
{
    mSampleByArcLength = sampleByArcLength;
}

bool Rendering::RevolutionSurface ::GetSampleByArcLength() const noexcept
{
    return mSampleByArcLength;
}

#include STSTEM_WARNING_POP
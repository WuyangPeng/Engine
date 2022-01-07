// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/25 16:35)

#include "Rendering/RenderingExport.h"

#include "CurveMesh.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/VertexBufferAccessor.h"

#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26489)
#include SYSTEM_WARNING_DISABLE(26492)
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26429)
CORE_TOOLS_RTTI_DEFINE(Rendering, CurveMesh);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, CurveMesh);
CORE_TOOLS_FACTORY_DEFINE(Rendering, CurveMesh);

Rendering::CurveMesh ::CurveMesh(VertexFormatSharedPtr vformat, VertexBufferSharedPtr vbuffer, CurveSegmentSharedPtr* segments,
                                 FloatArray* params, bool allowDynamicChange)
    : Polysegment(vformat, vbuffer, true), mOrigVBuffer(vbuffer), mOrigParams(params), mSegments(segments),
      mNumFullVertices(vbuffer->GetNumElements()), mNumSegments(vbuffer->GetNumElements() - 1), mLevel(0), mAllowDynamicChange(allowDynamicChange)
{
    if (mAllowDynamicChange)
    {
        //mCInfo = NEW1<CurveInfo>(mNumFullVertices);
        InitializeCurveInfo();
    }
    else
    {
        mCInfo = 0;
    }
}

Rendering::CurveMesh ::~CurveMesh()
{
    EXCEPTION_TRY
    {
        // DELETE1(mSegments);
        //DELETE1(mCInfo);
    }
    EXCEPTION_ALL_CATCH(Rendering)
}

void Rendering::CurveMesh ::SetLevel(int level)
{
    if (!mOrigVBuffer)
    {
        // The mesh is locked, so no subdivision is allowed.
        return;
    }

    if (level == mLevel)
    {
        return;
    }
    mLevel = level;

    // Allocate the storage for subdivision.
    int numTotalVertices, numTotalEdges;
    Edge* edges;
    Allocate(numTotalVertices, numTotalEdges, edges);

    // Subdivide the mesh.
    int numVertices = mNumSegments + 1;
    int numEdges = mNumSegments;
    int i;
    for (i = 0; i < mLevel; ++i)
    {
        const int nextNumVertices = numVertices + numEdges;
        const int nextNumEdges = 2 * numEdges;
        Subdivide(numVertices, numEdges, edges);
        RENDERING_ASSERTION_0(numVertices == nextNumVertices && numEdges == nextNumEdges, "Unexpected condition\n");
        numVertices = nextNumVertices;
        numEdges = nextNumEdges;
    }

    // Check to make sure the implementation is correct.
    RENDERING_ASSERTION_0(numVertices == numTotalVertices && numEdges == numTotalEdges, "Unexpected condition\n");
    SetNumSegments(numTotalVertices - 1);
    mNumFullVertices = numTotalVertices;

    UpdateModelSpace(VisualUpdateType::Normals);

    // DELETE1(edges);
    OnDynamicChange();
    RENDERER_MANAGE_SINGLETON.BindAll(GetVertexBuffer().get());
}

int Rendering::CurveMesh ::GetLevel() const noexcept
{
    return mLevel;
}

void Rendering::CurveMesh ::Allocate(int& numTotalVertices, int& numTotalEdges, Edge*& edges)
{
    // The number of original vertices.
    int numOrigVertices = mNumSegments + 1;

    // The number of original edges.
    int numOrigEdges = mNumSegments;

    // Determine the various quantities needed for subdivision.
    numTotalVertices = numOrigVertices;
    numTotalEdges = numOrigEdges;
    int i;
    for (i = 0; i < mLevel; ++i)
    {
        numTotalVertices = numTotalVertices + numTotalEdges;
        numTotalEdges = 2 * numTotalEdges;
    }

    // Allocate storage for the subdivision.
    int vstride = GetVertexFormat()->GetStride();
    SetVertexBuffer(VertexBufferSharedPtr(std::make_shared<VertexBuffer>(numTotalVertices, vstride)));
    // edges = NEW1<Edge>(numTotalEdges);
    if (mAllowDynamicChange)
    {
        //DELETE1(mCInfo);
        //  mCInfo = NEW1<CurveInfo>(numTotalVertices);
        InitializeCurveInfo();
    }

    // Initialize the edge data structures.  Copy the original vertices to
    // their proper locations in the new vertex buffer.
    // 先通过编译

    const float* origParam = mOrigParams->GetData();
    char* origData = const_cast<char*>(mOrigVBuffer->GetReadOnlyData());
    char* fullData = const_cast<char*>(GetVertexBuffer()->GetReadOnlyData());
    int index = 0;
    const int indexDelta = (1 << mLevel);
    int fullStride = vstride * indexDelta;
    for (i = 0; i < numOrigEdges; ++i)
    {
        Edge& edge = edges[i];

        // The curve affecting the edge.
        edge.Segment = mSegments[i];

        // Get the vertex indices for the edge.
        edge.V[0] = index;
        index += indexDelta;
        edge.V[1] = index;

        // Get the parameters associated with the vertices.
        edge.Param[0] = *origParam++;
        edge.Param[1] = *origParam++;

        // Copy the vertex for edge.V[0].
        memcpy(fullData, origData, vstride);
        origData += vstride;
        fullData += fullStride;
    }

    // Copy the last vertex.
    memcpy(fullData, origData, vstride);
}

void Rendering::CurveMesh ::Subdivide(int& numVertices, int& numEdges, Edge* edges)
{
    // The subdivision is computed in-place, so you need to fill in the new
    // edge slots starting from the end of the array and working towards the
    // beginning.  This avoids overwriting old edges not yet subdivided.
    VertexBufferAccessor vba(GetVertexFormat(), GetVertexBuffer());

    for (int old = numEdges - 1, curr = 2 * numEdges - 1; old >= 0; --old)
    {
        const Edge& edge = edges[old];

        // Compute the vertex at the average of the parameter values.
        const int v0 = edge.V[0];
        const int v1 = edge.V[1];
        int vMid = (v0 + v1) / 2;
        const float paramMid = 0.5f * (edge.Param[0] + edge.Param[1]);

        // vba.Position<Float3>(vMid) = edge.Segment->P(paramMid);

        // Compute the average of vertex attributes.
        if (vba.HasNormal())
        {
            // Use the curve normal.

            // vba.Normal<Float3>(vMid) = edge.Segment->Normal(paramMid);
        }

        //        int unit, i;
        float* data0 = nullptr;
        float* data1 = nullptr;
        float* data = nullptr;
        constexpr int numColorUnits = System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::ColorUnits);
        for (int unit = 0; unit < numColorUnits; ++unit)
        {
            if (vba.HasColor(unit))
            {
                data0 = const_cast<float*>(vba.GetColorTuple(unit, v0));
                data1 = const_cast<float*>(vba.GetColorTuple(unit, v1));
                data = const_cast<float*>(vba.GetColorTuple(unit, vMid));
                for (auto i = 0; i < vba.GetColorChannels(unit); ++i)
                {
                    data[i] = 0.5f * (data0[i] + data1[i]);
                }
            }
        }

        constexpr int numTCoordUnits = System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::TextureCoordinateUnits);
        for (int unit = 0; unit < numTCoordUnits; ++unit)
        {
            if (vba.HasTextureCoord(unit))
            {
                // 先通过编译

                data0 = const_cast<float*>(vba.GetTextureCoordTuple(unit, v0));
                data1 = const_cast<float*>(vba.GetTextureCoordTuple(unit, v1));
                data = const_cast<float*>(vba.GetTextureCoordTuple(unit, vMid));
                for (auto i = 0; i < vba.GetTextureCoordChannels(unit); ++i)
                {
                    data[i] = 0.5f * (data0[i] + data1[i]);
                }
            }
        }

        if (mAllowDynamicChange)
        {
            mCInfo[vMid].Segment = edge.Segment;
            mCInfo[vMid].Param = paramMid;
        }

        // Subdivide the edge.
        Edge& edge1 = edges[curr--];
        edge1.Segment = edge.Segment;
        edge1.V[0] = vMid;
        edge1.V[1] = edge.V[1];
        edge1.Param[0] = paramMid;
        edge1.Param[1] = edge.Param[1];

        Edge& edge0 = edges[curr--];
        edge0.Segment = edge.Segment;
        edge0.V[0] = edge.V[0];
        edge0.V[1] = vMid;
        edge0.Param[0] = edge.Param[0];
        edge0.Param[1] = paramMid;

        ++numVertices;
    }

    numEdges = 2 * numEdges;
}

void Rendering::CurveMesh ::OnDynamicChange()
{
    if (mAllowDynamicChange)
    {
        VertexBufferAccessor vba(GetVertexFormat(), GetVertexBuffer());

        for (int i = 0; i < mNumFullVertices; ++i)
        {
            //  CurveInfo& ci = mCInfo[i];

            // vba.Position<Float3>(i) = ci.Segment->P(ci.Param);
        }

        UpdateModelSpace(VisualUpdateType::Normals);
    }
}

void Rendering::CurveMesh ::Lock()
{
    CoreTools::DisableNoexcept();
    if (mOrigVBuffer)
    {
        mOrigVBuffer.reset();
        mOrigParams.reset();
        // DELETE1(mSegments);
        mSegments = 0;
    }

    // The array mCInfo is not deleted.  This allows dynamic updates of
    // the vertices of the mesh, even though the mesh is "locked".
}

bool Rendering::CurveMesh ::IsLocked() const noexcept
{
    return !mOrigVBuffer;
}

void Rendering::CurveMesh ::InitializeCurveInfo() noexcept
{
    // Because vertices are shared by edges, the last visited edge for a
    // vertex donates its segment and parameter values to that vertex.
    const float* params = mOrigParams->GetData();
    int index = 0;
    const int indexDelta = (1 << mLevel);
    for (int i = 0; i < mNumSegments; ++i)
    {
        int v0 = index;
        index += indexDelta;
        int v1 = index;
        mCInfo[v0].Segment = mSegments[i];
        mCInfo[v0].Param = *params++;
        mCInfo[v1].Segment = mSegments[i];
        mCInfo[v1].Param = *params++;
    }
}

Rendering::CurveMesh::Edge ::Edge() noexcept
{
    Segment.reset();
    V[0] = -1;
    V[1] = -1;
    Param[0] = 0.0f;
    Param[1] = 0.0f;
}

Rendering::CurveMesh::CurveInfo ::CurveInfo() noexcept
{
    Segment.reset();
    Param = 0.0f;
}

// Name support.
CoreTools::ObjectSharedPtr Rendering::CurveMesh ::GetObjectByName(const std::string& name)
{
    CoreTools::ObjectSharedPtr found = ParentType::GetObjectByName(name);
    if (found)
    {
        return found;
    }

    found = mOrigVBuffer->GetObjectByName(name);
    if (found)
    {
        return found;
    }

    found = mOrigParams->GetObjectByName(name);
    if (found)
    {
        return found;
    }

    if (mSegments)
    {
        for (int i = 0; i < mNumSegments; ++i)
        {
            CoreTools::ObjectSharedPtr found2 = mSegments[i]->GetObjectByName(name);
            if (found2)
                return found2;
        }
    }

    return CoreTools::ObjectSharedPtr();
}

std::vector<CoreTools::ObjectSharedPtr> Rendering::CurveMesh ::GetAllObjectsByName(const std::string& name)
{
    std::vector<CoreTools::ObjectSharedPtr> objects = ParentType::GetAllObjectsByName(name);

    std::vector<CoreTools::ObjectSharedPtr> pointerObjects = mOrigVBuffer->GetAllObjectsByName(name);
    objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());

    pointerObjects = mOrigParams->GetAllObjectsByName(name);
    objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());

    if (mSegments)
    {
        for (int i = 0; i < mNumSegments; ++i)
        {
            pointerObjects = mOrigParams->GetAllObjectsByName(name);
            objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
        }
    }

    return objects;
}

CoreTools::ConstObjectSharedPtr Rendering::CurveMesh ::GetConstObjectByName(const std::string& name) const
{
    CoreTools::ConstObjectSharedPtr found = ParentType::GetConstObjectByName(name);
    if (found)
    {
        return found;
    }

    found = mOrigVBuffer->GetConstObjectByName(name);
    if (found)
    {
        return found;
    }

    found = mOrigParams->GetConstObjectByName(name);
    if (found)
    {
        return found;
    }

    if (mSegments)
    {
        for (int i = 0; i < mNumSegments; ++i)
        {
            CoreTools::ConstObjectSharedPtr found2 = mSegments[i]->GetConstObjectByName(name);
            if (found2)
                return found2;
        }
    }

    return CoreTools::ConstObjectSharedPtr();
}

std::vector<CoreTools::ConstObjectSharedPtr> Rendering::CurveMesh ::GetAllConstObjectsByName(const std::string& name) const
{
    std::vector<CoreTools::ConstObjectSharedPtr> objects = ParentType::GetAllConstObjectsByName(name);

    std::vector<CoreTools::ConstObjectSharedPtr> pointerObjects = mOrigVBuffer->GetAllConstObjectsByName(name);
    objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());

    pointerObjects = mOrigParams->GetAllConstObjectsByName(name);
    objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());

    if (mSegments)
    {
        for (int i = 0; i < mNumSegments; ++i)
        {
            pointerObjects = mOrigParams->GetAllConstObjectsByName(name);
            objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
        }
    }

    return objects;
}

// Streaming support.

Rendering::CurveMesh ::CurveMesh(LoadConstructor value)
    : Polysegment(value), mSegments(0), mNumFullVertices(0), mNumSegments(0), mLevel(0), mAllowDynamicChange(false), mCInfo(0)
{
}

void Rendering::CurveMesh ::Load(CoreTools::BufferSource& source)
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    Polysegment::Load(source);

    source.Read(mNumFullVertices);
    source.Read(mNumSegments);
    source.Read(mLevel);
    mAllowDynamicChange = source.ReadBool();
    //	source.ReadSharedPtr(mOrigVBuffer);
    //source.ReadSharedPtr(mOrigParams);

    const bool locked = (!mOrigVBuffer);
    if (!locked)
    {
        //  source.ReadSharedPtr(mNumSegments, mSegments);
    }

    if (mAllowDynamicChange)
    {
        //  mCInfo = NEW1<CurveInfo>(mNumFullVertices);
        for (int i = 0; i < mNumFullVertices; ++i)
        {
            //   source.ReadSharedPtr(mCInfo[i].Segment);
            source.Read(mCInfo[i].Param);
        }
    }

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::CurveMesh ::Link(CoreTools::ObjectLink& source)
{
    Polysegment::Link(source);

    //source.ResolveObjectSharedPtrLink(mOrigVBuffer);
    //source.ResolveObjectSharedPtrLink(mOrigParams);
    //source.ResolveObjectSharedPtrLink(mNumSegments, mSegments);
    if (mCInfo)
    {
        for (int i = 0; i < mNumFullVertices; ++i)
        {
            //  source.ResolveObjectSharedPtrLink(mCInfo[i].Segment);
        }
    }
}

void Rendering::CurveMesh ::PostLink()
{
    Polysegment::PostLink();
}

uint64_t Rendering::CurveMesh ::Register(CoreTools::ObjectRegister& target) const
{
    const uint64_t id = Polysegment::Register(target);
    if (0 < id)
    {
        //  target.RegisterSharedPtr(mOrigVBuffer);
        //target.RegisterSharedPtr(mOrigParams);
        //target.RegisterSharedPtr(mNumSegments, mSegments);
        if (mCInfo)
        {
            for (int i = 0; i < mNumFullVertices; ++i)
            {
                //  target.RegisterSharedPtr(mCInfo[i].Segment);
            }
        }
        return id;
    }
    return id;
}

void Rendering::CurveMesh ::Save(CoreTools::BufferTarget& target) const
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    Polysegment::Save(target);

    target.Write(mNumFullVertices);
    target.Write(mNumSegments);
    target.Write(mLevel);
    target.Write(mAllowDynamicChange);
    //  target.WriteSharedPtr(mOrigVBuffer);
    //target.WriteSharedPtr(mOrigParams);
    // target.WriteSharedPtrWithNumber(mNumSegments, mSegments);

    if (mCInfo)
    {
        for (int i = 0; i < mNumFullVertices; ++i)
        {
            // target.WriteSharedPtr(mCInfo[i].Segment);
            target.Write(mCInfo[i].Param);
        }
    }

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::CurveMesh ::GetStreamingSize() const
{
    int size = Polysegment::GetStreamingSize();
    size += CORE_TOOLS_STREAM_SIZE(mNumFullVertices);
    size += CORE_TOOLS_STREAM_SIZE(mNumSegments);
    size += CORE_TOOLS_STREAM_SIZE(mLevel);
    size += CORE_TOOLS_STREAM_SIZE(mAllowDynamicChange);
    size += CORE_TOOLS_STREAM_SIZE(mOrigVBuffer);
    size += CORE_TOOLS_STREAM_SIZE(mOrigParams);

    if (mSegments)
    {
        size += mNumSegments * CORE_TOOLS_STREAM_SIZE(mSegments[0]);
    }

    if (mCInfo)
    {
        size += mNumFullVertices * CORE_TOOLS_STREAM_SIZE(mCInfo[0].Segment);
        size += mNumFullVertices * sizeof(mCInfo[0].Param);
    }

    return size;
}

CoreTools::ObjectInterfaceSharedPtr Rendering::CurveMesh::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

#include STSTEM_WARNING_POP
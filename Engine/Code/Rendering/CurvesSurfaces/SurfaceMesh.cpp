// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/25 17:23)

#include "Rendering/RenderingExport.h"

#include "SurfaceMesh.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Meshes/EdgeKey.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/VertexBufferAccessor.h"
#include <set>
#include "CoreTools/ClassInvariant/Noexcept.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26489)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26493)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26455)
CORE_TOOLS_RTTI_DEFINE(Rendering, SurfaceMesh);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, SurfaceMesh);
CORE_TOOLS_FACTORY_DEFINE(Rendering, SurfaceMesh);

Rendering::SurfaceMesh ::SurfaceMesh(VertexFormatSmartPointer vformat, VertexBufferSmartPointer vbuffer, IndexBufferSmartPointer ibuffer,
                                     Float2ArraySmartPointer params, SurfacePatchSmartPointer* patches, bool allowDynamicChange)
    : ParentType(vformat, vbuffer, ibuffer), mOrigVBuffer(vbuffer), mOrigIBuffer(ibuffer), mOrigParams(params), mPatches(patches),
      mNumFullVertices(vbuffer->GetNumElements()), mNumPatches(ibuffer->GetNumElements() / 3), mLevel(0), mAllowDynamicChange(allowDynamicChange)
{
    if (mAllowDynamicChange)
    {
        mSInfo = NEW1<SurfaceInfo>(mNumFullVertices);
        InitializeSurfaceInfo();
    }
    else
    {
        mSInfo = 0;
    }
}

Rendering::SurfaceMesh ::~SurfaceMesh()
{
    EXCEPTION_TRY
    {
        DELETE1(mPatches);
        DELETE1(mSInfo);
    }
    EXCEPTION_ALL_CATCH(Rendering)
}

void Rendering::SurfaceMesh ::SetLevel(int level)
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
    int numTotalVertices, numTotalEdges, numTotalTriangles;
    EdgeMap edgeMap;
    Triangle* triangles;
    Allocate(numTotalVertices, numTotalEdges, edgeMap, numTotalTriangles, triangles);

    // Subdivide the mesh.
    int numVertices = mOrigVBuffer->GetNumElements();
    int numEdges = (int)edgeMap.size();
    int numTriangles = mOrigIBuffer->GetNumElements() / 3;
    int i;
    for (i = 0; i < mLevel; ++i)
    {
        const int nextNumVertices = numVertices + numEdges;
        const int nextNumEdges = 2 * numEdges + 3 * numTriangles;
        const int nextNumTriangles = 4 * numTriangles;
        Subdivide(numVertices, numEdges, edgeMap, numTriangles, triangles);
        RENDERING_ASSERTION_0(numVertices == nextNumVertices && numEdges == nextNumEdges && numTriangles == nextNumTriangles, "Unexpected condition\n");
        numVertices = nextNumVertices;
        numEdges = nextNumEdges;
        numTriangles = nextNumTriangles;
    }

    // Check to make sure the implementation is correct.
    RENDERING_ASSERTION_0(numVertices == numTotalVertices && numEdges == numTotalEdges && numTriangles == numTotalTriangles, "Unexpected condition\n");
    mNumFullVertices = numTotalVertices;

    const int numTotalIndices = 3 * numTotalTriangles;
    SetIndexBuffer(IndexBufferSmartPointer(std::make_shared< IndexBuffer>(numTotalIndices, (int)sizeof(int))));

    int* indices = (int*)GetIndexBuffer()->GetReadOnlyData();
    for (i = 0; i < numTotalTriangles; ++i)
    {
        Triangle& tri = triangles[i];
        for (int j = 0; j < 3; ++j)
        {
            *indices++ = tri.V[j];
        }
    }
    RENDERER_MANAGE_SINGLETON.UpdateAll(GetIndexBuffer().get());

    DELETE1(triangles);
    OnDynamicChange();
    UpdateModelSpace(VisualUpdateType::Normals);
}

int Rendering::SurfaceMesh ::GetLevel() const noexcept
{
    return mLevel;
}

void Rendering::SurfaceMesh ::Allocate(int& numTotalVertices, int& numTotalEdges, EdgeMap& edgeMap, int& numTotalTriangles, Triangle*& triangles)
{
    // The number of original vertices.
    int numOrigVertices = mOrigVBuffer->GetNumElements();

    // The number of original indices and triangles.
    const int numOrigIndices = mOrigIBuffer->GetNumElements();
    int numOrigTriangles = numOrigIndices / 3;

    // Count the number of unique edges in the mesh.
    // 先通过编译
    int* indices = (int*)mOrigIBuffer->GetReadOnlyData();
    std::set<Mathematics::EdgeKey> eKeys;
    int i = 0, v0 = 0, v1 = 0, v2 = 0;
    for (i = 0; i < numOrigTriangles; ++i)
    {
        // Get the vertex indices for the triangle.
        v0 = *indices++;
        v1 = *indices++;
        v2 = *indices++;

        // Store the edges with the vertex indices.
        eKeys.insert(Mathematics::EdgeKey(v0, v1));
        eKeys.insert(Mathematics::EdgeKey(v1, v2));
        eKeys.insert(Mathematics::EdgeKey(v2, v0));
    }

    const int numOrigEdges = (int)eKeys.size();

    // Determine the various quantities needed for subdivision.
    numTotalVertices = numOrigVertices;
    numTotalEdges = numOrigEdges;
    numTotalTriangles = numOrigTriangles;
    for (i = 0; i < mLevel; ++i)
    {
        numTotalVertices = numTotalVertices + numTotalEdges;
        numTotalEdges = 2 * numTotalEdges + 3 * numTotalTriangles;
        numTotalTriangles = 4 * numTotalTriangles;
    }

    // Allocate storage for the subdivision.
    int vstride = GetVertexFormat()->GetStride();
    SetVertexBuffer(VertexBufferSmartPointer(std::make_shared < VertexBuffer>(numTotalVertices, vstride)));
    triangles = NEW1<Triangle>(numTotalTriangles);
    if (mAllowDynamicChange)
    {
        DELETE1(mSInfo);
        mSInfo = NEW1<SurfaceInfo>(numTotalVertices);
        InitializeSurfaceInfo();
    }

    // Copy the original vertices to the storage.
    // 先通过编译

    const char* origData = (char*)mOrigVBuffer->GetReadOnlyData();
    char* fullData = (char*)GetVertexBuffer()->GetReadOnlyData();
    const int numOrigBytes = mOrigVBuffer->GetNumBytes();
    memcpy(fullData, origData, numOrigBytes);

    // Initialize the edge and triangle data structures.
    const Mathematics::Float2* origParam = mOrigParams->GetData();
    indices = (int*)mOrigIBuffer->GetReadOnlyData();
    for (i = 0; i < numOrigTriangles; ++i)
    {
        Triangle& tri = triangles[i];

        // Surface affecting the triangle.
        tri.Patch = mPatches[i];

        // Get the vertex indices for the triangle.
        v0 = *indices++;
        v1 = *indices++;
        v2 = *indices++;
        tri.V[0] = v0;
        tri.V[1] = v1;
        tri.V[2] = v2;

        // Get the parameters associated with the vertices.
        const Mathematics::Float2& param0 = *origParam++;
        const Mathematics::Float2& param1 = *origParam++;
        const Mathematics::Float2& param2 = *origParam++;

        // Store the edges with the surface and parameter values.
        InsertInto(edgeMap, tri.Patch, v0, v1, param0, param1, 1);
        InsertInto(edgeMap, tri.Patch, v1, v2, param1, param2, 1);
        InsertInto(edgeMap, tri.Patch, v2, v0, param2, param0, 1);
    }

    RENDERING_ASSERTION_0(numOrigEdges == (int)edgeMap.size(), "Unexpected condition\n");
}

void Rendering::SurfaceMesh ::Subdivide(int& numVertices, int& numEdges, EdgeMap& edgeMap, int& numTriangles, Triangle* triangles)
{
    numVertices;
    numEdges;
    numTriangles;
    triangles;
    VertexBufferAccessor vba(GetVertexFormat(), GetVertexBuffer());

    EdgeMap::iterator iter = edgeMap.begin();
    const EdgeMap::iterator end = edgeMap.end();
    for (/**/; iter != end; ++iter)
    {
        // Compute the vertex at the average of the parameter values.  The
        // index and parameter values of the new vertex will be used when
        // subdividing the triangles.

        Edge& edge = iter->second;
        edge.ParamMid.SetFirstValue(0.5f * (edge.Param[0].GetFirstValue() + edge.Param[1].GetFirstValue()));
        edge.ParamMid.SetSecondValue(0.5f * (edge.Param[0].GetSecondValue() + edge.Param[1].GetSecondValue()));

        GetVertexBuffer()->SetPosition(vba, numVertices, edge.Patch->GetPosition(edge.ParamMid.GetFirstValue(), edge.ParamMid.GetSecondValue()));

        // Compute the average of vertex attributes.
        if (vba.HasNormal())
        {
            // Use the surface normal.
            // vba.Normal<Float3>(numVertices) = edge.Patch->Normal(edge.ParamMid[0], edge.ParamMid[1]);
        }

        const int v0 = edge.V[0];
        const int v1 = edge.V[1];
        int unit = 0, i = 0;
        float* data0 = nullptr;
        float* data1 = nullptr;
        float* data = nullptr;
        constexpr int numColorUnits = System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::ColorUnits);
        for (unit = 0; unit < numColorUnits; ++unit)
        {
            if (vba.HasColor(unit))
            {
                data0 = (float*)vba.GetColorTuple(unit, v0);
                data1 = (float*)vba.GetColorTuple(unit, v1);
                data = (float*)vba.GetColorTuple(unit, numVertices);
                for (i = 0; i < vba.GetColorChannels(unit); ++i)
                {
                    data[i] = 0.5f * (data0[i] + data1[i]);
                }
            }
        }

        constexpr int numTCoordUnits = System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::TextureCoordinateUnits);
        for (unit = 0; unit < numTCoordUnits; ++unit)
        {
            if (vba.HasTextureCoord(unit))
            {
                data0 = (float*)vba.GetTextureCoordTuple(unit, v0);
                data1 = (float*)vba.GetTextureCoordTuple(unit, v1);
                data = (float*)vba.GetTextureCoordTuple(unit, numVertices);
                for (i = 0; i < vba.GetTextureCoordChannels(unit); ++i)
                {
                    data[i] = 0.5f * (data0[i] + data1[i]);
                }
            }
        }

        if (mAllowDynamicChange)
        {
            mSInfo[numVertices].Patch = edge.Patch;
            mSInfo[numVertices].Param = edge.ParamMid;
        }

        edge.VMid = numVertices++;
    }

    // This allows numTriangles to change inside the loop.
    const int tmpNumTriangles = numTriangles;
    int i = 0;
    for (i = 0; i < tmpNumTriangles; ++i)
    {
        Triangle& tri0 = triangles[i];

        // Get the vertices.
        const int v0 = tri0.V[0];
        const int v1 = tri0.V[1];
        const int v2 = tri0.V[2];

        // Get the edge information.
        const Mathematics::EdgeKey key01(v0, v1);
        EdgeMap::iterator iter2 = edgeMap.find(key01);
        Edge& edge01 = iter2->second;

        const Mathematics::EdgeKey key12(v1, v2);
        iter2 = edgeMap.find(key12);
        Edge& edge12 = iter2->second;

        const Mathematics::EdgeKey key20(v2, v0);
        iter2 = edgeMap.find(key20);
        Edge& edge20 = iter2->second;

        Mathematics::Float2 param0 = edge01.Param[edge01.V[0] == v0 ? 0 : 1];
        Mathematics::Float2 param1 = edge12.Param[edge12.V[0] == v1 ? 0 : 1];
        Mathematics::Float2 param2 = edge20.Param[edge20.V[0] == v2 ? 0 : 1];

        // Get the midpoint information.
        const int v01 = edge01.VMid;
        Mathematics::Float2 param01 = edge01.ParamMid;
        const int v12 = edge12.VMid;
        Mathematics::Float2 param12 = edge12.ParamMid;
        const int v20 = edge20.VMid;
        Mathematics::Float2 param20 = edge20.ParamMid;

        // Tf done with edges, remove them.
        if (--edge01.References == 0)
        {
            edgeMap.erase(key01);
        }
        if (--edge12.References == 0)
        {
            edgeMap.erase(key12);
        }
        if (--edge20.References == 0)
        {
            edgeMap.erase(key20);
        }

        // Insert the six new boundary edges.
        InsertInto(edgeMap, tri0.Patch, v0, v01, param0, param01, 1);
        InsertInto(edgeMap, tri0.Patch, v01, v1, param01, param1, 1);
        InsertInto(edgeMap, tri0.Patch, v1, v12, param1, param12, 1);
        InsertInto(edgeMap, tri0.Patch, v12, v2, param12, param2, 1);
        InsertInto(edgeMap, tri0.Patch, v2, v20, param2, param20, 1);
        InsertInto(edgeMap, tri0.Patch, v20, v0, param20, param0, 1);

        // Insert the three new interior edges.
        InsertInto(edgeMap, tri0.Patch, v01, v12, param01, param12, 2);
        InsertInto(edgeMap, tri0.Patch, v12, v20, param12, param20, 2);
        InsertInto(edgeMap, tri0.Patch, v20, v01, param20, param01, 2);

        // The old triangle is replaced by the new interior triangle.
        tri0.V[0] = v01;
        tri0.V[1] = v12;
        tri0.V[2] = v20;

        // Insert the remaining triangles in new slots.
        Triangle& tri1 = triangles[numTriangles++];
        tri1.Patch = tri0.Patch;
        tri1.V[0] = v0;
        tri1.V[1] = v01;
        tri1.V[2] = v20;

        Triangle& tri2 = triangles[numTriangles++];
        tri2.Patch = tri0.Patch;
        tri2.V[0] = v01;
        tri2.V[1] = v1;
        tri2.V[2] = v12;

        Triangle& tri3 = triangles[numTriangles++];
        tri3.Patch = tri0.Patch;
        tri3.V[0] = v20;
        tri3.V[1] = v12;
        tri3.V[2] = v2;
    }

    numEdges = (int)edgeMap.size();
}

void Rendering::SurfaceMesh ::InsertInto(EdgeMap& edgeMap, SurfacePatchSmartPointer patch, int v0, int v1, const Mathematics::Float2& param0, const Mathematics::Float2& param1, int newReferences)
{
    Mathematics::EdgeKey key(v0, v1);
    const EdgeMap::iterator iter = edgeMap.find(key);
    if (iter == edgeMap.end())
    {
        Edge edge(v0, v1);
        edge.Patch = patch;
        edge.Param[0] = param0;
        edge.Param[1] = param1;
        edge.References = newReferences;
        edgeMap.insert(std::make_pair(key, edge));
    }
    else
    {
        iter->second.References += newReferences;
    }
}

void Rendering::SurfaceMesh ::OnDynamicChange()
{
    if (mAllowDynamicChange)
    {
        VertexBufferAccessor vba(GetVertexFormat(), GetVertexBuffer());

        for (int i = 0; i < mNumFullVertices; ++i)
        {
            const SurfaceInfo& si = mSInfo[i];
            GetVertexBuffer()->SetPosition(vba, i, si.Patch->GetPosition(si.Param.GetFirstValue(), si.Param.GetSecondValue()));
        }

        UpdateModelSpace(VisualUpdateType::Normals);
    }
}

void Rendering::SurfaceMesh ::Lock()
{
    CoreTools::DoNothing();
    if (mOrigVBuffer)
    {
        mOrigVBuffer.reset();
        mOrigIBuffer.reset();
        mOrigParams.reset();
        DELETE1(mPatches);
        mPatches = nullptr;
    }

    // The array mSInfo is not deleted.  This allows dynamic updates of
    // the vertices of the mesh, even though the mesh is "locked".
}

bool Rendering::SurfaceMesh ::IsLocked() const noexcept
{
    return !mOrigVBuffer;
}

void Rendering::SurfaceMesh ::InitializeSurfaceInfo() noexcept
{
    // Because vertices are shared by triangles, the last visited triangle
    // for a vertex donates its patch and parameter values to that vertex.
    // 先通过编译
    /*
	int* indices = (int*)mOrigIBuffer->GetData();
	const  Float2* params = mOrigParams->GetData();
	for (int i = 0; i < mNumPatches; ++i)
	{
		int v0 = *indices++;
		int v1 = *indices++;
		int v2 = *indices++;
		mSInfo[v0].Patch = mPatches[i];
		mSInfo[v0].Param = *params++;
		mSInfo[v1].Patch = mPatches[i];
		mSInfo[v1].Param = *params++;
		mSInfo[v2].Patch = mPatches[i];
		mSInfo[v2].Param = *params++;
	}*/
}

// SurfaceMesh::Edge

Rendering::SurfaceMesh::Edge ::Edge(int v0, int v1)  
    : Patch(), VMid(-1), ParamMid(0.0f, 0.0f), References(0)
{
    V[0] = v0;
    V[1] = v1;
    Param[0] = Mathematics::Float2(0.0f, 0.0f);
    Param[1] = Mathematics::Float2(0.0f, 0.0f);
}

bool Rendering::SurfaceMesh::Edge ::operator<(const Edge& edge) const
{
    return Mathematics::EdgeKey(V[0], V[1]) < Mathematics::EdgeKey(edge.V[0], edge.V[1]);
}

// SurfaceMesh::Triangle

Rendering::SurfaceMesh::Triangle ::Triangle() noexcept
    : Patch(nullptr)
{
    for (int i = 0; i < 3; ++i)
    {
        V[i] = -1;
    }
}

// SurfaceMesh::SurfaceInfo

Rendering::SurfaceMesh::SurfaceInfo ::SurfaceInfo()  
    : Patch(nullptr), Param(0.0f, 0.0f)
{
}
// Name support.

const CoreTools::ObjectSmartPointer Rendering::SurfaceMesh ::GetObjectByName(const std::string& name)
{
    CoreTools::ObjectSmartPointer found = ParentType::GetObjectByName(name);
    if (found)
    {
        return found;
    }

    found = mOrigVBuffer->GetObjectByName(name);
    if (found)
    {
        return found;
    }

    found = mOrigIBuffer->GetObjectByName(name);
    if (found)
    {
        return found;
    }

    found = mOrigParams->GetObjectByName(name);
    if (found)
    {
        return found;
    }

    if (mPatches)
    {
        for (int i = 0; i < mNumPatches; ++i)
        {
            CoreTools::ObjectSmartPointer found2 = mPatches[i]->GetObjectByName(name);
            if (found2)
                return found2;
        }
    }

    return CoreTools::ObjectSmartPointer();
}

const std::vector<CoreTools::ObjectSmartPointer> Rendering::SurfaceMesh ::GetAllObjectsByName(const std::string& name)
{
    std::vector<CoreTools::ObjectSmartPointer> objects = ParentType::GetAllObjectsByName(name);

    std::vector<CoreTools::ObjectSmartPointer> pointerObjects = mOrigVBuffer->GetAllObjectsByName(name);
    objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());

    pointerObjects = mOrigIBuffer->GetAllObjectsByName(name);
    objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
    pointerObjects = mOrigParams->GetAllObjectsByName(name);
    objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());

    if (mPatches)
    {
        for (int i = 0; i < mNumPatches; ++i)
        {
            pointerObjects = mPatches[mNumPatches]->GetAllObjectsByName(name);
            objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
        }
    }

    return objects;
}

const CoreTools::ConstObjectSmartPointer Rendering::SurfaceMesh ::GetConstObjectByName(const std::string& name) const
{
    CoreTools::ConstObjectSmartPointer found = ParentType::GetConstObjectByName(name);
    if (found)
    {
        return found;
    }

    found = mOrigVBuffer->GetConstObjectByName(name);
    if (found)
    {
        return found;
    }

    found = mOrigIBuffer->GetConstObjectByName(name);
    if (found)
    {
        return found;
    }

    found = mOrigParams->GetConstObjectByName(name);
    if (found)
    {
        return found;
    }

    if (mPatches)
    {
        for (int i = 0; i < mNumPatches; ++i)
        {
            CoreTools::ConstObjectSmartPointer found2 = mPatches[i]->GetConstObjectByName(name);
            if (found2)
                return found2;
        }
    }

    return CoreTools::ConstObjectSmartPointer();
}

const std::vector<CoreTools::ConstObjectSmartPointer> Rendering::SurfaceMesh ::GetAllConstObjectsByName(const std::string& name) const
{
    std::vector<CoreTools::ConstObjectSmartPointer> objects = ParentType::GetAllConstObjectsByName(name);

    std::vector<CoreTools::ConstObjectSmartPointer> pointerObjects = mOrigVBuffer->GetAllConstObjectsByName(name);
    objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());

    pointerObjects = mOrigIBuffer->GetAllConstObjectsByName(name);
    objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
    pointerObjects = mOrigParams->GetAllConstObjectsByName(name);
    objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());

    if (mPatches)
    {
        for (int i = 0; i < mNumPatches; ++i)
        {
            pointerObjects = mPatches[mNumPatches]->GetAllConstObjectsByName(name);
            objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
        }
    }

    return objects;
}

// Streaming support.

Rendering::SurfaceMesh ::SurfaceMesh(LoadConstructor value)
    : ParentType(value), mPatches(0), mNumFullVertices(0), mNumPatches(0), mLevel(0), mAllowDynamicChange(false), mSInfo(0)
{
}

void Rendering::SurfaceMesh ::Load(CoreTools::BufferSource& source)
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    source.Read(mNumFullVertices);
    source.Read(mNumPatches);
    source.Read(mLevel);
    mAllowDynamicChange = source.ReadBool();
    //source.ReadSmartPointer(mOrigVBuffer);
    //source.ReadSmartPointer(mOrigIBuffer);
    //source.ReadSmartPointer(mOrigParams);

    const bool locked = (!mOrigVBuffer);
    if (!locked)
    {
        //source.ReadSmartPointer(mNumPatches, mPatches);
    }

    if (mAllowDynamicChange)
    {
        mSInfo = NEW1<SurfaceInfo>(mNumFullVertices);
        for (int i = 0; i < mNumFullVertices; ++i)
        {
            //source.ReadSmartPointer(mSInfo[i].Patch);
            //source.ReadAggregate(mSInfo[i].Param);
        }
    }

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::SurfaceMesh ::Link(CoreTools::ObjectLink& source)
{
    ParentType::Link(source);

    //source.ResolveObjectSmartPointerLink(mOrigVBuffer);
    //source.ResolveObjectSmartPointerLink(mOrigIBuffer);
    //source.ResolveObjectSmartPointerLink(mOrigParams);
    //source.ResolveObjectSmartPointerLink(mNumPatches, mPatches);
    if (mSInfo)
    {
        for (int i = 0; i < mNumFullVertices; ++i)
        {
            //source.ResolveObjectSmartPointerLink(mSInfo[i].Patch);
        }
    }
}

void Rendering::SurfaceMesh ::PostLink()
{
    ParentType::PostLink();
}

uint64_t Rendering::SurfaceMesh ::Register(CoreTools::ObjectRegister& target) const
{
    const uint64_t id = ParentType::Register(target);
    if (0 < id)
    {
        //target.RegisterSmartPointer(mOrigVBuffer);
        //target.RegisterSmartPointer(mOrigIBuffer);
        //target.RegisterSmartPointer(mOrigParams);
        //target.RegisterSmartPointer(mNumPatches, mPatches);
        if (mSInfo)
        {
            for (int i = 0; i < mNumFullVertices; ++i)
            {
                //target.RegisterSmartPointer(mSInfo[i].Patch);
            }
        }
        return id;
    }
    return id;
}

void Rendering::SurfaceMesh ::Save(CoreTools::BufferTarget& target) const
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    target.Write(mNumFullVertices);
    target.Write(mNumPatches);
    target.Write(mLevel);
    target.WriteBool(mAllowDynamicChange);
    //target.WriteSmartPointer(mOrigVBuffer);
    //target.WriteSmartPointer(mOrigIBuffer);
    //target.WriteSmartPointer(mOrigParams);
    //target.WriteSmartPointerWithNumber(mNumPatches, mPatches);

    if (mSInfo)
    {
        for (int i = 0; i < mNumFullVertices; i++)
        {
            //target.WriteSmartPointer(mSInfo[i].Patch);
            //target.WriteAggregate(mSInfo[i].Param);
        }
    }

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::SurfaceMesh ::GetStreamingSize() const
{
    int size = ParentType::GetStreamingSize();
    size += sizeof(mNumFullVertices);
    size += sizeof(mNumPatches);
    size += sizeof(mLevel);
    size += CORE_TOOLS_STREAM_SIZE(mAllowDynamicChange);
    size += CORE_TOOLS_STREAM_SIZE(mOrigVBuffer);
    size += CORE_TOOLS_STREAM_SIZE(mOrigIBuffer);
    size += CORE_TOOLS_STREAM_SIZE(mOrigParams);

    if (mPatches)
    {
        size += mNumPatches * CORE_TOOLS_STREAM_SIZE(mPatches[0]);
    }

    if (mSInfo)
    {
        size += mNumFullVertices * CORE_TOOLS_STREAM_SIZE(mSInfo[0].Patch);
        size += mNumFullVertices * sizeof(mSInfo[0].Param);
    }

    return size;
}

#include STSTEM_WARNING_POP
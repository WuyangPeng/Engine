///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 14:00)

#include "Rendering/RenderingExport.h"

#include "SurfaceMesh.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Base/SpanIteratorDetail.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Meshes/EdgeKey.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"

#include <set>

CORE_TOOLS_RTTI_DEFINE(Rendering, SurfaceMesh);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, SurfaceMesh);
CORE_TOOLS_FACTORY_DEFINE(Rendering, SurfaceMesh);

Rendering::SurfaceMesh::SurfaceMesh(const VertexFormatSharedPtr& vformat,
                                    const VertexBufferSharedPtr& vbuffer,
                                    const IndexBufferSharedPtr& ibuffer,
                                    const Float2ArraySharedPtr& params,
                                    const std::vector<CoreTools::ObjectAssociated<SurfacePatch>>& patches,
                                    bool allowDynamicChange)
    : ParentType{ vformat, vbuffer, ibuffer },
      origVBuffer{ vbuffer },
      origIBuffer{ ibuffer },
      origParams{ params },
      patches{ patches },
      numFullVertices{ vbuffer->GetNumElements() },
      numPatches{ ibuffer->GetNumElements() / 3 },
      level{ 0 },
      allowDynamicChange{ allowDynamicChange },
      sInfo{}
{
    if (allowDynamicChange)
    {
        sInfo.resize(numFullVertices);
        InitializeSurfaceInfo();
    }

    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, SurfaceMesh)

void Rendering::SurfaceMesh::SetLevel(int aLevel)
{
    RENDERING_CLASS_IS_VALID_1;

    if (origVBuffer.object == nullptr)
    {
        return;
    }

    if (level == aLevel)
    {
        return;
    }

    level = aLevel;

    auto numTotalVertices = 0;
    auto numTotalEdges = 0;
    auto numTotalTriangles = 0;
    EdgeMap edgeMap{};
    auto triangles = Allocate(numTotalVertices, numTotalEdges, edgeMap, numTotalTriangles);

    auto numVertices = origVBuffer->GetNumElements();
    auto numEdges = boost::numeric_cast<int>(edgeMap.size());
    auto numTriangles = origIBuffer->GetNumElements() / 3;

    for (auto i = 0; i < level; ++i)
    {
        const auto nextNumVertices = numVertices + numEdges;
        const auto nextNumEdges = 2 * numEdges + 3 * numTriangles;
        const auto nextNumTriangles = 4 * numTriangles;
        Subdivide(numVertices, numEdges, edgeMap, numTriangles, triangles);
        RENDERING_ASSERTION_0(numVertices == nextNumVertices && numEdges == nextNumEdges && numTriangles == nextNumTriangles, "意外情况\n");
        numVertices = nextNumVertices;
        numEdges = nextNumEdges;
        numTriangles = nextNumTriangles;
    }

    RENDERING_ASSERTION_0(numVertices == numTotalVertices && numEdges == numTotalEdges && numTriangles == numTotalTriangles, "意外情况\n");
    numFullVertices = numTotalVertices;

    const auto numTotalIndices = 3 * numTotalTriangles;
    SetIndexBuffer(IndexBuffer::Create(IndexFormatType::Polypoint, numTotalIndices, sizeof(int)));

    auto indices = GetIndexBuffer()->GetData();
    for (auto i = 0; i < numTotalTriangles; ++i)
    {
        auto& tri = triangles.at(i);
        for (auto j = 0; j < 3; ++j)
        {
            indices.Increase(tri.v.at(j));
        }
    }
    RENDERER_MANAGE_SINGLETON.UpdateAll(GetIndexBuffer());

    OnDynamicChange();
    UpdateModelSpace(VisualUpdateType::Normals);
}

int Rendering::SurfaceMesh::GetLevel() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return level;
}

std::vector<Rendering::SurfaceMesh::Triangle> Rendering::SurfaceMesh::Allocate(int& numTotalVertices, int& numTotalEdges, EdgeMap& edgeMap, int& numTotalTriangles)
{
    RENDERING_CLASS_IS_VALID_9;

    auto numOrigVertices = origVBuffer->GetNumElements();

    const auto numOrigIndices = origIBuffer->GetNumElements();
    auto numOrigTriangles = numOrigIndices / 3;

    auto indices = origIBuffer->GetData();
    std::set<Mathematics::EdgeKey> eKeys{};

    for (auto i = 0; i < numOrigTriangles; ++i)
    {
        auto v0 = indices.Increase<int32_t>();
        auto v1 = indices.Increase<int32_t>();
        auto v2 = indices.Increase<int32_t>();

        eKeys.emplace(v0, v1);
        eKeys.emplace(v1, v2);
        eKeys.emplace(v2, v0);
    }

    const auto numOrigEdges = boost::numeric_cast<int>(eKeys.size());

    numTotalVertices = numOrigVertices;
    numTotalEdges = numOrigEdges;
    numTotalTriangles = numOrigTriangles;
    for (auto i = 0; i < level; ++i)
    {
        numTotalVertices = numTotalVertices + numTotalEdges;
        numTotalEdges = 2 * numTotalEdges + 3 * numTotalTriangles;
        numTotalTriangles = 4 * numTotalTriangles;
    }

    auto vstride = GetVertexFormat()->GetStride();
    SetVertexBuffer(VertexBuffer::Create(*GetVertexFormat(), vstride));
    std::vector<Triangle> triangles(numTotalTriangles);
    if (allowDynamicChange)
    {
        sInfo.resize(numTotalVertices);
        InitializeSurfaceInfo();
    }

    auto origData = origVBuffer->GetData();
    auto fullData = GetVertexBuffer()->GetData();
    const auto numOrigBytes = origVBuffer->GetNumBytes();

    for (int i = 0; i < numOrigBytes; ++i)
    {
        fullData.Increase(origData.Increase<char>());
    }

    auto origParam = origParams->GetData();
    indices = origIBuffer->GetData();
    for (auto i = 0; i < numOrigTriangles; ++i)
    {
        auto& tri = triangles.at(i);

        tri.patch.object = patches.at(i).object;

        auto v0 = indices.Increase<int32_t>();
        auto v1 = indices.Increase<int32_t>();
        auto v2 = indices.Increase<int32_t>();
        tri.v.at(0) = v0;
        tri.v.at(1) = v1;
        tri.v.at(2) = v2;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        const auto& param0 = *origParam++;
        const auto& param1 = *origParam++;
        const auto& param2 = *origParam++;

#include STSTEM_WARNING_POP

        InsertInto(edgeMap, tri.patch.object, v0, v1, param0, param1, 1);
        InsertInto(edgeMap, tri.patch.object, v1, v2, param1, param2, 1);
        InsertInto(edgeMap, tri.patch.object, v2, v0, param2, param0, 1);
    }

    RENDERING_ASSERTION_0(numOrigEdges == boost::numeric_cast<int>(edgeMap.size()), "意外情况\n");

    return triangles;
}

void Rendering::SurfaceMesh::Subdivide(int& numVertices, int& numEdges, EdgeMap& edgeMap, int& numTriangles, std::vector<Triangle>& triangles)
{
    RENDERING_CLASS_IS_VALID_9;

    VertexBuffer vba = *GetVertexBuffer();

    for (auto& value : edgeMap)
    {
        auto& edge = value.second;
        edge.paramMid[0] = (0.5f * (edge.param.at(0)[0] + edge.param.at(1)[0]));
        edge.paramMid[1] = (0.5f * (edge.param.at(0)[1] + edge.param.at(1)[1]));

        const auto v0 = edge.v.at(0);
        const auto v1 = edge.v.at(1);

        if (allowDynamicChange)
        {
            sInfo.at(numVertices).patch.object = edge.patch;
            sInfo.at(numVertices).param = edge.paramMid;
        }

        edge.vMid = numVertices++;
    }

    const auto tmpNumTriangles = numTriangles;

    for (auto i = 0; i < tmpNumTriangles; ++i)
    {
        auto& tri0 = triangles.at(i);

        const auto v0 = tri0.v.at(0);
        const auto v1 = tri0.v.at(1);
        const auto v2 = tri0.v.at(2);

        const Mathematics::EdgeKey key01{ v0, v1 };
        auto iter2 = edgeMap.find(key01);
        auto& edge01 = iter2->second;

        const Mathematics::EdgeKey key12{ v1, v2 };
        iter2 = edgeMap.find(key12);
        auto& edge12 = iter2->second;

        const Mathematics::EdgeKey key20{ v2, v0 };
        iter2 = edgeMap.find(key20);
        auto& edge20 = iter2->second;

        const auto param0 = edge01.param.at(edge01.v.at(0) == v0 ? 0 : 1);
        const auto param1 = edge12.param.at(edge12.v.at(0) == v1 ? 0 : 1);
        const auto param2 = edge20.param.at(edge20.v.at(0) == v2 ? 0 : 1);

        const auto v01 = edge01.vMid;
        const auto param01 = edge01.paramMid;
        const auto v12 = edge12.vMid;
        const auto param12 = edge12.paramMid;
        const auto v20 = edge20.vMid;
        const auto param20 = edge20.paramMid;

        if (--edge01.references == 0)
        {
            edgeMap.erase(key01);
        }
        if (--edge12.references == 0)
        {
            edgeMap.erase(key12);
        }
        if (--edge20.references == 0)
        {
            edgeMap.erase(key20);
        }

        InsertInto(edgeMap, tri0.patch.object, v0, v01, param0, param01, 1);
        InsertInto(edgeMap, tri0.patch.object, v01, v1, param01, param1, 1);
        InsertInto(edgeMap, tri0.patch.object, v1, v12, param1, param12, 1);
        InsertInto(edgeMap, tri0.patch.object, v12, v2, param12, param2, 1);
        InsertInto(edgeMap, tri0.patch.object, v2, v20, param2, param20, 1);
        InsertInto(edgeMap, tri0.patch.object, v20, v0, param20, param0, 1);

        InsertInto(edgeMap, tri0.patch.object, v01, v12, param01, param12, 2);
        InsertInto(edgeMap, tri0.patch.object, v12, v20, param12, param20, 2);
        InsertInto(edgeMap, tri0.patch.object, v20, v01, param20, param01, 2);

        tri0.v.at(0) = v01;
        tri0.v.at(1) = v12;
        tri0.v.at(2) = v20;

        auto& tri1 = triangles.at(numTriangles++);
        tri1.patch = tri0.patch;
        tri1.v.at(0) = v0;
        tri1.v.at(1) = v01;
        tri1.v.at(2) = v20;

        auto& tri2 = triangles.at(numTriangles++);
        tri2.patch = tri0.patch;
        tri2.v.at(0) = v01;
        tri2.v.at(1) = v1;
        tri2.v.at(2) = v12;

        auto& tri3 = triangles.at(numTriangles++);
        tri3.patch = tri0.patch;
        tri3.v.at(0) = v20;
        tri3.v.at(1) = v12;
        tri3.v.at(2) = v2;
    }

    numEdges = boost::numeric_cast<int>(edgeMap.size());
}

void Rendering::SurfaceMesh::InsertInto(EdgeMap& edgeMap, const SurfacePatchSharedPtr& patch, int v0, int v1, const Mathematics::Float2& param0, const Mathematics::Float2& param1, int newReferences)
{
    RENDERING_CLASS_IS_VALID_1;

    Mathematics::EdgeKey key{ v0, v1 };
    const auto iter = edgeMap.find(key);
    if (iter == edgeMap.end())
    {
        Edge edge{ v0, v1 };
        edge.patch = patch;
        edge.param.at(0) = param0;
        edge.param.at(1) = param1;
        edge.references = newReferences;
        edgeMap.insert(std::make_pair(key, edge));
    }
    else
    {
        iter->second.references += newReferences;
    }
}

void Rendering::SurfaceMesh::OnDynamicChange()
{
    RENDERING_CLASS_IS_VALID_1;

    if (allowDynamicChange)
    {
        for (auto i = 0; i < numFullVertices; ++i)
        {
        }

        UpdateModelSpace(VisualUpdateType::Normals);
    }
}

void Rendering::SurfaceMesh::Lock() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    if (origVBuffer.object != nullptr)
    {
        origVBuffer.object.reset();
        origIBuffer.object.reset();
        origParams.object.reset();

        patches.clear();
    }
}

bool Rendering::SurfaceMesh::IsLocked() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return origVBuffer.object == nullptr;
}

void Rendering::SurfaceMesh::InitializeSurfaceInfo()
{
    RENDERING_CLASS_IS_VALID_1;

    auto indices = origIBuffer->GetData();
    const auto* params = origParams->GetData();
    for (auto i = 0; i < numPatches; ++i)
    {
        const auto v0 = indices.Increase<int32_t>();
        const auto v1 = indices.Increase<int32_t>();
        const auto v2 = indices.Increase<int32_t>();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        sInfo.at(v0).patch.object = patches.at(i).object;
        sInfo.at(v0).param = *params++;
        sInfo.at(v1).patch.object = patches.at(i).object;
        sInfo.at(v1).param = *params++;
        sInfo.at(v2).patch.object = patches.at(i).object;
        sInfo.at(v2).param = *params++;

#include STSTEM_WARNING_POP
    }
}

Rendering::SurfaceMesh::Edge::Edge(int v0, int v1) noexcept
    : patch{}, v{ v0, v1 }, param{}, vMid(-1), paramMid{ 0.0f, 0.0f }, references{ 0 }
{
}

bool Rendering::SurfaceMesh::Edge::operator<(const Edge& edge) const
{
    return Mathematics::EdgeKey{ v.at(0), v.at(1) } < Mathematics::EdgeKey{ edge.v.at(0), edge.v.at(1) };
}

Rendering::SurfaceMesh::Triangle::Triangle() noexcept
    : patch{ nullptr }, v{ -1, -1, -1 }
{
}

Rendering::SurfaceMesh::SurfaceInfo::SurfaceInfo() noexcept
    : patch{ nullptr }, param{ 0.0f, 0.0f }
{
}

CoreTools::ObjectSharedPtr Rendering::SurfaceMesh::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    auto found = ParentType::GetObjectByName(name);
    if (found)
    {
        return found;
    }

    found = origVBuffer->GetObjectByName(name);
    if (found)
    {
        return found;
    }

    found = origIBuffer->GetObjectByName(name);
    if (found)
    {
        return found;
    }

    found = origParams->GetObjectByName(name);
    if (found)
    {
        return found;
    }

    if (!patches.empty())
    {
        for (auto i = 0; i < numPatches; ++i)
        {
            auto found2 = patches.at(i)->GetObjectByName(name);
            if (found2)
                return found2;
        }
    }

    return nullptr;
}

std::vector<CoreTools::ObjectSharedPtr> Rendering::SurfaceMesh::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    auto objects = ParentType::GetAllObjectsByName(name);

    auto pointerObjects = origVBuffer->GetAllObjectsByName(name);
    objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());

    pointerObjects = origIBuffer->GetAllObjectsByName(name);
    objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
    pointerObjects = origParams->GetAllObjectsByName(name);
    objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());

    if (!patches.empty())
    {
        for (auto i = 0; i < numPatches; ++i)
        {
            pointerObjects = patches.at(i)->GetAllObjectsByName(name);
            objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
        }
    }

    return objects;
}

CoreTools::ConstObjectSharedPtr Rendering::SurfaceMesh::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_1;

    auto found = ParentType::GetConstObjectByName(name);
    if (found)
    {
        return found;
    }

    found = origVBuffer->GetConstObjectByName(name);
    if (found)
    {
        return found;
    }

    found = origIBuffer->GetConstObjectByName(name);
    if (found)
    {
        return found;
    }

    found = origParams->GetConstObjectByName(name);
    if (found)
    {
        return found;
    }

    if (!patches.empty())
    {
        for (auto i = 0; i < numPatches; ++i)
        {
            auto found2 = patches.at(i)->GetConstObjectByName(name);
            if (found2)
                return found2;
        }
    }

    return nullptr;
}

std::vector<CoreTools::ConstObjectSharedPtr> Rendering::SurfaceMesh::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_1;

    auto objects = ParentType::GetAllConstObjectsByName(name);

    auto pointerObjects = origVBuffer->GetAllConstObjectsByName(name);
    objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());

    pointerObjects = origIBuffer->GetAllConstObjectsByName(name);
    objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
    pointerObjects = origParams->GetAllConstObjectsByName(name);
    objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());

    if (!patches.empty())
    {
        for (auto i = 0; i < numPatches; ++i)
        {
            pointerObjects = patches.at(i)->GetAllConstObjectsByName(name);
            objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
        }
    }

    return objects;
}

Rendering::SurfaceMesh::SurfaceMesh(LoadConstructor value)
    : ParentType{ value },
      origVBuffer{},
      origIBuffer{},
      origParams{},
      patches{},
      numFullVertices{},
      numPatches{},
      level{ 0 },
      allowDynamicChange{ false },
      sInfo{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::SurfaceMesh::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    source.Read(numFullVertices);
    source.Read(numPatches);
    source.Read(level);
    allowDynamicChange = source.ReadBool();
    source.ReadObjectAssociated(origVBuffer);
    source.ReadObjectAssociated(origIBuffer);
    source.ReadObjectAssociated(origParams);

    const bool locked = (origVBuffer.object == nullptr);
    if (!locked)
    {
        source.ReadObjectAssociatedContainer(patches);
    }

    if (allowDynamicChange)
    {
        sInfo.resize(numFullVertices);
        for (int i = 0; i < numFullVertices; ++i)
        {
            source.ReadObjectAssociated(sInfo.at(i).patch);
            source.ReadAggregate(sInfo.at(i).param);
        }
    }

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::SurfaceMesh::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);

    source.ResolveLink(origVBuffer);
    source.ResolveLink(origIBuffer);
    source.ResolveLink(origParams);
    source.ResolveLinkContainer(patches);
    if (!sInfo.empty())
    {
        for (int i = 0; i < numFullVertices; ++i)
        {
            source.ResolveLink(sInfo.at(i).patch);
        }
    }
}

void Rendering::SurfaceMesh::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

int64_t Rendering::SurfaceMesh::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto id = ParentType::Register(target);
    if (0 < id)
    {
        target.Register(origVBuffer);
        target.Register(origIBuffer);
        target.Register(origParams);
        target.RegisterContainer(patches);
        if (!sInfo.empty())
        {
            for (int i = 0; i < numFullVertices; ++i)
            {
                target.Register(sInfo.at(i).patch);
            }
        }
        return id;
    }
    return id;
}

void Rendering::SurfaceMesh::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    target.Write(numFullVertices);
    target.Write(numPatches);
    target.Write(level);
    target.Write(allowDynamicChange);
    target.WriteObjectAssociated(origVBuffer);
    target.WriteObjectAssociated(origIBuffer);
    target.WriteObjectAssociated(origParams);
    target.WriteObjectAssociatedContainerWithNumber(patches);

    if (!sInfo.empty())
    {
        for (auto i = 0; i < numFullVertices; i++)
        {
            target.WriteObjectAssociated(sInfo.at(i).patch);
            target.WriteAggregate(sInfo.at(i).param);
        }
    }

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::SurfaceMesh::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = ParentType::GetStreamingSize();
    size += CoreTools::GetStreamSize(numFullVertices);
    size += CoreTools::GetStreamSize(numPatches);
    size += CoreTools::GetStreamSize(level);
    size += CoreTools::GetStreamSize(allowDynamicChange);
    size += CoreTools::GetStreamSize(origVBuffer);
    size += CoreTools::GetStreamSize(origIBuffer);
    size += CoreTools::GetStreamSize(origParams);

    if (!patches.empty())
    {
        size += numPatches * CoreTools::GetStreamSize(patches.at(0));
    }

    if (!sInfo.empty())
    {
        size += numFullVertices * CoreTools::GetStreamSize(sInfo.at(0).patch);
        size += numFullVertices * CoreTools::GetStreamSize(sInfo.at(0).param);
    }

    return size;
}

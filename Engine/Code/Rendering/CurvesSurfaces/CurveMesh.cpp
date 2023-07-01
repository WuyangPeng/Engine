///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:59)

#include "Rendering/RenderingExport.h"

#include "CurveMesh.h"
#include "CoreTools/Base/SpanIteratorDetail.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Base/Float.h" 
#include "Rendering/Resources/Buffers/VertexBuffer.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, CurveMesh);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, CurveMesh);
CORE_TOOLS_FACTORY_DEFINE(Rendering, CurveMesh);

Rendering::CurveMesh::CurveMesh(const VertexFormatSharedPtr& vformat, const VertexBufferSharedPtr& vbuffer, const std::vector<CoreTools::ObjectAssociated<CurveSegment>>& segments, const FloatArraySharedPtr& params, bool allowDynamicChange)
    : ParentType{ vformat, vbuffer, true },
      origVBuffer{ vbuffer },
      origParams{ params },
      segments{ segments },
      numFullVertices{ vbuffer->GetNumElements() },
      numSegments{ vbuffer->GetNumElements() - 1 },
      level{ 0 },
      allowDynamicChange{ allowDynamicChange },
      cInfo{}
{
    if (allowDynamicChange)
    {
        cInfo.resize(numFullVertices);
        InitializeCurveInfo();
    }

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, CurveMesh)

void Rendering::CurveMesh::SetLevel(int aLevel)
{
    RENDERING_CLASS_IS_VALID_9;

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

    auto edges = Allocate(numTotalVertices, numTotalEdges);

    auto numVertices = numSegments + 1;
    auto numEdges = numSegments;

    for (auto i = 0; i < level; ++i)
    {
        const auto nextNumVertices = numVertices + numEdges;
        const auto nextNumEdges = 2 * numEdges;
        Subdivide(numVertices, numEdges, edges);
        RENDERING_ASSERTION_0(numVertices == nextNumVertices && numEdges == nextNumEdges, "意外情况。\n");
        numVertices = nextNumVertices;
        numEdges = nextNumEdges;
    }

    RENDERING_ASSERTION_0(numVertices == numTotalVertices && numEdges == numTotalEdges, "意外情况。\n");
    SetNumSegments(numTotalVertices - 1);
    numFullVertices = numTotalVertices;

    UpdateModelSpace(VisualUpdateType::Normals);

    OnDynamicChange();
  
}

int Rendering::CurveMesh::GetLevel() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return level;
}

std::vector<Rendering::CurveMesh::Edge> Rendering::CurveMesh::Allocate(int& numTotalVertices, int& numTotalEdges)
{
    auto numOrigVertices = numSegments + 1;

    auto numOrigEdges = numSegments;

    numTotalVertices = numOrigVertices;
    numTotalEdges = numOrigEdges;

    for (auto i = 0; i < level; ++i)
    {
        numTotalVertices = numTotalVertices + numTotalEdges;
        numTotalEdges = 2 * numTotalEdges;
    }

    auto vstride = GetVertexFormat()->GetStride();
    SetVertexBuffer(VertexBuffer::Create(*GetVertexFormat(), vstride));
    std::vector<Edge> edges(numTotalEdges);

    if (allowDynamicChange)
    {
        cInfo.clear();
        cInfo.resize(numTotalVertices);
        InitializeCurveInfo();
    }

    auto origParam = 0;
    auto origData = origVBuffer.object->GetData();
    auto fullData = GetVertexBuffer()->GetData();
    auto index = 0;
    const auto indexDelta = (1 << level);

    for (auto i = 0; i < numOrigEdges; ++i)
    {
        auto& edge = edges.at(i);

        edge.segment = segments.at(i).object;

        edge.v.at(0) = index;
        index += indexDelta;
        edge.v.at(1) = index;

        edge.param.at(0) = (*origParams.object)[origParam++];
        edge.param.at(1) = (*origParams.object)[origParam++];

        fullData.Increase(*origData.GetCurrent());

        ++origData;
    }

    fullData.Increase(*origData.GetCurrent());

    return edges;
}

void Rendering::CurveMesh::Subdivide(int& numVertices, int& numEdges, std::vector<Edge>& edges)
{
    for (auto old = numEdges - 1, curr = 2 * numEdges - 1; old >= 0; --old)
    {
        const auto& edge = edges.at(old);

        const auto v0 = edge.v.at(0);
        const auto v1 = edge.v.at(1);
        auto vMid = (v0 + v1) / 2;
        const auto paramMid = 0.5f * (edge.param.at(0) + edge.param.at(1));

        constexpr auto numColorUnits = System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::ColorUnits);
        for (auto unit = 0; unit < numColorUnits; ++unit)
        {
        }

        constexpr auto numTCoordUnits = System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::TextureCoordinateUnits);
        for (auto unit = 0; unit < numTCoordUnits; ++unit)
        {
        }

        if (allowDynamicChange)
        {
            cInfo.at(vMid).segment.object = edge.segment;
            cInfo.at(vMid).param = paramMid;
        }

        auto& edge1 = edges.at(curr--);
        edge1.segment = edge.segment;
        edge1.v.at(0) = vMid;
        edge1.v.at(1) = edge.v.at(1);
        edge1.param.at(0) = paramMid;
        edge1.param.at(1) = edge.param.at(1);

        auto& edge0 = edges.at(curr--);
        edge0.segment = edge.segment;
        edge0.v.at(0) = edge.v.at(0);
        edge0.v.at(1) = vMid;
        edge0.param.at(0) = edge.param.at(0);
        edge0.param.at(1) = paramMid;

        ++numVertices;
    }

    numEdges = 2 * numEdges;
}

void Rendering::CurveMesh::OnDynamicChange()
{
    RENDERING_CLASS_IS_VALID_9;

    if (allowDynamicChange)
    {
        UpdateModelSpace(VisualUpdateType::Normals);
    }
}

void Rendering::CurveMesh::Lock() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    if (origVBuffer.object)
    {
        origVBuffer.object.reset();
        origParams.object.reset();
        segments.clear();
    }
}

bool Rendering::CurveMesh::IsLocked() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return !origVBuffer.object;
}

void Rendering::CurveMesh::InitializeCurveInfo()
{
    RENDERING_CLASS_IS_VALID_9;

    auto params = 0;
    auto index = 0;
    const auto indexDelta = (1 << level);
    for (auto i = 0; i < numSegments; ++i)
    {
        const auto v0 = index;
        index += indexDelta;
        const auto v1 = index;
        cInfo.at(v0).segment.object = segments.at(i).object;
        cInfo.at(v0).param = (*origParams.object)[params++];
        cInfo.at(v1).segment.object = segments.at(i).object;
        cInfo.at(v1).param = (*origParams.object)[params++];
    }
}

Rendering::CurveMesh::Edge::Edge() noexcept
    : segment{}, v{ -1, -1 }, param{}
{
}

Rendering::CurveMesh::CurveInfo::CurveInfo() noexcept
    : segment{}, param{}
{
}

CoreTools::ObjectSharedPtr Rendering::CurveMesh::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    auto found = ParentType::GetObjectByName(name);
    if (found)
    {
        return found;
    }

    found = origVBuffer.object->GetObjectByName(name);
    if (found)
    {
        return found;
    }

    found = origParams.object->GetObjectByName(name);
    if (found)
    {
        return found;
    }

    for (auto i = 0; i < numSegments; ++i)
    {
        auto found2 = segments.at(i).object->GetObjectByName(name);
        if (found2)
            return found2;
    }

    return nullptr;
}

std::vector<CoreTools::ObjectSharedPtr> Rendering::CurveMesh::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    auto objects = ParentType::GetAllObjectsByName(name);

    auto pointerObjects = origVBuffer.object->GetAllObjectsByName(name);
    objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());

    pointerObjects = origParams.object->GetAllObjectsByName(name);
    objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());

    for (auto i = 0; i < numSegments; ++i)
    {
        pointerObjects = origParams.object->GetAllObjectsByName(name);
        objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
    }

    return objects;
}

CoreTools::ConstObjectSharedPtr Rendering::CurveMesh::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto found = ParentType::GetConstObjectByName(name);
    if (found)
    {
        return found;
    }

    found = origVBuffer.object->GetConstObjectByName(name);
    if (found)
    {
        return found;
    }

    found = origParams.object->GetConstObjectByName(name);
    if (found)
    {
        return found;
    }

    for (auto i = 0; i < numSegments; ++i)
    {
        auto found2 = segments.at(i).object->GetConstObjectByName(name);
        if (found2)
            return found2;
    }

    return nullptr;
}

std::vector<CoreTools::ConstObjectSharedPtr> Rendering::CurveMesh::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto objects = ParentType::GetAllConstObjectsByName(name);

    auto pointerObjects = origVBuffer.object->GetAllConstObjectsByName(name);
    objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());

    pointerObjects = origParams.object->GetAllConstObjectsByName(name);
    objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());

    for (auto i = 0; i < numSegments; ++i)
    {
        pointerObjects = origParams.object->GetAllConstObjectsByName(name);
        objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
    }

    return objects;
}

Rendering::CurveMesh::CurveMesh(LoadConstructor value)
    : ParentType{ value },
      origVBuffer{},
      origParams{},
      segments{},
      numFullVertices{},
      numSegments{},
      level{},
      allowDynamicChange{ false },
      cInfo{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

void Rendering::CurveMesh::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    source.Read(numFullVertices);
    source.Read(numSegments);
    source.Read(level);
    allowDynamicChange = source.ReadBool();
    source.ReadObjectAssociated(origVBuffer);
    source.ReadObjectAssociated(origParams);

    const bool locked = (!origVBuffer.object);
    if (!locked)
    {
        source.ReadObjectAssociatedContainer(segments);
    }

    if (allowDynamicChange)
    {
        cInfo.resize(numFullVertices);
        for (int i = 0; i < numFullVertices; ++i)
        {
            source.ReadObjectAssociated(cInfo.at(i).segment);
            source.Read(cInfo.at(i).param);
        }
    }

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::CurveMesh::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::Link(source);

    source.ResolveLink(origVBuffer);
    source.ResolveLink(origParams);
    source.ResolveLinkContainer(segments);

    for (int i = 0; i < numFullVertices; ++i)
    {
        source.ResolveLink(cInfo.at(i).segment);
    }
}

void Rendering::CurveMesh::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::PostLink();
}

int64_t Rendering::CurveMesh::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const uint64_t id = Polysegment::Register(target);
    if (0 < id)
    {
        target.Register(origVBuffer);
        target.Register(origParams);
        target.RegisterContainer(segments);

        for (int i = 0; i < numFullVertices; ++i)
        {
            target.Register(cInfo.at(i).segment);
        }

        return id;
    }
    return id;
}

void Rendering::CurveMesh::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    target.Write(numFullVertices);
    target.Write(numSegments);
    target.Write(level);
    target.Write(allowDynamicChange);
    target.WriteObjectAssociated(origVBuffer);
    target.WriteObjectAssociated(origParams);
    target.WriteObjectAssociatedContainerWithNumber(segments);

    for (int i = 0; i < numFullVertices; ++i)
    {
        target.WriteObjectAssociated(cInfo.at(i).segment);
        target.Write(cInfo.at(i).param);
    }

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::CurveMesh::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = ParentType::GetStreamingSize();
    size += CoreTools::GetStreamSize(numFullVertices);
    size += CoreTools::GetStreamSize(numSegments);
    size += CoreTools::GetStreamSize(level);
    size += CoreTools::GetStreamSize(allowDynamicChange);
    size += CoreTools::GetStreamSize(origVBuffer);
    size += CoreTools::GetStreamSize(origParams);

    if (!segments.empty())
    {
        size += numSegments * CoreTools::GetStreamSize(segments.at(0));
    }

    if (!cInfo.empty())
    {
        size += numFullVertices * CoreTools::GetStreamSize(cInfo.at(0).segment);
        size += numFullVertices * sizeof(cInfo[0].param);
    }

    return size;
}

CoreTools::ObjectInterfaceSharedPtr Rendering::CurveMesh::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

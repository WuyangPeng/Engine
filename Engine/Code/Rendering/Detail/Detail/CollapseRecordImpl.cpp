// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 10:50)

#include "Rendering/RenderingExport.h"

#include "CollapseRecordImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26418)
#include SYSTEM_WARNING_DISABLE(26415)
Rendering::CollapseRecordImpl ::CollapseRecordImpl(int vKeep, int vThrow, int numVertices, int numTriangles) noexcept
    : m_VKeep{ vKeep }, m_VThrow{ vThrow }, m_NumVertices{ numVertices }, m_NumTriangles{ numTriangles }, m_Indices{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::CollapseRecordImpl ::IsValid() const noexcept
{
    if (0 <= m_NumTriangles && 0 <= m_NumVertices)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

int Rendering::CollapseRecordImpl ::GetVKeep() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return m_VKeep;
}

void Rendering::CollapseRecordImpl ::SetVKeep(int vKeep) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    m_VKeep = vKeep;
}

int Rendering::CollapseRecordImpl ::GetNumVertices() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return m_NumVertices;
}

void Rendering::CollapseRecordImpl ::SetNumVertices(int numVertices) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    m_NumVertices = numVertices;
}

int Rendering::CollapseRecordImpl ::GetNumTriangles() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return m_NumTriangles;
}

void Rendering::CollapseRecordImpl ::SetNumTriangles(int numTriangles) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    m_NumTriangles = numTriangles;
}

void Rendering::CollapseRecordImpl ::SetIndices(const std::vector<int>& indices)
{
    RENDERING_CLASS_IS_VALID_9;

    m_Indices = indices;
}

const std::vector<int> Rendering::CollapseRecordImpl ::GetIndices() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return m_Indices;
}

int Rendering::CollapseRecordImpl ::GetIndex(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= index && index < GetIndicesSize(), "À˜“˝¥ÌŒÛ£°");

    return m_Indices.at(index);
}

int Rendering::CollapseRecordImpl ::GetIndicesSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(m_Indices.size());
}

int Rendering::CollapseRecordImpl ::GetVThrow() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return m_VThrow;
}

void Rendering::CollapseRecordImpl ::SetVThrow(int vThrow) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    m_VThrow = vThrow;
}

void Rendering::CollapseRecordImpl ::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.Read(m_VKeep);
    source.Read(m_VThrow);
    source.Read(m_NumVertices);
    source.Read(m_NumTriangles);
    m_Indices = source.ReadVectorWithoutNumber<int>();
}

void Rendering::CollapseRecordImpl ::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Write(m_VKeep);
    target.Write(m_VThrow);
    target.Write(m_NumVertices);
    target.Write(m_NumTriangles);
    target.WriteContainerWithNumber(m_Indices);
}

int Rendering::CollapseRecordImpl ::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CORE_TOOLS_STREAM_SIZE(m_VKeep);
    size += CORE_TOOLS_STREAM_SIZE(m_VThrow);
    size += CORE_TOOLS_STREAM_SIZE(m_NumVertices);
    size += CORE_TOOLS_STREAM_SIZE(m_NumTriangles);
    size += CORE_TOOLS_STREAM_SIZE(m_Indices);

    return size;
}

void Rendering::CollapseRecordImpl ::ClearIndices() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    m_Indices.clear();
}
#include STSTEM_WARNING_POP
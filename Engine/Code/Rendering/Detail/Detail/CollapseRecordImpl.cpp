///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/09 22:06)

#include "Rendering/RenderingExport.h"

#include "CollapseRecordImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

Rendering::CollapseRecordImpl::CollapseRecordImpl(int vKeep, int vThrow, int numVertices, int numTriangles) noexcept
    : recordVKeep{ vKeep }, recordVThrow{ vThrow }, numVertices{ numVertices }, numTriangles{ numTriangles }, indices{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::CollapseRecordImpl::IsValid() const noexcept
{
    if (0 <= numTriangles && 0 <= numVertices)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int Rendering::CollapseRecordImpl::GetVKeep() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return recordVKeep;
}

void Rendering::CollapseRecordImpl::SetVKeep(int vKeep) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    recordVKeep = vKeep;
}

int Rendering::CollapseRecordImpl::GetNumVertices() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return numVertices;
}

void Rendering::CollapseRecordImpl::SetNumVertices(int aNumVertices) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    numVertices = aNumVertices;
}

int Rendering::CollapseRecordImpl::GetNumTriangles() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return numTriangles;
}

void Rendering::CollapseRecordImpl::SetNumTriangles(int aNumTriangles) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    numTriangles = aNumTriangles;
}

void Rendering::CollapseRecordImpl::SetIndices(const std::vector<int>& aIndices)
{
    RENDERING_CLASS_IS_VALID_9;

    indices = aIndices;
}

std::vector<int> Rendering::CollapseRecordImpl::GetIndices() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return indices;
}

int Rendering::CollapseRecordImpl::GetIndex(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= index && index < GetIndicesSize(), "索引错误！");

    return indices.at(index);
}

int Rendering::CollapseRecordImpl::GetIndicesSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(indices.size());
}

int Rendering::CollapseRecordImpl::GetVThrow() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return recordVThrow;
}

void Rendering::CollapseRecordImpl::SetVThrow(int vThrow) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    recordVThrow = vThrow;
}

void Rendering::CollapseRecordImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.Read(recordVKeep);
    source.Read(recordVThrow);
    source.Read(numVertices);
    source.Read(numTriangles);
    indices = source.ReadVectorNotUseNumber<int>();
}

void Rendering::CollapseRecordImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Write(recordVKeep);
    target.Write(recordVThrow);
    target.Write(numVertices);
    target.Write(numTriangles);
    target.WriteContainerWithNumber(indices);
}

int Rendering::CollapseRecordImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CoreTools::GetStreamSize(recordVKeep);
    size += CoreTools::GetStreamSize(recordVThrow);
    size += CoreTools::GetStreamSize(numVertices);
    size += CoreTools::GetStreamSize(numTriangles);
    size += CoreTools::GetStreamSize(indices);

    return size;
}

void Rendering::CollapseRecordImpl::ClearIndices() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    indices.clear();
}

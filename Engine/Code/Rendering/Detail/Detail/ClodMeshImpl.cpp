///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:52)

#include "Rendering/RenderingExport.h"

#include "ClodMeshImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

Rendering::ClodMeshImpl::ClodMeshImpl() noexcept
    : currentRecord{ 0 }, targetRecord{ 0 }, recordArray{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ClodMeshImpl::ClodMeshImpl(const CollapseRecordArraySharedPtr& recordArray) noexcept
    : currentRecord{ 0 }, targetRecord{ 0 }, recordArray{ recordArray }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ClodMeshImpl)

void Rendering::ClodMeshImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.Read(currentRecord);
    source.Read(targetRecord);
    source.ReadObjectAssociated(recordArray);
}

void Rendering::ClodMeshImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Write(currentRecord);
    target.Write(targetRecord);
    target.WriteObjectAssociated(recordArray);
}

int Rendering::ClodMeshImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CoreTools::GetStreamSize(currentRecord);

    size += CoreTools::GetStreamSize(targetRecord);
    size += CoreTools::GetStreamSize(recordArray);

    return size;
}

void Rendering::ClodMeshImpl::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ResolveLink(recordArray);
}

void Rendering::ClodMeshImpl::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Register(recordArray);
}

int Rendering::ClodMeshImpl::GetNumRecords() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return recordArray.object->GetNumRecords();
}

int Rendering::ClodMeshImpl::GetTargetRecord() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return targetRecord;
}

void Rendering::ClodMeshImpl::SetTargetRecord(int aTargetRecord) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    targetRecord = aTargetRecord;
}

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

void Rendering::ClodMeshImpl::SelectLevelOfDetail(VertexBuffer& vertexbuffer, const IndexBufferSharedPtr& indexbuffer, int aTargetRecord)
{
    RENDERING_CLASS_IS_VALID_9;

    // 如果必要的话，塌陷网格。
    const auto bufferChanged = (currentRecord != aTargetRecord);

    while (currentRecord < aTargetRecord)
    {
        ++currentRecord;

        // 更换连接数组中的索引
        auto record = recordArray.object->GetRecord(currentRecord);
        for (auto i = 0; i < record.GetIndicesSize(); ++i)
        {
            const auto recordIndex = record.GetIndex(i);
            indexbuffer->SetPoint(recordIndex, record.GetVKeep());
        }

        // 减少顶点数，顶点正确排序。
        vertexbuffer.SetNumActiveElements(record.GetNumVertices());

        // 减少三角形数量，三角形正确排序。
        indexbuffer->SetNumActiveElements(3 * record.GetNumTriangles());
    }

    // 如果需要的话,扩大网格
    while (targetRecord < currentRecord)
    {
        // 更换连接数组中的索引
        auto record = recordArray.object->GetRecord(currentRecord);
        for (auto i = 0; i < record.GetIndicesSize(); ++i)
        {
            const auto recordIndex = record.GetIndex(i);
            indexbuffer->SetPoint(recordIndex, record.GetVThrow());
        }

        --currentRecord;
        auto prevRecord = recordArray.object->GetRecord(currentRecord);

        // 增加顶点数，顶点正确排序。
        vertexbuffer.SetNumActiveElements(prevRecord.GetNumVertices());

        // 增加三角形数量，三角形正确排序。
        indexbuffer->SetNumActiveElements(3 * prevRecord.GetNumTriangles());
    }

    if (bufferChanged)
    {
        
    }
}

#include SYSTEM_WARNING_POP

CoreTools::ObjectSharedPtr Rendering::ClodMeshImpl::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    return recordArray.object->GetObjectByName(name);
}

std::vector<CoreTools::ObjectSharedPtr> Rendering::ClodMeshImpl::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    return recordArray.object->GetAllObjectsByName(name);
}

CoreTools::ConstObjectSharedPtr Rendering::ClodMeshImpl::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    return recordArray.object->GetConstObjectByName(name);
}

std::vector<CoreTools::ConstObjectSharedPtr> Rendering::ClodMeshImpl::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    return recordArray.object->GetAllConstObjectsByName(name);
}

///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/08 18:44)

#include "Rendering/RenderingExport.h"

#include "ClodMeshImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/Renderers/RendererManager.h"

using std::string;
using std::vector;

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

    auto size = CORE_TOOLS_STREAM_SIZE(currentRecord);

    size += CORE_TOOLS_STREAM_SIZE(targetRecord);
    size += CORE_TOOLS_STREAM_SIZE(recordArray);

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

void Rendering::ClodMeshImpl::SelectLevelOfDetail(VertexBuffer& vertexbuffer, const IndexBufferSharedPtr& indexbuffer, int aTargetRecord)
{
    RENDERING_CLASS_IS_VALID_9;

    // �����Ҫ�Ļ�����������
    const auto bufferChanged = (currentRecord != aTargetRecord);

    while (currentRecord < aTargetRecord)
    {
        ++currentRecord;

        // �������������е�����
        auto record = recordArray.object->GetRecord(currentRecord);
        for (auto i = 0; i < record.GetIndicesSize(); ++i)
        {
            const auto recordIndex = record.GetIndex(i);
            indexbuffer->SetPoint(recordIndex, record.GetVKeep());
        }

        // ���ٶ�������������ȷ����
        vertexbuffer.SetNumActiveElements(record.GetNumVertices());

        // ������������������������ȷ����
        indexbuffer->SetNumActiveElements(3 * record.GetNumTriangles());
    }

    // �����Ҫ�Ļ�,��������
    while (targetRecord < currentRecord)
    {
        // �������������е�����
        auto record = recordArray.object->GetRecord(currentRecord);
        for (auto i = 0; i < record.GetIndicesSize(); ++i)
        {
            const auto recordIndex = record.GetIndex(i);
            indexbuffer->SetPoint(recordIndex, record.GetVThrow());
        }

        --currentRecord;
        auto prevRecord = recordArray.object->GetRecord(currentRecord);

        // ���Ӷ�������������ȷ����
        vertexbuffer.SetNumActiveElements(prevRecord.GetNumVertices());

        // ������������������������ȷ����
        indexbuffer->SetNumActiveElements(3 * prevRecord.GetNumTriangles());
    }

    if (bufferChanged)
    {
        RENDERER_MANAGE_SINGLETON.UpdateAll(indexbuffer);
    }
}

CoreTools::ObjectSharedPtr Rendering::ClodMeshImpl::GetObjectByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    return recordArray.object->GetObjectByName(name);
}

vector<CoreTools::ObjectSharedPtr> Rendering::ClodMeshImpl::GetAllObjectsByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    return recordArray.object->GetAllObjectsByName(name);
}

CoreTools::ConstObjectSharedPtr Rendering::ClodMeshImpl::GetConstObjectByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    return recordArray.object->GetConstObjectByName(name);
}

vector<CoreTools::ConstObjectSharedPtr> Rendering::ClodMeshImpl::GetAllConstObjectsByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    return recordArray.object->GetAllConstObjectsByName(name);
}

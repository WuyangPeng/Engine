// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 10:36)

#include "Rendering/RenderingExport.h"

#include "ClodMeshImpl.h"
#include "Rendering/Renderers/RendererManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"

#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
using std::string;
using std::vector;

Rendering::ClodMeshImpl
	::ClodMeshImpl() noexcept
	:m_CurrentRecord{ 0 }, m_TargetRecord{ 0 }, m_RecordArray{}
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ClodMeshImpl
	::ClodMeshImpl(const CollapseRecordArraySharedPtr& recordArray) noexcept
	:m_CurrentRecord{ 0 }, m_TargetRecord{ 0 }, m_RecordArray{ recordArray }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
} 

CLASS_INVARIANT_STUB_DEFINE(Rendering, ClodMeshImpl)

void Rendering::ClodMeshImpl ::Load(const CoreTools::BufferSourceSharedPtr& source)
{
	RENDERING_CLASS_IS_VALID_9;

	source->Read(m_CurrentRecord);
	source->Read(m_TargetRecord);
	//source.ReadSharedPtr(m_RecordArray);
}

void Rendering::ClodMeshImpl
	::Save(const CoreTools::BufferTargetSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	target->Write(m_CurrentRecord);
	target->Write(m_TargetRecord);
//	target.WriteSharedPtr(m_RecordArray);
}

int Rendering::ClodMeshImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto size = CORE_TOOLS_STREAM_SIZE(m_CurrentRecord);

	size += CORE_TOOLS_STREAM_SIZE(m_TargetRecord);
	size += CORE_TOOLS_STREAM_SIZE(m_RecordArray);

	return size;
}

void Rendering::ClodMeshImpl ::Link(const CoreTools::ObjectLinkSharedPtr& source)
{
	RENDERING_CLASS_IS_VALID_9;
    source;
	//source.ResolveObjectSharedPtrLink(m_RecordArray);
}

void Rendering::ClodMeshImpl ::Register(const CoreTools::ObjectRegisterSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
    target;
	//target.RegisterSharedPtr(m_RecordArray);
}

int Rendering::ClodMeshImpl
	::GetNumRecords() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_RecordArray->GetNumRecords();
}

int Rendering::ClodMeshImpl
	::GetTargetRecord() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_TargetRecord;
}

void Rendering::ClodMeshImpl
	::SetTargetRecord(int targetRecord) noexcept
{
	RENDERING_CLASS_IS_VALID_9;

	m_TargetRecord = targetRecord;
}

void Rendering::ClodMeshImpl
	::SelectLevelOfDetail(VertexBufferSharedPtr vertexbuffer,IndexBufferSharedPtr indexbuffer,int targetRecord)
{
	RENDERING_CLASS_IS_VALID_9; 	

	// 如果必要的话，塌陷网格。
	const auto bufferChanged = (m_CurrentRecord != targetRecord);
 
	while (m_CurrentRecord < targetRecord)
	{
		++m_CurrentRecord;

		// 更换连接数组中的索引
		auto record = m_RecordArray->GetRecord(m_CurrentRecord);
		for (auto i = 0; i < record.GetIndicesSize(); ++i)
		{
			const auto recordIndex = record.GetIndex(i);
			indexbuffer->SetIndexBuffer(recordIndex, record.GetVThrow(), record.GetVKeep());
		}

		// 减少顶点数，顶点正确排序。
		vertexbuffer->SetNumElements(record.GetNumVertices());

		// 减少三角形数量，三角形正确排序。
		indexbuffer->SetNumElements(3 * record.GetNumTriangles());
	}

	// 如果需要的话,扩大网格
	while (targetRecord < m_CurrentRecord)
	{
		// 更换连接数组中的索引
		auto record = m_RecordArray->GetRecord(m_CurrentRecord);
		for (auto i = 0; i < record.GetIndicesSize(); ++i)
		{
			const auto recordIndex = record.GetIndex(i);
			indexbuffer->SetIndexBuffer(recordIndex, record.GetVKeep(), record.GetVThrow());
		}

		--m_CurrentRecord;
		auto prevRecord = m_RecordArray->GetRecord(m_CurrentRecord);

		// 增加顶点数，顶点正确排序。
		vertexbuffer->SetNumElements(prevRecord.GetNumVertices());

		// 增加三角形数量，三角形正确排序。
		indexbuffer->SetNumElements(3 * prevRecord.GetNumTriangles());
	}

	if (bufferChanged)
	{
		RENDERER_MANAGE_SINGLETON.UpdateAll(indexbuffer.get());
	}
}


const CoreTools::ObjectSharedPtr Rendering::ClodMeshImpl
	::GetObjectByName(const string& name)
{
	RENDERING_CLASS_IS_VALID_9;

	return m_RecordArray->GetObjectByName(name);
}

const vector<CoreTools::ObjectSharedPtr> Rendering::ClodMeshImpl
	::GetAllObjectsByName(const string& name)
{
	RENDERING_CLASS_IS_VALID_9;

	return m_RecordArray->GetAllObjectsByName(name);
}

const CoreTools::ConstObjectSharedPtr Rendering::ClodMeshImpl
	::GetConstObjectByName(const string& name) const
{
	RENDERING_CLASS_IS_VALID_9;

	return m_RecordArray->GetConstObjectByName(name);
}

const vector<CoreTools::ConstObjectSharedPtr> Rendering::ClodMeshImpl
	::GetAllConstObjectsByName(const string& name) const
{ 
	RENDERING_CLASS_IS_VALID_9;

	return m_RecordArray->GetAllConstObjectsByName(name);
}
#include STSTEM_WARNING_POP
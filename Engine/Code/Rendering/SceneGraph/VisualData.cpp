// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 18:44)

#include "Rendering/RenderingExport.h"

#include "VisualData.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Rendering/Shaders/VisualEffectInstance.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"

#include "CoreTools/Helper/ExceptionMacro.h" 
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;
using std::vector;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
Rendering::VisualData
	::VisualData(VisualPrimitiveType type)
	:m_Type{ type }, m_VertexFormat{}, m_VertexBuffer{}, m_IndexBuffer{}
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisualData
	::VisualData(VisualPrimitiveType type,const VertexFormatSharedPtr& vertexformat, const VertexBufferSharedPtr& vertexbuffer,const IndexBufferSharedPtr& indexbuffer)
	:m_Type{ type },m_VertexFormat{ vertexformat },m_VertexBuffer{ vertexbuffer },m_IndexBuffer{ indexbuffer }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VisualData)

void Rendering::VisualData
	::SetPrimitiveType(VisualPrimitiveType type) 
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	m_Type = type;
}

Rendering::VisualPrimitiveType
    Rendering::VisualData::GetPrimitiveType() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Type;
}

Rendering::ConstVertexFormatSharedPtr 
	Rendering::VisualData::GetConstVertexFormat() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_VertexFormat;
}

const char* Rendering::VisualData
	::GetVertexBufferReadOnlyData() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_VertexBuffer->GetReadOnlyData();
}

int Rendering::VisualData
	::GetPositionOffset() const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;

const	auto positionIndex = m_VertexFormat->GetIndex(VertexFormatFlags::AttributeUsage::Position);
	if (positionIndex == -1)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("更新需要顶点位置\n"s));	
	}

const auto positionType = m_VertexFormat->GetAttributeType(positionIndex);
	if (positionType != VertexFormatFlags::AttributeType::Float3 && positionType != VertexFormatFlags::AttributeType::Float4)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("顶点必须是3元组或4元组\n"s));		 
	}
 
	return m_VertexFormat->GetOffset(positionIndex);
}

int Rendering::VisualData
	::GetVertexFormatStride() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_VertexFormat->GetStride();
}

int Rendering::VisualData
	::GetVertexBufferNumElements() const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_VertexBuffer->GetNumElements();
}

bool Rendering::VisualData
	::IsVertexSharedPtrValid() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	if (!(!m_VertexBuffer || !m_VertexFormat ))
	{
		return true;
	}
	else
	{
		return false;
	}
} 

Rendering::IndexBufferSharedPtr Rendering::VisualData
	::GetIndexBuffer()
{
	RENDERING_CLASS_IS_VALID_9;

	return m_IndexBuffer;
}

Rendering::VertexBufferSharedPtr Rendering::VisualData
	::GetVertexBuffer()
{
	RENDERING_CLASS_IS_VALID_9;

	return m_VertexBuffer;
}


Rendering::ConstIndexBufferSharedPtr Rendering::VisualData
	::GetConstIndexBuffer() const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_IndexBuffer;
}

void Rendering::VisualData
	::SetIndexBuffer(const IndexBufferSharedPtr& indexbuffer)
{
	RENDERING_CLASS_IS_VALID_9;

	m_IndexBuffer = indexbuffer;
}

Rendering::ConstVertexBufferSharedPtr Rendering::VisualData
	::GetConstVertexBuffer() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_VertexBuffer;

}

void Rendering::VisualData
	::SetVertexBuffer(const VertexBufferSharedPtr& vertexbuffer) 
{
	RENDERING_CLASS_IS_VALID_9;

	m_VertexBuffer = vertexbuffer;
}

Rendering::VertexFormatSharedPtr Rendering::VisualData
	::GetVertexFormat() 
{
	RENDERING_CLASS_IS_VALID_9;

	return m_VertexFormat;
}

void Rendering::VisualData
	::SetVertexFormat(const VertexFormatSharedPtr& vertexformat)
{
	RENDERING_CLASS_IS_VALID_9;

	m_VertexFormat = vertexformat;
}
 
void Rendering::VisualData ::Load(const CoreTools::BufferSourceSharedPtr& source)
{
	RENDERING_CLASS_IS_VALID_9;

	source->ReadEnum(m_Type);
	//source.ReadSharedPtr(m_VertexFormat);
	//source.ReadSharedPtr(m_VertexBuffer);
	//source.ReadSharedPtr(m_IndexBuffer);	
}

void Rendering::VisualData
	::Save(const CoreTools::BufferTargetSharedPtr& target) const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	target->WriteEnum(m_Type);
	//target.WriteSharedPtr(m_VertexFormat);
	//target.WriteSharedPtr(m_VertexBuffer);
	//target.WriteSharedPtr(m_IndexBuffer);	
}

int Rendering::VisualData
	::GetStreamingSize() const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	int size = CORE_TOOLS_STREAM_SIZE(m_Type);

	size += CORE_TOOLS_STREAM_SIZE(m_VertexFormat);
	size += CORE_TOOLS_STREAM_SIZE(m_VertexBuffer);
	size += CORE_TOOLS_STREAM_SIZE(m_IndexBuffer);

	return size;
}

void Rendering::VisualData ::Register(const CoreTools::ObjectRegisterSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
    target;
	//target.RegisterSharedPtr(m_VertexFormat);
	//target.RegisterSharedPtr(m_VertexBuffer);
	//target.RegisterSharedPtr(m_IndexBuffer);
}


void Rendering::VisualData ::Link(const CoreTools::ObjectLinkSharedPtr& source)
{
	RENDERING_CLASS_IS_VALID_9;	
	source;
	//source.ResolveObjectSharedPtrLink(m_VertexFormat);
	//source.ResolveObjectSharedPtrLink(m_VertexBuffer);
	//source.ResolveObjectSharedPtrLink(m_IndexBuffer);	
}


const CoreTools::ObjectSharedPtr Rendering::VisualData
	::GetObjectByName(const string& name) 
{
	RENDERING_CLASS_IS_VALID_9;

	auto object = m_VertexFormat->GetObjectByName(name);
	if (object != nullptr)
		return object;

	object = m_VertexBuffer->GetObjectByName(name);
	if (object != nullptr)
		return object;

	object = m_IndexBuffer->GetObjectByName(name);
	if (object != nullptr)
		return object;
	else
		return CoreTools::ObjectSharedPtr();
}

const vector<CoreTools::ObjectSharedPtr> Rendering::VisualData
	::GetAllObjectsByName(const string& name)
{
	RENDERING_CLASS_IS_VALID_9;

	auto vertexFormatObjects = m_VertexFormat->GetAllObjectsByName(name);
	auto vertexBufferObjects = m_VertexBuffer->GetAllObjectsByName(name);
	auto indexBufferObjects = m_IndexBuffer->GetAllObjectsByName(name);

	vector<CoreTools::ObjectSharedPtr> entirelyObjects;

	entirelyObjects.insert(entirelyObjects.end(),vertexFormatObjects.begin(),vertexFormatObjects.end());
	
	entirelyObjects.insert(entirelyObjects.end(),vertexBufferObjects.begin(),vertexBufferObjects.end());

	entirelyObjects.insert(entirelyObjects.end(),indexBufferObjects.begin(), indexBufferObjects.end());

	return entirelyObjects;
}

const CoreTools::ConstObjectSharedPtr Rendering::VisualData
	::GetConstObjectByName(const string& name)  const
{
	RENDERING_CLASS_IS_VALID_9;

	auto object = m_VertexFormat->GetConstObjectByName(name);
	if (object != nullptr)
		return object;

	object = m_VertexBuffer->GetConstObjectByName(name);
	if (object != nullptr)
		return object;

	object = m_IndexBuffer->GetConstObjectByName(name);
	if (object != nullptr)
		return object;
	else
		return CoreTools::ConstObjectSharedPtr();
}

const vector<CoreTools::ConstObjectSharedPtr> Rendering::VisualData
	::GetAllConstObjectsByName(const string& name) const
{
	RENDERING_CLASS_IS_VALID_9;

	auto vertexFormatObjects = m_VertexFormat->GetAllConstObjectsByName(name);
	auto vertexBufferObjects = m_VertexBuffer->GetAllConstObjectsByName(name);
	auto indexBufferObjects = m_IndexBuffer->GetAllConstObjectsByName(name);

	vector<CoreTools::ConstObjectSharedPtr> entirelyObjects;

	entirelyObjects.insert(entirelyObjects.end(),vertexFormatObjects.begin(), vertexFormatObjects.end());
	
	entirelyObjects.insert(entirelyObjects.end(),vertexBufferObjects.begin(),vertexBufferObjects.end());

	entirelyObjects.insert(entirelyObjects.end(),indexBufferObjects.begin(),indexBufferObjects.end());

	return entirelyObjects;
}
#include STSTEM_WARNING_POP
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
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h" 
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;
using std::vector;

Rendering::VisualData
	::VisualData(VisualPrimitiveType type)
	:m_Type{ type }, m_VertexFormat{}, m_VertexBuffer{}, m_IndexBuffer{}
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisualData
	::VisualData(VisualPrimitiveType type,const VertexFormatSmartPointer& vertexformat, const VertexBufferSmartPointer& vertexbuffer,const IndexBufferSmartPointer& indexbuffer)
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

Rendering::ConstVertexFormatSmartPointer 
	Rendering::VisualData::GetConstVertexFormat() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_VertexFormat.GetConstSmartPointer();
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

	auto positionIndex = m_VertexFormat->GetIndex(VertexFormatFlags::AttributeUsage::Position);
	if (positionIndex == -1)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("更新需要顶点位置\n"));	
	}

	auto positionType = m_VertexFormat->GetAttributeType(positionIndex);
	if (positionType != VertexFormatFlags::AttributeType::Float3 && positionType != VertexFormatFlags::AttributeType::Float4)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("顶点必须是3元组或4元组\n"));		 
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
	::IsVertexSmartPointerValid() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	if (!(m_VertexBuffer.IsNullPtr() || m_VertexFormat.IsNullPtr()))
	{
		return true;
	}
	else
	{
		return false;
	}
} 

Rendering::IndexBufferSmartPointer Rendering::VisualData
	::GetIndexBuffer()
{
	RENDERING_CLASS_IS_VALID_9;

	return m_IndexBuffer;
}

Rendering::VertexBufferSmartPointer Rendering::VisualData
	::GetVertexBuffer()
{
	RENDERING_CLASS_IS_VALID_9;

	return m_VertexBuffer;
}


Rendering::ConstIndexBufferSmartPointer Rendering::VisualData
	::GetConstIndexBuffer() const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_IndexBuffer.GetConstSmartPointer();
}

void Rendering::VisualData
	::SetIndexBuffer(const IndexBufferSmartPointer& indexbuffer)
{
	RENDERING_CLASS_IS_VALID_9;

	m_IndexBuffer = indexbuffer;
}

Rendering::ConstVertexBufferSmartPointer Rendering::VisualData
	::GetConstVertexBuffer() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_VertexBuffer.GetConstSmartPointer();

}

void Rendering::VisualData
	::SetVertexBuffer(const VertexBufferSmartPointer& vertexbuffer) 
{
	RENDERING_CLASS_IS_VALID_9;

	m_VertexBuffer = vertexbuffer;
}

Rendering::VertexFormatSmartPointer Rendering::VisualData
	::GetVertexFormat() 
{
	RENDERING_CLASS_IS_VALID_9;

	return m_VertexFormat;
}

void Rendering::VisualData
	::SetVertexFormat(const VertexFormatSmartPointer& vertexformat)
{
	RENDERING_CLASS_IS_VALID_9;

	m_VertexFormat = vertexformat;
}
 
void Rendering::VisualData
	::Load(BufferSource& source)
{
	RENDERING_CLASS_IS_VALID_9;

	source.ReadEnum(m_Type);
	source.ReadSmartPointer(m_VertexFormat);
	source.ReadSmartPointer(m_VertexBuffer);
	source.ReadSmartPointer(m_IndexBuffer);	
}

void Rendering::VisualData
	::Save(BufferTarget& target) const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	target.WriteEnum(m_Type);
	target.WriteSmartPointer(m_VertexFormat);
	target.WriteSmartPointer(m_VertexBuffer);
	target.WriteSmartPointer(m_IndexBuffer);	
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

void Rendering::VisualData
	::Register(ObjectRegister& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	target.RegisterSmartPointer(m_VertexFormat);
	target.RegisterSmartPointer(m_VertexBuffer);
	target.RegisterSmartPointer(m_IndexBuffer);
}


void Rendering::VisualData
	::Link(ObjectLink& source)
{
	RENDERING_CLASS_IS_VALID_9;	

	source.ResolveObjectSmartPointerLink(m_VertexFormat);
	source.ResolveObjectSmartPointerLink(m_VertexBuffer);
	source.ResolveObjectSmartPointerLink(m_IndexBuffer);	
}


const CoreTools::ObjectSmartPointer Rendering::VisualData
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
		return CoreTools::ObjectSmartPointer();
}

const vector<CoreTools::ObjectSmartPointer> Rendering::VisualData
	::GetAllObjectsByName(const string& name)
{
	RENDERING_CLASS_IS_VALID_9;

	auto vertexFormatObjects = m_VertexFormat->GetAllObjectsByName(name);
	auto vertexBufferObjects = m_VertexBuffer->GetAllObjectsByName(name);
	auto indexBufferObjects = m_IndexBuffer->GetAllObjectsByName(name);

	vector<CoreTools::ObjectSmartPointer> entirelyObjects;

	entirelyObjects.insert(entirelyObjects.end(),vertexFormatObjects.begin(),vertexFormatObjects.end());
	
	entirelyObjects.insert(entirelyObjects.end(),vertexBufferObjects.begin(),vertexBufferObjects.end());

	entirelyObjects.insert(entirelyObjects.end(),indexBufferObjects.begin(), indexBufferObjects.end());

	return entirelyObjects;
}

const CoreTools::ConstObjectSmartPointer Rendering::VisualData
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
		return CoreTools::ConstObjectSmartPointer();
}

const vector<CoreTools::ConstObjectSmartPointer> Rendering::VisualData
	::GetAllConstObjectsByName(const string& name) const
{
	RENDERING_CLASS_IS_VALID_9;

	auto vertexFormatObjects = m_VertexFormat->GetAllConstObjectsByName(name);
	auto vertexBufferObjects = m_VertexBuffer->GetAllConstObjectsByName(name);
	auto indexBufferObjects = m_IndexBuffer->GetAllConstObjectsByName(name);

	vector<CoreTools::ConstObjectSmartPointer> entirelyObjects;

	entirelyObjects.insert(entirelyObjects.end(),vertexFormatObjects.begin(), vertexFormatObjects.end());
	
	entirelyObjects.insert(entirelyObjects.end(),vertexBufferObjects.begin(),vertexBufferObjects.end());

	entirelyObjects.insert(entirelyObjects.end(),indexBufferObjects.begin(),indexBufferObjects.end());

	return entirelyObjects;
}
// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 15:11)

#include "Rendering/RenderingExport.h"

#include "VertexFormatImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectInterface.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h" 
#include "CoreTools/Contract/Noexcept.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(6385)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(6386)
int Rendering::VertexFormatImpl
	::sm_ComponentSize[System::EnumCastUnderlying(VertexFormatFlags::AttributeType::Quantity)] 
{
	0,  // AttributeType::None
	4,  // AttributeType::Float1
	4,  // AttributeType::Float2
	4,  // AttributeType::Float3
	4,  // AttributeType::Float4
	2,  // AttributeType::Half1
	2,  // AttributeType::Half2
	2,  // AttributeType::Half3
	2,  // AttributeType::Half4
	1,  // AttributeType::UByte4
	2,  // AttributeType::Short1
	2,  // AttributeType::Short2
	2   // AttributeType::Short3
};

int Rendering::VertexFormatImpl
	::sm_NumComponents[System::EnumCastUnderlying(VertexFormatFlags::AttributeType::Quantity)] 
{
	0,  // AttributeType::None
	1,  // AttributeType::Float1
	2,  // AttributeType::Float2
	3,  // AttributeType::Float3
	4,  // AttributeType::Float4
	1,  // AttributeType::Half1
	2,  // AttributeType::Half2
	3,  // AttributeType::Half3
	4,  // AttributeType::Half4
	4,  // AttributeType::UByte4
	1,  // AttributeType::Short1
	2,  // AttributeType::Short2
	4   // AttributeType::Short3
};

int Rendering::VertexFormatImpl
	::sm_TypeSize[System::EnumCastUnderlying(VertexFormatFlags::AttributeType::Quantity)] 
{
	0,  // AttributeType::None
	4,  // AttributeType::Float1
	8,  // AttributeType::Float2
	12, // AttributeType::Float3
	16, // AttributeType::Float4
	2,  // AttributeType::Half1
	4,  // AttributeType::Half2
	6,  // AttributeType::Half3
	8,  // AttributeType::Half4
	4,  // AttributeType::UByte4
	2,  // AttributeType::Short1
	4,  // AttributeType::Short2
	8   // AttributeType::Short3
};

Rendering::VertexFormatImpl
	::VertexFormatImpl( int numAttributes )
	:m_NumAttributes{ numAttributes }, m_Stride{ 0 }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::VertexFormatImpl
	::IsValid() const noexcept
{
	if(0 < m_NumAttributes && m_NumAttributes <= System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::Attributes) &&  0 <= m_Stride)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT	

void Rendering::VertexFormatImpl
	::SetAttribute( int attribute, unsigned int streamIndex, unsigned int offset, AttributeType type, AttributeUsage usage, unsigned int usageIndex )
{
	RENDERING_CLASS_IS_VALID_1;

	SetAttribute(attribute, streamIndex, offset, VertexFormatType{ type, usage, usageIndex });
}

void Rendering::VertexFormatImpl
    ::SetAttribute(int attribute, unsigned int streamIndex,unsigned int offset,const VertexFormatType& vertexFormatType) 
{
	RENDERING_CLASS_IS_VALID_1;

	SetAttribute(attribute, VertexFormatElement{ streamIndex, offset, vertexFormatType });
}

void Rendering::VertexFormatImpl
	::SetAttribute(int attribute, const VertexFormatElement& vertexFormatElement)
{
    RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= attribute && attribute < m_NumAttributes,"无效索引在SetAttribute\n");

	if (0 < attribute)
	{
		RENDERING_ASSERTION_1(m_Elements[attribute - 1].GetOffset() < vertexFormatElement.GetOffset(),"偏移量必须比属性索引高。\n");
	}
	else
	{
		RENDERING_ASSERTION_1(vertexFormatElement.GetOffset() == 0, "第一个属性的偏移量必须为零。\n");
	}

	m_Elements[attribute] = vertexFormatElement;
}

void Rendering::VertexFormatImpl
	::SetStride( int stride )
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_1(0 < stride, "Stride必须是正数。\n");
        CoreTools::DisableNoexcept();
	m_Stride = stride;
}

int Rendering::VertexFormatImpl
	::GetNumAttributes() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_NumAttributes;
}

unsigned int Rendering::VertexFormatImpl
	::GetStreamIndex( int attribute ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= attribute && attribute < m_NumAttributes,"无效索引在GetStreamIndex\n");

	return m_Elements[attribute].GetStreamIndex();
}

unsigned int Rendering::VertexFormatImpl
	::GetOffset( int attribute ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= attribute && attribute < m_NumAttributes,"无效索引在GetStreamIndex\n");

	return m_Elements[attribute].GetOffset();
}

Rendering::VertexFormatFlags::AttributeType Rendering::VertexFormatImpl
	::GetAttributeType( int attribute ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= attribute && attribute < m_NumAttributes,"无效索引在GetStreamIndex\n");

	return m_Elements[attribute].GetType();
}

Rendering::VertexFormatFlags::AttributeUsage Rendering::VertexFormatImpl
	::GetAttributeUsage( int attribute ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= attribute && attribute < m_NumAttributes,"无效索引在GetStreamIndex\n");

	return m_Elements[attribute].GetUsage();
}

unsigned int Rendering::VertexFormatImpl
	::GetUsageIndex( int attribute ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= attribute && attribute < m_NumAttributes,"无效索引在GetStreamIndex\n");

	return m_Elements[attribute].GetUsageIndex();
}

int Rendering::VertexFormatImpl
	::GetStride() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Stride;
}

int Rendering::VertexFormatImpl ::GetIndex(AttributeUsage usage, unsigned int usageIndex) const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	for (auto index = 0; index < m_NumAttributes; ++index)
	{
		if (m_Elements[index].GetUsage() == usage && m_Elements[index].GetUsageIndex() == usageIndex)
		{
			return index;
		}
	}

	return -1;
}

int Rendering::VertexFormatImpl
	::GetComponentSize( AttributeType type ) noexcept
{
	return sm_ComponentSize[System::EnumCastUnderlying(type)];
}

int Rendering::VertexFormatImpl
	::GetNumComponents( AttributeType type ) noexcept
{
	 return sm_NumComponents[System::EnumCastUnderlying(type)];
}

int Rendering::VertexFormatImpl
	::GetTypeSize( AttributeType type ) noexcept
{
	return sm_TypeSize[System::EnumCastUnderlying(type)];
}

int Rendering::VertexFormatImpl ::GetStreamingSize() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto size = CORE_TOOLS_STREAM_SIZE(m_NumAttributes);

	for (auto i = 0; i < System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::Attributes); ++i)
	{
		size += m_Elements[i].GetStreamingSize();		
	}

	size += CORE_TOOLS_STREAM_SIZE(m_Stride);

	return size;
}

void Rendering::VertexFormatImpl
	::Save(const CoreTools::BufferTargetSharedPtr& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	target->Write(m_NumAttributes);

	for (auto i = 0; i < System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::Attributes); ++i)
	{
		m_Elements[i].Save(target);
	}

	target->Write(m_Stride);
}

void Rendering::VertexFormatImpl
	::Load(const CoreTools::BufferSourceSharedPtr& source )
{
	RENDERING_CLASS_IS_VALID_1;

	source->Read(m_NumAttributes);

	for (auto i = 0; i < System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::Attributes); ++i)
	{
		m_Elements[i].Load(source);
	}

	source->Read(m_Stride);
}

void Rendering::VertexFormatImpl
	::SaveToFile( WriteFileManager& outFile ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	outFile.Write(sizeof(int),&m_NumAttributes);	

	for (auto i = 0; i < m_NumAttributes; ++i)
	{
		m_Elements[i].SaveToFile(outFile);
	}

	outFile.Write(sizeof(int),&m_Stride);
}

void Rendering::VertexFormatImpl
	::ReadFromFile( ReadFileManager& inFile )
{
	RENDERING_CLASS_IS_VALID_1;

	// m_NumAttributes已在LoadFromFile读取。
	// inFile.Read(sizeof(int),&m_NumAttributes);

	for (auto i = 0; i < m_NumAttributes; ++i)
	{
		m_Elements[i].ReadFromFile(inFile);
	}

	inFile.Read(sizeof(int),&m_Stride);
}


#include STSTEM_WARNING_POP

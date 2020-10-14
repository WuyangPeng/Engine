// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 14:06)

#include "Rendering/RenderingExport.h"

#include "BufferImpl.h"
#include "BufferParameter.h"
#include "CoreTools/DataTypes/TupleDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"


#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Noexcept.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26451)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
#include SYSTEM_WARNING_DISABLE(26492)
Rendering::BufferImpl
	::BufferImpl() noexcept
	:m_NumElements{ 0 }, m_ElementSize{ 0 }, m_Usage{ BufferUsage::Quantity }, m_Data{}
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::BufferImpl
	::BufferImpl(int numElements, int elementSize, BufferUsage usage)
	:m_NumElements{ numElements }, m_ElementSize{ elementSize }, m_Usage{ usage }, m_Data(m_NumElements * m_ElementSize)
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::BufferImpl
	::IsValid() const noexcept
{
	if(0 <= m_NumElements && 0 <= m_ElementSize && m_NumElements * m_ElementSize <= static_cast<int>(m_Data.size()))
	    return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

int Rendering::BufferImpl ::GetNumElements() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_NumElements;
}

int Rendering::BufferImpl
	::GetElementSize() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_ElementSize;
}

Rendering::BufferUsage Rendering::BufferImpl ::GetUsage() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Usage;
}

void Rendering::BufferImpl
	::SetNumElements( int numElements )
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_1(numElements <= boost::numeric_cast<int>(m_Data.size()) / m_ElementSize, "设置的长度溢出！");

	CoreTools::DisableNoexcept();

	m_NumElements = numElements;
}

int Rendering::BufferImpl
	::GetNumBytes() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return boost::numeric_cast<int>(m_Data.size());
}

const char* Rendering::BufferImpl ::GetReadOnlyData() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return &m_Data[0];
}

const char* Rendering::BufferImpl
	::GetReadOnlyData(int index) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	if (0 <= index && index < GetNumBytes())
	{
		return &m_Data[index];
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("索引越界！"s));
	}
}

void Rendering::BufferImpl
	::Load( const CoreTools::BufferSourceSharedPtr& source )
{
	RENDERING_CLASS_IS_VALID_1;

	source->Read(m_NumElements);
	source->Read(m_ElementSize);
	source->ReadEnum(m_Usage);

	auto size = 0;
	source->Read(size);
	m_Data.resize(size);

	source->Read(boost::numeric_cast<int>(m_Data.size()), &m_Data[0]);
}

void Rendering::BufferImpl
	::Save( const CoreTools::BufferTargetSharedPtr& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	target->Write(m_NumElements);
	target->Write(m_ElementSize);
        target->WriteEnum(m_Usage);
        target->WriteContainerWithNumber(m_Data);
}

int Rendering::BufferImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto size = CORE_TOOLS_STREAM_SIZE(m_NumElements);

	size += CORE_TOOLS_STREAM_SIZE(m_ElementSize);
	size += CORE_TOOLS_STREAM_SIZE(m_Usage);
	auto numBytes = boost::numeric_cast<int>(m_Data.size());
	size += CORE_TOOLS_STREAM_SIZE(numBytes);
	size += numBytes * CORE_TOOLS_STREAM_SIZE(m_Data[0]);

	return size;
}

void Rendering::BufferImpl
    ::SaveBufferDataToFile(WriteFileManager& outFile) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	SaveHeadToFile(outFile);

	const auto numBytes = GetNumBytes();
	outFile.Write(sizeof(int), &numBytes);
	 
	outFile.Write(m_ElementSize, numBytes / m_ElementSize, &m_Data[0]);
}

void Rendering::BufferImpl
	::SaveBufferDataToFile(WriteFileManager& outFile,const ConstVertexFormatSharedPtr& vertexformat) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	const auto stride = vertexformat->GetStride();

	RENDERING_ASSERTION_1(stride == GetElementSize(), "格式步进值和顶点大小必须匹配。\n");

	// 建立一个顶点缓冲属性的表。
	// 每个属性都有一个偏移量,属性组件的大小,和组件大小的数量
	// 例如,属性使用偏移量0和类型AT_FLOAT3为(offset,size,numComponents) = (0,4,3)。
	BufferParameter table[System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::Attributes)];
	const auto numAttributes = vertexformat->GetNumAttributes();
	for (auto attributesIndex = 0; attributesIndex < numAttributes; ++attributesIndex)
    {
            const auto type = vertexformat->GetAttributeType(attributesIndex);
        const auto offset = vertexformat->GetOffset(attributesIndex);
            const auto componentSize = VertexFormat::GetComponentSize(type);
        const auto numComponents = VertexFormat::GetNumComponents(type);

		table[attributesIndex].Set(offset, componentSize, numComponents);
    }

 	// 一次写入顶点，允许字节交换(字节顺序)。
	const auto numElements = GetNumElements();
	auto vertexIndex = 0;
	for (auto i = 0; i < numElements; ++i)
    {
		for (auto attributesIndex = 0; attributesIndex < numAttributes; ++attributesIndex)
        {
			outFile.Write(table[attributesIndex].GetComponentSize(), table[attributesIndex].GetNumComponents(), &m_Data[vertexIndex + table[attributesIndex].GetOffset()]);
        }

		vertexIndex += stride;
    }
}

void Rendering::BufferImpl
	::SaveHeadToFile(WriteFileManager& outFile) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	outFile.Write(sizeof(int), &m_NumElements);
	outFile.Write(sizeof(int), &m_ElementSize);
	outFile.Write(sizeof(int), &m_Usage);
}

void Rendering::BufferImpl
    ::ReadBufferDataFromFile(ReadFileManager& inFile)
{
	RENDERING_CLASS_IS_VALID_1;

	inFile.Read(sizeof(int), &m_NumElements);

	if (m_NumElements != 0)
	{
		inFile.Read(sizeof(int), &m_ElementSize);
		inFile.Read(sizeof(int), &m_Usage);

		auto numBytes = 0;
		inFile.Read(sizeof(int), &numBytes);
		m_Data.resize(numBytes);

		inFile.Read(m_ElementSize, numBytes / m_ElementSize, &m_Data[0]);
	}	
}

void Rendering::BufferImpl
	::ReadBufferDataFromFile(ReadFileManager& inFile, const ConstVertexFormatSharedPtr& vertexformat)
{
	RENDERING_CLASS_IS_VALID_1;

	const auto stride = vertexformat->GetStride();

	RENDERING_ASSERTION_1(stride == GetElementSize(), "格式步进值和顶点大小必须匹配。\n");

	// 建立一个顶点缓冲属性的表。
	// 每个属性都有一个偏移量,属性组件的大小,和组件大小的数量
	// 例如,属性使用偏移量0和类型AT_FLOAT3为(offset,size,numComponents) = (0,4,3)。
	BufferParameter table[System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::Attributes)];
	const auto numAttributes = vertexformat->GetNumAttributes();
	for (auto attributesIndex = 0; attributesIndex < numAttributes; ++attributesIndex)
    {
            const auto type = vertexformat->GetAttributeType(attributesIndex);
        const auto offset = vertexformat->GetOffset(attributesIndex);
            const auto componentSize = VertexFormat::GetComponentSize(type);
        const auto numComponents = VertexFormat::GetNumComponents(type);

		table[attributesIndex].Set(offset, componentSize, numComponents);
    }


	// 一次读取顶点，允许字节交换(字节顺序)。
	const auto numElements = GetNumElements();
	auto vertexIndex = 0;
	for (auto i = 0; i < numElements; ++i, vertexIndex += stride)
	{
		for (auto attributesIndex = 0; attributesIndex < numAttributes; ++attributesIndex)
		{
			inFile.Read(table[attributesIndex].GetComponentSize(), table[attributesIndex].GetNumComponents(), &m_Data[vertexIndex + table[attributesIndex].GetOffset()]);
		}
	}
}

void Rendering::BufferImpl
	::ReadHeadFromFile(ReadFileManager& inFile) 
{
	RENDERING_CLASS_IS_VALID_1;

	inFile.Read(sizeof(int), &m_NumElements);
	inFile.Read(sizeof(int), &m_ElementSize);
	inFile.Read(sizeof(int), &m_Usage);

	m_Data.resize(m_NumElements * m_ElementSize);
}

char* Rendering::BufferImpl
	::GetAccessWriteData(int index)
{
	RENDERING_CLASS_IS_VALID_1;

	return const_cast<char*>(GetReadOnlyData(index));
}

void Rendering::BufferImpl
	::SetNewData(const std::vector<char>& newData)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_2(m_Data.size() == newData.size(), "数据大小不相等\n");

	m_Data = newData;
}

#include STSTEM_WARNING_POP
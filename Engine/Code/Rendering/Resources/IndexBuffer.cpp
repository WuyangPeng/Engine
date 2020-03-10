// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 15:25)

#include "Rendering/RenderingExport.h"

#include "IndexBuffer.h"
#include "System/Helper/UnusedMacro.h"
#include "Rendering/Renderers/RendererManager.h" 
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/BufferSource.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/FileManager/ReadFileManager.h"

using std::vector;

CORE_TOOLS_RTTI_DEFINE(Rendering,IndexBuffer);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering,IndexBuffer);
CORE_TOOLS_FACTORY_DEFINE(Rendering,IndexBuffer); 

Rendering::IndexBuffer
	::IndexBuffer()
	:ParentType{}, m_Offset{ 0 }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::IndexBuffer
	::IndexBuffer( int numIndices, int indexSize,BufferUsage usage )
	:ParentType{ numIndices,indexSize,usage }, m_Offset{ 0 }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::IndexBuffer
	::~IndexBuffer ()
{
	RENDERER_MANAGE_SINGLETON.UnbindAll(this); 

	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering,IndexBuffer)
	
void Rendering::IndexBuffer
    ::SetOffset( int offset )
{
	RENDERING_CLASS_IS_VALID_1;

	m_Offset = offset;
}

int Rendering::IndexBuffer
	::GetOffset() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Offset;
}

Rendering::IndexBuffer
	::IndexBuffer (LoadConstructor value)
	:ParentType{ value }, m_Offset{ 0 }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::IndexBuffer
	::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto size = ParentType::GetStreamingSize();

	size += CORE_TOOLS_STREAM_SIZE(m_Offset);

	return size;
}

uint64_t Rendering::IndexBuffer
	::Register( CoreTools::ObjectRegister& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ParentType::Register(target);
}

void Rendering::IndexBuffer
	::Save (CoreTools::BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

	ParentType::Save(target);
	
	target.Write(m_Offset);

	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::IndexBuffer
	::Link (CoreTools::ObjectLink& source)
{	
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::Link(source);
}

void Rendering::IndexBuffer
	::PostLink ()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::PostLink();
}

void Rendering::IndexBuffer
	::Load (CoreTools::BufferSource& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);
	
	source.Read(m_Offset);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::IndexBuffer
	::SaveToFile(WriteFileManager& outFile) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	ParentType::SaveBufferDataToFile(outFile);

	outFile.Write(sizeof(int), &m_Offset);
}

void Rendering::IndexBuffer
	::ReadFromFile(ReadFileManager& inFile)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::ReadBufferDataFromFile(inFile);

	if (GetNumElements() != 0)
	{
		inFile.Read(sizeof(int), &m_Offset);
	}		
}

Rendering::IndexBufferSmartPointer Rendering::IndexBuffer
	::Clone() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return IndexBufferSmartPointer(NEW0 ClassType(*this));
}

void Rendering::IndexBuffer
	::InitIndexBuffer()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	auto indexSize = GetElementSize();

	RENDERING_ASSERTION_1(indexSize == 2 || indexSize == 4, "索引大小只能为2或4。");

	auto numVertices = GetNumElements();

	if (indexSize == 2)
	{
		auto indices = reinterpret_cast<short*>(GetAccessWriteData(0));
		for (auto i = 0; i < numVertices; ++i)
		{
			indices[i] = static_cast<short>(i);
		}
	}
	else // indexSize == 4
	{
		auto indices = reinterpret_cast<int*>(GetAccessWriteData(0));
		for (auto i = 0; i < numVertices; ++i)
		{
			indices[i] = i;
		}
	}
}

void Rendering::IndexBuffer
	::InitIndexBuffer(const vector<int> indices) 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	auto indexSize = GetElementSize();

	RENDERING_ASSERTION_1(indexSize == 2 || indexSize == 4, "索引大小只能为2或4。");

	auto numVertices = boost::numeric_cast<size_t>(GetNumElements());

	RENDERING_ASSERTION_1(numVertices == indices.size(), "索引数不对应。");

	if (indexSize == 2)
	{
		auto accessWriteData = reinterpret_cast<short*>(GetAccessWriteData(0));
		for (auto i = 0u; i < numVertices; ++i)
		{
			accessWriteData[i] = static_cast<short>(indices[i]);
		}
	}
	else // indexSize == 4
	{
		auto accessWriteData = reinterpret_cast<int*>(GetAccessWriteData(0));
		for (auto i = 0u; i < numVertices; ++i)
		{
			accessWriteData[i] = indices[i];
		}
	}
}

void Rendering::IndexBuffer
	::InitIndexBufferInParticles() 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	auto indexSize = GetElementSize();

	RENDERING_ASSERTION_1(indexSize == 2 || indexSize == 4, "索引大小只能为2或4。");

	auto numVertices = GetNumElements();
	auto numParticles = numVertices / 6;

	if (indexSize == 2)
	{
		auto indices = reinterpret_cast<short*>(GetAccessWriteData(0));
		for (short i = 0; i < numParticles; ++i)
		{
			indices[i * 6] = 4 * i;
			indices[i * 6 + 1] = 4 * i + 1;
			indices[i * 6 + 2] = 4 * i + 2;
			indices[i * 6 + 3] = 4 * i;
			indices[i * 6 + 4] = 4 * i + 2;
			indices[i * 6 + 5] = 4 * i + 3;	
		}
	}
	else // indexSize == 4
	{
		auto indices = reinterpret_cast<int*>(GetAccessWriteData(0));
		for (auto i = 0; i < numParticles; ++i)
		{
			indices[i * 6] = 4 * i;
			indices[i * 6 + 1] = 4 * i + 1;
			indices[i * 6 + 2] = 4 * i + 2;
			indices[i * 6 + 3] = 4 * i;
			indices[i * 6 + 4] = 4 * i + 2;
			indices[i * 6 + 5] = 4 * i + 3;
		}
	} 
}

void Rendering::IndexBuffer
	::InitIndexBufferInRectangle(int index, int firstRectangleIndex, int secondRectangleIndex,  int thirdRectangleIndex, int fourthRectangleIndex) 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	auto indexSize = GetElementSize();

	RENDERING_ASSERTION_1(indexSize == 2 || indexSize == 4, "索引大小只能为2或4。");

	auto numVertices = GetNumElements();
	auto numRectangles = numVertices / 6;

	if (0 <= index && index < numRectangles)
	{
		if (indexSize == 2)
		{
			auto indices = reinterpret_cast<short*>(GetAccessWriteData(0));

			indices[index * 6] = static_cast<short>(firstRectangleIndex);
			indices[index * 6 + 1] = static_cast<short>(secondRectangleIndex);
			indices[index * 6 + 2] = static_cast<short>(thirdRectangleIndex);
			indices[index * 6 + 3] = static_cast<short>(firstRectangleIndex);
			indices[index * 6 + 4] = static_cast<short>(thirdRectangleIndex);
			indices[index * 6 + 5] = static_cast<short>(fourthRectangleIndex);
		}
		else // indexSize == 4
		{
			auto indices = reinterpret_cast<int*>(GetAccessWriteData(0));

			indices[index * 6] = firstRectangleIndex;
			indices[index * 6 + 1] = secondRectangleIndex;
			indices[index * 6 + 2] = thirdRectangleIndex;
			indices[index * 6 + 3] = firstRectangleIndex;
			indices[index * 6 + 4] = thirdRectangleIndex;
			indices[index * 6 + 5] = fourthRectangleIndex;
		}
	}	
}

void Rendering::IndexBuffer
	::InitIndexBufferInDisk(int radialSamplesMinus1, int shellSamplesMinus1)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	auto indexSize = GetElementSize();

	RENDERING_ASSERTION_1(indexSize == 2 || indexSize == 4, "索引大小只能为2或4。");

	if (indexSize == 2)
	{
		auto indices = reinterpret_cast<short*>(GetAccessWriteData(0));

		auto firstIndex = radialSamplesMinus1;
	
		for (auto secondIndex = 0; secondIndex <= radialSamplesMinus1; ++secondIndex)
		{
			indices[0] = 0;
			indices[1] = static_cast<short>(1 + shellSamplesMinus1 * firstIndex);
			indices[2] = static_cast<short>(1 + shellSamplesMinus1 * secondIndex);
			indices += 3;
		
			for (auto shellIndex = 1; shellIndex < shellSamplesMinus1; ++shellIndex)
			{
				auto index00 = static_cast<short>(shellIndex + shellSamplesMinus1 * firstIndex);
				auto index01 = static_cast<short>(shellIndex + shellSamplesMinus1 * secondIndex);
				short index10 = index00 + 1;
				short index11 = index01 + 1;

				indices[0] = index00;
				indices[1] = index10;
				indices[2] = index11;
				indices[3] = index00;
				indices[4] = index11;
				indices[5] = index01;
			
				indices += 6;
			}

			firstIndex = secondIndex;
		}

	}
	else // indexSize == 4
	{
		auto indices = reinterpret_cast<int*>(GetAccessWriteData(0));

		auto firstIndex = radialSamplesMinus1;
	
		for (auto secondIndex = 0; secondIndex <= radialSamplesMinus1; ++secondIndex)
		{
			indices[0] = 0;
			indices[1] = 1 + shellSamplesMinus1 * firstIndex;
			indices[2] = 1 + shellSamplesMinus1 * secondIndex;
			indices += 3;
		
			for (auto shellIndex = 1; shellIndex < shellSamplesMinus1; ++shellIndex)
			{
				auto index00 = shellIndex + shellSamplesMinus1 * firstIndex;
				auto index01 = shellIndex + shellSamplesMinus1 * secondIndex;
				auto index10 = index00 + 1;
				auto index11 = index01 + 1;

				indices[0] = index00;
				indices[1] = index10;
				indices[2] = index11;
				indices[3] = index00;
				indices[4] = index11;
				indices[5] = index01;
			
				indices += 6;
			}

			firstIndex = secondIndex;
		}
	} 
}

void Rendering::IndexBuffer
	::SetIndexBuffer(int index, int original, int current)
{
    RENDERING_CLASS_IS_VALID_1;

	auto accessWriteData = reinterpret_cast<int*>(GetAccessWriteData(0));

	RENDERING_ASSERTION_2(accessWriteData[index] == original, "原来的索引错误\n");

	SYSTEM_UNUSED_ARG(original);

	accessWriteData[index] = current;
}

 
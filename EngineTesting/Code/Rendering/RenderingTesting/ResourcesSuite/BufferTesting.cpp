// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/03 17:27)

#include "BufferTesting.h"
#include "Rendering/Resources/IndexBuffer.h"
#include "Rendering/Resources/VertexBuffer.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/VertexFormatElement.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/FileManager/FileManagerHelper.h"

#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"






using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, BufferTesting) 

void Rendering::BufferTesting
	::MainTest()
{ 
	CoreTools::InitTerm::ExecuteInitializers();

	RendererManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(VertexBufferTest);
	ASSERT_NOT_THROW_EXCEPTION_0(IndexBufferTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
	ASSERT_NOT_THROW_EXCEPTION_0(FileTest);

	RendererManager::Destroy();

	CoreTools::InitTerm::ExecuteTerminators();
}
 
void Rendering::BufferTesting
	::VertexBufferTest()
{
	VertexBuffer firstVertexBuffer;

	ASSERT_EQUAL(firstVertexBuffer.GetNumElements(), 0);
	ASSERT_EQUAL(firstVertexBuffer.GetElementSize(), 0);
	ASSERT_ENUM_EQUAL(firstVertexBuffer.GetUsage(), BufferUsage::Quantity);
	ASSERT_EQUAL(firstVertexBuffer.GetNumBytes(), 0);

	VertexBuffer secondVertexBuffer(7, 8, BufferUsage::Dynamic);

	ASSERT_EQUAL(secondVertexBuffer.GetNumElements(), 7);
	ASSERT_EQUAL(secondVertexBuffer.GetElementSize(), 8);
	ASSERT_ENUM_EQUAL(secondVertexBuffer.GetUsage(), BufferUsage::Dynamic);
	ASSERT_EQUAL(secondVertexBuffer.GetNumBytes(), 56);

	secondVertexBuffer.SetNumElements(4);

	ASSERT_EQUAL(secondVertexBuffer.GetNumElements(), 4);
	ASSERT_EQUAL(secondVertexBuffer.GetElementSize(), 8);
	ASSERT_ENUM_EQUAL(secondVertexBuffer.GetUsage(), BufferUsage::Dynamic);
	ASSERT_EQUAL(secondVertexBuffer.GetNumBytes(), 56);

	ASSERT_UNEQUAL_NULL_PTR(secondVertexBuffer.GetReadOnlyData());
}

void Rendering::BufferTesting
	::IndexBufferTest()
{
	IndexBuffer firstIndexBuffer;

	ASSERT_EQUAL(firstIndexBuffer.GetNumElements(), 0);
	ASSERT_EQUAL(firstIndexBuffer.GetElementSize(), 0);
	ASSERT_ENUM_EQUAL(firstIndexBuffer.GetUsage(), BufferUsage::Quantity);
	ASSERT_EQUAL(firstIndexBuffer.GetNumBytes(), 0);
	ASSERT_EQUAL(firstIndexBuffer.GetOffset(), 0);

	IndexBuffer secondIndexBuffer(7, 8, BufferUsage::Dynamic);

	ASSERT_EQUAL(secondIndexBuffer.GetNumElements(), 7);
	ASSERT_EQUAL(secondIndexBuffer.GetElementSize(), 8);
	ASSERT_ENUM_EQUAL(secondIndexBuffer.GetUsage(), BufferUsage::Dynamic);
	ASSERT_EQUAL(secondIndexBuffer.GetNumBytes(), 56);
	ASSERT_EQUAL(secondIndexBuffer.GetOffset(), 0);

	secondIndexBuffer.SetNumElements(4);

	ASSERT_EQUAL(secondIndexBuffer.GetNumElements(), 4);
	ASSERT_EQUAL(secondIndexBuffer.GetElementSize(), 8);
	ASSERT_ENUM_EQUAL(secondIndexBuffer.GetUsage(), BufferUsage::Dynamic);
	ASSERT_EQUAL(secondIndexBuffer.GetNumBytes(), 56);
	ASSERT_EQUAL(secondIndexBuffer.GetOffset(), 0);

	secondIndexBuffer.SetOffset(4);

	ASSERT_EQUAL(secondIndexBuffer.GetNumElements(), 4);
	ASSERT_EQUAL(secondIndexBuffer.GetElementSize(), 8);
	ASSERT_ENUM_EQUAL(secondIndexBuffer.GetUsage(), BufferUsage::Dynamic);
	ASSERT_EQUAL(secondIndexBuffer.GetNumBytes(), 56);
	ASSERT_EQUAL(secondIndexBuffer.GetOffset(), 4);

	ASSERT_UNEQUAL_NULL_PTR(secondIndexBuffer.GetReadOnlyData());
} 

void Rendering::BufferTesting
	::StreamTest()
{
// 	vector<VertexFormatElement> firstVertexFormatElement { VertexFormatElement(0,0,VertexFormatType(VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::Position, 0)) };
// 
// 	VertexFormatSharedPtr firstVertexFormat = VertexFormat::Create(firstVertexFormatElement);
// 
// 	CoreTools::ReadFileManager vertexManage(SYSTEM_TEXT("Resource/ResourcesSuite/Buffer.vb"));
// 	CoreTools::ReadFileManager indexManage(SYSTEM_TEXT("Resource/ResourcesSuite/Buffer.ib"));
// 
// 	CoreTools::OutTopLevel outTopLevel;
// 	CoreTools::ObjectInterfaceSharedPtr firstBuffer(new VertexBuffer);
// 
// 	outTopLevel.Insert(firstBuffer);
// 
// 	VertexBuffer* secondBuffer = CoreTools::PolymorphicCast<VertexBuffer>(firstBuffer.GetData());
// 	secondBuffer->ReadFromFile(vertexManage, firstVertexFormat.PolymorphicDowncastConstObjectSharedPtr<ConstVertexFormatSharedPtr>());
// 
// 	CoreTools::ObjectInterfaceSharedPtr thirdBuffer(new IndexBuffer);
// 
// 	outTopLevel.Insert(thirdBuffer);
// 
// 	IndexBuffer* fourthBuffer = CoreTools::PolymorphicCast<IndexBuffer>(thirdBuffer.GetData());
// 	fourthBuffer->ReadFromFile(indexManage);
// 
// 	CoreTools::BufferOutStream outStream(outTopLevel);
// 
// 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr = outStream.GetBufferOutStreamInformation();
//         
// 	CoreTools::BufferInStream inStream(fileBufferPtr);
//         
// 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
// 
// 	VertexBufferSharedPtr fifthBuffer = inTopLevel[0].PolymorphicDowncastObjectSharedPtr<VertexBufferSharedPtr>();
// 
// 	IndexBufferSharedPtr sixthBuffer = inTopLevel[1].PolymorphicDowncastObjectSharedPtr<IndexBufferSharedPtr>();
// 
// 	ASSERT_EQUAL(fifthBuffer->GetNumElements(), secondBuffer->GetNumElements());
// 	ASSERT_EQUAL(fifthBuffer->GetElementSize(), secondBuffer->GetElementSize());
// 	ASSERT_ENUM_EQUAL(fifthBuffer->GetUsage(), secondBuffer->GetUsage());
// 	ASSERT_EQUAL(fifthBuffer->GetNumBytes(), secondBuffer->GetNumBytes());
// 
// 	ASSERT_EQUAL(sixthBuffer->GetNumElements(), fourthBuffer->GetNumElements());
// 	ASSERT_EQUAL(sixthBuffer->GetElementSize(), fourthBuffer->GetElementSize());
// 	ASSERT_ENUM_EQUAL(sixthBuffer->GetUsage(), fourthBuffer->GetUsage());
// 	ASSERT_EQUAL(sixthBuffer->GetNumBytes(), fourthBuffer->GetNumBytes());
// 	ASSERT_EQUAL(sixthBuffer->GetOffset(), fourthBuffer->GetOffset());
// 
// 	for (int i = 0; i < fifthBuffer->GetNumElements() * fifthBuffer->GetElementSize(); ++i)
// 	{
// 		ASSERT_EQUAL(fifthBuffer->GetReadOnlyData()[i], secondBuffer->GetReadOnlyData()[i]);		
// 	}
// 
// 	for (int i = 0; i < sixthBuffer->GetNumElements() * sixthBuffer->GetElementSize(); ++i)
// 	{
// 		ASSERT_EQUAL(sixthBuffer->GetReadOnlyData()[i], fourthBuffer->GetReadOnlyData()[i]);
// 	}	
// 
// 	CoreTools::WriteFileManager writeVertexManage(SYSTEM_TEXT("Resource/ResourcesSuite/WriteBuffer.vb"));
// 	CoreTools::WriteFileManager writeIndexManage(SYSTEM_TEXT("Resource/ResourcesSuite/WriteBuffer.ib"));
// 
// 	fifthBuffer->SaveToFile(writeVertexManage, firstVertexFormat.PolymorphicDowncastConstObjectSharedPtr<ConstVertexFormatSharedPtr>());
	//sixthBuffer->SaveToFile(writeIndexManage);
}

void Rendering::BufferTesting
	::FileTest()
{
// 	CoreTools::FileBuffer firstFileBuffer = CoreTools::FileManagerHelper::LoadFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/Buffer.vb"), true);
// 	CoreTools::FileBuffer secondFileBuffer = CoreTools::FileManagerHelper::LoadFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/Buffer.ib"), true);
// 	CoreTools::FileBuffer thirdFileBuffer = CoreTools::FileManagerHelper::LoadFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/WriteBuffer.vb"), true);
// 	CoreTools::FileBuffer fourthFileBuffer = CoreTools::FileManagerHelper::LoadFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/WriteBuffer.ib"), true);
// 
// 	ASSERT_EQUAL(firstFileBuffer.GetSize(), thirdFileBuffer.GetSize());
// 	ASSERT_EQUAL(secondFileBuffer.GetSize(), fourthFileBuffer.GetSize());
// 
// 	for (size_t i = 0; i < firstFileBuffer.GetSize(); ++i)
// 	{
// 		ASSERT_EQUAL(firstFileBuffer.GetBufferBegin()[i], thirdFileBuffer.GetBufferBegin()[i]);
// 	}
// 
// 	for (size_t i = 0; i < secondFileBuffer.GetSize(); ++i)
// 	{
// 		ASSERT_EQUAL(secondFileBuffer.GetBufferBegin()[i], fourthFileBuffer.GetBufferBegin()[i]);
// 	}
}

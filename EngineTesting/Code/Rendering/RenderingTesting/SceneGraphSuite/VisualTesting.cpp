// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.3 (2019/09/05 11:53)

#include "VisualTesting.h"
#include "VisualTest.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/FileManager/ReadFileManager.h"

#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"

#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Rendering/SceneGraph/SaveVisual.h"
#include "Rendering/SceneGraph/LoadVisual.h"

#include <vector>

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, VisualTesting) 
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26496)
void Rendering::VisualTesting
	::MainTest()
{
	CoreTools::InitTerm::ExecuteInitializers();

	CameraManager::Create();
	RendererManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
	ASSERT_NOT_THROW_EXCEPTION_0(TransformTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
	ASSERT_NOT_THROW_EXCEPTION_0(FileTest);
	
	RendererManager::Destroy();
	CameraManager::Destroy();

	CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::VisualTesting
	::InitTest()
{
// 	VisualTest firstVisualTest;
// 
// 	ASSERT_EQUAL(firstVisualTest.GetNumControllers(),0);	
// 
// 	ControllerInterfaceSharedPtr controllerTest(new VisualTest);	
// 	firstVisualTest.AttachController(controllerTest);
// 
// 	ASSERT_EQUAL(firstVisualTest.GetNumControllers(),1);
// 	ASSERT_EQUAL(firstVisualTest.GetController(0), controllerTest);
// 
// 	ControllerInterfaceSharedPtr secondVisualTest(new VisualTest);
// 
// 	ASSERT_EQUAL_NULL_PTR(secondVisualTest->GetControllerObject());
// 
// 	firstVisualTest.AttachController(secondVisualTest);
// 
// 	VisualTest* ptr = CoreTools::StaticCast<VisualTest>(secondVisualTest.GetData());
// 
// 	ASSERT_EQUAL(secondVisualTest->GetControllerObject(),
// 	             &firstVisualTest);
// 	ASSERT_EQUAL_NULL_PTR(ptr->GetParent());
// 	
// 	ASSERT_EQUAL(firstVisualTest.GetNumControllers(),2);
// 	ASSERT_EQUAL(firstVisualTest.GetController(0), controllerTest);
// 	ASSERT_EQUAL(firstVisualTest.GetController(1), secondVisualTest);
// 
// 	firstVisualTest.DetachController(controllerTest);
// 
// 	ASSERT_EQUAL(firstVisualTest.GetNumControllers(),1);
// 	ASSERT_EQUAL(firstVisualTest.GetController(0), secondVisualTest);
// 
// 	firstVisualTest.DetachAllControllers();
// 
// 	ASSERT_EQUAL(firstVisualTest.GetNumControllers(),0);
// 
// 	// VisualTest测试
// 	VisualTest thirdVisualTest(VisualPrimitiveType::Polypoint);
// 	
// 	ASSERT_ENUM_EQUAL(thirdVisualTest.GetPrimitiveType(),VisualPrimitiveType::Polypoint);
// 
// 	ASSERT_TRUE(thirdVisualTest.GetConstVertexFormat().IsNullPtr());
// 	ASSERT_TRUE(thirdVisualTest.GetVertexFormat().IsNullPtr());
// 
// 	ASSERT_TRUE(thirdVisualTest.GetConstVertexBuffer().IsNullPtr());
// 	ASSERT_TRUE(thirdVisualTest.GetVertexBuffer().IsNullPtr());
// 
// 	ASSERT_TRUE(thirdVisualTest.GetConstIndexBuffer().IsNullPtr());
// 	ASSERT_TRUE(thirdVisualTest.GetIndexBuffer().IsNullPtr());
// 
// 	ASSERT_TRUE(thirdVisualTest.GetEffectInstance().IsNullPtr());
// 
// 	vector<VertexFormatType> vertexFormatType{ VertexFormatType(VertexFormatFlags::AttributeType::Float3,
// 										 VertexFormatFlags::AttributeUsage::Position,0) };
// 
// 	VertexFormatSharedPtr firstVertexformat 
// 		= VertexFormat::Create(vertexFormatType);
// 	VertexBufferSharedPtr firstVertexbuffer(new VertexBuffer);
// 	IndexBufferSharedPtr firstIndexbuffer(new IndexBuffer);
// 
// 	CoreTools::ReadFileManager vertexManage(SYSTEM_TEXT("Resource/ResourcesSuite/Buffer.vb"));
// 	CoreTools::ReadFileManager indexManage(SYSTEM_TEXT("Resource/ResourcesSuite/Buffer.ib"));
// 
// 	firstVertexbuffer->ReadFromFile(vertexManage, firstVertexformat.PolymorphicDowncastConstObjectSharedPtr<ConstVertexFormatSharedPtr>());
// 	firstIndexbuffer->ReadFromFile(indexManage);
// 
// 	VisualTest fourthVisualTest(VisualPrimitiveType::TriangleFan,firstVertexformat,
// 		                        firstVertexbuffer,firstIndexbuffer);
// 
// 	ASSERT_ENUM_EQUAL(fourthVisualTest.GetPrimitiveType(),VisualPrimitiveType::TriangleFan);
// 
// 	ASSERT_EQUAL(fourthVisualTest.GetConstVertexFormat(),firstVertexformat);
// 	ASSERT_EQUAL(fourthVisualTest.GetVertexFormat(),firstVertexformat);
// 
// 	ASSERT_EQUAL(fourthVisualTest.GetConstVertexBuffer(),firstVertexbuffer);
// 	ASSERT_EQUAL(fourthVisualTest.GetVertexBuffer(),firstVertexbuffer);
// 
// 	ASSERT_EQUAL(fourthVisualTest.GetConstIndexBuffer(),firstIndexbuffer);
// 	ASSERT_EQUAL(fourthVisualTest.GetIndexBuffer(),firstIndexbuffer);
// 
// 	ASSERT_TRUE(fourthVisualTest.GetEffectInstance().IsNullPtr());
// 
// 	VertexFormatSharedPtr secondVertexformat 
// 		= firstVertexformat->Clone();
// 	VertexBufferSharedPtr secondVertexbuffer(new VertexBuffer);
// 	IndexBufferSharedPtr secondIndexbuffer(new IndexBuffer);
// 
// 	thirdVisualTest.SetVertexFormat(secondVertexformat);
// 	ASSERT_EQUAL(thirdVisualTest.GetConstVertexFormat(),secondVertexformat);
// 	ASSERT_EQUAL(thirdVisualTest.GetVertexFormat(),secondVertexformat);
// 
// 	thirdVisualTest.SetVertexBuffer(secondVertexbuffer);
// 	ASSERT_EQUAL(thirdVisualTest.GetConstVertexBuffer(),secondVertexbuffer);
// 	ASSERT_EQUAL(thirdVisualTest.GetVertexBuffer(),secondVertexbuffer);
// 
// 	thirdVisualTest.SetIndexBuffer(secondIndexbuffer);
// 	ASSERT_EQUAL(thirdVisualTest.GetConstIndexBuffer(),secondIndexbuffer);
// 	ASSERT_EQUAL(thirdVisualTest.GetIndexBuffer(),secondIndexbuffer);
// 
// 	ASSERT_TRUE(thirdVisualTest.GetEffectInstance().IsNullPtr());
}

void Rendering::VisualTesting
	::CopyTest()
{
// 	VisualTest firstVisualTest;
// 
// 	ASSERT_EQUAL(firstVisualTest.GetNumControllers(),0);
// 
// 	ControllerInterfaceSharedPtr controllerTest(new VisualTest);
// 
// 	ControllerInterfaceSharedPtr secondVisualTest(new VisualTest);
// 	VisualTest* firstPtr = CoreTools::StaticCast<VisualTest>(secondVisualTest.GetData());
// 
// 	ASSERT_EQUAL_NULL_PTR(secondVisualTest->GetControllerObject());
// 
// 	secondVisualTest->AttachController(controllerTest);
// 
// 	firstVisualTest.AttachController(secondVisualTest);
// 
// 	Transform firstTransform;
// 
// 	firstTransform.SetUniformScale(5.0f);
// 	firstPtr->SetLocalTransform(firstTransform);
//  
//  	ControllerInterfaceSharedPtr thirdVisualTest(secondVisualTest->Clone());
// 	VisualTest* secondPtr = CoreTools::StaticCast<VisualTest>(thirdVisualTest.GetData());
// 
// 	Transform secondTransform;
// 	secondTransform.SetUniformScale(3.0f);
// 	secondPtr->SetLocalTransform(secondTransform);
// 
// 	ASSERT_APPROXIMATE(secondPtr->GetLocalTransform().GetUniformScale (),
// 		               3.0f,1e-8f);
// 	ASSERT_APPROXIMATE(firstPtr->GetLocalTransform().GetUniformScale (),
// 		               5.0f,1e-8f);
// 
// 	firstVisualTest.AttachController(thirdVisualTest);
// 
// 	ASSERT_EQUAL(firstVisualTest.GetNumControllers(),2);
// 	ASSERT_EQUAL(firstVisualTest.GetController(0), secondVisualTest); 
// 	ASSERT_EQUAL(firstVisualTest.GetController(1), thirdVisualTest);
// 
// 	secondVisualTest->DetachController(controllerTest);
// 
// 	thirdVisualTest->AttachController(controllerTest);
// 
// 	ASSERT_EQUAL(secondVisualTest->GetNumControllers(),0);
// 
// 	// thirdVisualTest已经复制了一个VisualTest
// 	ASSERT_EQUAL(thirdVisualTest->GetNumControllers(),2); 
// 
// 	// VisualTest测试
// 	vector<VertexFormatType> vertexFormatType{ VertexFormatType(VertexFormatFlags::AttributeType::Float3,
// 										 VertexFormatFlags::AttributeUsage::Position,0) };
// 
// 	VertexFormatSharedPtr firstVertexformat 
// 		= VertexFormat::Create(vertexFormatType);
// 	VertexBufferSharedPtr firstVertexbuffer(new VertexBuffer);
// 	IndexBufferSharedPtr firstIndexbuffer(new IndexBuffer);
// 
// 	CoreTools::ReadFileManager vertexManage(SYSTEM_TEXT("Resource/ResourcesSuite/Buffer.vb"));
// 	CoreTools::ReadFileManager indexManage(SYSTEM_TEXT("Resource/ResourcesSuite/Buffer.ib"));
// 
// 	firstVertexbuffer->ReadFromFile(vertexManage, firstVertexformat.PolymorphicDowncastConstObjectSharedPtr<ConstVertexFormatSharedPtr>());
// 	firstIndexbuffer->ReadFromFile(indexManage);
// 
// 	VisualTest fourthVisualTest(VisualPrimitiveType::TriangleFan,firstVertexformat,
// 		                        firstVertexbuffer,firstIndexbuffer);
// 
// 	VisualTestSharedPtr fifthVisualTest = fourthVisualTest.Clone().PolymorphicDowncastObjectSharedPtr<VisualTestSharedPtr>();
// 
// 	ASSERT_UNEQUAL(fourthVisualTest.GetConstVertexFormat(), fifthVisualTest->GetConstVertexFormat());
// 	ASSERT_UNEQUAL(fourthVisualTest.GetVertexFormat(), fifthVisualTest->GetVertexFormat());
// 	ASSERT_UNEQUAL(fourthVisualTest.GetConstVertexBuffer(), fifthVisualTest->GetConstVertexBuffer());
// 	ASSERT_UNEQUAL(fourthVisualTest.GetVertexBuffer(), fifthVisualTest->GetVertexBuffer());
// 	ASSERT_UNEQUAL(fourthVisualTest.GetConstIndexBuffer(), fifthVisualTest->GetConstIndexBuffer());
// 	ASSERT_UNEQUAL(fourthVisualTest.GetIndexBuffer(), fifthVisualTest->GetIndexBuffer());
}

void Rendering::VisualTesting
	::TransformTest()
{
// 	VisualTest firstVisualTest;
// 	ControllerInterfaceSharedPtr secondSpatialTest(new VisualTest);
// 	firstVisualTest.AttachController(secondSpatialTest);
// 
// 	VisualTest* firstPtr = CoreTools::StaticCast<VisualTest>(secondSpatialTest.GetData());
// 
// 	Transform firstTransform;
// 	firstTransform.SetUniformScale(5.0f);
// 
// 	Transform secondTransform;
// 	secondTransform.SetTranslate(Transform::APoint(5.0f,3.0f,5.6f));
// 
// 	firstVisualTest.SetLocalTransform(firstTransform);
// 	firstPtr->SetLocalTransform(secondTransform);
// 	firstPtr->SetParent(&firstVisualTest);
// 
// 	firstVisualTest.Update();
// 
// 	ASSERT_TRUE(Approximate(firstVisualTest.GetLocalTransform(),
// 	                        firstTransform,1e-8f));
// 	ASSERT_TRUE(Approximate(firstPtr->GetLocalTransform(),
// 	                        secondTransform,1e-8f));
// 
// 	ASSERT_TRUE(Approximate(firstVisualTest.GetWorldTransform(),
// 	                        firstTransform,1e-8f));
// 	ASSERT_TRUE(Approximate(firstPtr->GetWorldTransform(),
// 	                        firstTransform * secondTransform,1e-8f));
// 
// 	// VisualTest测试
// 	vector<VertexFormatType> vertexFormatType{ VertexFormatType(VertexFormatFlags::AttributeType::Float3,
// 										 VertexFormatFlags::AttributeUsage::Position, 0) };
// 
// 	VertexFormatSharedPtr firstVertexformat 
// 		= VertexFormat::Create(vertexFormatType);
// 	VertexBufferSharedPtr firstVertexbuffer(new VertexBuffer);
// 	IndexBufferSharedPtr firstIndexbuffer(new IndexBuffer);
// 
// 	CoreTools::ReadFileManager vertexManage(SYSTEM_TEXT("Resource/ResourcesSuite/Buffer.vb"));
// 	CoreTools::ReadFileManager indexManage(SYSTEM_TEXT("Resource/ResourcesSuite/Buffer.ib"));
// 
// 	firstVertexbuffer->ReadFromFile(vertexManage, firstVertexformat.PolymorphicDowncastConstObjectSharedPtr<ConstVertexFormatSharedPtr>());
// 	firstIndexbuffer->ReadFromFile(indexManage);
// 
// 	VisualTest secondVisualTest(VisualPrimitiveType::TriangleFan,firstVertexformat,
// 		                        firstVertexbuffer,firstIndexbuffer);
// 
// 	int numVertices = firstVertexbuffer->GetNumElements();
// 	int stride = firstVertexformat->GetStride();
// 
// 	int positionIndex = firstVertexformat->GetIndex(VertexFormatFlags::AttributeUsage::Position);
// 
// 	const char* data = firstVertexbuffer->GetReadOnlyData();
// 	int positionOffset = firstVertexformat->GetOffset(positionIndex);
// 
// 	Bound modelBound;
// 	modelBound.ComputeFromData(numVertices, stride, data + positionOffset);
// 
// 	Bound worldBound = modelBound.TransformBy(firstVisualTest.GetWorldTransform());
//   
// 	secondVisualTest.Update();
// 	
// 	ASSERT_TRUE(Approximate(secondVisualTest.GetModelBound(),
// 	                        worldBound,1e-8f));

}

void Rendering::VisualTesting
	::StreamTest()
{
// 	vector<VertexFormatType> vertexFormatType{ VertexFormatType(VertexFormatFlags::AttributeType::Float3,
// 										 VertexFormatFlags::AttributeUsage::Position,0) };
// 
// 	VertexFormatSharedPtr firstVertexformat 
// 		= VertexFormat::Create(vertexFormatType);
// 	VertexBufferSharedPtr firstVertexbuffer(new VertexBuffer);
// 	IndexBufferSharedPtr firstIndexbuffer(new IndexBuffer);
// 
// 	CoreTools::ReadFileManager vertexManage(SYSTEM_TEXT("Resource/ResourcesSuite/Buffer.vb"));
// 	CoreTools::ReadFileManager indexManage(SYSTEM_TEXT("Resource/ResourcesSuite/Buffer.ib"));
// 
// 	firstVertexbuffer->ReadFromFile(vertexManage, firstVertexformat.PolymorphicDowncastConstObjectSharedPtr<ConstVertexFormatSharedPtr>());
// 	firstIndexbuffer->ReadFromFile(indexManage);
//  
// 	CoreTools::OutTopLevel outTopLevel;
// 	CoreTools::ObjectInterfaceSharedPtr firstVisualTest(new VisualTest(VisualPrimitiveType::TriangleFan, firstVertexformat,
// 		                                                           firstVertexbuffer, firstIndexbuffer));
// 
// 	firstVisualTest->SetUniqueID(5);
// 
// 	outTopLevel.Insert(firstVisualTest);
// 
// 	VisualTest* secondVisualTest =
// 		CoreTools::PolymorphicCast<VisualTest>(firstVisualTest.GetData());
// 
// 	Transform firstTransform;
// 	Transform secondTransform;
// 	Bound firstBound(Bound::APoint(0.2f,5.0f,3.0f),2.0f);	
// 
// 	firstTransform.SetUniformScale(5.0f);
// 	secondTransform.SetUniformScale(3.0f);
// 
// 	secondVisualTest->SetLocalTransform(firstTransform);
// 	secondVisualTest->SetWorldTransform(secondTransform);
// 	secondVisualTest->SetWorldBound(firstBound);
// 	secondVisualTest->SetCullingMode(CullingMode::Always);
// 
// 	ControllerInterfaceSharedPtr thirdVisualTest(new VisualTest);
// 	secondVisualTest->AttachController(thirdVisualTest);
// 
// 	thirdVisualTest->SetUniqueID(4);
// 
// 	ControllerInterfaceSharedPtr fourthVisualTest(new VisualTest);
// 	secondVisualTest->AttachController(fourthVisualTest);
// 
// 	fourthVisualTest->SetUniqueID(3);
// 
// 	ControllerInterfaceSharedPtr fifthVisualTest(new VisualTest);
// 	secondVisualTest->AttachController(fifthVisualTest);
// 
// 	fifthVisualTest->SetUniqueID(2);
// 
// 	ControllerInterfaceSharedPtr sixthVisualTest(new VisualTest);
// 	fifthVisualTest->AttachController(sixthVisualTest);
// 
// 	sixthVisualTest->SetUniqueID(1);
// 
// 	CoreTools::BufferOutStream outStream(outTopLevel);
// 
// 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr =
// 		    outStream.GetBufferOutStreamInformation();
//         
// 	CoreTools::BufferInStream inStream(fileBufferPtr);
//         
// 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
// 
// 	VisualTestSharedPtr  seventhVisualTest =
// 		inTopLevel[0].PolymorphicDowncastObjectSharedPtr<VisualTestSharedPtr>();
// 
// 	ASSERT_EQUAL(seventhVisualTest->GetNumControllers(), 3);
// 
// 	ASSERT_TRUE(Approximate(seventhVisualTest->GetLocalTransform(),
// 	                        firstTransform,1e-8f));
// 	ASSERT_TRUE(Approximate(seventhVisualTest->GetWorldTransform(),
// 	                        secondTransform,1e-8f));
// 	ASSERT_TRUE(Approximate(seventhVisualTest->GetWorldBound(), firstBound, 1e-8f));
// 	ASSERT_ENUM_EQUAL(seventhVisualTest->GetCullingMode(), CullingMode::Always);
// 
// 	VisualTest* eighthVisualTest =
// 		CoreTools::DynamicCast<VisualTest>(seventhVisualTest->GetController(0).GetData());
// 
// 	ASSERT_UNEQUAL_NULL_PTR(eighthVisualTest);
// 
// 	VisualTest* ninthVisualTest =
// 		CoreTools::DynamicCast<VisualTest>(seventhVisualTest->GetController(1).GetData());
// 
// 	ASSERT_UNEQUAL_NULL_PTR(ninthVisualTest);
// 
// 	VisualTest* tenthVisualTest =
// 		CoreTools::DynamicCast<VisualTest>
// 		(seventhVisualTest->GetController(2).GetData());
// 
// 	ASSERT_UNEQUAL_NULL_PTR(tenthVisualTest);
// 
// 	ASSERT_EQUAL(tenthVisualTest->GetNumControllers(), 1);
// 
// 	VisualTest* eleventhVisualTest =
// 		CoreTools::DynamicCast<VisualTest>
// 		(tenthVisualTest->GetController(0).GetData());
// 
// 	ASSERT_UNEQUAL_NULL_PTR(eleventhVisualTest);
// 
// 	// VisualTest测试
// 	ASSERT_ENUM_EQUAL(secondVisualTest->GetPrimitiveType(), seventhVisualTest->GetPrimitiveType());
// 
// 	VertexBufferSharedPtr firstBuffer = secondVisualTest->GetVertexBuffer();
// 	VertexBufferSharedPtr secondBuffer = seventhVisualTest->GetVertexBuffer();
// 
// 	IndexBufferSharedPtr thirdBuffer = secondVisualTest->GetIndexBuffer();
// 	IndexBufferSharedPtr fourthBuffer = seventhVisualTest->GetIndexBuffer();
// 
// 	ASSERT_EQUAL(firstBuffer->GetNumElements(), secondBuffer->GetNumElements());
// 	ASSERT_EQUAL(firstBuffer->GetElementSize(), secondBuffer->GetElementSize());
// 	ASSERT_ENUM_EQUAL(firstBuffer->GetUsage(), secondBuffer->GetUsage());
// 	ASSERT_EQUAL(firstBuffer->GetNumBytes(), secondBuffer->GetNumBytes());
// 
// 	ASSERT_EQUAL(thirdBuffer->GetNumElements(), fourthBuffer->GetNumElements());
// 	ASSERT_EQUAL(thirdBuffer->GetElementSize(), fourthBuffer->GetElementSize());
// 	ASSERT_ENUM_EQUAL(thirdBuffer->GetUsage(), fourthBuffer->GetUsage());
// 	ASSERT_EQUAL(thirdBuffer->GetNumBytes(), fourthBuffer->GetNumBytes());
// 	ASSERT_EQUAL(thirdBuffer->GetOffset(), fourthBuffer->GetOffset());
// 
// 	for (int i = 0; i < firstBuffer->GetNumElements() * firstBuffer->GetElementSize(); ++i)
// 	{
// 		ASSERT_EQUAL(firstBuffer->GetReadOnlyData()[i], secondBuffer->GetReadOnlyData()[i]);
// 	}
// 
// 	for (int i = 0; i < thirdBuffer->GetNumElements() * thirdBuffer->GetElementSize(); ++i)
// 	{
// 		ASSERT_EQUAL(thirdBuffer->GetReadOnlyData()[i], fourthBuffer->GetReadOnlyData()[i]);
// 	}
// 
// 	VertexFormatSharedPtr firstVertexFormat = secondVisualTest->GetVertexFormat();
// 	VertexFormatSharedPtr secondVertexFormat = seventhVisualTest->GetVertexFormat();
// 
// 	ASSERT_EQUAL(firstVertexFormat->GetNumAttributes(),
// 		         secondVertexFormat->GetNumAttributes()); 
// 
// 	for (int i = 0; i < firstVertexFormat->GetNumAttributes(); ++i)
// 	{
// 		ASSERT_EQUAL(firstVertexFormat->GetStreamIndex(i), secondVertexFormat->GetStreamIndex(i));
// 		ASSERT_EQUAL(firstVertexFormat->GetOffset(i), secondVertexFormat->GetOffset(i));
// 		ASSERT_ENUM_EQUAL(firstVertexFormat->GetAttributeType(i),
// 			         secondVertexFormat->GetAttributeType(i));
// 		ASSERT_ENUM_EQUAL(firstVertexFormat->GetAttributeUsage(i),
// 			         secondVertexFormat->GetAttributeUsage(i));
// 		ASSERT_EQUAL(firstVertexFormat->GetUsageIndex(i),
// 			         secondVertexFormat->GetUsageIndex(i));
// 	}
// 
// 	ASSERT_EQUAL(firstVertexFormat->GetStride(), secondVertexFormat->GetStride()); 
// 
// 	// 保证FileTest是正常的。
// 	SaveVisual::SaveToFile(*secondVisualTest, SYSTEM_TEXT("Resource/SceneGraphSuite/Visual.trv"));
}

void Rendering::VisualTesting
	::FileTest()
{
// 	LoadVisual firstLoadVisual(SYSTEM_TEXT("Resource/SceneGraphSuite/Visual.trv"));
// 
// 	VisualTest firstVisualTest(firstLoadVisual.GetPrimitiveType(),
// 		                       firstLoadVisual.GetVertexFormat(),
// 							   firstLoadVisual.GetVertexBuffer(),
// 							   firstLoadVisual.GetIndexBuffer());
// 
// 	SaveVisual::SaveToFile(firstVisualTest,SYSTEM_TEXT("Resource/SceneGraphSuite/VisualSave.trv"));
// 
// 	LoadVisual secondLoadVisual(SYSTEM_TEXT("Resource/SceneGraphSuite/VisualSave.trv"));
// 
// 	VisualTest secondVisualTest(secondLoadVisual.GetPrimitiveType(),
// 		                        secondLoadVisual.GetVertexFormat(),
// 								secondLoadVisual.GetVertexBuffer(),
// 								secondLoadVisual.GetIndexBuffer());
// 
// 	ASSERT_ENUM_EQUAL(firstVisualTest.GetPrimitiveType(), secondLoadVisual.GetPrimitiveType());
// 
// 	VertexBufferSharedPtr firstBuffer = firstVisualTest.GetVertexBuffer();
// 	VertexBufferSharedPtr secondBuffer = secondLoadVisual.GetVertexBuffer();
// 
// 	IndexBufferSharedPtr thirdBuffer = firstVisualTest.GetIndexBuffer();
// 	IndexBufferSharedPtr fourthBuffer = secondLoadVisual.GetIndexBuffer();
// 
// 	ASSERT_EQUAL(firstBuffer->GetNumElements(), secondBuffer->GetNumElements());
// 	ASSERT_EQUAL(firstBuffer->GetElementSize(), secondBuffer->GetElementSize());
// 	ASSERT_ENUM_EQUAL(firstBuffer->GetUsage(), secondBuffer->GetUsage());
// 	ASSERT_EQUAL(firstBuffer->GetNumBytes(), secondBuffer->GetNumBytes());
// 
// 	ASSERT_EQUAL(thirdBuffer->GetNumElements(), fourthBuffer->GetNumElements());
// 	ASSERT_EQUAL(thirdBuffer->GetElementSize(), fourthBuffer->GetElementSize());
// 	ASSERT_ENUM_EQUAL(thirdBuffer->GetUsage(), fourthBuffer->GetUsage());
// 	ASSERT_EQUAL(thirdBuffer->GetNumBytes(), fourthBuffer->GetNumBytes());
// 	ASSERT_EQUAL(thirdBuffer->GetOffset(), fourthBuffer->GetOffset());
// 
// 	for (int i = 0; i < firstBuffer->GetNumElements() * firstBuffer->GetElementSize(); ++i)
// 	{
// 		ASSERT_EQUAL(firstBuffer->GetReadOnlyData()[i], secondBuffer->GetReadOnlyData()[i]);
// 	}
// 
// 	for (int i = 0; i < thirdBuffer->GetNumElements() * thirdBuffer->GetElementSize(); ++i)
// 	{
// 		ASSERT_EQUAL(thirdBuffer->GetReadOnlyData()[i], fourthBuffer->GetReadOnlyData()[i]);
// 	}
// 
// 	VertexFormatSharedPtr firstVertexFormat = firstLoadVisual.GetVertexFormat();
// 	VertexFormatSharedPtr secondVertexFormat = secondLoadVisual.GetVertexFormat();
// 
// 	ASSERT_EQUAL(firstVertexFormat->GetNumAttributes(),
// 		         secondVertexFormat->GetNumAttributes()); 
// 
// 	for (int i = 0; i < firstVertexFormat->GetNumAttributes(); ++i)
// 	{
// 		ASSERT_EQUAL(firstVertexFormat->GetStreamIndex(i), secondVertexFormat->GetStreamIndex(i));
// 		ASSERT_EQUAL(firstVertexFormat->GetOffset(i), secondVertexFormat->GetOffset(i));
// 		ASSERT_ENUM_EQUAL(firstVertexFormat->GetAttributeType(i),
// 			         secondVertexFormat->GetAttributeType(i));
// 		ASSERT_ENUM_EQUAL(firstVertexFormat->GetAttributeUsage(i),
// 			         secondVertexFormat->GetAttributeUsage(i));
// 		ASSERT_EQUAL(firstVertexFormat->GetUsageIndex(i),
// 			         secondVertexFormat->GetUsageIndex(i));
// 	}
// 
// 	ASSERT_EQUAL(firstVertexFormat->GetStride(), secondVertexFormat->GetStride()); 

	
}

 
// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.3 (2019/09/05 11:11)

#include "PolysegmentTesting.h"
#include "VisualTest.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/SceneGraph/SaveVisual.h"
#include "Rendering/SceneGraph/LoadVisual.h"
#include "Rendering/SceneGraph/Polysegment.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/FileManager/ReadFileManager.h"

#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"


#include <vector>

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, PolysegmentTesting) 

void Rendering::PolysegmentTesting
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

void Rendering::PolysegmentTesting
	::InitTest()
{
// 	VisualSharedPtr firstPolysegments = LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/PolysegmentsDisjoint.trv"));
// 
// 	ASSERT_EQUAL(firstPolysegments->GetNumControllers(), 0);
// 
// 	ControllerInterfaceSharedPtr controllerTest(new VisualTest);	
// 	firstPolysegments->AttachController(controllerTest);
// 
// 	ASSERT_EQUAL(firstPolysegments->GetNumControllers(), 1);
// 	ASSERT_EQUAL(firstPolysegments->GetController(0), controllerTest);
// 
// 	ControllerInterfaceSharedPtr secondVisualTest(new VisualTest);
// 
// 	ASSERT_EQUAL_NULL_PTR(secondVisualTest->GetControllerObject());
// 
// 	firstPolysegments->AttachController(secondVisualTest);
// 
// 	VisualTest* ptr = CoreTools::StaticCast<VisualTest>(secondVisualTest.GetData());
// 
// 	ASSERT_EQUAL(secondVisualTest->GetControllerObject(),firstPolysegments.GetData());
// 	ASSERT_EQUAL_NULL_PTR(ptr->GetParent());
// 	
// 	ASSERT_EQUAL(firstPolysegments->GetNumControllers(), 2);
// 	ASSERT_EQUAL(firstPolysegments->GetController(0), controllerTest);
// 	ASSERT_EQUAL(firstPolysegments->GetController(1), secondVisualTest);
// 
// 	firstPolysegments->DetachController(controllerTest);
// 
// 	ASSERT_EQUAL(firstPolysegments->GetNumControllers(), 1);
// 	ASSERT_EQUAL(firstPolysegments->GetController(0), secondVisualTest);
// 
// 	firstPolysegments->DetachAllControllers();
// 
// 	ASSERT_EQUAL(firstPolysegments->GetNumControllers(), 0);
// 
// 	// Visual测试
// 	ASSERT_FALSE(firstPolysegments->GetConstVertexFormat().IsNullPtr());
// 	ASSERT_FALSE(firstPolysegments->GetVertexFormat().IsNullPtr());
// 
// 	ASSERT_FALSE(firstPolysegments->GetConstVertexBuffer().IsNullPtr());
// 	ASSERT_FALSE(firstPolysegments->GetVertexBuffer().IsNullPtr());
// 
// 	ASSERT_TRUE(firstPolysegments->GetConstIndexBuffer().IsNullPtr());
// 	ASSERT_TRUE(firstPolysegments->GetIndexBuffer().IsNullPtr());
// 
// 	ASSERT_TRUE(firstPolysegments->GetEffectInstance().IsNullPtr());
// 
// 	// Polysegment测试
// 
// 	PolysegmentSharedPtr secondPolysegments = firstPolysegments.PolymorphicDowncastObjectSharedPtr<PolysegmentSharedPtr>();
// 
// 	ASSERT_EQUAL(secondPolysegments->GetMaxNumSegments(),secondPolysegments->GetConstVertexBuffer()->GetNumElements() / 2);
// 	
// 	ASSERT_EQUAL(secondPolysegments->GetNumSegments(), secondPolysegments->GetConstVertexBuffer()->GetNumElements() / 2);
// 	
// 	secondPolysegments->SetNumSegments(secondPolysegments->GetConstVertexBuffer()->GetNumElements());
// 	ASSERT_EQUAL(secondPolysegments->GetMaxNumSegments(),secondPolysegments->GetConstVertexBuffer()->GetNumElements() / 2);
// 	
// 	ASSERT_EQUAL(secondPolysegments->GetNumSegments(),secondPolysegments->GetConstVertexBuffer()->GetNumElements() / 2);
//  
// 	secondPolysegments->SetNumSegments(1);
// 	ASSERT_EQUAL(secondPolysegments->GetMaxNumSegments(), secondPolysegments->GetConstVertexBuffer()->GetNumElements() / 2);
// 	
// 	ASSERT_EQUAL(secondPolysegments->GetNumSegments(), 1);
// 	ASSERT_FALSE(secondPolysegments->GetContiguous());
// 
// 	VertexFormatSharedPtr secondVertexformat = firstPolysegments->GetConstVertexFormat()->Clone();
// 	VertexBufferSharedPtr secondVertexbuffer(new VertexBuffer);
// 	IndexBufferSharedPtr secondIndexbuffer(new IndexBuffer);
// 
// 	firstPolysegments->SetVertexFormat(secondVertexformat);
// 	ASSERT_EQUAL(firstPolysegments->GetConstVertexFormat(), secondVertexformat);
// 	ASSERT_EQUAL(firstPolysegments->GetVertexFormat(), secondVertexformat);
// 
// 	firstPolysegments->SetVertexBuffer(secondVertexbuffer);
// 	ASSERT_EQUAL(firstPolysegments->GetConstVertexBuffer(), secondVertexbuffer);
// 	ASSERT_EQUAL(firstPolysegments->GetVertexBuffer(), secondVertexbuffer);
// 
// 	firstPolysegments->SetIndexBuffer(secondIndexbuffer);
// 	ASSERT_EQUAL(firstPolysegments->GetConstIndexBuffer(), secondIndexbuffer);
// 	ASSERT_EQUAL(firstPolysegments->GetIndexBuffer(), secondIndexbuffer);
// 
// 	ASSERT_TRUE(firstPolysegments->GetEffectInstance().IsNullPtr());
// 
// 	VisualSharedPtr thirdPolysegments = LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/PolysegmentsContiguous.trv"));
// 
// 	PolysegmentSharedPtr fourthPolysegments = thirdPolysegments.PolymorphicDowncastObjectSharedPtr<PolysegmentSharedPtr>();
// 
// 	ASSERT_EQUAL(fourthPolysegments->GetMaxNumSegments(),fourthPolysegments->GetConstVertexBuffer()->GetNumElements() - 1);
// 
// 	ASSERT_EQUAL(fourthPolysegments->GetNumSegments(),fourthPolysegments->GetConstVertexBuffer()->GetNumElements() - 1);
// 
// 	fourthPolysegments->SetNumSegments(fourthPolysegments->GetConstVertexBuffer()->GetNumElements());
// 	ASSERT_EQUAL(fourthPolysegments->GetMaxNumSegments(),fourthPolysegments->GetConstVertexBuffer()->GetNumElements() - 1);
// 
// 	ASSERT_EQUAL(fourthPolysegments->GetNumSegments(),fourthPolysegments->GetConstVertexBuffer()->GetNumElements() - 1);
// 
// 	fourthPolysegments->SetNumSegments(1);
// 	ASSERT_EQUAL(fourthPolysegments->GetMaxNumSegments(),fourthPolysegments->GetConstVertexBuffer()->GetNumElements()- 1);
// 
// 	ASSERT_EQUAL(fourthPolysegments->GetNumSegments(), 1);
	/*ASSERT_TRUE(fourthPolysegments->GetContiguous());*/
}

void Rendering::PolysegmentTesting
	::CopyTest()
{ 
// 	VisualSharedPtr firstPolysegments = LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/PolysegmentsDisjoint.trv"));
// 	
// 	ASSERT_EQUAL(firstPolysegments->GetNumControllers(), 0);
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
// 	firstPolysegments->AttachController(secondVisualTest);
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
// 	ASSERT_APPROXIMATE(secondPtr->GetLocalTransform().GetUniformScale (), 3.0f,1e-8f);
// 	ASSERT_APPROXIMATE(firstPtr->GetLocalTransform().GetUniformScale (),5.0f,1e-8f);
// 
// 	firstPolysegments->AttachController(thirdVisualTest);
// 
// 	ASSERT_EQUAL(firstPolysegments->GetNumControllers(), 2);
// 	ASSERT_EQUAL(firstPolysegments->GetController(0), secondVisualTest);
// 	ASSERT_EQUAL(firstPolysegments->GetController(1), thirdVisualTest);
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
// 	// Visual测试
// 	PolysegmentSharedPtr secondPolysegments = firstPolysegments->Clone().PolymorphicDowncastObjectSharedPtr<PolysegmentSharedPtr>();
// 
// 	ASSERT_UNEQUAL(secondPolysegments->GetConstVertexFormat(), firstPolysegments->GetConstVertexFormat());
// 	ASSERT_UNEQUAL(secondPolysegments->GetVertexFormat(), firstPolysegments->GetVertexFormat());
// 	ASSERT_UNEQUAL(secondPolysegments->GetConstVertexBuffer(), firstPolysegments->GetConstVertexBuffer());
// 	ASSERT_UNEQUAL(secondPolysegments->GetVertexBuffer(), firstPolysegments->GetVertexBuffer());
// 	ASSERT_TRUE(secondPolysegments->GetConstIndexBuffer().IsNullPtr());
// 	ASSERT_TRUE(firstPolysegments->GetConstIndexBuffer().IsNullPtr());
// 	ASSERT_TRUE(secondPolysegments->GetIndexBuffer().IsNullPtr());
// 	ASSERT_TRUE(firstPolysegments->GetIndexBuffer().IsNullPtr());
// 
// 	PolysegmentSharedPtr thirdPolysegments = firstPolysegments.PolymorphicDowncastObjectSharedPtr<PolysegmentSharedPtr>();
// 
// 	ASSERT_EQUAL(thirdPolysegments->GetMaxNumSegments(), secondPolysegments->GetMaxNumSegments());
// 	ASSERT_EQUAL(thirdPolysegments->GetNumSegments(), secondPolysegments->GetNumSegments());
// 	ASSERT_EQUAL(thirdPolysegments->GetContiguous(), secondPolysegments->GetContiguous());
 }

void Rendering::PolysegmentTesting
	::TransformTest()
{
// 	VisualSharedPtr firstPolysegments = LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/PolysegmentsContiguous.trv"));
// 
// 	ControllerInterfaceSharedPtr secondSpatialTest(new VisualTest);
// 	firstPolysegments->AttachController(secondSpatialTest);
// 
// 	VisualTest* firstPtr = CoreTools::StaticCast<VisualTest>(secondSpatialTest.GetData());
// 
// 	Transform firstTransform;
// 	firstTransform.SetUniformScale(5.0f);
// 
// 	Transform secondTransform;
// 	secondTransform.SetTranslate(Transform::APoint(5.0f,3.0f,5.6f));
// 
// 	firstPolysegments->SetLocalTransform(firstTransform);
// 	firstPtr->SetLocalTransform(secondTransform);
// 	firstPtr->SetParent(firstPolysegments.GetData());
// 
// 	firstPolysegments->Update();
// 
// 	ASSERT_TRUE(Approximate(firstPolysegments->GetLocalTransform(),firstTransform,1e-8f));
// 	ASSERT_TRUE(Approximate(firstPtr->GetLocalTransform(),secondTransform,1e-8f));
// 
// 	ASSERT_TRUE(Approximate(firstPolysegments->GetWorldTransform(),firstTransform,1e-8f));
// 	ASSERT_TRUE(Approximate(firstPtr->GetWorldTransform(),firstTransform * secondTransform,1e-8f));
// 
// 	// Visual测试
// 	PolysegmentSharedPtr secondPolysegments = firstPolysegments.PolymorphicDowncastObjectSharedPtr<PolysegmentSharedPtr>();
// 	VertexBufferSharedPtr firstVertexbuffer(firstPolysegments->GetVertexBuffer());
// 	VertexFormatSharedPtr firstVertexformat(firstPolysegments->GetVertexFormat());
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
// 	Bound worldBound = modelBound.TransformBy(firstPolysegments->GetWorldTransform());
//   
// 	firstPolysegments->Update();
// 	
// 	ASSERT_TRUE(Approximate(firstPolysegments->GetModelBound(), modelBound,1e-8f)); 
// 
// 	ASSERT_TRUE(Approximate(firstPolysegments->GetWorldBound(), worldBound, 1e-8f));
}

void Rendering::PolysegmentTesting
	::StreamTest()
{
// 	VisualSharedPtr firstPolysegments = LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/PolysegmentsDisjoint.trv"));		 
//  
// 	CoreTools::OutTopLevel outTopLevel;
// 	 
// 	firstPolysegments->SetUniqueID(5);
// 
// 	outTopLevel.Insert(firstPolysegments.PolymorphicDowncastObjectSharedPtr<CoreTools::ObjectInterfaceSharedPtr>());
// 
// 	Polysegment* secondPolysegments = CoreTools::PolymorphicCast<Polysegment>(firstPolysegments.GetData());
// 
// 	Transform firstTransform;
// 	Transform secondTransform;
// 	Bound firstBound(Bound::APoint(0.2f,5.0f,3.0f),2.0f);	
// 
// 	firstTransform.SetUniformScale(5.0f);
// 	secondTransform.SetUniformScale(3.0f);
// 
// 	secondPolysegments->SetLocalTransform(firstTransform);
// 	secondPolysegments->SetWorldTransform(secondTransform);
// 	secondPolysegments->SetWorldBound(firstBound);
// 	secondPolysegments->SetCullingMode(CullingMode::Always);
// 
// 	ControllerInterfaceSharedPtr thirdVisualTest(new VisualTest);
// 	secondPolysegments->AttachController(thirdVisualTest);
// 
// 	thirdVisualTest->SetUniqueID(4);
// 
// 	ControllerInterfaceSharedPtr fourthVisualTest(new VisualTest);
// 	secondPolysegments->AttachController(fourthVisualTest);
// 
// 	fourthVisualTest->SetUniqueID(3);
// 
// 	ControllerInterfaceSharedPtr fifthVisualTest(new VisualTest);
// 	secondPolysegments->AttachController(fifthVisualTest);
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
// 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr = outStream.GetBufferOutStreamInformation();
//         
// 	CoreTools::BufferInStream inStream(fileBufferPtr);
//         
// 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
// 
// 	PolysegmentSharedPtr  seventhVisualTest = inTopLevel[0].PolymorphicDowncastObjectSharedPtr<PolysegmentSharedPtr>();
// 
// 	ASSERT_EQUAL(seventhVisualTest->GetNumControllers(), 3);
// 
// 	ASSERT_TRUE(Approximate(seventhVisualTest->GetLocalTransform(),firstTransform,1e-8f));
// 	ASSERT_TRUE(Approximate(seventhVisualTest->GetWorldTransform(),secondTransform,1e-8f));
// 	ASSERT_TRUE(Approximate(seventhVisualTest->GetWorldBound(), firstBound, 1e-8f));
// 	ASSERT_ENUM_EQUAL(seventhVisualTest->GetCullingMode(), CullingMode::Always);
// 
// 	VisualTest* eighthVisualTest =	CoreTools::DynamicCast<VisualTest>(seventhVisualTest->GetController(0).GetData());
// 
// 	ASSERT_UNEQUAL_NULL_PTR(eighthVisualTest);
// 
// 	VisualTest* ninthVisualTest = CoreTools::DynamicCast<VisualTest>(seventhVisualTest->GetController(1).GetData());
// 
// 	ASSERT_UNEQUAL_NULL_PTR(ninthVisualTest);
// 
// 	VisualTest* tenthVisualTest = CoreTools::DynamicCast<VisualTest>(seventhVisualTest->GetController(2).GetData());
// 
// 	ASSERT_UNEQUAL_NULL_PTR(tenthVisualTest);
// 
// 	ASSERT_EQUAL(tenthVisualTest->GetNumControllers(), 1);
// 
// 	VisualTest* eleventhVisualTest = CoreTools::DynamicCast<VisualTest>(tenthVisualTest->GetController(0).GetData());
// 
// 	ASSERT_UNEQUAL_NULL_PTR(eleventhVisualTest);
// 
// 	// Visual测试
// 	ASSERT_ENUM_EQUAL(secondPolysegments->GetPrimitiveType(), seventhVisualTest->GetPrimitiveType());
// 
// 	VertexBufferSharedPtr firstBuffer = secondPolysegments->GetVertexBuffer();
// 	VertexBufferSharedPtr secondBuffer = seventhVisualTest->GetVertexBuffer();
// 
// 	IndexBufferSharedPtr thirdBuffer = secondPolysegments->GetIndexBuffer();
// 	IndexBufferSharedPtr fourthBuffer = seventhVisualTest->GetIndexBuffer();
// 
// 	ASSERT_EQUAL(firstBuffer->GetNumElements(), secondBuffer->GetNumElements());
// 	ASSERT_EQUAL(firstBuffer->GetElementSize(), secondBuffer->GetElementSize());
// 	ASSERT_ENUM_EQUAL(firstBuffer->GetUsage(), secondBuffer->GetUsage());
// 	ASSERT_EQUAL(firstBuffer->GetNumBytes(), secondBuffer->GetNumBytes());
// 
// 	ASSERT_TRUE(thirdBuffer.IsNullPtr());
// 	ASSERT_TRUE(fourthBuffer.IsNullPtr());
// 
// 	for (int i = 0; i < firstBuffer->GetNumElements() * firstBuffer->GetElementSize(); ++i)
// 	{
// 		ASSERT_EQUAL(firstBuffer->GetReadOnlyData()[i], secondBuffer->GetReadOnlyData()[i]);
// 	}
// 	 
// 	VertexFormatSharedPtr firstVertexFormat = secondPolysegments->GetVertexFormat();
// 	VertexFormatSharedPtr secondVertexFormat = seventhVisualTest->GetVertexFormat();
// 
// 	ASSERT_EQUAL(firstVertexFormat->GetNumAttributes(),secondVertexFormat->GetNumAttributes()); 
// 
// 	for (int i = 0; i < firstVertexFormat->GetNumAttributes(); ++i)
// 	{
// 		ASSERT_EQUAL(firstVertexFormat->GetStreamIndex(i), secondVertexFormat->GetStreamIndex(i));
// 		ASSERT_EQUAL(firstVertexFormat->GetOffset(i), secondVertexFormat->GetOffset(i));
// 		ASSERT_ENUM_EQUAL(firstVertexFormat->GetAttributeType(i),secondVertexFormat->GetAttributeType(i));
// 		ASSERT_ENUM_EQUAL(firstVertexFormat->GetAttributeUsage(i),secondVertexFormat->GetAttributeUsage(i));
// 		ASSERT_EQUAL(firstVertexFormat->GetUsageIndex(i), secondVertexFormat->GetUsageIndex(i));
// 	}
// 
// 	ASSERT_EQUAL(firstVertexFormat->GetStride(), secondVertexFormat->GetStride()); 
// 
// 	// 保证FileTest是正常的。
// 	SaveVisual::SaveToFile(*secondPolysegments, SYSTEM_TEXT("Resource/SceneGraphSuite/PolysegmentsDisjointSave.trv"));	
}

void Rendering::PolysegmentTesting
	::FileTest()
{
		
// 	LoadVisual firstLoadVisual(SYSTEM_TEXT("Resource/SceneGraphSuite/PolysegmentsDisjointSave.trv"));
// 
// 	VisualTest firstVisualTest(firstLoadVisual.GetPrimitiveType(),
// 		                       firstLoadVisual.GetVertexFormat(),
// 							   firstLoadVisual.GetVertexBuffer(),
// 							   firstLoadVisual.GetIndexBuffer());
// 
// 	SaveVisual::SaveToFile(firstVisualTest,SYSTEM_TEXT("Resource/SceneGraphSuite/PolysegmentsDisjointSaveCopy.trv"));
// 
// 	LoadVisual secondLoadVisual(SYSTEM_TEXT("Resource/SceneGraphSuite/PolysegmentsDisjointSaveCopy.trv"));
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
// 	ASSERT_TRUE(thirdBuffer.IsNullPtr());
// 	ASSERT_TRUE(fourthBuffer.IsNullPtr());
// 
// 	for (int i = 0; i < firstBuffer->GetNumElements() * firstBuffer->GetElementSize(); ++i)
// 	{
// 		ASSERT_EQUAL(firstBuffer->GetReadOnlyData()[i], secondBuffer->GetReadOnlyData()[i]);
// 	}
// 
// 	VertexFormatSharedPtr firstVertexFormat = firstLoadVisual.GetVertexFormat();
// 	VertexFormatSharedPtr secondVertexFormat = secondLoadVisual.GetVertexFormat();
// 
// 	ASSERT_EQUAL(firstVertexFormat->GetNumAttributes(),secondVertexFormat->GetNumAttributes()); 
// 
// 	for (int i = 0; i < firstVertexFormat->GetNumAttributes(); ++i)
// 	{
// 		ASSERT_EQUAL(firstVertexFormat->GetStreamIndex(i), secondVertexFormat->GetStreamIndex(i));
// 		ASSERT_EQUAL(firstVertexFormat->GetOffset(i), secondVertexFormat->GetOffset(i));
// 		ASSERT_ENUM_EQUAL(firstVertexFormat->GetAttributeType(i),secondVertexFormat->GetAttributeType(i));
// 		ASSERT_ENUM_EQUAL(firstVertexFormat->GetAttributeUsage(i),secondVertexFormat->GetAttributeUsage(i));
// 		ASSERT_EQUAL(firstVertexFormat->GetUsageIndex(i),secondVertexFormat->GetUsageIndex(i));
// 	}
// 
// 	ASSERT_EQUAL(firstVertexFormat->GetStride(), secondVertexFormat->GetStride()); 	
}

 
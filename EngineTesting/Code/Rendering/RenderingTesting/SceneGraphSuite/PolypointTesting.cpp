// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.3 (2019/09/05 11:09)

#include "PolypointTesting.h"
#include "VisualTest.h"
#include "Rendering/SceneGraph/SaveVisual.h"
#include "Rendering/SceneGraph/LoadVisual.h"
#include "Rendering/SceneGraph/Polypoint.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Rendering/Renderers/RendererManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/FileManager/ReadFileManager.h"


#include <vector>

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, PolypointTesting) 

void Rendering::PolypointTesting
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
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26496)
void Rendering::PolypointTesting
	::InitTest()
{
// 	VisualSharedPtr firstPolypoint =	LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/Polypoint.trv"));
// 	 
// 	ASSERT_EQUAL(firstPolypoint->GetNumControllers(),0);	
// 
// 	ControllerInterfaceSharedPtr firstVisualTest(new VisualTest);
// 	firstPolypoint->AttachController(firstVisualTest);
// 
// 	ASSERT_EQUAL(firstPolypoint->GetNumControllers(), 1);
// 	ASSERT_EQUAL(firstPolypoint->GetController(0), firstVisualTest);
// 
// 	ControllerInterfaceSharedPtr secondVisualTest(new VisualTest);
// 
// 	ASSERT_EQUAL_NULL_PTR(secondVisualTest->GetControllerObject());
// 
// 	firstPolypoint->AttachController(secondVisualTest);
// 
// 	Polypoint* ptr = CoreTools::StaticCast<Polypoint>(secondVisualTest.GetData());
// 
// 	ASSERT_EQUAL(secondVisualTest->GetControllerObject(),
// 	             firstPolypoint.GetData());
// 	ASSERT_EQUAL_NULL_PTR(ptr->GetParent());
// 	
// 	ASSERT_EQUAL(firstPolypoint->GetNumControllers(), 2);
// 	ASSERT_EQUAL(firstPolypoint->GetController(0), firstVisualTest);
// 	ASSERT_EQUAL(firstPolypoint->GetController(1), secondVisualTest);
// 
// 	firstPolypoint->DetachController(firstVisualTest);
// 
// 	ASSERT_EQUAL(firstPolypoint->GetNumControllers(), 1);
// 	ASSERT_EQUAL(firstPolypoint->GetController(0), secondVisualTest);
// 
// 	firstPolypoint->DetachAllControllers();
// 
// 	ASSERT_EQUAL(firstPolypoint->GetNumControllers(), 0);
// 
// 	// Visual测试	
// 	ASSERT_ENUM_EQUAL(firstPolypoint->GetPrimitiveType(), VisualPrimitiveType::Polypoint);
// 
// 	ASSERT_FALSE(firstPolypoint->GetConstVertexFormat().IsNullPtr());
// 	ASSERT_FALSE(firstPolypoint->GetVertexFormat().IsNullPtr());
// 
// 	ASSERT_FALSE(firstPolypoint->GetConstVertexBuffer().IsNullPtr());
// 	ASSERT_FALSE(firstPolypoint->GetVertexBuffer().IsNullPtr());
// 
// 	ASSERT_TRUE(firstPolypoint->GetConstIndexBuffer().IsNullPtr());
// 	ASSERT_TRUE(firstPolypoint->GetIndexBuffer().IsNullPtr());
// 
// 	ASSERT_TRUE(firstPolypoint->GetEffectInstance().IsNullPtr());		
// 
// 	// Polypoint测试
// 	PolypointSharedPtr secondPolypoint = firstPolypoint.PolymorphicDowncastObjectSharedPtr<PolypointSharedPtr>();
// 	ASSERT_EQUAL(secondPolypoint->GetMaxNumPoints(), firstPolypoint->GetConstVertexBuffer()->GetNumElements());
// 	ASSERT_EQUAL(secondPolypoint->GetNumPoints(), firstPolypoint->GetConstVertexBuffer()->GetNumElements());
//  
// 	secondPolypoint->SetNumPoints(secondPolypoint->GetMaxNumPoints() + 20);
// 	ASSERT_EQUAL(secondPolypoint->GetMaxNumPoints(), firstPolypoint->GetConstVertexBuffer()->GetNumElements());
// 	ASSERT_EQUAL(secondPolypoint->GetNumPoints(), firstPolypoint->GetConstVertexBuffer()->GetNumElements());
// 	 
// 	secondPolypoint->SetNumPoints(2);
// 	ASSERT_EQUAL(secondPolypoint->GetMaxNumPoints(), firstPolypoint->GetConstVertexBuffer()->GetNumElements());
// 	ASSERT_EQUAL(secondPolypoint->GetNumPoints(), 2);
// 
// 	VertexFormatSharedPtr secondVertexformat
// 		= firstPolypoint->GetVertexFormat()->Clone();
// 	VertexBufferSharedPtr secondVertexbuffer(new VertexBuffer);
// 	IndexBufferSharedPtr secondIndexbuffer(new IndexBuffer);
// 
// 	firstPolypoint->SetVertexFormat(secondVertexformat);
// 	ASSERT_EQUAL(firstPolypoint->GetConstVertexFormat(), secondVertexformat);
// 	ASSERT_EQUAL(firstPolypoint->GetVertexFormat(), secondVertexformat);
// 
// 	firstPolypoint->SetVertexBuffer(secondVertexbuffer);
// 	ASSERT_EQUAL(firstPolypoint->GetConstVertexBuffer(), secondVertexbuffer);
// 	ASSERT_EQUAL(firstPolypoint->GetVertexBuffer(), secondVertexbuffer);
// 
// 	firstPolypoint->SetIndexBuffer(secondIndexbuffer);
// 	ASSERT_EQUAL(firstPolypoint->GetConstIndexBuffer(), secondIndexbuffer);
// 	ASSERT_EQUAL(firstPolypoint->GetIndexBuffer(), secondIndexbuffer);
// 
// 	ASSERT_TRUE(firstPolypoint->GetEffectInstance().IsNullPtr());
}

void Rendering::PolypointTesting
	::CopyTest()
{ 
// 	VisualSharedPtr firstPolypoint = LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/Polypoint.trv"));
// 	
// 	ASSERT_EQUAL(firstPolypoint->GetNumControllers(), 0);
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
// 	firstPolypoint->AttachController(secondVisualTest);
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
// 	ASSERT_APPROXIMATE(secondPtr->GetLocalTransform().GetUniformScale (),3.0f,1e-8f);
// 	ASSERT_APPROXIMATE(firstPtr->GetLocalTransform().GetUniformScale (),5.0f,1e-8f);
// 
// 	firstPolypoint->AttachController(thirdVisualTest);
// 
// 	ASSERT_EQUAL(firstPolypoint->GetNumControllers(), 2);
// 	ASSERT_EQUAL(firstPolypoint->GetController(0), secondVisualTest);
// 	ASSERT_EQUAL(firstPolypoint->GetController(1), thirdVisualTest);
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
// 	VisualSharedPtr fifthVisualTest = firstPolypoint->Clone().PolymorphicDowncastObjectSharedPtr<VisualSharedPtr>();
// 
// 	ASSERT_UNEQUAL(firstPolypoint->GetConstVertexFormat(), fifthVisualTest->GetConstVertexFormat());
// 	ASSERT_UNEQUAL(firstPolypoint->GetVertexFormat(), fifthVisualTest->GetVertexFormat());
// 	ASSERT_UNEQUAL(firstPolypoint->GetConstVertexBuffer(), fifthVisualTest->GetConstVertexBuffer());
// 	ASSERT_UNEQUAL(firstPolypoint->GetVertexBuffer(), fifthVisualTest->GetVertexBuffer());
// 	ASSERT_EQUAL(firstPolypoint->GetConstIndexBuffer(), fifthVisualTest->GetConstIndexBuffer());
// 	ASSERT_EQUAL(firstPolypoint->GetIndexBuffer(), fifthVisualTest->GetIndexBuffer());
// 	ASSERT_TRUE(firstPolypoint->GetConstIndexBuffer().IsNullPtr());
}

void Rendering::PolypointTesting
	::TransformTest()
{
// 	VisualSharedPtr firstPolypoint = LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/Polypoint.trv"));
// 		
// 	ControllerInterfaceSharedPtr secondSpatialTest(new VisualTest);
// 	firstPolypoint->AttachController(secondSpatialTest);
// 
// 	VisualTest* firstPtr = CoreTools::StaticCast<VisualTest>(secondSpatialTest.GetData());
// 
// 	Transform firstTransform;
// 	firstTransform.SetUniformScale(5.0f);
// 
// 	Transform secondTransform;
// 	secondTransform.SetTranslate(Transform::APoint(5.0f,3.0f,5.6f));
// 
// 	firstPolypoint->SetLocalTransform(firstTransform);
// 	firstPtr->SetLocalTransform(secondTransform);
// 	firstPtr->SetParent(firstPolypoint.GetData());
// 
// 	firstPolypoint->Update();
// 
// 	ASSERT_TRUE(Approximate(firstPolypoint->GetLocalTransform(),firstTransform,1e-8f));
// 	ASSERT_TRUE(Approximate(firstPtr->GetLocalTransform(),secondTransform,1e-8f));
// 
// 	ASSERT_TRUE(Approximate(firstPolypoint->GetWorldTransform(),firstTransform,1e-8f));
// 	ASSERT_TRUE(Approximate(firstPtr->GetWorldTransform(),firstTransform * secondTransform,1e-8f));
// 
// 	// Visual测试
// 	int numVertices = firstPolypoint->GetVertexBuffer()->GetNumElements();
// 	int stride = firstPolypoint->GetVertexFormat()->GetStride();
// 
// 	int positionIndex = firstPolypoint->GetVertexFormat()->GetIndex(VertexFormatFlags::AttributeUsage::Position);
// 
// 	const char* data = firstPolypoint->GetVertexBuffer()->GetReadOnlyData();
// 	int positionOffset = firstPolypoint->GetVertexFormat()->GetOffset(positionIndex);
// 
// 	Bound modelBound;
// 	modelBound.ComputeFromData(numVertices, stride, data + positionOffset);
// 
// 	Bound worldBound = modelBound.TransformBy(firstPolypoint->GetWorldTransform());
//   
// 	firstPolypoint->Update();
// 	
// 	ASSERT_TRUE(Approximate(firstPolypoint->GetModelBound(),modelBound,1e-8f)); 
// 
// 	ASSERT_TRUE(Approximate(firstPolypoint->GetWorldBound(),worldBound, 1e-8f)); 
}

void Rendering::PolypointTesting
	::StreamTest()
{
// 	VisualSharedPtr firstPolypoint = LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/Polypoint.trv"));
// 		 
// 	CoreTools::OutTopLevel outTopLevel;
// 
// 	firstPolypoint->SetUniqueID(5);
// 
// 	outTopLevel.Insert(firstPolypoint.PolymorphicDowncastObjectSharedPtr<CoreTools::ObjectInterfaceSharedPtr>());	 
// 
// 	Transform firstTransform;
// 	Transform secondTransform;
// 	Bound firstBound(Bound::APoint(0.2f,5.0f,3.0f),2.0f);	
// 
// 	firstTransform.SetUniformScale(5.0f);
// 	secondTransform.SetUniformScale(3.0f);
// 
// 	firstPolypoint->SetLocalTransform(firstTransform);
// 	firstPolypoint->SetWorldTransform(secondTransform);
// 	firstPolypoint->SetWorldBound(firstBound);
// 	firstPolypoint->SetCullingMode(CullingMode::Always);
// 
// 	ControllerInterfaceSharedPtr thirdVisualTest(new VisualTest);
// 	firstPolypoint->AttachController(thirdVisualTest);
// 
// 	thirdVisualTest->SetUniqueID(4);
// 
// 	ControllerInterfaceSharedPtr fourthVisualTest(new VisualTest);
// 	firstPolypoint->AttachController(fourthVisualTest);
// 
// 	fourthVisualTest->SetUniqueID(3);
// 
// 	ControllerInterfaceSharedPtr fifthVisualTest(new VisualTest);
// 	firstPolypoint->AttachController(fifthVisualTest);
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
// 	PolypointSharedPtr  seventhVisualTest = inTopLevel[0].PolymorphicDowncastObjectSharedPtr<PolypointSharedPtr>();
// 
// 	ASSERT_EQUAL(seventhVisualTest->GetNumControllers(), 3);
// 
// 	ASSERT_TRUE(Approximate(seventhVisualTest->GetLocalTransform(),firstTransform,1e-8f));
// 	ASSERT_TRUE(Approximate(seventhVisualTest->GetWorldTransform(),secondTransform,1e-8f));
// 	ASSERT_TRUE(Approximate(seventhVisualTest->GetWorldBound(), firstBound, 1e-8f));
// 	ASSERT_ENUM_EQUAL(seventhVisualTest->GetCullingMode(), CullingMode::Always);
// 
// 	VisualTest* eighthVisualTest = CoreTools::DynamicCast<VisualTest>(seventhVisualTest->GetController(0).GetData());
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
// 	ASSERT_ENUM_EQUAL(firstPolypoint->GetPrimitiveType(), seventhVisualTest->GetPrimitiveType());
// 
// 	VertexBufferSharedPtr firstBuffer = firstPolypoint->GetVertexBuffer();
// 	VertexBufferSharedPtr secondBuffer = seventhVisualTest->GetVertexBuffer();
// 
// 	IndexBufferSharedPtr thirdBuffer = firstPolypoint->GetIndexBuffer();
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
// 	VertexFormatSharedPtr firstVertexFormat = firstPolypoint->GetVertexFormat();
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
// 		ASSERT_EQUAL(firstVertexFormat->GetUsageIndex(i),secondVertexFormat->GetUsageIndex(i));
// 	}
// 
// 	ASSERT_EQUAL(firstVertexFormat->GetStride(), secondVertexFormat->GetStride()); 
// 
// 	// 保证FileTest是正常的。
// 	SaveVisual::SaveToFile(*firstPolypoint, SYSTEM_TEXT("Resource/SceneGraphSuite/PolypointSave.trv")); 
}

void Rendering::PolypointTesting
	::FileTest()
{
// 	LoadVisual firstLoadVisual(SYSTEM_TEXT("Resource/SceneGraphSuite/PolypointSave.trv"));
// 
// 	VisualTest firstVisualTest(firstLoadVisual.GetPrimitiveType(),
// 		                       firstLoadVisual.GetVertexFormat(),
// 							   firstLoadVisual.GetVertexBuffer(),
// 							   firstLoadVisual.GetIndexBuffer());
// 
// 	SaveVisual::SaveToFile(firstVisualTest,SYSTEM_TEXT("Resource/SceneGraphSuite/PolypointSaveCopy.trv"));
// 
// 	LoadVisual secondLoadVisual(SYSTEM_TEXT("Resource/SceneGraphSuite/PolypointSaveCopy.trv"));
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
// 	ASSERT_EQUAL(firstVertexFormat->GetNumAttributes(),
// 		         secondVertexFormat->GetNumAttributes()); 
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

 
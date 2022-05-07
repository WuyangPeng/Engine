// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/05 09:39)

#include "CameraNodeTesting.h"
#include "SpatialTest.h"
#include "Rendering/SceneGraph/CameraNode.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"






UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, CameraNodeTesting) 

void Rendering::CameraNodeTesting
	::MainTest()
{ 
	CoreTools::InitTerm::ExecuteInitializers();

	CameraManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
	ASSERT_NOT_THROW_EXCEPTION_0(TransformTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ChildTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

	CameraManager::Destroy();

	CoreTools::InitTerm::ExecuteTerminators();
}
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26451)
#include SYSTEM_WARNING_DISABLE(26429)
void Rendering::CameraNodeTesting
	::InitTest()
{
// 	CameraSharedPtr firstCamera(new Camera(true, 1e-5f));
// 	CameraNode firstNode(firstCamera);
//  
//  	ASSERT_EQUAL(firstNode.GetNumControllers(),0);
//  
// 	ControllerInterfaceSharedPtr secondNode(new Node);
// 	firstNode.AttachController(secondNode);
// 
// 	ASSERT_EQUAL(firstNode.GetNumControllers(),1);
// 	ASSERT_EQUAL(firstNode.GetController(0), secondNode);
// 
// 	ControllerInterfaceSharedPtr thirdNode(new Node);
// 
// 	ASSERT_EQUAL_NULL_PTR(thirdNode->GetControllerObject());
// 
// 	firstNode.AttachController(thirdNode);
// 
// 	Node* ptr = CoreTools::StaticCast<Node>(thirdNode.GetData());
// 
// 	ASSERT_EQUAL(ptr->GetControllerObject(),&firstNode);
// 	ASSERT_EQUAL_NULL_PTR(ptr->GetParent());
// 
// 	ASSERT_EQUAL(firstNode.GetNumControllers(),2);
// 	ASSERT_EQUAL(firstNode.GetController(0), secondNode);
// 	ASSERT_EQUAL(firstNode.GetController(1), thirdNode);
// 
// 	firstNode.DetachController(secondNode);
// 
// 	ASSERT_EQUAL(firstNode.GetNumControllers(),1);
// 	ASSERT_EQUAL(firstNode.GetController(0), thirdNode);
// 
// 	firstNode.DetachAllControllers();
// 
// 	ASSERT_EQUAL(firstNode.GetNumControllers(),0);
//     
//     // Child≤‚ ‘
// 	ASSERT_EQUAL(firstNode.GetNumChildren(),0);
//     
//     SpatialSharedPtr fourthNode(new Node);
//     
//     firstNode.AttachChild(fourthNode);
//     
//     ASSERT_EQUAL(firstNode.GetNumChildren(),1);
// 	ASSERT_EQUAL(firstNode.GetChild(0), fourthNode);
//     
//     ptr = CoreTools::StaticCast<Node>(fourthNode.GetData());
//     
// 	ASSERT_EQUAL_NULL_PTR(ptr->GetControllerObject());
// 	ASSERT_EQUAL(ptr->GetParent(),&firstNode);
//     
// 	SpatialSharedPtr fifthNode(new Node);
//     
//     firstNode.AttachChild(fifthNode);
//     
//     ASSERT_EQUAL(firstNode.GetNumChildren(),2);
// 	ASSERT_EQUAL(firstNode.GetChild(0), fourthNode);
//     ASSERT_EQUAL(firstNode.GetChild(1), fifthNode);
//     
// 	SpatialSharedPtr sixthNode = firstNode.DetachChildAt(0);
//     
// 	ASSERT_EQUAL(firstNode.GetNumChildren(),2);
// 	ASSERT_TRUE(firstNode.GetChild(0).IsNullPtr());
//     ASSERT_EQUAL(sixthNode, fourthNode);
//     ASSERT_EQUAL(firstNode.GetChild(1), fifthNode);
//     
//     int index = firstNode.DetachChild(fifthNode);
//     
// 	ASSERT_EQUAL(firstNode.GetNumChildren(),2);
// 	ASSERT_TRUE(firstNode.GetChild(0).IsNullPtr());
// 	ASSERT_TRUE(firstNode.GetChild(1).IsNullPtr());
//     ASSERT_EQUAL(index,1);
// 
// 	// Camera≤‚ ‘
// 	CameraSharedPtr secondCamera(new Camera(false, 1e-5f));
// 	firstNode.SetCamera(secondCamera);
// 
// 	ASSERT_EQUAL(secondCamera, firstNode.GetCamera());
}

void Rendering::CameraNodeTesting
	::CopyTest()
{
// 	CameraSharedPtr firstCamera(new Camera(true, 1e-5f));
// 	CameraNode firstNode(firstCamera);
// 
// 	ASSERT_EQUAL(firstNode.GetNumControllers(),0);
// 
// 	ControllerInterfaceSharedPtr secondNode(new Node);
// 
// 	ControllerInterfaceSharedPtr thirdNode(new Node);
// 	Node* firstPtr = CoreTools::StaticCast<Node>(secondNode.GetData());
// 
// 	ASSERT_EQUAL_NULL_PTR(thirdNode->GetControllerObject());
// 
// 	firstPtr->AttachController(thirdNode);
// 
// 	firstNode.AttachController(secondNode);
// 
// 	Transform firstTransform;
// 
// 	firstTransform.SetUniformScale(5.0f);
// 	firstPtr->SetLocalTransform(firstTransform);
//  
// 	ControllerInterfaceSharedPtr fourthNode(secondNode->Clone());
// 	SpatialTest* secondPtr = CoreTools::StaticCast<SpatialTest>(fourthNode.GetData());
// 
// 	Transform secondTransform;
// 	secondTransform.SetUniformScale(3.0f);
// 	secondPtr->SetLocalTransform(secondTransform);
// 
// 	ASSERT_APPROXIMATE(secondPtr->GetLocalTransform().GetUniformScale (),3.0f,1e-8f);
// 	ASSERT_APPROXIMATE(firstPtr->GetLocalTransform().GetUniformScale (),5.0f,1e-8f);
// 
// 	firstNode.AttachController(fourthNode);
// 
// 	ASSERT_EQUAL(firstNode.GetNumControllers(),2);
// 	ASSERT_EQUAL(firstNode.GetController(0), secondNode);
// 	ASSERT_EQUAL(firstNode.GetController(1), fourthNode);
// 
// 	secondNode->DetachController(thirdNode);
// 
// 	fourthNode->AttachController(thirdNode);
// 
// 	ASSERT_EQUAL(secondNode->GetNumControllers(),0);
// 	ASSERT_EQUAL(fourthNode->GetNumControllers(),2);
//     
//     // Child≤‚ ‘
//     SpatialSharedPtr fifthNode(new Node);
// 
// 	fifthNode->SetLocalTransform(secondTransform);
//     firstNode.AttachChild(fifthNode);
//     
// 	SpatialSharedPtr sixthNode(new Node);
//     
// 	sixthNode->SetLocalTransform(firstTransform);
//     firstNode.AttachChild(sixthNode);
//     
// 	ControllerInterfaceSharedPtr seventhNode(firstNode.Clone());
// 	Node* thirdPtr = CoreTools::StaticCast<Node>(seventhNode.GetData());
//     
// 	SpatialSharedPtr eighthNode = thirdPtr->GetChild(0);
// 	SpatialSharedPtr ninthNode = thirdPtr->GetChild(1);
//     
//     ASSERT_APPROXIMATE(eighthNode->GetLocalTransform().GetUniformScale (),3.0f,1e-8f);
// 	ASSERT_APPROXIMATE(ninthNode->GetLocalTransform().GetUniformScale (), 5.0f,1e-8f);
}

void Rendering::CameraNodeTesting
	::TransformTest()
{
// 	CameraSharedPtr firstCamera(new Camera(true, 1e-5f));
// 	CameraNode firstNode(firstCamera);
// 	ControllerInterfaceSharedPtr secondNode(new Node);
// 	firstNode.AttachController(secondNode);
// 
// 	Node* firstPtr = CoreTools::StaticCast<Node>(secondNode.GetData());
// 
// 	Transform firstTransform;
// 	firstTransform.SetUniformScale(5.0f);
// 
// 	Transform secondTransform;
// 	secondTransform.SetTranslate(Transform::APoint(5.0f,3.0f,5.6f));
// 
// 	firstNode.SetLocalTransform(firstTransform);
// 	firstPtr->SetLocalTransform(secondTransform);
// 	firstPtr->SetParent(&firstNode);
// 
// 	firstNode.Update();
// 
// 	ASSERT_TRUE(Approximate(firstNode.GetLocalTransform(),firstTransform,1e-8f));
// 	ASSERT_TRUE(Approximate(firstPtr->GetLocalTransform(),secondTransform,1e-8f));
// 
// 	ASSERT_TRUE(Approximate(firstNode.GetWorldTransform(),firstTransform,1e-8f));
// 	ASSERT_TRUE(Approximate(firstPtr->GetWorldTransform(), firstTransform * secondTransform,1e-8f));
//     
//     // Child≤‚ ‘
//     SpatialSharedPtr thirdNode(new Node);
//     
// 	thirdNode->SetLocalTransform(secondTransform);
// 	firstNode.AttachChild(thirdNode);
//     
//     firstNode.Update();
//     
// 	ASSERT_TRUE(Approximate(firstNode.GetLocalTransform(),firstTransform,1e-8f));
// 	ASSERT_TRUE(Approximate(thirdNode->GetLocalTransform(),secondTransform,1e-8f));
//     
// 	ASSERT_TRUE(Approximate(firstNode.GetWorldTransform(),firstTransform,1e-8f));
// 	ASSERT_TRUE(Approximate(thirdNode->GetWorldTransform(),firstTransform * secondTransform,1e-8f));  
}

void Rendering::CameraNodeTesting
 ::ChildTest()
{
//     CoreTools::OutTopLevel outTopLevel;
// 	CameraSharedPtr firstCamera(new Camera(true, 1e-5f));
// 
// 	CoreTools::ObjectInterfaceSharedPtr firstNode(new CameraNode(firstCamera));
//     
// 	firstNode->SetUniqueID(5);
//     
// 	outTopLevel.Insert(firstNode);
//     
// 	Node* secondNode = CoreTools::PolymorphicCast<Node>(firstNode.GetData());
//     
// 	Transform firstTransform;
// 	Transform secondTransform;
// 	Bound firstBound(Bound::APoint(0.2f,5.0f,3.0f),2.0f);
//     
// 	firstTransform.SetUniformScale(5.0f);
// 	secondTransform.SetUniformScale(3.0f);
//     
// 	secondNode->SetLocalTransform(firstTransform);
// 	secondNode->SetWorldTransform(secondTransform);
// 	secondNode->SetWorldBound(firstBound);
// 	secondNode->SetCullingMode(CullingMode::Always);
//     
// 	SpatialSharedPtr thirdNode(new Node);
// 	secondNode->AttachChild(thirdNode);
//     
// 	thirdNode->SetUniqueID(4);
//     
// 	SpatialSharedPtr fourthNode(new Node);
// 	secondNode->AttachChild(fourthNode);
//     
// 	fourthNode->SetUniqueID(3);
//     
// 	NodeSharedPtr fifthNode(new Node);
// 	secondNode->AttachChild(fifthNode);
//     
// 	fifthNode->SetUniqueID(2);
//     
// 	SpatialSharedPtr sixthNode(new Node);
// 	fifthNode->AttachChild(sixthNode);
//     
// 	sixthNode->SetUniqueID(1);
//     
// 	CoreTools::BufferOutStream outStream(outTopLevel);
//     
// 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr =
//     outStream.GetBufferOutStreamInformation();
//     
// 	CoreTools::BufferInStream inStream(fileBufferPtr);
//     
// 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
//     
// 	NodeSharedPtr seventhNode = inTopLevel[0].PolymorphicDowncastObjectSharedPtr<NodeSharedPtr>();
//     
// 	ASSERT_EQUAL(seventhNode->GetNumChildren(),3);
//     
// 	ASSERT_TRUE(Approximate(seventhNode->GetLocalTransform(),firstTransform,1e-8f));
// 	ASSERT_TRUE(Approximate(seventhNode->GetWorldTransform(),secondTransform,1e-8f));
// 	ASSERT_TRUE(Approximate(seventhNode->GetWorldBound(),firstBound,1e-8f));
// 	ASSERT_ENUM_EQUAL(seventhNode->GetCullingMode(),CullingMode::Always);
//     
// 	SpatialSharedPtr eighthNode = seventhNode->GetChild(0);
//     
// 	ASSERT_UNEQUAL_NULL_PTR(eighthNode);
//     
// 	SpatialSharedPtr ninthNode = seventhNode->GetChild(1);
//     
// 	ASSERT_UNEQUAL_NULL_PTR(ninthNode);
//     
// 	NodeSharedPtr tenthNode = seventhNode->GetChild(2).PolymorphicDowncastObjectSharedPtr<NodeSharedPtr>();
//     
// 	ASSERT_UNEQUAL_NULL_PTR(tenthNode);
//     
// 	ASSERT_EQUAL(tenthNode->GetNumChildren(),1);
//     
// 	SpatialSharedPtr eleventhNode = tenthNode->GetChild(0);
//     
// 	ASSERT_UNEQUAL_NULL_PTR(eleventhNode);
}

void Rendering::CameraNodeTesting
	::StreamTest()
{
// 	CoreTools::OutTopLevel outTopLevel;
// 
// 	CoreTools::ObjectInterfaceSharedPtr firstCamera(new Camera(true, 1e-5f));
// 	CameraSharedPtr ptr = firstCamera.PolymorphicDowncastObjectSharedPtr<CameraSharedPtr>();
// 	CoreTools::ObjectInterfaceSharedPtr firstNode(new CameraNode(ptr));
// 
// 	firstCamera->SetUniqueID(6);
// 	firstNode->SetUniqueID(5);
// 
// 	ptr->SetPosition(Camera::APoint(1.0f, 9.8f, 6.2f));
// 
// 	outTopLevel.Insert(firstCamera);
// 	outTopLevel.Insert(firstNode);
// 
// 	Node* secondNode = CoreTools::PolymorphicCast<Node>(firstNode.GetData());
// 
// 	Transform firstTransform;
// 	Transform secondTransform;
// 	Bound firstBound(Bound::APoint(0.2f,5.0f,3.0f),2.0f);	
// 
// 	firstTransform.SetUniformScale(5.0f);
// 	secondTransform.SetUniformScale(3.0f);
// 
// 	secondNode->SetLocalTransform(firstTransform);
// 	secondNode->SetWorldTransform(secondTransform);
// 	secondNode->SetWorldBound(firstBound);
// 	secondNode->SetCullingMode(CullingMode::Always);
// 
// 	ControllerInterfaceSharedPtr thirdNode(new Node);
// 	secondNode->AttachController(thirdNode);
// 
// 	thirdNode->SetUniqueID(4);
// 
// 	ControllerInterfaceSharedPtr fourthNode(new Node);
// 	secondNode->AttachController(fourthNode);
// 
// 	fourthNode->SetUniqueID(3);
// 
// 	ControllerInterfaceSharedPtr fifthNode(new Node);
// 	secondNode->AttachController(fifthNode);
// 
// 	fifthNode->SetUniqueID(2);
// 
// 	ControllerInterfaceSharedPtr sixthNode(new Node);
// 	fifthNode->AttachController(sixthNode);
// 
// 	sixthNode->SetUniqueID(1);
// 
// 	CoreTools::BufferOutStream outStream(outTopLevel);
// 
// 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr =  outStream.GetBufferOutStreamInformation();
//         
// 	CoreTools::BufferInStream inStream(fileBufferPtr);
//         
// 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
// 	
// 	CameraSharedPtr secondCamera = inTopLevel[0].PolymorphicDowncastObjectSharedPtr<CameraSharedPtr>();
// 	CameraNodeSharedPtr seventhNode = inTopLevel[1].PolymorphicDowncastObjectSharedPtr<CameraNodeSharedPtr>();
// 
// 	ASSERT_EQUAL(seventhNode->GetNumControllers(),3);
// 
// 	ASSERT_TRUE(Approximate(seventhNode->GetLocalTransform(),firstTransform,1e-8f));
// 	ASSERT_TRUE(Approximate(seventhNode->GetWorldTransform(),secondTransform,1e-8f));
// 	ASSERT_TRUE(Approximate(seventhNode->GetWorldBound(),firstBound,1e-8f));
// 	ASSERT_ENUM_EQUAL(seventhNode->GetCullingMode(),CullingMode::Always);
// 
// 	Node* eighthNode = CoreTools::DynamicCast<Node>(seventhNode->GetController(0).GetData());
// 
// 	ASSERT_UNEQUAL_NULL_PTR(eighthNode);
// 
// 	Node* ninthNode = CoreTools::DynamicCast<Node>(seventhNode->GetController(1).GetData());
// 
// 	ASSERT_UNEQUAL_NULL_PTR(ninthNode);
// 
// 	Node* tenthNode = CoreTools::DynamicCast<Node>(seventhNode->GetController(2).GetData());
// 
// 	ASSERT_UNEQUAL_NULL_PTR(tenthNode);
// 
// 	ASSERT_EQUAL(tenthNode->GetNumControllers(),1);
// 
// 	Node* eleventhNode = CoreTools::DynamicCast<Node>(tenthNode->GetController(0).GetData());
// 
// 	ASSERT_UNEQUAL_NULL_PTR(eleventhNode);
// 
// 	ASSERT_EQUAL(secondCamera, seventhNode->GetCamera());
// 
// 	ASSERT_APPROXIMATE(secondCamera->GetEpsilon(), ptr->GetEpsilon(), 1e-8f);
// 	ASSERT_EQUAL(secondCamera->IsPerspective(), ptr->IsPerspective());
// 	ASSERT_TRUE(Approximate(secondCamera->GetPosition(), ptr->GetPosition(), 1e-8f));
}
// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/06 16:40)

#include "BillboardNodeTesting.h"
#include "Rendering/Detail/BillboardNode.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"


UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, BillboardNodeTesting) 

void Rendering::BillboardNodeTesting
	::MainTest()
{ 
	CoreTools::InitTerm::ExecuteInitializers();

	CameraManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
	ASSERT_NOT_THROW_EXCEPTION_0(TransformTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

	CameraManager::Destroy();

	CoreTools::InitTerm::ExecuteTerminators();
}
 
void Rendering::BillboardNodeTesting
	::InitTest()
{
// 	CameraSharedPtr camera(new Camera);
// 	camera->SetAxes(Mathematics::AVectorf::sm_UnitX, Mathematics::AVectorf::sm_UnitY, Mathematics::AVectorf::sm_UnitZ);
// 
// 	BillboardNode firstNode(camera);
//  
//  	ASSERT_EQUAL(firstNode.GetNumControllers(),0);
//  
// 	ControllerInterfaceSharedPtr secondNode(new BillboardNode(camera));
// 	firstNode.AttachController(secondNode);
// 
// 	ASSERT_EQUAL(firstNode.GetNumControllers(),1);
// 	ASSERT_EQUAL(firstNode.GetController(0), secondNode);
// 
// 	ControllerInterfaceSharedPtr thirdNode(new BillboardNode(camera));
// 
// 	ASSERT_EQUAL_NULL_PTR(thirdNode->GetControllerObject());
// 
// 	firstNode.AttachController(thirdNode);
// 
// 	BillboardNode* ptr = CoreTools::StaticCast<BillboardNode>(thirdNode.GetData());
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
// 	SpatialSharedPtr fourthNode(new BillboardNode(camera));
//     
//     firstNode.AttachChild(fourthNode);
//     
//     ASSERT_EQUAL(firstNode.GetNumChildren(),1);
// 	ASSERT_EQUAL(firstNode.GetChild(0), fourthNode);
//     
// 	ptr = CoreTools::StaticCast<BillboardNode>(fourthNode.GetData());
//     
// 	ASSERT_EQUAL_NULL_PTR(ptr->GetControllerObject());
// 	ASSERT_EQUAL(ptr->GetParent(),&firstNode);
//     
// 	SpatialSharedPtr fifthNode(new BillboardNode(camera));
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
// 	// Billboard≤‚ ‘
// 	ASSERT_EQUAL(firstNode.GetCamera(),camera); 
// 
// 	CameraSharedPtr secondCamera(new Camera);
// 	firstNode.AlignTo(secondCamera);
// 
// 	ASSERT_EQUAL(firstNode.GetCamera(),secondCamera);
}

void Rendering::BillboardNodeTesting
	::CopyTest()
{
// 	CameraSharedPtr camera(new Camera);
// 	camera->SetAxes(Mathematics::AVectorf::sm_UnitX, Mathematics::AVectorf::sm_UnitY, Mathematics::AVectorf::sm_UnitZ);
// 	
// 	BillboardNode firstNode(camera);
// 
// 	ASSERT_EQUAL(firstNode.GetNumControllers(),0);
// 
// 	ControllerInterfaceSharedPtr secondNode(new BillboardNode(camera));
// 
// 	ControllerInterfaceSharedPtr thirdNode(new BillboardNode(camera));
// 	BillboardNode* firstPtr = CoreTools::StaticCast<BillboardNode>(secondNode.GetData());
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
// 	BillboardNode* secondPtr = CoreTools::StaticCast<BillboardNode>(fourthNode.GetData());
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
// 	SpatialSharedPtr fifthNode(new BillboardNode(camera));
// 
// 	fifthNode->SetLocalTransform(secondTransform);
//     firstNode.AttachChild(fifthNode);
//     
// 	SpatialSharedPtr sixthNode(new BillboardNode(camera));
//     
//     sixthNode->SetLocalTransform(firstTransform);
//     firstNode.AttachChild(sixthNode);
//     
//  	ControllerInterfaceSharedPtr seventhNode(firstNode.Clone());
// 	BillboardNode* thirdPtr = CoreTools::StaticCast<BillboardNode>(seventhNode.GetData());
//     
// 	SpatialSharedPtr eighthNode = thirdPtr->GetChild(0);
// 	SpatialSharedPtr ninthNode = thirdPtr->GetChild(1);
//     
//     ASSERT_APPROXIMATE(eighthNode->GetLocalTransform().GetUniformScale (),3.0f,1e-8f);
// 	ASSERT_APPROXIMATE(ninthNode->GetLocalTransform().GetUniformScale (), 5.0f,1e-8f);
}

void Rendering::BillboardNodeTesting
	::TransformTest()
{
// 	CameraSharedPtr camera(new Camera);
// 	camera->SetAxes(Mathematics::AVectorf::sm_UnitX, Mathematics::AVectorf::sm_UnitY, Mathematics::AVectorf::sm_UnitZ);
// 	camera->SetPosition(Mathematics::APointf(2.0f,1.0f,3.0f));
// 
// 	BillboardNode firstNode(camera);
// 	ControllerInterfaceSharedPtr secondNode(new BillboardNode(camera));
// 	firstNode.AttachController(secondNode);
// 
// 	BillboardNode* firstPtr = CoreTools::StaticCast<BillboardNode>(secondNode.GetData());
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
// 	firstNode.Update(); 
// 	
// 	Transform thirdTransform = firstTransform;
// 	Transform fourthTransform = firstTransform * secondTransform;
// 
// 	Mathematics::APointf modelPosition = thirdTransform.GetInverseTransform() * camera->GetPosition();
// 	Mathematics::APointf secondModelPosition = fourthTransform.GetInverseTransform() * camera->GetPosition();
// 		 
// 	float angle = Mathematics::FloatMath::ATan2(modelPosition[0], modelPosition[2]);
// 	Mathematics::Matrixf orient(Mathematics::AVectorf::sm_UnitY, angle);
// 
// 	float secondAngle = Mathematics::FloatMath::ATan2(secondModelPosition[0], secondModelPosition[2]);
// 	Mathematics::Matrixf secondOrient(Mathematics::AVectorf::sm_UnitY, secondAngle);
// 
// 	Mathematics::Matrixf rotate = thirdTransform.GetRotate() * orient;
// 	thirdTransform.SetRotate(rotate);
// 
// 	rotate = fourthTransform.GetRotate() * secondOrient;
// 	fourthTransform.SetRotate(rotate);
// 
// 	ASSERT_TRUE(Approximate(firstNode.GetLocalTransform(), firstTransform,1e-8f));
// 	ASSERT_TRUE(Approximate(firstPtr->GetLocalTransform(),secondTransform,1e-8f));
// 
// 	typedef bool(*TransformFunction)(const Transform& lhs, const Transform& rhs,const float epsilon);
// 
// 	TransformFunction transformFunction = Approximate;
// 
// 	ASSERT_APPROXIMATE_USE_FUNCTION(transformFunction,firstNode.GetWorldTransform(),thirdTransform,1e-8f);
// 	ASSERT_APPROXIMATE_USE_FUNCTION(transformFunction,firstPtr->GetWorldTransform(),fourthTransform,1e-8f);
// 
//     // Child≤‚ ‘
// 	SpatialSharedPtr thirdNode(new BillboardNode(camera));
//     
// 	thirdNode->SetLocalTransform(secondTransform);
// 	firstNode.AttachChild(thirdNode);
// 
//     firstNode.Update();
// 
// 	fourthTransform = thirdTransform * secondTransform;
// 
// 	secondModelPosition = fourthTransform.GetInverseTransform() * camera->GetPosition();
// 		 
// 	secondAngle = Mathematics::FloatMath::ATan2(secondModelPosition[0], secondModelPosition[2]);
// 	secondOrient = Mathematics::Matrixf(Mathematics::AVectorf::sm_UnitY, secondAngle);
//     rotate = fourthTransform.GetRotate() * secondOrient;
// 	fourthTransform.SetRotate(rotate);
//     
// 	ASSERT_TRUE(Approximate(firstNode.GetLocalTransform(),firstTransform,1e-8f));
// 	ASSERT_TRUE(Approximate(thirdNode->GetLocalTransform(),secondTransform,1e-8f));
//     
// 	ASSERT_APPROXIMATE_USE_FUNCTION(transformFunction,firstNode.GetWorldTransform(),thirdTransform,1e-8f);
// 	ASSERT_APPROXIMATE_USE_FUNCTION(transformFunction,thirdNode->GetWorldTransform(),fourthTransform,1e-8f); 
}
void Rendering::BillboardNodeTesting
	::StreamTest()
{
// 	CameraSharedPtr camera(new Camera);
// 	camera->SetAxes(Mathematics::AVectorf::sm_UnitX, Mathematics::AVectorf::sm_UnitY, Mathematics::AVectorf::sm_UnitZ);
// 	camera->SetPosition(Mathematics::APointf(2.0f,1.0f,3.0f));
// 
// 	CoreTools::OutTopLevel outTopLevel;
// 	CoreTools::ObjectInterfaceSharedPtr firstNode(new BillboardNode(camera));
// 
// 	firstNode->SetUniqueID(5);
// 
// 	outTopLevel.Insert(firstNode);
// 
// 	BillboardNode* secondNode = CoreTools::PolymorphicCast<BillboardNode>(firstNode.GetData());
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
// 	ControllerInterfaceSharedPtr thirdNode(new BillboardNode(camera));
// 	secondNode->AttachController(thirdNode);
// 
// 	thirdNode->SetUniqueID(4);
// 
// 	ControllerInterfaceSharedPtr fourthNode(new BillboardNode(camera));
// 	secondNode->AttachController(fourthNode);
// 
// 	fourthNode->SetUniqueID(3);
// 
// 	ControllerInterfaceSharedPtr fifthNode(new BillboardNode(camera));
// 	secondNode->AttachController(fifthNode);
// 
// 	fifthNode->SetUniqueID(2);
// 
// 	ControllerInterfaceSharedPtr sixthNode(new BillboardNode(camera));
// 	fifthNode->AttachController(sixthNode);
// 
// 	sixthNode->SetUniqueID(1);
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
// 	BillboardNodeSharedPtr seventhNode =
// 		inTopLevel[0].PolymorphicDowncastObjectSharedPtr<BillboardNodeSharedPtr>();
// 
// 	ASSERT_EQUAL(seventhNode->GetNumControllers(),3);
// 
// 	ASSERT_TRUE(Approximate(seventhNode->GetLocalTransform(),
// 	                        firstTransform,1e-8f));
// 	ASSERT_TRUE(Approximate(seventhNode->GetWorldTransform(),
// 	                        secondTransform,1e-8f));
// 	ASSERT_TRUE(Approximate(seventhNode->GetWorldBound(),firstBound,1e-8f));
// 	ASSERT_ENUM_EQUAL(seventhNode->GetCullingMode(),CullingMode::Always);
// 
// 	BillboardNode* eighthNode =
// 		CoreTools::DynamicCast<BillboardNode>(seventhNode->GetController(0).GetData());
// 
// 	ASSERT_UNEQUAL_NULL_PTR(eighthNode);
// 
// 	BillboardNode* ninthNode =
// 		CoreTools::DynamicCast<BillboardNode>(seventhNode->GetController(1).GetData());
// 
// 	ASSERT_UNEQUAL_NULL_PTR(ninthNode);
// 
// 	BillboardNode* tenthNode =
// 		CoreTools::DynamicCast<BillboardNode>
// 		(seventhNode->GetController(2).GetData());
// 
// 	ASSERT_UNEQUAL_NULL_PTR(tenthNode);
// 
// 	ASSERT_EQUAL(tenthNode->GetNumControllers(),1);
// 
// 	BillboardNode* eleventhNode =
// 		CoreTools::DynamicCast<BillboardNode>(tenthNode->GetController(0).GetData());
// 
// 	ASSERT_UNEQUAL_NULL_PTR(eleventhNode);
}
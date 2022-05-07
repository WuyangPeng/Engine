// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/06 16:43)

#include "DlodNodeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/Detail/DlodNode.h"
#include "Rendering/SceneGraph/CameraManager.h"

#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"

#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26414)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, DlodNodeTesting)

void Rendering::DlodNodeTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    CameraManager::Create();

    //ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TransformTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ChildTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    CameraManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::DlodNodeTesting::InitTest()
{
    auto firstNode = std::make_shared<DlodNode>(4);

    ASSERT_EQUAL(firstNode->GetNumControllers(), 0);

    ControllerInterfaceSharedPtr secondNode = SwitchNode::Create();
    firstNode->AttachController(secondNode);

    ASSERT_EQUAL(firstNode->GetNumControllers(), 1);
    ASSERT_EQUAL(firstNode->GetController(0), secondNode);

    ControllerInterfaceSharedPtr thirdNode = SwitchNode::Create();

    ASSERT_EQUAL_NULL_PTR(thirdNode->GetControllerObject());

    firstNode->AttachController(thirdNode);

    // 	SwitchNode* ptr = CoreTools::StaticCast<SwitchNode>(thirdNode.GetData());
    //
    // 	ASSERT_EQUAL(ptr->GetControllerObject(),&firstNode);
    // 	ASSERT_EQUAL_NULL_PTR(ptr->GetParent());
    //
    // 	ASSERT_EQUAL(firstNode->GetNumControllers(),2);
    // 	ASSERT_EQUAL(firstNode->GetController(0), secondNode);
    // 	ASSERT_EQUAL(firstNode->GetController(1), thirdNode);
    //
    // 	firstNode->DetachController(secondNode);
    //
    // 	ASSERT_EQUAL(firstNode->GetNumControllers(),1);
    // 	ASSERT_EQUAL(firstNode->GetController(0), thirdNode);
    //
    // 	firstNode->DetachAllControllers();
    //
    // 	ASSERT_EQUAL(firstNode->GetNumControllers(),0);
    //
    //     // Child≤‚ ‘
    // 	ASSERT_EQUAL(firstNode->GetNumChildren(),0);
    //
    // 	SpatialSharedPtr fourthNode(new SwitchNode);
    //
    //     firstNode->AttachChild(fourthNode);
    //
    //     ASSERT_EQUAL(firstNode->GetNumChildren(),1);
    // 	ASSERT_EQUAL(firstNode->GetChild(0), fourthNode);
    //
    // 	ptr = CoreTools::StaticCast<SwitchNode>(fourthNode.GetData());
    //
    // 	ASSERT_EQUAL_NULL_PTR(ptr->GetControllerObject());
    // 	ASSERT_EQUAL(ptr->GetParent(),&firstNode);
    //
    // 	SpatialSharedPtr fifthNode(new SwitchNode);
    //
    //     firstNode->AttachChild(fifthNode);
    //
    //     ASSERT_EQUAL(firstNode->GetNumChildren(),2);
    // 	ASSERT_EQUAL(firstNode->GetChild(0), fourthNode);
    //     ASSERT_EQUAL(firstNode->GetChild(1), fifthNode);
    //
    // 	SpatialSharedPtr sixthNode = firstNode->DetachChildAt(0);
    //
    // 	ASSERT_EQUAL(firstNode->GetNumChildren(),2);
    // 	ASSERT_TRUE(firstNode->GetChild(0).IsNullPtr());
    //     ASSERT_EQUAL(sixthNode, fourthNode);
    //     ASSERT_EQUAL(firstNode->GetChild(1), fifthNode);
    //
    //     int index = firstNode->DetachChild(fifthNode);
    //
    // 	ASSERT_EQUAL(firstNode->GetNumChildren(),2);
    // 	ASSERT_TRUE(firstNode->GetChild(0).IsNullPtr());
    // 	ASSERT_TRUE(firstNode->GetChild(1).IsNullPtr());
    //     ASSERT_EQUAL(index,1);
    //
    // 	// SwitchNode≤‚ ‘
    // 	ASSERT_EQUAL(firstNode->GetActiveChild(),System::EnumCastUnderlying(SwitchNodeType::InvalidChild));
    //
    // 	firstNode->SetActiveChild(0);
    // 	ASSERT_EQUAL(firstNode->GetActiveChild(), 0);
    //
    // 	firstNode->DisableAllChildren();
    //
    // 	ASSERT_EQUAL(firstNode->GetActiveChild(), System::EnumCastUnderlying(SwitchNodeType::InvalidChild));
}

void Rendering::DlodNodeTesting::CopyTest()
{
    // 	DlodNode firstNode(4);
    //
    // 	ASSERT_EQUAL(firstNode->GetNumControllers(),0);
    //
    // 	ControllerInterfaceSharedPtr secondNode(new SwitchNode);
    //
    // 	ControllerInterfaceSharedPtr thirdNode(new SwitchNode);
    // 	SwitchNode* firstPtr = CoreTools::StaticCast<SwitchNode>(secondNode.GetData());
    //
    // 	ASSERT_EQUAL_NULL_PTR(thirdNode->GetControllerObject());
    //
    // 	firstPtr->AttachController(thirdNode);
    //
    // 	firstNode->AttachController(secondNode);
    //
    // 	Transform firstTransform;
    //
    // 	firstTransform.SetUniformScale(5.0f);
    // 	firstPtr->SetLocalTransform(firstTransform);
    //
    // 	ControllerInterfaceSharedPtr fourthNode(secondNode->Clone());
    // 	SwitchNode* secondPtr = CoreTools::StaticCast<SwitchNode>(fourthNode.GetData());
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
    // 	firstNode->AttachController(fourthNode);
    //
    // 	ASSERT_EQUAL(firstNode->GetNumControllers(),2);
    // 	ASSERT_EQUAL(firstNode->GetController(0), secondNode);
    // 	ASSERT_EQUAL(firstNode->GetController(1), fourthNode);
    //
    // 	secondNode->DetachController(thirdNode);
    //
    // 	fourthNode->AttachController(thirdNode);
    //
    // 	ASSERT_EQUAL(secondNode->GetNumControllers(),0);
    // 	ASSERT_EQUAL(fourthNode->GetNumControllers(),2);
    //
    //     // Child≤‚ ‘
    // 	SpatialSharedPtr fifthNode(new SwitchNode);
    //
    // 	fifthNode->SetLocalTransform(secondTransform);
    //     firstNode->AttachChild(fifthNode);
    //
    // 	SpatialSharedPtr sixthNode(new SwitchNode);
    //
    //     sixthNode->SetLocalTransform(firstTransform);
    //     firstNode->AttachChild(sixthNode);
    //
    //  	ControllerInterfaceSharedPtr seventhNode(firstNode->Clone());
    // 	SwitchNode* thirdPtr = CoreTools::StaticCast<SwitchNode>(seventhNode.GetData());
    //
    // 	SpatialSharedPtr eighthNode = thirdPtr->GetChild(0);
    // 	SpatialSharedPtr ninthNode = thirdPtr->GetChild(1);
    //
    //     ASSERT_APPROXIMATE(eighthNode->GetLocalTransform().GetUniformScale (),
    // 		               3.0f,1e-8f);
    // 	ASSERT_APPROXIMATE(ninthNode->GetLocalTransform().GetUniformScale (),
    // 		               5.0f,1e-8f);
}

void Rendering::DlodNodeTesting::TransformTest()
{
    // 	DlodNode firstNode(4);
    // 	ControllerInterfaceSharedPtr secondNode(new SwitchNode);
    // 	firstNode->AttachController(secondNode);
    //
    // 	SwitchNode* firstPtr = CoreTools::StaticCast<SwitchNode>(secondNode.GetData());
    //
    // 	Transform firstTransform;
    // 	firstTransform.SetUniformScale(5.0f);
    //
    // 	Transform secondTransform;
    // 	secondTransform.SetTranslate(Transform::APoint(5.0f,3.0f,5.6f));
    //
    // 	firstNode->SetLocalTransform(firstTransform);
    // 	firstPtr->SetLocalTransform(secondTransform);
    // 	firstPtr->SetParent(&firstNode);
    //
    // 	firstNode->Update();
    //
    // 	ASSERT_TRUE(Approximate(firstNode->GetLocalTransform(),
    // 	                        firstTransform,1e-8f));
    // 	ASSERT_TRUE(Approximate(firstPtr->GetLocalTransform(),
    // 	                        secondTransform,1e-8f));
    //
    // 	ASSERT_TRUE(Approximate(firstNode->GetWorldTransform(),
    // 	                        firstTransform,1e-8f));
    // 	ASSERT_TRUE(Approximate(firstPtr->GetWorldTransform(),
    // 	                        firstTransform * secondTransform,1e-8f));
    //
    //     // Child≤‚ ‘
    // 	SpatialSharedPtr thirdNode(new SwitchNode);
    //
    // 	thirdNode->SetLocalTransform(secondTransform);
    // 	firstNode->AttachChild(thirdNode);
    //
    //     firstNode->Update();
    //
    // 	ASSERT_TRUE(Approximate(firstNode->GetLocalTransform(),
    // 	                        firstTransform,1e-8f));
    // 	ASSERT_TRUE(Approximate(thirdNode->GetLocalTransform(),
    // 	                        secondTransform,1e-8f));
    //
    // 	ASSERT_TRUE(Approximate(firstNode->GetWorldTransform(),
    // 	                        firstTransform,1e-8f));
    // 	ASSERT_TRUE(Approximate(thirdNode->GetWorldTransform(),
    // 	                        firstTransform * secondTransform,1e-8f));
}

void Rendering::DlodNodeTesting::ChildTest()
{
    //     CoreTools::OutTopLevel outTopLevel;
    // 	CoreTools::ObjectInterfaceSharedPtr firstNode(new DlodNode(4));
    //
    // 	firstNode->SetUniqueID(5);
    //
    // 	outTopLevel.Insert(firstNode);
    //
    // 	SwitchNode* secondNode = CoreTools::PolymorphicCast<SwitchNode>(firstNode->GetData());
    //
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
    // 	SpatialSharedPtr thirdNode(new SwitchNode);
    // 	secondNode->AttachChild(thirdNode);
    //
    // 	thirdNode->SetUniqueID(4);
    //
    // 	SpatialSharedPtr fourthNode(new SwitchNode);
    // 	secondNode->AttachChild(fourthNode);
    //
    // 	fourthNode->SetUniqueID(3);
    //
    // 	NodeSharedPtr fifthNode(new SwitchNode);
    // 	secondNode->AttachChild(fifthNode);
    //
    // 	fifthNode->SetUniqueID(2);
    //
    // 	SpatialSharedPtr sixthNode(new SwitchNode);
    // 	fifthNode->AttachChild(sixthNode);
    //
    // 	sixthNode->SetUniqueID(1);
    // 	secondNode->SetActiveChild(0);
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
    // 	SwitchNodeSharedPtr seventhNode =
    // 		inTopLevel[0].PolymorphicDowncastObjectSharedPtr<SwitchNodeSharedPtr>();
    //
    // 	ASSERT_EQUAL(seventhNode->GetActiveChild(), 0);
    //
    // 	ASSERT_EQUAL(seventhNode->GetNumChildren(),3);
    //
    // 	ASSERT_TRUE(Approximate(seventhNode->GetLocalTransform(),
    // 	                        firstTransform,1e-8f));
    // 	ASSERT_TRUE(Approximate(seventhNode->GetWorldTransform(),
    // 	                        secondTransform,1e-8f));
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
    // 	NodeSharedPtr tenthNode =
    // 		seventhNode->GetChild(2).PolymorphicDowncastObjectSharedPtr<NodeSharedPtr>();
    //
    // 	ASSERT_UNEQUAL_NULL_PTR(tenthNode);
    //
    // 	ASSERT_EQUAL(tenthNode->GetNumChildren(),1);
    //
    // 	SpatialSharedPtr eleventhNode = tenthNode->GetChild(0);
    //
    // 	ASSERT_UNEQUAL_NULL_PTR(eleventhNode);
}

void Rendering::DlodNodeTesting::StreamTest()
{
    // 	CoreTools::OutTopLevel outTopLevel;
    // 	CoreTools::ObjectInterfaceSharedPtr firstNode(new DlodNode(4));
    //
    // 	firstNode->SetUniqueID(5);
    //
    // 	outTopLevel.Insert(firstNode);
    //
    // 	SwitchNode* secondNode = CoreTools::PolymorphicCast<SwitchNode>(firstNode->GetData());
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
    // 	ControllerInterfaceSharedPtr thirdNode(new SwitchNode);
    // 	secondNode->AttachController(thirdNode);
    //
    // 	thirdNode->SetUniqueID(4);
    //
    // 	ControllerInterfaceSharedPtr fourthNode(new SwitchNode);
    // 	secondNode->AttachController(fourthNode);
    //
    // 	fourthNode->SetUniqueID(3);
    //
    // 	ControllerInterfaceSharedPtr fifthNode(new SwitchNode);
    // 	secondNode->AttachController(fifthNode);
    //
    // 	fifthNode->SetUniqueID(2);
    //
    // 	ControllerInterfaceSharedPtr sixthNode(new SwitchNode);
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
    // 	SwitchNodeSharedPtr seventhNode =
    // 		inTopLevel[0].PolymorphicDowncastObjectSharedPtr<SwitchNodeSharedPtr>();
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
    // 	SwitchNode* eighthNode =
    // 		CoreTools::DynamicCast<SwitchNode>(seventhNode->GetController(0).GetData());
    //
    // 	ASSERT_UNEQUAL_NULL_PTR(eighthNode);
    //
    // 	SwitchNode* ninthNode =
    // 		CoreTools::DynamicCast<SwitchNode>(seventhNode->GetController(1).GetData());
    //
    // 	ASSERT_UNEQUAL_NULL_PTR(ninthNode);
    //
    // 	SwitchNode* tenthNode =
    // 		CoreTools::DynamicCast<SwitchNode>
    // 		(seventhNode->GetController(2).GetData());
    //
    // 	ASSERT_UNEQUAL_NULL_PTR(tenthNode);
    //
    // 	ASSERT_EQUAL(tenthNode->GetNumControllers(),1);
    //
    // 	SwitchNode* eleventhNode =
    // 		CoreTools::DynamicCast<SwitchNode>(tenthNode->GetController(0).GetData());
    //
    // 	ASSERT_UNEQUAL_NULL_PTR(eleventhNode);
}
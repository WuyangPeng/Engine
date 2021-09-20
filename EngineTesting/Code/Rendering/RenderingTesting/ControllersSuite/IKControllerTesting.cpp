// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.3 (2019/09/06 09:27)

#include "IKControllerTesting.h"
#include "Rendering/DataTypes/Transform.h"
#include "Rendering/Controllers/IKController.h"
#include "Rendering/RenderingTesting/SceneGraphSuite/SpatialTest.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"


using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, IKControllerTesting) 

void Rendering::IKControllerTesting
	::MainTest()
{
	CoreTools::InitTerm::ExecuteInitializers();

	ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
	ASSERT_NOT_THROW_EXCEPTION_0(UpdateTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

	CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::IKControllerTesting
	::InitTest()
{
// 	vector<IKGoalSharedPtr> goals;
// 	vector<IKJointSharedPtr> joints;
// 
// 	for (int i = 0; i < 10; ++i )
// 	{
// 		SpatialSharedPtr target(new SpatialTest);
// 		Transform firstTransform;
// 		firstTransform.SetTranslate(Mathematics::APointf(1.0f * i, 2.0f * i, 3.0f * i));
// 		target->SetWorldTransform(firstTransform);
// 		
// 		SpatialSharedPtr effector(new SpatialTest);
// 		Transform secondTransform;
// 		secondTransform.SetTranslate(Mathematics::APointf(3.0f * i, 2.0f * i, 1.0f * i));
// 		effector->SetWorldTransform(secondTransform);
// 		
// 		IKGoalSharedPtr ikGoal(new IKGoal(target, effector, 2.0f));
// 
// 		goals.push_back(ikGoal);
// 	}
// 
// 	for (int i = 0; i < 5; ++i)
// 	{
// 		SpatialSharedPtr object(new SpatialTest);
// 		Transform thirdTransform;
// 		thirdTransform.SetTranslate(Mathematics::APointf(11.0f, 12.0f, 13.0f));
// 		object->SetWorldTransform(thirdTransform);
// 
// 		IKJointSharedPtr ikJoint(new IKJoint(object, goals));
// 
// 		joints.push_back(ikJoint);
// 	}
// 
// 	IKControllerSharedPtr ikController(new IKController(joints));
// 
// 	ASSERT_EQUAL(ikController->GetIterations(), 128);
// 	ASSERT_TRUE(ikController->IsOrderEndToRoot());
// 
// 	ikController->SetIterations(35);
// 	ASSERT_EQUAL(ikController->GetIterations(), 35);
// 
// 	ikController->SetOrderEndToRoot(false);
// 	ASSERT_FALSE(ikController->IsOrderEndToRoot());
// 
// 	ASSERT_EQUAL(ikController->GetJointsNum(), 5);
// 
// 	for (int i = 0; i < ikController->GetJointsNum();++i)
// 	{
// 		IKJointSharedPtr ikJoint = ikController->GetJointsSharedPtr(i);
// 
// 		ASSERT_EQUAL(ikJoint, joints[i]);		 
// 	}
}

void Rendering::IKControllerTesting
	::CopyTest()
{
// 	vector<IKGoalSharedPtr> goals;
// 	vector<IKJointSharedPtr> joints;
// 
// 	for (int i = 0; i < 10; ++i )
// 	{
// 		SpatialSharedPtr target(new SpatialTest);
// 		Transform firstTransform;
// 		firstTransform.SetTranslate(Mathematics::APointf(1.0f * i, 2.0f * i, 3.0f * i));
// 		target->SetWorldTransform(firstTransform);
// 		
// 		SpatialSharedPtr effector(new SpatialTest);
// 		Transform secondTransform;
// 		secondTransform.SetTranslate(Mathematics::APointf(3.0f * i, 2.0f * i, 1.0f * i));
// 		effector->SetWorldTransform(secondTransform);
// 		
// 		IKGoalSharedPtr ikGoal(new IKGoal(target, effector, 2.0f));
// 
// 		goals.push_back(ikGoal);
// 	}
// 
// 	for (int i = 0; i < 3; ++i)
// 	{
// 		SpatialSharedPtr object(new SpatialTest);
// 		Transform thirdTransform;
// 		thirdTransform.SetTranslate(Mathematics::APointf(11.0f, 12.0f, 13.0f));
// 		object->SetWorldTransform(thirdTransform);
// 
// 		IKJointSharedPtr ikJoint(new IKJoint(object, goals));
// 
// 		joints.push_back(ikJoint);
// 	}
// 
// 	IKControllerSharedPtr firstIKController(new IKController(joints));
// 
// 	IKControllerSharedPtr secondIKController(new IKController(*firstIKController.GetData()));
// 
// 	ASSERT_EQUAL(secondIKController->GetIterations(), 128);
// 	ASSERT_TRUE(secondIKController->IsOrderEndToRoot());
// 
// 	firstIKController->SetIterations(35);
// 	ASSERT_EQUAL(firstIKController->GetIterations(), 35);
// 	ASSERT_EQUAL(secondIKController->GetIterations(), 128);
// 
// 	firstIKController->SetOrderEndToRoot(false);
// 	ASSERT_FALSE(firstIKController->IsOrderEndToRoot());
// 	ASSERT_TRUE(secondIKController->IsOrderEndToRoot());
// 
// 	ASSERT_EQUAL(firstIKController->GetJointsNum(), secondIKController->GetJointsNum());
// 
// 	for (int i = 0; i < firstIKController->GetJointsNum();++i)
// 	{
// 	 	ASSERT_EQUAL(firstIKController->GetJointsSharedPtr(i), secondIKController->GetJointsSharedPtr(i));
// 	}
}

void Rendering::IKControllerTesting
	::UpdateTest()
{
// 	vector<IKGoalSharedPtr> goals;
// 	vector<IKJointSharedPtr> firstJoints;
// 	vector<IKJointSharedPtr> secondJoints;
// 
// 	for (int i = 0; i < 10; ++i )
// 	{
// 		SpatialSharedPtr target(new SpatialTest);
// 		Transform firstTransform;
// 		firstTransform.SetTranslate(Mathematics::APointf(1.0f * i, 2.0f * i, 3.0f * i));
// 		target->SetWorldTransform(firstTransform);
// 		
// 		SpatialSharedPtr effector(new SpatialTest);
// 		Transform secondTransform;
// 		secondTransform.SetTranslate(Mathematics::APointf(3.0f * i, 2.0f * i, 1.0f * i));
// 		effector->SetWorldTransform(secondTransform);
// 		
// 		IKGoalSharedPtr ikGoal(new IKGoal(target, effector, 2.0f));
// 
// 		goals.push_back(ikGoal);
// 	}
// 
// 	for (int i = 0; i < 3; ++i)
// 	{
// 		SpatialSharedPtr firstObject(new SpatialTest);
// 		Transform thirdTransform;
// 		thirdTransform.SetTranslate(Mathematics::APointf(11.0f, 12.0f, 13.0f));
// 		firstObject->SetWorldTransform(thirdTransform);
// 
// 		IKJointSharedPtr firstIKJoint(new IKJoint(firstObject, goals));
// 
// 		firstJoints.push_back(firstIKJoint);
// 
// 		SpatialSharedPtr secondObject(new SpatialTest);	 
// 		secondObject->SetWorldTransform(thirdTransform);
// 
// 		IKJointSharedPtr secondIKJoint(new IKJoint(secondObject, goals));
// 
// 		secondJoints.push_back(secondIKJoint);
// 	}
// 
// 	IKControllerSharedPtr firstIKController(new IKController(firstJoints));
// 	IKControllerSharedPtr secondIKController(new IKController(secondJoints));
// 
// 	int mNumJoints = firstIKController->GetJointsNum();
// 
// 	for (int index = 0; index < mNumJoints; ++index)
// 	{
// 		IKJointSharedPtr pointer = firstIKController->GetJointsSharedPtr(index);
// 		pointer->UpdateWorldTransform();
// 	}
// 
// 	// 更新joints一次一个，以满足目标。
// 	// 由于每个关节被更新，即联合之后出现在链中的节点joint必须在世界空间。
// 
// 	for (int iter = 0; iter < firstIKController->GetIterations(); ++iter)
// 	{
// 		for (int index = 0; index < mNumJoints; ++index)
// 		{
// 			int realIndex = index;
// 			if (firstIKController->IsOrderEndToRoot())
// 			{
// 				realIndex = mNumJoints - 1 - index;
// 			}
// 
// 			IKJointSharedPtr joint = firstIKController->GetJointsSharedPtr(realIndex);
// 
// 			for (Mathematics::MatrixRotationAxis axis = Mathematics::MatrixRotationAxis::X;
// 				axis < Mathematics::MatrixRotationAxis::Count;
// 				axis = static_cast<Mathematics::MatrixRotationAxis>(static_cast<int>(axis)+1))
// 			{
// 				if (joint->IsAllowTranslation(axis))
// 				{
// 					if (joint->UpdateLocalTranslate(axis))
// 					{
// 						for (int j = realIndex; j < mNumJoints; ++j)
// 						{
// 							IKJointSharedPtr joint1 = firstIKController->GetJointsSharedPtr(j);
// 							joint1->UpdateWorldRotateAndTranslate();
// 						}
// 					}
// 				}
// 			}
// 
// 			for (Mathematics::MatrixRotationAxis axis = Mathematics::MatrixRotationAxis::X;
// 				axis < Mathematics::MatrixRotationAxis::Count;
// 				axis = static_cast<Mathematics::MatrixRotationAxis>(static_cast<int>(axis)+1))
// 			{
// 				if (joint->IsAllowRotation(axis))
// 				{
// 					if (joint->UpdateLocalRotate(axis))
// 					{
// 						for (int j = realIndex; j < mNumJoints; ++j)
// 						{
// 							IKJointSharedPtr joint1 = firstIKController->GetJointsSharedPtr(j);
// 
// 							joint1->UpdateWorldRotateAndTranslate();
// 						}
// 					}
// 				}
// 			}
// 		}
// 	}
// 
// 	secondIKController->Update(0.0);
// 
// 	for (int i = 0; i < secondIKController->GetJointsNum(); ++i)
// 	{
// 		IKJointSharedPtr secondIKJoint = secondIKController->GetJointsSharedPtr(i);
// 		IKJointSharedPtr firstIKJoint = firstIKController->GetJointsSharedPtr(i);
// 
// 		ConstSpatialSharedPtr firstObject = firstIKJoint->GetObjectSharedPtr();
// 		ConstSpatialSharedPtr secondObject = secondIKJoint->GetObjectSharedPtr();
// 
// 		typedef bool(*TransformFunction)(const Transform& lhs, const Transform& rhs,
// 		                                 const float epsilon);
// 		
// 		TransformFunction transformFunction = Approximate;
// 
// 		ASSERT_APPROXIMATE_USE_FUNCTION(transformFunction, firstObject->GetLocalTransform(),secondObject->GetLocalTransform(),1e-8f);
// 		ASSERT_APPROXIMATE_USE_FUNCTION(transformFunction, firstObject->GetWorldTransform(),secondObject->GetWorldTransform(),1e-8f);
// 	}
}

void Rendering::IKControllerTesting
	::StreamTest()
{
// 	vector<IKGoalSharedPtr> goals;
// 	vector<IKJointSharedPtr> joints;
// 	CoreTools::OutTopLevel outTopLevel;
// 
// 	for (int i = 0; i < 10; ++i )
// 	{
// 		SpatialSharedPtr target(new SpatialTest);
// 		Transform firstTransform;
// 		firstTransform.SetTranslate(Mathematics::APointf(1.0f * i, 2.0f * i, 3.0f * i));
// 		target->SetWorldTransform(firstTransform);
// 		outTopLevel.Insert(target);
// 		
// 		SpatialSharedPtr effector(new SpatialTest);
// 		Transform secondTransform;
// 		secondTransform.SetTranslate(Mathematics::APointf(3.0f * i, 2.0f * i, 1.0f * i));
// 		effector->SetWorldTransform(secondTransform);
// 		outTopLevel.Insert(effector);
// 		
// 		IKGoalSharedPtr ikGoal(new IKGoal(target, effector, 2.0f));
// 		outTopLevel.Insert(ikGoal);
// 
// 		goals.push_back(ikGoal);
// 	}
// 
// 	for (int i = 0; i < 2; ++i)
// 	{
// 		SpatialSharedPtr object(new SpatialTest);
// 		Transform thirdTransform;
// 		thirdTransform.SetTranslate(Mathematics::APointf(11.0f, 12.0f, 13.0f));
// 		object->SetWorldTransform(thirdTransform);
// 		outTopLevel.Insert(object);
// 
// 		IKJointSharedPtr ikJoint(new IKJoint(object, goals));
// 		outTopLevel.Insert(ikJoint);
// 
// 		joints.push_back(ikJoint);
// 	}
// 
// 	IKControllerSharedPtr firstIKController(new IKController(joints));
// 	outTopLevel.Insert(firstIKController);
// 
// 	CoreTools::BufferOutStream outStream(outTopLevel);
// 
// 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr =
// 		outStream.GetBufferOutStreamInformation();
// 
// 	CoreTools::BufferInStream inStream(fileBufferPtr);
// 
// 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
// 
// 	IKControllerSharedPtr secondIKController = inTopLevel[inTopLevel.GetTopLevelSize() - 1].PolymorphicDowncastObjectSharedPtr<IKControllerSharedPtr>();
// 
// 	ASSERT_EQUAL(secondIKController->GetIterations(), firstIKController->GetIterations());
// 	ASSERT_EQUAL(secondIKController->IsOrderEndToRoot(), firstIKController->IsOrderEndToRoot());
// 	ASSERT_EQUAL(firstIKController->GetJointsNum(), secondIKController->GetJointsNum());
// 
// 	for (int i = 0; i < secondIKController->GetJointsNum(); ++i)
// 	{
// 		IKJointSharedPtr secondIKJoint = secondIKController->GetJointsSharedPtr(i);
// 		IKJointSharedPtr firstIKJoint = firstIKController->GetJointsSharedPtr(i);
// 
// 		ConstSpatialSharedPtr firstObject = firstIKJoint->GetObjectSharedPtr();
// 		ConstSpatialSharedPtr secondObject = secondIKJoint->GetObjectSharedPtr();
// 
// 		typedef bool(*TransformFunction)(const Transform& lhs, const Transform& rhs,const float epsilon);
// 
// 		TransformFunction transformFunction = Approximate;
// 
// 		ASSERT_APPROXIMATE_USE_FUNCTION(transformFunction, firstObject->GetLocalTransform(),secondObject->GetLocalTransform(),1e-8f);
// 		ASSERT_APPROXIMATE_USE_FUNCTION(transformFunction, firstObject->GetWorldTransform(),secondObject->GetWorldTransform(),1e-8f);
// 	}
}

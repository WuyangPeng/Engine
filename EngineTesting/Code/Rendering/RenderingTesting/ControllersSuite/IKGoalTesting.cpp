// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ²âÊÔ°æ±¾£º0.0.0.3 (2019/09/06 09:29)

#include "IKGoalTesting.h"
#include "Rendering/Controllers/IKGoal.h"
#include "Rendering/RenderingTesting/SceneGraphSuite/SpatialTest.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"


UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, IKGoalTesting) 

void Rendering::IKGoalTesting
	::MainTest()
{	 
	CoreTools::InitTerm::ExecuteInitializers();

	ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

	CoreTools::InitTerm::ExecuteTerminators();
}
#include SYSTEM_WARNING_DISABLE(26440)
void Rendering::IKGoalTesting
	::InitTest()
{
// 	SpatialSharedPtr target(new SpatialTest);
// 	Transform firstTransform;
// 	firstTransform.SetTranslate(Mathematics::APointf(1.0f,2.0f,3.0f));
// 	target->SetWorldTransform(firstTransform);
// 
// 	SpatialSharedPtr effector(new SpatialTest);
// 	Transform secondTransform;
// 	secondTransform.SetTranslate(Mathematics::APointf(3.0f,2.0f,1.0f));
// 	effector->SetWorldTransform(secondTransform);
// 
// 	IKGoal ikGoal(target,effector,2.0f);
// 
// 	typedef bool(*Function)(const Mathematics::APointf& lhs, const Mathematics::APointf& rhs,const float epsilon);
// 
// 	Function function = Mathematics::Approximate<float>;
// 
// 	ASSERT_EQUAL(ikGoal.GetTarget(),target.PolymorphicDowncastConstObjectSharedPtr<ConstSpatialSharedPtr>());
// 	ASSERT_EQUAL(ikGoal.GetEffector(),effector.PolymorphicDowncastConstObjectSharedPtr<ConstSpatialSharedPtr>());
// 
// 	ASSERT_APPROXIMATE(ikGoal.GetWeight(),2.0f,1e-8f);
// 
// 	ikGoal.SetWeight(3.0f);
// 	ASSERT_APPROXIMATE(ikGoal.GetWeight(),3.0f,1e-8f);
// 
// 	ASSERT_APPROXIMATE_USE_FUNCTION(function,ikGoal.GetEffectorPosition(),secondTransform.GetTranslate(),1e-8f);
// 	ASSERT_APPROXIMATE_USE_FUNCTION(function,ikGoal.GetTargetPosition(),firstTransform.GetTranslate(),1e-8f);
}

void Rendering::IKGoalTesting
	::CopyTest()
{
// 	SpatialSharedPtr target(new SpatialTest);
// 	Transform firstTransform;
// 	firstTransform.SetTranslate(Mathematics::APointf(1.0f,2.0f,3.0f));
// 	target->SetWorldTransform(firstTransform);
// 
// 	SpatialSharedPtr effector(new SpatialTest);
// 	Transform secondTransform;
// 	secondTransform.SetTranslate(Mathematics::APointf(3.0f,2.0f,1.0f));
// 	effector->SetWorldTransform(secondTransform);
// 
// 	IKGoal firstIKGoal(target,effector,2.0f);
// 
// 	IKGoal secondIKGoal = firstIKGoal;
// 
// 	secondIKGoal.SetWeight(3.0f);
// 
// 	typedef bool(*Function)(const Mathematics::APointf& lhs, const Mathematics::APointf& rhs,const float epsilon);
// 
// 	Function function = Mathematics::Approximate<float>;
// 
// 	ASSERT_EQUAL(secondIKGoal.GetTarget(),target.PolymorphicDowncastConstObjectSharedPtr<ConstSpatialSharedPtr>());
// 	ASSERT_EQUAL(secondIKGoal.GetEffector(),effector.PolymorphicDowncastConstObjectSharedPtr<ConstSpatialSharedPtr>());
// 
// 	ASSERT_APPROXIMATE(secondIKGoal.GetWeight(),3.0f,1e-8f);
// 
// 	ASSERT_APPROXIMATE_USE_FUNCTION(function,secondIKGoal.GetEffectorPosition(),secondTransform.GetTranslate(),1e-8f);
// 	ASSERT_APPROXIMATE_USE_FUNCTION(function,secondIKGoal.GetTargetPosition(),firstTransform.GetTranslate(),1e-8f);
}

void Rendering::IKGoalTesting
	::StreamTest()
{
// 	CoreTools::OutTopLevel outTopLevel;
// 	CoreTools::ObjectInterfaceSharedPtr target(new SpatialTest);	
// 
// 	target->SetUniqueID(5);	
// 
// 	Transform firstTransform;
// 	firstTransform.SetTranslate(Mathematics::APointf(1.0f,2.0f,3.0f));
// 	target.PolymorphicDowncastObjectSharedPtr<SpatialTestSharedPtr>()->SetWorldTransform(firstTransform);
// 	outTopLevel.Insert(target);
// 
// 	CoreTools::ObjectInterfaceSharedPtr effector(new SpatialTest);	
// 
// 	effector->SetUniqueID(4);	
// 
// 	Transform secondTransform;
// 	secondTransform.SetTranslate(Mathematics::APointf(3.0f,2.0f,1.0f));
// 	effector.PolymorphicDowncastObjectSharedPtr<SpatialTestSharedPtr>()->SetWorldTransform(secondTransform);
// 	outTopLevel.Insert(effector);
// 
// 	CoreTools::ObjectInterfaceSharedPtr firstIKGoal(new IKGoal(target.PolymorphicDowncastObjectSharedPtr<SpatialSharedPtr>(),effector.PolymorphicDowncastObjectSharedPtr<SpatialSharedPtr>(),2.0f));	
// 	firstIKGoal->SetUniqueID(3);
// 	outTopLevel.Insert(firstIKGoal);
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
// 	IKGoalSharedPtr secondIKGoal = inTopLevel[2].PolymorphicDowncastObjectSharedPtr<IKGoalSharedPtr>();
// 
// 	ASSERT_APPROXIMATE(secondIKGoal->GetWeight(),firstIKGoal.PolymorphicDowncastObjectSharedPtr<IKGoalSharedPtr>()->GetWeight(),1e-8f);
// 
// 	typedef bool(*Function)(const Mathematics::APointf& lhs, const Mathematics::APointf& rhs,const float epsilon);
// 
// 	Function function = Mathematics::Approximate<float>;
// 
// 	ASSERT_APPROXIMATE_USE_FUNCTION(function,secondIKGoal->GetEffectorPosition(),firstIKGoal.PolymorphicDowncastObjectSharedPtr<IKGoalSharedPtr>()->GetEffectorPosition(),1e-8f);
// 	ASSERT_APPROXIMATE_USE_FUNCTION(function,secondIKGoal->GetTargetPosition(),firstIKGoal.PolymorphicDowncastObjectSharedPtr<IKGoalSharedPtr>()->GetTargetPosition(),1e-8f);
// 	ASSERT_EQUAL(secondIKGoal->GetEffector(),inTopLevel[1]);
// 	ASSERT_EQUAL(secondIKGoal->GetTarget(),inTopLevel[0]);
}


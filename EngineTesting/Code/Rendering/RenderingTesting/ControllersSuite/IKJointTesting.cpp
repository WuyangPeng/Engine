// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/06 09:30)

#include "IKJointTesting.h"
#include "Rendering/Controllers/IKJoint.h"
#include "Rendering/RenderingTesting/SceneGraphSuite/SpatialTest.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"

#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/EulerDetail.h"
#include "Mathematics/Algebra/Matrix3Detail.h"

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, IKJointTesting) 

void Rendering::IKJointTesting
	::MainTest()
{	 
	CoreTools::InitTerm::ExecuteInitializers();

	ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
	ASSERT_NOT_THROW_EXCEPTION_0(UpdateTest);

	CoreTools::InitTerm::ExecuteTerminators();
}
#include SYSTEM_WARNING_DISABLE(26440)
void Rendering::IKJointTesting
	::InitTest()
{
// 	vector<IKGoalSharedPtr> goals;
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
// 	SpatialSharedPtr object(new SpatialTest);
// 	Transform thirdTransform;
// 	thirdTransform.SetTranslate(Mathematics::APointf(11.0f, 12.0f, 13.0f));
// 	object->SetWorldTransform(thirdTransform);
// 
// 	IKJointSharedPtr ikJoint(new IKJoint(object, goals));
// 
// 	ASSERT_EQUAL(ikJoint->GetObjectSharedPtr(), object);
// 	ASSERT_EQUAL(ikJoint->GetGoalsNum(),static_cast<int>( goals.size()));
// 
// 	for (int i = 0; i < ikJoint->GetGoalsNum(); ++i)
// 	{
// 		ASSERT_EQUAL(ikJoint->GetGoalsSharedPtr(i), goals[i]);
// 	}
	 
}

void Rendering::IKJointTesting
	::CopyTest()
{
// 	vector<IKGoalSharedPtr> goals;
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
// 	SpatialSharedPtr object(new SpatialTest);
// 	Transform thirdTransform;
// 	thirdTransform.SetTranslate(Mathematics::APointf(11.0f, 12.0f, 13.0f));
// 	object->SetWorldTransform(thirdTransform);
// 
// 	IKJointSharedPtr firstIKJoint(new IKJoint(object, goals));
// 	IKJointSharedPtr secondIKJoint(new IKJoint(*firstIKJoint.GetData()));
// 
// 	ASSERT_EQUAL(firstIKJoint->GetObjectSharedPtr(), secondIKJoint->GetObjectSharedPtr());
// 	ASSERT_EQUAL(firstIKJoint->GetGoalsNum(), secondIKJoint->GetGoalsNum());
// 	for (int i = 0; i < firstIKJoint->GetGoalsNum();++i)
// 	{
// 		ASSERT_EQUAL(firstIKJoint->GetGoalsSharedPtr(i), secondIKJoint->GetGoalsSharedPtr(i));
// 	}
}

void Rendering::IKJointTesting
	::StreamTest()
{
// 	CoreTools::OutTopLevel outTopLevel;
// 	vector<IKGoalSharedPtr> goals;
// 
// 	for (int i = 0; i < 10; ++i )
// 	{
// 		SpatialSharedPtr target(new SpatialTest);
// 		Transform firstTransform;
// 		firstTransform.SetTranslate(Mathematics::APointf(1.0f * i, 2.0f * i, 3.0f * i));
// 		target->SetWorldTransform(firstTransform);
// 
// 		outTopLevel.Insert(target.PolymorphicDowncastObjectSharedPtr<CoreTools::ObjectInterfaceSharedPtr>());
// 				
// 		SpatialSharedPtr effector(new SpatialTest);
// 		Transform secondTransform;
// 		secondTransform.SetTranslate(Mathematics::APointf(3.0f * i, 2.0f * i, 1.0f * i));
// 		effector->SetWorldTransform(secondTransform);
// 
// 		outTopLevel.Insert(effector.PolymorphicDowncastObjectSharedPtr<CoreTools::ObjectInterfaceSharedPtr>());
// 
// 		IKGoalSharedPtr ikGoal(new IKGoal(target, effector, 2.0f));
// 		outTopLevel.Insert(ikGoal.PolymorphicDowncastObjectSharedPtr<CoreTools::ObjectInterfaceSharedPtr>());
// 		
// 		goals.push_back(ikGoal);
// 	}
// 
// 	SpatialSharedPtr object(new SpatialTest);
// 	Transform thirdTransform;
// 	thirdTransform.SetTranslate(Mathematics::APointf(11.0f, 12.0f, 13.0f));
// 	object->SetWorldTransform(thirdTransform);
// 
// 	outTopLevel.Insert(object.PolymorphicDowncastObjectSharedPtr<CoreTools::ObjectInterfaceSharedPtr>());
// 
// 	IKJointSharedPtr firstIKJoint(new IKJoint(object, goals));	
// 	outTopLevel.Insert(firstIKJoint.PolymorphicDowncastObjectSharedPtr<CoreTools::ObjectInterfaceSharedPtr>());
// 		
// 	CoreTools::BufferOutStream outStream(outTopLevel);
// 
// 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr = outStream.GetBufferOutStreamInformation();
// 
// 	CoreTools::BufferInStream inStream(fileBufferPtr);
// 
// 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
// 
// 	IKJointSharedPtr secondIKJoint = inTopLevel[inTopLevel.GetTopLevelSize() - 1].PolymorphicDowncastObjectSharedPtr<IKJointSharedPtr>();
// 
// 	ASSERT_TRUE(secondIKJoint.IsValidPtr());
// 
// 	typedef bool(*Function)(const Transform& lhs, const Transform& rhs,
// 		                    const float epsilon);
// 
// 	Function function = Approximate;
// 
// 	ASSERT_APPROXIMATE_USE_FUNCTION(function,firstIKJoint->GetObjectSharedPtr()->GetWorldTransform(),secondIKJoint->GetObjectSharedPtr()->GetWorldTransform(),1e-8f);
// 
// 	ASSERT_EQUAL(firstIKJoint->GetGoalsNum(), secondIKJoint->GetGoalsNum());
// 
// 
// 	for (int i = 0; i < firstIKJoint->GetGoalsNum();++i)
// 	{
// 		ConstIKGoalSharedPtr lhsIKGoal = firstIKJoint->GetGoalsSharedPtr(i);
// 		ConstIKGoalSharedPtr rhsIKGoal = secondIKJoint->GetGoalsSharedPtr(i);
// 
// 		ASSERT_APPROXIMATE(lhsIKGoal->GetWeight(), rhsIKGoal->GetWeight(), 1e-8f);
// 
// 		typedef bool(*PointFunction)(const Mathematics::APointf& lhs, const Mathematics::APointf& rhs,const float epsilon);
// 
// 		PointFunction pointFunction = Mathematics::Approximate<float>;
// 		
// 		ASSERT_APPROXIMATE_USE_FUNCTION(pointFunction, lhsIKGoal->GetEffectorPosition(), rhsIKGoal->GetEffectorPosition(), 1e-8f);
// 		ASSERT_APPROXIMATE_USE_FUNCTION(pointFunction, lhsIKGoal->GetTargetPosition(), rhsIKGoal->GetTargetPosition(), 1e-8f);
// 	}
}

void Rendering::IKJointTesting
	::UpdateTest()
{
// 	vector<IKGoalSharedPtr> goals;
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
// 	SpatialSharedPtr object(new SpatialTest);
// 	Transform thirdTransform;
// 	thirdTransform.SetTranslate(Mathematics::APointf(11.0f, 12.0f, 13.0f));
// 	object->SetWorldTransform(thirdTransform);
// 
// 	IKJointSharedPtr firstIKJoint(new IKJoint(object, goals));
// 
// 	// GetAxis≤‚ ‘
// 	SpatialSharedPtr parentObject(new SpatialTest);
// 	Transform fourthTransform;
// 	fourthTransform.SetTranslate(Mathematics::APointf(21.0f, 22.0f, 23.0f));
// 	fourthTransform.SetRotate(Mathematics::Matrixf(Mathematics::AVectorf::sm_UnitZ, 3.0f));
// 	parentObject->SetWorldTransform(fourthTransform);
// 
// 	typedef bool(*PointFunction)(const Mathematics::AVectorf& lhs, const Mathematics::AVectorf& rhs,const float epsilon);
// 	
// 	PointFunction pointFunction = Mathematics::Approximate<float>;
// 
// 	ASSERT_APPROXIMATE_USE_FUNCTION(pointFunction, firstIKJoint->GetAxis(Mathematics::MatrixRotationAxis::X),
// 		                            Mathematics::AVectorf::sm_UnitX,1e-8f);
// 	ASSERT_APPROXIMATE_USE_FUNCTION(pointFunction, firstIKJoint->GetAxis(Mathematics::MatrixRotationAxis::Y),
// 		                            Mathematics::AVectorf::sm_UnitY,1e-8f);
// 	ASSERT_APPROXIMATE_USE_FUNCTION(pointFunction, firstIKJoint->GetAxis(Mathematics::MatrixRotationAxis::Z),
// 		                            Mathematics::AVectorf::sm_UnitZ,1e-8f);
// 
// 	typedef bool(*TransformFunction)(const Transform& lhs, const Transform& rhs,const float epsilon);
// 
// 	TransformFunction transformFunction = Approximate;
// 
// 	// UpdateWorldTransform≤‚ ‘
// 	Transform fifthTransform;
// 	thirdTransform.SetTranslate(Mathematics::APointf(31.0f, 32.0f, 33.0f));
// 	thirdTransform.SetRotate(Mathematics::Matrixf(Mathematics::AVectorf::sm_UnitY, 3.0f));
// 	thirdTransform.SetScale(Mathematics::APointf(2.0f, 1.0f, 0.5f));
// 	object->SetLocalTransform(fifthTransform);
// 
// 	firstIKJoint->UpdateWorldTransform();
// 	ASSERT_APPROXIMATE_USE_FUNCTION(transformFunction, object->GetWorldTransform(), fifthTransform, 1e-8f);
// 
// 	// UpdateWorldRotateAndTranslate≤‚ ‘
// 	Transform sixthTransform;
// 	sixthTransform.SetTranslate(Mathematics::APointf(41.0f, 42.0f, 43.0f));
// 	sixthTransform.SetRotate(Mathematics::Matrixf(Mathematics::AVectorf::sm_UnitX,4.0f));
// 	sixthTransform.SetScale(Mathematics::APointf(1.0f, 2.0f, 1.5f));
// 
// 	Transform worldTransform = object->GetWorldTransform();
// 	object->SetLocalTransform(sixthTransform);
// 	object->SetWorldTransform(worldTransform);
// 	firstIKJoint->UpdateWorldRotateAndTranslate();
// 
// 	ASSERT_TRUE(Approximate(object->GetWorldTransform().GetTranslate(), sixthTransform.GetTranslate(), 1e-8f));
// 	ASSERT_TRUE(Approximate(object->GetWorldTransform().GetRotate(), sixthTransform.GetRotate(), 1e-8f));
// 	ASSERT_FALSE(transformFunction(object->GetWorldTransform(), sixthTransform, 1e-8f));
// 	ASSERT_TRUE(Approximate(object->GetWorldTransform().GetScale(), worldTransform.GetScale(), 1e-8f));
// 	
// 	object->SetParent(parentObject.GetData());
// 
// 	// GetAxis≤‚ ‘
// 	ASSERT_APPROXIMATE_USE_FUNCTION(pointFunction, firstIKJoint->GetAxis(Mathematics::MatrixRotationAxis::X),
// 		                            Mathematics::AVectorf(parentObject->GetWorldTransform().GetRotate().GetColumn(System::EnumCastUnderlying(Mathematics::MatrixRotationAxis::X))),1e-8f);
// 	ASSERT_APPROXIMATE_USE_FUNCTION(pointFunction, firstIKJoint->GetAxis(Mathematics::MatrixRotationAxis::Y),
// 		                            Mathematics::AVectorf(parentObject->GetWorldTransform().GetRotate().GetColumn(System::EnumCastUnderlying(Mathematics::MatrixRotationAxis::Y))),1e-8f);
// 	ASSERT_APPROXIMATE_USE_FUNCTION(pointFunction, firstIKJoint->GetAxis(Mathematics::MatrixRotationAxis::Z),
// 		                            Mathematics::AVectorf(parentObject->GetWorldTransform().GetRotate().GetColumn(System::EnumCastUnderlying(Mathematics::MatrixRotationAxis::Z))),1e-8f);
// 
// 	// UpdateWorldTransform≤‚ ‘
// 	object->SetLocalTransform(fifthTransform);
// 
// 	firstIKJoint->UpdateWorldTransform();
// 	ASSERT_APPROXIMATE_USE_FUNCTION(transformFunction, object->GetWorldTransform(), parentObject->GetWorldTransform() * fifthTransform, 1e-8f);
// 
// 
// 	// UpdateWorldRotateAndTranslate≤‚ ‘
// 	worldTransform = object->GetWorldTransform();
// 	object->SetLocalTransform(sixthTransform);
// 	object->SetWorldTransform(worldTransform);
// 	firstIKJoint->UpdateWorldRotateAndTranslate();
// 
// 	ASSERT_TRUE(Approximate(object->GetWorldTransform().GetTranslate(), parentObject->GetWorldTransform() * sixthTransform.GetTranslate(), 1e-8f));
// 	ASSERT_TRUE(Approximate(object->GetWorldTransform().GetRotate(), parentObject->GetWorldTransform().GetRotate() *  sixthTransform.GetRotate(), 1e-8f));
// 	ASSERT_FALSE(transformFunction(object->GetWorldTransform(), parentObject->GetWorldTransform() * sixthTransform, 1e-8f));
// 	ASSERT_TRUE(Approximate(object->GetWorldTransform().GetScale(), worldTransform.GetScale(), 1e-8f));
// 
// 	// UpdateLocalTranslate≤‚ ‘
// 	Mathematics::AVectorf axis = firstIKJoint->GetAxis(Mathematics::MatrixRotationAxis::X);
// 	
// 	float oldNorm = 0.0f;
// 	float numer = 0.0f;
// 	float denom = 0.0f;
// 	for(const IKGoalSharedPtr& goal: goals)
// 	{
// 		Mathematics::AVectorf goalMinusEffector = goal->GetTargetPosition() - goal->GetEffectorPosition();
// 		oldNorm += goalMinusEffector.SquaredLength();
// 		numer += goal->GetWeight() * Dot(axis, goalMinusEffector);
// 		denom += goal->GetWeight();
// 	} 
// 
// 	float distance = numer / denom;
// 
// 	Mathematics::APointf translate = object->GetLocalTransform().GetTranslate();
// 	float desired = translate[System::EnumCastUnderlying(Mathematics::MatrixRotationAxis::X)] + distance;
// 	if (-Mathematics::MathF::maxReal < desired)
// 	{
// 		if (desired < Mathematics::MathF::maxReal)
// 		{
// 			translate[System::EnumCastUnderlying(Mathematics::MatrixRotationAxis::X)] = desired;
// 		}
// 		else
// 		{
// 			distance = Mathematics::MathF::maxReal - translate[System::EnumCastUnderlying(Mathematics::MatrixRotationAxis::X)];
// 			translate[System::EnumCastUnderlying(Mathematics::MatrixRotationAxis::X)] = Mathematics::MathF::maxReal;
// 		}
// 	}
// 	else
// 	{
// 		distance = -Mathematics::MathF::maxReal - translate[System::EnumCastUnderlying(Mathematics::MatrixRotationAxis::X)];
// 		translate[System::EnumCastUnderlying(Mathematics::MatrixRotationAxis::X)] = -Mathematics::MathF::maxReal;
// 	}
// 
// 	float newNorm = 0.0f;
// 	Mathematics::AVectorf step = distance * axis;
// 	for(const IKGoalSharedPtr& goal: goals)
// 	{
// 		Mathematics::APointf newEffector = goal->GetEffectorPosition() + step;
// 		Mathematics::AVectorf difference = goal->GetTargetPosition() - newEffector;
// 		newNorm += difference.SquaredLength();
// 	}
// 
// 	if (newNorm < oldNorm)
// 	{
// 		firstIKJoint->UpdateLocalTranslate(Mathematics::MatrixRotationAxis::X);
//  		ASSERT_TRUE(Approximate(object->GetLocalTransform().GetTranslate(), translate, 1e-8f));
// 	}
// 	
// 	// UpdateLocalRotate≤‚ ‘
// 	axis = firstIKJoint->GetAxis(Mathematics::MatrixRotationAxis::Y);
// 
// 	numer = 0.0f;
// 	denom = 0.0f;
// 	oldNorm = 0.0f;
// 
// 	for (const IKGoalSharedPtr& goal: goals)
// 	{
// 		Mathematics::AVectorf effectorMinusPoint = goal->GetEffectorPosition() - object->GetWorldTransform().GetTranslate();
// 		Mathematics::AVectorf goalMinusPoint = goal->GetTargetPosition() - object->GetWorldTransform().GetTranslate();
// 		Mathematics::AVectorf goalMinusEffector = goal->GetTargetPosition() - goal->GetEffectorPosition();
// 		oldNorm += goalMinusEffector.SquaredLength();
// 		Mathematics::AVectorf axisCrossEffectorMinusPoint = Cross(axis, effectorMinusPoint);
// 		Mathematics::AVectorf axisCrossAxisCrossEffectorMinusPoint = Cross(axis, axisCrossEffectorMinusPoint);
// 		numer += goal->GetWeight() * Dot(goalMinusPoint, axisCrossEffectorMinusPoint);
// 		denom -= goal->GetWeight() * Dot(goalMinusPoint, axisCrossAxisCrossEffectorMinusPoint);
// 	} 
// 
// 	float theta = Mathematics::MathF::ATan2(numer, denom);
// 
// 	Mathematics::Matrixf rotate = object->GetLocalTransform().GetRotate();
// 	Mathematics::Matrix3f rotateMatrix3 = rotate.GetMatrix3();
// 	Mathematics::Eulerf euler = rotateMatrix3.ExtractEulerZYX();
// 
// 	// Ωÿ∂œµΩ∑∂Œß
// 	desired = euler.GetAngle(Mathematics::MatrixRotationAxis::Y) + theta;
// 	if (-Mathematics::MathF::sm_PI < desired)
// 	{
// 		if (desired < Mathematics::MathF::sm_PI)
// 		{
// 			euler.SetAngle(Mathematics::MatrixRotationAxis::Y, desired);
// 		}
// 		else
// 		{
// 			theta = Mathematics::MathF::sm_PI - euler.GetAngle(Mathematics::MatrixRotationAxis::Y);
// 			euler.SetAngle(Mathematics::MatrixRotationAxis::Y, Mathematics::MathF::sm_PI);
// 		}
// 	}
// 	else
// 	{
// 		theta = -Mathematics::MathF::sm_PI - euler.GetAngle(Mathematics::MatrixRotationAxis::Y);
// 		euler.SetAngle(Mathematics::MatrixRotationAxis::Y, -Mathematics::MathF::sm_PI);
// 	}
// 
// 	// ≤‚ ‘≤Ω÷Ë «∑Ò”¶∏√≤…»°°£
// 	newNorm = 0.0f;
// 	rotate.MakeRotation(axis, theta);
// 	for(const IKGoalSharedPtr& goal: goals)
// 	{
// 		Mathematics::AVectorf effectorMinusPoint = goal->GetEffectorPosition() - object->GetWorldTransform().GetTranslate();
// 		Mathematics::APointf newEffector = object->GetWorldTransform().GetTranslate() + rotate * effectorMinusPoint;
// 		Mathematics::AVectorf goalMinusEffector = goal->GetTargetPosition() - newEffector;
// 		newNorm += goalMinusEffector.SquaredLength();
// 	}
// 
// 	if (newNorm < oldNorm)
// 	{
// 		rotateMatrix3.MakeEulerZYX(euler.GetZ0Angle(), euler.GetY0Angle(), euler.GetX0Angle());
// 		rotate = Mathematics::Matrixf(rotateMatrix3);
// 
// 		firstIKJoint->UpdateLocalRotate(Mathematics::MatrixRotationAxis::Y);
// 		ASSERT_TRUE(Approximate(object->GetLocalTransform().GetRotate(), rotate, 1e-8f));
// 	}
}


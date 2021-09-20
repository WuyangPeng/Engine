// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/25 0:52)

#include "ObjectMotionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  

#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Rendering/SceneGraph/Node.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Framework/Application/ObjectMotion.h"

#include <random>

using std::uniform_int;
using std::uniform_real;
using std::default_random_engine;

namespace Framework
{
	using TestingType = ObjectMotion;
}

Framework::ObjectMotionTesting
	::ObjectMotionTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ObjectMotionTesting)

void Framework::ObjectMotionTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::ObjectMotionTesting
	::MainTest()
{
	Rendering::CameraManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(NoParentMoveObjectTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ParentMoveObjectTest);
	ASSERT_NOT_THROW_EXCEPTION_0(TrackBallDownTest);
	ASSERT_NOT_THROW_EXCEPTION_0(NoParentRotateTrackBallTest);	
	ASSERT_NOT_THROW_EXCEPTION_0(ParentRotateTrackBallTest);

	Rendering::CameraManager::Destroy();
}

void Framework::ObjectMotionTesting
	::NoParentMoveObjectTest()
{
// 	Rendering::SpatialSmartPointer motionObject{ CoreTools::New0<Rendering::Node>() };
// 
// 	TestingType objectMotion{ motionObject }; 
// 	objectMotion.SetTrackBallDow(false);
// 
// 	default_random_engine generator{ GetEngineRandomSeed() };
// 	const uniform_int<> random{ -2, 3 };
// 	const uniform_int<> selectRandom{ 0, 2 };
// 	const uniform_int<> speedRandom{ 0, 3 };
// 
// 	ASSERT_FALSE(objectMotion.MoveObject(2.0f));
// 
// 	const auto testLoopCount = GetTestLoopCount();
// 	for (auto i = 0; i < testLoopCount; ++i)
// 	{
// 		const auto rotationSpeed = speedRandom(generator);
// 
// 		const auto select = selectRandom(generator);
// 
// 		auto value = random(generator);
// 
// 		if (value <= 0)
// 		{
// 			value -= 1;
// 		}
// 
// 		AVectorf axis{ };
// 		switch (select)
// 		{
// 		case 0:
// 		{
// 			objectMotion.SetDoRoll(value);
// 			objectMotion.SetDoYaw(0);
// 			objectMotion.SetDoPitch(0);
// 			axis = AVectorf::sm_UnitX;
// 		}
// 		break;
// 		case 1:
// 		{
// 			objectMotion.SetDoRoll(0);
// 			objectMotion.SetDoYaw(value);
// 			objectMotion.SetDoPitch(0);
// 			axis = AVectorf::sm_UnitY;
// 		}
// 		break;
// 		case 2:
// 		{
// 			objectMotion.SetDoRoll(0);
// 			objectMotion.SetDoYaw(0);
// 			objectMotion.SetDoPitch(value);
// 			axis = AVectorf::sm_UnitZ;
// 		}
// 		break;
// 		default:
// 			break;
// 		}	
// 
// 		auto rotate = motionObject->GetLocalTransform().GetRotate();
// 		auto angle = value * rotationSpeed;	
// 
// 		const Matrixf incr{ axis, boost::numeric_cast<float>(angle) };
// 		rotate = incr * rotate;
// 		rotate.Orthonormalize(); 
// 		
// 		ASSERT_TRUE(objectMotion.MoveObject(boost::numeric_cast<float>(rotationSpeed)));
// 
// 		AssertRotate(rotate, motionObject->GetLocalTransform().GetRotate());
// 	}
}

void Framework::ObjectMotionTesting
	::ParentMoveObjectTest()
{
// 	Rendering::SpatialSmartPointer motionObject{ CoreTools::New0<Rendering::Node>() };
// 	Rendering::NodeSmartPointer parentMotionObject{ CoreTools::New0<Rendering::Node>() };
// 	parentMotionObject->AttachChild(motionObject);
// 
// 	Rendering::Transform Transform{ }; 
// 	const Matrixf matrix{ AVectorf::sm_UnitZ,Mathematics::FloatMath::sm_QuarterPI };
// 	Transform.SetRotate(matrix);
// 
// 	parentMotionObject->SetWorldTransform(Transform);
// 
// 	TestingType objectMotion{ motionObject };
// 	objectMotion.SetTrackBallDow(false);
// 
// 	default_random_engine generator{ GetEngineRandomSeed() };
// 	const uniform_int<> random{ -2, 3 };
// 	const uniform_int<> selectRandom{ 0, 2 };
// 	const uniform_int<> speedRandom{ 0, 3 };
// 
// 	ASSERT_FALSE(objectMotion.MoveObject(2.0f));
// 
// 	const auto testLoopCount = GetTestLoopCount();
// 	for (auto i = 0; i < testLoopCount; ++i)
// 	{
// 		const auto rotationSpeed = speedRandom(generator);
// 
// 		const auto select = selectRandom(generator);
// 
// 		auto value = random(generator);
// 
// 		if (value <= 0)
// 		{
// 			value -= 1;
// 		}
// 
// 		AVectorf axis{ };
// 		switch (select)
// 		{
// 		case 0:
// 		{
// 			objectMotion.SetDoRoll(value);
// 			objectMotion.SetDoYaw(0);
// 			objectMotion.SetDoPitch(0);
// 			axis = parentMotionObject->GetWorldTransform().GetRotate().GetColumn(0);
// 		}
// 		break;
// 		case 1:
// 		{
// 			objectMotion.SetDoRoll(0);
// 			objectMotion.SetDoYaw(value);
// 			objectMotion.SetDoPitch(0);
// 			axis = parentMotionObject->GetWorldTransform().GetRotate().GetColumn(1);
// 		}
// 		break;
// 		case 2:
// 		{
// 			objectMotion.SetDoRoll(0);
// 			objectMotion.SetDoYaw(0);
// 			objectMotion.SetDoPitch(value);
// 			axis = parentMotionObject->GetWorldTransform().GetRotate().GetColumn(2);
// 		}
// 		break;
// 		default:
// 			break;
// 		}
// 
// 		auto rotate = motionObject->GetLocalTransform().GetRotate();
// 		auto angle = value * rotationSpeed;
// 
// 		const Matrixf incr{ axis, boost::numeric_cast<float>(angle) };
// 		rotate = incr * rotate;
// 		rotate.Orthonormalize();
// 
// 		ASSERT_TRUE(objectMotion.MoveObject(boost::numeric_cast<float>(rotationSpeed)));
// 
// 		AssertRotate(rotate, motionObject->GetLocalTransform().GetRotate());
// 	}
}

void Framework::ObjectMotionTesting
	::TrackBallDownTest()
{
// 	Rendering::SpatialSmartPointer motionObject{ CoreTools::New0<Rendering::Node>() };
// 
// 	TestingType objectMotion{ motionObject };
// 	ASSERT_FALSE(objectMotion.GetTrackBallDow());
// 
// 	objectMotion.SetTrackBallDow(true);
// 	ASSERT_TRUE(objectMotion.GetTrackBallDow());
// 
// 	objectMotion.SetTrackBallDow(false);
// 	ASSERT_FALSE(objectMotion.GetTrackBallDow());	
}

void Framework::ObjectMotionTesting	
	::NoParentRotateTrackBallTest()
{
// 	Rendering::SpatialSmartPointer motionObject{ CoreTools::New0<Rendering::Node>() };
// 	Rendering::CameraSmartPointer camera{ CoreTools::New0<Rendering::Camera>() };	
// 
// 	camera->SetAxes(AVectorf::sm_UnitY, AVectorf::sm_UnitZ, AVectorf::sm_UnitX);
// 
// 	TestingType objectMotion{ motionObject };
// 
// 	default_random_engine generator{ GetEngineRandomSeed() };
// 	const uniform_real<float> random{ 0.0f, 100.0f };
// 
// 	const auto testLoopCount = GetTestLoopCount();
// 	for (auto i = 0; i < testLoopCount; ++i)
// 	{
// 		auto xTrackBegin = random(generator);
// 		auto yTrackBegin = random(generator);
// 		auto xTrackEnd = random(generator);
// 		auto yTrackEnd = random(generator);
// 
// 		objectMotion.SetBeginTrack(xTrackBegin, yTrackBegin);
// 		objectMotion.SetEndTrack(xTrackEnd, yTrackEnd);
// 		objectMotion.SetSaveRotate(); 
// 
// 		const auto rotate = motionObject->GetLocalTransform().GetRotate();
// 
// 		auto vecBegin = GetSphereVector(xTrackBegin, yTrackBegin);
// 		auto vecEnd = GetSphereVector(xTrackEnd, yTrackEnd); 
//    
// 		auto axis = Cross(vecBegin, vecEnd);
// 		const auto dot = Dot(vecBegin, vecEnd);
// 		auto angle = 0.0f;
// 		if (!axis.IsZero())
// 		{
// 			axis.Normalize();
// 			angle = Mathematics::FloatMath::ACos(dot);
// 		}
// 		else  
// 		{
// 			if (dot < 0.0f)
// 			{				 
// 				auto invLength = Mathematics::FloatMath::InvSqrt(xTrackBegin * xTrackBegin + yTrackBegin * yTrackBegin);
// 				axis[0] = yTrackBegin * invLength;
// 				axis[1] = -xTrackBegin * invLength;
// 				axis[2] = 0.0f;
// 				angle = Mathematics::FloatMath::sm_PI;
// 			}
// 			else
// 			{ 
// 				axis = AVectorf::sm_UnitX;
// 				angle = 0.0f;
// 			}
// 		} 
//  
// 		auto worldAxis = axis[0] * camera->GetDirectionVector() + axis[1] * camera->GetUpVector() +	axis[2] * camera->GetRightVector();
// 
// 		const Matrixf trackRotate{ worldAxis, angle };
//  		 
// 		auto localRotate = trackRotate * rotate;
// 
// 		localRotate.Orthonormalize();
// 
// 		objectMotion.RotateTrackBall(camera.GetConstSmartPointer());
// 
// 		AssertRotate(localRotate, objectMotion.GetMotionObjectLocalTransform().GetRotate());
// 	}
}

void Framework::ObjectMotionTesting
	::ParentRotateTrackBallTest()
{
// 	Rendering::SpatialSmartPointer motionObject{ CoreTools::New0<Rendering::Node>() };
// 	Rendering::CameraSmartPointer camera{ CoreTools::New0<Rendering::Camera>() };
// 
// 	TestingType objectMotion{ motionObject };
// 
// 	default_random_engine generator{ GetEngineRandomSeed() };
// 	const uniform_real<float> random{ 0.0f, 100.0f };
// 
// 	Rendering::NodeSmartPointer parentMotionObject{ CoreTools::New0<Rendering::Node>() };
// 	parentMotionObject->AttachChild(motionObject);
// 
// 	Rendering::Transform Transform{ };
// 	const Matrixf matrix{ AVectorf::sm_UnitZ,Mathematics::FloatMath::sm_QuarterPI };
// 	Transform.SetRotate(matrix);
// 
// 	parentMotionObject->SetWorldTransform(Transform);
// 
// 	const auto testLoopCount = GetTestLoopCount();
// 	for (auto i = 0; i < testLoopCount; ++i)
// 	{
// 		auto xTrackBegin = random(generator);
// 		auto yTrackBegin = random(generator);
// 		auto xTrackEnd = random(generator);
// 		auto yTrackEnd = random(generator);
// 
// 		objectMotion.SetBeginTrack(xTrackBegin, yTrackBegin);
// 		objectMotion.SetEndTrack(xTrackEnd, yTrackEnd);
// 		objectMotion.SetSaveRotate();
// 
// 		const auto rotate = motionObject->GetLocalTransform().GetRotate();
// 
// 		auto vecBegin = GetSphereVector(xTrackBegin, yTrackBegin);
// 		auto vecEnd = GetSphereVector(xTrackEnd, yTrackEnd);
// 
// 		auto axis = Cross(vecBegin, vecEnd);
// 		const auto dot = Dot(vecBegin, vecEnd);
// 		auto angle = 0.0f;
// 		if (!axis.IsZero())
// 		{
// 			axis.Normalize();
// 			angle = Mathematics::FloatMath::ACos(dot);
// 		}
// 		else
// 		{
// 			if (dot < 0.0f)
// 			{
// 				auto invLength = Mathematics::FloatMath::InvSqrt(xTrackBegin * xTrackBegin + yTrackBegin * yTrackBegin);
// 				axis[0] = yTrackBegin * invLength;
// 				axis[1] = -xTrackBegin * invLength;
// 				axis[2] = 0.0f;
// 				angle = Mathematics::FloatMath::sm_PI;
// 			}
// 			else
// 			{
// 				axis = AVectorf::sm_UnitX;
// 				angle = 0.0f;
// 			}
// 		}
// 
// 		auto worldAxis = axis[0] * camera->GetDirectionVector() + axis[1] * camera->GetUpVector() + axis[2] * camera->GetRightVector();
// 
// 		const Matrixf trackRotate{ worldAxis, angle };
// 
// 		const auto parWorRotate = parentMotionObject->GetWorldTransform().GetRotate(); 
// 		auto localRotate = TransposeTimes(parWorRotate, trackRotate) * parWorRotate * rotate;
// 
// 		localRotate.Orthonormalize();
// 
// 		objectMotion.RotateTrackBall(camera.GetConstSmartPointer());
// 
// 		AssertRotate(localRotate, objectMotion.GetMotionObjectLocalTransform().GetRotate());
// 	}
}

void Framework::ObjectMotionTesting
	::AssertRotate(const Matrixf& lhs, const Matrixf& rhs)
{
	using Approximate = bool(*)(const Matrixf&, const Matrixf&, float);
	Approximate approximate{ Mathematics::Approximate<float> };

	ASSERT_APPROXIMATE_USE_FUNCTION(approximate, lhs, rhs, Mathematics::FloatMath::sm_Epsilon);
}

Mathematics::FloatAVector Framework::ObjectMotionTesting
	::GetSphereVector(float x, float y) const
{
    auto length = Mathematics::FloatMath::Sqrt(x * x + y * y);
	auto z = 0.0f; 

	if (1.0f < length)
	{
		x /= length;
		y /= length;
		z = 0.0f;
	}
	else
	{
		z = 1.0f - x * x - y * y;
            z = (z <= 0.0f ? 0.0f : Mathematics::FloatMath::Sqrt(z));
	}
	z *= -1.0f;

	return AVectorf{ z, y, x };
}



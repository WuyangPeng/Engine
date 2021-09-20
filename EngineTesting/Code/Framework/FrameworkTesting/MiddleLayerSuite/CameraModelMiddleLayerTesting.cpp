// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.1.0 (2020/06/28 22:26)

#include "CameraModelMiddleLayerTesting.h"
#include "System/Threading/SyncTools.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "System/Window/Flags/WindowDisplayFlags.h"
#include "CoreTools/Time/CustomTime.h"
#include "CoreTools/Helper/AssertMacro.h" 
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  
#include "Rendering/SceneGraph/Node.h"
#include "Rendering/SceneGraph/CameraManager.h" 
#include "Rendering/Renderers/RendererManager.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"
#include "Framework/WindowProcess/Flags/MouseTypes.h"
#include "Framework/MiddleLayer/CameraViewMiddleLayer.h" 
#include "Framework/MiddleLayer/CameraModelMiddleLayer.h" 
#include "Framework/MiddleLayer/CameraControllerMiddleLayerDetail.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"  

#include <random>

using std::string;
using std::make_shared; 
using std::uniform_int;
using std::uniform_real;
using std::default_random_engine;

namespace Framework
{
	using TestingType = CameraModelMiddleLayer;
}

Framework::CameraModelMiddleLayerTesting
	::CameraModelMiddleLayerTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, CameraModelMiddleLayerTesting)

void Framework::CameraModelMiddleLayerTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::CameraModelMiddleLayerTesting
	::MainTest()
{
	Rendering::RendererManager::Create();
	Rendering::CameraManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerTest);
	ASSERT_NOT_THROW_EXCEPTION_0(FrameRateTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CameraMotionMoveTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CameraMotionSpeedTest);
	ASSERT_NOT_THROW_EXCEPTION_0(MoveObjectTest);
	ASSERT_NOT_THROW_EXCEPTION_0(TrackBallDownTest);
	ASSERT_NOT_THROW_EXCEPTION_0(RotateTrackBallTest);

	Rendering::CameraManager::Destroy();
	Rendering::RendererManager::Destroy();
}

void Framework::CameraModelMiddleLayerTesting
	::MiddleLayerTest()
{
	constexpr auto platform = MiddleLayerPlatform::Windows;

	TestingType middleLayer{ platform };

	auto cameraViewMiddleLayer = make_shared<CameraViewMiddleLayer>(platform);

	middleLayer.SetViewMiddleLayer(cameraViewMiddleLayer);

	ASSERT_ENUM_EQUAL(middleLayer.GetMiddleLayerPlatform(), platform);

	EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment") ,SYSTEM_TEXT("") };
	ASSERT_TRUE(middleLayer.PreCreate(environmentDirectory));
	ASSERT_TRUE(middleLayer.Create());
	ASSERT_TRUE(middleLayer.Initialize());

	ASSERT_TRUE(middleLayer.Destroy());
	middleLayer.Terminate();

	middleLayer.PreIdle();
	ASSERT_TRUE(middleLayer.Idle(0));

	constexpr WindowPoint point{ };
	const WindowSize size{ };
	const VirtualKeysTypes virtualKeysTypes{ };

	ASSERT_TRUE(middleLayer.Paint());
	ASSERT_TRUE(middleLayer.Move(point));
	ASSERT_TRUE(middleLayer.Resize(System::WindowDisplay::MaxHide, size));

	ASSERT_TRUE(middleLayer.KeyUp(0, point));
	ASSERT_TRUE(middleLayer.KeyDown(0, point));
	ASSERT_TRUE(middleLayer.SpecialKeyUp(0, point));
	ASSERT_TRUE(middleLayer.SpecialKeyDown(0, point));

	ASSERT_TRUE(middleLayer.PassiveMotion(point));
	ASSERT_TRUE(middleLayer.Motion(point, virtualKeysTypes));
	ASSERT_TRUE(middleLayer.MouseWheel(0, point, virtualKeysTypes));
	ASSERT_TRUE(middleLayer.MouseClick(MouseButtonsTypes::LeftButton, MouseStateTypes::MouseDown, point, virtualKeysTypes)); 
}

void Framework::CameraModelMiddleLayerTesting
	::FrameRateTest()
{ 
	constexpr auto maxTimer = 30;
	constexpr auto platform = MiddleLayerPlatform::Windows;

	TestingType middleLayer{ platform };

	auto cameraViewMiddleLayer = make_shared<CameraViewMiddleLayer>(platform);

	middleLayer.SetViewMiddleLayer(cameraViewMiddleLayer);

	EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment") ,SYSTEM_TEXT("") };
	ASSERT_TRUE(middleLayer.PreCreate(environmentDirectory));
	ASSERT_TRUE(middleLayer.Initialize());

	const auto frame = System::g_Millisecond / maxTimer;
	const auto testLoopCount = maxTimer * GetTestLoopCount();

	CoreTools::CustomTime customTime{ };
	auto delta = 0;
	auto frameSum = 0;
	for (auto i = 0; i < testLoopCount; ++i)
	{
		middleLayer.UpdateFrameCount();

		delta += boost::numeric_cast<int>(customTime.GetThisElapsedMillisecondTime());
		frameSum += frame;

		if (delta < frameSum)
		{
			System::SystemSleep(frameSum - delta);
		}

		middleLayer.MeasureTime();
	}

	const auto rate = middleLayer.GetFrameRate();

	constexpr auto epsilon = 0.5;

	ASSERT_RANGE(rate, maxTimer - epsilon, maxTimer + epsilon);

	boost::format message{ "fps: %.2lf" };
	message % middleLayer.GetFrameRate();

	ASSERT_EQUAL(middleLayer.GetFrameRateMessage(), message.str());

	middleLayer.ResetTime();

	const auto zero = middleLayer.GetFrameRate();

	ASSERT_APPROXIMATE(0.0, zero, Mathematics::DoubleMath::sm_Epsilon);

	middleLayer.Terminate();
}

void Framework::CameraModelMiddleLayerTesting
	::CameraMotionSpeedTest()
{
	constexpr auto platform = MiddleLayerPlatform::Windows;

	TestingType middleLayer{ platform };

	auto cameraViewMiddleLayer = make_shared<CameraViewMiddleLayer>(platform);

	middleLayer.SetViewMiddleLayer(cameraViewMiddleLayer);

	EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment") ,SYSTEM_TEXT("") };
	ASSERT_TRUE(middleLayer.PreCreate(environmentDirectory));
	ASSERT_TRUE(middleLayer.Initialize());

	constexpr auto speed = 0.01f;
	constexpr auto speedFactor = 2.0f;

	ASSERT_APPROXIMATE(middleLayer.GetTranslationSpeed(), speed, Mathematics::FloatMath::sm_Epsilon);
	ASSERT_APPROXIMATE(middleLayer.GetRotationSpeed(), speed, Mathematics::FloatMath::sm_Epsilon);

	middleLayer.SlowerCameraTranslation();
	ASSERT_APPROXIMATE(middleLayer.GetTranslationSpeed(), speed / speedFactor, Mathematics::FloatMath::sm_Epsilon);
	ASSERT_APPROXIMATE(middleLayer.GetRotationSpeed(), speed, Mathematics::FloatMath::sm_Epsilon);

	middleLayer.FasterCameraTranslation();
	ASSERT_APPROXIMATE(middleLayer.GetTranslationSpeed(), speed, Mathematics::FloatMath::sm_Epsilon);
	ASSERT_APPROXIMATE(middleLayer.GetRotationSpeed(), speed, Mathematics::FloatMath::sm_Epsilon);

	middleLayer.SlowerCameraRotation();
	middleLayer.SlowerCameraRotation();
	ASSERT_APPROXIMATE(middleLayer.GetTranslationSpeed(), speed, Mathematics::FloatMath::sm_Epsilon);
	ASSERT_APPROXIMATE(middleLayer.GetRotationSpeed(), speed / (speedFactor * speedFactor), Mathematics::FloatMath::sm_Epsilon);

	middleLayer.FasterCameraRotation();
	ASSERT_APPROXIMATE(middleLayer.GetTranslationSpeed(), speed, Mathematics::FloatMath::sm_Epsilon);
	ASSERT_APPROXIMATE(middleLayer.GetRotationSpeed(), speed / speedFactor, Mathematics::FloatMath::sm_Epsilon);	 

	middleLayer.Terminate();
}

void Framework::CameraModelMiddleLayerTesting
	::CameraMotionMoveTest()
{
	/*constexpr auto platform = MiddleLayerPlatform::Windows;

	TestingType middleLayer{ platform };

	auto cameraViewMiddleLayer = make_shared<CameraViewMiddleLayer>(platform);

	middleLayer.SetViewMiddleLayer(cameraViewMiddleLayer);

	EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment") ,SYSTEM_TEXT("") };
	ASSERT_TRUE(middleLayer.PreCreate(environmentDirectory));
	ASSERT_TRUE(middleLayer.Initialize());

	constexpr auto translationSpeed = 0.01f;
	constexpr auto rotationSpeed = 0.01f;
	 
	Rendering::CameraSmartPointer camera{ CoreTools::New0<Rendering::Camera>() };
	auto direction = camera->GetDirectionVector();
	auto up = camera->GetUpVector();
	auto right = camera->GetRightVector();

	default_random_engine generator{ GetEngineRandomSeed() };
	const uniform_int<> random{ 0, 1 };

	const auto testLoopCount = GetTestLoopCount();
	for (auto i = 0; i < testLoopCount; ++i)
	{
		const auto moveForward = random(generator) == 0 ? true : false;

		middleLayer.SetMoveForward(moveForward);

		if (moveForward)
		{
			auto position = camera->GetPosition();
			position += translationSpeed * direction;
			camera->SetPosition(position);
		}

		const auto moveBackward = random(generator) == 0 ? true : false;

		middleLayer.SetMoveBackward(moveBackward);

		if (moveBackward)
		{
			auto position = camera->GetPosition();
			position -= translationSpeed * direction;
			camera->SetPosition(position);
		}

		const auto turnLeft = random(generator) == 0 ? true : false;

		middleLayer.SetTurnLeft(turnLeft);

		if (turnLeft)
		{
			const Mathematics::Matrixf rotation{ up, rotationSpeed };
			direction = rotation * direction;
			right = rotation * right;

			auto directionVector = rotation * camera->GetDirectionVector();
			auto upVector = rotation * camera->GetUpVector();
			auto rightVector = rotation * camera->GetRightVector();
			camera->SetAxes(directionVector, upVector, rightVector);
		}

		const auto turnRight = random(generator) == 0 ? true : false;

		middleLayer.SetTurnRight(turnRight);

		if (turnRight)
		{
			const Mathematics::Matrixf rotation{ up, -rotationSpeed };
			direction = rotation * direction;
			right = rotation * right;

			auto directionVector = rotation * camera->GetDirectionVector();
			auto upVector = rotation * camera->GetUpVector();
			auto rightVector = rotation * camera->GetRightVector();
			camera->SetAxes(directionVector, upVector, rightVector);
		}

		const auto lookUp = random(generator) == 0 ? true : false;

		middleLayer.SetLookUp(lookUp);

		if (lookUp)
		{
			const Mathematics::Matrixf rotation{ right, rotationSpeed };

			auto directionVector = rotation * camera->GetDirectionVector();
			auto upVector = rotation * camera->GetUpVector();
			auto rightVector = rotation * camera->GetRightVector();
			camera->SetAxes(directionVector, upVector, rightVector);
		}

		const auto lookDown = random(generator) == 0 ? true : false;

		middleLayer.SetLookDown(lookDown);

		if (lookDown)
		{
			const Mathematics::Matrixf rotation{ right, -rotationSpeed };

			auto directionVector = rotation * camera->GetDirectionVector();
			auto upVector = rotation * camera->GetUpVector();
			auto rightVector = rotation * camera->GetRightVector();
			camera->SetAxes(directionVector, upVector, rightVector);
		}

		const auto moveUp = random(generator) == 0 ? true : false;

		middleLayer.SetMoveUp(moveUp);

		if (moveUp)
		{
			auto position = camera->GetPosition();
			position += translationSpeed * up;
			camera->SetPosition(position);
		}

		const auto moveDown = random(generator) == 0 ? true : false;

		middleLayer.SetMoveDown(moveDown);

		if (moveDown)
		{
			auto position = camera->GetPosition();
			position -= translationSpeed * up;
			camera->SetPosition(position);
		}

		const auto moveRight = random(generator) == 0 ? true : false;

		middleLayer.SetMoveRight(moveRight);

		if (moveRight)
		{
			auto position = camera->GetPosition();
			position += translationSpeed * right;
			camera->SetPosition(position);
		}

		const auto moveLeft = random(generator) == 0 ? true : false;

		middleLayer.SetMoveLeft(moveLeft);

		if (moveLeft)
		{
			auto position = camera->GetPosition();
			position -= translationSpeed * right;
			camera->SetPosition(position);
		}

		middleLayer.MoveCamera();

		APointTest(camera->GetPosition(), middleLayer.GetCameraPosition(),__func__, i);
		AVectorTest(camera->GetDirectionVector(), middleLayer.GetCameraDirectionVector(), __func__, i);
		AVectorTest(camera->GetUpVector(), middleLayer.GetCameraUpVector(), __func__, i);
		AVectorTest(camera->GetRightVector(), middleLayer.GetCameraRightVector(), __func__, i); 
	}

	middleLayer.Terminate();*/
}

void Framework::CameraModelMiddleLayerTesting
	::MoveObjectTest()
{
	constexpr auto platform = MiddleLayerPlatform::Windows;

	TestingType middleLayer{ platform };

	auto cameraViewMiddleLayer = make_shared<CameraViewMiddleLayer>(platform);

	middleLayer.SetViewMiddleLayer(cameraViewMiddleLayer);

	EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment") ,SYSTEM_TEXT("") };
	ASSERT_TRUE(middleLayer.PreCreate(environmentDirectory));
	ASSERT_TRUE(middleLayer.Initialize());	
 
	middleLayer.SetTrackBallDow(false);

	default_random_engine generator{ GetEngineRandomSeed() };
	const uniform_int<> random{ 0, 1 };
	const uniform_int<> selectRandom{ 0, 2 };

	ASSERT_FALSE(middleLayer.MoveObject());

	middleLayer.Terminate();

	constexpr auto rotationSpeed = 0.01f;

	const auto testLoopCount = GetTestLoopCount();
	for (auto i = 0; i < testLoopCount; ++i)
	{
		ASSERT_TRUE(middleLayer.Initialize());		

		const auto select = selectRandom(generator);

		auto value = random(generator);	
		const auto numericalValueSymbol = (value == 0 ? NumericalValueSymbol::Negative : NumericalValueSymbol::Positive);

		AVectorf axis{ };
		switch (select)
		{
		case 0:
		{
			middleLayer.SetDoRoll(numericalValueSymbol);
			middleLayer.SetDoYaw(NumericalValueSymbol::Zero);
			middleLayer.SetDoPitch(NumericalValueSymbol::Zero);
			axis = AVectorf::GetUnitX();
		}
		break;
		case 1:
		{
			middleLayer.SetDoRoll(NumericalValueSymbol::Zero);
			middleLayer.SetDoYaw(numericalValueSymbol);
			middleLayer.SetDoPitch(NumericalValueSymbol::Zero);
			axis = AVectorf::GetUnitY();
		}
		break;
		case 2:
		{
			middleLayer.SetDoRoll(NumericalValueSymbol::Zero);
			middleLayer.SetDoYaw(NumericalValueSymbol::Zero);
			middleLayer.SetDoPitch(numericalValueSymbol);
			axis = AVectorf::GetUnitZ();
		}
		break;
		default:
			break;
		} 

		auto rotate = middleLayer.GetMotionObjectLocalTransform().GetRotate();
		const auto angle = numericalValueSymbol * rotationSpeed;

		const Mathematics::FloatMatrix incr{ axis, boost::numeric_cast<float>(angle) };
		rotate = incr * rotate;
		rotate.Orthonormalize();

		ASSERT_TRUE(middleLayer.MoveObject());

		MatrixTest(rotate, middleLayer.GetMotionObjectLocalTransform().GetRotate(),__func__,i);

		middleLayer.Terminate();
	} 
}

void Framework::CameraModelMiddleLayerTesting
	::TrackBallDownTest()
{
	constexpr auto platform = MiddleLayerPlatform::Windows;

	TestingType middleLayer{ platform };

	auto cameraViewMiddleLayer = make_shared<CameraViewMiddleLayer>(platform);

	middleLayer.SetViewMiddleLayer(cameraViewMiddleLayer);

	EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment") ,SYSTEM_TEXT("") };
	ASSERT_TRUE(middleLayer.PreCreate(environmentDirectory));
	ASSERT_TRUE(middleLayer.Initialize());

	ASSERT_FALSE(middleLayer.GetTrackBallDow());

	middleLayer.SetTrackBallDow(true);
	ASSERT_TRUE(middleLayer.GetTrackBallDow());

	middleLayer.SetTrackBallDow(false);
	ASSERT_FALSE(middleLayer.GetTrackBallDow());

	middleLayer.Terminate();
}

void Framework::CameraModelMiddleLayerTesting
	::RotateTrackBallTest()
{
	constexpr auto platform = MiddleLayerPlatform::Windows;

	TestingType middleLayer{ platform };

	auto cameraViewMiddleLayer = make_shared<CameraViewMiddleLayer>(platform);

	middleLayer.SetViewMiddleLayer(cameraViewMiddleLayer);

	EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment") ,SYSTEM_TEXT("") };
	ASSERT_TRUE(middleLayer.PreCreate(environmentDirectory));	
	ASSERT_TRUE(middleLayer.Initialize());

	default_random_engine generator{ GetEngineRandomSeed() };
	const uniform_real<float> random{ 0.0f, 100.0f };

	const auto testLoopCount = GetTestLoopCount();
	for (auto i = 0; i < testLoopCount; ++i)
	{
		auto xTrackBegin = random(generator);
		auto yTrackBegin = random(generator);
		auto xTrackEnd = random(generator);
		auto yTrackEnd = random(generator);

		middleLayer.SetBeginTrack(xTrackBegin, yTrackBegin);
		middleLayer.SetEndTrack(xTrackEnd, yTrackEnd);
		middleLayer.SetSaveRotate();

		const auto rotate = middleLayer.GetMotionObjectLocalTransform().GetRotate();

		auto vecBegin = Calculate3DVector(xTrackBegin, yTrackBegin);
		auto vecEnd = Calculate3DVector(xTrackEnd, yTrackEnd);

		auto axis = Cross(vecBegin, vecEnd);
		const auto dot = Dot(vecBegin, vecEnd);
		auto angle = 0.0f;
		if (!axis.IsZero())
		{
			axis.Normalize();
			angle = Mathematics::FloatMath::ACos(dot);
		}
		else
		{
			if (dot < 0.0f)
			{
				auto invLength = Mathematics::FloatMath::InvSqrt(xTrackBegin * xTrackBegin + yTrackBegin * yTrackBegin);
				axis[0] = yTrackBegin * invLength;
				axis[1] = -xTrackBegin * invLength;
				axis[2] = 0.0f;
				angle = Mathematics::FloatMath::GetPI();
			}
			else
			{
				axis = AVectorf::GetUnitX();
				angle = 0.0f;
			}
		}

		auto worldAxis = axis[0] * middleLayer.GetCameraDirectionVector() + axis[1] * middleLayer.GetCameraUpVector() + axis[2] * middleLayer.GetCameraRightVector();

		const Matrixf trackRotate{ worldAxis, angle };

		auto localRotate = trackRotate * rotate;

		localRotate.Orthonormalize();

		middleLayer.RotateTrackBall();

		MatrixTest(localRotate, middleLayer.GetMotionObjectLocalTransform().GetRotate(),__func__,i);		
	}	

	middleLayer.Terminate();
}

// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.1.0 (2020/06/28 22:28)

#include "CameraControllerMiddleLayerTesting.h"
#include "System/Windows/Flags/WindowsDisplayFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Rendering/DataTypes/TransformMatrixDetail.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MiddleLayer/CameraControllerMiddleLayerDetail.h"
#include "Framework/MiddleLayer/CameraModelMiddleLayer.h"
#include "Framework/MiddleLayer/CameraViewMiddleLayer.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowProcess/Flags/MouseTypes.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"

#include <random>

using std::default_random_engine;
using std::make_shared;
using std::string;
using std::uniform_int;

namespace Framework
{
    using TestingType = CameraControllerMiddleLayer<WindowApplicationTrait>;
    using TestingTypeSharedPtr = std::shared_ptr<TestingType>;
}

#include SYSTEM_WARNING_DISABLE(26440)
Framework::CameraControllerMiddleLayerTesting::CameraControllerMiddleLayerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, CameraControllerMiddleLayerTesting)

void Framework::CameraControllerMiddleLayerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::CameraControllerMiddleLayerTesting::MainTest()
{
    Rendering::RendererManager::Create();
    Rendering::CameraManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(KeyDownTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CameraMotionMoveTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MoveObjectTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TrackBallDownTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RotateTrackBallTest);

    Rendering::CameraManager::Destroy();
    Rendering::RendererManager::Destroy();
}

void Framework::CameraControllerMiddleLayerTesting::MiddleLayerTest()
{
    constexpr auto platform = MiddleLayerPlatform::Windows;

    TestingType middleLayer{ platform };

    auto cameraModelMiddleLayer = make_shared<CameraModelMiddleLayer>(platform);
    middleLayer.SetModelMiddleLayer(cameraModelMiddleLayer);
    auto cameraViewMiddleLayer = make_shared<CameraViewMiddleLayer>(platform);
    middleLayer.SetViewMiddleLayer(cameraViewMiddleLayer);

    ASSERT_ENUM_EQUAL(middleLayer.GetMiddleLayerPlatform(), platform);

    EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };
    ASSERT_TRUE(middleLayer.PreCreate(environmentDirectory));
    ASSERT_TRUE(middleLayer.Create());
    ASSERT_TRUE(middleLayer.Initialize());

    ASSERT_TRUE(middleLayer.Destroy());
    middleLayer.Terminate();

    middleLayer.PreIdle();
    ASSERT_TRUE(middleLayer.Idle(0));

    constexpr WindowPoint point{};
    const WindowSize size{};
    const VirtualKeysTypes virtualKeysTypes{};

    ASSERT_TRUE(middleLayer.Paint());
    ASSERT_TRUE(middleLayer.Move(point));
    ASSERT_TRUE(middleLayer.Resize(System::WindowsDisplay::MaxHide, size));

    ASSERT_TRUE(middleLayer.KeyUp(0, point));
    ASSERT_TRUE(middleLayer.KeyDown(0, point));
    ASSERT_TRUE(middleLayer.SpecialKeyUp(0, point));
    ASSERT_TRUE(middleLayer.SpecialKeyDown(0, point));

    ASSERT_TRUE(middleLayer.PassiveMotion(point));
    ASSERT_TRUE(middleLayer.Motion(point, virtualKeysTypes));
    ASSERT_TRUE(middleLayer.MouseWheel(0, point, virtualKeysTypes));
    ASSERT_TRUE(middleLayer.MouseClick(MouseButtonsTypes::LeftButton, MouseStateTypes::MouseDown, point, virtualKeysTypes));
}

void Framework::CameraControllerMiddleLayerTesting::KeyDownTest()
{
    constexpr auto platform = MiddleLayerPlatform::Windows;

    auto middleLayer = make_shared<TestingType>(platform);

    auto cameraModelMiddleLayer = make_shared<CameraModelMiddleLayer>(platform);
    middleLayer->SetModelMiddleLayer(cameraModelMiddleLayer);
    auto cameraViewMiddleLayer = make_shared<CameraViewMiddleLayer>(platform);
    middleLayer->SetViewMiddleLayer(cameraViewMiddleLayer);
    cameraModelMiddleLayer->SetViewMiddleLayer(cameraViewMiddleLayer);
    cameraModelMiddleLayer->SetControllerMiddleLayer(middleLayer);
    cameraViewMiddleLayer->SetModelMiddleLayer(cameraModelMiddleLayer);
    cameraViewMiddleLayer->SetControllerMiddleLayer(middleLayer);

    EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };
    ASSERT_TRUE(middleLayer->PreCreate(environmentDirectory));
    ASSERT_TRUE(middleLayer->Create());
    ASSERT_TRUE(middleLayer->Initialize());

    ASSERT_TRUE(cameraModelMiddleLayer->PreCreate(environmentDirectory));
    ASSERT_TRUE(cameraModelMiddleLayer->Initialize());

    ASSERT_TRUE(cameraViewMiddleLayer->PreCreate(environmentDirectory));
    ASSERT_TRUE(cameraViewMiddleLayer->Initialize());

    const WindowSize defaultWindowSize{ 1024, 768 };
    ASSERT_TRUE(middleLayer->Resize(System::WindowsDisplay::MaxHide, defaultWindowSize));
    ASSERT_TRUE(cameraModelMiddleLayer->Resize(System::WindowsDisplay::MaxHide, defaultWindowSize));

    const auto originalRotationSpeed = cameraModelMiddleLayer->GetRotationSpeed();
    const auto originalTranslationSpeed = cameraModelMiddleLayer->GetTranslationSpeed();
    constexpr auto speedFactor = 2.0f;
    constexpr WindowPoint point{};

    ASSERT_TRUE(middleLayer->KeyDown(WindowApplicationTrait::KeyIdentifiers::lowerT, point));
    ASSERT_APPROXIMATE(originalTranslationSpeed / speedFactor, cameraModelMiddleLayer->GetTranslationSpeed(), Mathematics::MathF::epsilon);
    ASSERT_APPROXIMATE(originalRotationSpeed, cameraModelMiddleLayer->GetRotationSpeed(), Mathematics::MathF::epsilon);

    ASSERT_TRUE(middleLayer->KeyDown(WindowApplicationTrait::KeyIdentifiers::upperR, point));
    ASSERT_APPROXIMATE(originalTranslationSpeed / speedFactor, cameraModelMiddleLayer->GetTranslationSpeed(), Mathematics::MathF::epsilon);
    ASSERT_APPROXIMATE(originalRotationSpeed * speedFactor, cameraModelMiddleLayer->GetRotationSpeed(), Mathematics::MathF::epsilon);

    ASSERT_TRUE(middleLayer->KeyDown(WindowApplicationTrait::KeyIdentifiers::lowerR, point));
    ASSERT_APPROXIMATE(originalTranslationSpeed / speedFactor, cameraModelMiddleLayer->GetTranslationSpeed(), Mathematics::MathF::epsilon);
    ASSERT_APPROXIMATE(originalRotationSpeed, cameraModelMiddleLayer->GetRotationSpeed(), Mathematics::MathF::epsilon);

    ASSERT_TRUE(middleLayer->KeyDown(WindowApplicationTrait::KeyIdentifiers::upperT, point));
    ASSERT_APPROXIMATE(originalTranslationSpeed, cameraModelMiddleLayer->GetTranslationSpeed(), Mathematics::MathF::epsilon);
    ASSERT_APPROXIMATE(originalRotationSpeed, cameraModelMiddleLayer->GetRotationSpeed(), Mathematics::MathF::epsilon);

    ASSERT_TRUE(cameraModelMiddleLayer->Destroy());
    cameraModelMiddleLayer->Terminate();

    ASSERT_TRUE(middleLayer->Destroy());
    middleLayer->Terminate();
}

void Framework::CameraControllerMiddleLayerTesting::CameraMotionMoveTest()
{
    /*constexpr auto platform = MiddleLayerPlatform::Windows;

	auto middleLayer = make_shared<TestingType>(platform);

	auto cameraModelMiddleLayer = make_shared<CameraModelMiddleLayer>(platform);
	middleLayer->SetModelMiddleLayer(cameraModelMiddleLayer);
	auto cameraViewMiddleLayer = make_shared<CameraViewMiddleLayer>(platform);
	middleLayer->SetViewMiddleLayer(cameraViewMiddleLayer);
	cameraModelMiddleLayer->SetViewMiddleLayer(cameraViewMiddleLayer);
	cameraModelMiddleLayer->SetControllerMiddleLayer(middleLayer);
	cameraViewMiddleLayer->SetModelMiddleLayer(cameraModelMiddleLayer);
	cameraViewMiddleLayer->SetControllerMiddleLayer(middleLayer);

	EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment") ,SYSTEM_TEXT("") };
	ASSERT_TRUE(middleLayer->PreCreate(environmentDirectory));
	ASSERT_TRUE(middleLayer->Create());
	ASSERT_TRUE(middleLayer->Initialize());

	ASSERT_TRUE(cameraModelMiddleLayer->PreCreate(environmentDirectory));
	ASSERT_TRUE(cameraModelMiddleLayer->Initialize());

	ASSERT_TRUE(cameraViewMiddleLayer->PreCreate(environmentDirectory));
	ASSERT_TRUE(cameraViewMiddleLayer->Initialize());

	constexpr auto translationSpeed = 0.01f;
	constexpr auto rotationSpeed = 0.01f;

	Rendering::CameraSmartPointer camera{ CoreTools::New0<Rendering::Camera>() };
 
	auto direction = camera->GetDirectionVector();
	auto up = camera->GetUpVector();
	auto right = camera->GetRightVector();

	default_random_engine generator{ GetEngineRandomSeed() };
	const uniform_int<> random{ 0, 1 };
	constexpr WindowPoint point{ };

	const auto testLoopCount = GetTestLoopCount();
	for (auto i = 0; i < testLoopCount; ++i)
	{
		const auto moveForward = random(generator) == 0 ? true : false;		
			
		if (moveForward)
		{
			middleLayer->SpecialKeyDown(WindowApplicationTrait::KeyIdentifiers::keyUpArrow, point);

			auto position = camera->GetPosition();
			position += translationSpeed * direction;
			camera->SetPosition(position);
		}  
		else
		{
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyUpArrow, point);
		}

		const auto moveBackward = random(generator) == 0 ? true : false;
	
		if (moveBackward)
		{
			middleLayer->SpecialKeyDown(WindowApplicationTrait::KeyIdentifiers::keyDownArrow, point);

			auto position = camera->GetPosition();
			position -= translationSpeed * direction;
			camera->SetPosition(position);
		}
		else
		{
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyDownArrow, point);
		}

		const auto turnLeft = random(generator) == 0 ? true : false;		

		if (turnLeft)
		{
			middleLayer->SpecialKeyDown(WindowApplicationTrait::KeyIdentifiers::keyInsert, point);

			const Mathematics::Matrixf rotation{ up, rotationSpeed };
			direction = rotation * direction;
			right = rotation * right;

			auto directionVector = rotation * camera->GetDirectionVector();
			auto upVector = rotation * camera->GetUpVector();
			auto rightVector = rotation * camera->GetRightVector();
			camera->SetAxes(directionVector, upVector, rightVector);
		}
		else
		{
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyInsert, point);
		}
	 
		const auto turnRight = random(generator) == 0 ? true : false;		

		if (turnRight)
		{
			middleLayer->SpecialKeyDown(WindowApplicationTrait::KeyIdentifiers::keyDelete, point);

			const Mathematics::Matrixf rotation{ up, -rotationSpeed };
			direction = rotation * direction;
			right = rotation * right;

			auto directionVector = rotation * camera->GetDirectionVector();
			auto upVector = rotation * camera->GetUpVector();
			auto rightVector = rotation * camera->GetRightVector();
			camera->SetAxes(directionVector, upVector, rightVector);
		}
		else
		{
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyDelete, point);
		}

		const auto lookUp = random(generator) == 0 ? true : false;		

		if (lookUp)
		{
			middleLayer->SpecialKeyDown(WindowApplicationTrait::KeyIdentifiers::keyHome, point);

			const Mathematics::Matrixf rotation{ right, rotationSpeed };

			auto directionVector = rotation * camera->GetDirectionVector();
			auto upVector = rotation * camera->GetUpVector();
			auto rightVector = rotation * camera->GetRightVector();
			camera->SetAxes(directionVector, upVector, rightVector);
		}
		else
		{
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyHome, point);
		}

		const auto lookDown = random(generator) == 0 ? true : false;		

		if (lookDown)
		{
			middleLayer->SpecialKeyDown(WindowApplicationTrait::KeyIdentifiers::keyEnd, point);

			const Mathematics::Matrixf rotation{ right, -rotationSpeed };

			auto directionVector = rotation * camera->GetDirectionVector();
			auto upVector = rotation * camera->GetUpVector();
			auto rightVector = rotation * camera->GetRightVector();
			camera->SetAxes(directionVector, upVector, rightVector);
		}
		else
		{
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyEnd, point);
		}

		const auto moveUp = random(generator) == 0 ? true : false;	

		if (moveUp)
		{
			middleLayer->SpecialKeyDown(WindowApplicationTrait::KeyIdentifiers::keyPageUp, point);

			auto position = camera->GetPosition();
			position += translationSpeed * up;
			camera->SetPosition(position);
		}
		else
		{
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyPageUp, point);
		}

		const auto moveDown = random(generator) == 0 ? true : false;		

		if (moveDown)
		{
			middleLayer->SpecialKeyDown(WindowApplicationTrait::KeyIdentifiers::keyPageDown, point);

			auto position = camera->GetPosition();
			position -= translationSpeed * up;
			camera->SetPosition(position);
		}
		else
		{
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyPageDown, point);
		}

		const auto moveRight = random(generator) == 0 ? true : false;

		if (moveRight)
		{
			middleLayer->SpecialKeyDown(WindowApplicationTrait::KeyIdentifiers::keyRightArrow, point);

			auto position = camera->GetPosition();
			position += translationSpeed * right;
			camera->SetPosition(position);
		}
		else
		{
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyRightArrow, point);
		}
		
		const auto moveLeft = random(generator) == 0 ? true : false;		

		if (moveLeft)
		{
			middleLayer->SpecialKeyDown(WindowApplicationTrait::KeyIdentifiers::keyLeftArrow, point);

			auto position = camera->GetPosition();
			position -= translationSpeed * right;
			camera->SetPosition(position);
		}
		else
		{
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyLeftArrow, point);
		}		

		cameraModelMiddleLayer->MoveCamera();

		APointTest(camera->GetPosition(), cameraModelMiddleLayer->GetCameraPosition(), __func__, i);
		AVectorTest(camera->GetDirectionVector(), cameraModelMiddleLayer->GetCameraDirectionVector(), __func__, i);
		AVectorTest(camera->GetUpVector(), cameraModelMiddleLayer->GetCameraUpVector(), __func__, i);
		AVectorTest(camera->GetRightVector(), cameraModelMiddleLayer->GetCameraRightVector(), __func__, i);
	}

	ASSERT_TRUE(cameraModelMiddleLayer->Destroy());
	cameraModelMiddleLayer->Terminate();

	ASSERT_TRUE(middleLayer->Destroy());
	middleLayer->Terminate();*/
}

void Framework::CameraControllerMiddleLayerTesting::MoveObjectTest()
{
    /*constexpr auto platform = MiddleLayerPlatform::Windows;

	auto middleLayer = make_shared<TestingType>(platform);

	auto cameraModelMiddleLayer = make_shared<CameraModelMiddleLayer>(platform);
	middleLayer->SetModelMiddleLayer(cameraModelMiddleLayer);
	auto cameraViewMiddleLayer = make_shared<CameraViewMiddleLayer>(platform);
	middleLayer->SetViewMiddleLayer(cameraViewMiddleLayer);
	cameraModelMiddleLayer->SetViewMiddleLayer(cameraViewMiddleLayer);
	cameraModelMiddleLayer->SetControllerMiddleLayer(middleLayer);
	cameraViewMiddleLayer->SetModelMiddleLayer(cameraModelMiddleLayer);
	cameraViewMiddleLayer->SetControllerMiddleLayer(middleLayer);	
	constexpr WindowPoint point{ };
	const VirtualKeysTypes virtualKeysTypes{ };

	middleLayer->MouseClick(MouseButtonsTypes::LeftButton, MouseStateTypes::MouseDown, point, virtualKeysTypes);

	default_random_engine generator{ GetEngineRandomSeed() };
	const uniform_int<> random{ 0, 1 };
	const uniform_int<> selectRandom{ 0, 5 };

	ASSERT_FALSE(cameraModelMiddleLayer->MoveObject()); 

	constexpr auto rotationSpeed = 0.01f;

	const auto testLoopCount = GetTestLoopCount();
	for (auto i = 0; i < testLoopCount; ++i)
	{
		EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment") ,SYSTEM_TEXT("") };
		ASSERT_TRUE(middleLayer->PreCreate(environmentDirectory));
		ASSERT_TRUE(middleLayer->Create());
		ASSERT_TRUE(middleLayer->Initialize());

		ASSERT_TRUE(cameraModelMiddleLayer->PreCreate(environmentDirectory));
		ASSERT_TRUE(cameraModelMiddleLayer->Initialize());

		ASSERT_TRUE(cameraViewMiddleLayer->PreCreate(environmentDirectory));
		ASSERT_TRUE(cameraViewMiddleLayer->Initialize());

		const auto select = selectRandom(generator); 

		AVectorf axis{ };
		switch (select)
		{
		case 0:
		{
			middleLayer->SpecialKeyDown(WindowApplicationTrait::KeyIdentifiers::keyF1, point);
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyF3, point);
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyF4, point);
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyF5, point);
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyF6, point);
			axis = AVectorf::unitX;
		}
		break;
		case 1:
		{
			middleLayer->SpecialKeyDown(WindowApplicationTrait::KeyIdentifiers::keyF2, point);			
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyF3, point);
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyF4, point);
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyF5, point);
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyF6, point);

			axis = AVectorf::unitX;
		}
		break;
		case 2:
		{			
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyF2, point);
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyF1, point);
			middleLayer->SpecialKeyDown(WindowApplicationTrait::KeyIdentifiers::keyF3, point);
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyF5, point);
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyF6, point);

			axis = AVectorf::unitY;
		}
		break;
		case 3:
		{
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyF1, point);
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyF2, point);
			middleLayer->SpecialKeyDown(WindowApplicationTrait::KeyIdentifiers::keyF4, point);
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyF5, point);
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyF6, point);

			axis = AVectorf::unitY;
		}
		break;
		case 4:
		{
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyF1, point);
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyF2, point);
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyF3, point);
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyF4, point);
			middleLayer->SpecialKeyDown(WindowApplicationTrait::KeyIdentifiers::keyF5, point);
	
			axis = AVectorf::unitZ;
		}
		break;
		case 5:
		{			
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyF1, point);
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyF2, point);
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyF3, point);
			middleLayer->SpecialKeyUp(WindowApplicationTrait::KeyIdentifiers::keyF4, point);
			middleLayer->SpecialKeyDown(WindowApplicationTrait::KeyIdentifiers::keyF6, point);

			axis = AVectorf::unitZ;
		}
		break;
		default:
			break;
		}

		auto rotate = cameraModelMiddleLayer->GetMotionObjectLocalTransform().GetRotate();
		const auto angle = ((select % 2 == 0) ? 1 : -1) * rotationSpeed;

		const Mathematics::Matrixf incr{ axis, boost::numeric_cast<float>(angle) };
		rotate = incr * rotate;
		rotate.Orthonormalize();

		ASSERT_TRUE(cameraModelMiddleLayer->MoveObject());

		MatrixTest(rotate, cameraModelMiddleLayer->GetMotionObjectLocalTransform().GetRotate(), __func__, i);

		ASSERT_TRUE(cameraModelMiddleLayer->Destroy());
		cameraModelMiddleLayer->Terminate();

		ASSERT_TRUE(middleLayer->Destroy());
		middleLayer->Terminate();
	} */
}

void Framework::CameraControllerMiddleLayerTesting::TrackBallDownTest()
{
    constexpr auto platform = MiddleLayerPlatform::Windows;

    auto middleLayer = make_shared<TestingType>(platform);

    auto cameraModelMiddleLayer = make_shared<CameraModelMiddleLayer>(platform);
    middleLayer->SetModelMiddleLayer(cameraModelMiddleLayer);
    auto cameraViewMiddleLayer = make_shared<CameraViewMiddleLayer>(platform);
    middleLayer->SetViewMiddleLayer(cameraViewMiddleLayer);
    cameraModelMiddleLayer->SetViewMiddleLayer(cameraViewMiddleLayer);
    cameraModelMiddleLayer->SetControllerMiddleLayer(middleLayer);
    cameraViewMiddleLayer->SetModelMiddleLayer(cameraModelMiddleLayer);
    cameraViewMiddleLayer->SetControllerMiddleLayer(middleLayer);

    EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };
    ASSERT_TRUE(middleLayer->PreCreate(environmentDirectory));
    ASSERT_TRUE(middleLayer->Create());
    ASSERT_TRUE(middleLayer->Initialize());

    ASSERT_TRUE(cameraModelMiddleLayer->PreCreate(environmentDirectory));
    ASSERT_TRUE(cameraModelMiddleLayer->Initialize());

    ASSERT_TRUE(cameraViewMiddleLayer->PreCreate(environmentDirectory));
    ASSERT_TRUE(cameraViewMiddleLayer->Initialize());

    ASSERT_FALSE(cameraModelMiddleLayer->GetTrackBallDow());

    constexpr WindowPoint point{};
    const VirtualKeysTypes virtualKeysTypes{};

    middleLayer->MouseClick(MouseButtonsTypes::LeftButton, MouseStateTypes::MouseDown, point, virtualKeysTypes);
    ASSERT_TRUE(cameraModelMiddleLayer->GetTrackBallDow());

    middleLayer->MouseClick(MouseButtonsTypes::LeftButton, MouseStateTypes::MouseUp, point, virtualKeysTypes);
    ASSERT_FALSE(cameraModelMiddleLayer->GetTrackBallDow());

    ASSERT_TRUE(cameraModelMiddleLayer->Destroy());
    cameraModelMiddleLayer->Terminate();

    ASSERT_TRUE(middleLayer->Destroy());
    middleLayer->Terminate();
}

void Framework::CameraControllerMiddleLayerTesting::RotateTrackBallTest()
{
    constexpr auto platform = MiddleLayerPlatform::Windows;

    auto middleLayer = make_shared<TestingType>(platform);

    auto cameraModelMiddleLayer = make_shared<CameraModelMiddleLayer>(platform);
    middleLayer->SetModelMiddleLayer(cameraModelMiddleLayer);
    auto cameraViewMiddleLayer = make_shared<CameraViewMiddleLayer>(platform);
    middleLayer->SetViewMiddleLayer(cameraViewMiddleLayer);
    cameraModelMiddleLayer->SetViewMiddleLayer(cameraViewMiddleLayer);
    cameraModelMiddleLayer->SetControllerMiddleLayer(middleLayer);
    cameraViewMiddleLayer->SetModelMiddleLayer(cameraModelMiddleLayer);
    cameraViewMiddleLayer->SetControllerMiddleLayer(middleLayer);

    const WindowSize windowSize{ 1024, 768 };
    const auto multiplier = 1.0f / windowSize.GetWindowHeight();

    EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };
    ASSERT_TRUE(middleLayer->PreCreate(environmentDirectory));
    ASSERT_TRUE(middleLayer->Create());
    ASSERT_TRUE(middleLayer->Initialize());
    ASSERT_TRUE(middleLayer->Resize(System::WindowsDisplay::MaxHide, windowSize));

    ASSERT_TRUE(cameraModelMiddleLayer->PreCreate(environmentDirectory));
    ASSERT_TRUE(cameraModelMiddleLayer->Initialize());
    ASSERT_TRUE(cameraModelMiddleLayer->Resize(System::WindowsDisplay::MaxHide, windowSize));

    ASSERT_TRUE(cameraViewMiddleLayer->PreCreate(environmentDirectory));
    ASSERT_TRUE(cameraViewMiddleLayer->Initialize());
    ASSERT_TRUE(cameraViewMiddleLayer->Resize(System::WindowsDisplay::MaxHide, windowSize));

    default_random_engine generator{ GetEngineRandomSeed() };
    const uniform_int<> random{ 0, 100 };

    const auto testLoopCount = GetTestLoopCount();
    for (auto i = 0; i < testLoopCount; ++i)
    {
        auto xBegin = random(generator);
        auto yBegin = random(generator);
        auto xEnd = random(generator);
        auto yEnd = random(generator);

        const auto xTrackBegin = GetXTrack(xBegin, multiplier, windowSize);
        const auto yTrackBegin = GetYTrack(yBegin, multiplier, windowSize);
        const auto xTrackEnd = GetXTrack(xEnd, multiplier, windowSize);
        const auto yTrackEnd = GetYTrack(yEnd, multiplier, windowSize);

        const WindowPoint point{ xBegin, yBegin };
        const VirtualKeysTypes virtualKeysTypes{};

        middleLayer->MouseClick(MouseButtonsTypes::LeftButton, MouseStateTypes::MouseDown, point, virtualKeysTypes);

        const auto rotate = cameraModelMiddleLayer->GetMotionObjectLocalTransform().GetRotate();

        const auto vecBegin = Calculate3DVector(boost::numeric_cast<float>(xTrackBegin), boost::numeric_cast<float>(yTrackBegin));
        const auto vecEnd = Calculate3DVector(boost::numeric_cast<float>(xTrackEnd), boost::numeric_cast<float>(yTrackEnd));

        auto axis = Cross(vecBegin, vecEnd);
        const auto dot = Dot(vecBegin, vecEnd);
        auto angle = 0.0f;
        if (!axis.IsZero())
        {
            axis.Normalize();
            angle = Mathematics::MathF::ACos(dot);
        }
        else
        {
            if (dot < 0.0f)
            {
                auto invLength = Mathematics::MathF::InvSqrt(boost::numeric_cast<float>(xBegin * xBegin + yBegin * yBegin));
                axis[0] = yTrackBegin * invLength;
                axis[1] = -xTrackBegin * invLength;
                axis[2] = 0.0f;
                angle = Mathematics::MathF::GetPI();
            }
            else
            {
                axis = AVectorf::GetUnitX();
                angle = 0.0f;
            }
        }

        auto worldAxis = axis[0] * cameraModelMiddleLayer->GetCameraDirectionVector() + axis[1] * cameraModelMiddleLayer->GetCameraUpVector() + axis[2] * cameraModelMiddleLayer->GetCameraRightVector();

        const Matrixf trackRotate{ worldAxis, angle };

        auto localRotate = trackRotate * rotate;

        localRotate.Orthonormalize();

        middleLayer->Motion(WindowPoint{ xEnd, yEnd }, VirtualKeysTypes{ boost::numeric_cast<System::WindowsWParam>(WindowApplicationTrait::MouseModifiers::modifierLeftButton) });

        MatrixTest(localRotate, cameraModelMiddleLayer->GetMotionObjectLocalTransform().GetRotate(), __func__, i);
    }

    ASSERT_TRUE(cameraModelMiddleLayer->Destroy());
    cameraModelMiddleLayer->Terminate();

    ASSERT_TRUE(middleLayer->Destroy());
    middleLayer->Terminate();
}
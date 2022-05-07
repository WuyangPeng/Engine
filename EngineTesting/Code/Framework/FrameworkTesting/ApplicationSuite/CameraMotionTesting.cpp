// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.3.0.2 (2020/06/24 21:42)

#include "CameraMotionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Framework/Application/CameraMotion.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;

namespace Framework
{
    using TestingType = CameraMotion;
}

#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
Framework::CameraMotionTesting::CameraMotionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, CameraMotionTesting)

void Framework::CameraMotionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::CameraMotionTesting::MainTest()
{
    Rendering::CameraManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SpeedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MoveTest);

    Rendering::CameraManager::Destroy();
}

void Framework::CameraMotionTesting::BaseTest()
{
    TestingType cameraMotion{ 2.0f, 1.0f };

    ASSERT_APPROXIMATE(cameraMotion.GetTranslationSpeed(), 2.0f, Mathematics::MathF::epsilon);
    ASSERT_APPROXIMATE(cameraMotion.GetRotationSpeed(), 1.0f, Mathematics::MathF::epsilon);
    ASSERT_UNEQUAL_NULL_PTR(cameraMotion.GetCamera());
}

void Framework::CameraMotionTesting::SpeedTest()
{
    constexpr auto translationSpeedFactor = 4.0f;
    constexpr auto rotationSpeedFactor = 4.0f;
    constexpr auto translationSpeed = 2.0f;
    constexpr auto rotationSpeed = 1.0f;
    TestingType cameraMotion{ translationSpeed, rotationSpeed, translationSpeedFactor, rotationSpeedFactor };
    ASSERT_APPROXIMATE(cameraMotion.GetTranslationSpeed(), translationSpeed, Mathematics::MathF::epsilon);
    ASSERT_APPROXIMATE(cameraMotion.GetRotationSpeed(), rotationSpeed, Mathematics::MathF::epsilon);

    cameraMotion.SlowerCameraTranslation();
    ASSERT_APPROXIMATE(cameraMotion.GetTranslationSpeed(), translationSpeed / translationSpeedFactor, Mathematics::MathF::epsilon);
    ASSERT_APPROXIMATE(cameraMotion.GetRotationSpeed(), rotationSpeed, Mathematics::MathF::epsilon);

    cameraMotion.FasterCameraTranslation();
    ASSERT_APPROXIMATE(cameraMotion.GetTranslationSpeed(), translationSpeed, Mathematics::MathF::epsilon);
    ASSERT_APPROXIMATE(cameraMotion.GetRotationSpeed(), rotationSpeed, Mathematics::MathF::epsilon);

    cameraMotion.SlowerCameraRotation();
    cameraMotion.SlowerCameraRotation();
    ASSERT_APPROXIMATE(cameraMotion.GetTranslationSpeed(), translationSpeed, Mathematics::MathF::epsilon);
    ASSERT_APPROXIMATE(cameraMotion.GetRotationSpeed(), rotationSpeed / (rotationSpeedFactor * rotationSpeedFactor), Mathematics::MathF::epsilon);

    cameraMotion.FasterCameraRotation();
    ASSERT_APPROXIMATE(cameraMotion.GetTranslationSpeed(), translationSpeed, Mathematics::MathF::epsilon);
    ASSERT_APPROXIMATE(cameraMotion.GetRotationSpeed(), rotationSpeed / rotationSpeedFactor, Mathematics::MathF::epsilon);
}

void Framework::CameraMotionTesting::MoveTest()
{
    constexpr auto translationSpeed = 1.0f;
    constexpr auto rotationSpeed = 1.0f;
    TestingType cameraMotion{ translationSpeed, rotationSpeed };

    Rendering::CameraSharedPtr camera = std::make_shared<Rendering::Camera>(false);
    auto direction = camera->GetDirectionVector();
    const auto up = camera->GetUpVector();
    auto right = camera->GetRightVector();

    default_random_engine generator{ GetEngineRandomSeed() };
    const uniform_int<> random{ 0, 1 };

    const auto testLoopCount = GetTestLoopCount();
    for (auto i = 0; i < testLoopCount; ++i)
    {
        const auto moveForward = random(generator) == 1 ? true : false;

        cameraMotion.SetMoveForward(moveForward);

        if (moveForward)
        {
            auto position = camera->GetPosition();
            position += translationSpeed * direction;
            camera->SetPosition(position);
        }

        const auto moveBackward = random(generator) == 1 ? true : false;

        cameraMotion.SetMoveBackward(moveBackward);

        if (moveBackward)
        {
            auto position = camera->GetPosition();
            position -= translationSpeed * direction;
            camera->SetPosition(position);
        }

        const auto turnLeft = random(generator) == 1 ? true : false;

        cameraMotion.SetTurnLeft(turnLeft);

        if (turnLeft)
        {
            const Mathematics::MatrixF rotation{ up, rotationSpeed };
            direction = rotation * direction;
            right = rotation * right;

            const auto directionVector = rotation * camera->GetDirectionVector();
            const auto upVector = rotation * camera->GetUpVector();
            const auto rightVector = rotation * camera->GetRightVector();
            camera->SetAxes(directionVector, upVector, rightVector);
        }

        const auto turnRight = random(generator) == 1 ? true : false;

        cameraMotion.SetTurnRight(turnRight);

        if (turnRight)
        {
            const Mathematics::MatrixF rotation{ up, -rotationSpeed };
            direction = rotation * direction;
            right = rotation * right;

            const auto directionVector = rotation * camera->GetDirectionVector();
            const auto upVector = rotation * camera->GetUpVector();
            const auto rightVector = rotation * camera->GetRightVector();
            camera->SetAxes(directionVector, upVector, rightVector);
        }

        const auto lookUp = random(generator) == 1 ? true : false;

        cameraMotion.SetLookUp(lookUp);

        if (lookUp)
        {
            const Mathematics::MatrixF rotation{ right, rotationSpeed };

            const auto directionVector = rotation * camera->GetDirectionVector();
            const auto upVector = rotation * camera->GetUpVector();
            const auto rightVector = rotation * camera->GetRightVector();
            camera->SetAxes(directionVector, upVector, rightVector);
        }

        const auto lookDown = random(generator) == 1 ? true : false;

        cameraMotion.SetLookDown(lookDown);

        if (lookDown)
        {
            const Mathematics::MatrixF rotation{ right, -rotationSpeed };

            const auto directionVector = rotation * camera->GetDirectionVector();
            const auto upVector = rotation * camera->GetUpVector();
            const auto rightVector = rotation * camera->GetRightVector();
            camera->SetAxes(directionVector, upVector, rightVector);
        }

        const auto moveUp = random(generator) == 1 ? true : false;

        cameraMotion.SetMoveUp(moveUp);

        if (moveUp)
        {
            auto position = camera->GetPosition();
            position += translationSpeed * up;
            camera->SetPosition(position);
        }

        const auto moveDown = random(generator) == 1 ? true : false;

        cameraMotion.SetMoveDown(moveDown);

        if (moveDown)
        {
            auto position = camera->GetPosition();
            position -= translationSpeed * up;
            camera->SetPosition(position);
        }

        const auto moveRight = random(generator) == 1 ? true : false;

        cameraMotion.SetMoveRight(moveRight);

        if (moveRight)
        {
            auto position = camera->GetPosition();
            position += translationSpeed * right;
            camera->SetPosition(position);
        }

        const auto moveLeft = random(generator) == 1 ? true : false;

        cameraMotion.SetMoveLeft(moveLeft);

        if (moveLeft)
        {
            auto position = camera->GetPosition();
            position -= translationSpeed * right;
            camera->SetPosition(position);
        }

        cameraMotion.MoveCamera();
        AssertCamera(camera, cameraMotion.GetCamera());
    }
}

void Framework::CameraMotionTesting::AssertCamera(const CameraSmartPointer& lhs, const CameraSmartPointer& rhs)
{
    using APointApproximate = bool (*)(const Mathematics::APointF&, const Mathematics::APointF&, float);
    APointApproximate aPointApproximate{ Mathematics::Approximate<float> };

    using AVectorApproximate = bool (*)(const Mathematics::AVectorF&, const Mathematics::AVectorF&, float);
    AVectorApproximate aVectorApproximate{ Mathematics::Approximate<float> };

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointApproximate, lhs->GetPosition(), rhs->GetPosition(), Mathematics::MathF::epsilon);
    ASSERT_APPROXIMATE_USE_FUNCTION(aVectorApproximate, lhs->GetDirectionVector(), rhs->GetDirectionVector(), Mathematics::MathF::epsilon);
    ASSERT_APPROXIMATE_USE_FUNCTION(aVectorApproximate, lhs->GetUpVector(), rhs->GetUpVector(), Mathematics::MathF::epsilon);
    ASSERT_APPROXIMATE_USE_FUNCTION(aVectorApproximate, lhs->GetRightVector(), rhs->GetRightVector(), Mathematics::MathF::epsilon);
}
///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/05 19:08)

#ifndef FRAMEWORK_APPLICATION_CAMERA_MOTION_IMPL_H
#define FRAMEWORK_APPLICATION_CAMERA_MOTION_IMPL_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/SceneGraph/Camera.h"

#include <array>

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE CameraMotionImpl
    {
    public:
        using ClassType = CameraMotionImpl;
        using Camera = Rendering::Camera;
        using CameraSharedPtr = Rendering::CameraSharedPtr;

    public:
        CameraMotionImpl(float translationSpeed, float rotationSpeed, float translationSpeedFactor, float rotationSpeedFactor);

        CLASS_INVARIANT_DECLARE;

        NODISCARD CameraSharedPtr GetCamera() noexcept;

        NODISCARD bool MoveCamera();

        void SlowerCameraTranslation() noexcept;
        void FasterCameraTranslation() noexcept;
        void SlowerCameraRotation() noexcept;
        void FasterCameraRotation() noexcept;

        void SetMoveForward(bool pressed) noexcept;
        void SetMoveBackward(bool pressed) noexcept;
        void SetTurnLeft(bool pressed) noexcept;
        void SetTurnRight(bool pressed) noexcept;
        void SetLookUp(bool pressed) noexcept;
        void SetLookDown(bool pressed) noexcept;
        void SetMoveUp(bool pressed) noexcept;
        void SetMoveDown(bool pressed) noexcept;
        void SetMoveRight(bool pressed) noexcept;
        void SetMoveLeft(bool pressed) noexcept;

        NODISCARD float GetRotationSpeed() const noexcept;
        NODISCARD float GetTranslationSpeed() const noexcept;

    private:
        using AVector = Mathematics::AVector<float>;
        using APoint = Mathematics::APoint<float>;
        using Matrix = Mathematics::Matrix<float>;

    private:
        void MoveForward();
        void MoveBackward();
        void MoveUp();
        void MoveDown();
        void MoveLeft();
        void MoveRight();
        void TurnLeft();
        void TurnRight();
        void LookUp();
        void LookDown();

    private:
        CameraSharedPtr camera;
        AVector worldDirection;
        AVector worldUp;
        AVector worldRight;
        float translationSpeed;
        float translationSpeedFactor;
        float rotationSpeed;
        float rotationSpeedFactor;
        bool moveForwardPressed;
        bool moveBackwardPressed;
        bool turnLeftPressed;
        bool turnRightPressed;
        bool lookUpPressed;
        bool lookDownPressed;
        bool moveUpPressed;
        bool moveDownPressed;
        bool moveRightPressed;
        bool moveLeftPressed;
    };
}

#endif  // FRAMEWORK_APPLICATION_CAMERA_MOTION_IMPL_H

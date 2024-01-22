/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:24)

#ifndef FRAMEWORK_APPLICATION_CAMERA_MOTION_H
#define FRAMEWORK_APPLICATION_CAMERA_MOTION_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "Rendering/SceneGraph/Camera.h"

FRAMEWORK_NON_COPY_EXPORT_IMPL(CameraMotionImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE CameraMotion
    {
    public:
        NON_COPY_TYPE_DECLARE(CameraMotion);

        using CameraSharedPtr = Rendering::CameraSharedPtr;
        using ConstCameraSharedPtr = Rendering::ConstCameraSharedPtr;

    public:
        CameraMotion(float translationSpeed, float rotationSpeed, float translationSpeedFactor = 2.0f, float rotationSpeedFactor = 2.0f);

        CLASS_INVARIANT_DECLARE;

        NODISCARD CameraSharedPtr GetCamera() noexcept;

        bool MoveCamera();

        void SlowerCameraTranslation() noexcept;
        void FasterCameraTranslation() noexcept;
        void SlowerCameraRotation() noexcept;
        void FasterCameraRotation() noexcept;

        void SetMoveForward(bool pressed) noexcept;  // 向前
        void SetMoveBackward(bool pressed) noexcept;  // 向后
        void SetTurnLeft(bool pressed) noexcept;  // 左转
        void SetTurnRight(bool pressed) noexcept;  // 右转
        void SetLookUp(bool pressed) noexcept;  // 向上看
        void SetLookDown(bool pressed) noexcept;  // 向下看
        void SetMoveUp(bool pressed) noexcept;  // 向上
        void SetMoveDown(bool pressed) noexcept;  // 向下
        void SetMoveRight(bool pressed) noexcept;  // 向左
        void SetMoveLeft(bool pressed) noexcept;  // 向右

        NODISCARD float GetRotationSpeed() const noexcept;
        NODISCARD float GetTranslationSpeed() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // FRAMEWORK_APPLICATION_CAMERA_MOTION_H

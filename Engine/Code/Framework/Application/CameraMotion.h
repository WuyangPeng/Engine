/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 15:24)

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

        void SetMoveForward(bool pressed) noexcept;  // ��ǰ
        void SetMoveBackward(bool pressed) noexcept;  // ���
        void SetTurnLeft(bool pressed) noexcept;  // ��ת
        void SetTurnRight(bool pressed) noexcept;  // ��ת
        void SetLookUp(bool pressed) noexcept;  // ���Ͽ�
        void SetLookDown(bool pressed) noexcept;  // ���¿�
        void SetMoveUp(bool pressed) noexcept;  // ����
        void SetMoveDown(bool pressed) noexcept;  // ����
        void SetMoveRight(bool pressed) noexcept;  // ����
        void SetMoveLeft(bool pressed) noexcept;  // ����

        NODISCARD float GetRotationSpeed() const noexcept;
        NODISCARD float GetTranslationSpeed() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // FRAMEWORK_APPLICATION_CAMERA_MOTION_H

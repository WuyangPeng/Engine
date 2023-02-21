///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/06 15:58)

#ifndef FRAMEWORK_MIDDLE_LAYER_CAMERA_MODEL_MIDDLE_LAYER_IMPL_H
#define FRAMEWORK_MIDDLE_LAYER_CAMERA_MODEL_MIDDLE_LAYER_IMPL_H

#include "Framework/FrameworkDll.h"

#include "Rendering/DataTypes/Transform.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Framework/Application/ApplicationFwd.h"

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE CameraModelMiddleLayerImpl
    {
    public:
        using ClassType = CameraModelMiddleLayerImpl;
        using APoint = Mathematics::APointF;
        using AVector = Mathematics::AVectorF;
        using NumericalValueSymbol = Mathematics::NumericalValueSymbol;
        using Transform = Rendering::TransformF;
        using CameraSharedPtr = Rendering::CameraSharedPtr;
        using ConstCameraSharedPtr = Rendering::ConstCameraSharedPtr;

    public:
        CameraModelMiddleLayerImpl() noexcept;
        ~CameraModelMiddleLayerImpl() noexcept = default;
        CameraModelMiddleLayerImpl(const CameraModelMiddleLayerImpl& rhs) noexcept = delete;
        CameraModelMiddleLayerImpl& operator=(const CameraModelMiddleLayerImpl& rhs) noexcept = delete;
        CameraModelMiddleLayerImpl(CameraModelMiddleLayerImpl&& rhs) noexcept;
        CameraModelMiddleLayerImpl& operator=(CameraModelMiddleLayerImpl&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        void InitializeCameraMotion(float translationSpeed, float rotationSpeed, float translationSpeedFactor, float rotationSpeedFactor);

        void InitializeObjectMotion();

        NODISCARD ConstCameraSharedPtr GetCamera() const;
        NODISCARD CameraSharedPtr GetCamera();

        NODISCARD Transform GetMotionObjectLocalTransform() const;

        void Terminate() noexcept;

        // CameraMotion
        NODISCARD bool MoveCamera();

        void SlowerCameraTranslation() noexcept;
        void FasterCameraTranslation() noexcept;
        void SlowerCameraRotation() noexcept;
        void FasterCameraRotation() noexcept;

        NODISCARD float GetRotationSpeed() const;
        NODISCARD float GetTranslationSpeed() const;

        void SetMoveForward(bool pressed) noexcept;  // 向前
        void SetMoveBackward(bool pressed) noexcept;  // 向后
        void SetTurnLeft(bool pressed) noexcept;  // 左转
        void SetTurnRight(bool pressed) noexcept;  // 右转
        void SetLookUp(bool pressed) noexcept;  // 向上看
        void SetLookDown(bool pressed) noexcept;  // 向下看
        void SetMoveUp(bool pressed) noexcept;  // 向上
        void SetMoveDown(bool pressed) noexcept;  // 向下
        void SetMoveRight(bool pressed) noexcept;  // 向右
        void SetMoveLeft(bool pressed) noexcept;  // 向左

        NODISCARD APoint GetCameraPosition() const;
        NODISCARD AVector GetCameraDirectionVector() const;
        NODISCARD AVector GetCameraUpVector() const;
        NODISCARD AVector GetCameraRightVector() const;

        // ObjectMotion
        NODISCARD bool MoveObject();
        void SetBeginTrack(float xTrack, float yTrack) noexcept;
        void SetEndTrack(float xTrack, float yTrack) noexcept;
        void RotateTrackBall();
        void SetTrackBallDow(bool value) noexcept;
        void SetSaveRotate() noexcept(gAssert < 2 || gRenderingAssert < 2);
        void SetDoRoll(NumericalValueSymbol doRoll) noexcept;
        void SetDoYaw(NumericalValueSymbol doYaw) noexcept;
        void SetDoPitch(NumericalValueSymbol doPitch) noexcept;
        NODISCARD bool GetTrackBallDow() const noexcept;

    private:
        using CameraMotionSharedPtr = std::shared_ptr<CameraMotion>;
        using ObjectMotionSharedPtr = std::shared_ptr<ObjectMotion>;

    private:
        CameraMotionSharedPtr cameraMotion;
        ObjectMotionSharedPtr objectMotion;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_CAMERA_MODEL_MIDDLE_LAYER_IMPL_H

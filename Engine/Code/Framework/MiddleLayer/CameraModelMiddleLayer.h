///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/05 16:20)

#ifndef FRAMEWORK_MIDDLE_LAYER_CAMERA_MODEL_MIDDLE_LAYER_H
#define FRAMEWORK_MIDDLE_LAYER_CAMERA_MODEL_MIDDLE_LAYER_H

#include "Framework/FrameworkDll.h"

#include "ModelMiddleLayer.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Transform.h"

FRAMEWORK_NON_COPY_EXPORT_IMPL(CameraModelMiddleLayerImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE CameraModelMiddleLayer : public ModelMiddleLayer
    {
    public:
        NON_COPY_TYPE_DECLARE(CameraModelMiddleLayer);
        using ParentType = ModelMiddleLayer;

        using APoint = Mathematics::APointF;
        using AVector = Mathematics::AVectorF;
        using NumericalValueSymbol = Mathematics::NumericalValueSymbol;
        using Transform = Mathematics::TransformF;

    public:
        CameraModelMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool Initialize() override;
        void Terminate() override;
        NODISCARD bool Idle(int64_t aTimeDelta) override;

    public:
        NODISCARD Transform GetMotionObjectLocalTransform() const;

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
        void SetTrackBallDow(bool trackBallDow) noexcept;
        void SetSaveRotate();
        void SetDoRoll(NumericalValueSymbol doRoll) noexcept;
        void SetDoYaw(NumericalValueSymbol doYaw) noexcept;
        void SetDoPitch(NumericalValueSymbol doPitch) noexcept;
        NODISCARD bool GetTrackBallDow() const noexcept;

        void RotateTrackBall(const WindowPoint& point, const CameraViewMiddleLayer& cameraViewMiddleLayer);
        void SetBeginTrack(const WindowPoint& point, const CameraViewMiddleLayer& cameraViewMiddleLayer);

    protected:
        void InitializeCameraMotion(float translationSpeed, float rotationSpeed, float translationSpeedFactor, float rotationSpeedFactor);

        void InitializeObjectMotion();

    private:
        PackageType impl;
    };

    using CameraModelMiddleLayerSharedPtr = std::shared_ptr<CameraModelMiddleLayer>;
    using ConstCameraModelMiddleLayerSharedPtr = std::shared_ptr<const CameraModelMiddleLayer>;
}

#endif  // FRAMEWORK_MIDDLE_LAYER_CAMERA_MODEL_MIDDLE_LAYER_H

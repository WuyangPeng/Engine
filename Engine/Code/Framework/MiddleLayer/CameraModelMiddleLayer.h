///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 14:21)

#ifndef FRAMEWORK_MIDDLE_LAYER_CAMERA_MODEL_MIDDLE_LAYER_H
#define FRAMEWORK_MIDDLE_LAYER_CAMERA_MODEL_MIDDLE_LAYER_H

#include "Framework/FrameworkDll.h"

#include "ModelMiddleLayer.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Rendering/DataTypes/Transform.h"

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
        using Transform = Rendering::TransformF;

    public:
        explicit CameraModelMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);
        ~CameraModelMiddleLayer() noexcept = default;
        CameraModelMiddleLayer(const CameraModelMiddleLayer& rhs) noexcept = delete;
        CameraModelMiddleLayer& operator=(const CameraModelMiddleLayer& rhs) noexcept = delete;
        CameraModelMiddleLayer(CameraModelMiddleLayer&& rhs) noexcept;
        CameraModelMiddleLayer& operator=(CameraModelMiddleLayer&& rhs) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool Initialize() override;
        void Terminate() override;
        NODISCARD bool Idle(int64_t aTimeDelta) override;

    public:
        NODISCARD Transform GetMotionObjectLocalTransform() const;

        // CameraMotion
        bool MoveCamera();

        void SlowerCameraTranslation() noexcept;
        void FasterCameraTranslation() noexcept;
        void SlowerCameraRotation() noexcept;
        void FasterCameraRotation() noexcept;

        NODISCARD float GetRotationSpeed() const;
        NODISCARD float GetTranslationSpeed() const;

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

        NODISCARD APoint GetCameraPosition() const;
        NODISCARD AVector GetCameraDirectionVector() const;
        NODISCARD AVector GetCameraUpVector() const;
        NODISCARD AVector GetCameraRightVector() const;

        // ObjectMotion
        bool MoveObject();

        void SetBeginTrack(float xTrack, float yTrack) noexcept;
        void SetEndTrack(float xTrack, float yTrack) noexcept;
        void RotateTrackBall();
        void SetTrackBallDow(bool value) noexcept;
        void SetSaveRotate() noexcept(gAssert < 2 || gRenderingAssert < 2);
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
        int64_t timeDelta;
    };

    using CameraModelMiddleLayerSharedPtr = std::shared_ptr<CameraModelMiddleLayer>;
    using ConstCameraModelMiddleLayerSharedPtr = std::shared_ptr<const CameraModelMiddleLayer>;
}

#endif  // FRAMEWORK_MIDDLE_LAYER_CAMERA_MODEL_MIDDLE_LAYER_H

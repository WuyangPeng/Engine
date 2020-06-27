// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 14:47)

#ifndef FRAMEWORK_MIDDLE_LAYER_CAMERA_MODEL_MIDDLE_LAYER_H
#define FRAMEWORK_MIDDLE_LAYER_CAMERA_MODEL_MIDDLE_LAYER_H

#include "Framework/FrameworkDll.h"

#include "ModelMiddleLayer.h"
#include "CoreTools/Helper/ExportMacro.h" 
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Rendering/DataTypes/Transform.h"

FRAMEWORK_EXPORT_SHARED_PTR(CameraModelMiddleLayerImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE CameraModelMiddleLayer : public ModelMiddleLayer
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(CameraModelMiddleLayer);
		using ParentType = ModelMiddleLayer;
		using APoint = Mathematics::APointf;
		using AVector = Mathematics::AVectorf;
		using NumericalValueSymbol = Mathematics::NumericalValueSymbol;
		using Transform = Rendering::Transform;

	public:
		explicit CameraModelMiddleLayer(MiddleLayerPlatform middleLayerPlatform);
		~CameraModelMiddleLayer() noexcept = default;
		CameraModelMiddleLayer(const CameraModelMiddleLayer& rhs) noexcept = delete;
		CameraModelMiddleLayer& operator=(const CameraModelMiddleLayer& rhs) noexcept = delete;
		CameraModelMiddleLayer(CameraModelMiddleLayer&& rhs) noexcept;
		CameraModelMiddleLayer& operator=(CameraModelMiddleLayer&& rhs) noexcept;

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		bool Initialize() override;
		void Terminate() override;
		bool Idle(int64_t timeDelta) override;

	public:
		const Transform GetMotionObjectLocalTransform() const;

		// CameraMotion
		bool MoveCamera();

		void SlowerCameraTranslation() noexcept;
		void FasterCameraTranslation() noexcept;
		void SlowerCameraRotation() noexcept;
		void FasterCameraRotation() noexcept;

		float GetRotationSpeed() const;
		float GetTranslationSpeed() const;

		void SetMoveForward(bool pressed) noexcept; // 向前
		void SetMoveBackward(bool pressed) noexcept; // 向后
		void SetTurnLeft(bool pressed) noexcept; // 左转
		void SetTurnRight(bool pressed) noexcept;// 右转
		void SetLookUp(bool pressed) noexcept;// 向上看
		void SetLookDown(bool pressed) noexcept;// 向下看
		void SetMoveUp(bool pressed) noexcept;// 向上
		void SetMoveDown(bool pressed) noexcept;// 向下
		void SetMoveRight(bool pressed) noexcept;// 向右
		void SetMoveLeft(bool pressed) noexcept; // 向左	

		const APoint GetCameraPosition() const;
		const AVector GetCameraDirectionVector() const;
		const AVector GetCameraUpVector() const;
		const AVector GetCameraRightVector() const;

		// ObjectMotion
		bool MoveObject();

		void SetBeginTrack(float xTrack, float yTrack) noexcept;
		void SetEndTrack(float xTrack, float yTrack) noexcept;
		void RotateTrackBall();
		void SetTrackBallDow(bool value) noexcept;
		void SetSaveRotate();
		void SetDoRoll(NumericalValueSymbol doRoll) noexcept;
		void SetDoYaw(NumericalValueSymbol doYaw) noexcept;
		void SetDoPitch(NumericalValueSymbol doPitch) noexcept;
		bool GetTrackBallDow() const noexcept;

		void RotateTrackBall(const WindowPoint& point, const CameraViewMiddleLayer& cameraViewMiddleLayer);
		void SetBeginTrack(const WindowPoint& point, const CameraViewMiddleLayer& cameraViewMiddleLayer);

	protected:
		void InitializeCameraMotion(float translationSpeed, float rotationSpeed, float translationSpeedFactor, float rotationSpeedFactor);

		void InitializeObjectMotion();

	private:
		IMPL_TYPE_DECLARE(CameraModelMiddleLayer);
		int64_t m_TimeDelta;
	};

	using CameraModelMiddleLayerSharedPtr = std::shared_ptr<CameraModelMiddleLayer>;
	using ConstCameraModelMiddleLayerSharedPtr = std::shared_ptr<const CameraModelMiddleLayer>;
}

#endif // FRAMEWORK_MIDDLE_LAYER_CAMERA_MODEL_MIDDLE_LAYER_H


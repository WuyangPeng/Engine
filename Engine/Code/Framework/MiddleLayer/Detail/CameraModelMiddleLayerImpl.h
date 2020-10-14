// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.3.0.1 (2020/05/21 14:45)

#ifndef FRAMEWORK_MIDDLE_LAYER_CAMERA_MODEL_MIDDLE_LAYER_IMPL_H
#define FRAMEWORK_MIDDLE_LAYER_CAMERA_MODEL_MIDDLE_LAYER_IMPL_H

#include "Framework/FrameworkDll.h"

#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/DataTypes/Transform.h"
#include "Framework/Application/ApplicationFwd.h" 

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE CameraModelMiddleLayerImpl
	{
	public:
		using ClassType = CameraModelMiddleLayerImpl;
		using APoint = Mathematics::FloatAPoint;
		using AVector = Mathematics::FloatAVector;
		using NumericalValueSymbol = Mathematics::NumericalValueSymbol;
		using Transform = Rendering::FloatTransform;
		using CameraSmartPointer = Rendering::CameraSharedPtr;
		using ConstCameraSmartPointer = Rendering::ConstCameraSharedPtr;

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

		ConstCameraSmartPointer GetCamera() const;
		CameraSmartPointer GetCamera();

		const Transform GetMotionObjectLocalTransform() const;

		void Terminate() noexcept;

		// CameraMotion
		bool MoveCamera();

		void SlowerCameraTranslation() noexcept;
		void FasterCameraTranslation() noexcept;
		void SlowerCameraRotation() noexcept;
		void FasterCameraRotation() noexcept;

		float GetRotationSpeed() const;
		float GetTranslationSpeed() const;

		void SetMoveForward(bool pressed) noexcept; // ��ǰ
		void SetMoveBackward(bool pressed) noexcept; // ���
		void SetTurnLeft(bool pressed) noexcept; // ��ת
		void SetTurnRight(bool pressed) noexcept;// ��ת
		void SetLookUp(bool pressed) noexcept;// ���Ͽ�
		void SetLookDown(bool pressed) noexcept;// ���¿�
		void SetMoveUp(bool pressed) noexcept;// ����
		void SetMoveDown(bool pressed) noexcept;// ����
		void SetMoveRight(bool pressed) noexcept;// ����
		void SetMoveLeft(bool pressed) noexcept; // ����	

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

	private:
		using CameraMotionSharedPtr = std::shared_ptr<CameraMotion>;
		using ObjectMotionSharedPtr = std::shared_ptr<ObjectMotion>;

	private:
		CameraMotionSharedPtr m_CameraMotion;
		ObjectMotionSharedPtr m_ObjectMotion;
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_CAMERA_MODEL_MIDDLE_LAYER_IMPL_H


// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:38)

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
		using CameraSmartPointer = Rendering::CameraSharedPtr;	

	public:
		CameraMotionImpl(float translationSpeed, float rotationSpeed, float translationSpeedFactor, float rotationSpeedFactor);

		CLASS_INVARIANT_DECLARE;

		const CameraSmartPointer GetCameraPtr() noexcept;

		bool MoveCamera();

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

		float GetRotationSpeed() const noexcept;
		float GetTranslationSpeed() const noexcept;	

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
		CameraSmartPointer m_Camera;
		AVector m_WorldDirection;
		AVector	m_WorldUp;
		AVector	m_WorldRight;
		float m_TranslationSpeed;
		float m_TranslationSpeedFactor;
		float m_RotationSpeed;
		float m_RotationSpeedFactor;
		bool m_MoveForwardPressed;
		bool m_MoveBackwardPressed;
		bool m_TurnLeftPressed;
		bool m_TurnRightPressed;
		bool m_LookUpPressed;
		bool m_LookDownPressed;
		bool m_MoveUpPressed;
		bool m_MoveDownPressed;
		bool m_MoveRightPressed;
		bool m_MoveLeftPressed;
	};
}

#endif // FRAMEWORK_APPLICATION_CAMERA_MOTION_IMPL_H




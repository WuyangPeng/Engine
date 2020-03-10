// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 10:58)

#ifndef FRAMEWORK_APPLICATION_CAMERA_MOTION_IMPL_H
#define FRAMEWORK_APPLICATION_CAMERA_MOTION_IMPL_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "Rendering/SceneGraph/Camera.h"

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE CameraMotionImpl
	{
	public:
		using ClassType = CameraMotionImpl;
		using ConstCameraSmartPointer = Rendering::ConstCameraSmartPointer;
		using CameraSmartPointer = Rendering::CameraSmartPointer;
		using Camera = Rendering::Camera;

	public:
		CameraMotionImpl(float translationSpeed,float rotationSpeed,float translationSpeedFactor = 2.0f, float rotationSpeedFactor = 2.0f);
	
		CLASS_INVARIANT_DECLARE;

		const ConstCameraSmartPointer GetCameraPtr() const;

		bool MoveCamera ();		

		void SlowerCameraTranslation ();
		void FasterCameraTranslation ();
		void SlowerCameraRotation ();
		void FasterCameraRotation ();

		void SetMoveForward(bool pressed);
		void SetMoveBackward(bool pressed);
		void SetTurnLeft(bool pressed);
		void SetTurnRight(bool pressed);
		void SetLookUp(bool pressed);
		void SetLookDown(bool pressed);
		void SetMoveUp(bool pressed);
		void SetMoveDown(bool pressed);
		void SetMoveRight(bool pressed);
		void SetMoveLeft(bool pressed);

        float GetRotationSpeed() const;
		float GetTranslationSpeed() const;

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
		AVector m_WorldAxis[3];
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



	
// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/08/01 11:35)
 
#ifndef FRAMEWORK_MIDDLE_LAYER_CAMERA_MODEL_MIDDLE_LAYER_IMPL_H
#define FRAMEWORK_MIDDLE_LAYER_CAMERA_MODEL_MIDDLE_LAYER_IMPL_H

#include "Framework/FrameworkDll.h"

#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/DataTypes/Transform.h"

#include <boost/noncopyable.hpp>

namespace Framework
{
	class CameraMotion;
	class ObjectMotion;

	class FRAMEWORK_HIDDEN_DECLARE CameraModelMiddleLayerImpl : private boost::noncopyable
	{
	public:
		using ClassType = CameraModelMiddleLayerImpl;
		using ConstCameraSmartPointer = Rendering::ConstCameraSmartPointer;
		using APoint = Mathematics::APointf;
		using AVector = Mathematics::AVectorf;
		using Transform = Rendering::Transform;

	public:
		CameraModelMiddleLayerImpl();
		~CameraModelMiddleLayerImpl();
	
		CLASS_INVARIANT_DECLARE;

		// CameraMotion
		bool MoveCamera ();	

		void SlowerCameraTranslation ();
		void FasterCameraTranslation ();
		void SlowerCameraRotation ();
		void FasterCameraRotation ();

		float GetRotationSpeed() const;
		float GetTranslationSpeed() const;

		void SetMoveForward(bool pressed); // ��ǰ
		void SetMoveBackward(bool pressed); // ���
		void SetTurnLeft(bool pressed); // ��ת
		void SetTurnRight(bool pressed);// ��ת
		void SetLookUp(bool pressed);// ���Ͽ�
		void SetLookDown(bool pressed);// ���¿�
		void SetMoveUp(bool pressed);// ����
		void SetMoveDown(bool pressed);// ����
		void SetMoveRight(bool pressed);// ����
		void SetMoveLeft(bool pressed); // ����	

		const APoint GetCameraPosition() const;
		const AVector GetCameraDirectionVector() const;
		const AVector GetCameraUpVector() const;
		const AVector GetCameraRightVector() const;

		// ObjectMotion
		bool MoveObject ();
		void SetBeginTrack(float xTrack,float yTrack);
		void SetEndTrack(float xTrack,float yTrack);
		void RotateTrackBall();
		void SetTrackBallDow(bool value);
		void SetSaveRotate();
		void SetDoRoll(Mathematics::NumericalValueSymbol doRoll);
		void SetDoYaw(Mathematics::NumericalValueSymbol doYaw);
		void SetDoPitch(Mathematics::NumericalValueSymbol doPitch);
		bool GetTrackBallDow() const;
	 
		void InitializeCameraMotion(float translationSpeed, float rotationSpeed, float translationSpeedFactor,float rotationSpeedFactor);

		void InitializeObjectMotion();

		ConstCameraSmartPointer GetCamera() const;

		const Transform GetMotionObjectLocalTransform() const;

		void Terminate();

	private:		
		std::shared_ptr<CameraMotion> m_CameraMotion;
		std::shared_ptr<ObjectMotion> m_ObjectMotion;
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_CAMERA_MODEL_MIDDLE_LAYER_IMPL_H


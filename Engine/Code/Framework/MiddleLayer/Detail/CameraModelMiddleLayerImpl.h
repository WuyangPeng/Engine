// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 11:35)
 
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

		void SetMoveForward(bool pressed); // 向前
		void SetMoveBackward(bool pressed); // 向后
		void SetTurnLeft(bool pressed); // 左转
		void SetTurnRight(bool pressed);// 右转
		void SetLookUp(bool pressed);// 向上看
		void SetLookDown(bool pressed);// 向下看
		void SetMoveUp(bool pressed);// 向上
		void SetMoveDown(bool pressed);// 向下
		void SetMoveRight(bool pressed);// 向右
		void SetMoveLeft(bool pressed); // 向左	

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


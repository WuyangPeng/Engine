// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 11:39)
 
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
		using Transform = Rendering::Transform;

	public:
		CameraModelMiddleLayer();
		virtual ~CameraModelMiddleLayer();
	
		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual bool Initialize();
		virtual void Terminate();
		virtual bool Idle(int64_t timeDelta);

	 public:
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

		const Transform GetMotionObjectLocalTransform() const;

	protected:
		void InitializeCameraMotion (float translationSpeed, float rotationSpeed, float translationSpeedFactor, float rotationSpeedFactor);

		void InitializeObjectMotion();

	private:		
		IMPL_TYPE_DECLARE(CameraModelMiddleLayer);
		int64_t m_TimeDelta;
	};

	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, CameraModelMiddleLayer);
}

#endif // FRAMEWORK_MIDDLE_LAYER_CAMERA_MODEL_MIDDLE_LAYER_H


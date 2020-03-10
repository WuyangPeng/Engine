// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/08/01 11:39)
 
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


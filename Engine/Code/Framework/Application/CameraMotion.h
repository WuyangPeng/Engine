// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/08/01 11:08)

#ifndef FRAMEWORK_APPLICATION_CAMERA_MOTION_H
#define FRAMEWORK_APPLICATION_CAMERA_MOTION_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "Rendering/SceneGraph/Camera.h"

#include <boost/noncopyable.hpp>

FRAMEWORK_EXPORT_SHARED_PTR(CameraMotionImpl);
EXPORT_NONCOPYABLE_CLASS(FRAMEWORK);

namespace Rendering
{
    class Camera;
}

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE CameraMotion : private boost::noncopyable 
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(CameraMotion);
		using ConstCameraSmartPointer = Rendering::ConstCameraSmartPointer;
		using CameraSmartPointer = Rendering::CameraSmartPointer;

	public:
		CameraMotion(float translationSpeed,float rotationSpeed,float translationSpeedFactor = 2.0f,float rotationSpeedFactor = 2.0f);
	
		CLASS_INVARIANT_DECLARE;

		const ConstCameraSmartPointer GetCameraPtr() const;

		bool MoveCamera ();	

		void SlowerCameraTranslation ();
		void FasterCameraTranslation ();
		void SlowerCameraRotation ();
		void FasterCameraRotation ();

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

        float GetRotationSpeed() const;
		float GetTranslationSpeed() const;

	private:
        IMPL_TYPE_DECLARE(CameraMotion);
	};
}

#endif // FRAMEWORK_APPLICATION_CAMERA_MOTION_H



	
// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 11:08)

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

		void SetMoveForward(bool pressed); // 向前
		void SetMoveBackward(bool pressed); // 向后
		void SetTurnLeft(bool pressed); // 左转
		void SetTurnRight(bool pressed);// 右转
		void SetLookUp(bool pressed);// 向上看
		void SetLookDown(bool pressed);// 向下看
		void SetMoveUp(bool pressed);// 向上
		void SetMoveDown(bool pressed);// 向下
		void SetMoveRight(bool pressed);// 向左
		void SetMoveLeft(bool pressed); // 向右

        float GetRotationSpeed() const;
		float GetTranslationSpeed() const;

	private:
        IMPL_TYPE_DECLARE(CameraMotion);
	};
}

#endif // FRAMEWORK_APPLICATION_CAMERA_MOTION_H



	
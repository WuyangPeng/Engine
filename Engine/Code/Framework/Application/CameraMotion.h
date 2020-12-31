// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 13:42)

#ifndef FRAMEWORK_APPLICATION_CAMERA_MOTION_H
#define FRAMEWORK_APPLICATION_CAMERA_MOTION_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "Rendering/SceneGraph/Camera.h"

#include <boost/noncopyable.hpp>

FRAMEWORK_EXPORT_SHARED_PTR(CameraMotionImpl);
EXPORT_NONCOPYABLE_CLASS(FRAMEWORK);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE CameraMotion : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(CameraMotion);
		using CameraSmartPointer = Rendering::CameraSharedPtr;
		using ConstCameraSmartPointer = Rendering::ConstCameraSharedPtr;

	public:
		CameraMotion(float translationSpeed, float rotationSpeed, float translationSpeedFactor = 2.0f, float rotationSpeedFactor = 2.0f);

		CLASS_INVARIANT_DECLARE;

		const CameraSmartPointer GetCameraPtr() noexcept;

		bool MoveCamera();

		void SlowerCameraTranslation() noexcept;
		void FasterCameraTranslation() noexcept;
		void SlowerCameraRotation() noexcept;
		void FasterCameraRotation() noexcept;

		void SetMoveForward(bool pressed) noexcept; // 向前
		void SetMoveBackward(bool pressed) noexcept; // 向后
		void SetTurnLeft(bool pressed) noexcept; // 左转
		void SetTurnRight(bool pressed) noexcept;// 右转
		void SetLookUp(bool pressed) noexcept;// 向上看
		void SetLookDown(bool pressed) noexcept;// 向下看
		void SetMoveUp(bool pressed) noexcept;// 向上
		void SetMoveDown(bool pressed) noexcept;// 向下
		void SetMoveRight(bool pressed) noexcept;// 向左
		void SetMoveLeft(bool pressed)noexcept; // 向右

		float GetRotationSpeed() const noexcept;
		float GetTranslationSpeed() const noexcept;

	private:
		IMPL_TYPE_DECLARE(CameraMotion);
	};
}

#endif // FRAMEWORK_APPLICATION_CAMERA_MOTION_H




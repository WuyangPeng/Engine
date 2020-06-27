// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:46)

#ifndef FRAMEWORK_APPLICATION_OBJECT_MOTION_H
#define FRAMEWORK_APPLICATION_OBJECT_MOTION_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Spatial.h"

FRAMEWORK_EXPORT_SHARED_PTR(ObjectMotionImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE ObjectMotion
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(ObjectMotion);
		using Matrix = Mathematics::Matrixf;
		using AVector = Mathematics::AVectorf;
		using Transform = Rendering::Transform;
		using SpatialSmartPointer = Rendering::SpatialSmartPointer;
		using ConstCameraSmartPointer = Rendering::ConstCameraSmartPointer;

	public:
		explicit ObjectMotion(const SpatialSmartPointer& motionObject);

		CLASS_INVARIANT_DECLARE;

		bool MoveObject(float rotationSpeed);
		void RotateTrackBall(const ConstCameraSmartPointer& camera);

		void SetDoRoll(int value) noexcept;
		void SetDoYaw(int value) noexcept;
		void SetDoPitch(int value) noexcept;
		void SetTrackBallDow(bool value) noexcept;
		bool GetTrackBallDow() const noexcept;

		void SetBeginTrack(float xTrack, float yTrack) noexcept;
		void SetEndTrack(float xTrack, float yTrack) noexcept;
		void SetSaveRotate();

		const Transform GetMotionObjectLocalTransform() const;

	private:
		IMPL_TYPE_DECLARE(ObjectMotion);
	};
}

#endif // FRAMEWORK_APPLICATION_OBJECT_MOTION_H




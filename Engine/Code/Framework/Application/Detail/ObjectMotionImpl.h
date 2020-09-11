// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:39)

#ifndef FRAMEWORK_APPLICATION_OBJECT_MOTION_IMPL_H
#define FRAMEWORK_APPLICATION_OBJECT_MOTION_IMPL_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Spatial.h"

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE ObjectMotionImpl
	{
	public:
		using ClassType = ObjectMotionImpl;
		using Matrix = Mathematics::FloatMatrix;
		using AVector = Mathematics::FloatAVector;
		using Transform = Rendering::FloatTransform;
		using SpatialSmartPointer = Rendering::SpatialSmartPointer;
		using ConstCameraSmartPointer = Rendering::ConstCameraSmartPointer;	

	public:
                explicit ObjectMotionImpl(const SpatialSmartPointer& motionObject) noexcept;

		CLASS_INVARIANT_DECLARE;

		bool MoveObject(float rotationSpeed);
		void RotateTrackBall(const ConstCameraSmartPointer& camera);

		void SetDoRoll(int value) noexcept;
		void SetDoYaw(int value) noexcept;
		void SetDoPitch(int value) noexcept;
		void SetTrackBallDow(bool value) noexcept;
		void SetBeginTrack(float xTrack, float yTrack) noexcept;
		void SetEndTrack(float xTrack, float yTrack) noexcept;
		void SetSaveRotate();
		bool GetTrackBallDow() const noexcept;

		const Transform GetMotionObjectLocalTransform() const;

	private:
		SpatialSmartPointer m_MotionObject;
		int m_DoRoll;
		int m_DoYaw;
		int m_DoPitch;
		float m_BeginXTrack;
		float m_BeginYTrack;
		float m_EndXTrack;
		float m_EndYTrack;
		Matrix m_SaveRotate;
		bool m_UseTrackBall;
		bool m_TrackBallDown;
	};
}

#endif // FRAMEWORK_APPLICATION_CAMERA_MOTION_IMPL_H




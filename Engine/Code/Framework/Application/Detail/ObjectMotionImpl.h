// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:00)

#ifndef FRAMEWORK_APPLICATION_OBJECT_MOTION_IMPL_H
#define FRAMEWORK_APPLICATION_OBJECT_MOTION_IMPL_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "Rendering/SceneGraph/Spatial.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Mathematics/Algebra/Matrix.h"

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE ObjectMotionImpl
	{
	public:
		using ClassType = ObjectMotionImpl;
		using SpatialSmartPointer = Rendering::SpatialSmartPointer;
		using ConstSpatialSmartPointer = Rendering::ConstSpatialSmartPointer;
		using ConstCameraSmartPointer = Rendering::ConstCameraSmartPointer;
		using Matrix = Mathematics::Matrixf;
		using AVector = Mathematics::AVectorf;
		using Transform = Rendering::Transform;
		
	public:
		explicit ObjectMotionImpl(const SpatialSmartPointer& motionObject);
	
		CLASS_INVARIANT_DECLARE;

		bool MoveObject (float rotationSpeed);
		void RotateTrackBall(const ConstCameraSmartPointer& camera);

        void SetDoRoll(int value);
        void SetDoYaw(int value);
        void SetDoPitch(int value);
        void SetTrackBallDow(bool value);
        void SetBeginTrack(float xTrack,float yTrack);
        void SetEndTrack(float xTrack,float yTrack);
		void SetSaveRotate(); 
		bool GetTrackBallDow() const;

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



	
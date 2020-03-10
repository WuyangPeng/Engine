// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:02)

#ifndef FRAMEWORK_APPLICATION_OBJECT_MOTION_ROTATE_TRACK_BALL_H
#define FRAMEWORK_APPLICATION_OBJECT_MOTION_ROTATE_TRACK_BALL_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "Rendering/SceneGraph/Spatial.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/DataTypes/Transform.h"
#include "Mathematics/Algebra/Matrix.h"

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE ObjectMotionRotateTrackBall
	{
	public:
		using ClassType = ObjectMotionRotateTrackBall;
		using SpatialSmartPointer = Rendering::SpatialSmartPointer;
		using ConstSpatialSmartPointer = Rendering::ConstSpatialSmartPointer;
		using ConstCameraSmartPointer = Rendering::ConstCameraSmartPointer;
		using Matrix = Mathematics::Matrixf;
		using AVector = Mathematics::AVectorf;
		using Transform = Rendering::Transform;
		
	public:
		explicit ObjectMotionRotateTrackBall(const SpatialSmartPointer& motionObject,const ConstCameraSmartPointer& camera,float m_BeginXTrack,
											 float m_BeginYTrack,float m_EndXTrack,float m_EndYTrack,const Matrix& m_SaveRotate);
	
		CLASS_INVARIANT_DECLARE;

		const Transform GetTransform() const;

	private:
		void Calculate();

	private:
		SpatialSmartPointer m_MotionObject;
		ConstCameraSmartPointer m_Camera;
		float m_BeginXTrack; 
		float m_BeginYTrack; 
		float m_EndXTrack;
		float m_EndYTrack;
		Matrix m_SaveRotate;
		Matrix m_LocalRotate;
	};
}

#endif // FRAMEWORK_APPLICATION_OBJECT_MOTION_ROTATE_TRACK_BALL_H



	
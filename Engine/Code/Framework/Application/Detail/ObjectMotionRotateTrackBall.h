// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:40)

#ifndef FRAMEWORK_APPLICATION_OBJECT_MOTION_ROTATE_TRACK_BALL_H
#define FRAMEWORK_APPLICATION_OBJECT_MOTION_ROTATE_TRACK_BALL_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Spatial.h"
#include "Rendering/DataTypes/Transform.h"

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE ObjectMotionRotateTrackBall
	{
	public:
		using ClassType = ObjectMotionRotateTrackBall;
		using Matrix = Mathematics::FloatMatrix;
		using AVector = Mathematics::FloatAVector;
		using Transform = Rendering::FloatTransform;
		using SpatialSmartPointer = Rendering::SpatialSharedPtr;
		using ConstCameraSmartPointer = Rendering::ConstCameraSharedPtr;

	public:
		explicit ObjectMotionRotateTrackBall(const SpatialSmartPointer& motionObject, const ConstCameraSmartPointer& camera, float beginXTrack,
											 float beginYTrack, float endXTrack, float endYTrack, const Matrix& saveRotate);

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




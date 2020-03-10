// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:01)

#ifndef FRAMEWORK_APPLICATION_OBJECT_MOTION_MOVE_H
#define FRAMEWORK_APPLICATION_OBJECT_MOTION_MOVE_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "Rendering/SceneGraph/Spatial.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/DataTypes/Transform.h"
#include "Mathematics/Algebra/Matrix.h"

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE ObjectMotionMove
	{
	public:
		using ClassType = ObjectMotionMove;
		using Matrix = Mathematics::Matrixf;
		using AVector = Mathematics::AVectorf;
		using SpatialSmartPointer = Rendering::SpatialSmartPointer;
		using Transform = Rendering::Transform;
		
	public:
		explicit ObjectMotionMove(const SpatialSmartPointer& motionObject,int doRoll,int doYaw,int doPitch,float rotationSpeed);
	
		CLASS_INVARIANT_DECLARE;

		const AVector GetAxis() const;
		float GetAngle() const;
		const Matrix GetRotate() const;
		const Transform GetIncr() const;

	private:
		void Calculate();

	private:
		SpatialSmartPointer m_MotionObject;
		int m_DoRoll;
		int m_DoYaw;
		int m_DoPitch;
		float m_RotationSpeed;
		AVector m_Axis;
		float m_Angle;
		Matrix m_Rotate;
	};
}

#endif // FRAMEWORK_APPLICATION_OBJECT_MOTION_MOVE_H



	
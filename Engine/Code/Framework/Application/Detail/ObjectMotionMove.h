// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:39)

#ifndef FRAMEWORK_APPLICATION_OBJECT_MOTION_MOVE_H
#define FRAMEWORK_APPLICATION_OBJECT_MOTION_MOVE_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Spatial.h"
#include "Rendering/DataTypes/Transform.h"

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE ObjectMotionMove
	{
	public:
		using ClassType = ObjectMotionMove;
		using Matrix = Mathematics::FloatMatrix;
		using AVector = Mathematics::FloatAVector;
		using Spatial = Rendering::Spatial;
		using Transform = Rendering::FloatTransform;		
		using SpatialSmartPointer = Rendering::SpatialSharedPtr;

	public:
		explicit ObjectMotionMove(const SpatialSmartPointer& motionObject, int doRoll, int doYaw, int doPitch, float rotationSpeed);

		CLASS_INVARIANT_DECLARE;

		const AVector GetAxis() const noexcept;
		float GetAngle() const noexcept;
                const Matrix GetRotate() const noexcept;
		const Transform GetIncrement() const;

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




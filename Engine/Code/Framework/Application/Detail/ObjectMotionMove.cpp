// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 11:16)

#include "Framework/FrameworkExport.h"

#include "ObjectMotionMove.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Rendering/DataTypes/Transform.h" 
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using Rendering::Spatial;

Framework::ObjectMotionMove
	::ObjectMotionMove(const SpatialSmartPointer& motionObject,int doRoll,int doYaw,int doPitch,float rotationSpeed)
	:m_MotionObject(motionObject),
     m_DoRoll(doRoll), 
	 m_DoYaw(doYaw),
	 m_DoPitch(doPitch),
	 m_RotationSpeed(rotationSpeed),
	 m_Axis(),
	 m_Angle(0.0f),
	 m_Rotate()
{
	Calculate();

	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework,ObjectMotionMove)


const Framework::ObjectMotionMove::AVector Framework::ObjectMotionMove
	::GetAxis() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Axis;
}

float Framework::ObjectMotionMove
	::GetAngle() const 
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Angle;
}

const Framework::ObjectMotionMove::Matrix Framework::ObjectMotionMove
	::GetRotate() const 
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Rotate;
}

void Framework::ObjectMotionMove
	::Calculate() 
{
	// 检查对象是否被移动。
	Spatial* parent = m_MotionObject->GetParent();

	if (m_DoRoll != 0)
	{
		m_Rotate = m_MotionObject->GetLocalTransform().GetRotate();

		m_Angle = m_DoRoll * m_RotationSpeed;
		if (parent != nullptr)
		{
			m_Axis = parent->GetWorldTransform().GetRotate().GetColumn(0);
		}
		else
		{
			m_Axis = AVector::sm_UnitX;
		}
	}
	else if (m_DoYaw != 0)
	{
		m_Rotate = m_MotionObject->GetLocalTransform().GetRotate();

		m_Angle = m_DoYaw * m_RotationSpeed;
		if (parent != nullptr)
		{
			m_Axis = parent->GetWorldTransform().GetRotate().GetColumn(1);
		}
		else
		{
			m_Axis = AVector::sm_UnitY;
		}
	}
	else if (m_DoPitch != 0)
	{
		m_Rotate = m_MotionObject->GetLocalTransform().GetRotate();

		m_Angle = m_DoPitch * m_RotationSpeed;
		if (parent != nullptr)
		{
			m_Axis = parent->GetWorldTransform().GetRotate().GetColumn(2);
		}
		else
		{
			m_Axis = AVector::sm_UnitZ;
		}
	}
}

const Framework::ObjectMotionMove::Transform Framework::ObjectMotionMove
	::GetIncr() const 
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	Matrix incr(m_Axis, m_Angle);
	Matrix rotate = incr * m_Rotate;
	rotate.Orthonormalize();

	Transform transform = m_MotionObject->GetLocalTransform();
	transform.SetRotate(rotate);
	
	return transform;
}


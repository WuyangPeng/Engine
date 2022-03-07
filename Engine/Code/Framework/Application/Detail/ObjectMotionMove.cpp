// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 13:53)

#include "Framework/FrameworkExport.h"

#include "ObjectMotionMove.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Rendering/DataTypes/Transform.h" 
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
Framework::ObjectMotionMove
	::ObjectMotionMove(const SpatialSmartPointer& motionObject, int doRoll, int doYaw, int doPitch, float rotationSpeed)
	:m_MotionObject{ motionObject }, m_DoRoll{ doRoll }, m_DoYaw{ doYaw }, m_DoPitch{ doPitch },
	 m_RotationSpeed{ rotationSpeed }, m_Axis{ }, m_Angle{ 0.0f }, m_Rotate{ }
{
	Calculate();

	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, ObjectMotionMove)

const Framework::ObjectMotionMove::AVector Framework::ObjectMotionMove ::GetAxis() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Axis;
}

float Framework::ObjectMotionMove
	::GetAngle() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Angle;
}

const Framework::ObjectMotionMove::Matrix Framework::ObjectMotionMove ::GetRotate() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Rotate;
}

void Framework::ObjectMotionMove
	::Calculate()
{
	// 检查对象是否被移动。
	const auto* parent = m_MotionObject->GetParent();

	if (m_DoRoll != 0)
	{
		m_Rotate = m_MotionObject->GetLocalTransform().GetRotate();

		m_Angle = m_DoRoll * m_RotationSpeed;
		if (parent != nullptr)
		{
                    m_Axis = Mathematics::AVector{ parent->GetWorldTransform().GetRotate().GetColumn(0) };
		}
		else
		{
                    m_Axis = Mathematics::AVectorF::GetUnitX();
		}
	}
	else if (m_DoYaw != 0)
	{
		m_Rotate = m_MotionObject->GetLocalTransform().GetRotate();

		m_Angle = m_DoYaw * m_RotationSpeed;
		if (parent != nullptr)
		{
                    m_Axis = Mathematics::AVector{
                        parent->GetWorldTransform().GetRotate().GetColumn(1)
                    };
		}
		else
		{
                    Mathematics::AVectorF::GetUnitY();
		}
	}
	else if (m_DoPitch != 0)
	{
		m_Rotate = m_MotionObject->GetLocalTransform().GetRotate();

		m_Angle = m_DoPitch * m_RotationSpeed;
		if (parent != nullptr)
		{
                    m_Axis = Mathematics::AVector{
                        parent->GetWorldTransform().GetRotate().GetColumn(2)
                    };
		}
		else
		{
                    m_Axis = Mathematics::AVectorF::GetUnitZ();
		}
	}
}

const Framework::ObjectMotionMove::Transform Framework::ObjectMotionMove
	::GetIncrement() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	const Matrix increment{ m_Axis, m_Angle };
	auto rotate = increment * m_Rotate;
	rotate.Orthonormalize();

	auto transform = m_MotionObject->GetLocalTransform();
	transform.SetRotate(rotate);

	return transform;
}


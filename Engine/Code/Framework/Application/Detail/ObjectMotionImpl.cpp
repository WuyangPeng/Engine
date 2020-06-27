// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 13:53)

#include "Framework/FrameworkExport.h"

#include "ObjectMotionImpl.h"
#include "ObjectMotionMove.h"
#include "ObjectMotionRotateTrackBall.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Rendering/DataTypes/Transform.h" 

using Mathematics::Mathf;
using Rendering::Spatial;
using Rendering::Transform;

Framework::ObjectMotionImpl
	::ObjectMotionImpl(const SpatialSmartPointer& motionObject)
	:m_MotionObject{ motionObject }, m_DoRoll{ 0 }, m_DoYaw{ 0 }, m_DoPitch{ 0 }, m_BeginXTrack{ 0.0f }, m_BeginYTrack{ 0.0f },
	 m_EndXTrack{ 0.0f }, m_EndYTrack{ 0.0f }, m_SaveRotate{ }, m_UseTrackBall{ true }, m_TrackBallDown{ false }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::ObjectMotionImpl
	::IsValid() const noexcept
{
	if (m_MotionObject.IsValidPtr())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

bool Framework::ObjectMotionImpl
	::MoveObject(float rotationSpeed)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	// 如果对象有一个父节点，应用到坐标系旋转。
	// 父节点的世界旋转矩阵R,坐标轴是方向的列。
	// 0列是“direction”，1列是"up"，2列是"right"的。
	// 如果对象没有父节点,在这种情况下,世界坐标轴被使用，旋转矩阵是I。
	// 列0(1,0,0)是“direction”,列1(0,1,0)是"up"和列2(0,0,1)是“right”。
	// 在使用旋转的Camera和Light类存储坐标轴，这个选择是一致的。

	// Roll是“方向”轴，yaw是“向上”的轴，pitch是“向右”的轴。

	if (m_TrackBallDown)
	{
		return true;
	}
	else if (m_DoRoll == 0 && m_DoYaw == 0 && m_DoPitch == 0)
	{
		return false;
	}
	else
	{
		ObjectMotionMove objectMotionMove{ m_MotionObject, m_DoRoll, m_DoYaw, m_DoPitch, rotationSpeed };

		auto transform = objectMotionMove.GetIncrement();
		m_MotionObject->SetLocalTransform(transform);

		return true;
	}
}

void Framework::ObjectMotionImpl
	::RotateTrackBall(const ConstCameraSmartPointer& camera)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if (m_BeginXTrack != m_EndXTrack || m_BeginYTrack != m_EndYTrack)
	{
		ObjectMotionRotateTrackBall rotateTrackBall{ m_MotionObject, camera, m_BeginXTrack, m_BeginYTrack, m_EndXTrack, m_EndYTrack, m_SaveRotate };

		auto transform = rotateTrackBall.GetTransform();

		m_MotionObject->SetLocalTransform(transform);
	}
}

void Framework::ObjectMotionImpl
	::SetDoRoll(int value) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_DoRoll = value;
}

void Framework::ObjectMotionImpl
	::SetDoYaw(int value) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_DoYaw = value;
}

void Framework::ObjectMotionImpl
	::SetDoPitch(int value) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_DoPitch = value;
}

void Framework::ObjectMotionImpl
	::SetTrackBallDow(bool value) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_TrackBallDown = value;
}

void Framework::ObjectMotionImpl
	::SetBeginTrack(float xTrack, float yTrack) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_BeginXTrack = xTrack;
	m_BeginYTrack = yTrack;
}

void Framework::ObjectMotionImpl
	::SetEndTrack(float xTrack, float yTrack) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_EndXTrack = xTrack;
	m_EndYTrack = yTrack;
}

void Framework::ObjectMotionImpl
	::SetSaveRotate()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_SaveRotate = m_MotionObject->GetLocalTransform().GetRotate();
}

bool Framework::ObjectMotionImpl
	::GetTrackBallDow() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_TrackBallDown;
}

const Transform Framework::ObjectMotionImpl
	::GetMotionObjectLocalTransform() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_MotionObject->GetLocalTransform();
}

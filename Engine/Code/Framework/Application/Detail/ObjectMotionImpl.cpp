// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.3.0.1 (2020/05/21 13:53)

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

	// ���������һ�����ڵ㣬Ӧ�õ�����ϵ��ת��
	// ���ڵ��������ת����R,�������Ƿ�����С�
	// 0���ǡ�direction����1����"up"��2����"right"�ġ�
	// �������û�и��ڵ�,�����������,���������ᱻʹ�ã���ת������I��
	// ��0(1,0,0)�ǡ�direction��,��1(0,1,0)��"up"����2(0,0,1)�ǡ�right����
	// ��ʹ����ת��Camera��Light��洢�����ᣬ���ѡ����һ�µġ�

	// Roll�ǡ������ᣬyaw�ǡ����ϡ����ᣬpitch�ǡ����ҡ����ᡣ

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

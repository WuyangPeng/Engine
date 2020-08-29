// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.3.0.1 (2020/05/21 13:53)

#include "Framework/FrameworkExport.h"

#include "ObjectMotionRotateTrackBall.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Rendering/DataTypes/Transform.h"

using Mathematics::Mathf;
using Rendering::Spatial;
using Rendering::Transform;

Framework::ObjectMotionRotateTrackBall
	::ObjectMotionRotateTrackBall(const SpatialSmartPointer& motionObject, const ConstCameraSmartPointer& camera, float m_BeginXTrack, float m_BeginYTrack,
								  float m_EndXTrack, float m_EndYTrack, const Matrix& m_SaveRotate)
	:m_MotionObject{ motionObject }, m_Camera{ camera }, m_BeginXTrack{ m_BeginXTrack }, m_BeginYTrack{ m_BeginYTrack },
	 m_EndXTrack{ m_EndXTrack }, m_EndYTrack(m_EndYTrack), m_SaveRotate(m_SaveRotate), m_LocalRotate()
{
	Calculate();

	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, ObjectMotionRotateTrackBall)

void Framework::ObjectMotionRotateTrackBall
	::Calculate()
{
	auto beginX = m_BeginXTrack;
	auto beginY = m_BeginYTrack;
	auto endX = m_EndXTrack;
	auto endY = m_EndYTrack;

	// ��������ϵĵ�һ��������
	auto length = Mathf::Sqrt(beginX * beginX + beginY * beginY);
	auto beginZ = 0.0f;
	auto endZ = 0.0f;

	if (1.0f < length)
	{
		// �ڵ�λԲ��,ͶӰ������
		beginX /= length;
		beginY /= length;
		beginZ = 0.0f;
	}
	else
	{
		// �����(x0,y0,z0)�ڸ���λ����
		beginZ = 1.0f - beginX * beginX - beginY * beginY;
		beginZ = (beginZ <= 0.0f ? 0.0f : Mathf::Sqrt(beginZ));
	}
	beginZ *= -1.0f;

	// ʹ���������������,˳����(D,U,R),���Ե���(z,y,x)��
        const AVector vec0{ beginZ, beginY, beginX };

	// ��������ϵĵڶ���������
	length = Mathf::Sqrt(endX * endX + endY * endY);
	if (1.0f < length)
	{
		// �ڵ�λԲ��,ͶӰ������  
		endX /= length;
		endY /= length;
		endZ = 0.0f;
	}
	else
	{
		// �����(x1,y1,z1) �ڸ���λ����
		endZ = 1.0f - endX * endX - endY * endY;
		endZ = (endZ <= 0.0f ? 0.0f : Mathf::Sqrt(endZ));
	}
	endZ *= -1.0f;

	// ʹ���������������,˳����(D,U,R),���Ե���(z,y,x)��
        const AVector vec1{ endZ, endY, endX };

	// ������ת����ͽǶȡ�
	auto axis = Cross(vec0, vec1);
	const auto dot = Dot(vec0, vec1);
	auto angle = 0.0f;
	if (!axis.IsZero())
	{
		axis.Normalize();
		angle = Mathf::ACos(dot);
	}
	else  // ������ƽ�еġ�
	{
		if (dot < 0.0f)
		{
			// �л�����ת��
			auto invLength = Mathf::InvSqrt(beginX * beginX + beginY * beginY);
			axis[0] = beginY * invLength;
			axis[1] = -beginX * invLength;
			axis[2] = 0.0f;
			angle = Mathf::GetPI();
		}
		else
		{
			// 0������ת�� 
			axis = Mathematics::Vectorf::g_UnitX;
			angle = 0.0f;
		}
	}

	// ����������ת���������˶���켣����ʸ�������������㡣
	// �����뱻ת�����������꣬��һ��,�������˳��(D,U,R)��
	auto worldAxis = axis[0] * m_Camera->GetDirectionVector() +
					 axis[1] * m_Camera->GetUpVector() +
					 axis[2] * m_Camera->GetRightVector();

	const Matrix trackRotate{ worldAxis, angle };

	// ������µľֲ���ת����������ǳ����ĸ�,	
	// �µ���ת�ǹ켣��Ӧ���ڶ��󱻾ɾֲ���ת��������ת��
	// ��������ǳ����ĸ�,��Ҫת��������ʽ��תҪ�ڸı丸����ռ�Ļ����ϡ�
	const auto* parent = m_MotionObject->GetParent();
	if (parent)
	{
		const auto parWorRotate = parent->GetWorldTransform().GetRotate();
		m_LocalRotate = TransposeTimes(parWorRotate, trackRotate) * parWorRotate * m_SaveRotate;
	}
	else
	{
		m_LocalRotate = trackRotate * m_SaveRotate;
	}

	m_LocalRotate.Orthonormalize();
}

const Transform Framework::ObjectMotionRotateTrackBall
	::GetTransform() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	auto transform = m_MotionObject->GetLocalTransform();
	transform.SetRotate(m_LocalRotate);

	return transform;
}


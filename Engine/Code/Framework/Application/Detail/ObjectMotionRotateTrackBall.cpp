// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 13:53)

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

	// 获得球面上的第一个向量。
	auto length = Mathf::Sqrt(beginX * beginX + beginY * beginY);
	auto beginZ = 0.0f;
	auto endZ = 0.0f;

	if (1.0f < length)
	{
		// 在单位圆外,投影到它。
		beginX /= length;
		beginY /= length;
		beginZ = 0.0f;
	}
	else
	{
		// 计算点(x0,y0,z0)在负单位半球。
		beginZ = 1.0f - beginX * beginX - beginY * beginY;
		beginZ = (beginZ <= 0.0f ? 0.0f : Mathf::Sqrt(beginZ));
	}
	beginZ *= -1.0f;

	// 使用相机的世界坐标,顺序是(D,U,R),所以点是(z,y,x)。
        const AVector vec0{ beginZ, beginY, beginX };

	// 获得球面上的第二个向量。
	length = Mathf::Sqrt(endX * endX + endY * endY);
	if (1.0f < length)
	{
		// 在单位圆外,投影到它。  
		endX /= length;
		endY /= length;
		endZ = 0.0f;
	}
	else
	{
		// 计算点(x1,y1,z1) 在负单位半球。
		endZ = 1.0f - endX * endX - endY * endY;
		endZ = (endZ <= 0.0f ? 0.0f : Mathf::Sqrt(endZ));
	}
	endZ *= -1.0f;

	// 使用相机的世界坐标,顺序是(D,U,R),所以点是(z,y,x)。
        const AVector vec1{ endZ, endY, endX };

	// 创建旋转的轴和角度。
	auto axis = Cross(vec0, vec1);
	const auto dot = Dot(vec0, vec1);
	auto angle = 0.0f;
	if (!axis.IsZero())
	{
		axis.Normalize();
		angle = Mathf::ACos(dot);
	}
	else  // 向量是平行的。
	{
		if (dot < 0.0f)
		{
			// π弧度旋转。
			auto invLength = Mathf::InvSqrt(beginX * beginX + beginY * beginY);
			axis[0] = beginY * invLength;
			axis[1] = -beginX * invLength;
			axis[2] = 0.0f;
			angle = Mathf::GetPI();
		}
		else
		{
			// 0弧度旋转。 
			axis = Mathematics::Vectorf::g_UnitX;
			angle = 0.0f;
		}
	}

	// 计算世界旋转矩阵隐含运动球轨迹，轴矢量在相机坐标计算。
	// 它必须被转换成世界坐标，再一次,我用相机顺序(D,U,R)。
	auto worldAxis = axis[0] * m_Camera->GetDirectionVector() +
					 axis[1] * m_Camera->GetUpVector() +
					 axis[2] * m_Camera->GetRightVector();

	const Matrix trackRotate{ worldAxis, angle };

	// 计算出新的局部旋转。如果对象是场景的根,	
	// 新的旋转是轨迹球应用在对象被旧局部旋转的增量旋转。
	// 如果对象不是场景的根,你要转换的增量式旋转要在改变父坐标空间的基础上。
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


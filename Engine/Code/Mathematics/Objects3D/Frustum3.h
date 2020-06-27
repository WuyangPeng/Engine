// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/19 17:22)

#ifndef MATHEMATICS_OBJECTS3D_FRUSTUM3_H
#define MATHEMATICS_OBJECTS3D_FRUSTUM3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/Math.h"
#include "Mathematics/Algebra/Vector3D.h"

#include <vector>
#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class Frustum3
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Frustum3<Real>;
		using Math = Math<Real>;
		using Vector3D = Vector3D<Real>;		

	public:
		// ������׶�塣
		// ��E��ԭ�㣬DΪ����������U��������������Real���ҷ���������
		// ��u > 0 �� r > 0�ֱ�����U��Real����ĳ��ȡ�
		// ��n��f��D�ķ����ϵķ�Χ0 < n < f��
		// �ĸ��ǣ��ڽ���ƽ���׶��E + n*D + s0*u*U + s1*r*Real��
		// ����|s0| =|s1| = 1���ĸ�ѡ���
		// �ĸ��ǵ�Զƽ��Ľ�׶�� E + f*D + (f/n)*(s0*u*U + s1*r*Real)��
		// ����|s0| = |s1| = 1������ѡ��
		Frustum3(const Vector3D& origin, const Vector3D& directionVector, const Vector3D& upVector, const Vector3D& rightVector, Real directionMin,
				 Real directionMax, Real upBound, Real rightBound, const Real epsilon = Math::sm_ZeroTolerance);

		CLASS_INVARIANT_DECLARE;

		const Vector3D GetOrigin() const;
		const Vector3D GetDirectionVector() const;
		const Vector3D GetUpVector() const;
		const Vector3D GetRightVector() const;
		Real GetDirectionMin() const;
		Real GetDirectionMax() const;
		Real GetUpBound() const;
		Real GetRightBound() const;

		Real GetDirectionRatio() const;
		Real GetMTwoUF() const;
		Real GetMTwoRF() const;

		// ����8������
		const std::vector<Vector3D> ComputeVertices() const;

	private:
		// Update()�������뱻�����ڸ�����m_DirectionMin��m_DirectionMax��
		// m_UpBound����m_RightBoundʱ��
		// ��ֵm_DirectionRatio��m_MTwoUF��m_MTwoRF����������Щֵ�ı仯��
		void Update();

	private:
		Vector3D m_Origin;
		Vector3D m_DirectionVector;
		Vector3D m_UpVector;
		Vector3D m_RightVector;
		Real m_DirectionMin;
		Real m_DirectionMax;
		Real m_UpBound;
		Real m_RightBound;

		// ��ֵ�ӹ��캯��������õ��ġ�
		Real m_DirectionRatio;
		Real m_MTwoUF;
		Real m_MTwoRF;

		Real m_Epsilon;
	};

	using Frustum3f = Frustum3<float>;
	using Frustum3d = Frustum3<double>;
}

#endif // MATHEMATICS_OBJECTS3D_FRUSTUM3_H

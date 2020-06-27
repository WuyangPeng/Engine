// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/19 16:47)

#ifndef MATHEMATICS_OBJECTS2D_RAY2_H
#define MATHEMATICS_OBJECTS2D_RAY2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class Ray2
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Ray2<Real>;
		using Vector2D = Vector2D<Real>;
		using Math = Math<Real>;

	public:
		// ���߱�ʾΪP+t*D������P����ԭ�㣬D�ǵ�λ���ȵķ���������t >= 0��
		// �û�����ȷ��D�ǵ�λ���ȡ�

		Ray2(const Vector2D& origin, const Vector2D& direction, const Real epsilon = Math::sm_ZeroTolerance);

		CLASS_INVARIANT_DECLARE;

		const Vector2D GetOrigin() const;
		const Vector2D GetDirection() const;

		const ClassType GetMove(Real t, const Vector2D& velocity) const;

	private:
		Vector2D m_Origin;
		Vector2D m_Direction;
		Real m_Epsilon;
	};

	using Ray2f = Ray2<float>;
	using Ray2d = Ray2<double>;

	template <typename Real>
	bool Approximate(const Ray2<Real>& lhs, const Ray2<Real>& rhs, const Real epsilon);

	// �������
	template <typename Real>
	std::ostream& operator<< (std::ostream& outFile, const Ray2<Real>& ray);
}

#endif // MATHEMATICS_OBJECTS2D_RAY2_H

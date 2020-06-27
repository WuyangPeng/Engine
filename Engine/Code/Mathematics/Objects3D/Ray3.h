// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/19 17:23)

#ifndef MATHEMATICS_OBJECTS3D_RAY3_H
#define MATHEMATICS_OBJECTS3D_RAY3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/Math.h"
#include "Mathematics/Algebra/Vector3D.h"

#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class Ray3
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Ray3<Real>;
		using Vector3D = Vector3D<Real>;
		using Math = Math<Real>;

	public:
		// ���߱�ʾΪP+t*D������P����ԭ�㣬D�ǵ�λ���ȵķ���������t >= 0��
		// �û�����ȷ��D�ǵ�λ���ȡ�
		Ray3(const Vector3D& origin, const Vector3D& direction, const Real epsilon = Math::sm_ZeroTolerance);

		CLASS_INVARIANT_DECLARE;

		const Vector3D GetOrigin() const;
		const Vector3D GetDirection() const;

		const ClassType GetMove(Real t, const Vector3D& velocity) const;

	private:
		Vector3D m_Origin;
		Vector3D m_Direction;
		Real m_Epsilon;
	};

	using Ray3f = Ray3<float>;
	using Ray3d = Ray3<double>;

	template <typename Real>
	bool Approximate(const Ray3<Real>& lhs, const Ray3<Real>& rhs, const Real epsilon);

	// �������
	template <typename Real>
	std::ostream& operator<< (std::ostream& outFile, const Ray3<Real>& ray);
}

#endif // MATHEMATICS_OBJECTS3D_RAY3_H

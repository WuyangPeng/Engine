// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/19 16:44)

#ifndef MATHEMATICS_OBJECTS2D_BOX2_H
#define MATHEMATICS_OBJECTS2D_BOX2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"

#include <vector>
#include <iosfwd>
#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class Box2
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Box2<Real>;
		using Math = Math<Real>;
		using Vector2D = Vector2D<Real>;		

	public:
		// һ�����������ĵ�C���᷽��U[0]��U[1]����ֱ�͵�λ���ȵ���������
		// �ͷ�Χe[0]��e[1]���Ǹ������� 
		// A point X = C+y[0]*U[0]+y[1]*U[1]�����ڲ����ں����ϣ�
		// ÿ��|y[i]| <= e[i]�������е�i
		Box2();
		Box2(const Vector2D& center, const Vector2D& firstAxis, const Vector2D& secondAxis,
			 const Real firstExtent, const Real secondExtent, const Real epsilon = Math::GetZeroTolerance());

		CLASS_INVARIANT_DECLARE;

		const std::vector<Vector2D> ComputeVertices() const;
		const Vector2D GetCenter() const;
		const Vector2D GetFirstAxis() const;
		const Vector2D GetSecondAxis() const;
		Real GetFirstExtent() const;
		Real GetSecondExtent() const;
		Real GetEpsilon() const;

		const ClassType GetMove(Real t, const Vector2D& velocity) const;

	private:
		Vector2D m_Center;
		Vector2D m_Axis[2];
		Real m_Extent[2];
		Real m_Epsilon;
	};

	using Box2f = Box2<float>;
	using Box2d = Box2<double>;

	template <typename Real>
	bool Approximate(const Box2<Real>& lhs, const Box2<Real>& rhs, const Real epsilon);

	// �������
	template <typename Real>
	std::ostream& operator<< (std::ostream& outFile, const Box2<Real>& box);
}

#endif // MATHEMATICS_OBJECTS2D_BOX2_H

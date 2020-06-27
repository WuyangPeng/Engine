// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/19 16:44)

#ifndef MATHEMATICS_OBJECTS2D_ARC2_H
#define MATHEMATICS_OBJECTS2D_ARC2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/Math.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/Vector2DTools.h"

#include <iosfwd>
#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class Arc2
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Arc2<Real>;
		using Math = Math<Real>;
		using Vector2D = Vector2D<Real>;
		using Vector2DTools = Vector2DTools<Real>;		

	public:
		// Բ���Ƕ�����Բ�ϵ�����end0��end1��
		// �Ա�end1ͨ��end0��ʱ�뷽�������á�
		// Ӧ�ó�����ȷ��end0��end1��Բ���ϣ���������ȷ������

		Arc2(const Vector2D& center, Real radius, const Vector2D& firstEnd, const Vector2D& secondEnd, const Real epsilon = Math::sm_ZeroTolerance);

		CLASS_INVARIANT_DECLARE;

		// ����point�Ƿ��ڻ��ϡ�Ӧ�ó������ȷ��point��Բ�ϣ�Ҳ����˵��|P-C| = Real��
		// �ò�����������B-C �� A-C���κνǶȣ�����������0 �� pi����֮�䡣
		bool Contains(const Vector2D& point) const;

		const Vector2D GetCenter() const;
		Real GetRadius() const;
		const Vector2D GetFirstEnd() const;
		const Vector2D GetSecondEnd() const;

	private:
		Vector2D m_Center;
		Real m_Radius;
		Vector2D m_FirstEnd;
		Vector2D m_SecondEnd;
		Real m_Epsilon;
	};

	using Arc2f = Arc2<float>;
	using Arc2d = Arc2<double>;

	template <typename Real>
	bool Approximate(const Arc2<Real>& lhs, const Arc2<Real>& rhs, const Real epsilon);

	// �������
	template <typename Real>
	std::ostream& operator<< (std::ostream& out, const Arc2<Real>& arc2);

}

#endif // MATHEMATICS_OBJECTS2D_ARC2_H

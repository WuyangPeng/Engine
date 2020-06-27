// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/24 14:39)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_CLASSIFY_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_CLASSIFY_H 

#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorLine2Classify : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticTestIntersectorLine2Classify<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>;

	public:
		// ���Է����ķ��ࡣ
		// ����P0 + s * D0��P1 + s * D1�� 
		// ���߲��ཻʱ������ֵΪIntersectionType::Empty��
		// ����ֻ��Ψһ�Ľ���ʱ������ֵΪIntersectionType::Point��
		// �����ص�ʱ������ֵΪIntersectionType::Line�� 
		// ��ֻ��Ψһ�Ľ���ʱ����ΪP0 + s[0] * D0 = P1 + s[1] * D1��
		// 'epsilon'���������ڲ���ƽ�л�ֱ�����ķǸ����� 
		// ��Test() �� Find() ������ʹ�õ�ֵ��m_Epsilon�� 
		// �������֪��s[]ֵ������isCalculateParameterΪ'true'��
		// ������������-���ߣ�ֱ��-ֱ�ߺ��߶�-�߶ε��ཻ���Թ���
		StaticTestIntersectorLine2Classify(const Vector2D& lhsOrigin, const Vector2D& lhsDirection, const Vector2D& rhsOrigin,
										   const Vector2D& rhsDirection, bool isCalculateParameter = true, const Real epsilon = Math::sm_ZeroTolerance);
		virtual ~StaticTestIntersectorLine2Classify();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		Real GetFirstParameter() const;
		Real GetSecondParameter() const;

	private:
		void Test(const Vector2D& lhsOrigin, const Vector2D& lhsDirection, const Vector2D& rhsOrigin, const Vector2D& rhsDirection, bool isCalculateParameter);

	private:
		Real m_FirstParameter;
		Real m_SecondParameter;
	};

	using StaticTestIntersectorLine2Classifyf = StaticTestIntersectorLine2Classify<float>;
	using StaticTestIntersectorLine2Classifyd = StaticTestIntersectorLine2Classify<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_CLASSIFY_H

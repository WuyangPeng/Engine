// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 14:39)

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
		// 线性分量的分类。
		// 线是P0 + s * D0和P1 + s * D1。 
		// 当线不相交时，返回值为IntersectionType::Empty，
		// 当线只有唯一的交点时，返回值为IntersectionType::Point，
		// 或当线重叠时，返回值为IntersectionType::Line。 
		// 当只有唯一的交点时，点为P0 + s[0] * D0 = P1 + s[1] * D1。
		// 'epsilon'参数是用于测试平行或垂直向量的非负数。 
		// 在Test() 和 Find() 函数中使用的值是m_Epsilon。 
		// 如果你想知道s[]值，传递isCalculateParameter为'true'。
		// 代码用于射线-射线，直线-直线和线段-线段的相交测试共享。
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

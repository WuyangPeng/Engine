// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 16:44)

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
		// 圆弧是定义在圆上的两点end0和end1，
		// 以便end1通过end0逆时针方向遍历获得。
		// 应用程序负责确保end0和end1在圆环上，和他们正确的排序。

		Arc2(const Vector2D& center, Real radius, const Vector2D& firstEnd, const Vector2D& secondEnd, const Real epsilon = Math::sm_ZeroTolerance);

		CLASS_INVARIANT_DECLARE;

		// 检验point是否在弧上。应用程序必须确保point在圆上，也就是说，|P-C| = Real。
		// 该测试适用于在B-C 和 A-C的任何角度，而不仅仅是0 到 pi弧度之间。
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

	// 调试输出
	template <typename Real>
	std::ostream& operator<< (std::ostream& out, const Arc2<Real>& arc2);

}

#endif // MATHEMATICS_OBJECTS2D_ARC2_H

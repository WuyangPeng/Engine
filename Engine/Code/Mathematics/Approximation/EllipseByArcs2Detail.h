// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/23 13:29)

#ifndef MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_DETAIL_H
#define MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_DETAIL_H

#include "EllipseByArcs2.h"
#include "Mathematics/Containment/ScribeCircle2CircumscribeDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

template <typename Real>
Mathematics::EllipseByArcs2<Real>
	::EllipseByArcs2(Real begin, Real end, size_t numArcs)
	:m_Points(numArcs + 1), m_Circle(numArcs)
{
	MATHEMATICS_ASSERTION_2(2 <= m_Circle.size(), "必须至少指定两个圆弧\n");
	MATHEMATICS_ASSERTION_2(Math<Real>::GetValue(0) <= begin, "begin必须大于或等于0\n");
	MATHEMATICS_ASSERTION_2(Math<Real>::GetValue(0) <= end, " end必须大于或等于0\n");

	Calculate(begin, end);

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::EllipseByArcs2<Real>
	::Calculate(Real begin, Real end)
{
	// 中间椭圆数量
	auto beginSquare = begin * begin;
	auto endSquare = end * end;
	auto aMultipliedB = begin * end;
	auto inverseEndSquareMinusBeginSquare = Math::GetValue(1) / (endSquare - beginSquare);

	auto numArcs = boost::numeric_cast<int>(m_Circle.size());

	// 在第一象限椭圆的终点。点按逆时针顺序产生。
	m_Points[0] = Vector2D{ begin, Math<Real>::GetValue(0) };
	m_Points[numArcs] = Vector2D{ Math<Real>::GetValue(0), end };

	// 终点的曲率，对于计算圆弧存储曲率。
	auto beginCurvature = begin / endSquare;
	auto endCurvature = end / beginSquare;

	// 选择基于曲率特性的椭圆点。
	for (auto index = 1; index < numArcs; ++index)
	{
		// 新点曲率为两端曲率加权平均值。
		auto weight1 = static_cast<Real>(index) / static_cast<Real>(numArcs);
		auto weight0 = Math::GetValue(1) - weight1;
		auto curvature = weight0 * beginCurvature + weight1 * endCurvature;

		// 使用曲率计算点。
		auto pow = Math<Real>::Pow(aMultipliedB / curvature, Math::GetValue(2) / static_cast<Real>(3));
		m_Points[index].SetCoordinate(begin * Math<Real>::Sqrt(Math<Real>::FAbs((pow - beginSquare) * inverseEndSquareMinusBeginSquare)),
									  end * Math<Real>::Sqrt(Math<Real>::FAbs((pow - endSquare) * inverseEndSquareMinusBeginSquare)));
	}

	// 计算圆弧在 (a,0).
	ScribeCircle2Circumscribe<Real> beginCircumscribe{ Vector2D{m_Points[1][0], -m_Points[1][1]}, m_Points[0], m_Points[1] };
	m_Circle[0] = beginCircumscribe.GetCircle2();

	// 计算圆弧在 (0,b).
	auto last = numArcs - 1;
	ScribeCircle2Circumscribe<Real> endCircumscribe{ Vector2D{-m_Points[last][0], m_Points[last][1]}, m_Points[numArcs], m_Points[last] };
	m_Circle[last] = endCircumscribe.GetCircle2();

	// 在点(a,0) 和 (0,b)间计算圆弧
	for (auto index = 1; index < last; ++index)
	{
		auto nextIndex = index + 1;
		auto beforeIndex = index - 1;
		ScribeCircle2Circumscribe<Real> circumscribe{ m_Points[beforeIndex], m_Points[index], m_Points[nextIndex] };
		m_Circle[index] = circumscribe.GetCircle2();
	}
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::EllipseByArcs2<Real>
	::IsValid() const noexcept
{
	if (2 <= m_Circle.size() && m_Points.size() == m_Circle.size() + 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
const std::vector<Mathematics::Vector2D<Real> > Mathematics::EllipseByArcs2<Real>
	::GetPoints() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Points;
}

template <typename Real>
const std::vector<typename Mathematics::EllipseByArcs2<Real>::Circle2>  Mathematics::EllipseByArcs2<Real>
	::GetCircle2() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Circle;
}

template <typename Real>
int Mathematics::EllipseByArcs2<Real>
	::getNumArcs() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return boost::numeric_cast<int>(m_Circle.size());
}

template <typename Real>
const typename Mathematics::EllipseByArcs2<Real>::Arc2 Mathematics::EllipseByArcs2<Real>
	::GetArc2(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_Circle.size()), "索引错误！");

	auto nextIndex = index + 1;
	Arc2 arc{ m_Circle[index].GetCenter(), m_Circle[index].GetRadius(), m_Points[index], m_Points[nextIndex] };

	return arc;
}

#endif // MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_DETAIL_H

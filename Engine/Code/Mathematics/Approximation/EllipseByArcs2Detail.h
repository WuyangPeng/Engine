// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/23 13:29)

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
	MATHEMATICS_ASSERTION_2(2 <= m_Circle.size(), "��������ָ������Բ��\n");
	MATHEMATICS_ASSERTION_2(Math<Real>::GetValue(0) <= begin, "begin������ڻ����0\n");
	MATHEMATICS_ASSERTION_2(Math<Real>::GetValue(0) <= end, " end������ڻ����0\n");

	Calculate(begin, end);

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::EllipseByArcs2<Real>
	::Calculate(Real begin, Real end)
{
	// �м���Բ����
	auto beginSquare = begin * begin;
	auto endSquare = end * end;
	auto aMultipliedB = begin * end;
	auto inverseEndSquareMinusBeginSquare = Math::GetValue(1) / (endSquare - beginSquare);

	auto numArcs = boost::numeric_cast<int>(m_Circle.size());

	// �ڵ�һ������Բ���յ㡣�㰴��ʱ��˳�������
	m_Points[0] = Vector2D{ begin, Math<Real>::GetValue(0) };
	m_Points[numArcs] = Vector2D{ Math<Real>::GetValue(0), end };

	// �յ�����ʣ����ڼ���Բ���洢���ʡ�
	auto beginCurvature = begin / endSquare;
	auto endCurvature = end / beginSquare;

	// ѡ������������Ե���Բ�㡣
	for (auto index = 1; index < numArcs; ++index)
	{
		// �µ�����Ϊ�������ʼ�Ȩƽ��ֵ��
		auto weight1 = static_cast<Real>(index) / static_cast<Real>(numArcs);
		auto weight0 = Math::GetValue(1) - weight1;
		auto curvature = weight0 * beginCurvature + weight1 * endCurvature;

		// ʹ�����ʼ���㡣
		auto pow = Math<Real>::Pow(aMultipliedB / curvature, Math::GetValue(2) / static_cast<Real>(3));
		m_Points[index].SetCoordinate(begin * Math<Real>::Sqrt(Math<Real>::FAbs((pow - beginSquare) * inverseEndSquareMinusBeginSquare)),
									  end * Math<Real>::Sqrt(Math<Real>::FAbs((pow - endSquare) * inverseEndSquareMinusBeginSquare)));
	}

	// ����Բ���� (a,0).
	ScribeCircle2Circumscribe<Real> beginCircumscribe{ Vector2D{m_Points[1][0], -m_Points[1][1]}, m_Points[0], m_Points[1] };
	m_Circle[0] = beginCircumscribe.GetCircle2();

	// ����Բ���� (0,b).
	auto last = numArcs - 1;
	ScribeCircle2Circumscribe<Real> endCircumscribe{ Vector2D{-m_Points[last][0], m_Points[last][1]}, m_Points[numArcs], m_Points[last] };
	m_Circle[last] = endCircumscribe.GetCircle2();

	// �ڵ�(a,0) �� (0,b)�����Բ��
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
	MATHEMATICS_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_Circle.size()), "��������");

	auto nextIndex = index + 1;
	Arc2 arc{ m_Circle[index].GetCenter(), m_Circle[index].GetRadius(), m_Points[index], m_Points[nextIndex] };

	return arc;
}

#endif // MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_DETAIL_H

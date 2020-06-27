// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 15:59)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_TRIANGLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_TRIANGLE2_DETAIL_H

#include "StaticTestIntersectorLine2Triangle2.h"
#include "Mathematics/Intersection/StaticFindIntersector1.h" 

template <typename Real>
Mathematics::StaticTestIntersectorLine2Triangle2<Real>
	::StaticTestIntersectorLine2Triangle2(const Line2& line, const Triangle2& triangle)
	: mLine{ line }, mTriangle{ triangle }
{
	Test();
}

template <typename Real>
const Mathematics::Line2<Real> Mathematics::StaticTestIntersectorLine2Triangle2<Real>
	::GetLine() const
{
	return mLine;
}

template <typename Real>
const Mathematics::Triangle2<Real> Mathematics::StaticTestIntersectorLine2Triangle2<Real>
	::GetTriangle() const
{
	return mTriangle;
}

template <typename Real>
void Mathematics::StaticTestIntersectorLine2Triangle2<Real>
	::Test()
{
	Real dist[3]{};
	int sign[3]{};
	auto positive = 0;
	auto negative = 0;
	auto zero = 0;
	TriangleLineRelations(mLine.GetOrigin(), mLine.GetDirection(), mTriangle, dist, sign, positive, negative, zero);

	if (positive == 3 || negative == 3)
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
	else
	{
		Real param[2]{};
		GetInterval(mLine.GetOrigin(), mLine.GetDirection(), mTriangle, dist, sign, param);

		StaticFindIntersector1<Real> intr{ param[0], param[1],-Math::sm_MaxReal, +Math::sm_MaxReal };

		auto  mQuantity = intr.GetNumIntersections();
		if (mQuantity == 2)
		{
			this->SetIntersectionType(IntersectionType::Segment);
		}
		else if (mQuantity == 1)
		{

			this->SetIntersectionType(IntersectionType::Point);
		}
		else
		{
			this->SetIntersectionType(IntersectionType::Empty);
		}
	}
}

template <typename Real>
void  Mathematics::StaticTestIntersectorLine2Triangle2<Real>
	::TriangleLineRelations(const Vector2D& origin, const Vector2D& direction, const Triangle2& triangle, Real dist[3], int sign[3], int& positive, int& negative, int& zero)
{
	positive = 0;
	negative = 0;
	zero = 0;
	for (auto i = 0; i < 3; ++i)
	{
		auto diff = triangle.GetVertex()[i] - origin;
		dist[i] = Vector2DTools::DotPerp(diff, direction);
		if (dist[i] > Math::sm_ZeroTolerance)
		{
			sign[i] = 1;
			++positive;
		}
		else if (dist[i] < -Math::sm_ZeroTolerance)
		{
			sign[i] = -1;
			++negative;
		}
		else
		{
			dist[i] = Math<Real>::sm_Zero;
			sign[i] = 0;
			++zero;
		}
	}
}

template <typename Real>
void Mathematics::StaticTestIntersectorLine2Triangle2<Real>
	::GetInterval(const Vector2D& origin, const Vector2D& direction, const Triangle2& triangle, const Real dist[3], const int sign[3], Real param[2])
{
	// Project triangle onto line.
	Real proj[3]{};
	auto i = 0;
	for (i = 0; i < 3; ++i)
	{
		auto diff = triangle.GetVertex()[i] - origin;
		proj[i] = Vector2DTools::DotProduct(direction, diff);
	}

	// Compute transverse intersections of triangle edges with line.
	auto numer = Math::sm_Zero;
	auto denom = Math::sm_Zero;
	auto i0 = 0;
	auto i1 = 0;
	auto i2 = 0;
	auto quantity = 0;
	for (i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
	{
		if (sign[i0] * sign[i1] < 0)
		{
			MATHEMATICS_ASSERTION_0(quantity < 2, "Too many intersections\n");
			numer = dist[i0] * proj[i1] - dist[i1] * proj[i0];
			denom = dist[i0] - dist[i1];
			param[quantity++] = numer / denom;
		}
	}

	// Check for grazing contact.
	if (quantity < 2)
	{
		for (i0 = 1, i1 = 2, i2 = 0; i2 < 3; i0 = i1, i1 = i2++)
		{
			if (sign[i2] == 0)
			{
				MATHEMATICS_ASSERTION_0(quantity < 2, "Too many intersections\n");
				param[quantity++] = proj[i2];
			}
		}
	}

	// Sort.
	MATHEMATICS_ASSERTION_0(quantity >= 1, "Need at least one intersection\n");
	if (quantity == 2)
	{
		if (param[0] > param[1])
		{
			auto save = param[0];
			param[0] = param[1];
			param[1] = save;
		}
	}
	else
	{
		param[1] = param[0];
	}
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_TRIANGLE2_DETAIL_H
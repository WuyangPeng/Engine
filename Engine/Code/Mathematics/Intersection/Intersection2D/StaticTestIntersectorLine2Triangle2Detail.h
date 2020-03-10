// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/13 10:44)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_TRIANGLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_TRIANGLE2_DETAIL_H

#include "StaticTestIntersectorLine2Triangle2.h"
#include "Mathematics/Intersection/StaticFindIntersector1.h" 

template <typename Real>
Mathematics::StaticTestIntersectorLine2Triangle2<Real>
	::StaticTestIntersectorLine2Triangle2(const Line2& line,const Triangle2& triangle)
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
    Real dist[3];
    int sign[3], positive, negative, zero;
    TriangleLineRelations(mLine.GetOrigin(), mLine.GetDirection(), mTriangle,dist, sign, positive, negative, zero);

    if (positive == 3 || negative == 3)
    {
		this->SetIntersectionType(IntersectionType::Empty);
    }
    else
    {
        Real param[2];
        GetInterval(mLine.GetOrigin(), mLine.GetDirection(), mTriangle, dist, sign, param);

		StaticFindIntersector1<Real> intr{ param[0], param[1],-Math::sm_MaxReal, +Math::sm_MaxReal };

       int  mQuantity = intr.GetNumIntersections();
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
	::TriangleLineRelations(const Vector2D& origin, const Vector2D& direction,const Triangle2& triangle, Real dist[3], int sign[3],int& positive, int& negative, int& zero)
{
    positive = 0;
    negative = 0;
    zero = 0;
    for (auto i = 0; i < 3; ++i)
    {
		auto diff = triangle.GetVertex()[i] - origin;
        dist[i] = Vector2DTools::DotPerp(diff,direction);
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
            dist[i] = Real{};
            sign[i] = 0;
            ++zero;
        }
    }
}

template <typename Real>
void Mathematics::StaticTestIntersectorLine2Triangle2<Real>
	::GetInterval(const Vector2D& origin,const Vector2D& direction,const Triangle2& triangle,const Real dist[3], const int sign[3], Real param[2])
{
    // Project triangle onto line.
    Real proj[3];
    int i;
    for (i = 0; i < 3; ++i)
    {
		auto diff = triangle.GetVertex()[i] - origin;
        proj[i] = Vector2DTools::DotProduct(direction,diff);
    }

    // Compute transverse intersections of triangle edges with line.
    Real numer, denom;
    int i0, i1, i2;
    int quantity = 0;
    for (i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
    {
        if (sign[i0]*sign[i1] < 0)
        {
            MATHEMATICS_ASSERTION_0(quantity < 2, "Too many intersections\n");
            numer = dist[i0]*proj[i1] - dist[i1]*proj[i0];
            denom = dist[i0] - dist[i1];
            param[quantity++] = numer/denom;
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
            Real save = param[0];
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
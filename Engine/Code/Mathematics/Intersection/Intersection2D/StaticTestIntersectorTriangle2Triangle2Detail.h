// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/13 10:54)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE2_TRIANGLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE2_TRIANGLE2_DETAIL_H

#include "StaticTestIntersectorTriangle2Triangle2.h" 

template <typename Real>
Mathematics::StaticTestIntersectorTriangle2Triangle2<Real>
	::StaticTestIntersectorTriangle2Triangle2(const Triangle2& triangle0, const Triangle2& triangle1)
	: mTriangle0{ triangle0 }, mTriangle1{ triangle1 }
{
     
}

template <typename Real>
const Mathematics::Triangle2<Real> Mathematics::StaticTestIntersectorTriangle2Triangle2<Real>
	::GetTriangle0() const
{
    return mTriangle0;
}

template <typename Real>
const Mathematics::Triangle2<Real> Mathematics::StaticTestIntersectorTriangle2Triangle2<Real>
	::GetTriangle1() const
{
    return mTriangle1;
}

template <typename Real>
void Mathematics::StaticTestIntersectorTriangle2Triangle2<Real>
	::Test()
{
    int i0, i1;
    Vector2D dir;

    // Test edges of triangle0 for separation.
    for (i0 = 0, i1 = 2; i0 < 3; i1 = i0++)
    {
        // Test axis V0[i1] + t*perp(V0[i0]-V0[i1]), perp(x,y) = (y,-x).
		dir.SetXCoordinate(mTriangle0.GetVertex()[i0].GetYCoordinate() - mTriangle0.GetVertex()[i1].GetYCoordinate());
		dir.SetYCoordinate(mTriangle0.GetVertex()[i1].GetXCoordinate() - mTriangle0.GetVertex()[i0].GetXCoordinate());
		if (WhichSide(mTriangle1.GetVertex(), mTriangle0.GetVertex()[i1], dir) > 0)
        {
            // Triangle1 is entirely on positive side of triangle0 edge.
			this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    // Test edges of triangle1 for separation.
    for (i0 = 0, i1 = 2; i0 < 3; i1 = i0++)
    {
        // Test axis V1[i1] + t*perp(V1[i0]-V1[i1]), perp(x,y) = (y,-x).
		dir.SetXCoordinate(mTriangle1.GetVertex()[i0].GetYCoordinate() - mTriangle1.GetVertex()[i1].GetYCoordinate());
		dir.SetYCoordinate(mTriangle1.GetVertex()[i1].GetXCoordinate() - mTriangle1.GetVertex()[i0].GetXCoordinate());
		if (WhichSide(mTriangle0.GetVertex(), mTriangle1.GetVertex()[i1], dir) > 0)
        {
            // Triangle0 is entirely on positive side of triangle1 edge.
			this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

	this->SetIntersectionType(IntersectionType::Point);
}
  

template <typename Real>
int Mathematics::StaticTestIntersectorTriangle2Triangle2<Real>
	::WhichSide(const std::vector<Vector2D>& V, const Vector2D& P, const Vector2D& D)
{
    // Vertices are projected to the form P+t*D.  Return value is +1 if all
    // t > 0, -1 if all t < 0, 0 otherwise, in which case the line splits the
    // triangle.

    int positive = 0, negative = 0, zero = 0;
    for (auto i = 0; i < 3; ++i)
    {
		auto t =Vector2DTools::DotProduct(D,(V[i] - P));
        if (t > Real{})
        {
            ++positive;
        }
        else if (t < Real{})
        {
            ++negative;
        }
        else
        {
            ++zero;
        }

        if (positive > 0 && negative > 0)
        {
            return 0;
        }
    }
    return (zero == 0 ? (positive > 0 ? 1 : -1) : 0);
}
 
#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE2_TRIANGLE2_DETAIL_H
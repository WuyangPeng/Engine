// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 15:56)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_DETAIL_H

#include "StaticFindIntersectorTriangle2Triangle2.h"

template <typename Real>
Mathematics::StaticFindIntersectorTriangle2Triangle2<Real>
	::StaticFindIntersectorTriangle2Triangle2(const Triangle2& triangle0, const Triangle2& triangle1)
	:mTriangle0{ triangle0 }, mTriangle1{ triangle1 }
{
	mQuantity = 0;

	Find();
}

template <typename Real>
const Mathematics::Triangle2<Real> Mathematics::StaticFindIntersectorTriangle2Triangle2<Real>
	::GetTriangle0() const
{
	return mTriangle0;
}

template <typename Real>
const Mathematics::Triangle2<Real> Mathematics::StaticFindIntersectorTriangle2Triangle2<Real>
	::GetTriangle1() const
{
	return mTriangle1;
}

template <typename Real>
void Mathematics::StaticFindIntersectorTriangle2Triangle2<Real>
	::Find()
{
	// The potential intersection is initialized to triangle1.  The set of
	// vertices is refined based on clipping against each edge of triangle0.
	mQuantity = 3;
	for (auto i = 0; i < 3; ++i)
	{
		mPoint[i] = mTriangle1.GetVertex()[i];
	}

	for (auto i1 = 2, i0 = 0; i0 < 3; i1 = i0++)
	{
		// Clip against edge <V0[i1],V0[i0]>.
		Vector2D N{ mTriangle0.GetVertex()[i1].GetYCoordinate() - mTriangle0.GetVertex()[i0].GetYCoordinate(),
					mTriangle0.GetVertex()[i0].GetXCoordinate() - mTriangle0.GetVertex()[i1].GetXCoordinate() };
		auto c = Vector2DTools::DotProduct(N, mTriangle0.GetVertex()[i1]);
		ClipConvexPolygonAgainstLine(N, c, mQuantity, mPoint);
		if (mQuantity == 0)
		{
			// Triangle completely clipped, no intersection occurs.
			this->SetIntersectionType(IntersectionType::Empty);
			return;
		}
	}
	this->SetIntersectionType(IntersectionType::Point);
	return;
}

template <typename Real>
int Mathematics::StaticFindIntersectorTriangle2Triangle2<Real>
	::GetQuantity() const
{
	return mQuantity;
}

template <typename Real>
const Mathematics::Vector2D<Real>  Mathematics::StaticFindIntersectorTriangle2Triangle2<Real>
	::GetPoint(int i) const
{
	return mPoint[i];
}

template <typename Real>
int Mathematics::StaticFindIntersectorTriangle2Triangle2<Real>
	::WhichSide(const Vector2D V[3], const Vector2D& P, const Vector2D& D)
{
	// Vertices are projected to the form P+t*D.  Return value is +1 if all
	// t > 0, -1 if all t < 0, 0 otherwise, in which case the line splits the
	// triangle.

	int positive = 0, negative = 0, zero = 0;
	for (auto i = 0; i < 3; ++i)
	{
		auto t = Vector2DTools::DotProduct(D, (V[i] - P));
		if (t > Math<Real>::GetZero())
		{
			++positive;
		}
		else if (t < Math<Real>::GetZero())
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

template <typename Real>
void Mathematics::StaticFindIntersectorTriangle2Triangle2<Real>
	::ClipConvexPolygonAgainstLine(const Vector2D& N, Real c, int& quantity, Vector2D V[6])
{
	// The input vertices are assumed to be in counterclockwise order.  The
	// ordering is an invariant of this function.

	// Test on which side of line the vertices are.
	auto positive = 0;
	auto negative = 0;
	auto pIndex = -1;
	Real test[6]{};
	auto i = 0;
	for (i = 0; i < quantity; ++i)
	{
		test[i] = Vector2DTools::DotProduct(N, V[i]) - c;
		if (test[i] > Math<Real>::GetZero())
		{
			positive++;
			if (pIndex < 0)
			{
				pIndex = i;
			}
		}
		else if (test[i] < Math<Real>::GetZero())
		{
			negative++;
		}
	}

	if (positive > 0)
	{
		if (negative > 0)
		{
			// Line transversely intersects polygon.
			Vector2D CV[6];
			auto cQuantity = 0;
			auto cur = 0;
			auto prv = 0;
			auto t = Math::GetValue(0);

			if (pIndex > 0)
			{
				// First clip vertex on line.
				cur = pIndex;
				prv = cur - 1;
				t = test[cur] / (test[cur] - test[prv]);
				CV[cQuantity++] = V[cur] + t * (V[prv] - V[cur]);

				// Vertices on positive side of line.
				while (cur < quantity && test[cur] >Math<Real>::GetZero())
				{
					CV[cQuantity++] = V[cur++];
				}

				// Last clip vertex on line.
				if (cur < quantity)
				{
					prv = cur - 1;
				}
				else
				{
					cur = 0;
					prv = quantity - 1;
				}
				t = test[cur] / (test[cur] - test[prv]);
				CV[cQuantity++] = V[cur] + t * (V[prv] - V[cur]);
			}
			else  // pIndex is 0
			{
				// Vertices on positive side of line.
				cur = 0;
				while (cur < quantity && test[cur] >Math<Real>::GetZero())
				{
					CV[cQuantity++] = V[cur++];
				}

				// Last clip vertex on line.
				prv = cur - 1;
				t = test[cur] / (test[cur] - test[prv]);
				CV[cQuantity++] = V[cur] + t * (V[prv] - V[cur]);

				// Skip vertices on negative side.
				while (cur < quantity && test[cur] <= Math<Real>::GetZero())
				{
					++cur;
				}

				// First clip vertex on line.
				if (cur < quantity)
				{
					prv = cur - 1;
					t = test[cur] / (test[cur] - test[prv]);
					CV[cQuantity++] = V[cur] + t * (V[prv] - V[cur]);

					// Vertices on positive side of line.
					while (cur < quantity && test[cur] >Math<Real>::GetZero())
					{
						CV[cQuantity++] = V[cur++];
					}
				}
				else
				{
					// cur = 0
					prv = quantity - 1;
					t = test[0] / (test[0] - test[prv]);
					CV[cQuantity++] = V[0] + t * (V[prv] - V[0]);
				}
			}

			quantity = cQuantity;
			memcpy(V, CV, cQuantity * sizeof(Vector2D));
		}
		// else polygon fully on positive side of line, nothing to do.
	}
	else
	{
		// Polygon does not intersect positive side of line, clip all.
		quantity = 0;
	}
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_DETAIL_H
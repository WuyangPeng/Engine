// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 17:00)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR_UTILITY3_DETAIL_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR_UTILITY3_DETAIL_H

#include "IntersectorUtility3.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_INTERSECTOR_UTILITY3_DETAIL) 

#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26485)
template <typename Real>
void Mathematics
	::ClipConvexPolygonAgainstPlane(const Vector3D<Real>& normal, Real constant, int& quantity, Vector3D<Real>* P)
{
	// The input vertices are assumed to be in counterclockwise order.  The
	// ordering is an invariant of this function.  The size of array P is
	// assumed to be large enough to store the clipped polygon vertices.

	// test on which side of line are the vertices
	auto positive = 0;
	auto negative = 0;
	auto pIndex = -1;
	auto currQuantity = quantity;

	Real test[8]{};
	auto i = 0;
	for (i = 0; i < quantity; ++i)
	{

		// An epsilon is used here because it is possible for the dot product
		// and 'constant' to be exactly equal to each other (in theory), but
		// differ slightly because of floating point problems.  Thus, add a
		// little to the test number to push actually equal numbers over the
		// edge towards the positive.

		// TODO: This should probably be a relative tolerance.  Multiplying
		// by the constant is probably not the best way to do this.
		test[i] = Vector3DTools<Real>::DotProduct(normal, P[i]) - constant + Math<Real>::FAbs(constant)*Math<Real>::sm_ZeroTolerance;

		if (test[i] >= Math<Real>::sm_Zero)
		{
			++positive;
			if (pIndex < 0)
			{
				pIndex = i;
			}
		}
		else
		{
			++negative;
		}
	}

	if (quantity == 2)
	{
		// Lines are a little different, in that clipping the segment
		// cannot create a new segment, as clipping a polygon would
		if (positive > 0)
		{
			if (negative > 0)
			{
				int clip = 0;

				if (pIndex == 0)
				{
					// vertex0 positive, vertex1 is clipped
					clip = 1;
				}
				else // pIndex == 1
				{
					// vertex1 positive, vertex0 clipped
					clip = 0;
				}

				Real t = test[pIndex] / (test[pIndex] - test[clip]);
				auto temp = P[clip];
				temp -= P[pIndex];
				P[clip] = P[pIndex] + t * (temp);
			}
			// otherwise both positive, no clipping
		}
		else
		{
			// Assert:  The entire line is clipped, but we should not
			// get here.
			quantity = 0;
		}
	}
	else
	{
		if (positive > 0)
		{
			if (negative > 0)
			{
				// plane transversely intersects polygon
				Vector3D<Real> CV[8];
				int cQuantity = 0; 
				int  cur= 0; 
				int prv= 0; 
				Real t { };

				if (pIndex > 0)
				{
					// first clip vertex on line
					cur = pIndex;
					prv = cur - 1;
					t = test[cur] / (test[cur] - test[prv]);
					CV[cQuantity++] = P[cur] + t * (P[prv] - P[cur]);

					// vertices on positive side of line
					while (cur < currQuantity && test[cur] >= Math<Real>::sm_Zero)
					{
						CV[cQuantity++] = P[cur++];
					}

					// last clip vertex on line
					if (cur < currQuantity)
					{
						prv = cur - 1;
					}
					else
					{
						cur = 0;
						prv = currQuantity - 1;
					}
					t = test[cur] / (test[cur] - test[prv]);
					CV[cQuantity++] = P[cur] + t * (P[prv] - P[cur]);
				}
				else  // pIndex is 0
				{
					// vertices on positive side of line
					cur = 0;
					while (cur < currQuantity && test[cur] >= Math<Real>::sm_Zero)
					{
						CV[cQuantity++] = P[cur++];
					}

					// last clip vertex on line
					prv = cur - 1;
					t = test[cur] / (test[cur] - test[prv]);
					CV[cQuantity++] = P[cur] + t * (P[prv] - P[cur]);

					// skip vertices on negative side
					while (cur < currQuantity && test[cur] < Math<Real>::sm_Zero)
					{
						cur++;
					}

					// first clip vertex on line
					if (cur < currQuantity)
					{
						prv = cur - 1;
						t = test[cur] / (test[cur] - test[prv]);
						CV[cQuantity++] = P[cur] + t * (P[prv] - P[cur]);

						// vertices on positive side of line
						while (cur < currQuantity && test[cur] >= Math<Real>::sm_Zero)
						{
							CV[cQuantity++] = P[cur++];
						}
					}
					else
					{
						// cur = 0
						prv = currQuantity - 1;
						t = test[0] / (test[0] - test[prv]);
						CV[cQuantity++] = P[0] + t * (P[prv] - P[0]);
					}
				}

				currQuantity = cQuantity;
				memcpy(P, CV, cQuantity * sizeof(Vector3D<Real>));
			}
			// else polygon fully on positive side of plane, nothing to do

			quantity = currQuantity;
		}
		else
		{
			// Polygon does not intersect positive side of plane, clip all.
			// This should not ever happen if called by the findintersect
			// routines after an intersection has been determined.
			quantity = 0;
		}
	}
}

template <typename Real>
Mathematics::Vector3D<Real> Mathematics
	::GetPointFromIndex(int index, const Box3<Real>& box)
{
	auto point = box.GetCenter();

	if (index & 4)
	{
		point += box.GetExtent(2)*box.GetAxis(2);
	}
	else
	{
		point -= box.GetExtent(2)*box.GetAxis(2);
	}

	if (index & 2)
	{
		point += box.GetExtent(1)*box.GetAxis(1);
	}
	else
	{
		point -= box.GetExtent(1)*box.GetAxis(1);
	}

	if (index & 1)
	{
		point += box.GetExtent(0)*box.GetAxis(0);
	}
	else
	{
		point -= box.GetExtent(0)*box.GetAxis(0);
	}

	return point;
}

#include STSTEM_WARNING_POP
#endif // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_INTERSECTOR_UTILITY3_DETAIL)

#endif // MATHEMATICS_INTERSECTION_INTERSECTOR_UTILITY3_DETAIL_H

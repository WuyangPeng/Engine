// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 16:40)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_BOX3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_BOX3_BOX3_DETAIL_H

#include "DynamicTestIntersectorBox3Box3.h"

template <typename Real>
Mathematics::DynamicTestIntersectorBox3Box3<Real>
	::DynamicTestIntersectorBox3Box3(const Box3& box0, const Box3& box1, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, mBox0{ box0 }, mBox1{ box1 }
{
	Test();
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DynamicTestIntersectorBox3Box3<Real>
	::GetBox0() const
{
	return mBox0;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DynamicTestIntersectorBox3Box3<Real>
	::GetBox1() const
{
	return mBox1;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorBox3Box3<Real>
	::Test()
{
	if (this->GetLhsVelocity() == this->GetRhsVelocity())
	{
		StaticTestIntersectorBox3Box3<Real> intersector{ mBox0,mBox1 };
		SetIntersectionType(intersector.GetIntersectionType());
		if (intersector.IsIntersection())
		{
			SetContactTime(Math::GetValue(0));
			return;
		}
		return;
	}

	// Cutoff for cosine of angles between box axes.  This is used to catch
	// the cases when at least one pair of axes are parallel.  If this
	// happens, there is no need to include the cross-product axes for
	// separation.
	const auto cutoff = Math::GetValue(1) - Math::GetZeroTolerance();
	auto existsParallelPair = false;

	// convenience variables
	const Vector3D A[]{ mBox0.GetAxis(0),mBox0.GetAxis(1),mBox0.GetAxis(2) };
	const Vector3D B[]{ mBox1.GetAxis(0),mBox1.GetAxis(1),mBox1.GetAxis(2) };
	const Real EA[]{ mBox0.GetExtent(0),mBox0.GetExtent(1),mBox0.GetExtent(2) };
	const Real EB[]{ mBox1.GetExtent(0),mBox1.GetExtent(1),mBox1.GetExtent(2) };
	auto D = mBox1.GetCenter() - mBox0.GetCenter();
	auto W = this->GetRhsVelocity() - this->GetLhsVelocity();
	Real C[3][3]{};     // matrix C = A^T B, c_{ij} = Dot(A_i,B_j)
	Real AbsC[3][3]{};  // |c_{ij}|
	Real AD[3]{};       // Dot(A_i,D)
	Real AW[3]{};       // Dot(A_i,W)
	auto min0 = Math::GetValue(0);
	auto max0 = Math::GetValue(0);
	auto min1 = Math::GetValue(0);
	auto max1 = Math::GetValue(0);
	auto center = Math::GetValue(0);
	auto radius = Math::GetValue(0);
	auto speed = Math::GetValue(0);
	auto i = 0;
	auto j = 0;

	SetContactTime(Math::GetValue(0));
	auto tlast = Math::sm_MaxReal;

	// axes C0+t*A[i]
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			C[i][j] = Vector3DTools::DotProduct(A[i], B[j]);
			AbsC[i][j] = Math::FAbs(C[i][j]);
			if (AbsC[i][j] > cutoff)
			{
				existsParallelPair = true;
			}
		}
		AD[i] = Vector3DTools::DotProduct(A[i], D);
		AW[i] = Vector3DTools::DotProduct(A[i], W);
		min0 = -EA[i];
		max0 = +EA[i];
		radius = EB[0] * AbsC[i][0] + EB[1] * AbsC[i][1] + EB[2] * AbsC[i][2];
		min1 = AD[i] - radius;
		max1 = AD[i] + radius;
		speed = AW[i];
		if (IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tlast))
		{
			this->SetIntersectionType(IntersectionType::Empty);
			return;
		}
	}

	// axes C0+t*B[i]
	for (i = 0; i < 3; ++i)
	{
		radius = EA[0] * AbsC[0][i] + EA[1] * AbsC[1][i] + EA[2] * AbsC[2][i];
		min0 = -radius;
		max0 = +radius;
		center = Vector3DTools::DotProduct(B[i], D);
		min1 = center - EB[i];
		max1 = center + EB[i];
		speed = Vector3DTools::DotProduct(W, B[i]);
		if (this->IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tlast))
		{
			this->SetIntersectionType(IntersectionType::Empty);
			return;
		}
	}

	// At least one pair of box axes was parallel, so the separation is
	// effectively in 2D where checking the "edge" normals is sufficient for
	// the separation of the boxes.
	if (existsParallelPair)
	{
		this->SetIntersectionType(IntersectionType::Other);
		return;
	}

	// axis C0+t*A0xB0
	radius = EA[1] * AbsC[2][0] + EA[2] * AbsC[1][0];
	min0 = -radius;
	max0 = +radius;
	center = AD[2] * C[1][0] - AD[1] * C[2][0];
	radius = EB[1] * AbsC[0][2] + EB[2] * AbsC[0][1];
	min1 = center - radius;
	max1 = center + radius;
	speed = AW[2] * C[1][0] - AW[1] * C[2][0];
	if (IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tlast))
	{
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	// axis C0+t*A0xB1
	radius = EA[1] * AbsC[2][1] + EA[2] * AbsC[1][1];
	min0 = -radius;
	max0 = +radius;
	center = AD[2] * C[1][1] - AD[1] * C[2][1];
	radius = EB[0] * AbsC[0][2] + EB[2] * AbsC[0][0];
	min1 = center - radius;
	max1 = center + radius;
	speed = AW[2] * C[1][1] - AW[1] * C[2][1];
	if (IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tlast))
	{
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	// axis C0+t*A0xB2
	radius = EA[1] * AbsC[2][2] + EA[2] * AbsC[1][2];
	min0 = -radius;
	max0 = +radius;
	center = AD[2] * C[1][2] - AD[1] * C[2][2];
	radius = EB[0] * AbsC[0][1] + EB[1] * AbsC[0][0];
	min1 = center - radius;
	max1 = center + radius;
	speed = AW[2] * C[1][2] - AW[1] * C[2][2];
	if (IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tlast))
	{
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	// axis C0+t*A1xB0
	radius = EA[0] * AbsC[2][0] + EA[2] * AbsC[0][0];
	min0 = -radius;
	max0 = +radius;
	center = AD[0] * C[2][0] - AD[2] * C[0][0];
	radius = EB[1] * AbsC[1][2] + EB[2] * AbsC[1][1];
	min1 = center - radius;
	max1 = center + radius;
	speed = AW[0] * C[2][0] - AW[2] * C[0][0];
	if (IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tlast))
	{
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	// axis C0+t*A1xB1
	radius = EA[0] * AbsC[2][1] + EA[2] * AbsC[0][1];
	min0 = -radius;
	max0 = +radius;
	center = AD[0] * C[2][1] - AD[2] * C[0][1];
	radius = EB[0] * AbsC[1][2] + EB[2] * AbsC[1][0];
	min1 = center - radius;
	max1 = center + radius;
	speed = AW[0] * C[2][1] - AW[2] * C[0][1];
	if (IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tlast))
	{
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	// axis C0+t*A1xB2
	radius = EA[0] * AbsC[2][2] + EA[2] * AbsC[0][2];
	min0 = -radius;
	max0 = +radius;
	center = AD[0] * C[2][2] - AD[2] * C[0][2];
	radius = EB[0] * AbsC[1][1] + EB[1] * AbsC[1][0];
	min1 = center - radius;
	max1 = center + radius;
	speed = AW[0] * C[2][2] - AW[2] * C[0][2];
	if (IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tlast))
	{
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	// axis C0+t*A2xB0
	radius = EA[0] * AbsC[1][0] + EA[1] * AbsC[0][0];
	min0 = -radius;
	max0 = +radius;
	center = AD[1] * C[0][0] - AD[0] * C[1][0];
	radius = EB[1] * AbsC[2][2] + EB[2] * AbsC[2][1];
	min1 = center - radius;
	max1 = center + radius;
	speed = AW[1] * C[0][0] - AW[0] * C[1][0];
	if (IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tlast))
	{
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	// axis C0+t*A2xB1
	radius = EA[0] * AbsC[1][1] + EA[1] * AbsC[0][1];
	min0 = -radius;
	max0 = +radius;
	center = AD[1] * C[0][1] - AD[0] * C[1][1];
	radius = EB[0] * AbsC[2][2] + EB[2] * AbsC[2][0];
	min1 = center - radius;
	max1 = center + radius;
	speed = AW[1] * C[0][1] - AW[0] * C[1][1];
	if (IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tlast))
	{
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	// axis C0+t*A2xB2
	radius = EA[0] * AbsC[1][2] + EA[1] * AbsC[0][2];
	min0 = -radius;
	max0 = +radius;
	center = AD[1] * C[0][2] - AD[0] * C[1][2];
	radius = EB[0] * AbsC[2][1] + EB[1] * AbsC[2][0];
	min1 = center - radius;
	max1 = center + radius;
	speed = AW[1] * C[0][2] - AW[0] * C[1][2];
	if (IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tlast))
	{
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	this->SetIntersectionType(IntersectionType::Other);
}

template <typename Real>
bool Mathematics::DynamicTestIntersectorBox3Box3<Real>
	::IsSeparated(Real min0, Real max0, Real min1, Real max1, Real speed, Real tmax, Real& tlast)
{
	auto invSpeed = Math::GetValue(0);
	auto t = Math::GetValue(0);

	if (max1 < min0) // box1 initially on left of box0
	{
		if (speed <= Math::GetValue(0))
		{
			// The projection intervals are moving apart.
			return true;
		}
		invSpeed = (Math::GetValue(1)) / speed;

		t = (min0 - max1)*invSpeed;
		if (t > this->GetContactTime())
		{
			SetContactTime(t);
		}

		if (this->GetContactTime() > tmax)
		{
			// Intervals do not intersect during the specified time.
			return true;
		}

		t = (max0 - min1)*invSpeed;
		if (t < tlast)
		{
			tlast = t;
		}

		if (this->GetContactTime() > tlast)
		{
			// Physically inconsistent times--the objects cannot intersect.
			return true;
		}
	}
	else if (max0 < min1) // box1 initially on right of box0
	{
		if (speed >= Math::GetValue(0))
		{
			// The projection intervals are moving apart.
			return true;
		}
		invSpeed = (Math::GetValue(1)) / speed;

		t = (max0 - min1)*invSpeed;
		if (t > this->GetContactTime())
		{
			SetContactTime(t);
		}

		if (this->GetContactTime() > tmax)
		{
			// Intervals do not intersect during the specified time.
			return true;
		}

		t = (min0 - max1)*invSpeed;
		if (t < tlast)
		{
			tlast = t;
		}

		if (this->GetContactTime() > tlast)
		{
			// Physically inconsistent times--the objects cannot intersect.
			return true;
		}
	}
	else // box0 and box1 initially overlap
	{
		if (speed > Math::GetValue(0))
		{
			t = (max0 - min1) / speed;
			if (t < tlast)
			{
				tlast = t;
			}

			if (this->GetContactTime() > tlast)
			{
				// Physically inconsistent times--the objects cannot
				// intersect.
				return true;
			}
		}
		else if (speed < Math::GetValue(0))
		{
			t = (min0 - max1) / speed;
			if (t < tlast)
			{
				tlast = t;
			}

			if (this->GetContactTime() > tlast)
			{
				// Physically inconsistent times--the objects cannot
				// intersect.
				return true;
			}
		}
	}

	return false;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_BOX3_BOX3_DETAIL_H
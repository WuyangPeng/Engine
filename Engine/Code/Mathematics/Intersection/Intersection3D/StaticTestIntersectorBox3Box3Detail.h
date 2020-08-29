// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/15 10:21)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_BOX3_DETAIL_H

#include "StaticTestIntersectorBox3Box3.h"
#include "IntersectorUtility3.h"

template <typename Real>
Mathematics::StaticTestIntersectorBox3Box3<Real>
	::StaticTestIntersectorBox3Box3(const Box3& box0,const Box3& box1)
	: mBox0{ box0 }, mBox1{ box1 }
{
    
	Test();
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::StaticTestIntersectorBox3Box3<Real>
	::GetBox0() const
{
    return mBox0;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::StaticTestIntersectorBox3Box3<Real>
	::GetBox1() const
{
    return mBox1;
}

template <typename Real>
void Mathematics::StaticTestIntersectorBox3Box3<Real>
	::Test()
{
    // Cutoff for cosine of angles between box axes.  This is used to catch
    // the cases when at least one pair of axes are parallel.  If this
    // happens, there is no need to test for separation along the
    // Cross(A[i],B[j]) directions.
    const auto cutoff = static_cast<Real>(1) - Math::GetZeroTolerance();
	auto existsParallelPair = false;
    int i;

    // Convenience variables.
   // const Vector3D* A = mBox0->Axis;
    //const Vector3D* B = mBox1->Axis;
   // const Real* EA = mBox0->Extent;
   // const Real* EB = mBox1->Extent;

    // Compute difference of box centers, D = C1-C0.
	auto D = mBox1.GetCenter() - mBox0.GetCenter();

    Real C[3][3];     // matrix C = A^T B, c_{ij} = Dot(A_i,B_j)
    Real AbsC[3][3];  // |c_{ij}|
    Real AD[3];       // Dot(A_i,D)
    Real r0, r1, r;   // interval radii and distance between centers
    Real r01;         // = R0 + R1

    // axis C0+t*A0
    for (i = 0; i < 3; ++i)
    {
		C[0][i] = Vector3DTools::DotProduct(mBox0.GetAxis(0),mBox1.GetAxis(i));
        AbsC[0][i] = Math::FAbs(C[0][i]);
        if (AbsC[0][i] > cutoff)
        {
            existsParallelPair = true;
        }
    }
	AD[0] = Vector3DTools::DotProduct(mBox0.GetAxis(0),D);
    r = Math::FAbs(AD[0]);
	r1 = mBox1.GetExtent(0) * AbsC[0][0] + mBox1.GetExtent(1)* AbsC[0][1] + mBox1.GetExtent(2) * AbsC[0][2];
	r01 = mBox0.GetExtent(0) + r1;
    if (r > r01)
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // axis C0+t*A1
    for (i = 0; i < 3; ++i)
    {
		C[1][i] = Vector3DTools::DotProduct(mBox0.GetAxis(1), mBox1.GetAxis(i)); 
        AbsC[1][i] = Math::FAbs(C[1][i]);
        if (AbsC[1][i] > cutoff)
        {
            existsParallelPair = true;
        }
    }
	AD[1] = Vector3DTools::DotProduct(mBox0.GetAxis(1),D);
    r = Math::FAbs(AD[1]);
	r1 = mBox1.GetExtent(0)*AbsC[1][0] + mBox1.GetExtent(1) * AbsC[1][1] + mBox1.GetExtent(2) * AbsC[1][2];
	r01 = mBox0.GetExtent(1) + r1;
    if (r > r01)
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // axis C0+t*A2
    for (i = 0; i < 3; ++i)
    {
		C[2][i] = Vector3DTools::DotProduct(mBox0.GetAxis(2), mBox1.GetAxis(i));
        AbsC[2][i] = Math::FAbs(C[2][i]);
        if (AbsC[2][i] > cutoff)
        {
            existsParallelPair = true;
        }
    }
	AD[2] = Vector3DTools::DotProduct(mBox0.GetAxis(2),D);
    r = Math::FAbs(AD[2]);
	r1 = mBox1.GetExtent(0)*AbsC[2][0] + mBox1.GetExtent(1) * AbsC[2][1] + mBox1.GetExtent(2) * AbsC[2][2];
	r01 = mBox0.GetExtent(2) + r1;
    if (r > r01)
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // axis C0+t*B0
	r = Math::FAbs(Vector3DTools::DotProduct(mBox1.GetAxis(0),D));
	r0 = mBox1.GetExtent(0)*AbsC[0][0] + mBox1.GetExtent(1) * AbsC[1][0] + mBox1.GetExtent(2) * AbsC[2][0];
	r01 = r0 + mBox1.GetExtent(0);
    if (r > r01)
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // axis C0+t*B1
	r = Math::FAbs(Vector3DTools::DotProduct(mBox1.GetAxis(1),D));
	r0 = mBox1.GetExtent(0)*AbsC[0][1] + mBox1.GetExtent(1) * AbsC[1][1] + mBox1.GetExtent(2) * AbsC[2][1];
	r01 = r0 + mBox1.GetExtent(1);
    if (r > r01)
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // axis C0+t*B2
	r = Math::FAbs(Vector3DTools::DotProduct(mBox1.GetAxis(2),D));
	r0 = mBox1.GetExtent(0)*AbsC[0][2] + mBox1.GetExtent(1) * AbsC[1][2] + mBox1.GetExtent(2) * AbsC[2][2];
	r01 = r0 + mBox1.GetExtent(2);
    if (r > r01)
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // At least one pair of box axes was parallel, so the separation is
    // effectively in 2D where checking the "edge" normals is sufficient for
    // the separation of the boxes.
    if (existsParallelPair)
    {
		this->SetIntersectionType(IntersectionType::Point);
        return;
    }

    // axis C0+t*A0xB0
    r = Math::FAbs(AD[2]*C[1][0] - AD[1]*C[2][0]);
	r0 = mBox0.GetExtent(1)*AbsC[2][0] + mBox0.GetExtent(2) * AbsC[1][0];
	r1 = mBox1.GetExtent(1)*AbsC[0][2] + mBox1.GetExtent(2) * AbsC[0][1];
    r01 = r0 + r1;
    if (r > r01)
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // axis C0+t*A0xB1
    r = Math::FAbs(AD[2]*C[1][1] - AD[1]*C[2][1]);
	r0 = mBox0.GetExtent(1)*AbsC[2][1] + mBox0.GetExtent(2)* AbsC[1][1];
	r1 = mBox1.GetExtent(0)*AbsC[0][2] + mBox1.GetExtent(2) * AbsC[0][0];
    r01 = r0 + r1;
    if (r > r01)
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // axis C0+t*A0xB2
    r = Math::FAbs(AD[2]*C[1][2] - AD[1]*C[2][2]);
	r0 = mBox0.GetExtent(1)*AbsC[2][2] + mBox0.GetExtent(2) * AbsC[1][2];
	r1 = mBox1.GetExtent(0)*AbsC[0][1] + mBox1.GetExtent(1) * AbsC[0][0];
    r01 = r0 + r1;
    if (r > r01)
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // axis C0+t*A1xB0
    r = Math::FAbs(AD[0]*C[2][0] - AD[2]*C[0][0]);
	r0 = mBox0.GetExtent(0)*AbsC[2][0] + mBox0.GetExtent(2) * AbsC[0][0];
	r1 = mBox1.GetExtent(1)*AbsC[1][2] + mBox1.GetExtent(2) * AbsC[1][1];
    r01 = r0 + r1;
    if (r > r01)
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // axis C0+t*A1xB1
    r = Math::FAbs(AD[0]*C[2][1] - AD[2]*C[0][1]);
	r0 = mBox0.GetExtent(0)*AbsC[2][1] + mBox0.GetExtent(2) * AbsC[0][1];
	r1 = mBox1.GetExtent(0)*AbsC[1][2] + mBox1.GetExtent(2)* AbsC[1][0];
    r01 = r0 + r1;
    if (r > r01)
	{
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // axis C0+t*A1xB2
    r = Math::FAbs(AD[0]*C[2][2] - AD[2]*C[0][2]);
	r0 = mBox0.GetExtent(0)*AbsC[2][2] + mBox0.GetExtent(2)* AbsC[0][2];
	r1 = mBox1.GetExtent(0)*AbsC[1][1] + mBox1.GetExtent(1) * AbsC[1][0];
    r01 = r0 + r1;
    if (r > r01)
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // axis C0+t*A2xB0
    r = Math::FAbs(AD[1]*C[0][0] - AD[0]*C[1][0]);
	r0 = mBox0.GetExtent(0)*AbsC[1][0] + mBox0.GetExtent(1) * AbsC[0][0];
	r1 = mBox1.GetExtent(1)*AbsC[2][2] + mBox1.GetExtent(2) * AbsC[2][1];
    r01 = r0 + r1;
    if (r > r01)
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // axis C0+t*A2xB1
    r = Math::FAbs(AD[1]*C[0][1] - AD[0]*C[1][1]);
	r0 = mBox0.GetExtent(0)*AbsC[1][1] + mBox0.GetExtent(1) * AbsC[0][1];
	r1 = mBox1.GetExtent(0)*AbsC[2][2] + mBox1.GetExtent(2) * AbsC[2][0];
    r01 = r0 + r1;
    if (r > r01)
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // axis C0+t*A2xB2
    r = Math::FAbs(AD[1]*C[0][2] - AD[0]*C[1][2]);
	r0 = mBox0.GetExtent(0)*AbsC[1][2] + mBox0.GetExtent(1)* AbsC[0][2];
	r1 = mBox1.GetExtent(0)*AbsC[2][1] + mBox1.GetExtent(1) * AbsC[2][0];
    r01 = r0 + r1;
    if (r > r01)
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

	this->SetIntersectionType(IntersectionType::Point);
    return;
}
 
#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_BOX3_DETAIL_H
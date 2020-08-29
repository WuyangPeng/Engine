// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 13:30)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_LOZENGE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_LOZENGE3_DETAIL_H

#include "StaticTestIntersectorPlane3Lozenge3.h"

template <typename Real>
Mathematics::StaticTestIntersectorPlane3Lozenge3<Real>
	::StaticTestIntersectorPlane3Lozenge3 (const Plane3& plane,const Lozenge3& lozenge)
	: mPlane{ plane }, mLozenge{ lozenge }
{
	Test();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorPlane3Lozenge3<Real>
	::GetPlane() const
{
    return mPlane;
}

template <typename Real>
const Mathematics::Lozenge3<Real> Mathematics::StaticTestIntersectorPlane3Lozenge3<Real>
	::GetLozenge() const
{
    return mLozenge;
}

template <typename Real>
void Mathematics::StaticTestIntersectorPlane3Lozenge3<Real>
	::Test()
{
	auto sDistMM = mPlane.DistanceTo(mLozenge.GetRectangle().GetMMCorner());
	auto sDistPM = mPlane.DistanceTo(mLozenge.GetRectangle().GetPMCorner());
    if (sDistMM*sDistPM <= Math<Real>::GetValue(0))
    {
        // Two lozenge ends on opposite sides of the plane.
		this->SetIntersectionType(IntersectionType::Other);
        return;
    }

	Real sDistMP = mPlane.DistanceTo(mLozenge.GetRectangle().GetMPCorner());
    if (sDistMM*sDistMP <= Math<Real>::GetValue(0))
    {
        // Two lozenge ends on opposite sides of the plane.
		this->SetIntersectionType(IntersectionType::Other);
        return;
    }

	auto sDistPP = mPlane.DistanceTo(mLozenge.GetRectangle().GetPPCorner());
    if (sDistPM*sDistPP <= Math<Real>::GetValue(0))
    {
        // Two lozenge ends on opposite sides of the plane.
		this->SetIntersectionType(IntersectionType::Other);
        return;
    }

    // The lozenge rectangle corners are all on one side of the plane.
    // The spheres centered at the corners, with radius that of the lozenge,
    // might intersect the plane.
	if (Math::FAbs(sDistMM) <= mLozenge.GetRadius()|| Math::FAbs(sDistPM) <= mLozenge.GetRadius() || Math::FAbs(sDistMP) <= mLozenge.GetRadius() || Math::FAbs(sDistPP) <= mLozenge.GetRadius())
	{
		this->SetIntersectionType(IntersectionType::Other);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}

template <typename Real>
bool Mathematics::StaticTestIntersectorPlane3Lozenge3<Real>
	::LozengeIsCulled() const
{
	auto sDistMM = mPlane.DistanceTo(mLozenge.GetRectangle().GetMMCorner());
    if (sDistMM < Math<Real>::GetValue(0))
    {
		auto sDistPM = mPlane.DistanceTo(mLozenge.GetRectangle().GetPMCorner());
        if (sDistPM < Math<Real>::GetValue(0))
        {
			auto sDistMP = mPlane.DistanceTo(mLozenge.GetRectangle().GetMPCorner());
            if (sDistMP < Math<Real>::GetValue(0))
            {
				auto sDistPP = mPlane.DistanceTo(mLozenge.GetRectangle().GetPPCorner());
                if (sDistPP < Math<Real>::GetValue(0))
                {
                    // All four lozenge corners on negative side of plane.
                    if (sDistMM <= sDistPM)
                    {
                        if (sDistMM <= sDistMP)
                        {
                            return sDistMM <= -mLozenge.GetRadius();
                        }
                        else
                        {
							return sDistMP <= -mLozenge.GetRadius();
                        }
                    }
                    else
                    {
                        if (sDistPM <= sDistPP)
                        {
							return sDistPM <= -mLozenge.GetRadius();
                        }
                        else
                        {
							return sDistPP <= -mLozenge.GetRadius();
                        }
                    }
                }
            }
        }
    }

    return false;
}


#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_LOZENGE3_DETAIL_H
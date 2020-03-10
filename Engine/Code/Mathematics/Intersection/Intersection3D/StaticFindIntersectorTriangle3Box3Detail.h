// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/15 10:04)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_DETAIL_H

#include "StaticFindIntersectorTriangle3Box3.h"
#include "StaticFindIntersectorSegment3Box3.h" 
#include "IntersectorUtility3.h"

template <typename Real>
Mathematics::StaticFindIntersectorTriangle3Box3<Real>
	::StaticFindIntersectorTriangle3Box3 (const Triangle3& triangle,const Box3& box)
	:mTriangle{ triangle }, mBox{ box }
{
    mQuantity = 0;
	Find();
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::StaticFindIntersectorTriangle3Box3<Real>
	::GetTriangle() const
{
    return mTriangle;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::StaticFindIntersectorTriangle3Box3<Real>
	::GetBox() const
{
    return mBox;
}
 
template <typename Real>
void Mathematics::StaticFindIntersectorTriangle3Box3<Real>
	::Find()
{
    // Start with the triangle and clip it against each face of the box.
    mQuantity = 3;
    for (auto i = 0; i < 3; ++i)
    {
        mPoint[i] = mTriangle.GetVertex()[i];
    }

    for (auto dir = -1; dir <= 1; dir += 2)
    {
        for (auto side = 0; side < 3; ++side)
        {
			auto innerNormal = ((Real)dir)*mBox.GetAxis(side);
			auto constant = Vector3DTools::DotProduct(innerNormal,mBox.GetCenter()) - mBox.GetExtent(side);
            ClipConvexPolygonAgainstPlane(innerNormal, constant,   mQuantity, mPoint);
        }
    }

	if (mQuantity > 0)
	{
		this->SetIntersectionType(IntersectionType::Point);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}
 
template <typename Real>
int Mathematics::StaticFindIntersectorTriangle3Box3<Real>
	::GetQuantity() const
{
    return mQuantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorTriangle3Box3<Real>
	::GetPoint(int i) const
{
    return mPoint[i];
}
 
#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_DETAIL_H
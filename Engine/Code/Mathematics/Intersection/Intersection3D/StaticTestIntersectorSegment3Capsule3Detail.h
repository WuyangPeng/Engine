// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 13:38)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_CAPSULE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_CAPSULE3_DETAIL_H

#include "StaticTestIntersectorLine3Capsule3.h"
#include "StaticTestIntersectorSegment3Capsule3.h"
#include "Mathematics/Distance/Distance3D/DistanceSegment3Segment3Detail.h"

template <typename Real>
Mathematics::StaticTestIntersectorSegment3Capsule3<Real>::StaticTestIntersectorSegment3Capsule3(const Segment3& rkSegment, const Capsule3& rkCapsule, const Real epsilon)
    : ParentType{ epsilon }, m_Segment{ rkSegment }, m_Capsule{ rkCapsule }
{
    Test();
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticTestIntersectorSegment3Capsule3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::StaticTestIntersectorSegment3Capsule3<Real>::GetSegment() const
{
    return m_Segment;
}

template <typename Real>
const Mathematics::Capsule3<Real> Mathematics::StaticTestIntersectorSegment3Capsule3<Real>::GetCapsule() const
{
    return m_Capsule;
}

template <typename Real>
void Mathematics::StaticTestIntersectorSegment3Capsule3<Real>::Test()
{
    auto distance = DistanceSegment3Segment3<Real>(m_Segment, m_Capsule.GetSegment()).Get().GetDistance();
    if (distance <= m_Capsule.GetRadius())
    {
        this->SetIntersectionType(IntersectionType::Other);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_CAPSULE3_DETAIL_H
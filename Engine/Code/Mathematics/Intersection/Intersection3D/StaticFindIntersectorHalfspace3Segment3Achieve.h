///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.1 (2021/01/18 11:24)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_SEGMENT3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_SEGMENT3_ACHIEVE_H

#include "IntersectorUtility3Detail.h"
#include "StaticFindIntersectorHalfspace3Segment3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorHalfspace3Segment3<Real>::StaticFindIntersectorHalfspace3Segment3(const Plane3& halfspace, const Segment3& segment, const Real epsilon)
    : ParentType{ epsilon }, m_Halfspace{ halfspace }, m_Segment{ segment }, m_Quantity{}, m_Point0{}, m_Point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorHalfspace3Segment3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real> 
const Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorHalfspace3Segment3<Real>::GetHalfspace() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Halfspace;
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::StaticFindIntersectorHalfspace3Segment3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Segment;
}

template <typename Real>
void Mathematics::StaticFindIntersectorHalfspace3Segment3<Real>::Find()
{
    // ���߶ο�ʼ������ü���ƽ���ϡ�

    typename IntersectorUtility3<Real>::Container container{ m_Segment.GetBeginPoint(), m_Point1 = m_Segment.GetEndPoint() };

    container = IntersectorUtility3<Real>::ClipConvexPolygonAgainstPlane(-m_Halfspace.GetNormal(), -m_Halfspace.GetConstant(), container);
    m_Quantity = boost::numeric_cast<int>(container.size());

    if (m_Quantity == 0)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        
    }
    else if (m_Quantity == 1)
    {
        m_Point0 = container.at(0);
        this->SetIntersectionType(IntersectionType::Point);
    }
    else if(1 < m_Quantity)
    {
        m_Point0 = container.at(0);
        m_Point1 = container.at(1);
        this->SetIntersectionType(IntersectionType::Point);
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorHalfspace3Segment3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorHalfspace3Segment3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < m_Quantity)
    {
        if (index == 0)
            return m_Point0;
        else if (index == 1)
            return m_Point1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("����Խ��\n"s));
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_SEGMENT3_ACHIEVE_H
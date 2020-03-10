// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/13 10:18)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_BOX2_CIRCLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_BOX2_CIRCLE2_DETAIL_H 

#include "StaticTestIntersectorBox2Circle2.h"
#include "Mathematics/Distance/Distance2D/DistancePoint2Box2.h"

template <typename Real>
Mathematics::StaticTestIntersectorBox2Circle2<Real>
	::StaticTestIntersectorBox2Circle2(const Box2& box, const Circle2& circle, const Real epsilon)
	:ParentType{ epsilon }, m_Box{ box }, m_Circle{ circle }
{
	Test();
}

template <typename Real>
typename const Mathematics::StaticTestIntersectorBox2Circle2<Real>::Box2 Mathematics::StaticTestIntersectorBox2Circle2<Real>
	::GetBox () const
{
    return m_Box;
}

template <typename Real>
typename const Mathematics::StaticTestIntersectorBox2Circle2<Real>::Circle2 Mathematics::StaticTestIntersectorBox2Circle2<Real>
	::GetCircle () const
{
    return m_Circle;
}

template <typename Real>
void Mathematics::StaticTestIntersectorBox2Circle2<Real>
	::Test ()
{
    auto distance = DistancePoint2Box2<Real>(m_Circle.GetCenter(), m_Box).Get().GetDistance();
    if(distance <= m_Circle.GetRadius())
	{
		this->SetIntersectionType(IntersectionType::Point);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}	
}
 
#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_BOX2_CIRCLE2_DETAIL_H
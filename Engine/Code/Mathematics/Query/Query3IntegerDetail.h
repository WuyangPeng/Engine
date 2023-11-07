///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
///	ÁªÏµ×÷Õß£º94458936@qq.com
///
///	±ê×¼£ºstd:c++20
///	°æ±¾£º0.9.1.6 (2023/10/27 13:58)

#ifndef MATHEMATICS_QUERY_QUERY3_INTEGER_DETAIL_H
#define MATHEMATICS_QUERY_QUERY3_INTEGER_DETAIL_H

#include "Query3Integer.h"
#include "QueryDotToolsDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Rational/IntegerDetail.h"

template <typename Real>
Mathematics::Query3Integer<Real>::Query3Integer(const VerticesType& vertices)
    : ParentType{ vertices }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Query3Integer<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::QueryType Mathematics::Query3Integer<Real>::GetType() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return QueryType::Interger;
}

template <typename Real>
Mathematics::PlaneQueryType Mathematics::Query3Integer<Real>::ToPlane(int index, int v0, int v1, int v2) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ParentType::ToPlane(index, v0, v1, v2);
}

template <typename Real>
Mathematics::PlaneQueryType Mathematics::Query3Integer<Real>::ToPlane(const Vector3& testVector, int v0, int v1, int v2) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(0 <= v0 && v0 < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");
    MATHEMATICS_ASSERTION_0(0 <= v1 && v1 < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");
    MATHEMATICS_ASSERTION_0(0 <= v2 && v2 < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");

    const auto vector0 = this->GetVertice(v0);
    const auto vector1 = this->GetVertice(v1);
    const auto vector2 = this->GetVertice(v2);

    const Integer<4> x0{ testVector.GetX() - vector0.GetX() };
    const Integer<4> y0{ testVector.GetY() - vector0.GetY() };
    const Integer<4> z0{ testVector.GetZ() - vector0.GetZ() };
    const Integer<4> x1{ vector1.GetX() - vector0.GetX() };
    const Integer<4> y1{ vector1.GetY() - vector0.GetY() };
    const Integer<4> z1{ vector1.GetZ() - vector0.GetZ() };
    const Integer<4> x2{ vector2.GetX() - vector0.GetX() };
    const Integer<4> y2{ vector2.GetY() - vector0.GetY() };
    const Integer<4> z2{ vector2.GetZ() - vector0.GetZ() };

    if (const auto det = QueryDotTools<Integer<4>>::Det3(x0, y0, z0, x1, y1, z1, x2, y2, z2);
        Integer<4>{} < det)
        return PlaneQueryType::PositiveSide;
    else if (det < Integer<4>{})
        return PlaneQueryType::NegativeSide;
    else
        return PlaneQueryType::OnPlane;
}

template <typename Real>
Mathematics::CircumsphereQueryType Mathematics::Query3Integer<Real>::ToCircumsphere(int index, int v0, int v1, int v2, int v3) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ParentType::ToCircumsphere(index, v0, v1, v2, v3);
}

template <typename Real>
Mathematics::CircumsphereQueryType Mathematics::Query3Integer<Real>::ToCircumsphere(const Vector3& testVector, int v0, int v1, int v2, int v3) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(0 <= v0 && v0 < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");
    MATHEMATICS_ASSERTION_0(0 <= v1 && v1 < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");
    MATHEMATICS_ASSERTION_0(0 <= v2 && v2 < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");

    const auto vector0 = this->GetVertice(v0);
    const auto vector1 = this->GetVertice(v1);
    const auto vector2 = this->GetVertice(v2);
    const auto vector3 = this->GetVertice(v3);

    const Integer<6> s0x{ vector0.GetX() + testVector.GetX() };
    const Integer<6> d0x{ vector0.GetX() - testVector.GetX() };
    const Integer<6> s0y{ vector0.GetY() + testVector.GetY() };
    const Integer<6> d0y{ vector0.GetY() - testVector.GetY() };
    const Integer<6> s0z{ vector0.GetZ() + testVector.GetZ() };
    const Integer<6> d0z{ vector0.GetZ() - testVector.GetZ() };
    const Integer<6> s1x{ vector1.GetX() + testVector.GetX() };
    const Integer<6> d1x{ vector1.GetX() - testVector.GetX() };
    const Integer<6> s1y{ vector1.GetY() + testVector.GetY() };
    const Integer<6> d1y{ vector1.GetY() - testVector.GetY() };
    const Integer<6> s1z{ vector1.GetZ() + testVector.GetZ() };
    const Integer<6> d1z{ vector1.GetZ() - testVector.GetZ() };
    const Integer<6> s2x{ vector2.GetX() + testVector.GetX() };
    const Integer<6> d2x{ vector2.GetX() - testVector.GetX() };
    const Integer<6> s2y{ vector2.GetY() + testVector.GetY() };
    const Integer<6> d2y{ vector2.GetY() - testVector.GetY() };
    const Integer<6> s2z{ vector2.GetZ() + testVector.GetZ() };
    const Integer<6> d2z{ vector2.GetZ() - testVector.GetZ() };
    const Integer<6> s3x{ vector3.GetX() + testVector.GetX() };
    const Integer<6> d3x{ vector3.GetX() - testVector.GetX() };
    const Integer<6> s3y{ vector3.GetY() + testVector.GetY() };
    const Integer<6> d3y{ vector3.GetY() - testVector.GetY() };
    const Integer<6> s3z{ vector3.GetZ() + testVector.GetZ() };
    const Integer<6> d3z{ vector3.GetZ() - testVector.GetZ() };
    const auto w0 = s0x * d0x + s0y * d0y + s0z * d0z;
    const auto w1 = s1x * d1x + s1y * d1y + s1z * d1z;
    const auto w2 = s2x * d2x + s2y * d2y + s2z * d2z;
    const auto w3 = s3x * d3x + s3y * d3y + s3z * d3z;

    if (const auto det = QueryDotTools<Integer<6>>::Det4(d0x, d0y, d0z, w0, d1x, d1y, d1z, w1, d2x, d2y, d2z, w2, d3x, d3y, d3z, w3);
        Integer<6>{} < det)
        return CircumsphereQueryType::Outside;
    else if (det < Integer<6>{})
        return CircumsphereQueryType::Inside;
    else
        return CircumsphereQueryType::OnCircumsphere;
}

#endif  // MATHEMATICS_QUERY_QUERY3_INTEGER_DETAIL_H

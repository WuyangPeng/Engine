///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
///	ÁªÏµ×÷Õß£º94458936@qq.com
///
///	±ê×¼£ºstd:c++17
///	ÒýÇæ°æ±¾£º0.5.2.5 (2020/11/30 16:28)

#ifndef MATHEMATICS_QUERY_QUERY3_FILTERED_DETAIL_H
#define MATHEMATICS_QUERY_QUERY3_FILTERED_DETAIL_H

#include "Query3Filtered.h"
#include "QueryDotToolsDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Query3Filtered<Real>::Query3Filtered(const VerticesType& vertices, Real uncertainty)
    : ParentType{ vertices }, m_RationalQuery{ vertices }, m_Uncertainty{ uncertainty }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Query3Filtered<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && Math::GetValue(0) <= m_Uncertainty && m_Uncertainty <= Math::GetValue(1))
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::QueryType Mathematics::Query3Filtered<Real>::GetType() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return QueryType::Filtered;
}

template <typename Real>
Mathematics::PlaneQueryType Mathematics::Query3Filtered<Real>::ToPlane(int index, int v0, int v1, int v2) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ParentType::ToPlane(index, v0, v1, v2);
}

template <typename Real>
Mathematics::PlaneQueryType Mathematics::Query3Filtered<Real>::ToPlane(const Vector3D& testVector, int v0, int v1, int v2) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(0 <= v0 && v0 < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");
    MATHEMATICS_ASSERTION_0(0 <= v1 && v1 < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");
    MATHEMATICS_ASSERTION_0(0 <= v2 && v2 < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");

    const auto vector0 = this->GetVertice(v0);
    const auto vector1 = this->GetVertice(v1);
    const auto vector2 = this->GetVertice(v2);

    auto x0 = testVector.GetX() - vector0.GetX();
    auto y0 = testVector.GetY() - vector0.GetY();
    auto z0 = testVector.GetZ() - vector0.GetZ();
    auto x1 = vector1.GetX() - vector0.GetX();
    auto y1 = vector1.GetY() - vector0.GetY();
    auto z1 = vector1.GetZ() - vector0.GetZ();
    auto x2 = vector2.GetX() - vector0.GetX();
    auto y2 = vector2.GetY() - vector0.GetY();
    auto z2 = vector2.GetZ() - vector0.GetZ();

    auto len0 = Math::Sqrt(x0 * x0 + y0 * y0 + z0 * z0);
    auto len1 = Math::Sqrt(x1 * x1 + y1 * y1 + z1 * z1);
    auto len2 = Math::Sqrt(x2 * x2 + y2 * y2 + z2 * z2);

    auto scaledUncertainty = m_Uncertainty * len0 * len1 * len2;

    auto det = QueryDotTools<Real>::Det3(x0, y0, z0, x1, y1, z1, x2, y2, z2);
    if (scaledUncertainty <= Math::FAbs(det))
    {
        if (Math::FAbs(det) <= Math::GetZeroTolerance())
            return PlaneQueryType::OnPlane;
        else if (Math::GetValue(0) < det)
            return PlaneQueryType::PositiveSide;
        else
            return PlaneQueryType::NegativeSide;
    }

    return m_RationalQuery.ToPlane(testVector, v0, v1, v2);
}

template <typename Real>
Mathematics::CircumsphereQueryType Mathematics::Query3Filtered<Real>::ToCircumsphere(int index, int v0, int v1, int v2, int v3) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ParentType::ToCircumsphere(index, v0, v1, v2, v3);
}

template <typename Real>
Mathematics::CircumsphereQueryType Mathematics::Query3Filtered<Real>::ToCircumsphere(const Vector3D& testVector, int v0, int v1, int v2, int v3) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(0 <= v0 && v0 < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");
    MATHEMATICS_ASSERTION_0(0 <= v1 && v1 < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");
    MATHEMATICS_ASSERTION_0(0 <= v2 && v2 < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");
    MATHEMATICS_ASSERTION_0(0 <= v3 && v3 < this->GetNumVertices(), "Ë÷Òý´íÎó£¡");

    const auto vector0 = this->GetVertice(v0);
    const auto vector1 = this->GetVertice(v1);
    const auto vector2 = this->GetVertice(v2);
    const auto vector3 = this->GetVertice(v3);

    auto s0x = vector0.GetX() + testVector.GetX();
    auto d0x = vector0.GetX() - testVector.GetX();
    auto s0y = vector0.GetY() + testVector.GetY();
    auto d0y = vector0.GetY() - testVector.GetY();
    auto s0z = vector0.GetZ() + testVector.GetZ();
    auto d0z = vector0.GetZ() - testVector.GetZ();
    auto s1x = vector1.GetX() + testVector.GetX();
    auto d1x = vector1.GetX() - testVector.GetX();
    auto s1y = vector1.GetY() + testVector.GetY();
    auto d1y = vector1.GetY() - testVector.GetY();
    auto s1z = vector1.GetZ() + testVector.GetZ();
    auto d1z = vector1.GetZ() - testVector.GetZ();
    auto s2x = vector2.GetX() + testVector.GetX();
    auto d2x = vector2.GetX() - testVector.GetX();
    auto s2y = vector2.GetY() + testVector.GetY();
    auto d2y = vector2.GetY() - testVector.GetY();
    auto s2z = vector2.GetZ() + testVector.GetZ();
    auto d2z = vector2.GetZ() - testVector.GetZ();
    auto s3x = vector3.GetX() + testVector.GetX();
    auto d3x = vector3.GetX() - testVector.GetX();
    auto s3y = vector3.GetY() + testVector.GetY();
    auto d3y = vector3.GetY() - testVector.GetY();
    auto s3z = vector3.GetZ() + testVector.GetZ();
    auto d3z = vector3.GetZ() - testVector.GetZ();
    auto w0 = s0x * d0x + s0y * d0y + s0z * d0z;
    auto w1 = s1x * d1x + s1y * d1y + s1z * d1z;
    auto w2 = s2x * d2x + s2y * d2y + s2z * d2z;
    auto w3 = s3x * d3x + s3y * d3y + s3z * d3z;

    auto len0 = Math::Sqrt(d0x * d0x + d0y * d0y + d0z * d0z + w0 * w0);
    auto len1 = Math::Sqrt(d1x * d1x + d1y * d1y + d1z * d1z + w1 * w1);
    auto len2 = Math::Sqrt(d2x * d2x + d2y * d2y + d2z * d2z + w2 * w2);
    auto len3 = Math::Sqrt(d3x * d3x + d3y * d3y + d3z * d3z + w3 * w3);
    auto scaledUncertainty = m_Uncertainty * len0 * len1 * len2 * len3;

    auto det = QueryDotTools<Real>::Det4(d0x, d0y, d0z, w0, d1x, d1y, d1z, w1, d2x, d2y, d2z, w2, d3x, d3y, d3z, w3);

    if (scaledUncertainty <= Math::FAbs(det))
    {
        if (Math::FAbs(det) <= Math::GetZeroTolerance())
            return CircumsphereQueryType::OnCircumsphere;
        else if (det < Math::GetValue(0))
            return CircumsphereQueryType::Inside;
        else
            return CircumsphereQueryType::Outside;
    }

    return m_RationalQuery.ToCircumsphere(testVector, v0, v1, v2, v3);
}

#endif  // MATHEMATICS_QUERY_QUERY3_FILTERED_DETAIL_H

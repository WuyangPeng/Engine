/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 23:34)

#ifndef MATHEMATICS_QUERY_QUERY3_RATIONAL_DETAIL_H
#define MATHEMATICS_QUERY_QUERY3_RATIONAL_DETAIL_H

#include "Query3Rational.h"
#include "QueryDotToolsDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Rational/IntegerDetail.h"
#include "Mathematics/Rational/RationalVector3Detail.h"
#include "Mathematics/Rational/RationalVectorDetail.h"
#include "Mathematics/Rational/SignRationalDetail.h"

template <typename Real>
Mathematics::Query3Rational<Real>::Query3Rational(const VerticesType& vertices)
    : ParentType{ vertices }, rationalVertices{}
{
    Convert();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::Query3Rational<Real>::Convert()
{
    const auto numVertices = this->GetNumVertices();

    for (auto index = 0; index < numVertices; ++index)
    {
        const auto vertex = this->GetVertex(index);

        QueryRational rational0{ vertex.GetX() };
        QueryRational rational1{ vertex.GetY() };
        QueryRational rational2{ vertex.GetZ() };

        rationalVertices.emplace_back(rational0, rational1, rational2);
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Query3Rational<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::QueryType Mathematics::Query3Rational<Real>::GetType() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return QueryType::Rational;
}

template <typename Real>
Mathematics::PlaneQueryType Mathematics::Query3Rational<Real>::ToPlane(int index, int v0, int v1, int v2) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(rationalVertices.size()), "��������");

    return ToPlane(rationalVertices.at(index), v0, v1, v2);
}

template <typename Real>
Mathematics::PlaneQueryType Mathematics::Query3Rational<Real>::ToPlane(const Vector3& testVector, int v0, int v1, int v2) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const QueryRational rational0{ testVector.GetX() };
    const QueryRational rational1{ testVector.GetY() };
    const QueryRational rational2{ testVector.GetZ() };

    const QueryRationalVector queryRationalVector{ rational0, rational1, rational2 };

    return ToPlane(queryRationalVector, v0, v1, v2);
}

template <typename Real>
Mathematics::PlaneQueryType Mathematics::Query3Rational<Real>::ToPlane(const QueryRationalVector& rationalTest, int v0, int v1, int v2) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto x0 = rationalTest.GetX() - rationalVertices.at(v0).GetX();
    const auto y0 = rationalTest.GetY() - rationalVertices.at(v0).GetY();
    const auto z0 = rationalTest.GetZ() - rationalVertices.at(v0).GetZ();
    const auto x1 = rationalVertices.at(v1).GetX() - rationalVertices.at(v0).GetX();
    const auto y1 = rationalVertices.at(v1).GetY() - rationalVertices.at(v0).GetY();
    const auto z1 = rationalVertices.at(v1).GetZ() - rationalVertices.at(v0).GetZ();
    const auto x2 = rationalVertices.at(v2).GetX() - rationalVertices.at(v0).GetX();
    const auto y2 = rationalVertices.at(v2).GetY() - rationalVertices.at(v0).GetY();
    const auto z2 = rationalVertices.at(v2).GetZ() - rationalVertices.at(v0).GetZ();

    const auto det = QueryDotTools<QueryRational>::Det3(x0, y0, z0, x1, y1, z1, x2, y2, z2);

    if (QueryRational{} < det)
        return PlaneQueryType::PositiveSide;
    else if (det < QueryRational{})
        return PlaneQueryType::NegativeSide;
    else
        return PlaneQueryType::OnPlane;
}

template <typename Real>
Mathematics::TetrahedronQueryType Mathematics::Query3Rational<Real>::ToTetrahedron(int index, int v0, int v1, int v2, int v3) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ToTetrahedron(rationalVertices.at(index), v0, v1, v2, v3);
}

template <typename Real>
Mathematics::TetrahedronQueryType Mathematics::Query3Rational<Real>::ToTetrahedron(const Vector3& testVector, int v0, int v1, int v2, int v3) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const QueryRational rational0{ testVector.GetX() };
    const QueryRational rational1{ testVector.GetY() };
    const QueryRational rational2{ testVector.GetZ() };

    const QueryRationalVector queryRationalVector{ rational0, rational1, rational2 };

    return ToTetrahedron(queryRationalVector, v0, v1, v2, v3);
}

template <typename Real>
Mathematics::TetrahedronQueryType Mathematics::Query3Rational<Real>::ToTetrahedron(const QueryRationalVector& rationalTest, int v0, int v1, int v2, int v3) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(0 <= v0 && v0 < this->GetNumVertices(), "��������");
    MATHEMATICS_ASSERTION_0(0 <= v1 && v1 < this->GetNumVertices(), "��������");
    MATHEMATICS_ASSERTION_0(0 <= v2 && v2 < this->GetNumVertices(), "��������");
    MATHEMATICS_ASSERTION_0(0 <= v3 && v3 < this->GetNumVertices(), "��������");

    const auto sign0 = ToPlane(rationalTest, v1, v2, v3);
    if (sign0 == PlaneQueryType::PositiveSide)
    {
        return TetrahedronQueryType::Outside;
    }

    const auto sign1 = ToPlane(rationalTest, v0, v2, v3);
    if (sign1 == PlaneQueryType::NegativeSide)
    {
        return TetrahedronQueryType::Outside;
    }

    const auto sign2 = ToPlane(rationalTest, v0, v1, v3);
    if (sign2 == PlaneQueryType::PositiveSide)
    {
        return TetrahedronQueryType::Outside;
    }

    const auto sign3 = ToPlane(rationalTest, v0, v1, v2);
    if (sign3 == PlaneQueryType::NegativeSide)
    {
        return TetrahedronQueryType::Outside;
    }

    if (sign0 == PlaneQueryType::OnPlane || sign1 == PlaneQueryType::OnPlane ||
        sign2 == PlaneQueryType::OnPlane || sign3 == PlaneQueryType::OnPlane)
    {
        return TetrahedronQueryType::OnTetrahedron;
    }
    else
    {
        return TetrahedronQueryType::Inside;
    }
}

template <typename Real>
Mathematics::CircumsphereQueryType Mathematics::Query3Rational<Real>::ToCircumsphere(int index, int v0, int v1, int v2, int v3) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ToCircumsphere(rationalVertices.at(index), v0, v1, v2, v3);
}

template <typename Real>
Mathematics::CircumsphereQueryType Mathematics::Query3Rational<Real>::ToCircumsphere(const Vector3& testVector, int v0, int v1, int v2, int v3) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const QueryRational rational0{ testVector.GetX() };
    const QueryRational rational1{ testVector.GetY() };
    const QueryRational rational2{ testVector.GetZ() };

    const QueryRationalVector queryRationalVector{ rational0, rational1, rational2 };

    return ToCircumsphere(queryRationalVector, v0, v1, v2, v3);
}

template <typename Real>
Mathematics::CircumsphereQueryType Mathematics::Query3Rational<Real>::ToCircumsphere(const QueryRationalVector& rationalTest, int v0, int v1, int v2, int v3) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto& vector0 = rationalVertices.at(v0);
    const auto& vector1 = rationalVertices.at(v1);
    const auto& vector2 = rationalVertices.at(v2);
    const auto& vector3 = rationalVertices.at(v3);

    const QueryRational s0x{ vector0.GetX() + rationalTest.GetX() };
    const QueryRational d0x{ vector0.GetX() - rationalTest.GetX() };
    const QueryRational s0y{ vector0.GetY() + rationalTest.GetY() };
    const QueryRational d0y{ vector0.GetY() - rationalTest.GetY() };
    const QueryRational s0z{ vector0.GetZ() + rationalTest.GetZ() };
    const QueryRational d0z{ vector0.GetZ() - rationalTest.GetZ() };
    const QueryRational s1x{ vector1.GetX() + rationalTest.GetX() };
    const QueryRational d1x{ vector1.GetX() - rationalTest.GetX() };
    const QueryRational s1y{ vector1.GetY() + rationalTest.GetY() };
    const QueryRational d1y{ vector1.GetY() - rationalTest.GetY() };
    const QueryRational s1z{ vector1.GetZ() + rationalTest.GetZ() };
    const QueryRational d1z{ vector1.GetZ() - rationalTest.GetZ() };
    const QueryRational s2x{ vector2.GetX() + rationalTest.GetX() };
    const QueryRational d2x{ vector2.GetX() - rationalTest.GetX() };
    const QueryRational s2y{ vector2.GetY() + rationalTest.GetY() };
    const QueryRational d2y{ vector2.GetY() - rationalTest.GetY() };
    const QueryRational s2z{ vector2.GetZ() + rationalTest.GetZ() };
    const QueryRational d2z{ vector2.GetZ() - rationalTest.GetZ() };
    const QueryRational s3x{ vector3.GetX() + rationalTest.GetX() };
    const QueryRational d3x{ vector3.GetX() - rationalTest.GetX() };
    const QueryRational s3y{ vector3.GetY() + rationalTest.GetY() };
    const QueryRational d3y{ vector3.GetY() - rationalTest.GetY() };
    const QueryRational s3z{ vector3.GetZ() + rationalTest.GetZ() };
    const QueryRational d3z{ vector3.GetZ() - rationalTest.GetZ() };
    const auto w0 = s0x * d0x + s0y * d0y + s0z * d0z;
    const auto w1 = s1x * d1x + s1y * d1y + s1z * d1z;
    const auto w2 = s2x * d2x + s2y * d2y + s2z * d2z;
    const auto w3 = s3x * d3x + s3y * d3y + s3z * d3z;

    const auto det = QueryDotTools<QueryRational>::Det4(d0x, d0y, d0z, w0, d1x, d1y, d1z, w1, d2x, d2y, d2z, w2, d3x, d3y, d3z, w3);

    if (QueryRational{} < det)
        return CircumsphereQueryType::Outside;
    else if (det < QueryRational{})
        return CircumsphereQueryType::Inside;
    else
        return CircumsphereQueryType::OnCircumsphere;
}

#endif  // MATHEMATICS_QUERY_QUERY3_RATIONAL_DETAIL_H

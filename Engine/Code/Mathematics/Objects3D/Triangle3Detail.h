///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 15:51)

#ifndef MATHEMATICS_OBJECTS_3D_TRIANGLE3_DETAIL_H
#define MATHEMATICS_OBJECTS_3D_TRIANGLE3_DETAIL_H

#include "Triangle3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Triangle3<Real>::Triangle3(const Vector3& vector0, const Vector3& vector1, const Vector3& vector2) noexcept
    : vertex{ vector0, vector1, vector2 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Triangle3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename Mathematics::Triangle3<Real>::ContainerType Mathematics::Triangle3<Real>::GetVertex() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ContainerType{ vertex.begin(), vertex.end() };
}

template <typename Real>
typename Mathematics::Triangle3<Real>::ContainerType Mathematics::Triangle3<Real>::GetEdgeVectors() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    ContainerType result{ vertex[1] - vertex[0], vertex[2] - vertex[1], vertex[0] - vertex[2] };

#include STSTEM_WARNING_POP

    return result;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Triangle3<Real>::GetNormal() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return Vector3Tools::UnitCrossProduct(vertex[1] - vertex[0], vertex[2] - vertex[1]);

#include STSTEM_WARNING_POP
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Triangle3<Real>::GetVertex(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return vertex.at(index);
}

template <typename Real>
Real Mathematics::Triangle3<Real>::DistanceTo(const Vector3& point) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    const auto diff = vertex[0] - point;
    const auto edge0 = vertex[1] - vertex[0];
    const auto edge1 = vertex[2] - vertex[0];

#include STSTEM_WARNING_POP

    const auto a00 = Vector3Tools::GetLengthSquared(edge0);
    const auto a01 = Vector3Tools::DotProduct(edge0, edge1);
    const auto a11 = Vector3Tools::GetLengthSquared(edge1);
    const auto b0 = Vector3Tools::DotProduct(diff, edge0);
    const auto b1 = Vector3Tools::DotProduct(diff, edge1);
    const auto c = Vector3Tools::GetLengthSquared(diff);
    const auto det = Math::FAbs(a00 * a11 - a01 * a01);
    auto s = a01 * b1 - a11 * b0;
    auto t = a01 * b0 - a00 * b1;
    auto sqrDistance = Math::GetValue(0);

    if (s + t <= det)
    {
        if (s < Math::GetValue(0))
        {
            if (t < Math::GetValue(0))  // ����4
            {
                if (b0 < Math::GetValue(0))
                {
                    if (a00 <= -b0)
                    {
                        sqrDistance = a00 + Math::GetValue(2) * b0 + c;
                    }
                    else
                    {
                        sqrDistance = c - b0 * b0 / a00;
                    }
                }
                else
                {
                    if (Math::GetValue(0) <= b1)
                    {
                        sqrDistance = c;
                    }
                    else if (a11 <= -b1)
                    {
                        sqrDistance = a11 + Math::GetValue(2) * b1 + c;
                    }
                    else
                    {
                        sqrDistance = c - b1 * b1 / a11;
                    }
                }
            }
            else  // ����3
            {
                if (Math::GetValue(0) <= b1)
                {
                    sqrDistance = c;
                }
                else if (a11 <= -b1)
                {
                    sqrDistance = a11 + Math::GetValue(2) * b1 + c;
                }
                else
                {
                    sqrDistance = c - b1 * b1 / a11;
                }
            }
        }
        else if (t < Math::GetValue(0))  // ����5
        {
            if (Math::GetValue(0) <= b0)
            {
                sqrDistance = c;
            }
            else if (a00 <= -b0)
            {
                sqrDistance = a00 + Math::GetValue(2) * b0 + c;
            }
            else
            {
                sqrDistance = b0 * s + c - b0 * b0 / a00;
            }
        }
        else  // ����0
        {
            // ��С���������ε��ڲ��㡣
            Real invDet = Math::GetValue(1) / det;
            s *= invDet;
            t *= invDet;
            sqrDistance = s * (a00 * s + a01 * t + Math::GetValue(2) * b0) +
                          t * (a01 * s + a11 * t + Math::GetValue(2) * b1) + c;
        }
    }
    else
    {
        if (s < Math::GetValue(0))  // ����2
        {
            auto tmp0 = a01 + b0;
            auto tmp1 = a11 + b1;
            if (tmp0 < tmp1)
            {
                auto numer = tmp1 - tmp0;
                auto denom = a00 - Math::GetValue(2) * a01 + a11;
                if (numer >= denom)
                {
                    sqrDistance = a00 + Math::GetValue(2) * b0 + c;
                }
                else
                {
                    s = numer / denom;
                    t = Math::GetValue(1) - s;
                    sqrDistance = s * (a00 * s + a01 * t + Math::GetValue(2) * b0) +
                                  t * (a01 * s + a11 * t + Math::GetValue(2) * b1) +
                                  c;
                }
            }
            else
            {
                if (tmp1 <= Math::GetValue(0))
                {
                    sqrDistance = a11 + Math::GetValue(2) * b1 + c;
                }
                else if (Math::GetValue(0) <= b1)
                {
                    sqrDistance = c;
                }
                else
                {
                    sqrDistance = c - b1 * b1 / a11;
                }
            }
        }
        else if (t < Math::GetValue(0))  // ���� 6
        {
            auto tmp0 = a01 + b1;
            auto tmp1 = a00 + b0;
            if (tmp0 < tmp1)
            {
                auto numer = tmp1 - tmp0;
                auto denom = a00 - Math::GetValue(2) * a01 + a11;
                if (denom <= numer)
                {
                    t = Math::GetValue(1);
                    s = Math::GetValue(0);
                    sqrDistance = a11 + Math::GetValue(2) * b1 + c;
                }
                else
                {
                    t = numer / denom;
                    s = Math::GetValue(1) - t;
                    sqrDistance = s * (a00 * s + a01 * t + Math::GetValue(2) * b0) +
                                  t * (a01 * s + a11 * t + Math::GetValue(2) * b1) +
                                  c;
                }
            }
            else
            {
                if (tmp1 <= Math::GetValue(0))
                {
                    sqrDistance = a00 + Math::GetValue(2) * b0 + c;
                }
                else if (Math::GetValue(0) <= b0)
                {
                    sqrDistance = c;
                }
                else
                {
                    sqrDistance = c - b0 * b0 / a00;
                }
            }
        }
        else  // ���� 1
        {
            auto numer = a11 + b1 - a01 - b0;
            if (numer <= Math::GetValue(0))
            {
                sqrDistance = a11 + Math::GetValue(2) * b1 + c;
            }
            else
            {
                auto denom = a00 - Math::GetValue(2) * a01 + a11;
                if (denom <= numer)
                {
                    sqrDistance = a00 + Math::GetValue(2) * b0 + c;
                }
                else
                {
                    s = numer / denom;
                    t = Math::GetValue(1) - s;
                    sqrDistance = s * (a00 * s + a01 * t + Math::GetValue(2) * b0) +
                                  t * (a01 * s + a11 * t + Math::GetValue(2) * b1) +
                                  c;
                }
            }
        }
    }

    return Math::Sqrt(Math::FAbs(sqrDistance));
}

template <typename Real>
Mathematics::Triangle3<Real> Mathematics::Triangle3<Real>::GetMove(Real t, const Vector3& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Triangle3{ GetVertex(0) + t * velocity, GetVertex(1) + t * velocity, GetVertex(2) + t * velocity };
}

#endif  // MATHEMATICS_OBJECTS_3D_TRIANGLE3_DETAIL_H

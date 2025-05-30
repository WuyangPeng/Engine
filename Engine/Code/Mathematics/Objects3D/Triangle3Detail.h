/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 10:29)

#ifndef MATHEMATICS_OBJECTS_3D_TRIANGLE3_DETAIL_H
#define MATHEMATICS_OBJECTS_3D_TRIANGLE3_DETAIL_H

#include "Triangle3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Triangle3<Real>::Triangle3(const Vector3Type& vector0, const Vector3Type& vector1, const Vector3Type& vector2) noexcept
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

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    ContainerType result{ vertex[1] - vertex[0], vertex[2] - vertex[1], vertex[0] - vertex[2] };

#include SYSTEM_WARNING_POP

    return result;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Triangle3<Real>::GetNormal() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return Vector3ToolsType::UnitCrossProduct(vertex[1] - vertex[0], vertex[2] - vertex[1]);

#include SYSTEM_WARNING_POP
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Triangle3<Real>::GetVertex(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return vertex.at(index);
}

template <typename Real>
Real Mathematics::Triangle3<Real>::DistanceTo(const Vector3Type& point) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    const auto diff = vertex[0] - point;
    const auto edge0 = vertex[1] - vertex[0];
    const auto edge1 = vertex[2] - vertex[0];

#include SYSTEM_WARNING_POP

    const auto a00 = Vector3ToolsType::GetLengthSquared(edge0);
    const auto a01 = Vector3ToolsType::DotProduct(edge0, edge1);
    const auto a11 = Vector3ToolsType::GetLengthSquared(edge1);
    const auto b0 = Vector3ToolsType::DotProduct(diff, edge0);
    const auto b1 = Vector3ToolsType::DotProduct(diff, edge1);
    const auto c = Vector3ToolsType::GetLengthSquared(diff);
    const auto det = MathType::FAbs(a00 * a11 - a01 * a01);
    auto s = a01 * b1 - a11 * b0;
    auto t = a01 * b0 - a00 * b1;
    auto sqrDistance = MathType::GetValue(0);

    if (s + t <= det)
    {
        if (s < MathType::GetValue(0))
        {
            if (t < MathType::GetValue(0))  // 区域4
            {
                if (b0 < MathType::GetValue(0))
                {
                    if (a00 <= -b0)
                    {
                        sqrDistance = a00 + MathType::GetValue(2) * b0 + c;
                    }
                    else
                    {
                        sqrDistance = c - b0 * b0 / a00;
                    }
                }
                else
                {
                    if (MathType::GetValue(0) <= b1)
                    {
                        sqrDistance = c;
                    }
                    else if (a11 <= -b1)
                    {
                        sqrDistance = a11 + MathType::GetValue(2) * b1 + c;
                    }
                    else
                    {
                        sqrDistance = c - b1 * b1 / a11;
                    }
                }
            }
            else  // 区域3
            {
                if (MathType::GetValue(0) <= b1)
                {
                    sqrDistance = c;
                }
                else if (a11 <= -b1)
                {
                    sqrDistance = a11 + MathType::GetValue(2) * b1 + c;
                }
                else
                {
                    sqrDistance = c - b1 * b1 / a11;
                }
            }
        }
        else if (t < MathType::GetValue(0))  // 区域5
        {
            if (MathType::GetValue(0) <= b0)
            {
                sqrDistance = c;
            }
            else if (a00 <= -b0)
            {
                sqrDistance = a00 + MathType::GetValue(2) * b0 + c;
            }
            else
            {
                sqrDistance = b0 * s + c - b0 * b0 / a00;
            }
        }
        else  // 区域0
        {
            // 最小是在三角形的内部点。
            Real invDet = MathType::GetValue(1) / det;
            s *= invDet;
            t *= invDet;
            sqrDistance = s * (a00 * s + a01 * t + MathType::GetValue(2) * b0) +
                          t * (a01 * s + a11 * t + MathType::GetValue(2) * b1) + c;
        }
    }
    else
    {
        if (s < MathType::GetValue(0))  // 区域2
        {
            auto tmp0 = a01 + b0;
            auto tmp1 = a11 + b1;
            if (tmp0 < tmp1)
            {
                auto numer = tmp1 - tmp0;
                auto denom = a00 - MathType::GetValue(2) * a01 + a11;
                if (numer >= denom)
                {
                    sqrDistance = a00 + MathType::GetValue(2) * b0 + c;
                }
                else
                {
                    s = numer / denom;
                    t = MathType::GetValue(1) - s;
                    sqrDistance = s * (a00 * s + a01 * t + MathType::GetValue(2) * b0) +
                                  t * (a01 * s + a11 * t + MathType::GetValue(2) * b1) +
                                  c;
                }
            }
            else
            {
                if (tmp1 <= MathType::GetValue(0))
                {
                    sqrDistance = a11 + MathType::GetValue(2) * b1 + c;
                }
                else if (MathType::GetValue(0) <= b1)
                {
                    sqrDistance = c;
                }
                else
                {
                    sqrDistance = c - b1 * b1 / a11;
                }
            }
        }
        else if (t < MathType::GetValue(0))  // 区域 6
        {
            auto tmp0 = a01 + b1;
            auto tmp1 = a00 + b0;
            if (tmp0 < tmp1)
            {
                auto numer = tmp1 - tmp0;
                auto denom = a00 - MathType::GetValue(2) * a01 + a11;
                if (denom <= numer)
                {
                    t = MathType::GetValue(1);
                    s = MathType::GetValue(0);
                    sqrDistance = a11 + MathType::GetValue(2) * b1 + c;
                }
                else
                {
                    t = numer / denom;
                    s = MathType::GetValue(1) - t;
                    sqrDistance = s * (a00 * s + a01 * t + MathType::GetValue(2) * b0) +
                                  t * (a01 * s + a11 * t + MathType::GetValue(2) * b1) +
                                  c;
                }
            }
            else
            {
                if (tmp1 <= MathType::GetValue(0))
                {
                    sqrDistance = a00 + MathType::GetValue(2) * b0 + c;
                }
                else if (MathType::GetValue(0) <= b0)
                {
                    sqrDistance = c;
                }
                else
                {
                    sqrDistance = c - b0 * b0 / a00;
                }
            }
        }
        else  // 区域 1
        {
            auto numer = a11 + b1 - a01 - b0;
            if (numer <= MathType::GetValue(0))
            {
                sqrDistance = a11 + MathType::GetValue(2) * b1 + c;
            }
            else
            {
                auto denom = a00 - MathType::GetValue(2) * a01 + a11;
                if (denom <= numer)
                {
                    sqrDistance = a00 + MathType::GetValue(2) * b0 + c;
                }
                else
                {
                    s = numer / denom;
                    t = MathType::GetValue(1) - s;
                    sqrDistance = s * (a00 * s + a01 * t + MathType::GetValue(2) * b0) +
                                  t * (a01 * s + a11 * t + MathType::GetValue(2) * b1) +
                                  c;
                }
            }
        }
    }

    return MathType::Sqrt(MathType::FAbs(sqrDistance));
}

template <typename Real>
Mathematics::Triangle3<Real> Mathematics::Triangle3<Real>::GetMove(Real t, const Vector3Type& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Triangle3{ GetVertex(0) + t * velocity, GetVertex(1) + t * velocity, GetVertex(2) + t * velocity };
}

#endif  // MATHEMATICS_OBJECTS_3D_TRIANGLE3_DETAIL_H

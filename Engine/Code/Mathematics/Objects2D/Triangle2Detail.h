/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 11:18)

#ifndef MATHEMATICS_OBJECTS_2D_TRIANGLE2_DETAIL_H
#define MATHEMATICS_OBJECTS_2D_TRIANGLE2_DETAIL_H

#include "Triangle2.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Triangle2<Real>::Triangle2(const Vector2& vector0, const Vector2& vector1, const Vector2& vector2) noexcept
    : vertex{ vector0, vector1, vector2 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Triangle2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename Mathematics::Triangle2<Real>::ContainerType Mathematics::Triangle2<Real>::GetVertex() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    ContainerType result{ vertex[0], vertex[1], vertex[2] };

#include SYSTEM_WARNING_POP

    return result;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::Triangle2<Real>::GetVertex(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return vertex.at(index);
}

template <typename Real>
Real Mathematics::Triangle2<Real>::DistanceTo(const Vector2& point) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    const auto diff = vertex[0] - point;
    const auto edge0 = vertex[1] - vertex[0];
    const auto edge1 = vertex[2] - vertex[0];

#include SYSTEM_WARNING_POP

    const auto a00 = Vector2Tools::GetLengthSquared(edge0);
    const auto a01 = Vector2Tools::DotProduct(edge0, edge1);
    const auto a11 = Vector2Tools::GetLengthSquared(edge1);
    const auto b0 = Vector2Tools::DotProduct(diff, edge0);
    const auto b1 = Vector2Tools::DotProduct(diff, edge1);
    const auto c = Vector2Tools::GetLengthSquared(diff);
    const auto det = Math::FAbs(a00 * a11 - a01 * a01);
    auto s = a01 * b1 - a11 * b0;
    auto t = a01 * b0 - a00 * b1;
    auto sqrDistance = Math::GetValue(0);

    if (s + t <= det)
    {
        if (s < Math::GetValue(0))
        {
            if (t < Math::GetValue(0))  // 区域4
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
            else  // 区域3
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
        else if (t < Math::GetValue(0))  // 区域5
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
        else  // 区域0
        {
            // 最小是在三角形的内部点。
            const auto invDet = Math::GetValue(1) / det;
            s *= invDet;
            t *= invDet;
            sqrDistance = s * (a00 * s + a01 * t + Math::GetValue(2) * b0) + t * (a01 * s + a11 * t + Math::GetValue(2) * b1) + c;
        }
    }
    else
    {
        if (s < Math::GetValue(0))  // 区域2
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
                    sqrDistance = s * (a00 * s + a01 * t + Math::GetValue(2) * b0) + t * (a01 * s + a11 * t + Math::GetValue(2) * b1) + c;
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
        else if (t < Math::GetValue(0))  // 区域 6
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
                    sqrDistance = s * (a00 * s + a01 * t + Math::GetValue(2) * b0) + t * (a01 * s + a11 * t + Math::GetValue(2) * b1) + c;
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
        else  // 区域 1
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
                    sqrDistance = s * (a00 * s + a01 * t + Math::GetValue(2) * b0) + t * (a01 * s + a11 * t + Math::GetValue(2) * b1) + c;
                }
            }
        }
    }

    return Math::Sqrt(Math::FAbs(sqrDistance));
}

#endif  // MATHEMATICS_OBJECTS_2D_TRIANGLE2_DETAIL_H

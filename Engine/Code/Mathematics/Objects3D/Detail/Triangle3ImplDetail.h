///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 16:41)

#ifndef MATHEMATICS_OBJECTS3D_TRIANGLE3_IMPL_DETAIL_H
#define MATHEMATICS_OBJECTS3D_TRIANGLE3_IMPL_DETAIL_H

#include "Triangle3Impl.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Triangle3Impl<Real>::Triangle3Impl(const Vector3D& vector0, const Vector3D& vector1, const Vector3D& vector2) noexcept
    : m_Vertex{ vector0, vector1, vector2 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Triangle3Impl<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const typename Mathematics::Triangle3Impl<Real>::ContainerType Mathematics::Triangle3Impl<Real>::GetVertex() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ContainerType{ m_Vertex.begin(), m_Vertex.end() };
}

template <typename Real>
const typename Mathematics::Triangle3Impl<Real>::ContainerType Mathematics::Triangle3Impl<Real>::GetEdgeVectors() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    ContainerType vertex{ m_Vertex[1] - m_Vertex[0], m_Vertex[2] - m_Vertex[1], m_Vertex[0] - m_Vertex[2] };
#include STSTEM_WARNING_POP

    return vertex;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Triangle3Impl<Real>::GetNormal() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    return Vector3DTools::UnitCrossProduct(m_Vertex[1] - m_Vertex[0], m_Vertex[2] - m_Vertex[1]);
#include STSTEM_WARNING_POP
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Triangle3Impl<Real>::GetVertex(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Vertex.at(index);
}

template <typename Real>
Real Mathematics::Triangle3Impl<Real>::DistanceTo(const Vector3D& point) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    auto diff = m_Vertex[0] - point;
    auto edge0 = m_Vertex[1] - m_Vertex[0];
    auto edge1 = m_Vertex[2] - m_Vertex[0];
#include STSTEM_WARNING_POP

    auto a00 = Vector3DTools::VectorMagnitudeSquared(edge0);
    auto a01 = Vector3DTools::DotProduct(edge0, edge1);
    auto a11 = Vector3DTools::VectorMagnitudeSquared(edge1);
    auto b0 = Vector3DTools::DotProduct(diff, edge0);
    auto b1 = Vector3DTools::DotProduct(diff, edge1);
    auto c = Vector3DTools::VectorMagnitudeSquared(diff);
    auto det = Math::FAbs(a00 * a11 - a01 * a01);
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
            Real invDet = Math::GetValue(1) / det;
            s *= invDet;
            t *= invDet;
            sqrDistance = s * (a00 * s + a01 * t + Math::GetValue(2) * b0) +
                          t * (a01 * s + a11 * t + Math::GetValue(2) * b1) + c;
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
                    sqrDistance = s * (a00 * s + a01 * t + Math::GetValue(2) * b0) +
                                  t * (a01 * s + a11 * t + Math::GetValue(2) * b1) +
                                  c;
                }
            }
        }
    }

    return Math::Sqrt(Math::FAbs(sqrDistance));
}

#endif  // MATHEMATICS_OBJECTS3D_TRIANGLE3_IMPL_DETAIL_H

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 15:49)

#ifndef MATHEMATICS_OBJECTS_3D_FRUSTUM3_ACHIEVE_H
#define MATHEMATICS_OBJECTS_3D_FRUSTUM3_ACHIEVE_H

#include "Frustum3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::Frustum3<Real>::Frustum3(const Vector3& origin,
                                      const Vector3& directionVector,
                                      const Vector3& upVector,
                                      const Vector3& rightVector,
                                      Real directionMin,
                                      Real directionMax,
                                      Real upBound,
                                      Real rightBound,
                                      Real epsilon) noexcept
    : origin{ origin },
      directionVector{ directionVector },
      upVector{ upVector },
      rightVector{ rightVector },
      directionMin{ directionMin },
      directionMax{ directionMax },
      upBound{ upBound },
      rightBound{ rightBound },
      directionRatio{ directionMax / directionMin },
      twoUF{ Math::GetValue(-2) * upBound * directionMax },
      twoRF{ Math::GetValue(-2) * rightBound * directionMax },
      epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Frustum3<Real>::IsValid() const noexcept
{
    try
    {
        if (directionVector.IsNormalize(epsilon) &&
            upVector.IsNormalize(epsilon) &&
            rightVector.IsNormalize(epsilon) &&
            Math::GetValue(0) < directionMin &&
            directionMin < directionMax &&
            Math::GetValue(0) < rightBound &&
            Math::GetValue(0) < upBound)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Frustum3<Real>::GetOrigin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return origin;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Frustum3<Real>::GetDirectionVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return directionVector;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Frustum3<Real>::GetUpVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return upVector;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Frustum3<Real>::GetRightVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rightVector;
}

template <typename Real>
Real Mathematics::Frustum3<Real>::GetDirectionMin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return directionMin;
}

template <typename Real>
Real Mathematics::Frustum3<Real>::GetDirectionMax() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return directionMax;
}

template <typename Real>
Real Mathematics::Frustum3<Real>::GetUpBound() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return upBound;
}

template <typename Real>
Real Mathematics::Frustum3<Real>::GetRightBound() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rightBound;
}

template <typename Real>
Real Mathematics::Frustum3<Real>::GetDirectionRatio() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return directionRatio;
}

template <typename Real>
Real Mathematics::Frustum3<Real>::GetMTwoUF() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return twoUF;
}

template <typename Real>
Real Mathematics::Frustum3<Real>::GetMTwoRF() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return twoRF;
}

template <typename Real>
typename Mathematics::Frustum3<Real>::VerticesType Mathematics::Frustum3<Real>::ComputeVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto directionScaled = directionMin * directionVector;
    const auto upScaled = upBound * upVector;
    const auto rightScaled = rightBound * rightVector;

    constexpr auto vertexSize = 8;

    VerticesType vertex(vertexSize);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    vertex[0] = directionScaled - upScaled - rightScaled;
    vertex[1] = directionScaled - upScaled + rightScaled;
    vertex[2] = directionScaled + upScaled + rightScaled;
    vertex[3] = directionScaled + upScaled - rightScaled;

    for (auto i = 0; i < vertexSize / 2; ++i)
    {
        const auto temp1 = directionRatio * vertex[i];
        const auto temp2 = origin + temp1;
        const auto temp = i + vertexSize / 2;
        vertex[temp] = temp2;
        vertex[i] += origin;
    }

#include SYSTEM_WARNING_POP

    return vertex;
}

template <typename Real>
Mathematics::Frustum3<Real> Mathematics::Frustum3<Real>::GetMove(Real t, const Vector3& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Frustum3{ GetOrigin() + t * velocity,
                     GetDirectionVector(),
                     GetUpVector(),
                     GetRightVector(),
                     GetDirectionMin(),
                     GetDirectionMax(),
                     GetUpBound(),
                     GetRightBound(),
                     epsilon };
}

// private
template <typename Real>
void Mathematics::Frustum3<Real>::Update() noexcept
{
    directionRatio = directionMax / directionMin;
    twoUF = Math::GetValue(-2) * upBound * directionMax;
    twoRF = Math::GetValue(-2) * rightBound * directionMax;
}

#endif  // MATHEMATICS_OBJECTS_3D_FRUSTUM3_ACHIEVE_H

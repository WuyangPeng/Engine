/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 10:38)

#ifndef MATHEMATICS_OBJECTS_3D_FRUSTUM3_ACHIEVE_H
#define MATHEMATICS_OBJECTS_3D_FRUSTUM3_ACHIEVE_H

#include "Frustum3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Frustum3<Real>::Frustum3() noexcept
    : origin{ Vector3Type::GetZero() },
      directionVector{ Vector3Type::GetUnitZ() },
      upVector{ Vector3Type::GetUnitY() },
      rightVector{ Vector3Type::GetUnitX() },
      directionMin{ MathType::GetValue(1) },
      directionMax{ MathType::GetValue(2) },
      upBound{ MathType::GetValue(1) },
      rightBound{ MathType::GetValue(1) },
      directionRatio{ directionMax / directionMin },
      twoUpF{ MathType::GetValue(-2) * upBound * directionMax },
      twoRightF{ MathType::GetValue(-2) * rightBound * directionMax },
      epsilon{ MathType::GetZeroTolerance() }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Frustum3<Real>::Frustum3(const Vector3Type& origin,
                                      const Vector3Type& directionVector,
                                      const Vector3Type& upVector,
                                      const Vector3Type& rightVector,
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
      twoUpF{ MathType::GetValue(-2) * upBound * directionMax },
      twoRightF{ MathType::GetValue(-2) * rightBound * directionMax },
      epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Frustum3<Real>::Frustum3(const AlgebraVector3& origin,
                                      const AlgebraVector3& directionVector,
                                      const AlgebraVector3& upVector,
                                      const AlgebraVector3& rightVector,
                                      Real directionMin,
                                      Real directionMax,
                                      Real upBound,
                                      Real rightBound,
                                      Real epsilon)
    : Frustum3{ Vector3Type{ origin }, Vector3Type{ directionVector }, Vector3Type{ upVector }, Vector3Type{ rightVector }, directionMin, directionMax, upBound, rightBound, epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Frustum3<Real>::IsValid() const noexcept
{
    try
    {
        if (directionVector.IsNormalize(epsilon) &&
            upVector.IsNormalize(epsilon) &&
            rightVector.IsNormalize(epsilon) &&
            MathType::GetValue(0) < directionMin &&
            directionMin < directionMax &&
            MathType::GetValue(0) < rightBound &&
            MathType::GetValue(0) < upBound)
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
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real> Mathematics::Frustum3<Real>::GetOrigin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return origin;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real> Mathematics::Frustum3<Real>::GetDirectionVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return directionVector;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real> Mathematics::Frustum3<Real>::GetUpVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return upVector;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real> Mathematics::Frustum3<Real>::GetRightVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rightVector;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Frustum3<Real>::GetDirectionMin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return directionMin;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Frustum3<Real>::GetDirectionMax() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return directionMax;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Frustum3<Real>::GetUpBound() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return upBound;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Frustum3<Real>::GetRightBound() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rightBound;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Frustum3<Real>::AlgebraVector3 Mathematics::Frustum3<Real>::GetAlgebraOrigin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return origin.GetVector();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Frustum3<Real>::AlgebraVector3 Mathematics::Frustum3<Real>::GetAlgebraDirectionVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return directionVector.GetVector();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Frustum3<Real>::AlgebraVector3 Mathematics::Frustum3<Real>::GetAlgebraUpVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return upVector.GetVector();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Frustum3<Real>::AlgebraVector3 Mathematics::Frustum3<Real>::GetAlgebraRightVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rightVector.GetVector();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Frustum3<Real>::GetDirectionRatio() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return directionRatio;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Frustum3<Real>::GetMTwoUpF() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return twoUpF;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Frustum3<Real>::GetMTwoRightF() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return twoRightF;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Frustum3<Real>::VerticesType Mathematics::Frustum3<Real>::ComputeVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto directionScaled = directionMin * directionVector;
    const auto upScaled = upBound * upVector;
    const auto rightScaled = rightBound * rightVector;

    VerticesType vertex(vertexSize);

    vertex.at(0) = directionScaled - upScaled - rightScaled;
    vertex.at(1) = directionScaled - upScaled + rightScaled;
    vertex.at(2) = directionScaled + upScaled + rightScaled;
    vertex.at(3) = directionScaled + upScaled - rightScaled;

    for (auto i = 0; i < vertexSize / 2; ++i)
    {
        const auto index = i + vertexSize / 2;
        vertex.at(index) = origin + directionRatio * vertex.at(i);
        vertex.at(i) += origin;
    }

    return vertex;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Frustum3<Real>::ArrayType Mathematics::Frustum3<Real>::ComputeVerticesToArray() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto directionScaled = directionMin * directionVector;
    const auto upScaled = upBound * upVector;
    const auto rightScaled = rightBound * rightVector;

    ArrayType vertex{};

    vertex.at(0) = directionScaled - upScaled - rightScaled;
    vertex.at(1) = directionScaled - upScaled + rightScaled;
    vertex.at(2) = directionScaled + upScaled + rightScaled;
    vertex.at(3) = directionScaled + upScaled - rightScaled;

    for (auto i = 0; i < vertexSize / 2; ++i)
    {
        const auto index = i + vertexSize / 2;
        vertex.at(index) = origin + directionRatio * vertex.at(i);
        vertex.at(i) += origin;
    }

    return vertex;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Frustum3<Real> Mathematics::Frustum3<Real>::GetMove(Real t, const Vector3Type& velocity) const
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

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Frustum3<Real>::SetOrigin(const Vector3Type& aOrigin) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    origin = aOrigin;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Frustum3<Real>::SetDirectionVector(const Vector3Type& aDirectionVector) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    directionVector = aDirectionVector;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Frustum3<Real>::SetUpVector(const Vector3Type& aUpVector) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    upVector = aUpVector;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Frustum3<Real>::SetRightVector(const Vector3Type& aRightVector) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    rightVector = aRightVector;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Frustum3<Real>::SetDirectionMin(Real aDirectionMin) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    directionMin = aDirectionMin;

    Update();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Frustum3<Real>::SetDirectionMax(Real aDirectionMax) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    directionMax = aDirectionMax;

    Update();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Frustum3<Real>::SetUpBound(Real aUpBound) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    upBound = aUpBound;

    Update();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Frustum3<Real>::SetRightBound(Real aRightBound) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    rightBound = aRightBound;

    Update();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Frustum3<Real>::SetOrigin(const AlgebraVector3& aOrigin)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    SetOrigin(Vector3Type{ aOrigin });
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Frustum3<Real>::SetDirectionVector(const AlgebraVector3& aDirectionVector)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    SetDirectionVector(Vector3Type{ aDirectionVector });
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Frustum3<Real>::SetUpVector(const AlgebraVector3& aUpVector)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    SetUpVector(Vector3Type{ aUpVector });
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Frustum3<Real>::SetRightVector(const AlgebraVector3& aRightVector)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    SetRightVector(Vector3Type{ aRightVector });
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Frustum3<Real>::Update() noexcept
{
    directionRatio = directionMax / directionMin;
    twoUpF = MathType::GetValue(-2) * upBound * directionMax;
    twoRightF = MathType::GetValue(-2) * rightBound * directionMax;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator==(const Frustum3<Real>& lhs, const Frustum3<Real>& rhs)
{
    return lhs.GetOrigin() == rhs.GetOrigin() &&
           lhs.GetDirectionVector() == rhs.GetDirectionVector() &&
           lhs.GetUpVector() == rhs.GetUpVector() &&
           lhs.GetRightVector() == rhs.GetRightVector() &&
           lhs.GetDirectionMin() == rhs.GetDirectionMin() &&
           lhs.GetDirectionMax() == rhs.GetDirectionMax() &&
           lhs.GetUpBound() == rhs.GetUpBound() &&
           lhs.GetRightBound() == rhs.GetRightBound();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator!=(const Frustum3<Real>& lhs, const Frustum3<Real>& rhs)
{
    return !(lhs == rhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator<(const Frustum3<Real>& lhs, const Frustum3<Real>& rhs)
{
    if (lhs.GetOrigin() < rhs.GetOrigin())
    {
        return true;
    }

    if (rhs.GetOrigin() < lhs.GetOrigin())
    {
        return false;
    }

    if (lhs.GetDirectionVector() < rhs.GetDirectionVector())
    {
        return true;
    }

    if (rhs.GetDirectionVector() < lhs.GetDirectionVector())
    {
        return false;
    }

    if (lhs.GetUpVector() < rhs.GetUpVector())
    {
        return true;
    }

    if (rhs.GetUpVector() < lhs.GetUpVector())
    {
        return false;
    }

    if (lhs.GetRightVector() < rhs.GetRightVector())
    {
        return true;
    }

    if (rhs.GetRightVector() < lhs.GetRightVector())
    {
        return false;
    }

    if (lhs.GetDirectionMin() < rhs.GetDirectionMin())
    {
        return true;
    }

    if (rhs.GetDirectionMin() < lhs.GetDirectionMin())
    {
        return false;
    }

    if (lhs.GetDirectionMax() < rhs.GetDirectionMax())
    {
        return true;
    }

    if (rhs.GetDirectionMax() < lhs.GetDirectionMax())
    {
        return false;
    }

    if (lhs.GetUpBound() < rhs.GetUpBound())
    {
        return true;
    }

    if (rhs.GetUpBound() < lhs.GetUpBound())
    {
        return false;
    }

    return lhs.GetRightBound() < rhs.GetRightBound();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator<=(const Frustum3<Real>& lhs, const Frustum3<Real>& rhs)
{
    return !(rhs < lhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator>(const Frustum3<Real>& lhs, const Frustum3<Real>& rhs)
{
    return rhs < lhs;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator>=(const Frustum3<Real>& lhs, const Frustum3<Real>& rhs)
{
    return !(lhs < rhs);
}

#endif  // MATHEMATICS_OBJECTS_3D_FRUSTUM3_ACHIEVE_H

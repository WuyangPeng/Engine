///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/07 11:20)

#ifndef MATHEMATICS_ALGEBRA_A_VECTOR_DETAIL_H
#define MATHEMATICS_ALGEBRA_A_VECTOR_DETAIL_H

#include "AVector.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_AVECTOR_ACHIEVE)

    #include "AVectorAchieve.h"

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_AVECTOR_ACHIEVE)

#include "AVectorOrthonormalBasisDetail.h"
#include "AVectorOrthonormalizeDetail.h"
#include "Vector3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename T>
bool Mathematics::Approximate(const AVector<T>& lhs, const AVector<T>& rhs, const T epsilon) noexcept
{
    return Math<T>::FAbs(lhs.GetX() - rhs.GetX()) <= epsilon &&
           Math<T>::FAbs(lhs.GetY() - rhs.GetY()) <= epsilon &&
           Math<T>::FAbs(lhs.GetZ() - rhs.GetZ()) <= epsilon;
}

template <typename T>
T Mathematics::Dot(const AVector<T>& lhs, const AVector<T>& rhs) noexcept
{
    return lhs.GetX() * rhs.GetX() + lhs.GetY() * rhs.GetY() + lhs.GetZ() * rhs.GetZ();
}

template <typename T>
const Mathematics::AVector<T> Mathematics::Cross(const AVector<T>& lhs, const AVector<T>& rhs) noexcept
{
    return AVector<T>{ lhs.GetY() * rhs.GetZ() - lhs.GetZ() * rhs.GetY(), lhs.GetZ() * rhs.GetX() - lhs.GetX() * rhs.GetZ(), lhs.GetX() * rhs.GetY() - lhs.GetY() * rhs.GetX() };
}

template <typename T>
const Mathematics::AVector<T> Mathematics::UnitCross(const AVector<T>& lhs, const AVector<T>& rhs, const T epsilon)
{
    auto cross = Cross(lhs, rhs);

    cross.Normalize(epsilon);

    return cross;
}

template <typename T>
const Mathematics::AVectorOrthonormalize<T> Mathematics::Orthonormalize(const AVector<T>& uVector, const AVector<T>& vVector, const AVector<T>& wVector, const T epsilon)
{
    /// 如果输入向量v0、v1和v2，则Gram-Schmidt正交向量产生矢量u0、u1和u2如下，
    ///   u0 = v0 / |v0|
    ///   u1 = (v1 - (u0 * v1)u0) / |v1 - (u0 * v1)u0|
    ///   u2 = (v2 - (u0 * v2)u0 - (u1 * v2)u1) / |v2 - (u0 * v2)u0 - (u1 * v2)u1|
    ///
    /// 其中|A|表示向量A的长度和A * B表示向量A和B的点积

    return AVectorOrthonormalize<T>{ uVector, vVector, wVector, epsilon };
}

template <typename T>
const Mathematics::AVectorOrthonormalize<T> Mathematics::Orthonormalize(const std::vector<AVector<T>>& vectors, const T epsilon)
{
    MATHEMATICS_ASSERTION_1(vectors.size() == 3, "vectors的大小错误！");

    return AVectorOrthonormalize<T>{ vectors, epsilon };
}

template <typename T>
const Mathematics::AVectorOrthonormalBasis<T> Mathematics::GenerateOrthonormalBasis(const AVector<T>& nonzeroVector, const T epsilon)
{
    MATHEMATICS_ASSERTION_1(!nonzeroVector.IsZero(epsilon), "输入必须是非零向量！");

    return AVectorOrthonormalBasis<T>(nonzeroVector, false, epsilon);
}

template <typename T>
const Mathematics::AVectorOrthonormalBasis<T> Mathematics::GenerateComplementBasis(const AVector<T>& unitVector, const T epsilon)
{
    MATHEMATICS_ASSERTION_3(unitVector.IsNormalize(epsilon), "输入必须是单位向量！");

    return AVectorOrthonormalBasis<T>(unitVector, true, epsilon);
}

template <typename T>
std::ostream& Mathematics::operator<<(std::ostream& outFile, const AVector<T>& vector)
{
    outFile << vector.GetX() << "　" << vector.GetY() << "　" << vector.GetZ();

    return outFile;
}

#endif  // MATHEMATICS_ALGEBRA_A_VECTOR_DETAIL_H

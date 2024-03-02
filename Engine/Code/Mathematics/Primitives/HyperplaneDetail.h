///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/27 09:24)

#ifndef MATHEMATICS_PRIMITIVES_HYPERPLANE_DETAIL_H
#define MATHEMATICS_PRIMITIVES_HYPERPLANE_DETAIL_H

#include "Hyperplane.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix/MatrixDetail.h"
#include "Mathematics/Algebra/Vector/Vector3Detail.h"
#include "Mathematics/Algebra/Vector/VectorDetail.h"
#include "Mathematics/NumericalAnalysis/Algebra/SingularValueDecompositionDetail.h"

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Hyperplane<N, Real>::Hyperplane() noexcept requires(N == 3)
    : normal{ Real{}, Real{}, Math::GetValue(1) },
      origin{},
      constant{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Hyperplane<N, Real>::Hyperplane() noexcept requires(N == 4)
    : normal{ Real{}, Real{}, Real{}, Math::GetValue(1) },
      origin{},
      constant{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Hyperplane<N, Real>::Hyperplane(const Vector& normal, Real constant)
    : normal{ normal },
      origin{ constant * normal },
      constant{ constant }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Hyperplane<N, Real>::Hyperplane(const Vector& normal, const Vector& origin)
    : normal{ normal },
      origin{ origin },
      constant{ Dot(normal, origin) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Hyperplane<N, Real>::Hyperplane(const PointType& p)
    : normal{},
      origin{},
      constant{}
{
    ComputeFromPoints(p);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Hyperplane<N, Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
typename Mathematics::Hyperplane<N, Real>::Vector Mathematics::Hyperplane<N, Real>::GetNormal() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return normal;
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
void Mathematics::Hyperplane<N, Real>::SetNormal(const Vector& aNormal) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    normal = aNormal;
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
typename Mathematics::Hyperplane<N, Real>::Vector Mathematics::Hyperplane<N, Real>::GetOrigin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return origin;
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
void Mathematics::Hyperplane<N, Real>::SetOrigin(const Vector& aOrigin) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    origin = aOrigin;
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Real Mathematics::Hyperplane<N, Real>::GetConstant() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return constant;
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
void Mathematics::Hyperplane<N, Real>::SetConstant(Real aConstant) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    constant = aConstant;
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
void Mathematics::Hyperplane<N, Real>::ComputeFromPoints(const PointType& p) requires(N != 3)
{
    Algebra::Matrix<N, N - 1, Real> edge{};
    for (auto i0 = 0, i1 = 1; i1 < N; i0 = i1++)
    {
        edge.SetCol(i0, p[i1] - p[0]);
    }

    /// 计算由点p[]形成的单纯形的边的一维正交补。
    Algebra::SingularValueDecomposition<Real> svd{ N, N - 1, 32 };
    svd.Solve(edge, -1);
    normal[0] = svd.GetUColumn(N - 1);

    constant = Dot(normal, p[0]);
    origin = constant * normal;
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
void Mathematics::Hyperplane<N, Real>::ComputeFromPoints(const PointType& p) requires(N == 3)
{
    const auto edge0 = p.at(1) - p.at(0);
    const auto edge1 = p.at(2) - p.at(0);
    normal = UnitCross(edge0, edge1);
    constant = Dot(normal, p.at(0));
    origin = constant * normal;
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator==(const Hyperplane<N, Real>& lhs, const Hyperplane<N, Real>& rhs)
{
    return lhs.GetNormal() == rhs.GetNormal() && lhs.GetOrigin() == rhs.GetOrigin() && lhs.GetConstant() == rhs.GetConstant();
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator!=(const Hyperplane<N, Real>& lhs, const Hyperplane<N, Real>& rhs)
{
    return !(lhs == rhs);
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator<(const Hyperplane<N, Real>& lhs, const Hyperplane<N, Real>& rhs)
{
    if (lhs.GetNormal() < rhs.GetNormal())
    {
        return true;
    }

    if (rhs.GetNormal() < lhs.GetNormal())
    {
        return false;
    }

    if (lhs.GetOrigin() < rhs.GetOrigin())
    {
        return true;
    }

    if (rhs.GetOrigin() < lhs.GetOrigin())
    {
        return false;
    }

    return lhs.GetConstant() < rhs.GetConstant();
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator<=(const Hyperplane<N, Real>& lhs, const Hyperplane<N, Real>& rhs)
{
    return !(rhs < lhs);
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator>(const Hyperplane<N, Real>& lhs, const Hyperplane<N, Real>& rhs)
{
    return rhs < lhs;
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator>=(const Hyperplane<N, Real>& lhs, const Hyperplane<N, Real>& rhs)
{
    return !(lhs < rhs);
}

#endif  // MATHEMATICS_PRIMITIVES_HYPERPLANE_DETAIL_H

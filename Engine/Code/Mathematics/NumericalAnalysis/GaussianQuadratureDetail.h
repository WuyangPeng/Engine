///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 16:47)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_GAUSSIAN_QUADRATURE_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_GAUSSIAN_QUADRATURE_DETAIL_H

#include "GaussianQuadrature.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, typename UserDataType>
Mathematics::GaussianQuadrature<Real, UserDataType>::GaussianQuadrature(Real begin, Real end, Function function, const UserDataType* userData) noexcept
    : radius{ Math::GetRational(1, 2) * (end - begin) },
      center{ Math::GetRational(1, 2) * (end + begin) },
      function{ function },
      userData{ userData },
      result{}
{
    Calculate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real, typename UserDataType>
void Mathematics::GaussianQuadrature<Real, UserDataType>::Calculate() noexcept
{
    // Legendre ����ʽ��
    // P_0(x) = 1
    // P_1(x) = x
    // P_2(x) = (3x^2 - 1) / 2
    // P_3(x) = x(5x^2 - 3) / 2
    // P_4(x) = (35x^4 - 30x^2 + 3) / 8
    // P_5(x) = x(63x^4 - 70x^2 + 15) / 8

    // ���ɶ���ʽ��
    //   d / dx[ (1-x^2) dP_n(x) / dx ] + n(n+1) P_n(x) = 0
    //   P_n(x) = sum_{k=0}^{floor(n / 2)} c_k x^{n - 2k}
    //     c_k = (-1)^k (2n - 2k)! / [ 2^n k! (n - k)! (n - 2k)! ]
    //   P_n(x) = ((-1)^n / (2^n n!)) d^n / dx^n[ (1 - x^2)^n ]
    //   (n + 1)P_{n + 1}(x) = (2n + 1) x P_n(x) - n P_{n - 1}(x)
    //   (1 - x^2) dP_n(x) / dx = -n x P_n(x) + n P_{n - 1}(x)

    // ָ������Legendre����ʽ�ĸ���
    constexpr auto degree = 5;
    constexpr std::array<Real, degree> root{ static_cast<Real>(-0.9061798459),
                                             static_cast<Real>(-0.5384693101),
                                             static_cast<Real>(0.0),
                                             static_cast<Real>(+0.5384693101),
                                             static_cast<Real>(+0.9061798459) };
    constexpr std::array<Real, degree> coeff{ static_cast<Real>(0.2369268850),
                                              static_cast<Real>(0.4786286705),
                                              static_cast<Real>(0.5688888889),
                                              static_cast<Real>(0.4786286705),
                                              static_cast<Real>(0.2369268850) };

    // ��Ҫ�任��[begin,end]Ϊ[-1,1]��
    // ���begin <= x <= end��-1 <= t <= 1,
    // Ȼ��x = ((end - begin) * t + (end + begin)) / 2��
    for (auto i = 0; i < degree; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

        result += coeff[i] * function(radius * root[i] + center, userData);

#include STSTEM_WARNING_POP
    }

    result *= radius;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
bool Mathematics::GaussianQuadrature<Real, UserDataType>::IsValid() const noexcept
{
    if (function != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
Real Mathematics::GaussianQuadrature<Real, UserDataType>::GetResult() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return result;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_GAUSSIAN_QUADRATURE_DETAIL_H

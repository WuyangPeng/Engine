///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 14:27)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Polynomial.h"

#include <vector>

namespace Mathematics
{
    // ��Ʒ��(x[i],w[i])Ϊ0 <= i < S��
    // �뵽w����Ϊx�ĺ�������ʾ w = f(x)��
    // �������Ϊά��Ϊd�Ķ���ʽ����Ʒ�У�w = sum_{i=0}^d c[i] * x^i
    // �÷�������С��������㷨�����ص�����洢ϵ��c[i]��0 <= i <= d��
    //
    // ���档����㷨����ʽ��
    //   (1,x,x^2,...,x^d)
    // ��֪�Ƕ��ڴ��ά�Ⱥʹ�ķ�ֵ�����Ƿǽ�׳��һ�����������ʹ����������ʽ
    //   (f[0](x),...,f[d](x))
    // ����С�����㷨��������Щ����һ�ַ����Ǹı�
    //   (x',w') = ((x-xcen)/rng, w/rng)
    // ���� xmin = min(x[i]), xmax = max(x[i]), xcen = (xmin+xmax)/2, ��
    // rng = xmax-xmin.  ��� (x',w') ��,
    //   w' = sum_{i=0}^d c'[i]*(x')^i.
    // ԭʼ����ʽ����ֵΪ
    //   w = rng * sum_{i=0}^d c'[i] * ((x-xcen) / rng)^i
    template <typename Real>
    class PolynomialFit2 final
    {
    public:
        using ClassType = PolynomialFit2<Real>;

        using Samples = std::vector<Real>;
        using Polynomial = Polynomial<Real>;
        using MathType = Math<Real>;

    public:
        PolynomialFit2(const Samples& xSamples, const Samples& wSamples, int degree);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Polynomial GetCoeff() const;
        NODISCARD bool IsSolveSucceed() const noexcept;

    private:
        void Calculate(const Samples& xSamples, const Samples& wSamples);

    private:
        Polynomial coeff;
        bool solveSucceed;
    };

    using PolynomialFit2F = PolynomialFit2<float>;
    using PolynomialFit2D = PolynomialFit2<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_H

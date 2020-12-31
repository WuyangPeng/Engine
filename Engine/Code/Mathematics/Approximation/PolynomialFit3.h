///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/04 13:35)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Polynomial.h"

#include <vector>

namespace Mathematics
{
    // ��Ʒ�� (x[i],y[i],w[i]) Ϊ0 <= i < S��
    // �뵽w����Ϊx��y�ĺ�������ʾ w = f(x,y)��
    // �������Ϊxά��Ϊd0��yά��Ϊd1�Ķ���ʽ����Ʒ�У� w = sum_{i=0}^{d0} sum_{j=0}^{d1} c[i][j]*x^i*y^j
    // �÷�������С��������㷨�����ص������д洢�� c[i][j] ��ֵ��
    // ���ݷ��صĵ� (d0 + 1) * (d1 + 1)��ϵ����

    // ���档����㷨����ʽ��
    //   (1,x,x^2,...,x^d0), (1,y,y^2,...,y^d1)
    // ��֪�Ƕ��ڴ��ά�Ⱥʹ�ķ�ֵ�����Ƿǽ�׳��һ�����������ʹ����������ʽ
    //   (f[0](x),...,f[d0](x)), (g[0](y),...,g[d1](y))
    // ����С�����㷨��������Щ����һ�ַ����Ǹı�
    //   (x',y',w') = ((x-xcen)/rng, (y-ycen)/rng, w/rng)
    // ���� xmin = min(x[i]), xmax = max(x[i]), xcen = (xmin+xmax)/2,
    // ymin = min(y[i]), ymax = max(y[i]), ycen = (ymin+ymax)/2, ��
    // rng = max(xmax-xmin,ymax-ymin).
    // ���(x',y',w') ��,
    //   w' = sum_{i=0}^{d0} sum_{j=0}^{d1} c'[i][j]*(x')^i*(y')^j
    // ԭʼ����ʽ����ֵΪ
    //   w = rng * sum_{i=0}^{d0} sum_{j=0}^{d1} c'[i][j] *
    //         ((x-xcen)/rng)^i * ((y-ycen)/rng)^j

    template <typename Real>
    class PolynomialFit3Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<PolynomialFit3Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<PolynomialFit3Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<PolynomialFit3Impl<Real>>;

    template <typename Real>
    class PolynomialFit3 final
    {
    public:
        using PolynomialFit3Impl = PolynomialFit3Impl<Real>;
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(PolynomialFit3);

        using ClassType = PolynomialFit3<Real>;
        using Samples = std::vector<Real>;
        using Polynomial = Polynomial<Real>;

    public:
        PolynomialFit3(const Samples& xSamples, const Samples& ySamples, const Samples& wSamples, size_t xDegree, size_t yDegree);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Samples GetCoeff() const;
        [[nodiscard]] bool IsSolveSucceed() const noexcept;

    private:
        IMPL_TYPE_DECLARE(PolynomialFit3);
    };

    using FloatPolynomialFit3 = PolynomialFit3<float>;
    using DoublePolynomialFit3 = PolynomialFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_H

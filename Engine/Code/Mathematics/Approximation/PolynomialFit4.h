///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/18 16:49)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT4_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT4_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Polynomial.h"

#include <vector>

namespace Mathematics
{
    // ��Ʒ��  (x[i],y[i],z[i],w[i])Ϊ0 <= i < S��
    // �뵽w����Ϊx��y��z�ĺ�������ʾ w = f(x,y,z)��
    // �������Ϊxά��Ϊd0��yά��Ϊd1,zά��Ϊd2�Ķ���ʽ����Ʒ�У�
    // w = sum_{i=0}^{d0} sum_{j=0}^{d1} sum_{k=0}^{d2} c[i][j][k]*x^i*y^j*z^k
    // �÷�������С��������㷨�����ص������д洢��  c[i][j][k] ��ֵ��
    // ���ݷ��صĵ� (d0+1) * (d1+1) * (d2+1)��ϵ����

    // ���档����㷨����ʽ��
    //   (1,x,x^2,...,x^d0), (1,y,y^2,...,y^d1), (1,z,z^2,...,z^d2)
    // ��֪�Ƕ��ڴ��ά�Ⱥʹ�ķ�ֵ�����Ƿǽ�׳��һ�����������ʹ����������ʽ
    //   (f[0](x),...,f[d0](x)), (g[0](y),...,g[d1](y)), (h[0](z),...,h[d2](z))
    // ����С�����㷨��������Щ����һ�ַ����Ǹı�
    //   (x',y',z',w') = ((x-xcen)/rng, (y-ycen)/rng, (z-zcen)/rng, w/rng)
    // ���� xmin = min(x[i]), xmax = max(x[i]), xcen = (xmin+xmax)/2,
    // ymin = min(y[i]), ymax = max(y[i]), ycen = (ymin+ymax)/2, zmin = min(z[i]),
    // zmax = max(z[i]), zcen = (zmin+zmax)/2, ��
    // rng = max(xmax-xmin,ymax-ymin,zmax-zmin).  ��� (x',y',z',w') ��,
    //   w' = sum_{i=0}^{d0} sum_{j=0}^{d1} sum_{k=0}^{d2} c'[i][j][k] *
    //          (x')^i*(y')^j*(z')^k
    // ԭʼ����ʽ����ֵΪ
    //   w = rng * sum_{i=0}^{d0} sum_{j=0}^{d1} sum_{k=0}^{d2} c'[i][j][k] *
    //         ((x-xcen)/rng)^i * ((y-ycen)/rng)^j * ((z-zcen)/rng)^k

    template <typename Real>
    class PolynomialFit4 final
    {
    public:
        using ClassType = PolynomialFit4<Real>;
        using Samples = std::vector<Real>;
        using Polynomial = Polynomial<Real>;
        using Math = Math<Real>;

    public:
        PolynomialFit4(const Samples& xSamples,
                       const Samples& ySamples,
                       const Samples& zSamples,
                       const Samples& wSamples,
                       size_t xDegree,
                       size_t yDegree,
                       size_t zDegree);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Samples GetCoeff() const;
        NODISCARD bool IsSolveSucceed() const noexcept;

    private:
        void Calculate(const Samples& xSamples,
                       const Samples& ySamples,
                       const Samples& zSamples,
                       const Samples& wSamples,
                       int xDegree,
                       int yDegree,
                       int zDegree);

    private:
        Samples coeff;
        bool solveSucceed;
    };

    using PolynomialFit4F = PolynomialFit4<float>;
    using PolynomialFit4D = PolynomialFit4<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT4_H

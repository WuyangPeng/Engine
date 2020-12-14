///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/04 15:17)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_POWERS_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_POWERS_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/DataTypes/Tuple.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <memory>
#include <vector>

namespace Mathematics
{
    // ��������ʽ�Ķ���ʽ�������
    //     w = sum_{i=0}^{n-1} c[i]*x^{p[i]}*y^{q[i]}
    // ����<p[i],q[i]> �ɵ������ṩ��ͬ�ķǸ����ݡ�
    // ��ʹ����С��������㷨��
    // ����������(x,y,w) ���ȱ�ӳ�䵽[-1,1]^3  ����ֵ³���ԡ�

    template <typename Real>
    class PolynomialFit3PowersImpl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<PolynomialFit3PowersImpl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<PolynomialFit3PowersImpl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<PolynomialFit3PowersImpl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE PolynomialFit3Powers final
    {
    public:
        using PolynomialFit3PowersImpl = PolynomialFit3PowersImpl<Real>;
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(PolynomialFit3Powers);

        using Samples = std::vector<Real>;
        using Tuple = CoreTools::Tuple<2, int>;
        using Powers = std::vector<Tuple>;

    public:
        // ���캯��������(x[i],y[i],w[i])���ֱ�Ϊ0 <= i < numSamples��
        // ��isRepackage Ϊtrueʱ�����캯��������(x[i],y[j],w[k])��
        // ���У�0 <= i < numXSamples, 0 <= j < numYSamples,�� k = i + numXSamples * j
        PolynomialFit3Powers(const Samples& xSamples, const Samples& ySamples, const Samples& wSamples, const Powers& powers, bool isRepackage = false);

        CLASS_INVARIANT_DECLARE;

        // ����һ�������࣬��������Է�����ɹ��򷵻ء�true����
        // ������ɹ��������ʽ��ֵ����Ч�ģ����Ƿ���false��
        [[nodiscard]] bool IsSolveSucceed() const noexcept;

        [[nodiscard]] Real GetXMin() const;
        [[nodiscard]] Real GetXMax() const;
        [[nodiscard]] Real GetYMin() const;
        [[nodiscard]] Real GetYMax() const;
        [[nodiscard]] Real GetWMin() const;
        [[nodiscard]] Real GetWMax() const;

        // ��϶���ʽ�ĵ�������
        // �����������д��ʵ�֣���Ч���������йش��ݸ����캯���ľ����ݵ�֪ʶ��
        [[nodiscard]] Real operator()(Real x, Real y) const;

    private:
        IMPL_TYPE_DECLARE(PolynomialFit3Powers);
    };

    using FloatPolynomialFit3Powers = PolynomialFit3Powers<float>;
    using DoublePolynomialFit3Powers = PolynomialFit3Powers<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_POWERS_H

///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/04 14:40)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <memory>
#include <vector>

namespace Mathematics
{
    // ��������ʽ�Ķ���ʽ�������
    //     w = sum_{i=0}^{n-1} c[i]*x^{p[i]}
    // ����p[i] �ɵ������ṩ��ͬ�ķǸ����ݡ�
    // ��ʹ����С��������㷨��
    // ����������(x,w) ���ȱ�ӳ�䵽[-1,1]^2 ����ֵ³���ԡ�

    template <typename Real>
    class PolynomialFit2PowersImpl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<PolynomialFit2PowersImpl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<PolynomialFit2PowersImpl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<PolynomialFit2PowersImpl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE PolynomialFit2Powers final
    {
    public:
        using PolynomialFit2PowersImpl = PolynomialFit2PowersImpl<Real>;
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(PolynomialFit2Powers);

        using Samples = std::vector<Real>;
        using Powers = std::vector<int>;

    public:
        // ���캯��������(x[i],w[i])���ֱ�Ϊ0 <= i < numSamples��
        PolynomialFit2Powers(const Samples& xSamples, const Samples& wSamples, const Powers& powers);

        CLASS_INVARIANT_DECLARE;

        // ����һ�������࣬��������Է�����ɹ��򷵻ء�true����
        // ������ɹ��������ʽ��ֵ����Ч�ģ����Ƿ���false��
        [[nodiscard]] bool IsSolveSucceed() const noexcept;

        [[nodiscard]] Real GetXMin() const;
        [[nodiscard]] Real GetXMax() const;
        [[nodiscard]] Real GetWMin() const;
        [[nodiscard]] Real GetWMax() const;

        // ��϶���ʽ�ĵ�������
        // �����������д��ʵ�֣���Ч���������йش��ݸ����캯���ľ����ݵ�֪ʶ��
        [[nodiscard]] Real operator()(Real x) const;

    private:
        IMPL_TYPE_DECLARE(PolynomialFit2Powers);
    };

    using FloatPolynomialFit2Powers = PolynomialFit2Powers<float>;
    using DoublePolynomialFit2Powers = PolynomialFit2Powers<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_H

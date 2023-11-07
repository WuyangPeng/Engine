///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 14:27)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_H

#include "Mathematics/MathematicsDll.h"

#include "PolynomialFitPowersData.h"

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
    class PolynomialFit2Powers final
    {
    public:
        using ClassType = PolynomialFit2Powers<Real>;

        using Samples = std::vector<Real>;
        using Powers = std::vector<int>;
        using Math = Math<Real>;

    public:
        // ���캯��������(x[i],w[i])���ֱ�Ϊ0 <= i < numSamples��
        PolynomialFit2Powers(const Samples& xSamples, const Samples& wSamples, const Powers& powers);

        CLASS_INVARIANT_DECLARE;

        // ����һ�������࣬��������Է�����ɹ��򷵻ء�true����
        // ������ɹ��������ʽ��ֵ����Ч�ģ����Ƿ���false��
        NODISCARD bool IsSolveSucceed() const noexcept;

        NODISCARD Real GetXMin() const;
        NODISCARD Real GetXMax() const;
        NODISCARD Real GetWMin() const;
        NODISCARD Real GetWMax() const;

        // ��϶���ʽ�ĵ�������
        // �����������д��ʵ�֣���Ч���������йش��ݸ����캯���ľ����ݵ�֪ʶ��
        NODISCARD Real operator()(Real x) const;

    private:
        // ֧�ֹ���
        void Init(const Samples& xSamples, const Samples& wSamples);
        void InitializePowers();
        void TransformToUnit(const Samples& xSourceSamples, const Samples& wSourceSamples, Samples& xTargetSamples, Samples& wTargetSamples);
        void TransformToUnit(const Samples& sourceSamples, Samples& targetSamples, int index);
        void DoLeastSquaresFit(const Samples& xTargetSamples, const Samples& wTargetSamples);

    private:
        // ���Ƶ�������ϵĶ���ʽ������ʹ�á�
        Powers powers;

        PolynomialFitPowersData<Real, 2> powersData;
    };

    using PolynomialFit2PowersF = PolynomialFit2Powers<float>;
    using PolynomialFit2PowersD = PolynomialFit2Powers<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_H

///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/04 14:09)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_IMPL_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "PolynomialFitPowersData.h"

#include <vector>

namespace Mathematics
{
    // ��������ʽ�Ķ���ʽ�������
    //     w = sum_{i=0}^{n-1} c[i]*x^{p[i]}
    // ����p[i] �ɵ������ṩ��ͬ�ķǸ����ݡ�
    // ��ʹ����С��������㷨��
    // ����������(x,w) ���ȱ�ӳ�䵽[-1,1]^2 ����ֵ³���ԡ�
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE PolynomialFit2PowersImpl final
    {
    public:
        using ClassType = PolynomialFit2PowersImpl<Real>;
        using Samples = std::vector<Real>;
        using Powers = std::vector<int>;
        using Math = Math<Real>;

    public:
        // ���캯��������(x[i],w[i])���ֱ�Ϊ0 <= i < numSamples��
        PolynomialFit2PowersImpl(const Samples& xSamples, const Samples& wSamples, const Powers& powers);

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
        // ֧�ֹ���
        void Init(const Samples& xSamples, const Samples& wSamples);
        void InitializePowers();
        void TransformToUnit(const Samples& xSourceSamples, const Samples& wSourceSamples, Samples& xTargetSamples, Samples& wTargetSamples);
        void TransformToUnit(const Samples& sourceSamples, Samples& targetSamples, int index);
        void DoLeastSquaresFit(const Samples& xTargetSamples, const Samples& wTargetSamples);

    private:
        // ���Ƶ�������ϵĶ���ʽ������ʹ�á�
        Powers m_Powers;

        PolynomialFitPowersData<Real, 2> m_PowersData;
    };
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_IMPL_H

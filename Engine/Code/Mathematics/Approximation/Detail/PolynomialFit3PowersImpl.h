///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/04 14:11)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_POWERS_IMPL_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_POWERS_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "PolynomialFitPowersData.h"
#include "CoreTools/DataTypes/Tuple.h"

#include <vector>

namespace Mathematics
{
    // ��������ʽ�Ķ���ʽ�������
    //     w = sum_{i=0}^{n-1} c[i]*x^{p[i]}*y^{q[i]}
    // ����<p[i],q[i]> �ɵ������ṩ��ͬ�ķǸ����ݡ�
    // ��ʹ����С��������㷨��
    // ����������(x,y,w) ���ȱ�ӳ�䵽[-1,1]^3  ����ֵ³���ԡ�
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE PolynomialFit3PowersImpl final
    {
    public:
        using ClassType = PolynomialFit3PowersImpl<Real>;
        using Samples = std::vector<Real>;
        using Tuple = CoreTools::Tuple<2, int>;
        using Powers = std::vector<Tuple>;
        using Math = Math<Real>;

    public:
        // ���캯��������(x[i],y[i],w[i])���ֱ�Ϊ0 <= i < numSamples��
        // ��isRepackage Ϊtrueʱ�����캯��������(x[i],y[j],w[k])��
        // ���У�0 <= i < numXSamples, 0 <= j < numYSamples,�� k = i + numXSamples * j
        PolynomialFit3PowersImpl(const Samples& xSamples, const Samples& ySamples, const Samples& wSamples, const Powers& powers, bool isRepackage = false);

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
        void Init(const Samples& xSamples, const Samples& ySamples, const Samples& wSamples, bool isRepackage);
        void InitializePowers();
        void Repackage(const Samples& xSourceSamples, const Samples& ySourceSamples, Samples& xTargetSamples, Samples& yTargetSamples);
        void TransformToUnit(const Samples& xSourceSamples, const Samples& ySourceSamples, const Samples& wSourceSamples, Samples& xTargetSamples, Samples& yTargetSamples, Samples& wTargetSamples);
        void TransformToUnit(const Samples& sourceSamples, Samples& targetSamples, int index);
        void DoLeastSquaresFit(const Samples& xTargetSamples, const Samples& yTargetSamples, const Samples& wTargetSamples);

    private:
        Powers m_Powers;
        PolynomialFitPowersData<Real, 3> m_PowersData;
    };
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_POWERS_IMPL_H

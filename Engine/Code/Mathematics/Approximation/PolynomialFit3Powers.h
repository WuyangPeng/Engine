///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/18 17:46)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_POWERS_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_POWERS_H

#include "Mathematics/MathematicsDll.h"

#include "PolynomialFitPowersData.h"
#include "CoreTools/DataTypes/Tuple.h"
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
    class PolynomialFit3Powers final
    {
    public:
        using ClassType = PolynomialFit3Powers<Real>;

        using Samples = std::vector<Real>;
        using Tuple = CoreTools::Tuple<2, int>;
        using Powers = std::vector<Tuple>;
        using Math = Math<Real>;

    public:
        // ���캯��������(x[i],y[i],w[i])���ֱ�Ϊ0 <= i < numSamples��
        // ��isRepackage Ϊtrueʱ�����캯��������(x[i],y[j],w[k])��
        // ���У�0 <= i < numXSamples, 0 <= j < numYSamples,�� k = i + numXSamples * j
        PolynomialFit3Powers(const Samples& xSamples, const Samples& ySamples, const Samples& wSamples, const Powers& powers, bool isRepackage = false);

        CLASS_INVARIANT_DECLARE;

        // ����һ�������࣬��������Է�����ɹ��򷵻ء�true����
        // ������ɹ��������ʽ��ֵ����Ч�ģ����Ƿ���false��
        NODISCARD bool IsSolveSucceed() const noexcept;

        NODISCARD Real GetXMin() const;
        NODISCARD Real GetXMax() const;
        NODISCARD Real GetYMin() const;
        NODISCARD Real GetYMax() const;
        NODISCARD Real GetWMin() const;
        NODISCARD Real GetWMax() const;

        // ��϶���ʽ�ĵ�������
        // �����������д��ʵ�֣���Ч���������йش��ݸ����캯���ľ����ݵ�֪ʶ��
        NODISCARD Real operator()(Real x, Real y) const;

    private:
        void Init(const Samples& xSamples, const Samples& ySamples, const Samples& wSamples, bool isRepackage);
        void InitializePowers();
        void Repackage(const Samples& xSourceSamples, const Samples& ySourceSamples, Samples& xTargetSamples, Samples& yTargetSamples);
        void TransformToUnit(const Samples& xSourceSamples, const Samples& ySourceSamples, const Samples& wSourceSamples, Samples& xTargetSamples, Samples& yTargetSamples, Samples& wTargetSamples);
        void TransformToUnit(const Samples& sourceSamples, Samples& targetSamples, int index);
        void DoLeastSquaresFit(const Samples& xTargetSamples, const Samples& yTargetSamples, const Samples& wTargetSamples);

    private:
        Powers powers;
        PolynomialFitPowersData<Real, 3> powersData;
    };

    using PolynomialFit3PowersF = PolynomialFit3Powers<float>;
    using PolynomialFit3PowersD = PolynomialFit3Powers<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_POWERS_H

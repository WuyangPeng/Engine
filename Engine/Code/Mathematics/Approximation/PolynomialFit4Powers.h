///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 17:21)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT4_POWERS_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT4_POWERS_H

#include "Mathematics/MathematicsDll.h"

#include "PolynomialFitPowersData.h"
#include "CoreTools/DataTypes/Tuple.h"

#include <memory>
#include <vector>

namespace Mathematics
{
    // ��������ʽ�Ķ���ʽ�������
    //     w = sum_{i=0}^{n-1} c[i]*x^{p[i]}*y^{q[i]}*z^{r[i]}
    // ����<p[i],q[i],r[i]> �ɵ������ṩ��ͬ�ķǸ����ݡ�
    // ��ʹ����С��������㷨��
    // ����������(x,y,z,w) ���ȱ�ӳ�䵽[-1,1]^4 ����ֵ³���ԡ�

    template <typename Real>
    class PolynomialFit4Powers final
    {
    public:
        using ClassType = PolynomialFit4Powers<Real>;

        using Samples = std::vector<Real>;
        using Tuple = CoreTools::Tuple<3, int>;
        using Powers = std::vector<Tuple>;
        using Math = Math<Real>;

    public:
        // ���캯��������(x[i],y[i],z[i],w[i])���ֱ�Ϊ0 <= i < numSamples��
        // ��isRepackage Ϊtrueʱ�����캯��������(x[i],y[j],z[k],w[m]),
        // ���У�0 <= i < numXSamples, 0 <= j < numYSamples,
        //  0 <= k < numZSamples �� m = i + numXSamples*(j + numYSamples*k)

        PolynomialFit4Powers(const Samples& xSamples,
                             const Samples& ySamples,
                             const Samples& zSamples,
                             const Samples& wSamples,
                             const Powers& powers,
                             bool isRepackage);

        CLASS_INVARIANT_DECLARE;

        // ����һ�������࣬��������Է�����ɹ��򷵻ء�true����
        // ������ɹ��������ʽ��ֵ����Ч�ģ����Ƿ���false��
        NODISCARD bool IsSolveSucceed() const noexcept;

        NODISCARD Real GetXMin() const;
        NODISCARD Real GetXMax() const;
        NODISCARD Real GetYMin() const;
        NODISCARD Real GetYMax() const;
        NODISCARD Real GetZMin() const;
        NODISCARD Real GetZMax() const;
        NODISCARD Real GetWMin() const;
        NODISCARD Real GetWMax() const;

        // ��϶���ʽ�ĵ�������
        // �����������д��ʵ�֣���Ч���������йش��ݸ����캯���ľ����ݵ�֪ʶ��
        NODISCARD Real operator()(Real x, Real y, Real z) const;

    private:
        void Init(const Samples& xSamples, const Samples& ySamples, const Samples& zSamples, const Samples& wSamples, bool isRepackage);
        void InitializePowers();
        void Repackage(const Samples& xSourceSamples,
                       const Samples& ySourceSamples,
                       const Samples& zSourceSamples,
                       Samples& xTargetSamples,
                       Samples& yTargetSamples,
                       Samples& zTargetSamples);
        void TransformToUnit(const Samples& xSourceSamples,
                             const Samples& ySourceSamples,
                             const Samples& zSourceSamples,
                             const Samples& wSourceSamples,
                             Samples& xTargetSamples,
                             Samples& yTargetSamples,
                             Samples& zTargetSamples,
                             Samples& wTargetSamples);
        void TransformToUnit(const Samples& sourceSamples, Samples& targetSamples, int index);
        void DoLeastSquaresFit(const Samples& xTargetSamples,
                               const Samples& yTargetSamples,
                               const Samples& zTargetSamples,
                               const Samples& wTargetSamples);

    private:
        Powers powers;
        PolynomialFitPowersData<Real, 4> powersData;
    };

    using PolynomialFit4PowersF = PolynomialFit4Powers<float>;
    using PolynomialFit4PowersD = PolynomialFit4Powers<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT4_POWERS_H

///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/04 10:02)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_SAMPLES_POWER_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_SAMPLES_POWER_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/VariableMatrix.h"
#include "Mathematics/Base/MathDetail.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE PolynomialSamplesPower final
    {
    public:
        using ClassType = PolynomialSamplesPower<Real>;
        using Samples = std::vector<Real>;
        using Math = Math<Real>;
        using VariableMatrix = VariableMatrix<Real>;

    public:
        PolynomialSamplesPower(const Samples& samples, int degree);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] Real operator()(int samplesIndex, int degreeIndex) const;
        [[nodiscard]] int GetNumSamples() const noexcept;
        [[nodiscard]] int GetNumDegree() const noexcept;

    private:
        void Calculate(const Samples& samples);

    private:
        int m_NumDegree;
        int m_NumSamples;
        VariableMatrix m_Power;
    };
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_SAMPLES_POWER_H

///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/18 18:14)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_SAMPLES_POWER_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_SAMPLES_POWER_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/VariableMatrix.h"
#include "Mathematics/Base/MathDetail.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class PolynomialSamplesPower final
    {
    public:
        using ClassType = PolynomialSamplesPower<Real>;
        using Samples = std::vector<Real>;
        using Math = Math<Real>;
        using VariableMatrix = VariableMatrix<Real>;

    public:
        PolynomialSamplesPower(const Samples& samples, int degree);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Real operator()(int samplesIndex, int degreeIndex) const;
        NODISCARD int GetNumSamples() const noexcept;
        NODISCARD int GetNumDegree() const noexcept;

    private:
        void Calculate(const Samples& samples);

    private:
        int numDegree;
        int numSamples;
        VariableMatrix power;
    };
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_SAMPLES_POWER_H

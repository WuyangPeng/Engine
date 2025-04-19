///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 14:27)

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
        using MathType = Math<Real>;
        using VariableMatrixType = VariableMatrix<Real>;

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
        VariableMatrixType power;
    };
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_SAMPLES_POWER_H

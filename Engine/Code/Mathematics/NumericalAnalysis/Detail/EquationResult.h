///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/19 14:01)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_RESULT_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_RESULT_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/EquationResultConstIterator.h"

#include <complex>
#include <vector>

namespace Mathematics
{
    class MATHEMATICS_HIDDEN_DECLARE EquationResult final
    {
    public:
        using ClassType = EquationResult;
        using Imaginary = std::complex<double>;
        using ImaginaryVector = std::vector<Imaginary>;
        using RealVector = std::vector<double>;
        using ImaginaryResultConstIter = ImaginaryVector::const_iterator;
        using RealResultConstIter = RealVector::const_iterator;
        using RealConstIterator = EquationResultConstIterator<RealResultConstIter>;
        using ImaginaryConstIterator = EquationResultConstIterator<ImaginaryResultConstIter>;

    public:
        EquationResult() noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] bool IsRealResult() const noexcept;
        [[nodiscard]] int GetRealResultCount() const;
        [[nodiscard]] int GetImaginaryResultCount() const;

        void AddRealResult(double solution, double epsilon = DoubleMath::GetZeroTolerance());
        void AddImaginaryResult(const Imaginary& solution, double epsilon = DoubleMath::GetZeroTolerance());
        void CleanSolution() noexcept;

        [[nodiscard]] const RealConstIterator GetRealBegin() const noexcept;
        [[nodiscard]] const RealConstIterator GetRealEnd() const noexcept;
        [[nodiscard]] const ImaginaryConstIterator GetImaginaryBegin() const noexcept;
        [[nodiscard]] const ImaginaryConstIterator GetImaginaryEnd() const noexcept;

        void SortResult();

    private:
        [[nodiscard]] bool FindSolution(double solution, double epsilon) const noexcept;
        [[nodiscard]] bool FindSolution(const Imaginary& solution, double epsilon) const;

        class ImaginaryLess
        {
        public:
            using ClassType = ImaginaryLess;

        public:
            [[nodiscard]] bool operator()(const Imaginary& lhs, const Imaginary& rhs) const;

            CLASS_INVARIANT_DECLARE;
        };

    private:
        RealVector m_RealResult;
        ImaginaryVector m_ImaginaryResult;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_RESULT_H
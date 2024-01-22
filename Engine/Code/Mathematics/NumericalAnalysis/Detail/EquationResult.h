/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 13:52)

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
        using ImaginaryContainer = std::vector<Imaginary>;
        using RealContainer = std::vector<double>;
        using ImaginaryResultConstIter = ImaginaryContainer::const_iterator;
        using RealResultConstIter = RealContainer::const_iterator;
        using RealConstIterator = EquationResultConstIterator<RealResultConstIter>;
        using ImaginaryConstIterator = EquationResultConstIterator<ImaginaryResultConstIter>;

    public:
        EquationResult() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsRealResult() const noexcept;
        NODISCARD int GetRealResultCount() const;
        NODISCARD int GetImaginaryResultCount() const;

        void AddRealResult(double solution, double epsilon = MathD::GetZeroTolerance());
        void AddImaginaryResult(const Imaginary& solution, double epsilon = MathD::GetZeroTolerance());
        void CleanSolution() noexcept;

        NODISCARD RealConstIterator GetRealBegin() const noexcept;
        NODISCARD RealConstIterator GetRealEnd() const noexcept;
        NODISCARD ImaginaryConstIterator GetImaginaryBegin() const noexcept;
        NODISCARD ImaginaryConstIterator GetImaginaryEnd() const noexcept;

        void SortResult();

    private:
        NODISCARD bool FindSolution(double solution, double epsilon) const noexcept;
        NODISCARD bool FindSolution(const Imaginary& solution, double epsilon) const noexcept;

        class ImaginaryLess
        {
        public:
            using ClassType = ImaginaryLess;

        public:
            NODISCARD bool operator()(const Imaginary& lhs, const Imaginary& rhs) const noexcept;

            CLASS_INVARIANT_DECLARE;
        };

    private:
        RealContainer realResult;
        ImaginaryContainer imaginaryResult;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_RESULT_H
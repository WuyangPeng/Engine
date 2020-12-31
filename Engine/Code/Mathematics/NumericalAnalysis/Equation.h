///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/24 17:51)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_H

#include "Mathematics/MathematicsDll.h"

#include "EquationResultConstIterator.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Mathematics/Base/MathDetail.h"

#include <complex>
#include <vector>

MATHEMATICS_EXPORT_SHARED_PTR(EquationImpl);

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE Equation final
    {
    public:
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(Equation);
        using Imaginary = std::complex<double>;
        using ImaginaryVector = std::vector<Imaginary>;
        using RealVector = std::vector<double>;
        using ImaginaryResultConstIter = ImaginaryVector::const_iterator;
        using RealResultConstIter = RealVector::const_iterator;
        using RealConstIterator = EquationResultConstIterator<RealResultConstIter>;
        using ImaginaryConstIterator = EquationResultConstIterator<ImaginaryResultConstIter>;

    public:
        explicit Equation(double constant, double once, double secondary = 0.0,
                          double thrice = 0.0, double quartic = 0.0, double epsilon = DoubleMath::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] bool IsRealResult() const noexcept;
        [[nodiscard]] double Substitution(double value) const;
        [[nodiscard]] const Imaginary Substitution(const Imaginary& value) const;
        [[nodiscard]] int GetRealResultCount() const;
        [[nodiscard]] int GetImaginaryResultCount() const;

        [[nodiscard]] const RealConstIterator GetRealBegin() const noexcept;
        [[nodiscard]] const RealConstIterator GetRealEnd() const noexcept;
        [[nodiscard]] const ImaginaryConstIterator GetImaginaryBegin() const noexcept;
        [[nodiscard]] const ImaginaryConstIterator GetImaginaryEnd() const noexcept;

    private:
        IMPL_TYPE_DECLARE(Equation);
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_H
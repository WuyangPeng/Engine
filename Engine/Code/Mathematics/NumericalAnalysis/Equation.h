///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 11:35)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_H

#include "Mathematics/MathematicsDll.h"

#include "EquationResultConstIterator.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Mathematics/Base/MathDetail.h"

#include <complex>
#include <vector>

MATHEMATICS_PERFORMANCE_UNSHARED_EXPORT_IMPL(EquationImpl);

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE Equation final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(Equation);

        using Imaginary = std::complex<double>;
        using ImaginaryContainer = std::vector<Imaginary>;
        using RealContainer = std::vector<double>;
        using ImaginaryResultConstIter = ImaginaryContainer::const_iterator;
        using RealResultConstIter = RealContainer::const_iterator;
        using RealConstIterator = EquationResultConstIterator<RealResultConstIter>;
        using ImaginaryConstIterator = EquationResultConstIterator<ImaginaryResultConstIter>;

    public:
        explicit Equation(double constant,
                          double once,
                          double secondary = 0.0,
                          double thrice = 0.0,
                          double quartic = 0.0,
                          double epsilon = MathD::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsRealResult() const noexcept;
        NODISCARD double Substitution(double value) const;
        NODISCARD Imaginary Substitution(const Imaginary& value) const;
        NODISCARD int GetRealResultCount() const;
        NODISCARD int GetImaginaryResultCount() const;

        NODISCARD RealConstIterator GetRealBegin() const noexcept;
        NODISCARD RealConstIterator GetRealEnd() const noexcept;
        NODISCARD ImaginaryConstIterator GetImaginaryBegin() const noexcept;
        NODISCARD ImaginaryConstIterator GetImaginaryEnd() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_H
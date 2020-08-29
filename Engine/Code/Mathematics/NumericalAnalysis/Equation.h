// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 12:48)

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
    class MATHEMATICS_DEFAULT_DECLARE Equation
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
                          double thrice = 0.0, double quartic = 0.0, double epsilon = Mathd::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        bool IsRealResult() const noexcept;
        double Substitution(double value) const;
        const Imaginary Substitution(const Imaginary& value) const;
        int GetRealResultCount() const;
        int GetImaginaryResultCount() const;

        const RealConstIterator GetRealBegin() const noexcept;
        const RealConstIterator GetRealEnd() const noexcept;
        const ImaginaryConstIterator GetImaginaryBegin() const noexcept;
        const ImaginaryConstIterator GetImaginaryEnd() const noexcept;

    private:
        IMPL_TYPE_DECLARE(Equation);
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_H
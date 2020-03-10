// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/08 15:48)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "EquationResultConstIterator.h"

#include <complex>
#include <vector>

MATHEMATICS_EXPORT_SHARED_PTR( EquationImpl);

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
        explicit Equation(double constant,double once,double secondary = 0.0,
						  double thrice = 0.0, double quartic = 0.0, double epsilon = Mathd::sm_ZeroTolerance);
        
		CLASS_INVARIANT_DECLARE;

		bool IsRealResult() const;
		double Substitution(double value) const;
		const Imaginary Substitution(const Imaginary& value) const;
		int GetRealResultCount() const;
		int GetImaginaryResultCount() const;

		const RealConstIterator GetRealBegin() const;
		const RealConstIterator GetRealEnd() const;
		const ImaginaryConstIterator GetImaginaryBegin() const;
		const ImaginaryConstIterator GetImaginaryEnd() const;
        
	private:
		IMPL_TYPE_DECLARE(Equation);
	};	
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_H
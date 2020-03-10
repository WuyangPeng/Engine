// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 11:20)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_SAMPLES_POWER_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_SAMPLES_POWER_H

#include "Mathematics/MathematicsDll.h"

#include <vector>

namespace Mathematics
{	
	template <typename Real>
	class PolynomialSamplesPower
	{
	public:		
		using ClassType = PolynomialSamplesPower<Real>;
		using Samples = std::vector<Real>;

	public:
		PolynomialSamplesPower(const Samples& samples,int degree);
		~PolynomialSamplesPower();

		PolynomialSamplesPower(const PolynomialSamplesPower& rhs);
		PolynomialSamplesPower& operator=(const PolynomialSamplesPower& rhs);

		CLASS_INVARIANT_DECLARE;

		Real operator()(int samplesIndex, int degreeIndex) const;
		int GetNumSamples() const;
		int GetNumDegree() const;

	private:
		void Swap(PolynomialSamplesPower& rhs);
		void Calculate(const Samples& samples);

	private:			
		int m_NumDegree;
		int m_NumSamples;
		Real** m_Power;
	};	 
}

#endif // MATHEMATICS_APPROXIMATION_POLYNOMIAL_SAMPLES_POWER_H

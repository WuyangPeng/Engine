// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/08 16:03)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_DATA_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_DATA_H

#include "Mathematics/MathematicsDll.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class Minimize1Data
    {
    public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Minimize1Data<Real>;
		
	public:
		Minimize1Data();
		Minimize1Data(Real minLocation, Real minValue);
        
		CLASS_INVARIANT_DECLARE;
 
		Real GetMinLocation() const;
		Real GetMinValue() const;

		void SetMinLocation(Real minLocation);
		void SetMinValue(Real minValue);
		void SetInitValue();
		void CompareData(Real minLocation, Real minValue);		
        
    private:
		Real m_MinLocation;
		Real m_MinValue;
    };

	using Minimize1Dataf = Minimize1Data<float>;
	using Minimize1Datad = Minimize1Data<double>;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_DATA_H

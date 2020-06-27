// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 12:50)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_DATA_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_DATA_H

#include "Mathematics/MathematicsDll.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
	template <typename Real>
	class MinimizeNData
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = MinimizeNData<Real>;
		using RealVector = std::vector<Real>;
		using ConstIter = typename RealVector::const_iterator;

	public:
		MinimizeNData();
		MinimizeNData(const RealVector& minLocation, Real minValue);

		CLASS_INVARIANT_DECLARE;

		const ConstIter GetMinLocationBegin() const;
		const ConstIter GetMinLocationEnd() const;
		Real GetMinLocation(int index) const;
		Real GetMinValue() const;
		int GetDimensions() const;

		void Set(Real minValue, Real minLocation, const Real* directionCurrent);

		const RealVector& GetMinLocation() const;

	private:
		RealVector m_MinLocation;
		Real m_MinValue;
	};

	using MinimizeNDataf = MinimizeNData<float>;
	using MinimizeNDatad = MinimizeNData<double>;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_DATA_H

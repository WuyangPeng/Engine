// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 12:31)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT_POWERS_DATA_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT_POWERS_DATA_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/VariableLengthVector.h"
#include "Mathematics/Algebra/VariableMatrix.h"

#include <array> 
#include <vector>

namespace Mathematics
{
	template <typename Real, int S>
	class PolynomialFitPowersData
	{
	public:
		static_assert(2 <= S && S <= 4, "2 <= S && S <= 4");
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		static constexpr auto Size = S;
		using ClassType = PolynomialFitPowersData<Real, Size>;

	public:
		explicit PolynomialFitPowersData(int numPowers);

		CLASS_INVARIANT_DECLARE;


		bool IsSolveSucceed() const;
		int GetSize() const;
		int GetMaxPower(int index) const;
		Real GetMin(int index) const;
		Real GetMax(int index) const;
		Real GetScale(int index) const;
		Real GetInvTwoWScale() const;
		const std::vector<Real> GetCoefficients() const;
		Real GetCoefficients(int index) const;

		void SetMaxPower(int index, int power);
		void SetScale(int index, Real scale);

		void Solve(const VariableMatrix<Real>& matrix, const VariableLengthVector<Real>& vector);

	private:
		std::array<int, Size - 1> m_MaxPower;
		std::array<Real, Size> m_Min;
		std::array<Real, Size> m_Max;
		std::array<Real, Size> m_Scale;
		Real m_InvTwoWScale;
		std::vector<Real> m_Coefficients;
		bool m_Solved;
	};
}

#endif // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT_POWERS_DATA_H

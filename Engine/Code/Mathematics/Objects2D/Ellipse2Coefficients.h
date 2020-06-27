// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 16:46)

#ifndef MATHEMATICS_OBJECTS2D_ELLIPSE2_COEFFICIENTS_H
#define MATHEMATICS_OBJECTS2D_ELLIPSE2_COEFFICIENTS_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/Math.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/Matrix2.h"

#include <vector>
#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class Ellipse2Coefficients
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Ellipse2Coefficients<Real>;
		using Vector2D = Vector2D<Real>;
		using Matrix2 = Matrix2<Real>;
		using Math = Math<Real>;
		using CoefficientsType = std::vector<Real>;

	public:
		Ellipse2Coefficients(const Matrix2& matrix, const Vector2D& vector, Real constants);

		explicit Ellipse2Coefficients(const std::vector<Real>& coefficient);

		CLASS_INVARIANT_DECLARE;

		const Matrix2 GetMatrix() const;
		const Vector2D GetVector() const;
		Real GetConstants() const;
		const CoefficientsType GetCoefficients() const;

	private:
		CoefficientsType m_Coefficients;
	};

	template <typename Real>
	bool Approximate(const Ellipse2Coefficients<Real>& lhs, const Ellipse2Coefficients<Real>& rhs, const Real epsilon);

	using Ellipse2Coefficientsf = Ellipse2Coefficients<float>;
	using Ellipse2Coefficientsd = Ellipse2Coefficients<double>;
}

#endif // MATHEMATICS_OBJECTS2D_ELLIPSE2_COEFFICIENTS_H

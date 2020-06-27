// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 17:22)

#ifndef MATHEMATICS_OBJECTS3D_ELLIPSOID3_COEFFICIENTS_H
#define MATHEMATICS_OBJECTS3D_ELLIPSOID3_COEFFICIENTS_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Algebra/Matrix3.h"

#include <type_traits> 
#include <vector>

namespace Mathematics
{
	template <typename Real>
	class Ellipsoid3Coefficients
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Ellipsoid3Coefficients<Real>;
		using Vector3D = Vector3D<Real>;
		using Matrix3 = Matrix3<Real>;

	public:
		Ellipsoid3Coefficients(const Matrix3& matrix, const Vector3D& vector, Real constants);

		explicit Ellipsoid3Coefficients(const std::vector<Real>& coefficient);

		CLASS_INVARIANT_DECLARE;

		const Matrix3 GetMatrix() const;
		const Vector3D GetVector() const;
		Real GetConstants() const;
		const std::vector<Real> GetCoefficients() const;

		static int GetCoefficientsSize();

	private:
		std::vector<Real> m_Coefficients;
	};

	template <typename Real>
	bool Approximate(const Ellipsoid3Coefficients<Real>& lhs, const Ellipsoid3Coefficients<Real>& rhs, const Real epsilon);

	using Ellipsoid3Coefficientsf = Ellipsoid3Coefficients<float>;
	using Ellipsoid3Coefficientsd = Ellipsoid3Coefficients<double>;
}

#endif // MATHEMATICS_OBJECTS3D_ELLIPSOID3_COEFFICIENTS_H

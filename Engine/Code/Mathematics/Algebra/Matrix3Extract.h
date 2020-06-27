// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 10:13)

#ifndef MATHEMATICS_ALGEBRA_MATRIX3_EXTRACT_H
#define MATHEMATICS_ALGEBRA_MATRIX3_EXTRACT_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"

#include <type_traits>

namespace Mathematics
{
	template <typename Real>
	class Matrix3Extract
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Matrix3Extract<Real>;
		using Vector3D = Vector3D<Real>;

	public:
		Matrix3Extract(Real angle, const Vector3D& axis);

		CLASS_INVARIANT_DECLARE;

		Real GetAngle() const;
		const Vector3D GetAxis() const;

	private:
		Real m_Angle;
		Vector3D m_Axis;
	};

	using Matrix3Extractf = Matrix3Extract<float>;
	using Matrix3Extractd = Matrix3Extract<double>;
}

#endif // MATHEMATICS_ALGEBRA_MATRIX3_EXTRACT_H

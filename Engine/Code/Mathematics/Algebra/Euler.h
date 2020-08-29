// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 10:11)

#ifndef MATHEMATICS_ALGEBRA_EULER_H
#define MATHEMATICS_ALGEBRA_EULER_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Flags/MatrixFlags.h"
#include "Flags/ExtractEulerResultType.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
	template <typename Real>
	class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Euler
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Euler<Real>;
		using Math = Math<Real>;

	public:
		Euler(ExtractEulerResultType type, ExtractEulerResultOrder order,
			  Real x0Angle, Real y0Angle, Real z0Angle,
			  Real x1Angle, Real y1Angle, Real z1Angle) noexcept;

		CLASS_INVARIANT_DECLARE;

		ExtractEulerResultType GetType() const noexcept;
		ExtractEulerResultOrder GetOrder() const noexcept;
		Real GetX0Angle() const noexcept;
		Real GetY0Angle() const noexcept;
		Real GetZ0Angle() const noexcept;
		Real GetX1Angle() const noexcept;
		Real GetY1Angle() const noexcept;
		Real GetZ1Angle() const noexcept;
		Real GetAngle(MatrixRotationAxis axisIndex) const noexcept;
		void SetAngle(MatrixRotationAxis axisIndex, Real angle) noexcept;

	private:
		ExtractEulerResultType m_Type;
		ExtractEulerResultOrder m_Order;
		Real m_X0Angle;
		Real m_Y0Angle;
		Real m_Z0Angle;
		Real m_X1Angle;
		Real m_Y1Angle;
		Real m_Z1Angle;
	};

	using Eulerf = Euler<float>;
	using Eulerd = Euler<double>;
}

#endif // MATHEMATICS_ALGEBRA_EULER_H

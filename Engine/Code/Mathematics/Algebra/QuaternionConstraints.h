// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 10:14)

#ifndef MATHEMATICS_ALGEBRA_QUATERNION_CONSTRAINTS_H
#define MATHEMATICS_ALGEBRA_QUATERNION_CONSTRAINTS_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Mathematics/Base/Math.h"

#include <type_traits>

namespace Mathematics
{
	// 查找最近的四元数使用约束的角度。
	template <typename Real>
	class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE QuaternionConstraints
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = QuaternionConstraints<Real>;
		using Quaternion = Quaternion<Real>;
		using Math = Math<Real>;

	public:
		QuaternionConstraints(Real minAngle, Real maxAngle) noexcept;

		CLASS_INVARIANT_DECLARE;

		bool IsValid(Real x, Real y) const;

		Real GetCosMinAngle() const noexcept;
		Real GetSinMinAngle() const noexcept;
		Real GetCosMaxAngle() const noexcept;
		Real GetSinMaxAngle() const noexcept;
		Real GetCosAvrAngle() const noexcept;
		Real GetSinAvrAngle() const noexcept;
		Real GetMinAngle() const noexcept;
		Real GetMaxAngle() const noexcept;

	private:
		Real m_MinAngle;       // 在 [-PI/2,PI/2]
		Real m_MaxAngle;       // 在 [m_fMinAngle/2,PI/2]
		Real m_CosMinAngle;    // = cos(m_fMinAngle)
		Real m_SinMinAngle;    // = sin(m_fMinAngle)
		Real m_CosMaxAngle;    // = cos(m_fMaxAngle)
		Real m_SinMaxAngle;    // = sin(m_fMaxAngle)
		Real m_DiffCosMaxMin;  // = cos(m_fMaxAngle) - cos(m_fMinAngle)
		Real m_DiffSinMaxMin;  // = sin(m_fMaxAngle) - sin(m_fMinAngle)
		Real m_AvrAngle;
		Real m_CosAvrAngle;    // = cos((m_fMinAngle + m_fMaxAngle)/2)
		Real m_SinAvrAngle;    // = sin((m_fMinAngle + mM_faxAngle)/2)		
	};

	using QuaternionConstraintsf = QuaternionConstraints<float>;
	using QuaternionConstraintsd = QuaternionConstraints<double>;
}

#endif // MATHEMATICS_ALGEBRA_QUATERNION_CONSTRAINTS_H

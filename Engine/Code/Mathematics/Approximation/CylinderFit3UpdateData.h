// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 12:28)

#ifndef MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_DATA_H
#define MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_DATA_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"

namespace Mathematics
{
	template <typename Real>
	class CylinderFit3UpdateData
	{
	public:
		using ClassType = CylinderFit3UpdateData<Real>;
		using Vector3D = Vector3D<Real>;

	public:
		CylinderFit3UpdateData(const Vector3D& point, const Vector3D& center, const Vector3D& axis);

		CLASS_INVARIANT_DECLARE;

		const Vector3D GetPoint() const;
		const Vector3D GetDelta() const;
		const Vector3D GetDeltaCrossAxis() const;
		Real GetDeltaCrossAxisLengthQuartic() const;
		const Vector3D GetDescentDirection() const;

	private:
		static const Vector3D CalculateDescentDirection(const Vector3D& delta, const Vector3D& axis);

	private:
		Vector3D m_Point;
		Vector3D m_Delta;
		Vector3D m_DeltaCrossAxis;
		Real m_DeltaCrossAxisLengthQuartic;
		Vector3D m_DescentDirection;
	};
}

#endif // MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_DATA_H	

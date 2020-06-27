// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 15:00)

#ifndef MATHEMATICS_INTERSECTION_TRIANGLE_PROJECT_ONTO_AXIS_H
#define MATHEMATICS_INTERSECTION_TRIANGLE_PROJECT_ONTO_AXIS_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Triangle3.h"
#include "Mathematics/Algebra/Vector3D.h"

namespace Mathematics
{
	template <typename Real>
	class TriangleProjectOntoAxis
	{
	public:
		using ClassType = TriangleProjectOntoAxis<Real>;
		using Triangle3 = Triangle3<Real>;
		using Vector3D = Vector3D<Real>;

	public:
		TriangleProjectOntoAxis(const Triangle3& triangle, const Vector3D& axis);

		CLASS_INVARIANT_DECLARE;

		Real GetMin() const;
		Real GetMax() const;

	private:
		void Project(const Triangle3& triangle, const Vector3D& axis);

	private:
		Real m_Min;
		Real m_Max;
	};

	using TriangleProjectOntoAxisf = TriangleProjectOntoAxis<float>;
	using TriangleProjectOntoAxisd = TriangleProjectOntoAxis<double>;
}

#endif // MATHEMATICS_INTERSECTION_TRIANGLE_PROJECT_ONTO_AXIS_H

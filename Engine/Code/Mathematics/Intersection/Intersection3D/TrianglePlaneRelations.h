// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 15:00)

#ifndef MATHEMATICS_INTERSECTION_TRIANGLE_PLANE_RELATIONS_H
#define MATHEMATICS_INTERSECTION_TRIANGLE_PLANE_RELATIONS_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Objects3D/Triangle3.h"

#include <array>

namespace Mathematics
{
	template <typename Real>
	class TrianglePlaneRelations
	{
	public:
		using ClassType = TrianglePlaneRelations<Real>;
		using Triangle3 = Triangle3<Real>;
		using Vector3D = Vector3D<Real>;
		using Plane3 = Plane3<Real>;
		using Math = Math<Real>;

	public:
		TrianglePlaneRelations(const Triangle3& triangle, const Plane3& plane, const Real epsilon = Math::sm_ZeroTolerance);

		CLASS_INVARIANT_DECLARE;

		Real GetDistance(int index) const;
		NumericalValueSymbol GetSign(int index) const;
		int GetPositive() const;
		int GetNegative() const;
		int GetZero() const;

	private:
		void Relations(const Triangle3& triangle, const Plane3& plane, const Real epsilon);

	private:
		constexpr static auto sm_Size = 3;

		std::array<Real, sm_Size> m_Distance;
		std::array<NumericalValueSymbol, sm_Size> m_Sign;
		int m_Positive;
		int m_Negative;
		int m_Zero;
	};

	using TrianglePlaneRelationsf = TrianglePlaneRelations<float>;
	using TrianglePlaneRelationsd = TrianglePlaneRelations<double>;
}

#endif // MATHEMATICS_INTERSECTION_TRIANGLE_PLANE_RELATIONS_H

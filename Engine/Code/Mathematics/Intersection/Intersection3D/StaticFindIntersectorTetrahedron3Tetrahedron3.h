// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:52)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRAHEDRON3_TETRAHEDRON3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRAHEDRON3_TETRAHEDRON3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Tetrahedron3.h" 
#include "Mathematics/Intersection/StaticIntersector.h"   

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorTetrahedron3Tetrahedron3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorTetrahedron3Tetrahedron3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Tetrahedron3 = Tetrahedron3<Real>;
		using Plane3 = Plane3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
		StaticFindIntersectorTetrahedron3Tetrahedron3(const Tetrahedron3& tetrahedron0, const Tetrahedron3& tetrahedron1);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		 [[nodiscard]] const Tetrahedron3 GetTetrahedron0() const;
                [[nodiscard]] const Tetrahedron3 GetTetrahedron1() const;

		// Information about the intersection set.
                [[nodiscard]] const std::vector<Tetrahedron3> GetIntersection() const;

	private:
		// Static query.
		void Find();

		static void SplitAndDecompose(Tetrahedron3 tetra, const Plane3& plane, std::vector<Tetrahedron3>& Inside);

		// The objects to intersect.
		Tetrahedron3 mTetrahedron0;
		Tetrahedron3 mTetrahedron1;

		std::vector<Tetrahedron3> mIntersection;
	};

	using FloatStaticFindIntersectorTetrahedron3Tetrahedron3 = StaticFindIntersectorTetrahedron3Tetrahedron3<float>;
	using DoubleStaticFindIntersectorTetrahedron3Tetrahedron3 = StaticFindIntersectorTetrahedron3Tetrahedron3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRAHEDRON3_TETRAHEDRON3_H

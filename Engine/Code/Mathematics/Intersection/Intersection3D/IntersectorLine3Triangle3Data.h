// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 14:49)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR_LINE3_TRIANGLE3_DATA_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR_LINE3_TRIANGLE3_DATA_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Triangle3.h"
#include "Mathematics/Algebra/Vector3DTools.h"

namespace Mathematics
{
	template <typename Real>
	class IntersectorLine3Triangle3Data
	{
	public:
		using ClassType = IntersectorLine3Triangle3Data<Real>;
		using Vector3D = Vector3D<Real>;
		using Line3 = Line3<Real>;
		using Triangle3 = Triangle3<Real>;
		using Vector3DTools = Vector3DTools<Real>;

	public:
		IntersectorLine3Triangle3Data(const Line3& line, const Triangle3& triangle);

		CLASS_INVARIANT_DECLARE;

		const Line3 GetLine() const;
		const Triangle3 GetTriangle() const;
                Real GetDirectionDotNormal() const noexcept;

		Vector3D GetOriginCrossEdge2() const noexcept;
                Vector3D GetEdge1CrossOrigin() const noexcept;
                Real GetOriginDotNormal() const noexcept;

	private:
		void CalculateDirectionDotNormal();

	private:
		// 相交对象
		Line3 m_Line;
		Triangle3 m_Triangle;
		Vector3D m_Origin;
		Vector3D m_Edge1;
		Vector3D m_Edge2;
		Vector3D m_Normal;
		Real m_DirectionDotNormal;
	};

	using IntersectorLine3Triangle3Dataf = IntersectorLine3Triangle3Data<float>;
	using IntersectorLine3Triangle3Datad = IntersectorLine3Triangle3Data<double>;
}

#endif // MATHEMATICS_INTERSECTION_INTERSECTOR_LINE3_TRIANGLE3_DATA_H
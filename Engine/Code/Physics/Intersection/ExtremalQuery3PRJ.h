// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 17:30)

#ifndef PHYSICS_INTERSECTION_EXTREMAL_QUERY3PRJ_H
#define PHYSICS_INTERSECTION_EXTREMAL_QUERY3PRJ_H

#include "Physics/PhysicsDll.h"

#include "ExtremalQuery3.h"

namespace Physics
{
	template <typename Real>
	class ExtremalQuery3PRJ : public ExtremalQuery3<Real>
	{
	public:
		typedef Mathematics::ConvexPolyhedron3<Real> ConvexPolyhedron3;
		ExtremalQuery3PRJ (const ConvexPolyhedron3* polytope);
		virtual ~ExtremalQuery3PRJ ();

		// Compute the extreme vertices in the specified direction and return the
		// indices of the vertices in the polyhedron vertex array.
		virtual void GetExtremeVertices (const typename  ExtremalQuery3<Real>::Vector3D& direction, int& positiveDirection, int& negativeDirection);

	private:
		using ExtremalQuery3<Real>::mPolytope;

		typename  ExtremalQuery3<Real>::Vector3D mCentroid;
	};

	using ExtremalQuery3PRJf = ExtremalQuery3PRJ<float>;
	using ExtremalQuery3PRJd = ExtremalQuery3PRJ<double>;
}

#endif // PHYSICS_INTERSECTION_EXTREMAL_QUERY3PRJ_H

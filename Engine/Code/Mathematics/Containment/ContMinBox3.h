// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 16:18)

#ifndef MATHEMATICS_CONTAINMENT_CONT_MIN_BOX3_H
#define MATHEMATICS_CONTAINMENT_CONT_MIN_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Box3.h"   
#include "Mathematics/Query/QueryBase.h"

namespace Mathematics
{
	// Compute a minimum volume oriented box containing the specified points.
	//
	// This is a function class.  Use it as follows:
	//   Box3<Real> minBox = MinBox3(numPoints, points, epsilon, queryType);
	
	template <typename Real>
	class MinBox3
	{
	public:
		MinBox3(const std::vector<Vector3<Real> >& points, Real epsilon, QueryType queryType);
		
		operator Box3<Real> () const;

	private:
		Box3<Real> mMinBox;
	};
}

#endif // MATHEMATICS_CONTAINMENT_CONT_MIN_BOX3_H

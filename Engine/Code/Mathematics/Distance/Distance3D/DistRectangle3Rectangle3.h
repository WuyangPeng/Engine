// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 16:21)

#ifndef MATHEMATICS_DISTANCE_DIST_RECTANGLE3_RECTANGLE3_H
#define MATHEMATICS_DISTANCE_DIST_RECTANGLE3_RECTANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Ray3.h"  
#include "Mathematics/Objects3D/Rectangle3.h"   
#include "Mathematics/Distance/DistanceBase.h"

namespace Mathematics
{
	template <typename Real>
	class DistRectangle3Rectangle3 : public DistanceBase<Real,Vector3D<Real> >
	{
	public:
		using ClassType = DistRectangle3Rectangle3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Rectangle3 = Rectangle3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult;
		using ParentType::GetZeroThreshold;

	public:
		DistRectangle3Rectangle3 (const Rectangle3& rectangle0,const Rectangle3& rectangle1);
		
		// Object access.
		const Rectangle3& GetRectangle0 () const;
		const Rectangle3& GetRectangle1 () const;
		
		// Static distanc queries.
		virtual const DistanceResult GetSquared() const override;
		
		// Function calculations for dynamic distance queries.
		virtual const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;
		
	private:
		Rectangle3 mRectangle0;
		Rectangle3 mRectangle1;
	};
	
	using DistRectangle3Rectangle3f = DistRectangle3Rectangle3<float>;
	using DistRectangle3Rectangle3d = DistRectangle3Rectangle3<double>;
}

#endif // MATHEMATICS_DISTANCE_DIST_RECTANGLE3_RECTANGLE3_H

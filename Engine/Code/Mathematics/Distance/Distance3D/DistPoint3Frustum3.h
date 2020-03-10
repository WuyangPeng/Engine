// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 16:12)

#ifndef MATHEMATICS_DISTANCE_DIST_POINT3_FRUSTUM3_H
#define MATHEMATICS_DISTANCE_DIST_POINT3_FRUSTUM3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Frustum3.h"  
#include "Mathematics/Distance/DistanceBase.h"

namespace Mathematics
{
	template <typename Real>
	class DistPoint3Frustum3 : public DistanceBase<Real,Vector3D<Real> >
	{
	public:
		using ClassType = DistPoint3Frustum3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Frustum3 = Frustum3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult;
		using ParentType::GetZeroThreshold;

	public:
		DistPoint3Frustum3 (const Vector3D& point,const Frustum3& frustum);
		
		// Object access.
		const Vector3D& GetPoint () const;
		const Frustum3& GetFrustum () const;
		
		// Static distance queries.
		virtual const DistanceResult GetSquared() const override;
		
		// Function calculations for dynamic distance queries.
		virtual const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity,const Vector3D& rhsVelocity) const override;
		
	private:
		Vector3D mPoint;
		Frustum3 mFrustum;
	};
	
	using DistPoint3Frustum3f = DistPoint3Frustum3<float>;
	using DistPoint3Frustum3d = DistPoint3Frustum3<double>;
}

#endif // MATHEMATICS_DISTANCE_DIST_POINT3_FRUSTUM3_H

// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 15:22)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Line3.h"

namespace Mathematics
{
	template <typename Real>
	class Vector3DTools;

	template <typename Real>
	class DistanceLine3Line3 : public DistanceBase<Real, Vector3D<Real> >
	{
	public:
		using ClassType = DistanceLine3Line3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Line3 = Line3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult;
		using ParentType::GetZeroThreshold;
		using Math = Math<Real>;

	public:
		DistanceLine3Line3(const Line3& lhsLine, const Line3& rhsLine);
		virtual ~DistanceLine3Line3();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Line3 GetLhsLine() const;
		const Line3 GetRhsLine() const;		

		// æ≤Ã¨æ‡¿Î≤È—Ø°£
		virtual const DistanceResult GetSquared() const override;

		// ∫Ø ˝º∆À„∂ØÃ¨æ‡¿Î≤È—Ø°£	
		virtual const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity,const Vector3D& rhsVelocity) const override;

	private:
		Line3 m_LhsLine;
		Line3 m_RhsLine;	
	};

	using DistanceLine3Line3f = DistanceLine3Line3<float>;
	using DistanceLine3Line3d = DistanceLine3Line3<double>;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_H


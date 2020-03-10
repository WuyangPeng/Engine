// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 15:09)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_TOOL_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_TOOL_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"

namespace Mathematics
{
	template <typename Real>
	class Vector3DTools;

	template <typename Real>
	class DistanceLine3Line3Tool
	{
	public:		
		using ClassType = DistanceLine3Line3Tool<Real>;
		using Vector3D = Vector3D<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;

	public:
		DistanceLine3Line3Tool(const Vector3D& lhsOrigin, const Vector3D& lhsDirection,const Vector3D& rhsOrigin, const Vector3D& rhsDirection);

		CLASS_INVARIANT_DECLARE;
		
		Real GetDet() const;
		Real GetLhsT() const;
		Real GetRhsT() const;
		Real GetOriginDifferenceDotLhsDirection() const;
		Real GetOriginDifferenceDotRhsDirection() const;
		Real GetOriginDifferenceSquaredLength() const;
		Real GetDirectionDot() const;
	
		Real GetLhsT(Real extent) const;
		Real GetRhsT(Real extent) const;		
		Real GetSquaredDistanceWithParallel() const;
		Real GetSquaredDistanceWithLhs() const;
		Real GetSquaredDistanceWithRhs() const;
		Real GetOriginDifferenceDotDirectionAverage() const;

	private:
		Vector3D m_OriginDifference;
		Real m_DirectionDot;
		Real m_OriginDifferenceDotLhsDirection;
		Real m_OriginDifferenceDotRhsDirection;
		Real m_OriginDifferenceSquaredLength;		
		Real m_Det;
	};	
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_TOOL_H

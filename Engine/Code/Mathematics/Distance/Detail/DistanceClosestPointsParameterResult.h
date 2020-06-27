// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 17:08)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_PARAMETER_RESULT_H
#define MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_PARAMETER_RESULT_H

#include "DistanceClosestPointsResult.h"

namespace Mathematics
{
	template <typename Real, typename Vector>
	class DistanceClosestPointsParameterResult : public DistanceClosestPointsResult<Real, Vector>
	{
	public:
		using ClassType = DistanceClosestPointsParameterResult<Real, Vector>;
		using ParentType = DistanceClosestPointsResult<Real, Vector>;
		using ImplTypePtr = ParentType::ImplTypePtr;

	public:
		DistanceClosestPointsParameterResult(Real distance, Real contactTime, const Vector& lhsClosestPoint,
											 const Vector& rhsClosestPoint, Real lhsParameter, Real rhsParameter);
		virtual ~DistanceClosestPointsParameterResult();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual Real GetLhsParameter() const override;
		virtual Real GetRhsParameter() const override;

		virtual ImplTypePtr Clone() const override;

	private:
		Real m_LhsParameter;
		Real m_RhsParameter;
	};
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_PARAMETER_RESULT_H

// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 17:08)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_MULTIPLE_CLOSEST_POINTS_RESULT_H
#define MATHEMATICS_DISTANCE_DISTANCE_MULTIPLE_CLOSEST_POINTS_RESULT_H

#include "DistanceContactTimeResult.h"

#include <vector>

namespace Mathematics
{
	template <typename Real, typename Vector>
	class DistanceMultipleClosestPointsResult : public DistanceContactTimeResult<Real, Vector>
	{
	public:
		using ClassType = DistanceMultipleClosestPointsResult<Real, Vector>;
		using ParentType = DistanceContactTimeResult<Real, Vector>;
		using ClosestPoints = std::vector<Vector>;
		using ImplTypePtr = ParentType::ImplTypePtr;

	public:
		DistanceMultipleClosestPointsResult(Real distance, Real contactTime, const ClosestPoints& lhsClosestPoints, const ClosestPoints& rhsClosestPoints);
		  ~DistanceMultipleClosestPointsResult();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		  const Vector GetLhsClosestPoint(int index) const override;
		  const Vector GetRhsClosestPoint(int index) const override;

		  int GetLhsClosestPointSize() const override;
		  int GetRhsClosestPointSize() const override;

		  ImplTypePtr Clone() const override;

	private:
		ClosestPoints m_LhsClosestPoints;
		ClosestPoints m_RhsClosestPoints;
	};
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_MULTIPLE_CLOSEST_POINTS_RESULT_H

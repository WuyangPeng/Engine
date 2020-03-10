// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 14:20)

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
		DistanceMultipleClosestPointsResult(Real distance, Real contactTime,const ClosestPoints& lhsClosestPoints,const ClosestPoints& rhsClosestPoints);
		virtual ~DistanceMultipleClosestPointsResult();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual const Vector GetLhsClosestPoint(int index) const override;
		virtual const Vector GetRhsClosestPoint(int index) const override;

		virtual int GetLhsClosestPointSize() const override;
		virtual int GetRhsClosestPointSize() const override;

		virtual ImplTypePtr Clone() const override;
		 
	private:
		ClosestPoints m_LhsClosestPoints;
		ClosestPoints m_RhsClosestPoints;
	};	  
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_MULTIPLE_CLOSEST_POINTS_RESULT_H

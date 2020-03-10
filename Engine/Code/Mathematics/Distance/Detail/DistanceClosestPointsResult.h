// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 14:18)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_RESULT_H
#define MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_RESULT_H

#include "DistanceContactTimeResult.h"

namespace Mathematics
{
	template <typename Real, typename Vector>
	class DistanceClosestPointsResult : public DistanceContactTimeResult<Real, Vector>
	{
	public:	
		using ClassType = DistanceClosestPointsResult<Real, Vector>;
		using ParentType = DistanceContactTimeResult<Real, Vector>;
		using ImplTypePtr = ParentType::ImplTypePtr;

	public:
		DistanceClosestPointsResult(Real distance, Real contactTime,const Vector& lhsClosestPoint,const Vector& rhsClosestPoint);
		virtual ~DistanceClosestPointsResult();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual const Vector GetLhsClosestPoint(int index) const override;
		virtual const Vector GetRhsClosestPoint(int index) const override;

		virtual int GetLhsClosestPointSize() const override;
		virtual int GetRhsClosestPointSize() const override;

		virtual ImplTypePtr Clone() const override;
		 
	private:
		static constexpr auto sm_PointSize = 1;

	private:
		Vector m_LhsClosestPoint;
		Vector m_RhsClosestPoint;
	};	  
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_RESULT_H

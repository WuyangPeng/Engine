// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 14:21)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RESULT_FACTORY_H
#define MATHEMATICS_DISTANCE_DISTANCE_RESULT_FACTORY_H

#include <vector>

namespace Mathematics
{
	template <typename Real, typename Vector>
	class DistanceResultImpl;

	template <typename Real, typename Vector>
	class DistanceResultFactory
	{
	public:		
		using ClassType = DistanceResultFactory<Real, Vector>;
		using DistanceResultImplPtr = std::shared_ptr<DistanceResultImpl<Real, Vector>>;
		using ClosestPoints = std::vector<Vector>;

	public:
		DistanceResultFactory();

		CLASS_INVARIANT_DECLARE;

		static DistanceResultImplPtr Create(Real distance);
		static DistanceResultImplPtr Create(Real distance, Real contactTime);
		static DistanceResultImplPtr Create(Real distance, Real contactTime,const Vector& lhsClosestPoint,const Vector& rhsClosestPoint);
		static DistanceResultImplPtr Create(Real distance, Real contactTime,const ClosestPoints& lhsClosestPoints,const ClosestPoints& rhsClosestPoints);
		static DistanceResultImplPtr Create(Real distance, Real contactTime,const Vector& lhsClosestPoint,const Vector& rhsClosestPoint,Real lhsParameter, Real rhsParameter);
	};
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_RESULT_FACTORY_H

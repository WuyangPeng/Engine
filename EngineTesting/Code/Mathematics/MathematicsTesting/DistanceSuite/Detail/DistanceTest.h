// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/29 17:42)

#ifndef MATHEMATICS_DISTANCE_SUITE_DISTANCE_TEST_H
#define MATHEMATICS_DISTANCE_SUITE_DISTANCE_TEST_H

#include "Mathematics/Distance/DistanceBase.h"

namespace Mathematics
{
	template <typename Real, typename Vector>
	class DistanceTest : public DistanceBase<Real, Vector>
	{
	public:
		using ClassType = DistanceTest<Real, Vector> ;
		using ParentType = DistanceBase<Real, Vector> ;
		using DistanceResult = DistanceResult<Real, Vector>;

	public:
		DistanceTest(const Vector& lhs, const Vector& rhs);
		virtual ~DistanceTest();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		const Vector GetLhs() const;
		const Vector GetRhs() const;

		virtual const DistanceResult GetSquared() const; 	
		virtual const DistanceResult GetSquared(Real t, const Vector& lhsVelocity,const Vector& rhsVelocity) const;

	private:
		Vector m_Lhs;
		Vector m_Rhs;
	};
}

#endif // MATHEMATICS_DISTANCE_SUITE_DISTANCE_TEST_H
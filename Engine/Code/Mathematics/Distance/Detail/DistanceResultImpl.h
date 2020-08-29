// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 17:08)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RESULT_IMPL_H
#define MATHEMATICS_DISTANCE_DISTANCE_RESULT_IMPL_H

#include "Mathematics/Base/MathDetail.h"

namespace Mathematics
{
	template <typename Real, typename Vector>
	class DistanceResultImpl
	{
	public:
		using ClassType = DistanceResultImpl<Real, Vector>;
		using ImplTypePtr = std::shared_ptr<ClassType>;
		using Math = Math<Real>;

	public:
		explicit DistanceResultImpl(Real distance);
		virtual ~DistanceResultImpl();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		Real GetDistance() const;
		const Vector GetLhsClosestPoint() const;
		const Vector GetRhsClosestPoint() const;

		void SetDistance(Real distance);
		void SetSqrtDistance();

		virtual Real GetContactTime() const;
		virtual const Vector GetLhsClosestPoint(int index) const;
		virtual const Vector GetRhsClosestPoint(int index) const;
		virtual int GetLhsClosestPointSize() const;
		virtual int GetRhsClosestPointSize() const;
		virtual ImplTypePtr Clone() const;
		virtual bool isHaveContactTime() const;

		virtual void SetContactTime(Real contactTime);

		virtual Real GetLhsParameter() const;
		virtual Real GetRhsParameter() const;

	private:
		static constexpr auto sm_ClosestPointZeroSize = 0;

	private:
		Real m_Distance;
	};
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_RESULT_IMPL_H

// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/23 17:12)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_RAY2_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_RAY2_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Ray2.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"

namespace Mathematics
{
	template <typename Real>
	class DistancePoint2Ray2 : public DistanceBase<Real, Vector2D<Real> >
	{
	public:
		using ClassType = DistancePoint2Ray2<Real>;
		using Vector2D = Vector2D<Real>;
		using ParentType = DistanceBase<Real, Vector2D>;
		using Ray2 = Ray2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult; 

	public:
		DistancePoint2Ray2(const Vector2D& point, const Ray2& ray);
		virtual ~DistancePoint2Ray2();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		const Vector2D GetPoint() const;
		const Ray2 GetRay() const;

		// ��̬�����ѯ��
		  const DistanceResult GetSquared() const override;

		// �������㶯̬�����ѯ��	
		  const DistanceResult GetSquared(Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity) const override;

	private:
		Vector2D m_Point;
		Ray2 m_Ray;
	};

	using DistancePoint2Ray2f = DistancePoint2Ray2<float>;
	using DistancePoint2Ray2d = DistancePoint2Ray2<double>;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_POINT2_RAY2_H



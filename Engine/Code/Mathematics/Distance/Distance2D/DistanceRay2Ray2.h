// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/10 15:05)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RAY2_RAY2_H
#define MATHEMATICS_DISTANCE_DISTANCE_RAY2_RAY2_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Ray2.h"
#include "Mathematics/Distance/DistanceBase.h"

namespace Mathematics
{
	template <typename Real>
	class Vector2DTools;

	template <typename Real>
	class DistanceLine2Line2Tool;

	template <typename Real>
	class DistanceRay2Ray2 : public DistanceBase<Real, Vector2D<Real> >
	{
	public:
		using ClassType = DistanceRay2Ray2<Real>;
		using Vector2D = Vector2D<Real>;
		using ParentType = DistanceBase<Real, Vector2D>;
		using Ray2 = Ray2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using DistanceLine2Line2Tool = DistanceLine2Line2Tool<Real>;
		using DistanceResult = typename ParentType::DistanceResult;
		using ParentType::GetZeroThreshold;
		using Math = Math<Real>;

	public:
		DistanceRay2Ray2(const Ray2& lhsRay, const Ray2& rhsRay);
		virtual ~DistanceRay2Ray2();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Ray2 GetLhsRay() const;
		const Ray2 GetRhsRay() const;

		// ��̬�����ѯ��
		virtual const DistanceResult GetSquared() const override;

		// �������㶯̬�����ѯ��	
		virtual const DistanceResult GetSquared(Real t, const Vector2D& lhsVelocity,const Vector2D& rhsVelocity) const override;

	private:
		const DistanceResult GetSquaredWithClosestPointsIsOrigin(const DistanceLine2Line2Tool& tool) const;
		const DistanceResult GetSquaredWithClosestPointsIsLhs(const DistanceLine2Line2Tool& tool) const;
		const DistanceResult GetSquaredWithClosestPointsIsRhs(const DistanceLine2Line2Tool& tool) const;
	
	private:
		Ray2 m_LhsRay;
		Ray2 m_RhsRay;
	};

	using DistanceRay2Ray2f = DistanceRay2Ray2<float>;
	using DistanceRay2Ray2d = DistanceRay2Ray2<double>;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_RAY2_RAY2_H

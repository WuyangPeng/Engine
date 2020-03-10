// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/10 15:55)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RAY3_RAY3_H
#define MATHEMATICS_DISTANCE_DISTANCE_RAY3_RAY3_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Ray3.h"

namespace Mathematics
{
	template <typename Real>
	class Vector3DTools;

	template <typename Real>
	class DistanceLine3Line3Tool;

	template <typename Real>
	class DistanceRay3Ray3 : public DistanceBase<Real, Vector3D<Real> >
	{
	public:
		using ClassType = DistanceRay3Ray3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Ray3 = Ray3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceLine3Line3Tool = DistanceLine3Line3Tool<Real>;
		using DistanceResult = typename ParentType::DistanceResult;
		using ParentType::GetZeroThreshold;
		using Math = Math<Real>;

	public:
		DistanceRay3Ray3(const Ray3& lhsRay, const Ray3& rhsRay);
		virtual ~DistanceRay3Ray3();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Ray3 GetLhsRay() const;
		const Ray3 GetRhsRay() const;

		// ��̬�����ѯ��
		virtual const DistanceResult GetSquared() const override;

		// �������㶯̬�����ѯ��	
		virtual const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity,const Vector3D& rhsVelocity) const override;

	private:
		const DistanceResult GetSquaredWithClosestPointsIsOrigin(const DistanceLine3Line3Tool& tool) const;
		const DistanceResult GetSquaredWithClosestPointsIsLhs(const DistanceLine3Line3Tool& tool) const;
		const DistanceResult GetSquaredWithClosestPointsIsRhs(const DistanceLine3Line3Tool& tool) const;
	
	private:
		Ray3 m_LhsRay;
		Ray3 m_RhsRay;
	};

	using DistanceRay3Ray3f = DistanceRay3Ray3<float>;
	using DistanceRay3Ray3d = DistanceRay3Ray3<double>;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_RAY3_RAY3_H


 
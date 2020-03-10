// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/10 15:19)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_CIRCLE3_CIRCLE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_CIRCLE3_CIRCLE3_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Circle3.h"
 
namespace Mathematics
{
	template <typename Real>
	class Vector3DTools;

	template <typename Real>
	class DistanceCircle3Circle3 : public DistanceBase<Real, Vector3D<Real> >
	{
	public:
		using ClassType = DistanceCircle3Circle3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Circle3 = Circle3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult;
		using ParentType::GetZeroThreshold;
		using Math = Math<Real>;

	public:
		DistanceCircle3Circle3(const Circle3& lhsCircle, const Circle3& rhsCircle);
		virtual ~DistanceCircle3Circle3();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Circle3 GetLhsCircle() const;
		const Circle3 GetRhsCircle() const;

		// ��̬�����ѯ��
		virtual const DistanceResult GetSquared() const override;

		// �������㶯̬�����ѯ��	
		virtual const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity,const Vector3D& rhsVelocity) const override;

	private:
		Circle3 m_LhsCircle;
		Circle3 m_RhsCircle;
	};

	using DistanceCircle3Circle3f = DistanceCircle3Circle3<float>;
	using DistanceCircle3Circle3d = DistanceCircle3Circle3<double>;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_CIRCLE3_CIRCLE3_H

// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/10 15:33)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Ellipsoid3.h" 

namespace Mathematics
{
	template <typename Real>
	class Vector3DTools;

	template <typename Real>
	class DistancePoint3Ellipsoid3 : public DistanceBase<Real, Vector3D<Real>>
	{
	public:		 
		using ClassType = DistancePoint3Ellipsoid3<Real>;
		using Vector3D = Vector3D<Real>;
		using Ellipsoid3 = Ellipsoid3<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult;
		using ParentType::GetZeroThreshold;

	public:
		DistancePoint3Ellipsoid3(const Vector3D& point,const Ellipsoid3& ellipsoid);
		virtual ~DistancePoint3Ellipsoid3();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Vector3D GetPoint() const;
		const Ellipsoid3 GetEllipsoid() const;
  
		// ��̬�����ѯ��
		virtual const DistanceResult GetSquared() const override;

		// �������㶯̬�����ѯ��	
		virtual const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity,const Vector3D& rhsVelocity) const override;
		
	private:
		Vector3D m_Point;
		Ellipsoid3 m_Ellipsoid;
	};

	using DistancePoint3Ellipsoid3f = DistancePoint3Ellipsoid3<float>;
	using DistancePoint3Ellipsoid3d = DistancePoint3Ellipsoid3<double>;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_H

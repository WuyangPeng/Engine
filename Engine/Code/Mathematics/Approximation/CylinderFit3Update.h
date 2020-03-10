// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/10 11:07)

#ifndef MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_H
#define MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_H

#include "Mathematics/MathematicsDll.h"

#include "CylinderFit3UpdateData.h"
#include "Mathematics/Base/Math.h"
#include "Mathematics/Algebra/Vector3D.h"

#include <vector>

namespace Mathematics
{
	template <typename Real>
	class CylinderFit3Update
	{
	public:
		using ClassType = CylinderFit3Update<Real>;
		using Vector3D = Vector3D<Real>;
		using Points = std::vector<Vector3D>;
		using CylinderFit3UpdateData = CylinderFit3UpdateData<Real>;
		using UpdateData = std::vector<CylinderFit3UpdateData>;
		using Math = Math<Real>;

	public:
		CylinderFit3Update(const Points& points, const Vector3D& guessCenter,const Vector3D& guessAxis,const Real epsilon = Math::sm_ZeroTolerance);

		CLASS_INVARIANT_DECLARE;

		void Update(int maxLoopTime);
		
		// 返回准确度
		Real GetExactly() const;
		
		Real GetInverseRadiusSqrare() const;
		const Vector3D GetAxis() const;
		const Vector3D GetCenter() const;

	private:
		void CalculateUpdateData();
		void UpdateInverseRadiusSqrare ();
		void UpdateDirection ();
		void UpdateCenter ();

	private:	
		Points m_Points;		
		Real m_InverseRadiusSqrare;
		Vector3D m_Axis;
		Vector3D m_Center;			
		Real m_Exactly;	
		Real m_Epsilon;		
		UpdateData m_UpdateData;
	};
}

#endif // MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_H	

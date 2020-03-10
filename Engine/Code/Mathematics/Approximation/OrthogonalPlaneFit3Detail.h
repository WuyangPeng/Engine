// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/10 13:21)

#ifndef MATHEMATICS_APPROXIMATION_ORTHOGONAL_PLANE_FIT3_DETAIL_H
#define MATHEMATICS_APPROXIMATION_ORTHOGONAL_PLANE_FIT3_DETAIL_H

#include "OrthogonalPlaneFit3.h"
#include "Mathematics/NumericalAnalysis/EigenDecompositionDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <boost/numeric/conversion/cast.hpp>

template <typename Real>
Mathematics::OrthogonalPlaneFit3<Real>
	::OrthogonalPlaneFit3(const std::vector<Vector3D>& points)
	:m_Plane3{ Calculate(points) }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}
#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::OrthogonalPlaneFit3<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT	

template <typename Real>
typename Mathematics::OrthogonalPlaneFit3<Real>::Plane3 Mathematics::OrthogonalPlaneFit3<Real>
	::GetPlane3() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Plane3;
}

template <typename Real>
typename Mathematics::OrthogonalPlaneFit3<Real>::Plane3 Mathematics::OrthogonalPlaneFit3<Real>
	::Calculate(const std::vector<Vector3D>& points)
{
	// ������ƽ��ֵ��
    Vector3D origin;
	auto numPoints = points.size();
	for (auto i = 0u; i < numPoints; i++)
    {
        origin += points[i];
    }
   
	origin /= boost::numeric_cast<Real>(numPoints);

	// �����Ʒ�ܺ�
	Real sumXX { };
	Real sumXY { };
	Real sumXZ { };
	Real sumYY { };
	Real sumYZ { };
	Real sumZZ { };
 
    for (auto i = 0u; i < numPoints; ++i)
    {
		auto diff = points[i] - origin;
        sumXX += diff[0] * diff[0];
        sumXY += diff[0] * diff[1];
        sumXZ += diff[0] * diff[2];
        sumYY += diff[1] * diff[1];
        sumYZ += diff[1] * diff[2];
        sumZZ += diff[2] * diff[2];
    }

	sumXX /= boost::numeric_cast<Real>(numPoints);
	sumXY /= boost::numeric_cast<Real>(numPoints);
	sumXZ /= boost::numeric_cast<Real>(numPoints);
	sumYY /= boost::numeric_cast<Real>(numPoints);
	sumYZ /= boost::numeric_cast<Real>(numPoints);
	sumZZ /= boost::numeric_cast<Real>(numPoints);

    // ���� eigensolver.
	EigenDecomposition<Real> esystem{ 3 };
    esystem(0,0) = sumXX;
    esystem(0,1) = sumXY;
    esystem(0,2) = sumXZ;
    esystem(1,0) = sumXY;
    esystem(1,1) = sumYY;
    esystem(1,2) = sumYZ;
    esystem(2,0) = sumXZ;
    esystem(2,1) = sumYZ;
    esystem(2,2) = sumZZ;

	// ��������ֵ����С������ֵ��������λ�á�
    esystem.Solve(false);

    // ��ȡƽ�淨��
    auto normal = esystem.GetEigenvector3(2);

    // ��С����
	return Plane3{ normal, origin };
}

#endif  // MATHEMATICS_APPROXIMATION_ORTHOGONAL_PLANE_FIT3_DETAIL_H

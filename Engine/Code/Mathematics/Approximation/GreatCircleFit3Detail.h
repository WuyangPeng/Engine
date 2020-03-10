// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/10 13:12)

#ifndef MATHEMATICS_APPROXIMATION_GREAT_CIRCLE_FIT3_DETAIL_H
#define MATHEMATICS_APPROXIMATION_GREAT_CIRCLE_FIT3_DETAIL_H

#include "GreatCircleFit3.h"

#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/NumericalAnalysis/EigenDecompositionDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::GreatCircleFit3<Real>
	::GreatCircleFit3(const Points& points)
	:m_Normal{}
{
	Calculate(points);

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::GreatCircleFit3<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::GreatCircleFit3<Real>::Vector3D Mathematics::GreatCircleFit3<Real>
	::GetNormal()
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Normal;
}


template <typename Real>
void Mathematics::GreatCircleFit3<Real>
	::Calculate(const Points& points)
{
	// ����������Э�������
	Real sumXX { };
	Real sumXY { };
	Real sumXZ { };
	Real sumYY { };
	Real sumYZ { };
	Real sumZZ { };
	auto numPoints = points.size();

	for(const auto& point: points)
    {
		auto diff = point;

        sumXX += diff[0] * diff[0];
        sumXY += diff[0] * diff[1];
        sumXZ += diff[0] * diff[2];
        sumYY += diff[1] * diff[1];
        sumYZ += diff[1] * diff[2];
        sumZZ += diff[2] * diff[2];
    }
	 
	sumXX /= numPoints;
	sumXY /= numPoints;
	sumXZ /= numPoints;
	sumYY /= numPoints;
	sumYZ /= numPoints;
	sumZZ /= numPoints;

    // ���� eigensolver.
	EigenDecomposition<Real> eigenSystem{ 3 };
    eigenSystem(0,0) = sumXX;
    eigenSystem(0,1) = sumXY;
    eigenSystem(0,2) = sumXZ;
    eigenSystem(1,0) = eigenSystem(0,1);
    eigenSystem(1,1) = sumYY;
    eigenSystem(1,2) = sumYZ;
    eigenSystem(2,0) = eigenSystem(0,2);
    eigenSystem(2,1) = eigenSystem(1,2);
    eigenSystem(2,2) = sumZZ;

	// ��������ֵ����С������ֵ��������λ�á�
    eigenSystem.Solve(false);

	// �����ϴ�Բ��λ���ȷ���
	m_Normal = eigenSystem.GetEigenvector3(2);   
}

#endif // MATHEMATICS_APPROXIMATION_GREAT_CIRCLE_FIT3_DETAIL_H
 
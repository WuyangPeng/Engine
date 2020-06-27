// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/23 14:15)

#ifndef MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT3_DETAIL_H
#define MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT3_DETAIL_H

#include "OrthogonalLineFit3.h"
#include "Mathematics/NumericalAnalysis/LinearSystem.h" 
#include "Mathematics/NumericalAnalysis/EigenDecompositionDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h" 

#include "System/Helper/PragmaWarning/NumericCast.h"

template <typename Real>
Mathematics::OrthogonalLineFit3<Real>
	::OrthogonalLineFit3(const std::vector<Vector3D>& points)
	:m_Line{ Calculate(points) }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::OrthogonalLineFit3<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename Mathematics::OrthogonalLineFit3<Real>::Line3 Mathematics::OrthogonalLineFit3<Real>
	::GetLine3() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Line;
}

// static
template <typename Real>
typename Mathematics::OrthogonalLineFit3<Real>::Line3  Mathematics::OrthogonalLineFit3<Real>
	::Calculate(const std::vector<Vector3D>& points)
{
	// ������ƽ��ֵ��
	Vector3D origin;
	for (const auto& point : points)
	{
		origin += point;
	}

	origin /= boost::numeric_cast<Real>(points.size());

	// ������Э�������
	auto sumXX = Math::sm_Zero;
	auto sumXY = Math::sm_Zero;
	auto sumXZ = Math::sm_Zero;
	auto sumYY = Math::sm_Zero;
	auto sumYZ = Math::sm_Zero;
	auto sumZZ = Math::sm_Zero;

	for (const auto& point : points)
	{
		auto diff = point - origin;
		sumXX += diff[0] * diff[0];
		sumXY += diff[0] * diff[1];
		sumXZ += diff[0] * diff[2];
		sumYY += diff[1] * diff[1];
		sumYZ += diff[1] * diff[2];
		sumZZ += diff[2] * diff[2];
	}

	sumXX /= boost::numeric_cast<Real>(points.size());
	sumXY /= boost::numeric_cast<Real>(points.size());
	sumXZ /= boost::numeric_cast<Real>(points.size());
	sumYY /= boost::numeric_cast<Real>(points.size());
	sumYZ /= boost::numeric_cast<Real>(points.size());
	sumZZ /= boost::numeric_cast<Real>(points.size());

	// ���� eigensolver.
	EigenDecomposition<Real> eigenSystem{ 3 };
	eigenSystem(0, 0) = sumYY + sumZZ;
	eigenSystem(0, 1) = -sumXY;
	eigenSystem(0, 2) = -sumXZ;
	eigenSystem(1, 0) = eigenSystem(0, 1);
	eigenSystem(1, 1) = sumXX + sumZZ;
	eigenSystem(1, 2) = -sumYZ;
	eigenSystem(2, 0) = eigenSystem(0, 2);
	eigenSystem(2, 1) = eigenSystem(1, 2);
	eigenSystem(2, 2) = sumXX + sumYY;

	// ��������ֵ����С��������������λ�á�
	eigenSystem.Solve(false);

	// �����������ߵĵ�λ���ȷ���
	auto direction = eigenSystem.GetEigenvector3(2);

	return Line3{ origin, direction };
}

#endif // MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT3_DETAIL_H

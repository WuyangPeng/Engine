// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/23 14:11)

#ifndef MATHEMATICS_APPROXIMATION_HEIGHT_PLANE_FIT3_DETAIL_H
#define MATHEMATICS_APPROXIMATION_HEIGHT_PLANE_FIT3_DETAIL_H

#include "HeightPlaneFit3.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/LinearSystem.h"

template <typename Real>
Mathematics::HeightPlaneFit3<Real>
	::HeightPlaneFit3(const std::vector<Vector3D>& points)
	:m_CoeffA{}, m_CoeffB{}, m_CoeffC{}, m_IsFit3Success{ false }
{
	Calculate(points);

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::HeightPlaneFit3<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::HeightPlaneFit3<Real>
	::IsFit3Success() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_IsFit3Success;
}

template <typename Real>
Real Mathematics::HeightPlaneFit3<Real>
	::GetCoeffA() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	if (m_IsFit3Success)
	{
		return m_CoeffA;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("拟合失败！"));
	}
}

template <typename Real>
Real Mathematics::HeightPlaneFit3<Real>
	::GetCoeffB() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	if (m_IsFit3Success)
	{
		return m_CoeffB;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("拟合失败！"));
	}
}

template <typename Real>
Real Mathematics::HeightPlaneFit3<Real>
	::GetCoeffC() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	if (m_IsFit3Success)
	{
		return m_CoeffC;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("拟合失败！"));
	}
}

template <typename Real>
void Mathematics::HeightPlaneFit3<Real>
	::Calculate(const std::vector<Vector3D>& points)
{
	// 您至少需要三个点来确定的平面。
	// 即使这样，如果点是在一个垂直平面，没有最小二次方拟合的“高度”的感觉。
	// 这将受限于系数矩阵的行列式。

	// 计算线性系统的总和。
	try
	{
		auto sumX = Math::sm_Zero;
		auto sumY = Math::sm_Zero;
		auto sumZ = Math::sm_Zero;
		auto sumXX = Math::sm_Zero;
		auto sumXY = Math::sm_Zero;
		auto sumXZ = Math::sm_Zero;
		auto sumYY = Math::sm_Zero;
		auto sumYZ = Math::sm_Zero;

		auto numPoints = points.size();

		for (auto i = 0u; i < numPoints; ++i)
		{
			sumX += points[i][0];
			sumY += points[i][1];
			sumZ += points[i][2];
			sumXX += points[i][0] * points[i][0];
			sumXY += points[i][0] * points[i][1];
			sumXZ += points[i][0] * points[i][2];
			sumYY += points[i][1] * points[i][1];
			sumYZ += points[i][1] * points[i][2];
		}

		Real matrix[3][3]
		{
			{ sumXX, sumXY, sumX },
			{ sumXY, sumYY, sumY },
			{ sumX, sumY, static_cast<Real>(numPoints) }
		};

		Real input[3]
		{
			sumXZ,
			sumYZ,
			sumZ
		};

		Real output[3]{};

		LinearSystem<Real>{}.Solve3(matrix, input, output);

		m_CoeffA = output[0];
		m_CoeffB = output[1];
		m_CoeffC = output[2];

		m_IsFit3Success = true;
	}
	catch (CoreTools::Error&)
	{
		m_IsFit3Success = false;
	}
}

#endif // MATHEMATICS_APPROXIMATION_HEIGHT_PLANE_FIT3_DETAIL_H

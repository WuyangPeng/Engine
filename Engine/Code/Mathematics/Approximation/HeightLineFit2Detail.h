// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/23 14:09)

#ifndef MATHEMATICS_APPROXIMATION_HEIGHT_LINT_FIT2_DETAIL_H
#define MATHEMATICS_APPROXIMATION_HEIGHT_LINT_FIT2_DETAIL_H

#include "HeightLineFit2.h"
#include "Mathematics/NumericalAnalysis/LinearSystem.h" 
#include "Mathematics/NumericalAnalysis/EigenDecompositionDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::HeightLineFit2<Real>
	::HeightLineFit2(const std::vector<Vector2D>& points)
	:m_CoeffA{}, m_CoeffB{}, m_IsFit2Success{ false }
{
	Calculate(points);

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
void Mathematics::HeightLineFit2<Real>
	::Calculate(const std::vector<Vector2D>& points)
{
	// ��������Ҫ������ȷ���߾�����
	// ��ʹ�������������һ����ֱ�ߣ�û����Сƽ����ϵġ��߶ȡ��ĸо���
	// �⽫������ϵ��������ڣ��������������ʽ��

	// ��������ϵͳ���ܺ͡�
	auto sumX = Math::sm_Zero;
	auto sumY = Math::sm_Zero;
	auto sumXX = Math::sm_Zero;
	auto sumXY = Math::sm_Zero;

	auto numPoints = points.size();
	for (auto i = 0u; i < numPoints; ++i)
	{
		sumX += points[i].GetXCoordinate();
		sumY += points[i].GetYCoordinate();
		sumXX += points[i].GetXCoordinate() * points[i].GetXCoordinate();
		sumXY += points[i].GetXCoordinate() * points[i].GetYCoordinate();
	}

	Real matrix[2][2]
	{
		{ sumXX, sumX },
		{ sumX, static_cast<Real>(numPoints) }
	};

	Real inputVector[2]
	{
		sumXY,
		sumY
	};

	try
	{
		Real outputVector[2]{};

		LinearSystem<Real> linearSystem;

		linearSystem.Solve2(matrix, inputVector, outputVector);

		m_CoeffA = outputVector[0];
		m_CoeffB = outputVector[1];
		m_IsFit2Success = true;
	}
	catch (CoreTools::Error&)
	{
		m_IsFit2Success = false;
	}
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::HeightLineFit2<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::HeightLineFit2<Real>
	::IsFit2Success() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_IsFit2Success;
}

template <typename Real>
Real Mathematics::HeightLineFit2<Real>
	::GetCoeffA() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	if (IsFit2Success())
	{
		return m_CoeffA;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("���ʧ��"));
	}
}

template <typename Real>
Real Mathematics::HeightLineFit2<Real>
	::GetCoeffB() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	if (IsFit2Success())
	{
		return m_CoeffB;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("���ʧ��"));
	}
}

#endif // MATHEMATICS_APPROXIMATION_HEIGHT_LINT_FIT2_DETAIL_H
// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/23 14:21)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_DETAIL_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_DETAIL_H

#include "PolynomialFit3.h"
#include "PolynomialSamplesPowerDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/NumericalAnalysis/LinearSystemDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::PolynomialFit3<Real>
	::PolynomialFit3(const Samples& xSamples, const Samples& ySamples, const Samples& wSamples, size_t xDegree, size_t yDegree)
	:m_Coeff((xDegree + 1) * (yDegree + 1)), m_SolveSucceed{ false }
{
	Calculate(xSamples, ySamples, wSamples,boost::numeric_cast<int>(xDegree), boost::numeric_cast<int>(yDegree));

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

// private
template <typename Real>
void Mathematics::PolynomialFit3<Real>
	::Calculate(const Samples& xSamples, const Samples& ySamples, const Samples& wSamples, int xDegree, int yDegree)
{
	MATHEMATICS_ASSERTION_2(xSamples.size() == ySamples.size(), "传入的样品大小不同！\n");
	MATHEMATICS_ASSERTION_2(xSamples.size() == wSamples.size(), "传入的样品大小不同！\n");

	auto xBound = xDegree + 1;
	auto yBound = yDegree + 1;
	auto quantity = xBound * yBound;

	// x、y的幂。
	PolynomialSamplesPower<Real> xPower{ xSamples, xDegree };
	PolynomialSamplesPower<Real> yPower{ ySamples, yDegree };

	// Vandermonde矩阵和右手坐标系的线性系统。
	VariableMatrix<Real> matrix{ quantity, quantity };
	std::vector<Real> inputVector(quantity);

	auto numSamples = wSamples.size();

	for (auto yDegreeIndex = 0; yDegreeIndex <= yDegree; ++yDegreeIndex)
	{
		for (auto xDegreeIndex = 0; xDegreeIndex <= xDegree; ++xDegreeIndex)
		{
			auto index = xDegreeIndex + xBound * yDegreeIndex;
			inputVector[index] = Math<Real>::GetValue(0);
			for (auto samplesIndex = 0u; samplesIndex < numSamples; ++samplesIndex)
			{
				inputVector[index] += wSamples[samplesIndex] * xPower(samplesIndex, xDegreeIndex) * yPower(samplesIndex, yDegreeIndex);
			}

			for (auto innerYDegreeIndex = 0; innerYDegreeIndex <= yDegree; ++innerYDegreeIndex)
			{
				for (auto innerXDegreeIndex = 0; innerXDegreeIndex <= xDegree; ++innerXDegreeIndex)
				{
					auto innerIndex = innerXDegreeIndex + xBound * innerYDegreeIndex;
					matrix(index, innerIndex) = Math<Real>::GetValue(0);
					for (auto samplesIndex = 0u; samplesIndex < numSamples; ++samplesIndex)
					{
						matrix(index, innerIndex) += xPower(samplesIndex, xDegreeIndex + innerXDegreeIndex) * yPower(samplesIndex, yDegreeIndex + innerYDegreeIndex);
					}
				}
			}
		}
	}

	try
	{
		// 求解多项式系数。
		LinearSystem<Real> linearSystem;

		linearSystem.Solve(matrix, &inputVector[0], &m_Coeff[0]);

		m_SolveSucceed = true;
	}
	catch (CoreTools::Error& error)
	{
		m_SolveSucceed = false;

		LOG_SINGLETON_ENGINE_APPENDER(Info, CoreTools)
			<< SYSTEM_TEXT("求解线性系统失败\n")
			<< error
			<< CoreTools::LogAppenderIOManageSign::Refresh;
	}
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::PolynomialFit3<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
const std::vector<Real> Mathematics::PolynomialFit3<Real>
	::GetCoeff() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Coeff;
}

template <typename Real>
bool Mathematics::PolynomialFit3<Real>
	::IsSolveSucceed() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SolveSucceed;
}

#endif // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_DETAIL_H

// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/10 13:33)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT4_DETAIL_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT4_DETAIL_H

#include "PolynomialFit4.h"
#include "PolynomialSamplesPowerDetail.h" 
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/NumericalAnalysis/LinearSystemDetail.h"

template <typename Real>
Mathematics::PolynomialFit4<Real>
	::PolynomialFit4(const Samples& xSamples, const Samples& ySamples, const Samples& zSamples,
			         const Samples& wSamples, int xDegree, int yDegree, int zDegree)
	:m_Coeff((xDegree + 1) * (yDegree + 1) * (zDegree + 1)), m_SolveSucceed{ false }
{
	Calculate(xSamples, ySamples, zSamples, wSamples, xDegree, yDegree, zDegree);

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}


template <typename Real>
void Mathematics::PolynomialFit4<Real>
	::Calculate(const Samples& xSamples, const Samples& ySamples, const Samples& zSamples, 
	            const Samples& wSamples, int xDegree, int yDegree, int zDegree)
{
	auto xBound = xDegree + 1;
	auto yBound = yDegree + 1;
	auto zBound = zDegree + 1;
	auto quantity = xBound * yBound * zBound;

	// x、y、z的幂。
	PolynomialSamplesPower<Real> xPower{ xSamples, xDegree };
	PolynomialSamplesPower<Real> yPower{ ySamples, yDegree };
	PolynomialSamplesPower<Real> zPower{ zSamples, zDegree };

	// Vandermonde矩阵和右手坐标系的线性系统。
	VariableMatrix<Real> matrix{ quantity, quantity };
	std::vector<Real> inputVector(quantity);

	auto numSamples = wSamples.size();

    for (auto zDegreeIndex = 0; zDegreeIndex <= zDegree; ++zDegreeIndex)
    {
		for (auto yDegreeIndex = 0; yDegreeIndex <= yDegree; ++yDegreeIndex)
        {
			for (auto xDegreeIndex = 0; xDegreeIndex <= xDegree; ++xDegreeIndex)
            {
				auto index = xDegreeIndex + xBound * (yDegreeIndex + yBound * zDegreeIndex);
				inputVector[index] = Real{ };
                for (auto samplesIndex = 0u; samplesIndex < numSamples; ++samplesIndex)
                {
					inputVector[index] += wSamples[samplesIndex] *  xPower(samplesIndex,xDegreeIndex) *  yPower(samplesIndex, yDegreeIndex) * zPower(samplesIndex, zDegreeIndex);
                } 

                for (auto innerZDegreeIndex = 0; innerZDegreeIndex <= zDegree; ++innerZDegreeIndex)
                {
					for (auto innerYDegreeIndex = 0; innerYDegreeIndex <= yDegree; ++innerYDegreeIndex)
                    {
						for (auto innerXDegreeIndex = 0; innerXDegreeIndex <= xDegree; ++innerXDegreeIndex)
                        {
							auto innerIndex = innerXDegreeIndex + xBound * (innerYDegreeIndex + yBound * innerZDegreeIndex);
							Real sum { };
                            for (auto samplesIndex = 0u; samplesIndex < numSamples; ++samplesIndex)
                            {
								sum += xPower(samplesIndex, xDegreeIndex + innerXDegreeIndex) *
									   yPower(samplesIndex,yDegreeIndex + innerYDegreeIndex) *
									   zPower(samplesIndex, zDegreeIndex + innerZDegreeIndex);
                            }

							matrix(index, innerIndex) = sum;
                        }
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
bool Mathematics::PolynomialFit4<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
const std::vector<Real> Mathematics::PolynomialFit4<Real>
	::GetCoeff() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Coeff;
}

template <typename Real>
bool Mathematics::PolynomialFit4<Real>
	::IsSolveSucceed() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SolveSucceed;
}

#endif // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT4_DETAIL_H


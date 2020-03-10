// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/10 13:23)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_DETAIL_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_DETAIL_H

#include "PolynomialFit2.h"
#include "PolynomialSamplesPowerDetail.h" 
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/NumericalAnalysis/LinearSystemDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::PolynomialFit2<Real>
	::PolynomialFit2(const Samples& xSamples, const Samples& wSamples, int degree)
	:m_Coeff{ degree }, m_SolveSucceed{ false }
{
	Calculate(xSamples, wSamples);

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

// private
template <typename Real>
void Mathematics::PolynomialFit2<Real>
	::Calculate(const Samples& xSamples, const Samples& wSamples)
{
	MATHEMATICS_ASSERTION_2(xSamples.size() == wSamples.size(), "传入的样品大小不同！\n");

	auto degree = m_Coeff.GetDegree();
	auto quantity = degree + 1;
	auto numSamples = wSamples.size();
	
    // x的幂。
	PolynomialSamplesPower<Real> power{ xSamples, degree };

	// Vandermonde矩阵和右手坐标系的线性系统。
	VariableMatrix<Real> matrix{ quantity, quantity };
	std::vector<Real> inputVector(quantity);

	for (auto degreeIndex = 0; degreeIndex <= degree; ++degreeIndex)
    {    
		inputVector[degreeIndex] = Real{ };
		for (auto samplesIndex = 0u; samplesIndex < numSamples; ++samplesIndex)
        {
			inputVector[degreeIndex] += wSamples[samplesIndex] * power(samplesIndex,degreeIndex);
        }

		for (auto innerIndex = 0; innerIndex <= degree; ++innerIndex)
        {
			matrix(degreeIndex, innerIndex) = Real{ };
			for (auto samplesIndex = 0u; samplesIndex < numSamples; ++samplesIndex)
            {
				matrix(degreeIndex, innerIndex) += power(samplesIndex, degreeIndex + innerIndex);
            }			 
        }
    }
	    
	try
	{
		// 求解多项式系数。
		std::vector<Real> outputVector(quantity);

		LinearSystem<Real> linearSystem;

		linearSystem.Solve(matrix, &inputVector[0], &outputVector[0]);

		m_Coeff = Polynomial{ outputVector };
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
bool Mathematics::PolynomialFit2<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::PolynomialFit2<Real>::Polynomial Mathematics::PolynomialFit2<Real>
	::GetCoeff() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Coeff;
}


template <typename Real>
bool Mathematics::PolynomialFit2<Real>
	::IsSolveSucceed() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SolveSucceed;
}


#endif // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_DETAIL_H
 
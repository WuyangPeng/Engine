// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/10 13:24)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_DETAIL_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_DETAIL_H

#include "PolynomialFit2Powers.h"
#include "PolynomialFitPowersDataDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h" 

#include <boost/numeric/conversion/cast.hpp>
#include <algorithm>

template <typename Real>
Mathematics::PolynomialFit2Powers<Real>
	::PolynomialFit2Powers(const Samples& xSamples, const Samples& wSamples, const Powers& powers)
	:m_Powers{ powers }, m_PowersData{ boost::numeric_cast<int>(m_Powers.size()) }
{
	Init(xSamples, wSamples);

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

// private
template <typename Real>
void Mathematics::PolynomialFit2Powers<Real>
	::Init(const Samples& xSamples, const Samples& wSamples)
{
	InitializePowers();

	Samples xTargetSamples;
	Samples wTargetSamples;
	TransformToUnit(xSamples, wSamples, xTargetSamples, wTargetSamples);
	DoLeastSquaresFit(xTargetSamples, wTargetSamples);	
}

// private
template <typename Real>
void Mathematics::PolynomialFit2Powers<Real>
	::InitializePowers()
{
	// 确定最大的幂功率。x的幂构造的多项式拟合计算两倍的幂。
	// x的幂计算可为拟合的多项式的评定的幂。
	auto maxXPowerConstIter = std::max_element(m_Powers.begin(), m_Powers.end());
 
	m_PowersData.SetMaxPower(0,*maxXPowerConstIter);
}

// private
template <typename Real>
void Mathematics::PolynomialFit2Powers<Real>
	::TransformToUnit(const Samples& xSourceSamples, const Samples& wSourceSamples, Samples& xTargetSamples, Samples& wTargetSamples)
{	
	// 为数值鲁棒性转换数据为 [-1,1]^2。
	TransformToUnit(xSourceSamples, xTargetSamples, 0);
	TransformToUnit(wSourceSamples, wTargetSamples, 1);
}

template <typename Real>
void Mathematics::PolynomialFit2Powers<Real>
	::TransformToUnit(const Samples& sourceSamples, Samples& targetSamples, int index)
{
	auto result = std::minmax_element(sourceSamples.begin(), sourceSamples.end());

	auto scale = static_cast<Real>(1) / (*result.second - *result.first);
	m_PowersData.SetScale(index, scale);

	for(auto sample:sourceSamples)
	{
		auto newSample = static_cast<Real>(-1) + static_cast<Real>(2) * (sample - *result.first) * scale;
		targetSamples.push_back(newSample);
	}
}

template <typename Real>
void Mathematics::PolynomialFit2Powers<Real>
	::DoLeastSquaresFit(const Samples& xTargetSamples, const Samples& wTargetSamples)
{
	MATHEMATICS_ASSERTION_2(xTargetSamples.size() == wTargetSamples.size(),"样品点数组大小不同\n");

	auto maxXPower = m_PowersData.GetMaxPower(0);
	std::vector<Real> xPowers(2 * maxXPower + 1);
	xPowers[0] = static_cast<Real>(1);

	auto numPowers = m_Powers.size();
	
	// 对于确定的拟合多项式的系数的线性系统的矩阵和矢量。
	VariableMatrix<Real> matrix{ boost::numeric_cast<int>(numPowers), boost::numeric_cast<int>(numPowers) };
	VariableLengthVector<Real> vector{ boost::numeric_cast<int>(numPowers) };

	auto numSamples = wTargetSamples.size();
  
    for (auto samplesIndex = 0u; samplesIndex < numSamples; ++samplesIndex)
    {
        // 计算x的有关幂
		auto x = xTargetSamples[samplesIndex];
		auto w = wTargetSamples[samplesIndex];
		for (auto powersIndex = 1; powersIndex <= 2 * maxXPower; ++powersIndex)
        {
			xPowers[powersIndex] = xPowers[powersIndex - 1] * x;
        }

		for (auto row = 0u; row < numPowers; ++row)
        {
			// 更新对称矩阵的上三角部分。
         	for (auto colomn = row; colomn < numPowers; ++colomn)
            {
				auto xp = xPowers[m_Powers[row] + m_Powers[colomn]];
                matrix(row,colomn) += xp;
            }

      		// 更新系统在右手坐标系。
			auto xp = xPowers[m_Powers[row]];
            vector[row] += xp * w;
        }
    }  

	// 对和进行正则化
	matrix /= boost::numeric_cast<Real>(numSamples);
	vector /= boost::numeric_cast<Real>(numSamples);

	m_PowersData.Solve(matrix, vector); 
}

template <typename Real>
Mathematics::PolynomialFit2Powers<Real>
	::~PolynomialFit2Powers()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::PolynomialFit2Powers<Real>
	::IsValid() const noexcept
{
	return true;
}

#endif // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::PolynomialFit2Powers<Real>
	::IsSolveSucceed() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_PowersData.IsSolveSucceed();
}


template <typename Real>
Real Mathematics::PolynomialFit2Powers<Real>
	::GetXMin() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_PowersData.GetMin(0);
}

template <typename Real>
Real Mathematics::PolynomialFit2Powers<Real>
	::GetXMax() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_PowersData.GetMax(0);
}

template <typename Real>
Real Mathematics::PolynomialFit2Powers<Real>
	::GetWMin() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_PowersData.GetMin(1);
}

template <typename Real>
Real Mathematics::PolynomialFit2Powers<Real>
	::GetWMax() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_PowersData.GetMax(1);
}

template <typename Real>
Real  Mathematics::PolynomialFit2Powers<Real>
	::operator()(Real x) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	auto maxXPower = m_PowersData.GetMaxPower(0);
	std::vector<Real> xPowers(maxXPower + 1);
	xPowers[0] = static_cast<Real>(1);

	// 变换x从原来的空间到[-1,1]。
	x = static_cast<Real>(-1) + (static_cast<Real>(2) * (x - m_PowersData.GetMin(0)) *  m_PowersData.GetScale(0));

	// 计算x的有关幂
	for (auto power = 1; power <= maxXPower; ++power)
	{
		xPowers[power] = xPowers[power - 1] * x;
	}

	Real w { };
	for (auto i = 0u; i < m_Powers.size(); ++i)
	{
		auto xp = xPowers[m_Powers[i]];
		w += m_PowersData.GetCoefficients(i) * xp;
	}

	// 变换w从[-1,1]回到原来的空间。
	w = (w + static_cast<Real>(1)) * m_PowersData.GetInvTwoWScale() + m_PowersData.GetMin(1);

	return w;
}

#endif // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_DETAIL_H

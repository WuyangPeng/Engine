// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/10 13:24)

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
	// ȷ�������ݹ��ʡ�x���ݹ���Ķ���ʽ��ϼ����������ݡ�
	// x���ݼ����Ϊ��ϵĶ���ʽ���������ݡ�
	auto maxXPowerConstIter = std::max_element(m_Powers.begin(), m_Powers.end());
 
	m_PowersData.SetMaxPower(0,*maxXPowerConstIter);
}

// private
template <typename Real>
void Mathematics::PolynomialFit2Powers<Real>
	::TransformToUnit(const Samples& xSourceSamples, const Samples& wSourceSamples, Samples& xTargetSamples, Samples& wTargetSamples)
{	
	// Ϊ��ֵ³����ת������Ϊ [-1,1]^2��
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
	MATHEMATICS_ASSERTION_2(xTargetSamples.size() == wTargetSamples.size(),"��Ʒ�������С��ͬ\n");

	auto maxXPower = m_PowersData.GetMaxPower(0);
	std::vector<Real> xPowers(2 * maxXPower + 1);
	xPowers[0] = static_cast<Real>(1);

	auto numPowers = m_Powers.size();
	
	// ����ȷ������϶���ʽ��ϵ��������ϵͳ�ľ����ʸ����
	VariableMatrix<Real> matrix{ boost::numeric_cast<int>(numPowers), boost::numeric_cast<int>(numPowers) };
	VariableLengthVector<Real> vector{ boost::numeric_cast<int>(numPowers) };

	auto numSamples = wTargetSamples.size();
  
    for (auto samplesIndex = 0u; samplesIndex < numSamples; ++samplesIndex)
    {
        // ����x���й���
		auto x = xTargetSamples[samplesIndex];
		auto w = wTargetSamples[samplesIndex];
		for (auto powersIndex = 1; powersIndex <= 2 * maxXPower; ++powersIndex)
        {
			xPowers[powersIndex] = xPowers[powersIndex - 1] * x;
        }

		for (auto row = 0u; row < numPowers; ++row)
        {
			// ���¶Գƾ���������ǲ��֡�
         	for (auto colomn = row; colomn < numPowers; ++colomn)
            {
				auto xp = xPowers[m_Powers[row] + m_Powers[colomn]];
                matrix(row,colomn) += xp;
            }

      		// ����ϵͳ����������ϵ��
			auto xp = xPowers[m_Powers[row]];
            vector[row] += xp * w;
        }
    }  

	// �Ժͽ�������
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

	// �任x��ԭ���Ŀռ䵽[-1,1]��
	x = static_cast<Real>(-1) + (static_cast<Real>(2) * (x - m_PowersData.GetMin(0)) *  m_PowersData.GetScale(0));

	// ����x���й���
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

	// �任w��[-1,1]�ص�ԭ���Ŀռ䡣
	w = (w + static_cast<Real>(1)) * m_PowersData.GetInvTwoWScale() + m_PowersData.GetMin(1);

	return w;
}

#endif // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_DETAIL_H

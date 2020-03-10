// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/10 13:35)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT4_POWERS_DETAIL_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT4_POWERS_DETAIL_H

#include "PolynomialFit4Powers.h"
#include "PolynomialFitPowersDataDetail.h"
#include "CoreTools/DataTypes/TupleLessDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h" 

#include <boost/numeric/conversion/cast.hpp>
#include <algorithm>

template <typename Real>
Mathematics::PolynomialFit4Powers<Real>
	::PolynomialFit4Powers( const Samples& xSamples,const Samples& ySamples, 
	                        const Samples& zSamples,const Samples& wSamples, 
							const Powers& powers, bool isRepackage)
	:m_Powers(powers), m_PowersData{ boost::numeric_cast<int>(m_Powers.size()) }
{
	Init(xSamples, ySamples,  zSamples,wSamples,isRepackage);

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

// private
template <typename Real>
void Mathematics::PolynomialFit4Powers<Real>
	::Init( const Samples& xSamples,const Samples& ySamples,const Samples& zSamples,const Samples& wSamples, bool isRepackage )
{
	InitializePowers();	

	Samples xRepackage;
	Samples yRepackage;
	Samples zRepackage;

	if(isRepackage)
	{
	 
		// 重新打包输入样品 (x[i],y[i],z[i],w[i])。
		Repackage(xSamples,ySamples,zSamples,xRepackage,yRepackage,zRepackage);
	}
	else
	{
		MATHEMATICS_ASSERTION_2(xSamples.size() == ySamples.size(),"样品大小不相等\n");
		MATHEMATICS_ASSERTION_2(xSamples.size() == zSamples.size(),"样品大小不相等\n");

		xRepackage = xSamples;
		yRepackage = ySamples;
		zRepackage = zSamples;
	}

	Samples xTargetSamples;
	Samples yTargetSamples;
	Samples zTargetSamples;
	Samples wTargetSamples;	

	TransformToUnit(xRepackage,yRepackage, zRepackage,wSamples, xTargetSamples,yTargetSamples,zTargetSamples, wTargetSamples);
	DoLeastSquaresFit(xTargetSamples,yTargetSamples,zTargetSamples, wTargetSamples);	
}

// private
template <typename Real>
void Mathematics::PolynomialFit4Powers<Real>
	::InitializePowers()
{
  	// 确定最大的幂功率。x、y和z的幂构造的多项式拟合计算两倍的幂。
	// x、y和z的幂计算可为拟合的多项式的评定的幂。
	for (auto i = 0; i < 3; ++i)
	{
		auto maxPowerConstIter = std::max_element(m_Powers.begin(), m_Powers.end(), CoreTools::TupleLess<3,int>(i));

		m_PowersData.SetMaxPower(i, (*maxPowerConstIter)[i]);
	}
}

// private
template <typename Real>
void Mathematics::PolynomialFit4Powers<Real>
	::Repackage(const Samples& xSourceSamples, const Samples& ySourceSamples,
	            const Samples& zSourceSamples, Samples& xTargetSamples, 
				Samples& yTargetSamples, Samples& zTargetSamples)
{
	for (auto z = 0u; z < zSourceSamples.size(); ++z)
	{
		auto zInput = zSourceSamples[z];
		for (auto y = 0u; y < ySourceSamples.size(); ++y)
		{
			auto yInput = ySourceSamples[y];
			for (auto x = 0u; x < xSourceSamples.size(); ++x)
			{
				xTargetSamples.push_back(xSourceSamples[x]);
				yTargetSamples.push_back(yInput);
				zTargetSamples.push_back(zInput);
			}
		}
	}
}


template <typename Real>
void Mathematics::PolynomialFit4Powers<Real>
	::TransformToUnit(const Samples& xSourceSamples, const Samples& ySourceSamples, 
	                  const Samples& zSourceSamples, const Samples& wSourceSamples, 
					  Samples& xTargetSamples, Samples& yTargetSamples,
					  Samples& zTargetSamples, Samples& wTargetSamples)
{
	// 为数值鲁棒性转换数据为 [-1,1]^4。
	TransformToUnit(xSourceSamples, xTargetSamples, 0);
	TransformToUnit(ySourceSamples, yTargetSamples, 1);
	TransformToUnit(zSourceSamples, zTargetSamples, 2);
	TransformToUnit(wSourceSamples, wTargetSamples, 3);
}


template <typename Real>
void Mathematics::PolynomialFit4Powers<Real>
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
void Mathematics::PolynomialFit4Powers<Real>
	::DoLeastSquaresFit(const Samples& xTargetSamples, const Samples& yTargetSamples,
	                    const Samples& zTargetSamples, const Samples& wTargetSamples)
{
	MATHEMATICS_ASSERTION_2(xTargetSamples.size() == wTargetSamples.size(), "样品点数组大小不同\n");
	MATHEMATICS_ASSERTION_2(yTargetSamples.size() == wTargetSamples.size(), "样品点数组大小不同\n");
	MATHEMATICS_ASSERTION_2(zTargetSamples.size() == wTargetSamples.size(), "样品点数组大小不同\n");
	
	auto maxXPower = m_PowersData.GetMaxPower(0);
	std::vector<Real> xPowers(2 * maxXPower + 1);
	xPowers[0] = static_cast<Real>(1);

	auto maxYPower = m_PowersData.GetMaxPower(1);
	std::vector<Real> yPowers(2 * maxYPower + 1);
	yPowers[0] = static_cast<Real>(1);

	auto maxZPower = m_PowersData.GetMaxPower(2);
	std::vector<Real> zPowers(2 * maxZPower + 1);
	zPowers[0] = static_cast<Real>(1);

	auto numPowers = m_Powers.size();
	
	// 对于确定的拟合多项式的系数的线性系统的矩阵和矢量
	VariableMatrix<Real> matrix{ boost::numeric_cast<int>(numPowers), boost::numeric_cast<int>(numPowers) };
	VariableLengthVector<Real> vector{ boost::numeric_cast<int>(numPowers) };

	auto numSamples = wTargetSamples.size();

	for (auto samplesIndex = 0u; samplesIndex < numSamples; ++samplesIndex)
    {    
		auto x = xTargetSamples[samplesIndex];
		auto y = yTargetSamples[samplesIndex];
		auto z = zTargetSamples[samplesIndex];
		auto w = wTargetSamples[samplesIndex];

		for (auto powersIndex = 1; powersIndex <= 2 * maxXPower; ++powersIndex)
		{
			xPowers[powersIndex] = xPowers[powersIndex - 1] * x;
		}

		for (auto powersIndex = 1; powersIndex <= 2 * maxYPower; ++powersIndex)
		{
			yPowers[powersIndex] = yPowers[powersIndex - 1] * y;
		}

		for (auto powersIndex = 1; powersIndex <= 2 * maxZPower; ++powersIndex)
		{
			zPowers[powersIndex] = zPowers[powersIndex - 1] * z;
		}

		for (auto row = 0u; row < numPowers; ++row)
        {
			// 更新对称矩阵的上三角部分。
			for (auto colomn = row; colomn < numPowers; ++colomn)
			{
				auto xp = xPowers[m_Powers[row][0] + m_Powers[colomn][0]];
				auto yp = yPowers[m_Powers[row][1] + m_Powers[colomn][1]];
				auto zp = zPowers[m_Powers[row][2] + m_Powers[colomn][2]];
				matrix(row, colomn) += xp * yp * zp;
			}           

			// 更新系统在右手坐标系。
			auto xp = xPowers[m_Powers[row][0]];
			auto yp = yPowers[m_Powers[row][1]];
			auto zp = zPowers[m_Powers[row][2]];
			vector[row] += xp * yp * zp * w;
        }
    }

	// 对和进行正则化
	matrix /= boost::numeric_cast<Real>(numSamples);
	vector /= boost::numeric_cast<Real>(numSamples);

	m_PowersData.Solve(matrix, vector);
}

template <typename Real>
Mathematics::PolynomialFit4Powers<Real>
	::~PolynomialFit4Powers()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::PolynomialFit4Powers<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::PolynomialFit4Powers<Real>
	::GetXMin() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_PowersData.GetMin(0);
}

template <typename Real>
Real Mathematics::PolynomialFit4Powers<Real>
	::GetXMax() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_PowersData.GetMax(0);
}

template <typename Real>
Real Mathematics::PolynomialFit4Powers<Real>
	::GetYMin() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_PowersData.GetMin(1);
}

template <typename Real>
Real Mathematics::PolynomialFit4Powers<Real>
	::GetYMax() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_PowersData.GetMax(1);
}

template <typename Real>
Real Mathematics::PolynomialFit4Powers<Real>
	::GetZMin() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_PowersData.GetMin(2);
}

template <typename Real>
Real Mathematics::PolynomialFit4Powers<Real>
	::GetZMax() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_PowersData.GetMax(2);
}

template <typename Real>
Real Mathematics::PolynomialFit4Powers<Real>
	::GetWMin() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_PowersData.GetMin(3);
}

template <typename Real>
Real Mathematics::PolynomialFit4Powers<Real>
	::GetWMax() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_PowersData.GetMax(3);
}

template <typename Real>
Real Mathematics::PolynomialFit4Powers<Real>
	::operator()( Real x, Real y, Real z ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	auto maxXPower = m_PowersData.GetMaxPower(0);
	std::vector<Real> xPowers(maxXPower + 1);
	xPowers[0] = static_cast<Real>(1);

	auto maxYPower = m_PowersData.GetMaxPower(1);
	std::vector<Real> yPowers(maxYPower + 1);
	yPowers[0] = static_cast<Real>(1);

	auto maxZPower = m_PowersData.GetMaxPower(2);
	std::vector<Real> zPowers(maxZPower + 1);
	zPowers[0] = static_cast<Real>(1);

	// 变换(x,y,z) 从原来的空间到[-1,1]^3。
	x = static_cast<Real>(-1) + (static_cast<Real>(2) * (x - m_PowersData.GetMin(0)) *  m_PowersData.GetScale(0));
	y = static_cast<Real>(-1) + (static_cast<Real>(2) * (y - m_PowersData.GetMin(1)) *  m_PowersData.GetScale(1));
	z = static_cast<Real>(-1) + (static_cast<Real>(2) * (z - m_PowersData.GetMin(2)) *  m_PowersData.GetScale(2));

	// 计算x、y和z的有关幂
	for (auto power = 1; power <= maxXPower; ++power)
	{
		xPowers[power] = xPowers[power - 1] * x;
	}
	for (auto power = 1; power <= maxYPower; ++power)
	{
		yPowers[power] = yPowers[power - 1] * y;
	}
	for (auto power = 1; power <= maxZPower; ++power)
	{
		zPowers[power] = zPowers[power - 1] * z;
	}

	Real w { };
	for (auto i = 0u; i < m_Powers.size(); ++i)
	{
		auto xp = xPowers[m_Powers[i][0]];
		auto yp = yPowers[m_Powers[i][1]];
		auto zp = zPowers[m_Powers[i][2]];
		w += m_PowersData.GetCoefficients(i) * xp * yp * zp;
	}

	// 变换w从[-1,1]回到原来的空间。
	w = (w + static_cast<Real>(1)) * m_PowersData.GetInvTwoWScale() + m_PowersData.GetMin(3);

	return w;
}

template <typename Real>
bool Mathematics::PolynomialFit4Powers<Real>
	::IsSolveSucceed() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_PowersData.IsSolveSucceed();
}

#endif // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT4_POWERS_DETAIL_H
 
// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/10 11:17)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_POWERS_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_POWERS_H

#include "Mathematics/MathematicsDll.h"

#include "PolynomialFitPowersData.h"
#include "CoreTools/DataTypes/Tuple.h"

#include <vector>

namespace Mathematics
{
	// 与以下形式的多项式拟合数据
	//     w = sum_{i=0}^{n-1} c[i]*x^{p[i]}*y^{q[i]}
	// 这里<p[i],q[i]> 由调用者提供不同的非负的幂。
	// 将使用最小二乘拟合算法，
	// 但输入数据(x,y,w) 首先被映射到[-1,1]^3  对数值鲁棒性。
	template <typename Real>
	class PolynomialFit3Powers
	{
	public:		
		using ClassType = PolynomialFit3Powers<Real>;
		using Samples = std::vector<Real>;
		using Tuple = CoreTools::Tuple<2,int>;
		using Powers = std::vector<Tuple>;
		
	public:	
		// 构造函数是数据(x[i],y[i],w[i])，分别为0 <= i < numSamples。
		// 当isRepackage 为true时，构造函数是数据(x[i],y[j],w[k])，
		// 其中，0 <= i < numXSamples, 0 <= j < numYSamples,和 k = i + numXSamples * j
		PolynomialFit3Powers (const Samples& xSamples,const Samples& ySamples,const Samples& wSamples,const Powers& powers,bool isRepackage = false);
		virtual ~PolynomialFit3Powers();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		// 这是一个功能类，如果解线性方程组成功则返回“true”。
		// 如果不成功，则多项式求值是无效的，总是返回false。
		bool IsSolveSucceed() const;
		
		Real GetXMin () const;
		Real GetXMax () const;
		Real GetYMin () const;
		Real GetYMax () const;
		Real GetWMin () const;
		Real GetWMax () const;
		
		// 拟合多项式的的评估。
		// 派生类可以重写此实现，有效方法基于有关传递给构造函数的具体幂的知识。
		virtual Real operator() (Real x, Real y) const;
		
	private:
		void Init(const Samples& xSamples,const Samples& ySamples, const Samples& wSamples, bool isRepackage);
		void InitializePowers ();
		void Repackage(const Samples& xSourceSamples, const Samples& ySourceSamples,Samples& xTargetSamples,Samples& yTargetSamples );
		void TransformToUnit(const Samples& xSourceSamples, const Samples& ySourceSamples,const Samples& wSourceSamples, Samples& xTargetSamples,Samples& yTargetSamples, Samples& wTargetSamples);
		void TransformToUnit(const Samples& sourceSamples,Samples& targetSamples, int index);
		void DoLeastSquaresFit(const Samples& xTargetSamples, const Samples& yTargetSamples,const Samples& wTargetSamples);

	private:		
		Powers m_Powers;
		PolynomialFitPowersData<Real, 3> m_PowersData;	  
	};

	using PolynomialFit3Powersd = PolynomialFit3Powers<double>;
	using PolynomialFit3Powersf = PolynomialFit3Powers<float>;
}

#endif // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_POWERS_H

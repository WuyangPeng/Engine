// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/10 11:16)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Polynomial.h"

#include <vector>

namespace Mathematics
{
	// ��Ʒ�� (x[i],y[i],w[i]) Ϊ0 <= i < S��
	// �뵽w����Ϊx��y�ĺ�������ʾ w = f(x,y)��
	// �������Ϊxά��Ϊd0��yά��Ϊd1�Ķ���ʽ����Ʒ�У� w = sum_{i=0}^{d0} sum_{j=0}^{d1} c[i][j]*x^i*y^j
	// �÷�������С��������㷨�����ص������д洢�� c[i][j] ��ֵ��
	// ���ݷ��صĵ� (d0 + 1) * (d1 + 1)��ϵ���� 

	// ���档����㷨����ʽ��
	//   (1,x,x^2,...,x^d0), (1,y,y^2,...,y^d1)
	// ��֪�Ƕ��ڴ��ά�Ⱥʹ�ķ�ֵ�����Ƿǽ�׳��һ�����������ʹ����������ʽ
	//   (f[0](x),...,f[d0](x)), (g[0](y),...,g[d1](y))
	// ����С�����㷨��������Щ����һ�ַ����Ǹı�
	//   (x',y',w') = ((x-xcen)/rng, (y-ycen)/rng, w/rng)
	// ���� xmin = min(x[i]), xmax = max(x[i]), xcen = (xmin+xmax)/2,
	// ymin = min(y[i]), ymax = max(y[i]), ycen = (ymin+ymax)/2, ��
	// rng = max(xmax-xmin,ymax-ymin). 
	// ���(x',y',w') ��,
	//   w' = sum_{i=0}^{d0} sum_{j=0}^{d1} c'[i][j]*(x')^i*(y')^j
	// ԭʼ����ʽ����ֵΪ
	//   w = rng * sum_{i=0}^{d0} sum_{j=0}^{d1} c'[i][j] *
	//         ((x-xcen)/rng)^i * ((y-ycen)/rng)^j
	template <typename Real>
	class PolynomialFit3
	{
	public:		
		using ClassType = PolynomialFit3<Real>;
		using Samples = std::vector<Real>;
		using Polynomial = Polynomial<Real>;

	public:
		PolynomialFit3(const Samples& xSamples, const Samples& ySamples, const Samples& wSamples,int xDegree, int yDegree);

		CLASS_INVARIANT_DECLARE;

		const std::vector<Real> GetCoeff() const;
		bool IsSolveSucceed() const;

	private:
		void Calculate(const Samples& xSamples, const Samples& ySamples, const Samples& wSamples,int xDegree, int yDegree);

	private:
		std::vector<Real> m_Coeff;
		bool m_SolveSucceed;
	};

	using PolynomialFit3d = PolynomialFit3<double>;
	using PolynomialFit3f = PolynomialFit3<float>;
}

#endif // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_H

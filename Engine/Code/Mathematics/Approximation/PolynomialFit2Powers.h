// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/10 11:15)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_H

#include "Mathematics/MathematicsDll.h"

#include "PolynomialFitPowersData.h"

#include <vector>

namespace Mathematics
{
	// ��������ʽ�Ķ���ʽ�������
	//     w = sum_{i=0}^{n-1} c[i]*x^{p[i]}
	// ����p[i] �ɵ������ṩ��ͬ�ķǸ����ݡ�
	// ��ʹ����С��������㷨��
	// ����������(x,w) ���ȱ�ӳ�䵽[-1,1]^2 ����ֵ³���ԡ�
	template <typename Real>
	class PolynomialFit2Powers
	{
	public:		
		using ClassType = PolynomialFit2Powers<Real>;
		using Samples = std::vector<Real>;
		using Powers = std::vector<int>;

	public:	
		// ���캯��������(x[i],w[i])���ֱ�Ϊ0 <= i < numSamples��
		PolynomialFit2Powers(const Samples& xSamples, const Samples& wSamples, const Powers& powers);
		virtual ~PolynomialFit2Powers();

		CLASS_INVARIANT_VIRTUAL_DECLARE;
		
		// ����һ�������࣬��������Է�����ɹ��򷵻ء�true����
		// ������ɹ��������ʽ��ֵ����Ч�ģ����Ƿ���false��
		bool IsSolveSucceed() const;
		
		Real GetXMin () const;
		Real GetXMax () const;
		Real GetWMin () const;
		Real GetWMax () const;
		
		// ��϶���ʽ�ĵ�������
		// �����������д��ʵ�֣���Ч���������йش��ݸ����캯���ľ����ݵ�֪ʶ��
		virtual Real operator() (Real x) const;
		
	private:
		// ֧�ֹ���
		void Init(const Samples& xSamples, const Samples& wSamples);
		void InitializePowers ();
		void TransformToUnit(const Samples& xSourceSamples, const Samples& wSourceSamples,Samples& xTargetSamples, Samples& wTargetSamples);
		void TransformToUnit(const Samples& sourceSamples,Samples& targetSamples, int index);
		void DoLeastSquaresFit(const Samples& xTargetSamples, const Samples& wTargetSamples);

	private:
		// ���Ƶ�������ϵĶ���ʽ������ʹ�á�
		Powers m_Powers;

		PolynomialFitPowersData<Real, 2> m_PowersData;	  
	};

	using PolynomialFit2Powersd = PolynomialFit2Powers<double>;
	using PolynomialFit2Powersf = PolynomialFit2Powers<float>;
}

#endif // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_H

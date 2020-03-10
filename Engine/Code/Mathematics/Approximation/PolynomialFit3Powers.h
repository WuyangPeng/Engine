// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/10 11:17)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_POWERS_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_POWERS_H

#include "Mathematics/MathematicsDll.h"

#include "PolynomialFitPowersData.h"
#include "CoreTools/DataTypes/Tuple.h"

#include <vector>

namespace Mathematics
{
	// ��������ʽ�Ķ���ʽ�������
	//     w = sum_{i=0}^{n-1} c[i]*x^{p[i]}*y^{q[i]}
	// ����<p[i],q[i]> �ɵ������ṩ��ͬ�ķǸ����ݡ�
	// ��ʹ����С��������㷨��
	// ����������(x,y,w) ���ȱ�ӳ�䵽[-1,1]^3  ����ֵ³���ԡ�
	template <typename Real>
	class PolynomialFit3Powers
	{
	public:		
		using ClassType = PolynomialFit3Powers<Real>;
		using Samples = std::vector<Real>;
		using Tuple = CoreTools::Tuple<2,int>;
		using Powers = std::vector<Tuple>;
		
	public:	
		// ���캯��������(x[i],y[i],w[i])���ֱ�Ϊ0 <= i < numSamples��
		// ��isRepackage Ϊtrueʱ�����캯��������(x[i],y[j],w[k])��
		// ���У�0 <= i < numXSamples, 0 <= j < numYSamples,�� k = i + numXSamples * j
		PolynomialFit3Powers (const Samples& xSamples,const Samples& ySamples,const Samples& wSamples,const Powers& powers,bool isRepackage = false);
		virtual ~PolynomialFit3Powers();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		// ����һ�������࣬��������Է�����ɹ��򷵻ء�true����
		// ������ɹ��������ʽ��ֵ����Ч�ģ����Ƿ���false��
		bool IsSolveSucceed() const;
		
		Real GetXMin () const;
		Real GetXMax () const;
		Real GetYMin () const;
		Real GetYMax () const;
		Real GetWMin () const;
		Real GetWMax () const;
		
		// ��϶���ʽ�ĵ�������
		// �����������д��ʵ�֣���Ч���������йش��ݸ����캯���ľ����ݵ�֪ʶ��
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

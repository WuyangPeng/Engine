// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/18 19:10)

#ifndef MATHEMATICS_BASE_MATH_H
#define MATHEMATICS_BASE_MATH_H

#include "Mathematics/MathematicsDll.h"

#include "Flags/NumericalValueSymbol.h" 
 
namespace Mathematics
{
	template <typename Real>
	class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Math
	{
	public:
		using ClassType = Math<Real>;

	public:
		// ��װ���غ�����ʵ�֡�
		// ��ACos��ASin�����нض��������Ϊ[-1,1]���Ա��⵱����Ϊ�Դ���1����С��-1ʱ����NaN�����⡣
		// ��������ʹ�ÿ��ٽ����㷨��Ǳ���������ǵ��ñ�׼����ѧ�⺯����    

		static Real ACos(Real value) noexcept;
		static Real ASin(Real value) noexcept;
		static Real ATan(Real value) noexcept;
		static Real ATan2(Real y, Real x) noexcept;
		static Real Sin(Real value) noexcept;
		static Real Cos(Real value) noexcept;
		static Real Tan(Real value) noexcept;

		static Real Ceil(Real value) noexcept;
		static Real FAbs(Real value) noexcept;
		static Real Floor(Real value) noexcept;
		static Real FMod(Real x, Real y);
		static NumericalValueSymbol Sign(Real value) noexcept;

		static Real Log(Real value);
		static Real Log2(Real value);
		static Real Log10(Real value);

		static Real Exp(Real value);
		static Real Pow(Real base, Real exponent);
		static Real Square(Real value) noexcept;
		static Real Sqrt(Real value) ;
		static Real InvSqrt(Real value);
		static Real CubeRoot(Real value);

		// �ض�����ֵΪ�ض��ķ�Χ[min,max]
		static Real Clamp(Real value, Real minValue, Real maxValue) noexcept;

		// �ض�����ֵΪ[0,1].
		static Real Saturate(Real value) noexcept;

		static bool Approximate(Real lhs, Real rhs, const Real epsilon = Math<Real>::sm_ZeroTolerance);

		// equalDigit��Ҫ�Ƚϵ�β��λ��float���Ϊ23λ��double���Ϊ52λ��
		static bool FloatingPointEqual(Real lhs, Real rhs, int equalDigit);

		static Real GetNumericalRoundOffNonnegative(Real value) noexcept;
		static Real GetNumericalRoundOff(Real value, Real minValue, Real maxValue) noexcept;

		// ���ó�����
		static const Real sm_Epsilon;
		static const Real sm_ZeroTolerance;
		static const Real sm_MaxReal;
		static const Real sm_Exponent;
		static const Real sm_PI;
		static const Real sm_TwoPI;
		static const Real sm_HalfPI;
		static const Real sm_QuarterPI;
		static const Real sm_InversePI;
		static const Real sm_InverseTwoPI;
		static const Real sm_DegToRad;
		static const Real sm_RadToDeg;
		static const Real sm_LN2;
		static const Real sm_LN10;
		static const Real sm_InverseLN2;
		static const Real sm_InverseLN10;
		static const Real sm_Sqrt2;
		static const Real sm_InverseSqrt2;
		static const Real sm_Sqrt3;
		static const Real sm_InverseSqrt3;
		static const Real sm_Zero;
		static const Real sm_One;
		static const Real sm_Two;
		static const Real sm_Three;
		static const Real sm_NegativeOne;
		static const Real sm_OneHalf;
		static const Real sm_OneThird;
	};

	using Mathf = Math<float>;
	using Mathd = Math<double>;
}

#endif // MATHEMATICS_BASE_MATH_H

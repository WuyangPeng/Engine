// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/03 19:30)

#ifndef MATHEMATICS_BASE_MATH_H
#define MATHEMATICS_BASE_MATH_H

#include "Mathematics/MathematicsDll.h"

#include "Flags/NumericalValueSymbol.h"

#include <boost/type_traits/is_floating_point.hpp>
#include <boost/static_assert.hpp>

namespace Mathematics
{	
	template <typename Real>
	class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Math
	{
	public:
		using ClassType = Math<Real>;
	
	public:
		// 封装隐藏函数的实现。
		// 在ACos和ASin函数中截断输入参数为[-1,1]，以避免当输入为略大于1或略小于-1时产生NaN的问题。
		// 其他函数使用快速近似算法的潜力，而不是调用标准的数学库函数。    

		static Real ACos (Real value) noexcept;
		static Real ASin (Real value) noexcept;
		static Real ATan (Real value) noexcept;
		static Real ATan2 (Real y, Real x) noexcept;
		static Real Sin (Real value) noexcept;
		static Real Cos (Real value) noexcept;
		static Real Tan (Real value) noexcept;

		static Real Ceil (Real value);		
		static Real FAbs (Real value) noexcept;
		static Real Floor (Real value);
		static Real FMod (Real x, Real y);
		static NumericalValueSymbol Sign (Real value);

		static Real Log (Real value);
		static Real Log2 (Real value);
		static Real Log10 (Real value);

		static Real Exp (Real value);
		static Real Pow (Real base, Real exponent);	
		static Real Square (Real value);
		static Real Sqrt (Real value) noexcept;
		static Real InvSqrt (Real value);
		static Real CubeRoot(Real value);
		
		// 截断输入值为特定的范围[min,max]
		static Real Clamp (Real value, Real minValue, Real maxValue);
		
		// 截断输入值为[0,1].
		static Real Saturate (Real value);		

		static bool Approximate(Real lhs,Real rhs,const Real epsilon = Math<Real>::sm_ZeroTolerance) noexcept;

		// equalDigit需要比较的尾数位（float最大为23位、double最大为52位）
		static bool FloatingPointEqual(Real lhs, Real rhs, int equalDigit);

		static Real GetNumericalRoundOffNonnegative(Real value);
		static Real GetNumericalRoundOff(Real value, Real minValue, Real maxValue);
		
		// 公用常数。
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
		static const Real sm_NegativeOne;
		static const Real sm_OneThird;
	};

	using Mathf = Math<float>;
	using Mathd = Math<double>;
}

#endif // MATHEMATICS_BASE_MATH_H

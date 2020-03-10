// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/08 15:17)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_H

#include "Mathematics/MathematicsDll.h"

#include "Bisect2Root.h"
#include "Mathematics/Base/Math.h"

namespace Mathematics
{
	template <typename Real>
	class Bisect2Calculate;

	template <typename Real>
	class Bisect2
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Bisect2<Real>;
		using Function = Real (*)(Real,Real);
		using Bisect2Calculate = Bisect2Calculate<Real>;
        using Bisect2Root = Bisect2Root<Real>;
        
    public:
        Bisect2 (Function firstFunction,  Function secondFunction, int maxLevel, Real tolerance = Math<Real>::sm_ZeroTolerance);
       
		CLASS_INVARIANT_DECLARE;
        
        const Bisect2Root Bisect(Real beginPointX, Real beginPointY,Real endPointX, Real endPointY) const;
        
        Real GetFirstFunctionValue(Real x,Real y) const;
        Real GetSecondFunctionValue(Real x,Real y) const;
        int GetMaxLevel() const;
        Real GetTolerance() const;

   private:
        // 输入数据和函数。
        Function m_FirstFunction;
        Function m_SecondFunction;        
        int m_MaxLevel;
        Real m_Tolerance;
    };

    using Bisect2f = Bisect2<float>;
    using Bisect2d = Bisect2<double>;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_H

// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 12:46)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_H

#include "Mathematics/MathematicsDll.h"

#include "Bisect3Root.h"
#include "NumericalAnalysisFwd.h"
#include "Mathematics/Base/MathDetail.h"

namespace Mathematics
{
	template <typename Real>
	class  Bisect3
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Bisect3<Real>;
		using Function = Real(*)(Real, Real, Real);
		using Bisect3Calculate = Bisect3Calculate<Real>;
		using Bisect3Root = Bisect3Root<Real>;

	public:
		Bisect3(Function firstFunction, Function secondFunction, Function thirdFunction,
				int maxLevel, Real tolerance = Math<Real>::GetZeroTolerance());

		CLASS_INVARIANT_DECLARE;

		const Bisect3Root Bisect(Real beginPointX, Real beginPointY, Real beginPointZ,
								 Real endPointX, Real endPointY, Real endPointZ) const;

		Real GetFirstFunctionValue(Real x, Real y, Real z) const;
		Real GetSecondFunctionValue(Real x, Real y, Real z) const;
		Real GetThirdFunctionValue(Real x, Real y, Real z) const;
		int GetMaxLevel() const;
		Real GetTolerance() const;

	private:
		// 输入数据和函数。
		Function m_FirstFunction;
		Function m_SecondFunction;
		Function m_ThirdFunction;
		int m_MaxLevel;
		Real m_Tolerance;
	};

	using Bisect3f = Bisect3<float>;
	using Bisect3d = Bisect3<double>;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_H

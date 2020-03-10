// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/08 16:06)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_GET_MINIMUM_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_GET_MINIMUM_H

#include "Mathematics/MathematicsDll.h"

#include "MinimizeNData.h"
#include "Minimize1.h"

namespace Mathematics
{
	template <typename Real, typename UserDataType>
	class MinimizeNGetMinimum
    {
    public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = MinimizeNGetMinimum<Real, UserDataType>;
		using Minimize1 = Minimize1<Real, ClassType>;
		using MinimizeNData = MinimizeNData<Real>;
		using RealVector = std::vector<Real>;
		using RealPtrVector = std::vector<Real*>;
		using Function = Real(*)(const RealVector&, const UserDataType*);
	 
	public:
		MinimizeNGetMinimum(int dimensions, const RealVector& initial, Function function,
							const UserDataType* userData, const RealVector& begin, const RealVector& end);

        CLASS_INVARIANT_DECLARE;

		int GetDimensions() const;
		Real CalculateLineArg(int index, Real value) const;
		Real GetFunctionResult(const RealVector& lineArg) const;

		void FindEachDirection(int index, int maxLevel, int maxBracket);
		Real EstimateUnitLengthConjugateDirection();
		void MinimizeConjugateDirection(Real length, int maxLevel, int maxBracket);

		const MinimizeNData& GetMinimizeNData() const;

	private:
		// 最低位置的目前的估计是m_TCurr[0..d-1]。
		// 当前线搜索的方向是m_DCurr[0..d-1]。此线必须对笛卡尔乘积域，在这个函数实现的过程被裁剪。
		// 如果该线是m_TCurr + s * m_DCurr，裁剪结果是区间[beginResult，endResult]。
		void ComputeDomain(const RealVector& begin, const RealVector& end,Real* beginResult, Real* endResult);

		// Minimize1<Real>对象需要C风格的函数来执行它的一维搜索
		// （沿线m_TCurr + s * m_DCurr）。
		static Real LineFunction(Real value, const ClassType* userData);
    		
	private:
		int m_Dimensions;
		RealVector m_DirectionStorage;
		RealPtrVector m_Direction;
		Real* m_DirectionConjugate;
		Real* m_DirectionCurrent;
		RealVector m_Save;

		Function m_Function;		 
		const UserDataType* m_UserData;
		MinimizeNData m_MinimizeNData;
		RealVector m_Begin;
		RealVector m_End;
    }; 
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_GET_MINIMUM_H

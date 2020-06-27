// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/20 12:58)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_TRAPEZOID_RULE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_TRAPEZOID_RULE_H

#include "Mathematics/MathematicsDll.h"

#include <type_traits>

namespace Mathematics
{
	template <typename Real, typename UserDataType>
	class  TrapezoidRule
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = TrapezoidRule<Real, UserDataType>;

		// ���һ���������û���������ݡ�
		using Function = Real(*)(Real, const UserDataType*);

	public:
		TrapezoidRule(int numSamples, Real begin, Real end, Function function, const UserDataType* userData);

		CLASS_INVARIANT_DECLARE;

		Real GetValue() const;

	private:
		void Calculate();

	private:
		int m_NumSamples;
		Real m_Begin;
		Real m_End;
		Function m_Function;
		const UserDataType* m_UserData;
		Real m_Value;
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_TRAPEZOID_RULE_H

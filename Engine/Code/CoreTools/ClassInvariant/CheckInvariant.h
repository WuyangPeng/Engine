// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.1.0.0 (2020/04/02 15:09)

#ifndef CORE_TOOLS_CLASS_INVARIANT_CHECK_INVARIANT_H
#define CORE_TOOLS_CLASS_INVARIANT_CHECK_INVARIANT_H

#include "ClassInvariantFwd.h"
#include "Flags/CheckInvariantFlags.h" 

// 验证类不变式的工具类
namespace CoreTools
{
	template <typename T>
	class CheckInvariant
	{
	public:
		using ClassType = CheckInvariant<T>;
		using ValueType = T;
		using Reference = T&;
		using ConstReference = const T&;

	public:
		CheckInvariant(ConstReference master, const FunctionDescribed& functionDescribed,
					   CheckInvariantConditions conditions = CheckInvariantConditions::Fully) noexcept;
		~CheckInvariant() noexcept;

		CheckInvariant(const CheckInvariant&) = delete;
		CheckInvariant& operator=(const CheckInvariant&) = delete;
		CheckInvariant(CheckInvariant&&) noexcept = delete;
		CheckInvariant& operator=(CheckInvariant&&) noexcept = delete;

	private:
		void CheckIsValid(const char* failLocationDescribe) const;

	private:
		ConstReference m_Master;
		const FunctionDescribed& m_FunctionDescribed;
		CheckInvariantConditions m_Conditions;
	};
}

#endif // CORE_TOOLS_CLASS_INVARIANT_CHECK_INVARIANT_H
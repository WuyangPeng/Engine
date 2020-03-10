// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/18 18:04)

#ifndef CORE_TOOLS_CLASS_INVARIANT_CHECK_INVARIANT_H
#define CORE_TOOLS_CLASS_INVARIANT_CHECK_INVARIANT_H

#include "ClassInvariantFwd.h"
#include "Flags/CheckInvariantFlags.h"

#include <boost/noncopyable.hpp>

// 验证类不变式的工具类
namespace CoreTools
{
	template <typename T>
	class CheckInvariant : private boost::noncopyable
	{
	public:
		using ClassType = CheckInvariant<T>;
		using ValueType = T;
		using Reference = T & ;
		using ConstReference = const T&;

	public:
		CheckInvariant(ConstReference master, const FunctionDescribed& functionDescribed,
					   CheckInvariantConditions conditions = CheckInvariantConditions::Fully) noexcept;
		~CheckInvariant() noexcept;

	private:
		void CheckIsValid(const char* failLocationDescribe) noexcept;

	private:
		ConstReference m_Master;
		const FunctionDescribed& m_FunctionDescribed;
		CheckInvariantConditions m_Conditions;
	};
}

#endif // CORE_TOOLS_CLASS_INVARIANT_CHECK_INVARIANT_H
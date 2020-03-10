// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 10:34)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_EXPLICIT_CAST_H
#define CORE_TOOLS_TEMPLATE_TOOLS_EXPLICIT_CAST_H 

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
	template <typename T>
	class ExplicitCast
	{
	public:
		using ValueType = T;
		using ClassType = ExplicitCast<T>;

	public:
		ExplicitCast(T value);

		CLASS_INVARIANT_DECLARE;

		operator ValueType () const;

	private:
		ValueType m_Value;
	};

	// 转换成非const引用不可用
	template <typename T>
	class ExplicitCast<T&>
	{
	public:
		using ValueType = T;
		using ClassType = ExplicitCast<T&>;

	public:
		ExplicitCast(T&) = delete;

		CLASS_INVARIANT_DECLARE;

		operator T& () = delete;
	};

	template <typename T>
	class ExplicitCast<T const&>
	{
	public:
		using ValueType = T;
		using ClassType = ExplicitCast<T const&>;

	public:
		ExplicitCast(T const& value);

		CLASS_INVARIANT_DECLARE;

	public:
		operator T const& () const;

		ExplicitCast& operator=(const ExplicitCast&) = delete;

	private:
		T const& m_Value;
	};

	// 转换成非const指针不可用
	template <typename T>
	class ExplicitCast<T*>
	{
	public:
		using ValueType = T;
		using ClassType = ExplicitCast<T*>;

	public:
		ExplicitCast(T*) = delete;

		CLASS_INVARIANT_DECLARE;

		operator T* () = delete;
	};

	template <typename T>
	class ExplicitCast<T const*>
	{
	public:
		using ValueType = T;
		using ClassType = ExplicitCast<T const*>;

	public:
		ExplicitCast(T const* value);

		CLASS_INVARIANT_DECLARE;

	public:
		operator T const* () const;

	private:
		T const* m_Value;
	};
}

#endif //  CORE_TOOLS_TEMPLATE_TOOLS_EXPLICIT_CAST_H


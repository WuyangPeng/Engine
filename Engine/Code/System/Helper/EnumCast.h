// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.2.0.0 (2020/05/08 19:33)

#ifndef SYSTEM_HELPER_ENUM_CAST_H
#define SYSTEM_HELPER_ENUM_CAST_H

#include "System/Helper/ConfigMacro.h"

#include <type_traits>

namespace System
{
	// ö�ٺ�����֮���ת��

	template <typename E>
	constexpr auto EnumCastUnderlying(E value) noexcept
	{
		static_assert(std::is_enum_v<E>, "E must be an enum.");

		using UnderlyingType = std::underlying_type_t<E>;

		return static_cast<UnderlyingType>(value);
	}

	template <typename T, typename E>
	constexpr T EnumCastUnderlying(E value) noexcept
	{
		static_assert(std::is_enum_v<E>, "E must be an enum.");

		return static_cast<T>(value);
	}

	template <typename E>
	constexpr E UnderlyingCastEnum(std::underlying_type_t<E> value) noexcept
	{
		static_assert(std::is_enum_v<E>, "E must be an enum.");

		return static_cast<E>(value);
	}

	template <typename E>
	void UnderlyingCastEnumPtr(typename std::underlying_type_t<E> value, E* ptr) noexcept
	{
		static_assert(std::is_enum_v<E>, "E must be an enum.");

		// ָ������Ϊ�ա�
		if (ptr != nullptr)
		{
			*ptr = UnderlyingCastEnum<E>(value);
		}
	}
}

#endif // SYSTEM_HELPER_ENUM_CAST_H
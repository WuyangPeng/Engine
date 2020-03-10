// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.0 (2020/01/02 14:49)

#ifndef SYSTEM_ENUM_CAST_DETAIL_H
#define SYSTEM_ENUM_CAST_DETAIL_H

#include "EnumCast.h"

template <typename E>
constexpr auto System
	::EnumCastUnderlying(E value) noexcept
{
	static_assert(std::is_enum_v<E>, "E must be an enum.");

	using UnderlyingType = std::underlying_type_t<E>;

	return static_cast<UnderlyingType>(value);
}

template <typename T, typename E>
constexpr T System
	::EnumCastUnderlying(E value) noexcept
{
	static_assert(std::is_enum_v<E>, "E must be an enum.");

	return static_cast<T>(value);
}

template <typename E>
constexpr E System
	::UnderlyingCastEnum(std::underlying_type_t<E> value) noexcept
{
	static_assert(std::is_enum_v<E>, "E must be an enum.");

	return static_cast<E>(value);
}	 

template <typename E>
void System
	::UnderlyingCastEnumPtr(typename std::underlying_type_t<E> value, E* ptr) noexcept
{
	static_assert(std::is_enum_v<E>, "E must be an enum.");

	// Ö¸ÕëÔÊĞíÎª¿Õ¡£
	if (ptr != nullptr)
	{
		*ptr = UnderlyingCastEnum<E>(value);
	}
}
 
#endif // SYSTEM_ENUM_CAST_DETAIL_H
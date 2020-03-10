// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 14:50)

#ifndef SYSTEM_ENUM_CAST_H
#define SYSTEM_ENUM_CAST_H

#include "System/Helper/ConfigMacro.h"

#include <type_traits>

namespace System
{
	// ö�ٺ�����֮���ת��
	
	template <typename E>
	constexpr auto EnumCastUnderlying(E value) noexcept;

	template <typename T,typename E>
	constexpr T EnumCastUnderlying(E value) noexcept;	
	
	template <typename E>
	constexpr E UnderlyingCastEnum(typename std::underlying_type_t<E> value) noexcept;

	template <typename E>
	void UnderlyingCastEnumPtr(typename std::underlying_type_t<E> value, E* ptr) noexcept;
}

#endif // SYSTEM_ENUM_CAST_H
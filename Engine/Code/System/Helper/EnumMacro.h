// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.2.0.0 (2020/05/08 19:33)

#ifndef SYSTEM_HELPER_ENUM_MACRO_H
#define SYSTEM_HELPER_ENUM_MACRO_H

#include "ConfigMacro.h"
#include "System/Helper/EnumCast.h"

#include <iosfwd>
#include <type_traits>

#define ENUM_ADDABLE_OPERATOR_DEFINE(className) \
        constexpr className operator+(className lhs,typename std::underlying_type<className>::type rhs) noexcept { \
        return System::UnderlyingCastEnum<className>(System::EnumCastUnderlying(lhs) + rhs); } \
		constexpr className operator+(typename std::underlying_type<className>::type lhs,className rhs) noexcept { return rhs + lhs;} \
        inline className& operator+=(className& lhs,std::underlying_type<className>::type rhs) noexcept { lhs = lhs + rhs; return lhs; }       

#define ENUM_SUBTRACTABLE_OPERATOR_DEFINE(className) \
        constexpr className operator-(className lhs,typename std::underlying_type<className>::type rhs) noexcept { \
        return System::UnderlyingCastEnum<className>(System::EnumCastUnderlying(lhs) - rhs); } \
        inline className& operator-=(className& lhs,std::underlying_type<className>::type rhs) noexcept { lhs = lhs - rhs; return lhs; } 

#define ENUM_MULTIPLICATION_OPERATOR_DEFINE(className) \
		template<typename T> constexpr T operator*(className lhs, T rhs) noexcept { return System::EnumCastUnderlying(lhs) * rhs; } 

#define ENUM_NEGATE_OPERATOR_DEFINE(className) \
		constexpr className operator-(className lhs) noexcept{ return System::UnderlyingCastEnum<className>(-System::EnumCastUnderlying(lhs)); } 

#define ENUM_INCREMENTABLE_OPERATOR_DEFINE(className) \
        inline className& operator++(className& lhs) noexcept{ using UnderlyingType = std::underlying_type<className>::type; \
        auto& result = reinterpret_cast<UnderlyingType&>(lhs); ++result; return lhs; } \
        inline className operator++(className& lhs, int) noexcept { const auto result = lhs; ++lhs; return result; }

#define ENUM_DECREMENTABLE_OPERATOR_DEFINE(className) \
        inline className& operator--(className& lhs) noexcept{ using UnderlyingType = std::underlying_type<className>::type; \
        auto& result = reinterpret_cast<UnderlyingType&>(lhs); --result;return lhs; } \
        inline className operator--(className& lhs, int) noexcept{ auto result = lhs; --lhs; return result; }

#define ENUM_ANDABLE_OPERATOR_DEFINE(className) \
	    constexpr className operator&(className lhs, className rhs) noexcept{ \
	    return System::UnderlyingCastEnum<className>(System::EnumCastUnderlying(lhs) & System::EnumCastUnderlying(rhs)); } \
	    inline className& operator&=(className& lhs, className rhs) noexcept { lhs = lhs & rhs; return lhs; }      

#define ENUM_ORABLE_OPERATOR_DEFINE(className) \
        constexpr className operator|(className lhs, className rhs) noexcept{ \
        return System::UnderlyingCastEnum<className>(System::EnumCastUnderlying(lhs) | System::EnumCastUnderlying(rhs)); } \
        inline className& operator|=(className& lhs, className rhs) noexcept { lhs = lhs | rhs; return lhs; } 

#define ENUM_XORABLE_OPERATOR_DEFINE(className) \
		constexpr className operator^(className lhs, className rhs) noexcept{ \
		return System::UnderlyingCastEnum<className>(System::EnumCastUnderlying(lhs) ^ System::EnumCastUnderlying(rhs)); } \
		inline className& operator^=(className& lhs, className rhs) noexcept{ lhs = lhs ^ rhs; return lhs; }  

// 使用下面宏需要包含头文件iostream。

#define ENUM_LEFT_SHIFTABLE_OPERATOR_DEFINE(className) \
        inline std::ostream& operator<<(std::ostream& os, className lhs) \
        { os << System::EnumCastUnderlying(lhs); return os; }

#define ENUM_RIGHT_SHIFTABLE_OPERATOR_DEFINE(className) \
        inline std::istream& operator>>(std::istream& is, className& lhs) \
	    { using UnderlyingType = std::underlying_type<className>::type; \
        UnderlyingType value{ }; is >> value; lhs = System::UnderlyingCastEnum<className>(value); return is; }

#define ENUM_LEFT_SHIFTABLE_OPERATOR_WCHAR_DEFINE(className) \
        inline std::wostream& operator<<(std::wostream& os, className lhs) \
        { os << System::EnumCastUnderlying(lhs); return os; }

#define ENUM_RIGHT_SHIFTABLE_OPERATOR_WCHAR_DEFINE(className) \
        inline std::wistream& operator>>(std::wistream& is, className& lhs) \
	    { using UnderlyingType = std::underlying_type<className>::type; \
        UnderlyingType value{ }; is >> value; lhs = System::UnderlyingCastEnum<className>(value); return is; }

#endif // SYSTEM_HELPER_ENUM_MACRO_H

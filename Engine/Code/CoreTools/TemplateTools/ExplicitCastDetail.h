//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 15:33)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_EXPLICIT_CAST_DETAIL_H
#define CORE_TOOLS_TEMPLATE_TOOLS_EXPLICIT_CAST_DETAIL_H

#include "ExplicitCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T>
CoreTools::ExplicitCast<T>::ExplicitCast(T value)
    : m_Value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool CoreTools::ExplicitCast<T>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename T>
CoreTools::ExplicitCast<T>::operator ValueType() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Value;
}

template <typename T>
CoreTools::ExplicitCast<T const&>::ExplicitCast(T const& value)
    : m_Value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool CoreTools::ExplicitCast<T const&>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename T>
CoreTools::ExplicitCast<T const&>::operator T const &() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Value;
}

template <typename T>
CoreTools::ExplicitCast<T const*>::ExplicitCast(T const* value)
    : m_Value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool CoreTools::ExplicitCast<T const*>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename T>
CoreTools::ExplicitCast<T const*>::operator T const *() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Value;
}

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_EXPLICIT_CAST_DETAIL_H

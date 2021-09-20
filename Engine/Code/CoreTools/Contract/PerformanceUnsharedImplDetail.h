///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.2 (2021/08/25 16:06)

#ifndef CORE_TOOLS_CONTRACT_PERFORMANCE_UNSHARED_IMPL_DETAIL_H
#define CORE_TOOLS_CONTRACT_PERFORMANCE_UNSHARED_IMPL_DETAIL_H

#include "PerformanceUnsharedImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T>
template <typename Type, typename... Types>
CoreTools::PerformanceUnsharedImpl<T>::PerformanceUnsharedImpl(Type&& arg, Types&&... args)
    : impl{ std::make_shared<T>(std::forward<Type>(arg), std::forward<Types>(args)...) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
template <typename... Types>
CoreTools::PerformanceUnsharedImpl<T>::PerformanceUnsharedImpl(MAYBE_UNUSED ImplCreateUseFactory implCreateType, Types&&... args)
    : impl{ T::FactoryType::Create(std::forward<Types>(args)...) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
template <typename... Types>
CoreTools::PerformanceUnsharedImpl<T>::PerformanceUnsharedImpl(MAYBE_UNUSED ImplCreateUseDefaultConstruction implCreateDefaultType, Types&&... args)
    : impl{ std::make_shared<T>() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool CoreTools::PerformanceUnsharedImpl<T>::IsValid() const noexcept
{
    if (impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename T>
typename CoreTools::PerformanceUnsharedImpl<T>::ConstSharedPtr CoreTools::PerformanceUnsharedImpl<T>::operator->() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl;
}

template <typename T>
const T& CoreTools::PerformanceUnsharedImpl<T>::operator*() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return *impl;
}

#endif  // CORE_TOOLS_CONTRACT_PERFORMANCE_UNSHARED_IMPL_DETAIL_H
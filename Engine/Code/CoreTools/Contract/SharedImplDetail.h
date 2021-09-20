///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.2 (2021/08/25 16:06)

#ifndef CORE_TOOLS_CONTRACT_SHARED_IMPL_DETAIL_H
#define CORE_TOOLS_CONTRACT_SHARED_IMPL_DETAIL_H

#include "SharedImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename T>
template <typename Type, typename... Types>
CoreTools::SharedImpl<T>::SharedImpl(Type&& arg, Types&&... args)
    : impl{ std::make_shared<T>(std::forward<Type>(arg), std::forward<Types>(args)...) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
template <typename... Types>
CoreTools::SharedImpl<T>::SharedImpl(MAYBE_UNUSED ImplCreateUseFactory ImplCreateType, Types&&... args)
    : impl{ T::FactoryType::Create(std::forward<Types>(args)...) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
template <typename... Types>
CoreTools::SharedImpl<T>::SharedImpl(MAYBE_UNUSED ImplCreateUseDefaultConstruction implCreateDefaultType, Types&&... args)
    : impl{ std::make_shared<T>() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool CoreTools::SharedImpl<T>::IsValid() const noexcept
{
    if (impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename T>
typename CoreTools::SharedImpl<T>::ConstSharedPtr CoreTools::SharedImpl<T>::operator->() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl;
}

template <typename T>
typename CoreTools::SharedImpl<T>::SharedPtr CoreTools::SharedImpl<T>::operator->() noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return impl;
}

template <typename T>
const T& CoreTools::SharedImpl<T>::operator*() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return *impl;
}

template <typename T>
T& CoreTools::SharedImpl<T>::operator*() noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return *impl;
}

#endif  // CORE_TOOLS_CONTRACT_SHARED_IMPL_DETAIL_H

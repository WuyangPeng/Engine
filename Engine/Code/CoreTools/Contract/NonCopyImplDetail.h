///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/10 18:24)

#ifndef CORE_TOOLS_CONTRACT_NON_COPY_IMPL_DETAIL_H
#define CORE_TOOLS_CONTRACT_NON_COPY_IMPL_DETAIL_H

#include "NonCopyImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename T>
template <typename Type, typename... Types>
CoreTools::NonCopyImpl<T>::NonCopyImpl(Type&& arg, Types&&... args)
    : impl{ std::make_shared<T>(std::forward<Type>(arg), std::forward<Types>(args)...) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
template <typename... Types>
CoreTools::NonCopyImpl<T>::NonCopyImpl(MAYBE_UNUSED ImplCreateUseFactory implCreateType, Types&&... args)
    : impl{ T::FactoryType::Create(std::forward<Types>(args)...) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
template <typename... Types>
CoreTools::NonCopyImpl<T>::NonCopyImpl(MAYBE_UNUSED ImplCreateUseDefaultConstruction implCreateDefaultType, Types&&... args)
    : impl{ std::make_shared<T>() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool CoreTools::NonCopyImpl<T>::IsValid() const noexcept
{
    if (impl != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
CoreTools::NonCopyImpl<T>::NonCopyImpl(NonCopyImpl&& rhs) noexcept
    : impl{ std::move(rhs.impl) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
CoreTools::NonCopyImpl<T>& CoreTools::NonCopyImpl<T>::operator=(NonCopyImpl&& rhs) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    ClassType result{ std::move(rhs) };
    impl.swap(result.impl);

    return *this;
}

template <typename T>
typename CoreTools::NonCopyImpl<T>::ConstSharedPtr CoreTools::NonCopyImpl<T>::operator->() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl;
}

template <typename T>
typename CoreTools::NonCopyImpl<T>::SharedPtr CoreTools::NonCopyImpl<T>::operator->() noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return impl;
}

template <typename T>
const T& CoreTools::NonCopyImpl<T>::operator*() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return *impl;
}

template <typename T>
T& CoreTools::NonCopyImpl<T>::operator*() noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return *impl;
}

#endif  // CORE_TOOLS_CONTRACT_NON_COPY_IMPL_DETAIL_H
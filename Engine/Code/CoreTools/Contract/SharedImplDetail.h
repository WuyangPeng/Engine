/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/28 16:06)

#ifndef CORE_TOOLS_CONTRACT_SHARED_IMPL_DETAIL_H
#define CORE_TOOLS_CONTRACT_SHARED_IMPL_DETAIL_H

#include "SharedImpl.h"
#include "System/Helper/Tools.h"
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
CoreTools::SharedImpl<T>::SharedImpl(ImplCreateUseFactory implCreateType, Types&&... args)
    : impl{ T::FactoryType::Create(std::forward<Types>(args)...) }
{
    System::UnusedFunction(implCreateType);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
template <typename... Types>
CoreTools::SharedImpl<T>::SharedImpl(ImplCreateUseDefaultConstruction implCreateDefaultType, Types&&... args)
    : impl{ std::make_shared<T>() }
{
    System::UnusedFunction(implCreateDefaultType);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool CoreTools::SharedImpl<T>::IsValid() const noexcept
{
    return impl != nullptr;
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

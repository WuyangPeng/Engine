///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/10 18:23)

#ifndef CORE_TOOLS_CONTRACT_COPY_UNSHARED_IMPL_DETAIL_H
#define CORE_TOOLS_CONTRACT_COPY_UNSHARED_IMPL_DETAIL_H

#include "CopyUnsharedImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Original, typename Package>
template <typename Type, typename... Types>
CoreTools::CopyUnsharedImpl<Original, Package>::CopyUnsharedImpl(Type&& arg, Types&&... args)
    : impl{ std::make_shared<Package>(std::forward<Type>(arg), std::forward<Types>(args)...) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename Original, typename Package>
template <typename... Types>
CoreTools::CopyUnsharedImpl<Original, Package>::CopyUnsharedImpl(MAYBE_UNUSED ImplCreateUseFactory implCreateType, Types&&... args)
    : impl{ Package::FactoryType::Create(std::forward<Types>(args)...) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename Original, typename Package>
template <typename... Types>
CoreTools::CopyUnsharedImpl<Original, Package>::CopyUnsharedImpl(MAYBE_UNUSED ImplCreateUseDefaultConstruction implCreateDefaultType, Types&&... args)
    : impl{ std::make_shared<Package>() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename Original, typename Package>
CoreTools::CopyUnsharedImpl<Original, Package>::CopyUnsharedImpl(const CopyUnsharedImpl& rhs)
    : impl{ Original::Clone(*rhs.impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename Original, typename Package>
CoreTools::CopyUnsharedImpl<Original, Package>& CoreTools::CopyUnsharedImpl<Original, Package>::operator=(const CopyUnsharedImpl& rhs)
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
    CORE_TOOLS_CLASS_IS_VALID_1;

    ClassType result{ rhs };
    Swap(result);

    return *this;
}

template <typename Original, typename Package>
CoreTools::CopyUnsharedImpl<Original, Package>::CopyUnsharedImpl(CopyUnsharedImpl&& rhs) noexcept
    : impl{ std::move(rhs.impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename Original, typename Package>
CoreTools::CopyUnsharedImpl<Original, Package>& CoreTools::CopyUnsharedImpl<Original, Package>::operator=(CopyUnsharedImpl&& rhs) noexcept
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
    CORE_TOOLS_CLASS_IS_VALID_1;

    ClassType result{ std::move(rhs) };
    Swap(result);

    return *this;
}

template <typename Original, typename Package>
void CoreTools::CopyUnsharedImpl<Original, Package>::Swap(CopyUnsharedImpl& rhs) noexcept
{
    impl.swap(rhs.impl);
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Original, typename Package>
bool CoreTools::CopyUnsharedImpl<Original, Package>::IsValid() const noexcept
{
    if (impl != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Original, typename Package>
typename CoreTools::CopyUnsharedImpl<Original, Package>::ConstSharedPtr CoreTools::CopyUnsharedImpl<Original, Package>::operator->() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl;
}

template <typename Original, typename Package>
typename CoreTools::CopyUnsharedImpl<Original, Package>::SharedPtr CoreTools::CopyUnsharedImpl<Original, Package>::operator->() noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return impl;
}

template <typename Original, typename Package>
const Package& CoreTools::CopyUnsharedImpl<Original, Package>::operator*() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return *impl;
}

template <typename Original, typename Package>
Package& CoreTools::CopyUnsharedImpl<Original, Package>::operator*() noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return *impl;
}

#endif  // CORE_TOOLS_CONTRACT_COPY_UNSHARED_IMPL_DETAIL_H
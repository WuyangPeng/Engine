/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/28 16:04)

#ifndef CORE_TOOLS_CONTRACT_DELAY_COPY_UNSHARED_IMPL_DETAIL_H
#define CORE_TOOLS_CONTRACT_DELAY_COPY_UNSHARED_IMPL_DETAIL_H

#include "DelayCopyUnsharedImpl.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Original, typename Package>
template <typename Type, typename... Types>
CoreTools::DelayCopyUnsharedImpl<Original, Package>::DelayCopyUnsharedImpl(Type&& arg, Types&&... args)
    : impl{ std::make_shared<Package>(std::forward<Type>(arg), std::forward<Types>(args)...) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename Original, typename Package>
template <typename... Types>
CoreTools::DelayCopyUnsharedImpl<Original, Package>::DelayCopyUnsharedImpl(ImplCreateUseFactory implCreateType, Types&&... args)
    : impl{ Package::FactoryType::Create(std::forward<Types>(args)...) }
{
    System::UnusedFunction(implCreateType);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename Original, typename Package>
template <typename... Types>
CoreTools::DelayCopyUnsharedImpl<Original, Package>::DelayCopyUnsharedImpl(ImplCreateUseDefaultConstruction implCreateDefaultType, Types&&... args)
    : impl{ std::make_shared<Package>() }
{
    System::UnusedFunction(implCreateDefaultType);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename Original, typename Package>
void CoreTools::DelayCopyUnsharedImpl<Original, Package>::Copy()
{
    if (1 < impl.use_count())
    {
        impl = Original::Clone(*impl);
    }
}

template <typename Original, typename Package>
CoreTools::DelayCopyUnsharedImpl<Original, Package>& CoreTools::DelayCopyUnsharedImpl<Original, Package>::operator=(const SharedPtr& sharedPtr) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    impl = sharedPtr;

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Original, typename Package>
bool CoreTools::DelayCopyUnsharedImpl<Original, Package>::IsValid() const noexcept
{
    return impl != nullptr;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Original, typename Package>
typename CoreTools::DelayCopyUnsharedImpl<Original, Package>::ConstSharedPtr CoreTools::DelayCopyUnsharedImpl<Original, Package>::GetConstImpl() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl;
}

template <typename Original, typename Package>
typename CoreTools::DelayCopyUnsharedImpl<Original, Package>::ConstSharedPtr CoreTools::DelayCopyUnsharedImpl<Original, Package>::operator->() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl;
}

template <typename Original, typename Package>
typename CoreTools::DelayCopyUnsharedImpl<Original, Package>::SharedPtr CoreTools::DelayCopyUnsharedImpl<Original, Package>::operator->()
{
    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    return impl;
}

template <typename Original, typename Package>
const Package& CoreTools::DelayCopyUnsharedImpl<Original, Package>::operator*() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return *impl;
}

template <typename Original, typename Package>
Package& CoreTools::DelayCopyUnsharedImpl<Original, Package>::operator*()
{
    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    return *impl;
}

#endif  // CORE_TOOLS_CONTRACT_DELAY_COPY_UNSHARED_IMPL_DETAIL_H
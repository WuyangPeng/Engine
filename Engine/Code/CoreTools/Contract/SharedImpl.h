///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/02/23 13:49)

#ifndef CORE_TOOLS_CONTRACT_SHARED_IMPL_H
#define CORE_TOOLS_CONTRACT_SHARED_IMPL_H

#include "ContractFwd.h"
#include "ImplStaticAssertHelper.h"
#include "CoreTools/Helper/UserMacro.h"

#include <memory>

namespace CoreTools
{
    // 类必须共享资源，复制只是复制类的指针成员。所有共享类必须以Shared作为后缀。
    template <typename T>
    class SharedImpl final
    {
    public:
        using ClassType = SharedImpl<T>;
        using ClassShareType = ShareClasses;
        using SharedPtr = std::shared_ptr<T>;
        using ConstSharedPtr = std::shared_ptr<const T>;

    public:
        SharedImpl() noexcept = delete;

        template <typename Type, typename... Types>
        explicit SharedImpl(Type&& arg, Types&&... args);

        template <typename... Types>
        explicit SharedImpl(ImplCreateUseFactory implCreateType, Types&&... args);

        template <typename... Types>
        explicit SharedImpl(ImplCreateUseDefaultConstruction implCreateDefaultType, Types&&... args);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstSharedPtr operator->() const noexcept;
        NODISCARD SharedPtr operator->() noexcept;
        NODISCARD const T& operator*() const noexcept;
        NODISCARD T& operator*() noexcept;

    private:
        SharedPtr impl;
    };
}

#endif  // CORE_TOOLS_CONTRACT_SHARED_IMPL_H

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 09:41)

#ifndef CORE_TOOLS_CONTRACT_NON_COPY_IMPL_H
#define CORE_TOOLS_CONTRACT_NON_COPY_IMPL_H

#include "ContractFwd.h"
#include "ImplStaticAssertHelper.h"
#include "CoreTools/Helper/UserMacro.h"

#include <memory>

namespace CoreTools
{
    template <typename T>
    class NonCopyImpl final
    {
    public:
        using ClassType = NonCopyImpl<T>;
        using ClassShareType = NonCopyClasses;
        using SharedPtr = std::shared_ptr<T>;
        using ConstSharedPtr = std::shared_ptr<const T>;

    public:
        template <typename Type, typename... Types>
        explicit NonCopyImpl(Type&& arg, Types&&... args);

        template <typename... Types>
        explicit NonCopyImpl(ImplCreateUseFactory implCreateType, Types&&... args);

        template <typename... Types>
        explicit NonCopyImpl(ImplCreateUseDefaultConstruction implCreateDefaultType, Types&&... args);

        NonCopyImpl() noexcept = delete;
        ~NonCopyImpl() noexcept = default;
        NonCopyImpl(const NonCopyImpl& rhs) = delete;
        NonCopyImpl& operator=(const NonCopyImpl& rhs) = delete;
        NonCopyImpl(NonCopyImpl&& rhs) noexcept;
        NonCopyImpl& operator=(NonCopyImpl&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstSharedPtr operator->() const noexcept;
        NODISCARD SharedPtr operator->() noexcept;
        NODISCARD const T& operator*() const noexcept;
        NODISCARD T& operator*() noexcept;

    private:
        SharedPtr impl;
    };
}

#endif  // CORE_TOOLS_CONTRACT_NON_COPY_IMPL_H

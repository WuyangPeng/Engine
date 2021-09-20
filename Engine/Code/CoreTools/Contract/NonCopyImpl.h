///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.2 (2021/08/25 16:02)

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
        using ClassShareType = CoreTools::NonCopyClasses;
        using SharedPtr = std::shared_ptr<T>;
        using ConstSharedPtr = std::shared_ptr<const T>;

    public:
        template <typename Type, typename... Types>
        explicit NonCopyImpl(Type&& arg, Types&&... args);

        template <typename... Types>
        explicit NonCopyImpl(MAYBE_UNUSED ImplCreateUseFactory implCreateType, Types&&... args);

        template <typename... Types>
        explicit NonCopyImpl(MAYBE_UNUSED ImplCreateUseDefaultConstruction implCreateDefaultType, Types&&... args);

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

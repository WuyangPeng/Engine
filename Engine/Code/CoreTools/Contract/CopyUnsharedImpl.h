///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/10 18:31)

#ifndef CORE_TOOLS_CONTRACT_COPY_UNSHARED_IMPL_H
#define CORE_TOOLS_CONTRACT_COPY_UNSHARED_IMPL_H

#include "ContractFwd.h"
#include "ImplStaticAssertHelper.h"
#include "CoreTools/Helper/UserMacro.h"

#include <memory>

namespace CoreTools
{
    template <typename Original, typename Package>
    class CopyUnsharedImpl final
    {
    public:
        using ClassType = CopyUnsharedImpl<Original, Package>;
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        using SharedPtr = std::shared_ptr<Package>;
        using ConstSharedPtr = std::shared_ptr<const Package>;

    public:
        CopyUnsharedImpl() noexcept = delete;

        template <typename Type, typename... Types>
        explicit CopyUnsharedImpl(Type&& arg, Types&&... args);

        template <typename... Types>
        explicit CopyUnsharedImpl(MAYBE_UNUSED ImplCreateUseFactory implCreateType, Types&&... args);

        template <typename... Types>
        explicit CopyUnsharedImpl(MAYBE_UNUSED ImplCreateUseDefaultConstruction implCreateDefaultType, Types&&... args);

        ~CopyUnsharedImpl() noexcept = default;
        CopyUnsharedImpl(const CopyUnsharedImpl& rhs);
        CopyUnsharedImpl& operator=(const CopyUnsharedImpl& rhs);
        CopyUnsharedImpl(CopyUnsharedImpl&& rhs) noexcept;
        CopyUnsharedImpl& operator=(CopyUnsharedImpl&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstSharedPtr operator->() const noexcept;
        NODISCARD SharedPtr operator->() noexcept;
        NODISCARD const Package& operator*() const noexcept;
        NODISCARD Package& operator*() noexcept;

    private:
        void Swap(CopyUnsharedImpl& rhs) noexcept;

    private:
        SharedPtr impl;
    };
}

#endif  // CORE_TOOLS_CONTRACT_COPY_UNSHARED_IMPL_H
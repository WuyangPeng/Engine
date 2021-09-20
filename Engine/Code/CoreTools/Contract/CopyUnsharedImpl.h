///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.2 (2021/08/25 16:01)

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

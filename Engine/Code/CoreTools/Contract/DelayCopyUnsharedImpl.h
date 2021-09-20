///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.2 (2021/08/25 16:02)

#ifndef CORE_TOOLS_CONTRACT_DELAY_COPY_UNSHARED_IMPL_H
#define CORE_TOOLS_CONTRACT_DELAY_COPY_UNSHARED_IMPL_H

#include "ContractFwd.h"
#include "ImplStaticAssertHelper.h"
#include "CoreTools/Helper/UserMacro.h"

#include <memory>

namespace CoreTools
{
    template <typename Original, typename Package>
    class DelayCopyUnsharedImpl final
    {
    public:
        using ClassType = DelayCopyUnsharedImpl<Original, Package>;
        using ClassShareType = CoreTools::DelayCopyUnsharedClasses;
        using SharedPtr = std::shared_ptr<Package>;
        using ConstSharedPtr = std::shared_ptr<const Package>;

    public:
        DelayCopyUnsharedImpl() noexcept = delete;

        template <typename Type, typename... Types>
        explicit DelayCopyUnsharedImpl(Type&& arg, Types&&... args);

        template <typename... Types>
        explicit DelayCopyUnsharedImpl(MAYBE_UNUSED ImplCreateUseFactory implCreateType, Types&&... args);

        template <typename... Types>
        explicit DelayCopyUnsharedImpl(MAYBE_UNUSED ImplCreateUseDefaultConstruction implCreateDefaultType, Types&&... args);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstSharedPtr GetConstImpl() const noexcept;

        NODISCARD ConstSharedPtr operator->() const noexcept;
        NODISCARD SharedPtr operator->();
        NODISCARD const Package& operator*() const noexcept;
        NODISCARD Package& operator*();

    private:
        void Copy();

    private:
        SharedPtr impl;
    };
}

#endif  // CORE_TOOLS_CONTRACT_DELAY_COPY_UNSHARED_IMPL_H

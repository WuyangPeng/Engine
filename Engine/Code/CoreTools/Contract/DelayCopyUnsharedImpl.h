///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/10 18:31)

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

        DelayCopyUnsharedImpl& operator=(const SharedPtr& sharedPtr) noexcept;

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

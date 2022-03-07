///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/10 18:32)

#ifndef CORE_TOOLS_CONTRACT_PERFORMANCE_UNSHARED_IMPL_H
#define CORE_TOOLS_CONTRACT_PERFORMANCE_UNSHARED_IMPL_H

#include "ContractFwd.h"
#include "ImplStaticAssertHelper.h"
#include "CoreTools/Helper/UserMacro.h"

#include <memory>

namespace CoreTools
{
    template <typename T>
    class PerformanceUnsharedImpl final
    {
    public:
        using ClassType = PerformanceUnsharedImpl<T>;
        using ClassShareType = CoreTools::PerformanceUnsharedClasses;
        using ConstSharedPtr = std::shared_ptr<const T>;

    public:
        PerformanceUnsharedImpl() noexcept = delete;

        template <typename Type, typename... Types>
        explicit PerformanceUnsharedImpl(Type&& arg, Types&&... args);

        template <typename... Types>
        explicit PerformanceUnsharedImpl(MAYBE_UNUSED ImplCreateUseFactory implCreateType, Types&&... args);

        template <typename... Types>
        explicit PerformanceUnsharedImpl(MAYBE_UNUSED ImplCreateUseDefaultConstruction implCreateDefaultType, Types&&... args);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstSharedPtr operator->() const noexcept;
        NODISCARD const T& operator*() const noexcept;

    private:
        ConstSharedPtr impl;
    };
}

#endif  // CORE_TOOLS_CONTRACT_PERFORMANCE_UNSHARED_IMPL_H

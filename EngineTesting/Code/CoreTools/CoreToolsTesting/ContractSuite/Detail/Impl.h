///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 16:30)

#ifndef CORE_TOOLS_CONTRACT_SUITE_IMPL_H
#define CORE_TOOLS_CONTRACT_SUITE_IMPL_H

#include "CoreTools/Helper/UserMacro.h"

#include <memory>

namespace CoreTools
{
    class Impl final
    {
    public:
        using ClassType = Impl;

        using FactoryType = ClassType;
        using ImplSharedPtr = std::shared_ptr<ClassType>;

    public:
        Impl() noexcept;
        explicit Impl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;
        NODISCARD size_t GetAddress() const noexcept;

        NODISCARD static ImplSharedPtr Create(int count);
        NODISCARD static ImplSharedPtr Create();

    private:
        int count;
    };
}

#endif  // CORE_TOOLS_CONTRACT_SUITE_IMPL_H
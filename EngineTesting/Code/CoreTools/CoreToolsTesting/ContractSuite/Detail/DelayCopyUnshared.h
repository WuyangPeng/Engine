///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.3 (2023/02/23 14:15)

#ifndef CORE_TOOLS_CONTRACT_SUITE_DELAY_COPY_UNSHARED_H
#define CORE_TOOLS_CONTRACT_SUITE_DELAY_COPY_UNSHARED_H

#include "Impl.h"
#include "CoreTools/Contract/DelayCopyUnsharedImpl.h"

#include <memory>

namespace CoreTools
{
    class DelayCopyUnshared final
    {
    public:
        using ClassType = DelayCopyUnshared;
        using PackageType = DelayCopyUnsharedImpl<ClassType, Impl>;
        using ImplSharedPtr = Impl::ImplSharedPtr;

    public:
        explicit DelayCopyUnshared(int count);
        DelayCopyUnshared(ImplCreateUseFactory implCreateUseFactory, int count);
        explicit DelayCopyUnshared(ImplCreateUseDefaultConstruction implCreateUseDefaultConstruction);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count);
        NODISCARD int GetDereferenceCount() const noexcept;
        void SetDereferenceCount(int count);
        NODISCARD size_t GetAddress() const noexcept;

        static NODISCARD ImplSharedPtr Clone(const Impl& impl);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_CONTRACT_SUITE_DELAY_COPY_UNSHARED_H
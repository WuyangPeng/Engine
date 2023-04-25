///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/11 15:31)

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
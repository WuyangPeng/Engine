///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.2 (2021/08/26 15:07)

#ifndef CORE_TOOLS_CONTRACT_SUITE_DELAY_COPY_UNSHAREDL_H
#define CORE_TOOLS_CONTRACT_SUITE_DELAY_COPY_UNSHAREDL_H

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

#endif  // CORE_TOOLS_CONTRACT_SUITE_DELAY_COPY_UNSHAREDL_H
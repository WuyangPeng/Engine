/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:32)

#ifndef EXPORT_TEST_NETWORK_DELAY_COPY_UNSHARED_MACRO_H
#define EXPORT_TEST_NETWORK_DELAY_COPY_UNSHARED_MACRO_H

#include "Network/NetworkDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"

NETWORK_DELAY_COPY_UNSHARED_EXPORT_IMPL(NetworkDelayCopyUnsharedMacro, NetworkDelayCopyUnsharedMacroImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE NetworkDelayCopyUnsharedMacro final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(NetworkDelayCopyUnsharedMacro);

    public:
        explicit NetworkDelayCopyUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count);

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_NETWORK_DELAY_COPY_UNSHARED_MACRO_H
/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:52)

#ifndef EXPORT_TEST_NETWORK_NON_COPY_MACRO_H
#define EXPORT_TEST_NETWORK_NON_COPY_MACRO_H

#include "Network/NetworkDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

NETWORK_NON_COPY_EXPORT_IMPL(NetworkNonCopyMacroImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE NetworkNonCopyMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(NetworkNonCopyMacro);

    public:
        explicit NetworkNonCopyMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_NETWORK_NON_COPY_MACRO_H
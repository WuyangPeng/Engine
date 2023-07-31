///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 14:57)

#ifndef EXPORT_TEST_NETWORK_TEST_EXPORT_MACRO_H
#define EXPORT_TEST_NETWORK_TEST_EXPORT_MACRO_H

#include "Network/NetworkDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

EXPORT_SHARED_PTR(Network, NetworkTestExportMacroImpl, NETWORK_DEFAULT_DECLARE);
NETWORK_EXPORT(NetworkTestExportMacroImpl, NON_COPY);
NETWORK_EXPORT_UNIQUE_PTR(NetworkTestExportMacro);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE NetworkTestExportMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(NetworkTestExportMacro);

    public:
        explicit NetworkTestExportMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_NETWORK_TEST_EXPORT_MACRO_H
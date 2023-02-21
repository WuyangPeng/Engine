///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.2 (2023/02/07 17:18)

#ifndef EXPORT_TEST_NETWORK_MACRO_SHARED_H
#define EXPORT_TEST_NETWORK_MACRO_SHARED_H

#include "Network/NetworkDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/SharedExportMacro.h"

NETWORK_SHARED_EXPORT_IMPL(NetworkMacroSharedImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE NetworkMacroShared final
    {
    public:
        SHARED_TYPE_DECLARE(NetworkMacroShared);

    public:
        explicit NetworkMacroShared(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_NETWORK_MACRO_SHARED_H
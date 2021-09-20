//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 20:22)

#ifndef NETWORK_NETWORK_INTERFACE_HANDLE_SET_H
#define NETWORK_NETWORK_INTERFACE_HANDLE_SET_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Network/ACEWrappers/Using/ACEUsing.h"
#include "Network/Interface/NetworkInternalFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
NETWORK_DELAY_COPY_UNSHARED_EXPORT_IMPL(HandleSet,HandleSetImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE HandleSet final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(HandleSet);

    public:
        explicit HandleSet(const ConfigurationStrategy& configurationStrategy);

        CLASS_INVARIANT_DECLARE;

        void SetBit(ACEHandle handle);
        [[nodiscard]] int64_t GetMaxSet() const;
        [[nodiscard]] SockFdSet* GetFdSet();
        void Sync(ACEHandle maxHandle);
        [[nodiscard]] bool IsSet(ACEHandle handle) const;
        void ClearBit(ACEHandle handle);

        [[nodiscard]] const ACEHandleSet& GetACEHandleSet() const;

        [[nodiscard]] bool IsFdSetFull() const;
        [[nodiscard]] int IsFdSetCount() const;

        [[nodiscard]] bool IsFdSetCountIsOne() const;

        [[nodiscard]] bool Select(int width);

    private:
        PackageType impl;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_HANDLE_SET_H

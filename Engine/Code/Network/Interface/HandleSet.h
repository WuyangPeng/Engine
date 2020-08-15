// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.2.4 (2020/03/11 09:57)

#ifndef NETWORK_NETWORK_INTERFACE_HANDLE_SET_H
#define NETWORK_NETWORK_INTERFACE_HANDLE_SET_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Network/ACEWrappers/Using/ACEUsing.h"
#include "Network/Interface/NetworkInternalFwd.h"

NETWORK_EXPORT_SHARED_PTR(HandleSetImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE HandleSet
    {
    public:
        DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(HandleSet);

    public:
        explicit HandleSet(const ConfigurationStrategy& configurationStrategy);

        CLASS_INVARIANT_DECLARE;

        void SetBit(ACEHandle handle);
        int64_t GetMaxSet() const;
        SockFdSet* GetFdSet();
        void Sync(ACEHandle maxHandle);
        bool IsSet(ACEHandle handle) const;
        void ClearBit(ACEHandle handle);

        const ACEHandleSet& GetACEHandleSet() const;

        bool IsFdSetFull() const;
        int IsFdSetCount() const;

        bool IsFdSetCountIsOne() const;

        bool Select(int width);

    private:
        IMPL_TYPE_DECLARE(HandleSet);
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_HANDLE_SET_H

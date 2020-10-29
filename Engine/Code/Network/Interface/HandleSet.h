//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 20:22)

#ifndef NETWORK_NETWORK_INTERFACE_HANDLE_SET_H
#define NETWORK_NETWORK_INTERFACE_HANDLE_SET_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Network/ACEWrappers/Using/ACEUsing.h"
#include "Network/Interface/NetworkInternalFwd.h"

NETWORK_EXPORT_SHARED_PTR(HandleSetImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE HandleSet final
    {
    public:
        DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(HandleSet);

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
        IMPL_TYPE_DECLARE(HandleSet);
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_HANDLE_SET_H

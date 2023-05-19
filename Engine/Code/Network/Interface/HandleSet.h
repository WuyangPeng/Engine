///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 09:51)

#ifndef NETWORK_NETWORK_INTERFACE_HANDLE_SET_H
#define NETWORK_NETWORK_INTERFACE_HANDLE_SET_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Network/ACEWrappers/Using/ACEUsing.h"
#include "Network/Interface/NetworkInternalFwd.h"

NETWORK_DELAY_COPY_UNSHARED_EXPORT_IMPL(HandleSet, HandleSetImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE HandleSet final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(HandleSet);

    public:
        explicit HandleSet(const ConfigurationStrategy& configurationStrategy);

        CLASS_INVARIANT_DECLARE;

        void SetBit(ACEHandleType handle);
        NODISCARD int64_t GetMaxSet() const;
        NODISCARD SockFdSet* GetFdSet();
        void Sync(ACEHandleType maxHandle);
        NODISCARD bool IsSet(ACEHandleType handle) const;
        void ClearBit(ACEHandleType handle);

        NODISCARD const ACEHandleSet& GetACEHandleSet() const;

        NODISCARD bool IsFdSetFull() const;
        NODISCARD int IsFdSetCount() const;

        NODISCARD bool IsFdSetCountIsOne() const;

        NODISCARD bool Select(int width);

    private:
        PackageType impl;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_HANDLE_SET_H

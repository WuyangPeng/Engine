///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/20 16:42)

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

        void SetBit(ACEHandle handle);
        NODISCARD int64_t GetMaxSet() const;
        NODISCARD SockFdSet* GetFdSet();
        void Sync(ACEHandle maxHandle);
        NODISCARD bool IsSet(ACEHandle handle) const;
        void ClearBit(ACEHandle handle);

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

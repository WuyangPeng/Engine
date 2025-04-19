/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 16:36)

#ifndef NETWORK_NETWORK_INTERFACE_HANDLE_SET_H
#define NETWORK_NETWORK_INTERFACE_HANDLE_SET_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Network/AceWrappers/Using/AceUsing.h"
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

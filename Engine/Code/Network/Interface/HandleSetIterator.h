/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:34)

#ifndef NETWORK_NETWORK_INTERFACE_HANDLE_SET_ITERATOR_H
#define NETWORK_NETWORK_INTERFACE_HANDLE_SET_ITERATOR_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Network/Interface/NetworkInternalFwd.h"

NETWORK_NON_COPY_EXPORT_IMPL(HandleSetIteratorImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE HandleSetIterator final
    {
    public:
        NON_COPY_TYPE_DECLARE(HandleSetIterator);

    public:
        explicit HandleSetIterator(const ConfigurationStrategy& configurationStrategy, const HandleSet& handleSet);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ACEHandleType operator()();

    private:
        PackageType impl;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_HANDLE_SET_ITERATOR_H

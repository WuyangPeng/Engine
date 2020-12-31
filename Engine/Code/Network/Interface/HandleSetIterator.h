//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 20:22)

#ifndef NETWORK_NETWORK_INTERFACE_HANDLE_SET_ITERATOR_H
#define NETWORK_NETWORK_INTERFACE_HANDLE_SET_ITERATOR_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Network/ACEWrappers/Using/ACEUsing.h"
#include "Network/Interface/NetworkInternalFwd.h"

#include <boost/noncopyable.hpp>

NETWORK_EXPORT_SHARED_PTR(HandleSetIteratorImpl);
EXPORT_NONCOPYABLE_CLASS(NETWORK);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE HandleSetIterator final : private boost::noncopyable
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(HandleSetIterator);

    public:
        explicit HandleSetIterator(const ConfigurationStrategy& configurationStrategy, const HandleSet& handleSet);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] ACEHandle operator()();

    private:
        IMPL_TYPE_DECLARE(HandleSetIterator);
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_HANDLE_SET_ITERATOR_H

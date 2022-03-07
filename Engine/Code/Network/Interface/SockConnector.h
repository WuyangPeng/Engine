///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/20 17:07)

#ifndef NETWORK_NETWORK_INTERFACE_SOCK_CONNECTOR_H
#define NETWORK_NETWORK_INTERFACE_SOCK_CONNECTOR_H

#include "Network/NetworkDll.h"

#include "NetworkInternalFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

NETWORK_DELAY_COPY_UNSHARED_EXPORT_IMPL(SockConnector, SockConnectorImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE SockConnector final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(SockConnector);

    public:
        explicit SockConnector(const ConfigurationStrategy& configurationStrategy);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool Connect(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress);

        // �첽�ص������뱣֤this��EventInterface��SockStream��SockAddress���������ں��̰߳�ȫ��
        void AsyncConnect(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress);

    private:
        PackageType impl;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SOCK_CONNECTOR_H

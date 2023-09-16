///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/15 09:10)

#ifndef NETWORK_NETWORK_INTERFACE_SOCK_ACCEPTOR_H
#define NETWORK_NETWORK_INTERFACE_SOCK_ACCEPTOR_H

#include "Network/NetworkDll.h"

#include "NetworkInternalFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

NETWORK_NON_COPY_EXPORT_IMPL(SockAcceptorImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE SockAcceptor final
    {
    public:
        NON_COPY_TYPE_DECLARE(SockAcceptor);

    public:
        explicit SockAcceptor(const ConfigurationStrategy& configurationStrategy);
        SockAcceptor(int port, const ConfigurationStrategy& configurationStrategy);
        SockAcceptor(const std::string& hostName, int port, const ConfigurationStrategy& configurationStrategy);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool Accept(SockStream& sockStream, SockAddress& sockAddress);
        NODISCARD bool Accept(SockStream& sockStream);

        // �첽�ص������뱣֤this��EventInterface��SockStream��SockAddress���������ں��̰߳�ȫ��
        void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream);
        void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress);

        NODISCARD bool EnableNonBlock();

        // ACE ר�ã�����������׳��쳣��
        NODISCARD ACEHandleType GetACEHandle();

        // boost ר�ã�����������׳��쳣��
        NODISCARD BoostHandleType GetBoostHandle();

        // Network ר�ã�����������׳��쳣��
        NODISCARD WinSocketType GetWinSocket();

        NODISCARD std::string GetAddress() const;
        NODISCARD int GetPort() const;

    private:
        PackageType impl;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SOCK_ACCEPTOR_H

///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/20 16:45)

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
        using ACEHandleType = ACEHandle;
        using BoostHandleType = boost::asio::ip::tcp::acceptor::native_handle_type;
        using WinSocketType = System::WinSocket;
        using EventInterface = CoreTools::EventInterface;

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
        NODISCARD ACEHandle GetACEHandle();

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

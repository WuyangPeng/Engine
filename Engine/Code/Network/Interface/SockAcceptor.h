//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 20:25)

#ifndef NETWORK_NETWORK_INTERFACE_SOCK_ACCEPTOR_H
#define NETWORK_NETWORK_INTERFACE_SOCK_ACCEPTOR_H

#include "Network/NetworkDll.h"

#include "NetworkInternalFwd.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>

NETWORK_EXPORT_SHARED_PTR(SockAcceptorImpl);
EXPORT_NONCOPYABLE_CLASS(NETWORK);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE SockAcceptor final : private boost::noncopyable
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(SockAcceptor);
        using ACEHandleType = ACEHandle;
        using BoostHandleType = boost::asio::ip::tcp::acceptor::native_handle_type;
        using WinSocketType = System::WinSocket;

    public:
        explicit SockAcceptor(const ConfigurationStrategy& configurationStrategy);
        SockAcceptor(int port, const ConfigurationStrategy& configurationStrategy);
        SockAcceptor(const std::string& hostName, int port, const ConfigurationStrategy& configurationStrategy);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] bool Accept(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress);
        [[nodiscard]] bool Accept(const SockStreamSharedPtr& sockStream);

        // �첽�ص������뱣֤this��EventInterface��SockStream��SockAddress���������ں��̰߳�ȫ��
        void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream);
        void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress);

        [[nodiscard]] bool EnableNonBlock();

        // ACE ר�ã�����������׳��쳣��
        [[nodiscard]] ACEHandle GetACEHandle();

        // boost ר�ã�����������׳��쳣��
        [[nodiscard]] BoostHandleType GetBoostHandle();

        // Network ר�ã�����������׳��쳣��
        [[nodiscard]] WinSocketType GetWinSocket();

        [[nodiscard]] const std::string GetAddress() const;
        [[nodiscard]] int GetPort() const;

    private:
        IMPL_TYPE_DECLARE(SockAcceptor);
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SOCK_ACCEPTOR_H

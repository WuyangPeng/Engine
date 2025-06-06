/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:33)

#ifndef NETWORK_INTERFACE_NETWORK_INTERNAL_FWD_H
#define NETWORK_INTERFACE_NETWORK_INTERNAL_FWD_H

#include "InterfaceFwd.h"
#include "System/Helper/Platform.h"
#include "System/Helper/PragmaWarning/AsioIpTcp.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/MessageEvent/MessageEventFwd.h"
#include "Network/AceWrappers/Using/AceUsing.h"

#include <memory>

namespace Network
{
    class HandleSetImpl;
    class SockStreamImpl;
    class SockAddressImpl;
    class SockAcceptorImpl;
    class SockConnectorImpl;
    class BoostSockStream;
    class BoostSockAcceptor;
    class BaseMainManagerImpl;
    class HandleSetIteratorImpl;

    class BaseMainManagerFactory;
    class HandleSetFactory;
    class HandleSetIteratorFactory;
    class SockAcceptorFactory;
    class SockConnectorFactory;
    class SockStreamFactory;
    class SockAddressFactory;

    class AddressData;
    class MessageBuffer;
    class ConfigurationStrategy;

    CORE_TOOLS_SHARED_PTR_DECLARE(SockStream);
    CORE_TOOLS_SHARED_PTR_DECLARE(SockAddress);
    CORE_TOOLS_SHARED_PTR_DECLARE(SockAcceptor);
    CORE_TOOLS_SHARED_PTR_DECLARE(MessageBuffer);

    using EventInterfaceSharedPtr = std::shared_ptr<CoreTools::EventInterface>;

    using ACEHandleType = ACEHandle;
    using BoostHandleType = boost::asio::ip::tcp::acceptor::native_handle_type;
    using WinSocketType = System::WinSocket;

    using ACEInternetAddressType = ACEInternetAddress;
    using BoostInternetAddressType = boost::asio::ip::tcp::endpoint;
    using WinSockInternetAddressType = System::WinSockInternetAddress;

    using ACESockStreamType = ACESockStreamNativeType;
    using BoostSockStreamType = boost::asio::ip::tcp::socket;
    using WinSocketStreamType = System::WinSocket;

    using IoContextType = boost::asio::io_context;
    using ErrorCodeType = boost::system::error_code;

    static constexpr System::StringView aceLogName{ SYSTEM_TEXT("ACENetwork") };
    static constexpr System::StringView boostLogName{ SYSTEM_TEXT("BoostNetwork") };
}

#endif  // NETWORK_INTERFACE_NETWORK_INTERNAL_FWD_H

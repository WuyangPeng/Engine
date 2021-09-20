///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.4 (2021/06/05 15:04)

#include "Toolset/System/SystemToolset/SystemToolsetExport.h"

#include "TcpSocket.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Contract/Noexcept.h"
#include "Toolset/System/SystemToolset/Helper/SystemToolsetClassInvariantMacro.h"

#include <array>
#include <exception>
#include <iostream>

using std::array;
using std::cout;
using std::exception;
using std::string;

SystemToolset::TcpSocket::TcpSocket(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : winSocket{ System::GetSocket(System::ProtocolFamilies::Inet, System::SocketTypes::Stream, System::SocketProtocols::Tcp) }
{
    if (!System::IsSocketValid(winSocket))
    {
        throw exception("GetSocket 失败。\n");
    }

    SYSTEM_TOOLSET_SELF_CLASS_IS_VALID_1;
}

SystemToolset::TcpSocket::~TcpSocket() noexcept
{
    SYSTEM_TOOLSET_SELF_CLASS_IS_VALID_1;

    CoreTools::NoexceptNoReturn(*this, &ClassType::CloseSocket);
}

#ifdef OPEN_CLASS_INVARIANT
bool SystemToolset::TcpSocket::IsValid() const noexcept
{
    if (System::IsSocketValid(winSocket))
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

System::WinSocket SystemToolset::TcpSocket::GetSocket() noexcept
{
    SYSTEM_TOOLSET_CLASS_IS_VALID_CONST_1;

    return winSocket;
}

void SystemToolset::TcpSocket::CloseSocket()
{
    if (!System::CloseSocket(winSocket))
    {
        cout << "WinSockCleanup失败\n";
    }
}

void SystemToolset::TcpSocket::Connect()
{
    SYSTEM_TOOLSET_CLASS_IS_VALID_CONST_1;

    boost::property_tree::basic_ptree<string, string> mainTree{};

    read_json("Configuration/EnvironmentVariable.json", mainTree);

    const auto port = boost::numeric_cast<uint16_t>(mainTree.get<uint16_t>("TcpPort") + System::GetEngineeringOffsetValue());
    const auto address = mainTree.get<string>("Address");
    const auto connectTime = mainTree.get<int>("ConnectTime");

    WinSockAddrIn addr{};

    addr.sin_family = System::EnumCastUnderlying<uint16_t>(System::AddressFamilies::Inet);
    addr.sin_port = System::GetHostToNetShort(port);
    addr.sin_addr.s_addr = System::GetInetAddr(address.c_str());

    Connect(addr, connectTime);
}

void SystemToolset::TcpSocket::Connect(const WinSockAddrIn& addr, int connectTime)
{
    cout << "准备connect服务器\n";
    auto connectFailureTime = 0;
    while (!System::Connect(winSocket, &addr))
    {
        cout << "connect失败，重新connect服务器\n";

        if (connectTime < connectFailureTime++)
        {
            throw exception("Connect 失败。\n");
        }
    }
}

void SystemToolset::TcpSocket::Send() noexcept
{
    SYSTEM_TOOLSET_CLASS_IS_VALID_CONST_1;

    constexpr auto bufferSize = 256;
    array<char, bufferSize> buffer{ 'H', 'e', 'l', 'l', 'o' };

    auto ret = 0;
    do
    {
        ret = System::Send(winSocket, buffer.data(), bufferSize, System::SocketSend::Default);

    } while (ret == System::g_SocketError);
}

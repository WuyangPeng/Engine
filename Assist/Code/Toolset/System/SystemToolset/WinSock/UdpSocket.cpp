///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/05 17:13)

#include "Toolset/System/SystemToolset/SystemToolsetExport.h"

#include "UdpSocket.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "System/Threading/SyncTools.h"
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

SystemToolset::UdpSocket::UdpSocket(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : winSocket{ System::GetSocket(System::ProtocolFamilies::Inet, System::SocketTypes::Dgram, System::SocketProtocols::Udp) }
{
    if (!System::IsSocketValid(winSocket))
    {
        throw exception("GetSocket 失败。\n");
    }

    SYSTEM_TOOLSET_SELF_CLASS_IS_VALID_1;
}

SystemToolset::UdpSocket::~UdpSocket() noexcept
{
    SYSTEM_TOOLSET_SELF_CLASS_IS_VALID_1;

    CoreTools::NoexceptNoReturn(*this, &ClassType::CloseSocket);
}

#ifdef OPEN_CLASS_INVARIANT

bool SystemToolset::UdpSocket::IsValid() const noexcept
{
    if (System::IsSocketValid(winSocket))
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

System::WinSocket SystemToolset::UdpSocket::GetSocket() noexcept
{
    SYSTEM_TOOLSET_CLASS_IS_VALID_CONST_1;

    return winSocket;
}

void SystemToolset::UdpSocket::CloseSocket()
{
    if (!System::CloseSocket(winSocket))
    {
        cout << "WinSockCleanup失败\n";
    }
}

void SystemToolset::UdpSocket::Send()
{
    SYSTEM_TOOLSET_CLASS_IS_VALID_CONST_1;

    boost::property_tree::basic_ptree<string, string> mainTree{};

    read_json("Configuration/EnvironmentVariable.json", mainTree);

    const auto port = boost::numeric_cast<uint16_t>(mainTree.get<uint16_t>("UdpPort") + System::GetEngineeringOffsetValue());
    const auto address = mainTree.get<string>("Address");

    WinSockAddrIn addr{};

    addr.sin_family = System::EnumCastUnderlying<uint16_t>(System::AddressFamilies::Inet);
    addr.sin_port = System::GetHostToNetShort(port);
    addr.sin_addr.s_addr = System::GetInetAddr(address.c_str());

    Send(addr);
}

void SystemToolset::UdpSocket::Send(const WinSockAddrIn& addr)
{
    constexpr auto bufferSize = 256;
    array<char, bufferSize> buffer{ 'H', 'e', 'l', 'l', 'o' };

    cout << "准备发送消息\n";

    int ret{ 0 };
    do
    {
        ret = System::SendTo(winSocket, buffer.data(), bufferSize, System::SocketSend::Default, &addr);

    } while (ret == System::g_SocketError);
}

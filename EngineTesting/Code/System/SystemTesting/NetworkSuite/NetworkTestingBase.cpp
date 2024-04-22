/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:17)

#include "NetworkTestingBase.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/Flags/WindowsExtensionPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "System/Network/Using/WindowsExtensionPrototypesUsing.h"
#include "System/Network/WindowsExtensionPrototypes.h"
#include "System/Threading/Process.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::NetworkTestingBase::NetworkTestingBase(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, NetworkTestingBase)

void System::NetworkTestingBase::WinSockStartUpTest()
{
    WinSockData wsaData{};

    constexpr auto versionRequested = MakeWord(2, 2);
    const auto startUp = WinSockStartUp(versionRequested, &wsaData);

    ASSERT_EQUAL(startUp, WinSockStartUpReturn::Successful);
}

void System::NetworkTestingBase::WinSockCleanupTest()
{
    const auto cleanup = WinSockCleanup();
    ASSERT_EQUAL(cleanup, WinSockCleanupReturn::Successful);
}

void System::NetworkTestingBase::CloseSocketTest(WinSocket socketHandle)
{
    SYSTEM_CLASS_IS_VALID_1;

    ASSERT_TRUE(CloseSocket(socketHandle));
}

void System::NetworkTestingBase::CreateTcpClientProcessTest()
{
    SYSTEM_CLASS_IS_VALID_1;

    ASSERT_TRUE(CreateSystemProcess(SYSTEM_TEXT("TcpClient")));
}

void System::NetworkTestingBase::CreateUdpClientProcessTest()
{
    SYSTEM_CLASS_IS_VALID_1;

    ASSERT_TRUE(CreateSystemProcess(SYSTEM_TEXT("UdpClient")));
}

uint16_t System::NetworkTestingBase::GetTcpPort() const
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    boost::property_tree::basic_ptree<std::string, std::string> mainTree{};

    read_json("Configuration/EnvironmentVariable.json", mainTree);

    return boost::numeric_cast<uint16_t>(mainTree.get<int>("TcpPort") + GetEngineeringOffsetValue());
}

uint16_t System::NetworkTestingBase::GetUdpPort() const
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    boost::property_tree::basic_ptree<std::string, std::string> mainTree{};

    read_json("Configuration/EnvironmentVariable.json", mainTree);

    return boost::numeric_cast<uint16_t>(mainTree.get<int>("UdpPort") + GetEngineeringOffsetValue());
}

System::WinSockInternetAddress System::NetworkTestingBase::GetAddress(uint16_t port) const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    WinSockInternetAddress address{};

    address.sin_family = EnumCastUnderlying<uint16_t>(AddressFamilies::Internet);
    address.sin_port = GetHostToNetShort(port);
    address.sin_addr.s_addr = GetHostToNetLong(internetAddressAny);

    return address;
}

std::string System::NetworkTestingBase::GetAddress() const
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    boost::property_tree::basic_ptree<std::string, std::string> mainTree{};

    read_json("Configuration/EnvironmentVariable.json", mainTree);

    return mainTree.get<std::string>("Address");
}

System::WinSockInternetAddress System::NetworkTestingBase::GetAddress(uint16_t port, const std::string& hostname) const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    WinSockInternetAddress address{};

    address.sin_family = EnumCastUnderlying<uint16_t>(AddressFamilies::Internet);
    address.sin_port = GetHostToNetShort(port);
    address.sin_addr.s_addr = GetInternetAddress(hostname.c_str());

    return address;
}

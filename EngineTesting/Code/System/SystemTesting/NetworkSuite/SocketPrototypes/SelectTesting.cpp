///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.4 (2021/06/07 13:48)

#include "SelectTesting.h"
#include "System/DynamicLink/LibraryTools.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/Flags/WindowsExtensionPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "System/Network/WindowsExtensionPrototypes.h"
#include "System/Threading/Flags/ProcessFlags.h"
#include "System/Threading/Process.h"
#include "System/Threading/ProcessTools.h"
#include "System/Threading/Thread.h"
#include "CoreTools/FileManager/EnvironmentVariable.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>
#include <thread>
#include <vector>

using std::array;
using std::string;
using std::thread;
using std::vector;

System::SelectTesting::SelectTesting(const OStreamShared& stream)
    : ParentType{ stream }, winSockFdSet{}
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SelectTesting)

void System::SelectTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Init);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(Cleanup);
}

void System::SelectTesting::Init()
{
    WinSockData wsaData{};

    constexpr auto versionRequested = MakeWord(2, 2);
    const auto startUp = WinSockStartUp(versionRequested, &wsaData);

    ASSERT_ENUM_EQUAL(startUp, WinSockStartUpReturn::Successful);
}

void System::SelectTesting::Cleanup()
{
    const auto cleanup = WinSockCleanup();
    ASSERT_ENUM_EQUAL(cleanup, WinSockCleanupReturn::Successful);
}

void System::SelectTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SelectTest);
}

void System::SelectTesting::SelectTest()
{
    ASSERT_TRUE(CreateSystemProcess(SYSTEM_TEXT("TcpClient")));

    boost::property_tree::basic_ptree<string, string> mainTree{};

    read_json("Configuration/EnvironmentVariable.json", mainTree);

    const auto port = boost::numeric_cast<uint16_t>(mainTree.get<uint16_t>("TcpPort") + GetEngineeringOffsetValue());

    thread thread{ &ClassType::SelectThreadTest, this };

    WinSockAddrIn addr{};

    addr.sin_family = EnumCastUnderlying<uint16_t>(AddressFamilies::Inet);
    addr.sin_port = GetHostToNetShort(port);
    addr.sin_addr.s_addr = GetHostToNetLong(g_InAddrAny);

    int addrLen{ sizeof(addr) };

    const auto socketHandle = GetSocket(ProtocolFamilies::Inet, SocketTypes::Stream, SocketProtocols::Tcp);
    ASSERT_TRUE(IsSocketValid(socketHandle));

    ASSERT_TRUE(Bind(socketHandle, &addr));
    ASSERT_TRUE(Listen(socketHandle, 5));

    const auto acceptHandle = Accept(socketHandle, &addr, &addrLen);
    ASSERT_TRUE(IsSocketValid(acceptHandle));

    WinSockSetFd(acceptHandle, &winSockFdSet);

    thread.join();

    ASSERT_TRUE(CloseSocket(socketHandle));
    ASSERT_TRUE(CloseSocket(acceptHandle));
}

void System::SelectTesting::SelectThreadTest()
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

    for (;;)
    {
        auto readWinSockFdSet = winSockFdSet;
        const auto result = Select(0, &readWinSockFdSet, nullptr, nullptr, nullptr);
        if (result != g_SocketError)
        {
            for (auto i = 0u; i < winSockFdSet.fd_count; i++)
            {
                if (WinSockFdIsSet(winSockFdSet.fd_array[i], &readWinSockFdSet))
                {
                    constexpr auto bufferSize = 256;
                    array<char, bufferSize> buffer{};
                    auto index = 0;
                    auto remain = bufferSize;

                    while (0 < remain)
                    {
                        const auto ret = Recv(winSockFdSet.fd_array[i], &buffer.at(index), remain, SocketRecv::Default);

                        ASSERT_UNEQUAL(ret, g_SocketError);

                        if (ret == g_SocketError)
                        {
                            break;
                        }

                        remain -= ret;
                        index += ret;
                    }

                    string recvResult{ buffer.data() };

                    ASSERT_EQUAL(recvResult, "Hello");

                    WinSockFdClear(winSockFdSet.fd_array[i], &winSockFdSet);
                }
            }

            break;
        }
    }

#include STSTEM_WARNING_POP
}

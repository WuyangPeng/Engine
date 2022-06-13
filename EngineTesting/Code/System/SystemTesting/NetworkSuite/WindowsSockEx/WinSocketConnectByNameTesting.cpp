///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/14 16:46)

#include "WinSocketConnectByNameTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/Flags/WindowsExtensionPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "System/Network/WindowsExtensionPrototypes.h"
#include "System/Network/WindowsSockEx.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>
#include <vector>

using std::array;
using std::string;
using std::vector;

System::WinSocketConnectByNameTesting::WinSocketConnectByNameTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WinSocketConnectByNameTesting)

void System::WinSocketConnectByNameTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Init);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(Cleanup);
}

void System::WinSocketConnectByNameTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConnectTest);
}

void System::WinSocketConnectByNameTesting::Init()
{
    WinSockData wsaData{};

    constexpr auto versionRequested = MakeWord(2, 2);
    const auto startUp = WinSockStartUp(versionRequested, &wsaData);

    ASSERT_ENUM_EQUAL(startUp, WinSockStartUpReturn::Successful);
}

void System::WinSocketConnectByNameTesting::Cleanup()
{
    const auto cleanup = WinSockCleanup();
    ASSERT_ENUM_EQUAL(cleanup, WinSockCleanupReturn::Successful);
}

void System::WinSocketConnectByNameTesting::ConnectTest()
{
    boost::property_tree::basic_ptree<String, String> mainTree{};

    read_json("Configuration/EnvironmentVariable.json", mainTree);

    const auto serverHostname = mainTree.get<String>(SYSTEM_TEXT("ConnectHostname"));

    const auto socketHandle = GetWinSocket(ProtocolFamilies::Inet, SocketTypes::Stream, SocketProtocols::Tcp, nullptr, 0, 0);

    ASSERT_TRUE(IsSocketValid(socketHandle));

    ASSERT_TRUE(WinSocketConnectByName(socketHandle, const_cast<TChar*>(serverHostname.c_str()), const_cast<TChar*>(SYSTEM_TEXT("80")), nullptr, nullptr, nullptr, nullptr, nullptr));

    string sendMessage{ "GET /index.html HTTP/1.0\r\n\r\n" };

    vector<char> iov{ sendMessage.begin(), sendMessage.end() };

    uint32_t sendNum{ 0 };

    WinSockBuf buffer{};

    do
    {
        buffer.buf = &iov.at(sendNum);
        buffer.len = boost::numeric_cast<uint32_t>(iov.size() - sendNum);

        WindowsDWord numberOfBytesSent{ boost::numeric_cast<WindowsDWord>(iov.size()) };
        const auto sendResult = WinSocketSend(socketHandle, &buffer, 1, &numberOfBytesSent, 0, nullptr, nullptr);
        if (sendResult != -1)
        {
            sendNum += numberOfBytesSent;
        }
        else
        {
            break;
        }

    } while (sendNum < iov.size());

    constexpr auto buffSize = 1024;

    array<char, buffSize> buf{};

    auto result = 0;
    do
    {
        result = Recv(socketHandle, buf.data(), buffSize, SocketRecv::Default);
        ASSERT_LESS_EQUAL(result, buffSize);
        GetStream() << "�յ�������Ϊ��" << buf.data() << "\n";
    } while (0 < result);

    ASSERT_TRUE(CloseSocket(socketHandle));
}

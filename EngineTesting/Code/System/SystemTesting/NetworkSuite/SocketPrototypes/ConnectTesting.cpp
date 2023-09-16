///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 10:48)

#include "ConnectTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "System/Network/WindowsExtensionPrototypes.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ConnectTesting::ConnectTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ConnectTesting)

void System::ConnectTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WinSockStartUpTest);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(WinSockCleanupTest);
}

void System::ConnectTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConnectTest);
}

void System::ConnectTesting::ConnectTest()
{
    const auto socketHandle = CreateTcpSocket();
    ASSERT_TRUE_FAILURE_THROW(IsSocketValid(socketHandle), "创建Tcp Socket失败。");

    ASSERT_NOT_THROW_EXCEPTION_1(DoConnectTest, socketHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSocketTest, socketHandle);
}

void System::ConnectTesting::DoConnectTest(WinSocket socketHandle)
{
    const auto address = GetAddress(defaultHttpPort, GetConnectHostname());

    ASSERT_TRUE(Connect(socketHandle, &address));

    ASSERT_NOT_THROW_EXCEPTION_1(SendTest, socketHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(RecvTest, socketHandle);
}

void System::ConnectTesting::SendTest(WinSocket socketHandle)
{
    std::string sendMessage{ "GET /index.html HTTP/1.0\r\n\r\n" };

    auto sendNum = 0u;

    std::vector<char> iov{ sendMessage.begin(), sendMessage.end() };

    do
    {
        if (const auto sendCount = Send(socketHandle, &iov.at(sendNum), boost::numeric_cast<int>(iov.size() - sendNum), SocketSend::Default);
            sendCount != socketError)
        {
            sendNum += sendCount;
        }
        else
        {
            break;
        }

    } while (sendNum < iov.size());
}

void System::ConnectTesting::RecvTest(WinSocket socketHandle)
{
    BufferType buffer{};
    std::string data{};

    auto recvCount = 0;
    do
    {
        recvCount = Recv(socketHandle, buffer.data(), bufferSize - 1, SocketRecv::Default);
        ASSERT_LESS_EQUAL(recvCount, bufferSize - 1);

        if (recvCount == socketError)
        {
            break;
        }

        data += buffer.data();

    } while (0 < recvCount);

    GetStream() << "收到的数据为：" << CoreTools::StringConversion::Utf8ConversionMultiByte(data) << "\n";
    ASSERT_FALSE(data.empty());
}

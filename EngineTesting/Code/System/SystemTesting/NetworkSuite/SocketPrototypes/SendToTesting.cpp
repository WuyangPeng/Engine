///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 11:02)

#include "SendToTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SendToTesting::SendToTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SendToTesting)

void System::SendToTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WinSockStartUpTest);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(WinSockCleanupTest);
}

void System::SendToTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SendToTest);
}

void System::SendToTesting::SendToTest()
{
    const auto socketHandle = CreateUdpSocket();
    ASSERT_TRUE_FAILURE_THROW(IsSocketValid(socketHandle), "����Udp Socketʧ�ܡ�");

    ASSERT_NOT_THROW_EXCEPTION_1(DoSendToTest, socketHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSocketTest, socketHandle);
}

void System::SendToTesting::DoSendToTest(WinSocket socketHandle)
{
    const auto address = GetAddress(defaultHttpPort, GetConnectHostname());

    std::string sendMessage{ "GET /index.html HTTP/1.0\r\n\r\n" };

    auto sendNum = 0u;

    std::vector<char> iov{ sendMessage.begin(), sendMessage.end() };

    do
    {
        if (const auto sendCount = SendTo(socketHandle, &iov.at(sendNum), boost::numeric_cast<int>(iov.size() - sendNum), SocketSend::Default, &address);
            sendCount != -1)
        {
            sendNum += sendCount;
        }
        else
        {
            break;
        }

    } while (sendNum < iov.size());
}

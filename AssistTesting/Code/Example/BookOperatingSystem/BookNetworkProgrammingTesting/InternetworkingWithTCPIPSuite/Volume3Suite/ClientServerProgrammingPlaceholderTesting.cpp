///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.3 (2021/09/23 22:11)

#include "ClientServerProgrammingPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookOperatingSystem/ClientServerProgrammingAndApplications/Helper/ClientServerProgrammingAndApplicationsClassInvariantMacro.h"

BookNetworkProgramming::ClientServerProgrammingAndApplications::ClientServerProgrammingPlaceholderTesting::ClientServerProgrammingPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CLIENT_SERVER_PROGRAMMING_AND_APPLICATIONS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookNetworkProgramming::ClientServerProgrammingAndApplications, ClientServerProgrammingPlaceholderTesting)

void BookNetworkProgramming::ClientServerProgrammingAndApplications::ClientServerProgrammingPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookNetworkProgramming::ClientServerProgrammingAndApplications::ClientServerProgrammingPlaceholderTesting::MainTest() noexcept
{
}

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.3 (2021/09/23 22:11)

#include "MultiplayerGameProgrammingPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookOperatingSystem/MultiplayerGameProgramming/Helper/MultiplayerGameProgrammingClassInvariantMacro.h"

BookNetworkProgramming::MultiplayerGameProgramming::MultiplayerGameProgrammingPlaceholderTesting::MultiplayerGameProgrammingPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    MULTIPLAYER_GAME_PROGRAMMING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookNetworkProgramming::MultiplayerGameProgramming, MultiplayerGameProgrammingPlaceholderTesting)

void BookNetworkProgramming::MultiplayerGameProgramming::MultiplayerGameProgrammingPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookNetworkProgramming::MultiplayerGameProgramming::MultiplayerGameProgrammingPlaceholderTesting::MainTest() noexcept
{
}

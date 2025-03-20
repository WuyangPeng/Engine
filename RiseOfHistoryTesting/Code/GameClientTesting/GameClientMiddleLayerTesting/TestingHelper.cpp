/// Copyright (c) 2010-2025
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.2.0 (2025/01/06 10:52)

#include "GameClient/GameClientMiddleLayer/Helper/GameClientMiddleLayerClassInvariantMacro.h"
#include "Testing.h"
#include "TestingHelper.h"

GameClientTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "��Ϸ�ͻ����м�㵥Ԫ����" }
{
    InitSuite();

    GAME_CLIENT_MIDDLE_LAYER_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(GameClientTesting, TestingHelper)

void GameClientTesting::TestingHelper::InitSuite() noexcept
{
}
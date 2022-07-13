///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨�����԰汾��0.8.0.10 (2022/07/09 15:32)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

SceneEditorAssistTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "�����༭������" }
{
    InitSuite();

    USER_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(SceneEditorAssistTesting, TestingHelper)

void SceneEditorAssistTesting::TestingHelper::InitSuite() noexcept
{
}

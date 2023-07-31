///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 19:42)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

SkeletonEditorAssistTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "�����༭������" }
{
    InitSuite();

    USER_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(SkeletonEditorAssistTesting, TestingHelper)

void SkeletonEditorAssistTesting::TestingHelper::InitSuite() noexcept
{
}

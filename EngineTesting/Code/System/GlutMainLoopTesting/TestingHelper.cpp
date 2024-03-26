/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 16:50)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"

GlutMainLoopTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "GlutMainLoop" }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(GlutMainLoopTesting, TestingHelper)

int GlutMainLoopTesting::TestingHelper::DoRun()
{
    SYSTEM_CLASS_IS_VALID_1;

    GlutMainLoop(GetArgc(), GetArgv());
    GlutLeaveMainLoop(GetArgc(), GetArgv());

    return 0;
}

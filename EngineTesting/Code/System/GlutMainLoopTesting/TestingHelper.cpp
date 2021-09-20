///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/07/30 22:42)

#include "GlutMainLoop/GlutMainLoop.h"
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

    GlutMainLoopTesting::GlutMainLoop(GetArgc(), GetArgv());
    GlutMainLoopTesting::GlutLeaveMainLoop(GetArgc(), GetArgv());

    return 0;
}

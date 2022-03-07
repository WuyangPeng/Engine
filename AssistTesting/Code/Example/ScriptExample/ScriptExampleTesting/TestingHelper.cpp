// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨�����԰汾��0.0.2.2 (2020/01/24 19:31)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/ScriptClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

using namespace std::literals;

ScriptExample::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "�ű�����"s }
{
    InitSuite();

    SCRIPT_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ScriptExample, TestingHelper)

void ScriptExample::TestingHelper::InitSuite() noexcept
{
}

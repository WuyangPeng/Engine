// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨�����԰汾��0.0.2.2 (2020/01/23 23:15)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

using namespace std::literals;

NetworkExample::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "��������"s }
{
    InitSuite();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(NetworkExample, TestingHelper)

void NetworkExample::TestingHelper::InitSuite()
{
}

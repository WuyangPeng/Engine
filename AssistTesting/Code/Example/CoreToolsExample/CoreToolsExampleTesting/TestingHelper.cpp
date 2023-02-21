///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨�����԰汾��0.9.0.2 (2023/02/05 15:05)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "Example/System/SystemExample/Helper/SystemExampleClassInvariantMacro.h"

CoreToolsExample::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "���Ĺ��ߡ�����" }
{
    InitSuite();

    SYSTEM_EXAMPLE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreToolsExample, TestingHelper)

void CoreToolsExample::TestingHelper::InitSuite() noexcept
{
}
///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.0 (2021/07/17 11:31)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "Example/System/SystemExample/Helper/SystemExampleClassInvariantMacro.h"

SystemExample::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "ϵͳ������" }
{
    InitSuite();

    SYSTEM_EXAMPLE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(SystemExample, TestingHelper)

void SystemExample::TestingHelper::InitSuite() noexcept
{
}
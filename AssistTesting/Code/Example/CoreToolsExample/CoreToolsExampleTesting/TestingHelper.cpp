/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 15:46)

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
///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 19:25)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"

MillenniumHistory::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "ǧ��ʷ�߲���" }
{
    InitSuite();

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(MillenniumHistory, TestingHelper)

void MillenniumHistory::TestingHelper::InitSuite()
{
    AddVersionSuite();
    AddEngineSuite();
}

void MillenniumHistory::TestingHelper::AddVersionSuite()
{
    auto versionSuite = GenerateSuite("�汾");

    ADD_TEST(versionSuite, VersionTesting);

    AddSuite(versionSuite);
}

void MillenniumHistory::TestingHelper::AddEngineSuite()
{
    auto engineSuite = GenerateSuite("����");

    ADD_TEST(engineSuite, EngineTesting);

    AddSuite(engineSuite);
}

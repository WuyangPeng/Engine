/// Copyright (c) 2010-2025
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.2.0 (2025/01/03 20:14)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"

RiseOfHistoryTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "��ʷ������Ԫ����" }
{
    InitSuite();

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(RiseOfHistoryTesting, TestingHelper)

void RiseOfHistoryTesting::TestingHelper::InitSuite()
{
    AddVersionSuite();
    AddEngineSuite();
}

void RiseOfHistoryTesting::TestingHelper::AddVersionSuite()
{
    auto versionSuite = GenerateSuite("�汾");

    ADD_TEST(versionSuite, VersionTesting);

    AddSuite(versionSuite);
}

void RiseOfHistoryTesting::TestingHelper::AddEngineSuite()
{
    auto engineSuite = GenerateSuite("����");

    ADD_TEST(engineSuite, EngineTesting);

    AddSuite(engineSuite);
}
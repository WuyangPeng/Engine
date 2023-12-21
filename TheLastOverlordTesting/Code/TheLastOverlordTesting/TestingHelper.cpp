/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/17 20:02)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"

TheLastOverlordTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "���İ�����Ԫ����" }
{
    InitSuite();

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(TheLastOverlordTesting, TestingHelper)

void TheLastOverlordTesting::TestingHelper::InitSuite()
{
    AddVersionSuite();
    AddEngineSuite();
}

void TheLastOverlordTesting::TestingHelper::AddVersionSuite()
{
    auto versionSuite = GenerateSuite("�汾");

    ADD_TEST(versionSuite, VersionTesting);

    AddSuite(versionSuite);
}

void TheLastOverlordTesting::TestingHelper::AddEngineSuite()
{
    auto engineSuite = GenerateSuite("����");

    ADD_TEST(engineSuite, EngineTesting);

    AddSuite(engineSuite);
}

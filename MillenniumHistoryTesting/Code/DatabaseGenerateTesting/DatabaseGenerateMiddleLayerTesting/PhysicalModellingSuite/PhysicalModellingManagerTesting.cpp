/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/30 23:03)

#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "PhysicalModellingManagerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"

DatabaseGenerateMiddleLayerTesting::PhysicalModellingManagerTesting::PhysicalModellingManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateMiddleLayerTesting, PhysicalModellingManagerTesting)

void DatabaseGenerateMiddleLayerTesting::PhysicalModellingManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateMiddleLayerTesting::PhysicalModellingManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PhysicalModellingManagerTest);
}

void DatabaseGenerateMiddleLayerTesting::PhysicalModellingManagerTesting::PhysicalModellingManagerTest()
{
    const Framework::EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };
    const DatabaseGenerateMiddleLayer::PhysicalModellingManager physicalModellingManager{ Framework::MiddleLayerPlatform::Windows, environmentDirectory };

    ASSERT_EQUAL(physicalModellingManager.GetMiddleLayerPlatform(), Framework::MiddleLayerPlatform::Windows);
}
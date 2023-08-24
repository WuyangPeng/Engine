///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/01 21:51)

#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "PhysicalModellingManagerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"

DatabaseGenerateServerMiddleLayerTesting::PhysicalModellingManagerTesting::PhysicalModellingManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerMiddleLayerTesting, PhysicalModellingManagerTesting)

void DatabaseGenerateServerMiddleLayerTesting::PhysicalModellingManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateServerMiddleLayerTesting::PhysicalModellingManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PhysicalModellingManagerTest);
}

void DatabaseGenerateServerMiddleLayerTesting::PhysicalModellingManagerTesting::PhysicalModellingManagerTest()
{
    const Framework::EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };
    const DatabaseGenerateServerMiddleLayer::PhysicalModellingManager physicalModellingManager{ Framework::MiddleLayerPlatform::Windows, environmentDirectory };

    ASSERT_EQUAL(physicalModellingManager.GetMiddleLayerPlatform(), Framework::MiddleLayerPlatform::Windows);
}
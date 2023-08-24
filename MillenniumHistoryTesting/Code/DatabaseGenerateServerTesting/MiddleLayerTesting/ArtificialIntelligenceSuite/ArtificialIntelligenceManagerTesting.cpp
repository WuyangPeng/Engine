///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/17 22:47)

#include "ArtificialIntelligenceManagerTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/ArtificialIntelligence/ArtificialIntelligenceManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"

DatabaseGenerateServerMiddleLayerTesting::ArtificialIntelligenceManagerTesting::ArtificialIntelligenceManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerMiddleLayerTesting, ArtificialIntelligenceManagerTesting)

void DatabaseGenerateServerMiddleLayerTesting::ArtificialIntelligenceManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateServerMiddleLayerTesting::ArtificialIntelligenceManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ArtificialIntelligenceManagerTest);
}

void DatabaseGenerateServerMiddleLayerTesting::ArtificialIntelligenceManagerTesting::ArtificialIntelligenceManagerTest()
{
    const Framework::EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };
    const DatabaseGenerateServerMiddleLayer::ArtificialIntelligenceManager artificialIntelligenceManager{ Framework::MiddleLayerPlatform::Windows, environmentDirectory };

    ASSERT_EQUAL(artificialIntelligenceManager.GetMiddleLayerPlatform(), Framework::MiddleLayerPlatform::Windows);
}
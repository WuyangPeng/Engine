/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/26 23:02)

#include "AIManagerTesting.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/ArtificialIntelligence/ArtificialIntelligenceManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"

DatabaseGenerateMiddleLayerTesting::AIManagerTesting::AIManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateMiddleLayerTesting, AIManagerTesting)

void DatabaseGenerateMiddleLayerTesting::AIManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateMiddleLayerTesting::AIManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ArtificialIntelligenceManagerTest);
}

void DatabaseGenerateMiddleLayerTesting::AIManagerTesting::ArtificialIntelligenceManagerTest()
{
    const Framework::EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };
    const DatabaseGenerateMiddleLayer::ArtificialIntelligenceManager artificialIntelligenceManager{ Framework::MiddleLayerPlatform::Windows, environmentDirectory };

    ASSERT_EQUAL(artificialIntelligenceManager.GetMiddleLayerPlatform(), Framework::MiddleLayerPlatform::Windows);
}
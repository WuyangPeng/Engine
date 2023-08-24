///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/01 21:51)

#include "AudioManagerTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/Audio/AudioManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"

DatabaseGenerateServerMiddleLayerTesting::AudioManagerTesting::AudioManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerMiddleLayerTesting, AudioManagerTesting)

void DatabaseGenerateServerMiddleLayerTesting::AudioManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateServerMiddleLayerTesting::AudioManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AudioManagerTest);
}

void DatabaseGenerateServerMiddleLayerTesting::AudioManagerTesting::AudioManagerTest()
{
    const Framework::EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };
    const DatabaseGenerateServerMiddleLayer::AudioManager audioManager{ Framework::MiddleLayerPlatform::Windows, environmentDirectory };

    ASSERT_EQUAL(audioManager.GetMiddleLayerPlatform(), Framework::MiddleLayerPlatform::Windows);
}
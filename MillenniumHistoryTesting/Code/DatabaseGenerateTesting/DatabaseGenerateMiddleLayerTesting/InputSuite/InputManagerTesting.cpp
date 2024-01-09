/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/26 23:01)

#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/Input/InputManagerDetail.h"
#include "InputManagerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"

DatabaseGenerateMiddleLayerTesting::InputManagerTesting::InputManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateMiddleLayerTesting, InputManagerTesting)

void DatabaseGenerateMiddleLayerTesting::InputManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateMiddleLayerTesting::InputManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InputManagerTest);
}

void DatabaseGenerateMiddleLayerTesting::InputManagerTesting::InputManagerTest()
{
    const Framework::EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };
    const DatabaseGenerateMiddleLayer::InputManager<Framework::WindowApplicationTrait> inputManager{ Framework::MiddleLayerPlatform::Windows, environmentDirectory };

    ASSERT_EQUAL(inputManager.GetMiddleLayerPlatform(), Framework::MiddleLayerPlatform::Windows);
}
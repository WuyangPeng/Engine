/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/30 23:03)

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/AncientBooksContainer.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/Resource/ResourceManager.h"
#include "ResourceManagerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"

DatabaseGenerateMiddleLayerTesting::ResourceManagerTesting::ResourceManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateMiddleLayerTesting, ResourceManagerTesting)

void DatabaseGenerateMiddleLayerTesting::ResourceManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateMiddleLayerTesting::ResourceManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ResourceManagerTest);
}

void DatabaseGenerateMiddleLayerTesting::ResourceManagerTesting::ResourceManagerTest()
{
    const Framework::EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };
    const DatabaseGenerateMiddleLayer::ResourceManager resourceManager{ Framework::MiddleLayerPlatform::Windows, environmentDirectory };

    ASSERT_EQUAL(resourceManager.GetMiddleLayerPlatform(), Framework::MiddleLayerPlatform::Windows);
}
///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/05 21:07)

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/SexagenaryCycle.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/SexagenaryCycleContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/SexagenaryCycleEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Convert/ConvertEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "SexagenaryCycleConvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerCoreTesting::SexagenaryCycleConvertTesting::SexagenaryCycleConvertTesting(const OStreamShared& stream, const SexagenaryCycleContainer& sexagenaryCycleContainer)
    : ParentType{ stream }, sexagenaryCycleContainer{ sexagenaryCycleContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerCoreTesting, SexagenaryCycleConvertTesting)

void DatabaseGenerateServerCoreTesting::SexagenaryCycleConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateServerCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& sexagenaryCycle : sexagenaryCycleContainer.GetContainer())
    {
        const auto sexagenaryCycleEntity = convertEntity.Convert(*sexagenaryCycle);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *sexagenaryCycle, sexagenaryCycleEntity);
    }
}

void DatabaseGenerateServerCoreTesting::SexagenaryCycleConvertTesting::EqualTest(const SexagenaryCycle& sexagenaryCycle, const SexagenaryCycleEntity& sexagenaryCycleEntity)
{
    ASSERT_EQUAL(sexagenaryCycleEntity.GetHeavenly(), CoreTools::StringConversion::StandardConversionUtf8(sexagenaryCycle.GetHeavenly()));
    ASSERT_EQUAL(sexagenaryCycleEntity.GetBranch(), CoreTools::StringConversion::StandardConversionUtf8(sexagenaryCycle.GetBranch()));
    ASSERT_EQUAL(sexagenaryCycleEntity.GetName(), CoreTools::StringConversion::StandardConversionUtf8(sexagenaryCycle.GetName()));
}

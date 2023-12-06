/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:52)

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/SexagenaryCycle.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/SexagenaryCycleContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/SexagenaryCycleEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Convert/ConvertEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "SexagenaryCycleConvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateCoreTesting::SexagenaryCycleConvertTesting::SexagenaryCycleConvertTesting(const OStreamShared& stream, const SexagenaryCycleContainer& sexagenaryCycleContainer)
    : ParentType{ stream }, sexagenaryCycleContainer{ sexagenaryCycleContainer }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateCoreTesting, SexagenaryCycleConvertTesting)

void DatabaseGenerateCoreTesting::SexagenaryCycleConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& sexagenaryCycle : sexagenaryCycleContainer.GetContainer())
    {
        const auto sexagenaryCycleEntity = convertEntity.Convert(*sexagenaryCycle);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *sexagenaryCycle, sexagenaryCycleEntity);
    }
}

void DatabaseGenerateCoreTesting::SexagenaryCycleConvertTesting::EqualTest(const SexagenaryCycle& sexagenaryCycle, const SexagenaryCycleEntity& sexagenaryCycleEntity)
{
    ASSERT_EQUAL(sexagenaryCycleEntity.GetHeavenly(), CoreTools::StringConversion::StandardConversionUtf8(sexagenaryCycle.GetHeavenly()));
    ASSERT_EQUAL(sexagenaryCycleEntity.GetBranch(), CoreTools::StringConversion::StandardConversionUtf8(sexagenaryCycle.GetBranch()));
    ASSERT_EQUAL(sexagenaryCycleEntity.GetName(), CoreTools::StringConversion::StandardConversionUtf8(sexagenaryCycle.GetName()));
}

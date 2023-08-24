///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/05 21:18)

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Year.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/YearContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/YearEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "YearConvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Convert/ConvertEntity.h"

DatabaseGenerateServerCoreTesting::YearConvertTesting::YearConvertTesting(const OStreamShared& stream, const YearContainer& yearContainer)
    : ParentType{ stream }, yearContainer{ yearContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerCoreTesting, YearConvertTesting)

void DatabaseGenerateServerCoreTesting::YearConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateServerCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& year : yearContainer.GetContainer())
    {
        const auto yearEntity = convertEntity.Convert(*year);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *year, yearEntity);
    }
}

void DatabaseGenerateServerCoreTesting::YearConvertTesting::EqualTest(const Year& year, const YearEntity& yearEntity)
{
    ASSERT_EQUAL(yearEntity.GetName(), CoreTools::StringConversion::StandardConversionUtf8(year.GetName()));
    ASSERT_EQUAL(yearEntity.GetSexagenaryCycle(), year.GetSexagenaryCycle());
    ASSERT_EQUAL(yearEntity.GetReignTitle(), year.GetReignTitle());
    ASSERT_EQUAL(yearEntity.GetYear(), year.GetYear());
    ASSERT_EQUAL(yearEntity.GetUnorthodoxReignTitle(), year.GetUnorthodoxReignTitle());
    ASSERT_EQUAL(yearEntity.GetUnorthodoxYear(), year.GetUnorthodoxYear());
}

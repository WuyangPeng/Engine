///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/03 23:23)

#include "CountryConvertTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Country.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/CountryContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/CountryEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Convert/ConvertEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerCoreTesting::CountryConvertTesting::CountryConvertTesting(const OStreamShared& stream, const CountryContainer& countryContainer)
    : ParentType{ stream }, countryContainer{ countryContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerCoreTesting, CountryConvertTesting)

void DatabaseGenerateServerCoreTesting::CountryConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateServerCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& country : countryContainer.GetContainer())
    {
        const auto countryEntity = convertEntity.Convert(*country);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *country, countryEntity);
    }
}

void DatabaseGenerateServerCoreTesting::CountryConvertTesting::EqualTest(const Country& country, const CountryEntity& countryEntity)
{
    ASSERT_EQUAL(countryEntity.GetImperialCourt(), country.GetImperialCourt());
    ASSERT_EQUAL(countryEntity.GetCategory(), CoreTools::StringConversion::StandardConversionUtf8(country.GetCategory()));
    ASSERT_EQUAL(countryEntity.GetBeginYear(), country.GetBeginYear());
    ASSERT_EQUAL(countryEntity.GetBeginMonth(), country.GetBeginMonth());
    ASSERT_EQUAL(countryEntity.GetBeginSexagenaryCycle(), country.GetBeginSexagenaryCycle());
    ASSERT_EQUAL(countryEntity.GetBeginDay(), country.GetBeginDay());
    ASSERT_EQUAL(countryEntity.GetEndYear(), country.GetEndYear());
    ASSERT_EQUAL(countryEntity.GetEndMonth(), country.GetEndMonth());
    ASSERT_EQUAL(countryEntity.GetEndSexagenaryCycle(), country.GetEndSexagenaryCycle());
    ASSERT_EQUAL(countryEntity.GetEndDay(), country.GetEndDay());
    ASSERT_EQUAL(countryEntity.GetUnansweredQuestion(), Convert(country.GetUnansweredQuestionBegin(), country.GetUnansweredQuestionEnd()));
}
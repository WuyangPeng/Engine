/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:51)

#include "CountryConvertTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Country.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/CountryContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/CountryEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Convert/ConvertEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateCoreTesting::CountryConvertTesting::CountryConvertTesting(const OStreamShared& stream, const CountryContainer& countryContainer)
    : ParentType{ stream }, countryContainer{ countryContainer }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateCoreTesting, CountryConvertTesting)

void DatabaseGenerateCoreTesting::CountryConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& country : countryContainer.GetContainer())
    {
        const auto countryEntity = convertEntity.Convert(*country);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *country, countryEntity);
    }
}

void DatabaseGenerateCoreTesting::CountryConvertTesting::EqualTest(const Country& country, const CountryEntity& countryEntity)
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
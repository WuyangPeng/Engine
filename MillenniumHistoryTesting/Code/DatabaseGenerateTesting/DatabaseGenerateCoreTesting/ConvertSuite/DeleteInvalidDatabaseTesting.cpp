/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:52)

#include "DatabaseGenerate/DatabaseGenerateCore/Convert/ConvertEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "DeleteInvalidDatabaseTestingDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateCoreTesting::DeleteInvalidDatabaseTesting::DeleteInvalidDatabaseTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream }, ancientBooksContainer{ ancientBooksContainer }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateCoreTesting, DeleteInvalidDatabaseTesting)

void DatabaseGenerateCoreTesting::DeleteInvalidDatabaseTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    ConvertEntity convertEntity{ databaseFlush };

    DatabaseSave(convertEntity, *ancientBooksContainer.GetArticleContainer());
    DatabaseSave(convertEntity, *ancientBooksContainer.GetBookContainer());
    DatabaseSave(convertEntity, *ancientBooksContainer.GetCalendarContainer());
    DatabaseSave(convertEntity, *ancientBooksContainer.GetCategoryContainer());
    DatabaseSave(convertEntity, *ancientBooksContainer.GetCharacterContainer());
    DatabaseSave(convertEntity, *ancientBooksContainer.GetCountryContainer());
    DatabaseSave(convertEntity, *ancientBooksContainer.GetDayContainer());
    DatabaseSave(convertEntity, *ancientBooksContainer.GetEmperorContainer());
    DatabaseSave(convertEntity, *ancientBooksContainer.GetGatherContainer());
    DatabaseSave(convertEntity, *ancientBooksContainer.GetGenusContainer());
    DatabaseSave(convertEntity, *ancientBooksContainer.GetGeographicContainer());
    DatabaseSave(convertEntity, *ancientBooksContainer.GetIdentityContainer());
    DatabaseSave(convertEntity, *ancientBooksContainer.GetImperialCourtContainer());
    DatabaseSave(convertEntity, *ancientBooksContainer.GetMonthContainer());
    DatabaseSave(convertEntity, *ancientBooksContainer.GetReignTitleContainer());
    DatabaseSave(convertEntity, *ancientBooksContainer.GetSexagenaryCycleContainer());
    DatabaseSave(convertEntity, *ancientBooksContainer.GetSourceContainer());
    DatabaseSave(convertEntity, *ancientBooksContainer.GetVersionContainer());
    DatabaseSave(convertEntity, *ancientBooksContainer.GetYearContainer());

    convertEntity.DeleteInvalidDatabase();
}

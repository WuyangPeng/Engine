///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/08 22:18)

#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Convert/ConvertEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "DeleteInvalidDatabaseTestingDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerCoreTesting::DeleteInvalidDatabaseTesting::DeleteInvalidDatabaseTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream }, ancientBooksContainer{ ancientBooksContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerCoreTesting, DeleteInvalidDatabaseTesting)

void DatabaseGenerateServerCoreTesting::DeleteInvalidDatabaseTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
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
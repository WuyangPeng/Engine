///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/16 15:55)

#include "DatabaseGenerateServer/DatabaseGenerateServerCore/DatabaseGenerateServerCoreExport.h"

#include "AncientBooksDatabaseSaveImplDetail.h"

DatabaseGenerateServerCore::AncientBooksDatabaseSaveImpl::AncientBooksDatabaseSaveImpl(const DatabaseFlushSharedPtr& databaseFlush) noexcept
    : databaseFlush{ databaseFlush }, convertEntity{ databaseFlush }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(DatabaseGenerateServerCore, AncientBooksDatabaseSaveImpl)

void DatabaseGenerateServerCore::AncientBooksDatabaseSaveImpl::DatabaseSave(const AncientBooksContainer& ancientBooksContainer)
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_9;

    DatabaseSave(*ancientBooksContainer.GetArticleContainer());
    DatabaseSave(*ancientBooksContainer.GetBookContainer());
    DatabaseSave(*ancientBooksContainer.GetCalendarContainer());
    DatabaseSave(*ancientBooksContainer.GetCategoryContainer());
    DatabaseSave(*ancientBooksContainer.GetCharacterContainer());
    DatabaseSave(*ancientBooksContainer.GetCountryContainer());
    DatabaseSave(*ancientBooksContainer.GetDayContainer());
    DatabaseSave(*ancientBooksContainer.GetEmperorContainer());
    DatabaseSave(*ancientBooksContainer.GetGatherContainer());
    DatabaseSave(*ancientBooksContainer.GetGenusContainer());
    DatabaseSave(*ancientBooksContainer.GetGeographicContainer());
    DatabaseSave(*ancientBooksContainer.GetIdentityContainer());
    DatabaseSave(*ancientBooksContainer.GetImperialCourtContainer());
    DatabaseSave(*ancientBooksContainer.GetMonthContainer());
    DatabaseSave(*ancientBooksContainer.GetReignTitleContainer());
    DatabaseSave(*ancientBooksContainer.GetSexagenaryCycleContainer());
    DatabaseSave(*ancientBooksContainer.GetSourceContainer());
    DatabaseSave(*ancientBooksContainer.GetVersionContainer());
    DatabaseSave(*ancientBooksContainer.GetYearContainer());
}
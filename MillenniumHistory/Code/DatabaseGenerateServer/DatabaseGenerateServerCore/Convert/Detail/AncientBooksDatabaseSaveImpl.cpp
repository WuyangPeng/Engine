///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/30 22:41)

#include "DatabaseGenerateServer/DatabaseGenerateServerCore/DatabaseGenerateServerCoreExport.h"

#include "AncientBooksDatabaseSaveImplDetail.h"
#include "CoreTools/Helper/LogMacro.h"

DatabaseGenerateServerCore::AncientBooksDatabaseSaveImpl::AncientBooksDatabaseSaveImpl(const DatabaseFlushSharedPtr& databaseFlush)
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

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("�������ݿ�����ɾ����"));

    convertEntity.DeleteInvalidDatabase();

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("���ݿ�ɾ������"));
}
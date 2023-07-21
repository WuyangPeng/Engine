///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.1 (2023/07/16 15:55)

#ifndef DATABASE_GENERATE_SERVER_CORE_CONVERT_ANCIENT_BOOKS_DATABASE_SAVE_IMPL_DETAIL_H
#define DATABASE_GENERATE_SERVER_CORE_CONVERT_ANCIENT_BOOKS_DATABASE_SAVE_IMPL_DETAIL_H

#include "AncientBooksDatabaseSaveImpl.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseManagerDetail.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

template <typename T>
void DatabaseGenerateServerCore::AncientBooksDatabaseSaveImpl::DatabaseSave(const T& container)
{
    DATABASE_GENERATE_SERVER_CORE_CLASS_IS_VALID_9;

    const auto databaseName = decltype(convertEntity.Convert(*(container.GetContainer()[0])))::GetDatabaseName();

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("���ݿ�"), databaseName, SYSTEM_TEXT("��ʼд�롣"));

    for (const auto& element : container.GetContainer())
    {
        const auto entity = convertEntity.Convert(*element);

        databaseFlush->ChangeDatabase(entity.GetId(), entity.GetModify());
    }

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("���ݿ�"), databaseName, SYSTEM_TEXT("д����ɡ�"));
}

#endif  // DATABASE_GENERATE_SERVER_CORE_CONVERT_ANCIENT_BOOKS_DATABASE_SAVE_IMPL_DETAIL_H
///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/16 15:55)

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

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("数据库"), databaseName, SYSTEM_TEXT("开始写入。"));

    for (const auto& element : container.GetContainer())
    {
        const auto entity = convertEntity.Convert(*element);

        databaseFlush->ChangeDatabase(entity.GetId(), entity.GetModify());
    }

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("数据库"), databaseName, SYSTEM_TEXT("写入完成。"));
}

#endif  // DATABASE_GENERATE_SERVER_CORE_CONVERT_ANCIENT_BOOKS_DATABASE_SAVE_IMPL_DETAIL_H
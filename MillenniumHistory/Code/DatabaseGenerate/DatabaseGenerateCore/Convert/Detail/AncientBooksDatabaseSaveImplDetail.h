/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/23 22:31)

#ifndef DATABASE_GENERATE_CORE_CONVERT_ANCIENT_BOOKS_DATABASE_SAVE_IMPL_DETAIL_H
#define DATABASE_GENERATE_CORE_CONVERT_ANCIENT_BOOKS_DATABASE_SAVE_IMPL_DETAIL_H

#include "AncientBooksDatabaseSaveImpl.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseManagerDetail.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

template <typename T>
void DatabaseGenerateCore::AncientBooksDatabaseSaveImpl::DatabaseSave(const T& container)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_9;

    const auto databaseName = decltype(convertEntity.Convert(*(container.GetContainer()[0])))::GetDatabaseName();

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("数据库"), databaseName, SYSTEM_TEXT("开始写入。"));

    for (const auto& element : container.GetContainer())
    {
        const auto entity = convertEntity.Convert(*element);

        databaseFlush->ChangeDatabase(entity.GetId(), entity.GetModify());
    }

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("数据库"), databaseName, SYSTEM_TEXT("写入完成。"));
}

#endif  // DATABASE_GENERATE_CORE_CONVERT_ANCIENT_BOOKS_DATABASE_SAVE_IMPL_DETAIL_H
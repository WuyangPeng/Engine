/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 13:37)

#include "Database/DatabaseExport.h"

#include "RedisStatement.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "Database/DatabaseInterface/BasisDatabase.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseField.h"

CLASS_INVARIANT_STUB_DEFINE(Database, RedisStatement)

std::string Database::RedisStatement::GenerateStatement(const std::string& hostName, const BasisDatabaseManager& basisDatabaseManager)
{
    switch (basisDatabaseManager.GetChangeType())
    {
        case ChangeType::Insert:
            return GenerateInsertStatement(hostName, basisDatabaseManager);
        case ChangeType::Update:
            return GenerateUpdateStatement(hostName, basisDatabaseManager);
        case ChangeType::Delete:
            return GenerateDeleteStatement(hostName, basisDatabaseManager);
    }

    return "";
}

std::string Database::RedisStatement::GenerateDeleteStatement(const std::string& hostName, const BasisDatabaseManager& basisDatabaseManager)
{
    return "del " + GenerateKey(hostName, basisDatabaseManager);
}

std::string Database::RedisStatement::GenerateInsertStatement(const std::string& hostName, const BasisDatabaseManager& basisDatabaseManager)
{
    return GenerateUpdateStatement(hostName, basisDatabaseManager);
}

std::string Database::RedisStatement::GenerateUpdateStatement(const std::string& hostName, const BasisDatabaseManager& basisDatabaseManager)
{
    std::string result{};

    result += "hmset " + GenerateKey(hostName, basisDatabaseManager);

    for (const auto container = basisDatabaseManager.GetDatabase();
         const auto& value : container)
    {
        result += " ";
        result += value.GetFieldName();
        result += " ";
        result += value.GetString();
    }

    return result;
}

std::string Database::RedisStatement::GenerateSelectStatement(const std::string& hostName, const FieldNameContainer& fieldNameContainer, const BasisDatabaseManager& basisDatabaseManager)
{
    std::string result{};

    result += "hmget " + GenerateKey(hostName, basisDatabaseManager);

    for (const auto& value : fieldNameContainer)
    {
        result += " ";
        result += value.GetFieldName();
        result += " ";
    }

    return result;
}

std::string Database::RedisStatement::GenerateKey(const std::string& hostName, const BasisDatabaseManager& basisDatabaseManager)
{
    auto result = hostName + ":";

    result += basisDatabaseManager.GetDatabaseName();
    result += ":";

    auto index = 1;
    for (const auto key = basisDatabaseManager.GetKey();
         const auto& value : key)
    {
        result += value.GetQuotationMarkString();

        if (index != key.GetSize())
        {
            result += "_";
        }

        ++index;
    }

    return result;
}
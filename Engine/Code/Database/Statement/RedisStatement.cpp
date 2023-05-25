///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/24 10:30)

#include "Database/DatabaseExport.h"

#include "RedisStatement.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "Database/DatabaseInterface/BasisDatabase.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"
#include "Database/DatabaseInterface/FieldName.h"

CLASS_INVARIANT_STUB_DEFINE(Database, RedisStatement)

std::string Database::RedisStatement::GenerateStatement(const BasisDatabaseContainer& basisDatabaseContainer)
{
    switch (basisDatabaseContainer.GetChangeType())
    {
        case ChangeType::Insert:
            return GenerateInsertStatement(basisDatabaseContainer);
        case ChangeType::Update:
            return GenerateUpdateStatement(basisDatabaseContainer);
        case ChangeType::Delete:
            return GenerateDeleteStatement(basisDatabaseContainer);
    }

    return "";
}

std::string Database::RedisStatement::GenerateDeleteStatement(const BasisDatabaseContainer& basisDatabaseContainer)
{
    return "del " + GenerateKey(basisDatabaseContainer);
}

std::string Database::RedisStatement::GenerateInsertStatement(const BasisDatabaseContainer& basisDatabaseContainer)
{
    return GenerateUpdateStatement(basisDatabaseContainer);
}

std::string Database::RedisStatement::GenerateUpdateStatement(const BasisDatabaseContainer& basisDatabaseContainer)
{
    std::string result{};

    result += "hmset " + GenerateKey(basisDatabaseContainer);

    for (const auto container = basisDatabaseContainer.GetContainer();
         const auto& value : container)
    {
        result += " ";
        result += value.GetFieldName();
        result += " ";
        result += value.GetRedisString();
    }

    return result;
}

std::string Database::RedisStatement::GenerateSelectStatement(const FieldNameContainer& fieldNameContainer, const BasisDatabaseContainer& basisDatabaseContainer)
{
    std::string result{};

    result += "hmget " + GenerateKey(basisDatabaseContainer);

    for (const auto& value : fieldNameContainer)
    {
        result += " ";
        result += value.GetFieldName();
        result += " ";
    }

    return result;
}

std::string Database::RedisStatement::GenerateKey(const BasisDatabaseContainer& basisDatabaseContainer)
{
    std::string result{};

    result += basisDatabaseContainer.GetDatabaseName() + ":";

    auto index = 1u;
    for (const auto key = basisDatabaseContainer.GetKey();
         const auto& value : key)
    {
        result += value.GetRedisString();

        if (index != key.size())
        {
            result += "_";
        }

        ++index;
    }

    return result;
}
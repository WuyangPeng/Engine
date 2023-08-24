///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 15:02)

#include "Database/DatabaseExport.h"

#include "SqlStatement.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "Database/DatabaseInterface/BasisDatabase.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseField.h"

using namespace std::literals;

CLASS_INVARIANT_STUB_DEFINE(Database, SqlStatement)

std::string Database::SqlStatement::GenerateStatement(const BasisDatabaseManager& basisDatabaseManager)
{
    switch (basisDatabaseManager.GetChangeType())
    {
        case ChangeType::Insert:
            return GenerateInsertStatement(basisDatabaseManager);
        case ChangeType::Update:
            return GenerateUpdateStatement(basisDatabaseManager);
        case ChangeType::Delete:
            return GenerateDeleteStatement(basisDatabaseManager);
    }

    return "";
}

std::string Database::SqlStatement::GenerateSelectOneStatement(const FieldNameContainer& fieldNameContainer, const BasisDatabaseManager& basisDatabaseManager)
{
    auto result = GenerateSelectStatement(fieldNameContainer, basisDatabaseManager);

    result += " LIMIT 1;";

    return result;
}

std::string Database::SqlStatement::GenerateSelectAllStatement(const FieldNameContainer& fieldNameContainer, const BasisDatabaseManager& basisDatabaseManager)
{
    auto result = GenerateSelectStatement(fieldNameContainer, basisDatabaseManager);

    result += ";";

    return result;
}

std::string Database::SqlStatement::GenerateDeleteStatement(const BasisDatabaseManager& basisDatabaseManager)
{
    std::string result{};

    result += "DELETE FROM `"s + basisDatabaseManager.GetDatabaseName().data() + "` WHERE ";

    const auto key = basisDatabaseManager.GetKey();
    auto index = 1;
    for (const auto& value : key)
    {
        result += "`";
        result += value.GetFieldName();
        result += "` = ";
        result += value.GetSqlFieldString();

        if (index != key.GetSize())
        {
            result += " AND ";
        }

        ++index;
    }

    result += " LIMIT 1;";

    return result;
}

std::string Database::SqlStatement::GenerateInsertStatement(const BasisDatabaseManager& basisDatabaseManager)
{
    std::string result{};

    result += "INSERT INTO `"s + basisDatabaseManager.GetDatabaseName().data() + "`(";

    const auto container = basisDatabaseManager.GetDatabase();
    auto index = 1;
    for (const auto& value : container)
    {
        result += "`";
        result += value.GetFieldName();
        result += "`";

        if (index != container.GetSize())
        {
            result += " , ";
        }

        ++index;
    }

    result += ") VALUES(";

    index = 1;
    for (const auto& value : container)
    {
        result += value.GetQuotationMarkString();

        if (index != container.GetSize())
        {
            result += " , ";
        }

        ++index;
    }

    result += ");";

    return result;
}

std::string Database::SqlStatement::GenerateUpdateStatement(const BasisDatabaseManager& basisDatabaseManager)
{
    std::string result{};

    result += "UPDATE `"s + basisDatabaseManager.GetDatabaseName().data() + "` SET ";

    const auto container = basisDatabaseManager.GetDatabase();
    auto index = 1;
    for (const auto& value : container)
    {
        result += "`";
        result += value.GetFieldName();
        result += "` = ";
        result += value.GetSqlFieldString();

        if (index != container.GetSize())
        {
            result += " , ";
        }

        ++index;
    }

    result += "WHERE ";

    const auto key = basisDatabaseManager.GetKey();

    index = 1;
    for (const auto& value : key)
    {
        result += "`";
        result += value.GetFieldName();
        result += "` = ";
        result += value.GetSqlFieldString();

        if (index != key.GetSize())
        {
            result += " AND ";
        }

        ++index;
    }

    result += " LIMIT 1;";

    return result;
}

std::string Database::SqlStatement::GenerateSelectStatement(const FieldNameContainer& fieldNameContainer, const BasisDatabaseManager& basisDatabaseManager)
{
    std::string result{};

    result += "SELECT ";

    auto index = 1u;
    for (const auto& value : fieldNameContainer)
    {
        result += "`";
        result += value.GetFieldName();
        result += "`";

        if (index != fieldNameContainer.size())
        {
            result += " , ";
        }

        ++index;
    }

    result += "FROM `"s + basisDatabaseManager.GetDatabaseName().data() + "` WHERE ";

    auto keyIndex = 1;
    for (const auto key = basisDatabaseManager.GetKey();
         const auto& value : key)
    {
        result += "`";
        result += value.GetFieldName();
        result += "` = ";

        result += value.GetSqlFieldString();

        if (keyIndex != key.GetSize())
        {
            result += " AND ";
        }

        ++keyIndex;
    }

    return result;
}

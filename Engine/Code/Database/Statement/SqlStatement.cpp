///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/24 10:30)

#include "Database/DatabaseExport.h"

#include "SqlStatement.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "Database/DatabaseInterface/BasisDatabase.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"
#include "Database/DatabaseInterface/FieldName.h"

CLASS_INVARIANT_STUB_DEFINE(Database, SqlStatement)

std::string Database::SqlStatement::GenerateStatement(const BasisDatabaseContainer& basisDatabaseContainer)
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

std::string Database::SqlStatement::GenerateSelectOneStatement(const FieldNameContainer& fieldNameContainer, const BasisDatabaseContainer& basisDatabaseContainer)
{
    auto result = GenerateSelectStatement(fieldNameContainer, basisDatabaseContainer);

    result += " LIMIT 1;";

    return result;
}

std::string Database::SqlStatement::GenerateSelectAllStatement(const FieldNameContainer& fieldNameContainer, const BasisDatabaseContainer& basisDatabaseContainer)
{
    auto result = GenerateSelectStatement(fieldNameContainer, basisDatabaseContainer);

    result += ";";

    return result;
}

std::string Database::SqlStatement::GenerateDeleteStatement(const BasisDatabaseContainer& basisDatabaseContainer)
{
    std::string result{};

    result += "DELETE FROM `" + basisDatabaseContainer.GetDatabaseName() + "` WHERE ";

    const auto key = basisDatabaseContainer.GetKey();
    auto index = 1u;
    for (const auto& value : key)
    {
        result += "`";
        result += value.GetFieldName();
        result += "` = ";
        result += value.GetSqlString();

        if (index != key.size())
        {
            result += " AND ";
        }

        ++index;
    }

    result += " LIMIT 1;";

    return result;
}

std::string Database::SqlStatement::GenerateInsertStatement(const BasisDatabaseContainer& basisDatabaseContainer)
{
    std::string result{};

    result += "INSERT INTO `" + basisDatabaseContainer.GetDatabaseName() + "`(";

    const auto container = basisDatabaseContainer.GetContainer();
    auto index = 1u;
    for (const auto& value : container)
    {
        result += "`";
        result += value.GetFieldName();
        result += "`";

        if (index != container.size())
        {
            result += " , ";
        }

        ++index;
    }

    result += ") VALUES(";

    index = 1u;
    for (const auto& value : container)
    {
        result += value.GetSqlString();

        if (index != container.size())
        {
            result += " , ";
        }

        ++index;
    }

    result += ");";

    return result;
}

std::string Database::SqlStatement::GenerateUpdateStatement(const BasisDatabaseContainer& basisDatabaseContainer)
{
    std::string result{};

    result += "UPDATE `" + basisDatabaseContainer.GetDatabaseName() + "` SET ";

    const auto container = basisDatabaseContainer.GetContainer();
    auto index = 1u;
    for (const auto& value : container)
    {
        result += "`";
        result += value.GetFieldName();
        result += "` = ";
        result += value.GetSqlString();

        if (index != container.size())
        {
            result += " , ";
        }

        ++index;
    }

    result += "WHERE ";

    const auto key = basisDatabaseContainer.GetKey();

    index = 1u;
    for (const auto& value : key)
    {
        result += "`";
        result += value.GetFieldName();
        result += "` = ";
        result += value.GetSqlString();

        if (index != key.size())
        {
            result += " AND ";
        }

        ++index;
    }

    result += " LIMIT 1;";

    return result;
}

std::string Database::SqlStatement::GenerateSelectStatement(const FieldNameContainer& fieldNameContainer, const BasisDatabaseContainer& basisDatabaseContainer)
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

    result += "FROM `" + basisDatabaseContainer.GetDatabaseName() + "` WHERE ";

    for (const auto key = basisDatabaseContainer.GetKey();
         const auto& value : key)
    {
        result += "`";
        result += value.GetFieldName();
        result += "` = ";

        result += value.GetSqlString();

        if (index != key.size())
        {
            result += " AND ";
        }

        ++index;
    }

    result += ";";

    return result;
}

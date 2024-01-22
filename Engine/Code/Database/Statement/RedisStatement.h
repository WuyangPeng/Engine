/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 13:38)

#ifndef DATABASE_STATEMENT_REDIS_STATEMENT_H
#define DATABASE_STATEMENT_REDIS_STATEMENT_H

#include "Database/DatabaseDll.h"

#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

#include <string>
#include <vector>

namespace Database
{
    class DATABASE_DEFAULT_DECLARE RedisStatement
    {
    public:
        using ClassType = RedisStatement;

        using FieldNameContainer = std::vector<DatabaseField>;

    public:
        CLASS_INVARIANT_DECLARE;

        NODISCARD static std::string GenerateStatement(const std::string& hostName, const BasisDatabaseManager& basisDatabaseManager);
        NODISCARD static std::string GenerateSelectStatement(const std::string& hostName, const FieldNameContainer& fieldNameContainer, const BasisDatabaseManager& basisDatabaseManager);

    private:
        NODISCARD static std::string GenerateInsertStatement(const std::string& hostName, const BasisDatabaseManager& basisDatabaseManager);
        NODISCARD static std::string GenerateUpdateStatement(const std::string& hostName, const BasisDatabaseManager& basisDatabaseManager);
        NODISCARD static std::string GenerateDeleteStatement(const std::string& hostName, const BasisDatabaseManager& basisDatabaseManager);

        NODISCARD static std::string GenerateKey(const std::string& hostName, const BasisDatabaseManager& basisDatabaseManager);
    };

}
#endif  // DATABASE_STATEMENT_REDIS_STATEMENT_H
///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/24 10:30)

#ifndef DATABASE_STATEMENT_SQL_STATEMENT_H
#define DATABASE_STATEMENT_SQL_STATEMENT_H

#include "Database/DatabaseDll.h"

#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

#include <string>
#include <vector>

namespace Database
{
    class DATABASE_DEFAULT_DECLARE SqlStatement
    {
    public:
        using ClassType = SqlStatement;
        using FieldNameContainer = std::vector<DatabaseField>;

    public:
        CLASS_INVARIANT_DECLARE;

        NODISCARD static std::string GenerateStatement(const BasisDatabaseManager& basisDatabaseManager);
        NODISCARD static std::string GenerateSelectOneStatement(const FieldNameContainer& fieldNameContainer, const BasisDatabaseManager& basisDatabaseManager);
        NODISCARD static std::string GenerateSelectAllStatement(const FieldNameContainer& fieldNameContainer, const BasisDatabaseManager& basisDatabaseManager);

    private:
        NODISCARD static std::string GenerateInsertStatement(const BasisDatabaseManager& basisDatabaseManager);
        NODISCARD static std::string GenerateUpdateStatement(const BasisDatabaseManager& basisDatabaseManager);
        NODISCARD static std::string GenerateDeleteStatement(const BasisDatabaseManager& basisDatabaseManager);
        NODISCARD static std::string GenerateSelectStatement(const FieldNameContainer& fieldNameContainer, const BasisDatabaseManager& basisDatabaseManager);
    };

}
#endif  // DATABASE_STATEMENT_SQL_STATEMENT_H
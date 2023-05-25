///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/25 10:05)

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
        using FieldNameContainer = std::vector<FieldName>;

    public:
        CLASS_INVARIANT_DECLARE;

        NODISCARD static std::string GenerateStatement(const BasisDatabaseContainer& basisDatabaseContainer);
        NODISCARD static std::string GenerateSelectStatement(const FieldNameContainer& fieldNameContainer, const BasisDatabaseContainer& basisDatabaseContainer);

    private:
        NODISCARD static std::string GenerateInsertStatement(const BasisDatabaseContainer& basisDatabaseContainer);
        NODISCARD static std::string GenerateUpdateStatement(const BasisDatabaseContainer& basisDatabaseContainer);
        NODISCARD static std::string GenerateDeleteStatement(const BasisDatabaseContainer& basisDatabaseContainer);

        NODISCARD static std::string GenerateKey(const BasisDatabaseContainer& basisDatabaseContainer);
    };

}
#endif  // DATABASE_STATEMENT_REDIS_STATEMENT_H
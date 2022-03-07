///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 14:44)

#ifndef DATABASE_SQL_INTERFACE_COLLECTION_H
#define DATABASE_SQL_INTERFACE_COLLECTION_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Database/SqlInterface/SqlInterfaceFwd.h"

#include <map>
#include <string>

DATABASE_NON_COPY_EXPORT_IMPL(CollectionImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE Collection final
    {
    public:
        NON_COPY_TYPE_DECLARE(Collection);
        using ResultSharedPtr = std::shared_ptr<Result>;
        using BindStatementType = std::map<std::string, std::string>;

    public:
        explicit Collection(const Schema& schema, const std::string& collectionName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ResultSharedPtr ExecuteDoc(const std::string& findStatement, const BindStatementType& bindStatement, int limitStatement);

    private:
        PackageType impl;
    };
}

#endif  // DATABASE_SQL_INTERFACE_COLLECTION_H

///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/25 14:41)

#ifndef DATABASE_SQL_INTERFACE_TABLE_FACTORY_H
#define DATABASE_SQL_INTERFACE_TABLE_FACTORY_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/SqlInterface/SqlInterfaceInternalFwd.h"

#include <string>

namespace Database
{
    class DATABASE_HIDDEN_DECLARE TableFactory final
    {
    public:
        using ClassType = TableFactory;
        using ImplType = TableImpl;
        using ImplTypeSharedPtr = std::shared_ptr<ImplType>;

    public:
        TableFactory() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD static ImplTypeSharedPtr Create(const Schema& schema, const std::string& tableName);
    };
}

#endif  // DATABASE_SQL_INTERFACE_TABLE_FACTORY_H

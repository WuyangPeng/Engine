//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/29 9:57)

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
        using ImplTypePtr = std::shared_ptr<ImplType>;

    public:
        TableFactory() noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] static ImplTypePtr Create(const Schema& schema, const std::string& tableName);
    };
}

#endif  // DATABASE_SQL_INTERFACE_TABLE_FACTORY_H

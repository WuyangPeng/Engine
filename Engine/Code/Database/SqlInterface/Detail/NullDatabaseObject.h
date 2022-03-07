///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/25 13:57)

#ifndef DATABASE_SQL_INTERFACE_NULL_DATABASE_OBJECT_H
#define DATABASE_SQL_INTERFACE_NULL_DATABASE_OBJECT_H

#include "Database/DatabaseDll.h"

#include "DatabaseObjectImpl.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE NullDatabaseObject final : public DatabaseObjectImpl
    {
    public:
        using ClassType = NullDatabaseObject;
        using ParentType = DatabaseObjectImpl;

    public:
        explicit NullDatabaseObject(const ConfigurationStrategy& configurationStrategy) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;
    };
}

#endif  // DATABASE_SQL_INTERFACE_NULL_DATABASE_OBJECT_H

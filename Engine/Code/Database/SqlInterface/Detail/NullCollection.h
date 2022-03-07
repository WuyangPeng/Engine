///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/25 13:55)

#ifndef DATABASE_SQL_INTERFACE_NULL_COLLECTION_H
#define DATABASE_SQL_INTERFACE_NULL_COLLECTION_H

#include "Database/DatabaseDll.h"

#include "CollectionImpl.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE NullCollection final : public CollectionImpl
    {
    public:
        using ClassType = NullCollection;
        using ParentType = CollectionImpl;

    public:
        explicit NullCollection(const ConfigurationStrategy& configurationStrategy) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;
    };
}

#endif  // DATABASE_SQL_INTERFACE_NULL_COLLECTION_H

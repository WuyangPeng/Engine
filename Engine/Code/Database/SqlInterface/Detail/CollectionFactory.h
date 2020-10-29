//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 9:44)

#ifndef DATABASE_SQL_INTERFACE_COLLECTION_FACTORY_H
#define DATABASE_SQL_INTERFACE_COLLECTION_FACTORY_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/SqlInterface/SqlInterfaceInternalFwd.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE CollectionFactory final
    {
    public:
        using ClassType = CollectionFactory;
        using ImplType = CollectionImpl;
        using ImplTypePtr = std::shared_ptr<ImplType>;

    public:
        CollectionFactory() noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] static ImplTypePtr Create(const Schema& schema, const std::string& collectionName);
    };
}

#endif  // DATABASE_SQL_INTERFACE_COLLECTION_FACTORY_H

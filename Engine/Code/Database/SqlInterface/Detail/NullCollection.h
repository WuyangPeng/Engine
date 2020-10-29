//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 9:48)

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

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // DATABASE_SQL_INTERFACE_NULL_COLLECTION_H

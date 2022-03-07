///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 13:45)

#ifndef DATABASE_SQL_INTERFACE_COLLECTION_IMPL_H
#define DATABASE_SQL_INTERFACE_COLLECTION_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/SqlInterface/Result.h"
#include "Database/SqlInterface/SqlInterfaceInternalFwd.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE CollectionImpl
    {
    public:
        using ClassType = CollectionImpl;
        using FactoryType = CollectionFactory;
        using ResultSharedPtr = std::shared_ptr<Result>;
        using BindStatementType = std::map<std::string, std::string>;

    public:
        explicit CollectionImpl(const ConfigurationStrategy& configurationStrategy) noexcept;
        virtual ~CollectionImpl() noexcept = 0;
        CollectionImpl(const CollectionImpl& rhs) noexcept = default;
        CollectionImpl& operator=(const CollectionImpl& rhs) noexcept = default;
        CollectionImpl(CollectionImpl&& rhs) noexcept = default;
        CollectionImpl& operator=(CollectionImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual ResultSharedPtr ExecuteDoc(const std::string& findStatement, const BindStatementType& bindStatement, int limitStatement);

        NODISCARD ConfigurationStrategy GetConfigurationStrategy() const noexcept;

    public:
        ConfigurationStrategy configurationStrategy;
    };
}

#endif  // DATABASE_SQL_INTERFACE_COLLECTION_IMPL_H

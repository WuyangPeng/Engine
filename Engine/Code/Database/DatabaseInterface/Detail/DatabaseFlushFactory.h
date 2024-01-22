/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 13:46)

#ifndef DATABASE_DATABASE_INTERFACE_DATABASE_FLUSH_FACTORY_H
#define DATABASE_DATABASE_INTERFACE_DATABASE_FLUSH_FACTORY_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/DatabaseInterfaceInternalFwd.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE DatabaseFlushFactory
    {
    public:
        using ClassType = DatabaseFlushFactory;

        using DatabaseFlushSharedPtr = std::shared_ptr<DatabaseFlushImpl>;

    public:
        CLASS_INVARIANT_DECLARE;

        NODISCARD static DatabaseFlushSharedPtr Create(const ConfigurationStrategy& configurationStrategy);
    };
}

#endif  // DATABASE_DATABASE_INTERFACE_DATABASE_FLUSH_FACTORY_H
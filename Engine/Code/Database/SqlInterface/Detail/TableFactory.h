// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 11:28)

#ifndef DATABASE_SQL_INTERFACE_TABLE_FACTORY_H
#define DATABASE_SQL_INTERFACE_TABLE_FACTORY_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/SqlInterface/SqlInterfaceInternalFwd.h"

#include <string>

namespace Database
{
    class DATABASE_HIDDEN_DECLARE TableFactory
    {
    public:
        using ClassType = TableFactory;
        using ImplType = TableImpl;
        using ImplTypePtr = std::shared_ptr<ImplType>;

    public:
        TableFactory() noexcept;

        CLASS_INVARIANT_DECLARE;

        static ImplTypePtr Create(const Schema& schema, const std::string& tableName);
    };
}

#endif  // DATABASE_SQL_INTERFACE_TABLE_FACTORY_H

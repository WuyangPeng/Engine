// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 11:27)

#ifndef DATABASE_SQL_INTERFACE_SESSION_FACTORY_H
#define DATABASE_SQL_INTERFACE_SESSION_FACTORY_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/SqlInterface/SqlInterfaceInternalFwd.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE SessionFactory
    {
    public:
        using ClassType = SessionFactory;
        using ImplType = SessionImpl;
        using ImplTypePtr = std::shared_ptr<ImplType>;

    public:
        SessionFactory() noexcept;

        CLASS_INVARIANT_DECLARE;

        static ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy);
        static ImplTypePtr Create(const DatabaseObject& databaseObject);
    };
}

#endif  // DATABASE_SQL_INTERFACE_SESSION_FACTORY_H

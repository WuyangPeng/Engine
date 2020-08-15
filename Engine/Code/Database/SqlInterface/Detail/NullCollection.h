// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 11:25)

#ifndef DATABASE_SQL_INTERFACE_NULL_COLLECTION_H
#define DATABASE_SQL_INTERFACE_NULL_COLLECTION_H

#include "Database/DatabaseDll.h"

#include "CollectionImpl.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE NullCollection : public CollectionImpl
    {
    public:
        using ClassType = NullCollection;
        using ParentType = CollectionImpl;

    public:
        explicit NullCollection(const ConfigurationStrategy& configurationStrategy) noexcept;

        CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
    };
}

#endif  // DATABASE_SQL_INTERFACE_NULL_COLLECTION_H

///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 13:58)

#ifndef DATABASE_SQL_INTERFACE_NULL_SCHEMA_H
#define DATABASE_SQL_INTERFACE_NULL_SCHEMA_H

#include "Database/DatabaseDll.h"

#include "SchemaImpl.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE NullSchema final : public SchemaImpl
    {
    public:
        using ClassType = NullSchema;
        using ParentType = SchemaImpl;

    public:
        explicit NullSchema(const ConfigurationStrategy& configurationStrategy) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;
    };
}

#endif  // DATABASE_SQL_INTERFACE_NULL_SCHEMA_H

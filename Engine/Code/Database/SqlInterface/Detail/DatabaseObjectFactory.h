//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/29 9:46)

#ifndef DATABASE_SQL_INTERFACE_DATABASE_OBJECT_FACTORY_H
#define DATABASE_SQL_INTERFACE_DATABASE_OBJECT_FACTORY_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/SqlInterface/SqlInterfaceInternalFwd.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE DatabaseObjectFactory final
    {
    public:
        using ClassType = DatabaseObjectFactory;
        using ImplType = DatabaseObjectImpl;
        using ImplTypePtr = std::shared_ptr<ImplType>;

    public:
        DatabaseObjectFactory() noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] static ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy);
    };
}

#endif  // DATABASE_SQL_INTERFACE_DATABASE_OBJECT_FACTORY_H

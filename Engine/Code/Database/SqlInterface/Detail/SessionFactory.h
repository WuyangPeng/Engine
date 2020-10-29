//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/29 9:53)

#ifndef DATABASE_SQL_INTERFACE_SESSION_FACTORY_H
#define DATABASE_SQL_INTERFACE_SESSION_FACTORY_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/SqlInterface/SqlInterfaceInternalFwd.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE SessionFactory final
    {
    public:
        using ClassType = SessionFactory;
        using ImplType = SessionImpl;
        using ImplTypePtr = std::shared_ptr<ImplType>;

    public:
        SessionFactory() noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] static ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy);
        [[nodiscard]] static ImplTypePtr Create(const DatabaseObject& databaseObject);
    };
}

#endif  // DATABASE_SQL_INTERFACE_SESSION_FACTORY_H

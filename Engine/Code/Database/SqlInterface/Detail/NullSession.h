//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/29 9:49)

#ifndef DATABASE_SQL_INTERFACE_NULL_SESSION_H
#define DATABASE_SQL_INTERFACE_NULL_SESSION_H

#include "Database/DatabaseDll.h"

#include "SessionImpl.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE NullSession final : public SessionImpl
    {
    public:
        using ClassType = NullSession;
        using ParentType = SessionImpl;

    public:
        explicit NullSession(const ConfigurationStrategy& configurationStrategy) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // DATABASE_SQL_INTERFACE_NULL_SESSION_H

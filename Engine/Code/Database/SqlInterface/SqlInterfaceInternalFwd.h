///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/25 16:21)

#ifndef DATABASE_SQL_INTERFACE_INTERNAL_FWD_H
#define DATABASE_SQL_INTERFACE_INTERNAL_FWD_H

#include "SqlInterfaceFwd.h"

namespace Database
{
    class CollectionImpl;
    class DatabaseObjectImpl;
    class ResultImpl;
    class ResultRowImpl;
    class SchemaImpl;
    class SessionImpl;
    class TableImpl;

    class CollectionFactory;
    class DatabaseObjectFactory;
    class ResultFactory;
    class ResultRowFactory;
    class SchemaFactory;
    class SessionFactory;
    class TableFactory;
}

#endif  // DATABASE_SQL_INTERFACE_INTERNAL_FWD_H
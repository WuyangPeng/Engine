///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/14 15:21)

#ifndef DATABASE_DATABASE_INTERFACE_INTERNAL_FWD_H
#define DATABASE_DATABASE_INTERFACE_INTERNAL_FWD_H

#include "DatabaseInterfaceFwd.h"

namespace Database
{
    class DatabaseFlushFactory;
    class DatabaseFlushImpl;

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

#endif  // DATABASE_DATABASE_INTERFACE_INTERNAL_FWD_H
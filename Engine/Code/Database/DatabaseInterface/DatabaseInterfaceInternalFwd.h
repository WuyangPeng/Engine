///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/22 16:37)

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
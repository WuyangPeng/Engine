///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.9 (2023/05/22 16:37)

#ifndef DATABASE_DATABASE_INTERFACE_FWD_H
#define DATABASE_DATABASE_INTERFACE_FWD_H

#include <string>

namespace Database
{
    enum class DataType;
    enum class IndexType;

    template <DataType Type>
    struct DataTypeTraits;

    class BasisDatabase;
    class BasisDatabaseContainer;
    class BasisDatabaseManager;
    class DatabaseEntity;

    template <const std::string_view& FieldName, DataType Type, IndexType Index>
    class Entity;

    class DatabaseManager;
    class DatabaseFlush;
    class DatabaseField;

    class DatabaseEnvironment;
}

#endif  // DATABASE_DATABASE_INTERFACE_FWD_H
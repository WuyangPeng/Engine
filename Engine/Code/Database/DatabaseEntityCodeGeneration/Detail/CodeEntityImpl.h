///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/14 15:50)

#ifndef DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_ENTITY_IMPL_H
#define DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_ENTITY_IMPL_H

#include "Database/DatabaseDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE CodeEntityImpl final
    {
    public:
        using ClassType = CodeEntityImpl;

        using String = System::String;

    public:
        CodeEntityImpl(String fieldName, String dataType, String indexType);

        NODISCARD bool IsValid() const noexcept;

        NODISCARD String GetFieldName() const;
        NODISCARD String GetDataType() const;
        NODISCARD String GetIndexType() const;

    private:
        String fieldName;
        String dataType;
        String indexType;
    };
}

#endif  // DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_ENTITY_IMPL_H

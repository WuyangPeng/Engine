/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 13:50)

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

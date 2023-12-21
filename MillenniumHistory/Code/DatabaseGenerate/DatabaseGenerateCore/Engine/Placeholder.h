/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/12/17 20:09)

#ifndef DATABASE_GENERATE_CORE_ENGINE_PLACEHOLDER_H
#define DATABASE_GENERATE_CORE_ENGINE_PLACEHOLDER_H

#include "DatabaseGenerate/DatabaseGenerateCore/DatabaseGenerateCoreDll.h"

#include "DatabaseGenerate/DatabaseGenerateCore/Helper/ExportMacro.h"

namespace DatabaseGenerateCore
{
    class DATABASE_GENERATE_CORE_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // DATABASE_GENERATE_CORE_ENGINE_PLACEHOLDER_H
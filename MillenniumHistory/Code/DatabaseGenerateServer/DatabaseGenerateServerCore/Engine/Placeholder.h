///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/19 21:33)

#ifndef DATABASE_GENERATE_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define DATABASE_GENERATE_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "DatabaseGenerateServer/DatabaseGenerateServerCore/DatabaseGenerateServerCoreDll.h"

#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/ExportMacro.h"

namespace DatabaseGenerateServerCore
{
    class DATABASE_GENERATE_SERVER_CORE_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // DATABASE_GENERATE_SERVER_CORE_ENGINE_PLACEHOLDER_H
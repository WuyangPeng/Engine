///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/29 20:50)

#ifndef DATABASE_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define DATABASE_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "DatabaseServer/DatabaseServerCore/DatabaseServerCoreDll.h"

#include "DatabaseServer/DatabaseServerCore/Macro/ExportMacro.h"

namespace DatabaseServerCore
{
    class DATABASE_SERVER_CORE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // DATABASE_SERVER_CORE_ENGINE_PLACEHOLDER_H
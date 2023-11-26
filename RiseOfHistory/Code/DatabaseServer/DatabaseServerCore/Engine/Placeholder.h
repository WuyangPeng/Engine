/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.0 (2023/11/19 00:20)

#ifndef DATABASE_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define DATABASE_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "DatabaseServer/DatabaseServerCore/DatabaseServerCoreDll.h"

#include "DatabaseServer/DatabaseServerCore/Helper/ExportMacro.h"

namespace DatabaseServerCore
{
    class DATABASE_SERVER_CORE_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // DATABASE_SERVER_CORE_ENGINE_PLACEHOLDER_H
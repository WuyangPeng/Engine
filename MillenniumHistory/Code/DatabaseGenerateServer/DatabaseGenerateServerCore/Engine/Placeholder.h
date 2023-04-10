///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	ǧ��ʷ�߰汾��0.9.0.5 (2023/04/03 09:46)

#ifndef DATABASE_GENERATE_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define DATABASE_GENERATE_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "DatabaseGenerateServer/DatabaseGenerateServerCore/DatabaseGenerateServerCoreDll.h"

#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/ExportMacro.h"

namespace DatabaseGenerateServerCore
{
    class DATABASE_GENERATE_SERVER_CORE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // DATABASE_GENERATE_SERVER_CORE_ENGINE_PLACEHOLDER_H
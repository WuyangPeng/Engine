/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/25 20:42)

#ifndef LOGIN_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define LOGIN_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "LoginServer/LoginServerCore/LoginServerCoreDll.h"

#include "LoginServer/LoginServerCore/Helper/ExportMacro.h"

namespace LoginServerCore
{
    class LOGIN_SERVER_CORE_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // LOGIN_SERVER_CORE_ENGINE_PLACEHOLDER_H
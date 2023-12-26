/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/17 19:10)

#ifndef CORSS_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define CORSS_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "CorssServer/CorssServerCore/CorssServerCoreDll.h"

#include "CorssServer/CorssServerCore/Helper/ExportMacro.h"

namespace CorssServerCore
{
    class CORSS_SERVER_CORE_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // CORSS_SERVER_CORE_ENGINE_PLACEHOLDER_H
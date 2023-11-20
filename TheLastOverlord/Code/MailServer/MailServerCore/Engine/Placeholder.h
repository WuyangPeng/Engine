/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.0 (2023/11/18 17:09)

#ifndef MAIL_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define MAIL_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "MailServer/MailServerCore/MailServerCoreDll.h"

#include "MailServer/MailServerCore/Helper/ExportMacro.h"

namespace MailServerCore
{
    class MAIL_SERVER_CORE_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // MAIL_SERVER_CORE_ENGINE_PLACEHOLDER_H
/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/25 20:42)

#ifndef MAIL_SERVER_CORE_HELPER_EXPORT_MACRO_H
#define MAIL_SERVER_CORE_HELPER_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define MAIL_SERVER_CORE_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(MailServerCore, implClassName, MAIL_SERVER_CORE_DEFAULT_DECLARE)

#endif  // MAIL_SERVER_CORE_HELPER_EXPORT_MACRO_H
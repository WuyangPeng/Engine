/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/17 19:45)

#include "MailServerCoreExport.h"

#include "MailServerCoreFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_MAIL_SERVER_CORE_STATIC

DLL_MAIN_FUNCTION(MailServerCore);

#else  // !BUILDING_MAIL_SERVER_CORE_STATIC

CORE_TOOLS_MUTEX_INIT(MailServerCore);

#endif  // BUILDING_MAIL_SERVER_CORE_STATIC
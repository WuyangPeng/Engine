///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.9.0.12 (2023/06/16 16:41)

#include "Mail/MailExport.h"

#include "MailFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_MAIL_STATIC

DLL_MAIN_FUNCTION(Mail);

#else  // !BUILDING_MAIL_STATIC

CORE_TOOLS_MUTEX_INIT(Mail);

#endif  // BUILDING_MAIL_STATIC

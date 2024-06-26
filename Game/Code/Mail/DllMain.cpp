///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 16:06)

#include "Mail/MailExport.h"

#include "MailFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_MAIL_STATIC

DLL_MAIN_FUNCTION(Mail);

#else  // !BUILDING_MAIL_STATIC

CORE_TOOLS_MUTEX_INIT(Mail);

#endif  // BUILDING_MAIL_STATIC

// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/05 23:02)

#include "Mail/MailExport.h"

#include "MailFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h" 

#ifndef BUILDING_MAIL_STATIC

	DLL_MAIN_FUNCTION(Mail);

#else // !BUILDING_MAIL_STATIC

	CORE_TOOLS_MUTEX_INIT(Mail);

#endif // BUILDING_MAIL_STATIC

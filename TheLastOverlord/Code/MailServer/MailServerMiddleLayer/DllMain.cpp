///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/27 14:03)

#include "MailServerMiddleLayerExport.h"

#include "MailServerMiddleLayerFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_MAIL_SERVER_MIDDLE_LAYER_STATIC

DLL_MAIN_FUNCTION(MailServerMiddleLayer);

#else  // !BUILDING_MAIL_SERVER_MIDDLE_LAYER_STATIC

CORE_TOOLS_MUTEX_INIT(MailServerMiddleLayer);

#endif  // BUILDING_MAIL_SERVER_MIDDLE_LAYER_STATIC
// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/11 14:08)

#include "LoginServerMiddleLayerExport.h"

#include "LoginServerMiddleLayerFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_LOGIN_SERVER_MIDDLE_LAYER_STATIC

	DLL_MAIN_FUNCTION(LoginServerMiddleLayer);

#else // !BUILDING_LOGIN_SERVER_MIDDLE_LAYER_STATIC

	CORE_TOOLS_MUTEX_INIT(LoginServerMiddleLayer);

#endif // BUILDING_LOGIN_SERVER_MIDDLE_LAYER_STATIC

// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/11 14:05)

#ifndef LOGIN_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H
#define LOGIN_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h" 

#define LOGIN_SERVER_MIDDLE_LAYER_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(LoginServerMiddleLayer,implClassName,LOGIN_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE) 

#endif // LOGIN_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/11 14:01)

#ifndef LOGIN_SERVER_CORE_MACRO_EXPORT_MACRO_H
#define LOGIN_SERVER_CORE_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h" 

#define LOGIN_SERVER_CORE_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(LoginServerCore,implClassName,LOGIN_SERVER_CORE_DEFAULT_DECLARE) 

#endif // LOGIN_SERVER_CORE_MACRO_EXPORT_MACRO_H

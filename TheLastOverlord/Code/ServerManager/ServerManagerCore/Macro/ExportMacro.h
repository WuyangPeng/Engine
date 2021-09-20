// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.0.1 (2019/10/13 16:38)

#ifndef SERVER_MANAGER_CORE_MACRO_EXPORT_MACRO_H
#define SERVER_MANAGER_CORE_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h" 

#define SERVER_MANAGER_CORE_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(ServerManagerCore,implClassName,SERVER_MANAGER_CORE_DEFAULT_DECLARE) 

#endif // SERVER_MANAGER_CORE_MACRO_EXPORT_MACRO_H

// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.0.1 (2019/10/13 18:55)

#ifndef UPDATE_SERVER_CORE_MACRO_EXPORT_MACRO_H
#define UPDATE_SERVER_CORE_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h" 

#define UPDATE_SERVER_CORE_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(UpdateServerCore,implClassName,UPDATE_SERVER_CORE_DEFAULT_DECLARE) 

#endif // UPDATE_SERVER_CORE_MACRO_EXPORT_MACRO_H

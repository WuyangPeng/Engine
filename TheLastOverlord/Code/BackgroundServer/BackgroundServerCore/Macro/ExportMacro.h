// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.0.1 (2019/10/13 18:06)

#ifndef BACKGROUND_SERVER_CORE_MACRO_EXPORT_MACRO_H
#define BACKGROUND_SERVER_CORE_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h" 

#define BACKGROUND_SERVER_CORE_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(BackgroundServerCore,implClassName,BACKGROUND_SERVER_CORE_DEFAULT_DECLARE) 

#endif // BACKGROUND_SERVER_CORE_MACRO_EXPORT_MACRO_H

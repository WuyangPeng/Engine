// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.0 (2019/10/10 17:49)

#ifndef BACKGROUND_CLIENT_CORE_MACRO_EXPORT_MACRO_H
#define BACKGROUND_CLIENT_CORE_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h" 

#define BACKGROUND_CLIENT_CORE_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(BackgroundClientCore,implClassName,BACKGROUND_CLIENT_CORE_DEFAULT_DECLARE) 

#endif // BACKGROUND_CLIENT_CORE_MACRO_EXPORT_MACRO_H

// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.0 (2019/10/10 16:27)

#ifndef MESSAGE_CLIENT_CORE_MACRO_EXPORT_MACRO_H
#define MESSAGE_CLIENT_CORE_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h" 

#define MESSAGE_CLIENT_CORE_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(MessageClientCore,implClassName,MESSAGE_CLIENT_CORE_DEFAULT_DECLARE) 

#endif // MESSAGE_CLIENT_CORE_MACRO_EXPORT_MACRO_H

// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.0 (2019/10/10 16:48)

#ifndef MESSAGE_CLIENT_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H
#define MESSAGE_CLIENT_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h" 

#define MESSAGE_CLIENT_MIDDLE_LAYER_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(MessageClientMiddleLayer,implClassName,MESSAGE_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE) 

#endif // MESSAGE_CLIENT_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 14:06)

#ifndef OFFLINE_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H
#define OFFLINE_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h" 

#define OFFLINE_SERVER_MIDDLE_LAYER_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(OfflineServerMiddleLayer,implClassName,OFFLINE_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE) 

#endif // OFFLINE_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

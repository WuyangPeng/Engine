// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.0 (2019/10/10 17:57)

#ifndef BACKGROUND_CLIENT_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H
#define BACKGROUND_CLIENT_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h" 

#define BACKGROUND_CLIENT_MIDDLE_LAYER_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(BackgroundClientMiddleLayer,implClassName,BACKGROUND_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE) 

#endif // BACKGROUND_CLIENT_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

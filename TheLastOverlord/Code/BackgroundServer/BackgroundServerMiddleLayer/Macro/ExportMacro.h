// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.0.1 (2019/10/13 18:10)

#ifndef BACKGROUND_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H
#define BACKGROUND_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h" 

#define BACKGROUND_SERVER_MIDDLE_LAYER_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(BackgroundServerMiddleLayer,implClassName,BACKGROUND_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE) 

#endif // BACKGROUND_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H
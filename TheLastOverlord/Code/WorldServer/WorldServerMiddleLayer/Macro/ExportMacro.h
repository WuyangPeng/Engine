// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 13:10)

#ifndef WORLD_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H
#define WORLD_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h" 

#define WORLD_SERVER_MIDDLE_LAYER_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(WorldServerMiddleLayer,implClassName,WORLD_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE) 

#endif // WORLD_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

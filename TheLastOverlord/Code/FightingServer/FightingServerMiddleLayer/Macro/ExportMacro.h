// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 09:46)

#ifndef FIGHTING_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H
#define FIGHTING_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h" 

#define FIGHTING_SERVER_MIDDLE_LAYER_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(FightingServerMiddleLayer,implClassName,FIGHTING_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE) 

#endif // FIGHTING_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

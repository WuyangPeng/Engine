// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 09:36)

#ifndef FIGHTING_SERVER_CORE_MACRO_EXPORT_MACRO_H
#define FIGHTING_SERVER_CORE_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h" 

#define FIGHTING_SERVER_CORE_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(FightingServerCore,implClassName,FIGHTING_SERVER_CORE_DEFAULT_DECLARE) 

#endif // FIGHTING_SERVER_CORE_MACRO_EXPORT_MACRO_H

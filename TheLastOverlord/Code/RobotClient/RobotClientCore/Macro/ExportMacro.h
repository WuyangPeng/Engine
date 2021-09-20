// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.0.0 (2019/10/09 23:38)

#ifndef ROBOT_CLIENT_CORE_MACRO_EXPORT_MACRO_H
#define ROBOT_CLIENT_CORE_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h" 

#define ROBOT_CLIENT_CORE_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(RobotClientCore,implClassName,ROBOT_CLIENT_CORE_DEFAULT_DECLARE) 

#endif // ROBOT_CLIENT_CORE_MACRO_EXPORT_MACRO_H

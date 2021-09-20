// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 16:49)

#ifndef SERVER_MANAGER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H
#define SERVER_MANAGER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h" 

#define SERVER_MANAGER_MIDDLE_LAYER_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(ServerManagerMiddleLayer,implClassName,SERVER_MANAGER_MIDDLE_LAYER_DEFAULT_DECLARE) 

#endif // SERVER_MANAGER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

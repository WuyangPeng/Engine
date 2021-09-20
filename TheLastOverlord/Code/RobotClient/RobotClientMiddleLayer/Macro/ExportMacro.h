// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.0 (2019/10/10 14:33)

#ifndef ROBOT_CLIENT_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H
#define ROBOT_CLIENT_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h" 

#define ROBOT_CLIENT_MIDDLE_LAYER_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(RobotClientMiddleLayer,implClassName,ROBOT_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE) 

#endif // ROBOT_CLIENT_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

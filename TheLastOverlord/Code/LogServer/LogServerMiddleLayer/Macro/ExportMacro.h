// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/12 22:59)

#ifndef LOG_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H
#define LOG_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h" 

#define LOG_SERVER_MIDDLE_LAYER_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(LogServerMiddleLayer,implClassName,LOG_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE) 

#endif // LOG_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/11 10:04)

#ifndef GATEWAY_SERVER_CORE_MACRO_EXPORT_MACRO_H
#define GATEWAY_SERVER_CORE_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h" 

#define GATEWAY_SERVER_CORE_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(GatewayServerCore,implClassName,GATEWAY_SERVER_CORE_DEFAULT_DECLARE) 

#endif // GATEWAY_SERVER_CORE_MACRO_EXPORT_MACRO_H

// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/11 16:58)

#ifndef GAME_SERVER_CORE_MACRO_EXPORT_MACRO_H
#define GAME_SERVER_CORE_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h" 

#define GAME_SERVER_CORE_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(GameServerCore,implClassName,GAME_SERVER_CORE_DEFAULT_DECLARE) 

#endif // GAME_SERVER_CORE_MACRO_EXPORT_MACRO_H

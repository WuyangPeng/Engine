// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.0.1 (2019/10/13 15:48)

#ifndef GAME_MASTER_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H
#define GAME_MASTER_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h" 

#define GAME_MASTER_SERVER_MIDDLE_LAYER_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(GameMasterServerMiddleLayer,implClassName,GAME_MASTER_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE) 

#endif // GAME_MASTER_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

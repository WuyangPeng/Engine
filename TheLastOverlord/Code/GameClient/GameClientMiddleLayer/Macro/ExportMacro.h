// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.2.0 (2020/01/09 22:41)

#ifndef GAME_CLIENT_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H
#define GAME_CLIENT_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h" 

#define GAME_CLIENT_MIDDLE_LAYER_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(GameClientMiddleLayer,implClassName,GAME_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE) 

#endif // GAME_CLIENT_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H
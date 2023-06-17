///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.9.0.12 (2022/07/28 22:24)

#ifndef GAME_MASTER_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H
#define GAME_MASTER_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define GAME_MASTER_SERVER_MIDDLE_LAYER_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(GameMasterServerMiddleLayer, implClassName, GAME_MASTER_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE)

#endif  // GAME_MASTER_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

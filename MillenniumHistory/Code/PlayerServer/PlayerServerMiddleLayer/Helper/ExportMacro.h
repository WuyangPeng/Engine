/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/12/17 20:09)

#ifndef PLAYER_SERVER_MIDDLE_LAYER_HELPER_EXPORT_MACRO_H
#define PLAYER_SERVER_MIDDLE_LAYER_HELPER_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define PLAYER_SERVER_MIDDLE_LAYER_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(PlayerServerMiddleLayer, implClassName, PLAYER_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE)

#endif  // PLAYER_SERVER_MIDDLE_LAYER_HELPER_EXPORT_MACRO_H
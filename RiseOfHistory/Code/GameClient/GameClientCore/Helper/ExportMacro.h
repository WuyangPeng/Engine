///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	��ʷ������汾��0.8.1.0 (2022/08/03 11:07)

#ifndef GAME_CLIENT_CORE_HELPER_EXPORT_MACRO_H
#define GAME_CLIENT_CORE_HELPER_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define GAME_CLIENT_CORE_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(GameClientCore, implClassName, GAME_CLIENT_CORE_DEFAULT_DECLARE)

#endif  // GAME_CLIENT_CORE_HELPER_EXPORT_MACRO_H
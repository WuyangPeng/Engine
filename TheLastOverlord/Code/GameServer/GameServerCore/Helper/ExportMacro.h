/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��0.9.1.3 (2023/08/21 10:42)

#ifndef GAME_SERVER_CORE_HELPER_EXPORT_MACRO_H
#define GAME_SERVER_CORE_HELPER_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define GAME_SERVER_CORE_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(GameServerCore, implClassName, GAME_SERVER_CORE_DEFAULT_DECLARE)

#endif  // GAME_SERVER_CORE_HELPER_EXPORT_MACRO_H
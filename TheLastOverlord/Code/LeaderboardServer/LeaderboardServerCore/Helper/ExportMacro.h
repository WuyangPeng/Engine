/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/17 19:26)

#ifndef LEADERBOARD_SERVER_CORE_HELPER_EXPORT_MACRO_H
#define LEADERBOARD_SERVER_CORE_HELPER_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define LEADERBOARD_SERVER_CORE_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(LeaderboardServerCore, implClassName, LEADERBOARD_SERVER_CORE_DEFAULT_DECLARE)

#endif  // LEADERBOARD_SERVER_CORE_HELPER_EXPORT_MACRO_H
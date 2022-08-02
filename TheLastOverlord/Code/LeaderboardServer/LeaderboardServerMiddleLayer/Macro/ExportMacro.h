///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/26 21:23)

#ifndef LEADERBOARD_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H
#define LEADERBOARD_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define LEADERBOARD_SERVER_MIDDLE_LAYER_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(LeaderboardServerMiddleLayer, implClassName, LEADERBOARD_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE)

#endif  // LEADERBOARD_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

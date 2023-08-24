/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：0.9.1.3 (2023/08/21 10:43)

#ifndef GAME_MASTER_SERVER_CORE_HELPER_EXPORT_MACRO_H
#define GAME_MASTER_SERVER_CORE_HELPER_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define GAME_MASTER_SERVER_CORE_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(GameMasterServerCore, implClassName, GAME_MASTER_SERVER_CORE_DEFAULT_DECLARE)

#endif  // GAME_MASTER_SERVER_CORE_HELPER_EXPORT_MACRO_H
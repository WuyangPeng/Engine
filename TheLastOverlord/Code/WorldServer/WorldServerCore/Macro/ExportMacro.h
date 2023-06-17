///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.9.0.12 (2022/07/25 18:14)

#ifndef WORLD_SERVER_CORE_MACRO_EXPORT_MACRO_H
#define WORLD_SERVER_CORE_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define WORLD_SERVER_CORE_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(WorldServerCore, implClassName, WORLD_SERVER_CORE_DEFAULT_DECLARE)

#endif  // WORLD_SERVER_CORE_MACRO_EXPORT_MACRO_H

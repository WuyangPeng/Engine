///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.9.0.12 (2023/06/17 15:20)

#ifndef WORLD_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H
#define WORLD_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define WORLD_SERVER_MIDDLE_LAYER_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(WorldServerMiddleLayer, implClassName, WORLD_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE)

#endif  // WORLD_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

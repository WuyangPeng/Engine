///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/26 19:20)

#ifndef OFFLINE_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H
#define OFFLINE_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define OFFLINE_SERVER_MIDDLE_LAYER_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(OfflineServerMiddleLayer, implClassName, OFFLINE_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE)

#endif  // OFFLINE_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

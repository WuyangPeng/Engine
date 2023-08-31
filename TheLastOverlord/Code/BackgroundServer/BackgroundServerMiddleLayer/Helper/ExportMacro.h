/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��0.9.1.3 (2023/08/21 10:43)

#ifndef BACKGROUND_SERVER_MIDDLE_LAYER_HELPER_EXPORT_MACRO_H
#define BACKGROUND_SERVER_MIDDLE_LAYER_HELPER_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define BACKGROUND_SERVER_MIDDLE_LAYER_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(BackgroundServerMiddleLayer, implClassName, BACKGROUND_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE)

#endif  // BACKGROUND_SERVER_MIDDLE_LAYER_HELPER_EXPORT_MACRO_H
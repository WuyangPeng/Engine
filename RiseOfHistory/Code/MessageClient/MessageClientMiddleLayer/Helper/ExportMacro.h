/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/17 19:45)

#ifndef MESSAGE_CLIENT_MIDDLE_LAYER_HELPER_EXPORT_MACRO_H
#define MESSAGE_CLIENT_MIDDLE_LAYER_HELPER_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define MESSAGE_CLIENT_MIDDLE_LAYER_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(MessageClientMiddleLayer, implClassName, MESSAGE_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE)

#endif  // MESSAGE_CLIENT_MIDDLE_LAYER_HELPER_EXPORT_MACRO_H
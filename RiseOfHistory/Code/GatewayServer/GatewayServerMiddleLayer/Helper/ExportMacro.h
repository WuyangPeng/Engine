/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.0 (2023/11/19 00:20)

#ifndef GATEWAY_SERVER_MIDDLE_LAYER_HELPER_EXPORT_MACRO_H
#define GATEWAY_SERVER_MIDDLE_LAYER_HELPER_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define GATEWAY_SERVER_MIDDLE_LAYER_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(GatewayServerMiddleLayer, implClassName, GATEWAY_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE)

#endif  // GATEWAY_SERVER_MIDDLE_LAYER_HELPER_EXPORT_MACRO_H
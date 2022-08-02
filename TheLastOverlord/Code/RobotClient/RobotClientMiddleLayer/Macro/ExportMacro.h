///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/22 17:06)

#ifndef ROBOT_CLIENT_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H
#define ROBOT_CLIENT_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define ROBOT_CLIENT_MIDDLE_LAYER_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(RobotClientMiddleLayer, implClassName, ROBOT_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE)

#endif  // ROBOT_CLIENT_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

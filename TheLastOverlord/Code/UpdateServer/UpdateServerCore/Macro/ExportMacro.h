///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/28 23:31)

#ifndef UPDATE_SERVER_CORE_MACRO_EXPORT_MACRO_H
#define UPDATE_SERVER_CORE_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define UPDATE_SERVER_CORE_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(UpdateServerCore, implClassName, UPDATE_SERVER_CORE_DEFAULT_DECLARE)

#endif  // UPDATE_SERVER_CORE_MACRO_EXPORT_MACRO_H

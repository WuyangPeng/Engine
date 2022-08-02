///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/29 18:07)

#ifndef BACKGROUND_SERVER_CORE_MACRO_EXPORT_MACRO_H
#define BACKGROUND_SERVER_CORE_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define BACKGROUND_SERVER_CORE_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(BackgroundServerCore, implClassName, BACKGROUND_SERVER_CORE_DEFAULT_DECLARE)

#endif  // BACKGROUND_SERVER_CORE_MACRO_EXPORT_MACRO_H

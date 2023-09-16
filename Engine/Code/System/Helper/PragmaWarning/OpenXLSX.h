///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/29 10:26)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_OPEN_XLSX_H
#define SYSTEM_HELPER_PRAGMA_WARNING_OPEN_XLSX_H

#include "System/Helper/PragmaWarning.h"

#ifdef CORE_TOOLS_USE_OPEN_XLSX

    #include SYSTEM_WARNING_PUSH

    #include SYSTEM_WARNING_DISABLE(4101)
    #include SYSTEM_WARNING_DISABLE(26440)
    #include SYSTEM_WARNING_DISABLE(26455)
    #include SYSTEM_WARNING_DISABLE(26814)

    #include <OpenXLSX.hpp>

    #include SYSTEM_WARNING_POP

#endif  // CORE_TOOLS_USE_OPEN_XLSX

#endif  // SYSTEM_HELPER_PRAGMA_WARNING_OPEN_XLSX_H

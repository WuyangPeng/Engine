/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/04 20:00)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_OPEN_XLSX_H
#define SYSTEM_HELPER_PRAGMA_WARNING_OPEN_XLSX_H

#include "System/Helper/PragmaWarning.h"

#ifdef CORE_TOOLS_USE_OPEN_XLSX

    #include SYSTEM_WARNING_PUSH

    #include SYSTEM_WARNING_DISABLE(4101)

    #include SYSTEM_WARNING_DISABLE(26440)
    #include SYSTEM_WARNING_DISABLE(26455)
    #include SYSTEM_WARNING_DISABLE(26814)

    #define PUGIXML_HAS_LONG_LONG

    #include <OpenXLSX.hpp>

    #include SYSTEM_WARNING_POP

#endif  // CORE_TOOLS_USE_OPEN_XLSX

#endif  // SYSTEM_HELPER_PRAGMA_WARNING_OPEN_XLSX_H

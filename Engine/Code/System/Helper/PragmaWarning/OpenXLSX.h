///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/29 10:26)

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

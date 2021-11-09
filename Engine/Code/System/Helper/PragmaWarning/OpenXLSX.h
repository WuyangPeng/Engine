///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.3 (2021/09/09 15:09)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_OPENXLSX_H
#define SYSTEM_HELPER_PRAGMA_WARNING_OPENXLSX_H

#include "System/Helper/PragmaWarning.h"

#ifdef CORE_TOOLS_USE_OPENXLSX

    #include STSTEM_WARNING_PUSH

    #include SYSTEM_WARNING_DISABLE(4101)
    #include SYSTEM_WARNING_DISABLE(26440)
    #include SYSTEM_WARNING_DISABLE(26455)
    #include SYSTEM_WARNING_DISABLE(26814)

    #include <OpenXLSX.hpp>

    #include STSTEM_WARNING_POP

#endif  // CORE_TOOLS_USE_OPENXLSX

#endif  // SYSTEM_HELPER_PRAGMA_WARNING_OPENXLSX_H

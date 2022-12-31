///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.5 (2022/12/16 22:03)

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

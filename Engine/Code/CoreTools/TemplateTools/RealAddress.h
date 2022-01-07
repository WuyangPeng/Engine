///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/21 15:24)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_REAL_ADDRESS_H
#define CORE_TOOLS_TEMPLATE_TOOLS_REAL_ADDRESS_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename T>
    NODISCARD T* GetAddress(T& t) noexcept;
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_REAL_ADDRESS_H
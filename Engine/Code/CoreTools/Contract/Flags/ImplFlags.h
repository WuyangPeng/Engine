///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/02/23 11:31)

#ifndef CORE_TOOLS_CONTRACT_IMPL_FLAGS_H
#define CORE_TOOLS_CONTRACT_IMPL_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace CoreTools
{
    enum class ImplCreateUseFactory
    {
        Default,
    };

    enum class ImplCreateUseDefaultConstruction
    {
        Default,
    };
}

#endif  // CORE_TOOLS_CONTRACT_IMPL_FLAGS_H
///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 15:47)

#ifndef CORE_TOOLS_HELPER_FUNCTION_DESCRIBED_MACRO_H
#define CORE_TOOLS_HELPER_FUNCTION_DESCRIBED_MACRO_H

#include "CoreTools/Contract/FunctionDescribed.h"

#define CORE_TOOLS_FUNCTION_DESCRIBED \
    CoreTools::FunctionDescribed(__func__, __FILE__, __LINE__)

#endif  // CORE_TOOLS_HELPER_FUNCTION_DESCRIBED_MACRO_H
///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/08 0:56)

#ifndef CORE_TOOLS_HELPER_FUNCTION_DESCRIBED_MACRO_H
#define CORE_TOOLS_HELPER_FUNCTION_DESCRIBED_MACRO_H

#include "CoreTools/Contract/FunctionDescribed.h"

#define CORE_TOOLS_FUNCTION_DESCRIBED \
    CoreTools::FunctionDescribed(__func__, __FILE__, __LINE__)

#endif  // CORE_TOOLS_HELPER_FUNCTION_DESCRIBED_MACRO_H
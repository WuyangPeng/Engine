/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/19 23:52)

#include "MillenniumHistoryHelper.h"
#include "Framework/Helper/MainFunctionMacro.h"

#include <vld.h>

WINDOWS_MAIN_FUNCTION_USE_PARAMETER(MillenniumHistory,
                                    MillenniumHistoryHelper,
                                    SYSTEM_TEXT("DefaultEnvironment"),
                                    SYSTEM_TEXT(""),
                                    SYSTEM_TEXT("MillenniumHistory.json"))
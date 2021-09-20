///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/23 20:48)

#include "Example/BookCpp/ThinkingInCppVolumeTwo/ThinkingInCppVolumeTwoExport.h"

#include "ThinkingInCppVolumeTwoFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_THINKING_IN_CPP_VOLUME_TWO_STATIC

DLL_MAIN_FUNCTION(ThinkingInCppVolumeTwo);

#else  // BUILDING_THINKING_IN_CPP_VOLUME_TWO_STATIC

CORE_TOOLS_MUTEX_INIT(ThinkingInCppVolumeTwo);

#endif  // !BUILDING_THINKING_IN_CPP_VOLUME_TWO_STATIC

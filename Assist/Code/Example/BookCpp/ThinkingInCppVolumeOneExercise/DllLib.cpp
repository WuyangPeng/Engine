///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/22 22:21)

#include "Example/BookCpp/ThinkingInCppVolumeOneExercise/ThinkingInCppVolumeOneExerciseExport.h"

#include "ThinkingInCppVolumeOneExercise.h"

#ifndef BUILDING_THINKING_IN_CPP_VOLUME_ONE_EXERCISE_STATIC

    #include "DllLib.h"

#else  // BUILDING_THINKING_IN_CPP_VOLUME_ONE_EXERCISE_STATIC

namespace ThinkingInCppVolumeOneExercise
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_THINKING_IN_CPP_VOLUME_ONE_EXERCISE_STATIC

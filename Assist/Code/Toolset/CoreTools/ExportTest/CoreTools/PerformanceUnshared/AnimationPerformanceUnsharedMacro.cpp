///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 19:35)

#include "Animation/AnimationExport.h"

#include "AnimationPerformanceUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/AnimationClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/PerformanceUnshared/AnimationPerformanceUnsharedMacroImpl.h"

Animation::AnimationPerformanceUnsharedMacro::AnimationPerformanceUnsharedMacro(int count)
    : impl{ count }
{
    ANIMATION_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Animation, AnimationPerformanceUnsharedMacro)

int Animation::AnimationPerformanceUnsharedMacro::GetCount() const noexcept
{
    ANIMATION_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

const void* Animation::AnimationPerformanceUnsharedMacro::GetAddress() const noexcept
{
    ANIMATION_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}
///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 19:24)

#include "Animation/AnimationExport.h"

#include "AnimationMacroSharedImpl.h"
#include "CoreTools/Helper/ClassInvariant/AnimationClassInvariantMacro.h"

Animation::AnimationMacroSharedImpl::AnimationMacroSharedImpl(int count) noexcept
    : count{ count }
{
    ANIMATION_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Animation, AnimationMacroSharedImpl)

int Animation::AnimationMacroSharedImpl::GetCount() const noexcept
{
    ANIMATION_CLASS_IS_VALID_CONST_9;

    return count;
}

void Animation::AnimationMacroSharedImpl::SetCount(int aCount) noexcept
{
    ANIMATION_CLASS_IS_VALID_9;

    count = aCount;
}

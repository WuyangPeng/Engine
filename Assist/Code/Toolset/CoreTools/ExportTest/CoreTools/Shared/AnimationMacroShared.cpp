///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 10:24)

#include "Animation/AnimationExport.h"

#include "AnimationMacroShared.h"
#include "CoreTools/Helper/ClassInvariant/AnimationClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/Shared/AnimationMacroSharedImpl.h"

Animation::AnimationMacroShared::AnimationMacroShared(int count)
    : impl{ count }
{
    ANIMATION_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Animation, AnimationMacroShared)

int Animation::AnimationMacroShared::GetCount() const noexcept
{
    ANIMATION_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Animation::AnimationMacroShared::SetCount(int count) noexcept
{
    ANIMATION_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

const void* Animation::AnimationMacroShared::GetAddress() const noexcept
{
    ANIMATION_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}
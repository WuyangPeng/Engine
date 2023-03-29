///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.4 (2023/03/17 09:13)

#include "Animation/AnimationExport.h"

#include "AnimationDelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/AnimationClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/DelayCopyUnshared/AnimationDelayCopyUnsharedMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Animation, AnimationDelayCopyUnsharedMacro)

Animation::AnimationDelayCopyUnsharedMacro::AnimationDelayCopyUnsharedMacro(int count)
    : impl{ count }
{
    ANIMATION_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Animation, AnimationDelayCopyUnsharedMacro)

int Animation::AnimationDelayCopyUnsharedMacro::GetCount() const noexcept
{
    ANIMATION_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Animation::AnimationDelayCopyUnsharedMacro::SetCount(int count)
{
    ANIMATION_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

const void* Animation::AnimationDelayCopyUnsharedMacro::GetAddress() const noexcept
{
    ANIMATION_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}

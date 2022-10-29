///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/18 22:36)

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

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/16 20:21)

#include "Animation/AnimationExport.h"

#include "AnimationTestExportMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/AnimationClassInvariantMacro.h"

Animation::AnimationTestExportMacroImpl::AnimationTestExportMacroImpl(int count) noexcept
    : count{ count }
{
    ANIMATION_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Animation, AnimationTestExportMacroImpl)

int Animation::AnimationTestExportMacroImpl::GetCount() const noexcept
{
    ANIMATION_CLASS_IS_VALID_CONST_9;

    return count;
}

void Animation::AnimationTestExportMacroImpl::SetCount(int aCount) noexcept
{
    ANIMATION_CLASS_IS_VALID_9;

    count = aCount;
}

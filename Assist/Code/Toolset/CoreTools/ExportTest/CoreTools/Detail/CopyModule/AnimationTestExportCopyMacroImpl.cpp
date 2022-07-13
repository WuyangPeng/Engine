///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 13:39)

#include "Animation/AnimationExport.h"

#include "AnimationTestExportCopyMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/AnimationClassInvariantMacro.h"

Animation::AnimationTestExportCopyMacroImpl::AnimationTestExportCopyMacroImpl(int count) noexcept
    : mCount{ count }
{
    ANIMATION_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Animation, AnimationTestExportCopyMacroImpl)

int Animation::AnimationTestExportCopyMacroImpl::GetCount() const noexcept
{
    ANIMATION_CLASS_IS_VALID_CONST_9;

    return mCount;
}

void Animation::AnimationTestExportCopyMacroImpl::SetCount(int count) noexcept
{
    ANIMATION_CLASS_IS_VALID_9;

    mCount = count;
}

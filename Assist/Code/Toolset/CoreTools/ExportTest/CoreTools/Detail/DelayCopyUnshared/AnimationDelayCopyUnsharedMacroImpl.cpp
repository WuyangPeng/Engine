///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/13 17:13)

#include "Animation/AnimationExport.h"

#include "AnimationDelayCopyUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/AnimationClassInvariantMacro.h"

Animation::AnimationDelayCopyUnsharedMacroImpl::AnimationDelayCopyUnsharedMacroImpl(int count) noexcept
    : m_Count{ count }
{
    ANIMATION_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Animation, AnimationDelayCopyUnsharedMacroImpl)

int Animation::AnimationDelayCopyUnsharedMacroImpl::GetCount() const noexcept
{
    ANIMATION_CLASS_IS_VALID_CONST_9;

    return m_Count;
}

void Animation::AnimationDelayCopyUnsharedMacroImpl::SetCount(int count) noexcept
{
    ANIMATION_CLASS_IS_VALID_9;

    m_Count = count;
}

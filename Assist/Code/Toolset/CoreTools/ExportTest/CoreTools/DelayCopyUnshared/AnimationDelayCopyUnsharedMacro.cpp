///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 16:11)

#include "Animation/AnimationExport.h"

#include "AnimationDelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/AnimationClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/DelayCopyUnshared/AnimationDelayCopyUnsharedMacroImpl.h"

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

COPY_UNSHARED_CLONE_SELF_DEFINE(Animation, AnimationDelayCopyUnsharedMacro)

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:57)

#include "Animation/AnimationExport.h"

#include "AnimationTestExportCopyMacro.h"
#include "CoreTools/Helper/ClassInvariant/AnimationClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/CopyModule/AnimationTestExportCopyMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Animation, AnimationTestExportCopyMacro)

Animation::AnimationTestExportCopyMacro::AnimationTestExportCopyMacro(int count)
    : impl{ count }
{
    ANIMATION_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Animation, AnimationTestExportCopyMacro)

int Animation::AnimationTestExportCopyMacro::GetCount() const noexcept
{
    ANIMATION_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Animation::AnimationTestExportCopyMacro::SetCount(int count) noexcept
{
    ANIMATION_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

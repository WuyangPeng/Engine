///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 14:08)

#include "Example/Animation/AnimationExample/AnimationExampleExport.h"

#include "Placeholder.h"
#include "CoreTools/Helper/ClassInvariant/AnimationClassInvariantMacro.h"

AnimationExample::Placeholder::Placeholder() noexcept
{
    ANIMATION_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AnimationExample, Placeholder)

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 11:05)

#include "Example/Script/ScriptExample/ScriptExampleExport.h"

#include "Placeholder.h"
#include "CoreTools/Helper/ClassInvariant/ScriptClassInvariantMacro.h"

ScriptExample::Placeholder::Placeholder() noexcept
{
    SCRIPT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ScriptExample, Placeholder)

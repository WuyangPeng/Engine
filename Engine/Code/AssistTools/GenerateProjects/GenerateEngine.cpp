﻿/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 19:57)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateEngine.h"
#include "Detail/GenerateEngineImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::GenerateEngine::GenerateEngine(const String& input, const String& output)
    : impl{ input, output }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateEngine)

void AssistTools::GenerateEngine::Generate() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_9;

    return impl->Generate();
}

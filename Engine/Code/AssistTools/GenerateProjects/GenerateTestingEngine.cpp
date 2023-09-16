///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/25 09:50)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTestingEngine.h"
#include "Detail/GenerateTestingEngineImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::GenerateTestingEngine::GenerateTestingEngine(const String& input, const String& output)
    : impl{ input, output }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateTestingEngine)

void AssistTools::GenerateTestingEngine::Generate() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_9;

    return impl->Generate();
}

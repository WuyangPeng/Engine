///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/28 15:21)

#include "CoreTools/CoreToolsExport.h"

#include "LogAsynchronousParameter.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/LogManager/AppenderManager.h"

CoreTools::LogAsynchronousParameter::LogAsynchronousParameter(LogMessage message, AppenderManagerSharedPtr appenderManager) noexcept
    : ParentType{}, fileName{}, message{ std::move(message) }, appenderManager{ std::move(appenderManager) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::LogAsynchronousParameter::LogAsynchronousParameter(String fileName, LogMessage message, AppenderManagerSharedPtr appenderManager) noexcept
    : ParentType{}, fileName{ std::move(fileName) }, message{ std::move(message) }, appenderManager{ std::move(appenderManager) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::LogAsynchronousParameter::IsValid() const noexcept
{
    if (ParentType::IsValid() && appenderManager != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void CoreTools::LogAsynchronousParameter::Write()
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (fileName.empty())
    {
        appenderManager->Write(message);
    }
    else
    {
        appenderManager->Write(fileName, message);
    }
}

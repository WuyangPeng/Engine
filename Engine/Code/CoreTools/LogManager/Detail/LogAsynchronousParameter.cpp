///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/06 21:45)

#include "CoreTools/CoreToolsExport.h"

#include "LogAsynchronousParameter.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/LogManager/AppenderManager.h"

CoreTools::LogAsynchronousParameter::LogAsynchronousParameter(const LogMessage& message, const AppenderManagerSharedPtr& appenderManager) noexcept
    : fileName{}, message{ message }, appenderManager{ appenderManager }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::LogAsynchronousParameter::LogAsynchronousParameter(const String& fileName, const LogMessage& message, const AppenderManagerSharedPtr& appenderManager)
    : fileName{ fileName }, message{ message }, appenderManager{ appenderManager }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LogAsynchronousParameter)

void CoreTools::LogAsynchronousParameter::Write() const
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto appenderManagerSharedPtr = appenderManager.lock();

    if (appenderManagerSharedPtr)
    {
        if (fileName.empty())
        {
            appenderManagerSharedPtr->Write(message);
        }
        else
        {
            appenderManagerSharedPtr->Write(fileName, message);
        }
    }
}

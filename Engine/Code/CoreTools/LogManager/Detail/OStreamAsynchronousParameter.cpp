/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 00:42)

#include "CoreTools/CoreToolsExport.h"

#include "OStreamAsynchronousParameter.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/LogManager/AppenderManager.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"
#include "CoreTools/LogManager/LogConsoleTextColorsManager.h"
#include "CoreTools/UnitTestSuite/OStreamSharedDetail.h"

CoreTools::OStreamAsynchronousParameter::OStreamAsynchronousParameter(OStreamShared streamShared, std::string message, LogLevel logLevel) noexcept
    : ParentType{}, streamShared{ std::move(streamShared) }, message{ std::move(message) }, logLevel{ logLevel }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, OStreamAsynchronousParameter)

void CoreTools::OStreamAsynchronousParameter::Write()
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (LogLevel::Trace < logLevel)
    {
        LogConsoleTextColorsManager manager{ streamShared, logLevel };

        streamShared << message;
    }
    else
    {
        streamShared << message;
    }
}

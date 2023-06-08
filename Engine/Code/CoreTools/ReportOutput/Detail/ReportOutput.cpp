///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/05/30 09:40)

#include "CoreTools/CoreToolsExport.h"

#include "ReportOutput.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/LogManager/LogAsynchronous.h"
#include "CoreTools/UnitTestSuite/OStreamSharedDetail.h"

CoreTools::ReportOutput::ReportOutput(const OStreamShared& streamShared) noexcept
    : streamShared{ streamShared }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ReportOutput)

void CoreTools::ReportOutput::PrintString(const std::string& characterString, LogLevel logLevel)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    LOG_ASYNCHRONOUS_SINGLETON.Registered(streamShared, characterString, logLevel);
}

void CoreTools::ReportOutput::PrintNewLine()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    LOG_ASYNCHRONOUS_SINGLETON.Registered(streamShared, "\n");
}

void CoreTools::ReportOutput::PrintNumber(int number, LogLevel logLevel)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    LOG_ASYNCHRONOUS_SINGLETON.Registered(streamShared, std::to_string(number), logLevel);
}

CoreTools::OStreamShared CoreTools::ReportOutput::GetStream() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return streamShared;
}

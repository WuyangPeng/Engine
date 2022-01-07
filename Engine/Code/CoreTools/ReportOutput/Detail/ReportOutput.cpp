///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/21 18:19)

#include "CoreTools/CoreToolsExport.h"

#include "ReportOutput.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/OStreamSharedDetail.h"

using std::string;

CoreTools::ReportOutput::ReportOutput(const OStreamShared& streamShared) noexcept
    : streamShared{ streamShared }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ReportOutput)

void CoreTools::ReportOutput::PrintString(const string& characterString)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    streamShared << characterString;
}

void CoreTools::ReportOutput::PrintNewLine()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    streamShared << '\n';
}

void CoreTools::ReportOutput::PrintNumber(int number)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    streamShared << number;
}

// protected
CoreTools::OStreamShared CoreTools::ReportOutput::GetStream() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return streamShared;
}

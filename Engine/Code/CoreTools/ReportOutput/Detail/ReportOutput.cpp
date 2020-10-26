//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 10:13)

#include "CoreTools/CoreToolsExport.h"

#include "ReportOutput.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/OStreamSharedDetail.h"

using std::ostream;
using std::string;

CoreTools::ReportOutput::ReportOutput(const OStreamShared& streamShared) noexcept
    : m_StreamShared{ streamShared }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ReportOutput)

void CoreTools::ReportOutput::PrintString(const string& characterString)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_StreamShared << characterString;
}

void CoreTools::ReportOutput::PrintNewLine()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_StreamShared << '\n';
}

void CoreTools::ReportOutput::PrintNumber(int number)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_StreamShared << number;
}

// protected
CoreTools::OStreamShared CoreTools::ReportOutput::GetStream() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return m_StreamShared;
}

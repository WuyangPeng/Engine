///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/21 09:56)

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

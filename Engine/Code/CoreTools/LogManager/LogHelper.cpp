///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/28 14:53)

#include "CoreTools/CoreToolsExport.h"

#include "Log.h"
#include "LogHelperDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LogHelper)

void CoreTools::LogHelper::Process(const LogMessage& logMessage)
{
    LOG_SINGLETON.Write(logMessage);
}
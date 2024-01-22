/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 00:44)

#include "CoreTools/CoreToolsExport.h"

#include "Log.h"
#include "LogHelperDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LogHelper)

void CoreTools::LogHelper::Process(const LogMessage& logMessage)
{
    LOG_SINGLETON.Write(logMessage);
}
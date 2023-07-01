///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/19 21:28)

#include "DatabaseGenerateServer/DatabaseGenerateServer/DatabaseGenerateServerHelper.h"
#include "Framework/Helper/MainFunctionMacro.h"

#include <vld.h>

WINDOWS_MAIN_FUNCTION_WITH_INFORMATION(DatabaseGenerateServer,
                                       DatabaseGenerateServerHelper,
                                       SYSTEM_TEXT("Millennium History Database Generate Server"),
                                       SYSTEM_TEXT("DefaultEnvironment"),
                                       SYSTEM_TEXT(""),
                                       1024,
                                       768)

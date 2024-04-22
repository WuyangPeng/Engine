/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/29 23:53)

#include "CoreTools/CoreToolsExport.h"

#include "ErrorFactory.h"
#include "ErrorImpl.h"
#include "NormalError.h"
#include "WindowsError.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "CoreTools/Exception/LastError.h"

CoreTools::ErrorFactory::ErrorImplSharedPtr CoreTools::ErrorFactory::Create(const FunctionDescribed& functionDescribed, const LastError& lastError, const String& message)
{
    return Create(functionDescribed, lastError.GetLastError(), message);
}

CoreTools::ErrorFactory::ErrorImplSharedPtr CoreTools::ErrorFactory::Create(const FunctionDescribed& functionDescribed, WindowError lastError, const String& message)
{
    if (lastError == WindowError::Success)
    {
        return std::make_shared<NormalError>(functionDescribed, message);
    }
    else
    {
        return std::make_shared<WindowsError>(functionDescribed, lastError, message);
    }
}

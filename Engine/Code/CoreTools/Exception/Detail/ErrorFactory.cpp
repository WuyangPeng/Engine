///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/09 12:33)

#include "CoreTools/CoreToolsExport.h"

#include "ErrorFactory.h"
#include "ErrorImpl.h"
#include "NormalError.h"
#include "WindowsError.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "CoreTools/Exception/LastError.h"

using std::make_shared;

// static
CoreTools::ErrorFactory::ErrorImplSharedPtr CoreTools::ErrorFactory::Create(const FunctionDescribed& functionDescribed, const LastError& lastError, const String& message)
{
    return Create(functionDescribed, lastError.GetLastError(), message);
}

// static
CoreTools::ErrorFactory::ErrorImplSharedPtr CoreTools::ErrorFactory::Create(const FunctionDescribed& functionDescribed, WindowError lastError, const String& message)
{
    switch (lastError)
    {
        case WindowError::Success:
            return make_shared<NormalError>(functionDescribed, message);

        default:
            return make_shared<WindowsError>(functionDescribed, lastError, message);
    }
}

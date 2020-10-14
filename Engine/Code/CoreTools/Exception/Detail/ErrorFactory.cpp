//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/12 14:27)

#include "CoreTools/CoreToolsExport.h"

#include "ErrorFactory.h"
#include "ErrorImpl.h"
#include "NormalError.h"
#include "WindowsError.h"
#include "System/Window/Flags/PlatformErrorFlags.h"
#include "CoreTools/Exception/LastError.h"

using std::make_shared;

// static
CoreTools::ErrorFactory::ErrorImplPtr CoreTools::ErrorFactory::CreateError(const FunctionDescribed& functionDescribed, const LastError& lastError, const String& message)
{
    return CreateError(functionDescribed, lastError.GetLastError(), message);
}

// static
CoreTools::ErrorFactory::ErrorImplPtr CoreTools::ErrorFactory::CreateError(const FunctionDescribed& functionDescribed, WindowError lastError, const String& message)
{
    switch (lastError)
    {
        case WindowError::Success:
            return make_shared<NormalError>(functionDescribed, message);

        default:
            return make_shared<WindowsError>(functionDescribed, lastError, message);
    }
}

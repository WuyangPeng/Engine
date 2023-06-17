///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:45)

#include "Framework/FrameworkExport.h"

#include "FontInformationImpl.h"
#include "GlutFontInformation.h"
#include "WindowFontInformation.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Framework/WindowProcess/WindowProcessManager.h"

using namespace std::literals;

CLASS_INVARIANT_STUB_DEFINE(Framework, FontInformationImpl)

Framework::FontInformationImpl::FontInformationImplSharedPtr Framework::FontInformationImpl::Create(WindowsHWnd hwnd)
{
    return std::make_shared<WindowFontInformation>(hwnd);
}

Framework::FontInformationImpl::FontInformationImplSharedPtr Framework::FontInformationImpl::Create(PlatformTypes type)
{
    switch (type)
    {
        case PlatformTypes::Glut:
        {
            return std::make_shared<GlutFontInformation>();
        }

        case PlatformTypes::Window:
        {
            auto hwnd = WINDOW_PROCESS_MANAGER_SINGLETON.GetMainWindowHwnd();
            return Create(hwnd);
        }

        case PlatformTypes::Android:
        case PlatformTypes::Linux:
        case PlatformTypes::Macintosh:
        default:
        {
            THROW_EXCEPTION(SYSTEM_TEXT("无法获取该平台的字体信息！"s));
        }
    }
}

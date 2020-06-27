// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 13:50)

#include "Framework/FrameworkExport.h"

#include "FontInformationImpl.h"
#include "WindowFontInformation.h"
#include "GlutFontInformation.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/WindowProcess/WindowProcessManager.h"

using std::make_shared;
using namespace std::literals;

CLASS_INVARIANT_STUB_DEFINE(Framework, FontInformationImpl)

Framework::FontInformationImpl::FontInformationImplSharedPtr Framework::FontInformationImpl
	::CreateWindowFontInformation(HWnd hwnd)
{
	return make_shared<WindowFontInformation>(hwnd);
}

Framework::FontInformationImpl::FontInformationImplSharedPtr Framework::FontInformationImpl
	::CreateFontInformation(PlatformTypes type)
{
	switch (type)
	{
	case PlatformTypes::Glut:
	{
		return make_shared<GlutFontInformation>();
	}

	case PlatformTypes::Window:
	{
		auto hwnd = WINDOW_PROCESS_MANAGER_SINGLETON.GetMainWindowHwnd();
		return CreateWindowFontInformation(hwnd);
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

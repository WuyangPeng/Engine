// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 11:15)

#include "Framework/FrameworkExport.h"

#include "FontInformationImpl.h"
#include "WindowFontInformation.h"
#include "GlutFontInformation.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/WindowProcess/WindowProcessManager.h"

Framework::FontInformationImpl
	::FontInformationImpl()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::FontInformationImpl
	::~FontInformationImpl()
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework,FontInformationImpl)

Framework::FontInformationImpl::FontInformationImplPtr Framework::FontInformationImpl
	::CreateWindowFontInformation( HWnd hwnd )
{
	return FontInformationImplPtr(new WindowFontInformation(hwnd));
}

Framework::FontInformationImpl::FontInformationImplPtr Framework::FontInformationImpl
	::CreateFontInformation(PlatformTypes type)
{
	switch(type)
	{		
	case PlatformTypesGlut:
		{
			return FontInformationImplPtr(new GlutFontInformation);
		}
		
	case PlatformTypesWindow:
		{
			HWnd hwnd = WINDOW_PROCESS_MANAGER_SINGLETON.GetMainWindowHwnd();
			return CreateWindowFontInformation(hwnd);
		}

	case PlatformTypesAndroid:
	default:
		{
			THROW_EXCEPTION(SYSTEM_TEXT("无法获取该平台的字体信息！"));
		}
	}	
}

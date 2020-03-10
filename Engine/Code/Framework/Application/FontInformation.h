// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/08/01 11:08)

#ifndef FRAMEWORK_APPLICATION_FONT_INFORMATION_H
#define FRAMEWORK_APPLICATION_FONT_INFORMATION_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"
#include "System/Window/Flags/WindowFlags.h"
#include "ApplicationTrait.h"
 
#include <string>

FRAMEWORK_EXPORT_SHARED_PTR(FontInformationImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE FontInformation
	{
	public:
		PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(FontInformation);
		using HWnd = System::WindowHWnd;

	public:
		// GLUT ƽ̨
		explicit FontInformation(PlatformTypes type);

		// Window ƽ̨
		explicit FontInformation(HWnd hwnd);

		CLASS_INVARIANT_DECLARE;

		// ������Ϣ����Щ���ض���ƽ̨�ġ�
		int GetStringWidth (const System::String& text) const;
		int GetCharacterWidth (const System::TChar character) const;
		int GetFontHeight () const;

	private:
		IMPL_TYPE_DECLARE(FontInformation);
	};

}

#endif // FRAMEWORK_APPLICATION_FONT_INFORMATION_H

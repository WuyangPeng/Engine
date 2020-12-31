// Copyright (c) 2010-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.3.0.1 (2020/05/21 13:43)

#ifndef FRAMEWORK_APPLICATION_FONT_INFORMATION_H
#define FRAMEWORK_APPLICATION_FONT_INFORMATION_H

#include "Framework/FrameworkDll.h"

#include "Flags/ApplicationTrait.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"
#include "System/Window/Flags/WindowFlags.h"
#include "CoreTools/Helper/ExportMacro.h"

FRAMEWORK_EXPORT_SHARED_PTR(FontInformationImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE FontInformation
	{
	public:
		PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(FontInformation);
		using TChar = System::TChar;
		using String = System::String;
		using HWnd = System::WindowHWnd;

	public:
		// GLUT ƽ̨
		explicit FontInformation(PlatformTypes type);

		// Window ƽ̨
		explicit FontInformation(HWnd hwnd);

		CLASS_INVARIANT_DECLARE;

		// ������Ϣ����Щ���ض���ƽ̨�ġ�
		int GetStringWidth(const String& text) const;
		int GetCharacterWidth(const TChar character) const;
		int GetFontHeight() const;

	private:
		IMPL_TYPE_DECLARE(FontInformation);
	};
}

#endif // FRAMEWORK_APPLICATION_FONT_INFORMATION_H

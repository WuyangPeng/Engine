// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 10:42)

// 窗口图示类的声明
#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_PICTORIAL_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_PICTORIAL_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Flags/WindowFlags.h" 
#include "System/Window/Using/WindowUsing.h"
#include "System/Window/Using/WindowPictorialUsing.h"
#include "System/Window/Flags/WindowPictorialFlags.h"

FRAMEWORK_EXPORT_SHARED_PTR(WindowPictorialImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE WindowPictorial
	{
	public:
		PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(WindowPictorial);
		using HInstance = System::WindowHInstance;
		using HIcon = System::WindowHIcon;
		using HCursor = System::WindowHCursor;
		using HBrush = System::WindowHBrush;

	public:
		explicit WindowPictorial(System::WindowBrushTypes background = System::WindowBrushTypes::WhiteBrush);
		WindowPictorial(const System::TChar* icon,const System::TChar* cursor,System::WindowBrushTypes background = System::WindowBrushTypes::WhiteBrush);
		WindowPictorial(HInstance hInstance,int icon,int cursor,System::WindowBrushTypes background = System::WindowBrushTypes::WhiteBrush);
		WindowPictorial(HInstance hInstance,int icon,const System::TChar* cursor,System::WindowBrushTypes background = System::WindowBrushTypes::WhiteBrush);
		WindowPictorial(HInstance hInstance,const System::TChar* icon,int cursor,System::WindowBrushTypes background = System::WindowBrushTypes::WhiteBrush);

		CLASS_INVARIANT_DECLARE;

		HIcon GetHIcon() const;
		HCursor GetHCursor() const;
		HBrush GetHBrush() const;

	private:
		IMPL_TYPE_DECLARE(WindowsPictorial);
	};
}

#endif // FRAMEWORK_WINDOW_REGISTER_WINDOW_PICTORIAL_H

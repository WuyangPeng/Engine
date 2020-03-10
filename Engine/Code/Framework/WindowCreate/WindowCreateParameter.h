// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 09:37)

#ifndef FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_PARAMETER_H
#define FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_PARAMETER_H

#include "Framework/FrameworkDll.h"

#include "WindowPoint.h"
#include "WindowStyles.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h" 

#include <string>

FRAMEWORK_EXPORT_SHARED_PTR(WindowCreateParameterImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE WindowCreateParameter
	{
	public:
		PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(WindowCreateParameter);
        using HWnd = System::WindowHWnd;
        using HMenu = System::WindowHMenu;

	public:
		explicit WindowCreateParameter(const System::String& windowsName,
			                           WindowStylesFlags style = System::WindowStyles::OverlappedWindow | System::WindowStyles::Visible,
									   HWnd parent = nullptr, HMenu menu = nullptr,
									   const WindowPoint& leftTopCorner = WindowPoint(static_cast<int>(System::WindowPointUse::Default), static_cast<int>(System::WindowPointUse::Default)));
		
		CLASS_INVARIANT_DECLARE;

		System::String GetWindowsName() const;
		WindowStylesFlags GetStyle() const;
		WindowPoint GetLeftTopCorner() const;
		HWnd GetParent() const;
		HMenu GetMenu() const;

	private:
		IMPL_TYPE_DECLARE(WindowCreateParameter);
	};
}

#endif // FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_PARAMETER_H

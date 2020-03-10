// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 09:37)

#ifndef FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_H
#define FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <string>
 
FRAMEWORK_EXPORT_SHARED_PTR(WindowCreateHandleImpl);
EXPORT_NONCOPYABLE_CLASS(FRAMEWORK);

namespace Framework
{
	class WindowInstanceParameter;
	class WindowCreateParameter;
	class WindowSize;

	class FRAMEWORK_DEFAULT_DECLARE WindowCreateHandle : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(WindowCreateHandle);
        using HWnd = System::WindowHWnd;

	public:
		WindowCreateHandle(const WindowInstanceParameter& windowInstanceParameter,
						   const WindowCreateParameter& windowCreateParameter,
						   const WindowSize& size);		
		
		CLASS_INVARIANT_DECLARE;	

		HWnd GetHwnd() const;
		
		void SetMainWindow();

	private:	
		IMPL_TYPE_DECLARE(WindowCreateParameter);
	};
}

#endif // FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_H
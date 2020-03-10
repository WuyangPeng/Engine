// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 09:55)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_LOOP_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_LOOP_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "System/Window/WindowProcess.h"

#include <boost/noncopyable.hpp>

FRAMEWORK_EXPORT_SHARED_PTR(WindowMessageLoopImpl);
EXPORT_NONCOPYABLE_CLASS(FRAMEWORK);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE WindowMessageLoop : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(WindowMessageLoop);
		using WParam = System::WindowWParam;
		using HWnd = System::WindowHWnd;

	public:
		explicit WindowMessageLoop(System::DisplayPtr function);
		
		CLASS_INVARIANT_DECLARE;	

		WParam EnterMessageLoop(HWnd hwnd);

	private:
		IMPL_TYPE_DECLARE(WindowMessageLoop);
	};
}

#endif // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_LOOP_H

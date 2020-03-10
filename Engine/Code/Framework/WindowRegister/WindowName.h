// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 10:42)

#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_NAME_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_NAME_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/shared_ptr.hpp>
#include <string>

FRAMEWORK_EXPORT_SHARED_PTR(WindowNameImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE WindowName
	{
	public:
		PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(WindowName);	

	public:
		explicit WindowName(const System::String& className, const System::String& menuName = System::String());			

		CLASS_INVARIANT_DECLARE;

		const System::String& GetWindowClassName() const;
		const System::String& GetWindowMenuName() const;	

	private:	
		IMPL_TYPE_DECLARE(WindowName);
	};
}

#endif // FRAMEWORK_WINDOW_REGISTER_WINDOW_NAME_H
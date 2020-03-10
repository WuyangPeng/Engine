// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 09:38)

#ifndef FRAMEWORK_WINDOW_CREATE_WINDOW_INSTANCE_PARAMETER_H
#define FRAMEWORK_WINDOW_CREATE_WINDOW_INSTANCE_PARAMETER_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

FRAMEWORK_EXPORT_SHARED_PTR(WindowInstanceParameterImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE WindowInstanceParameter
	{
	public:
		PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(WindowInstanceParameter);
        using HInstance = System::WindowHInstance;

	public:
		WindowInstanceParameter(HInstance hInstance, const System::String& className);			
		
		CLASS_INVARIANT_DECLARE;	

		HInstance GetHInstance() const;
		System::String GetWindowClassName() const;

	private:	
		IMPL_TYPE_DECLARE(WindowInstanceParameter);
	};
}

#endif // FRAMEWORK_WINDOW_CREATE_WINDOW_INSTANCE_PARAMETER_H
// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 09:45)

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
		using String = System::String;
		using HInstance = System::WindowHInstance;	

	public:
		WindowInstanceParameter(HInstance instance, const String& className);

		CLASS_INVARIANT_DECLARE;

		HInstance GetHInstance() const noexcept;
		const String GetWindowClassName() const;

	private:
		IMPL_TYPE_DECLARE(WindowInstanceParameter);
	};
}

#endif // FRAMEWORK_WINDOW_CREATE_WINDOW_INSTANCE_PARAMETER_H
// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 11:53)

#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_NAME_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_NAME_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
FRAMEWORK_PERFORMANCE_UNSHARED_EXPORT_IMPL(WindowNameImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE WindowName
	{
	public:
		PERFORMANCE_UNSHARED_TYPE_DECLARE(WindowName);
		using String = System::String;

	public:
		explicit WindowName(const String& className, const String& menuName = String{ });

		CLASS_INVARIANT_DECLARE;

		const String GetWindowClassName() const;
		const String GetWindowMenuName() const;

	private:
                PackageType impl;
	};
}

#endif // FRAMEWORK_WINDOW_REGISTER_WINDOW_NAME_H
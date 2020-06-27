// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 18:07)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_CONSOLE_TEXT_COLOR_MANAGER_H
#define CORE_TOOLS_LOG_MANAGER_LOG_CONSOLE_TEXT_COLOR_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <iosfwd>

CORE_TOOLS_EXPORT_SHARED_PTR(LogConsoleTextColorsManagerImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	enum class LogLevel;
	class OStreamShared;

	class CORE_TOOLS_DEFAULT_DECLARE LogConsoleTextColorsManager : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(LogConsoleTextColorsManager);  

	public:
		explicit LogConsoleTextColorsManager(LogLevel logLevel);
		LogConsoleTextColorsManager(const OStreamShared& osPtr,LogLevel logLevel);

		CLASS_INVARIANT_DECLARE;

	private:
		IMPL_TYPE_DECLARE(LogConsoleTextColorsManager);		
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_LOG_CONSOLE_TEXT_COLOR_MANAGER_H

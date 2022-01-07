///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.6 (2021/11/21 20:53)

#include "Example/BookOperatingSystem/LinuxCommandLineAndShellScriptingBible/LinuxCommandLineAndShellScriptingBibleExport.h"

#include "LinuxCommandLineAndShellScriptingBibleFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_LINUX_COMMAND_LINE_AND_SHELL_SCRIPTING_BIBLE_STATIC

DLL_MAIN_FUNCTION(LinuxCommandLineAndShellScriptingBible);

#else  // !BUILDING_LINUX_COMMAND_LINE_AND_SHELL_SCRIPTING_BIBLE_STATIC

CORE_TOOLS_MUTEX_INIT(LinuxCommandLineAndShellScriptingBible);

#endif  // BUILDING_LINUX_COMMAND_LINE_AND_SHELL_SCRIPTING_BIBLE_STATIC

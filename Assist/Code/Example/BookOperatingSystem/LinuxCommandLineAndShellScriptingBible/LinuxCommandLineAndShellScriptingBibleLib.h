///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.6 (2021/11/21 20:58)

#ifndef LINUX_COMMAND_LINE_AND_SHELL_SCRIPTING_BIBLE_LIB_H
#define LINUX_COMMAND_LINE_AND_SHELL_SCRIPTING_BIBLE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_LINUX_COMMAND_LINE_AND_SHELL_SCRIPTING_BIBLE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "LinuxCommandLineAndShellScriptingBibleD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "LinuxCommandLineAndShellScriptingBible.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_LINUX_COMMAND_LINE_AND_SHELL_SCRIPTING_BIBLE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "LinuxCommandLineAndShellScriptingBibleStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "LinuxCommandLineAndShellScriptingBibleStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_LINUX_COMMAND_LINE_AND_SHELL_SCRIPTING_BIBLE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // LINUX_COMMAND_LINE_AND_SHELL_SCRIPTING_BIBLE_LIB_H

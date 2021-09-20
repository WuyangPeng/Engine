///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.1 (2021/03/24 14:53)

#ifndef SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_FLAGS_H
#define SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_FLAGS_H

#include "System/Helper/Platform.h"

#ifndef SYSTEM_PLATFORM_WIN32
    #include <dlfcn.h>
#endif  // !SYSTEM_PLATFORM_WIN32

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class LoadLibraryType : uint32_t
    {
        Zero = 0,

        // 与LoadLibrary函数的行为是相同的。
        // NoFlags定义成0xFFFFFFFF，而不是0，保证枚举按或运算时，NoFlags标志依然有效。
        NoFlags = 0xFFFFFFFF,

        // 告诉系统只需将Dll映射到调用进程的地址空间。系统不会调用DllMain为进程和线程进行初始化和终止。
        // 另外，该系统不会加载由指定模块引用附加的可执行模块。
        DontResolveDllReferences = DONT_RESOLVE_DLL_REFERENCES,

        // 告诉系统将Dll作为数据文件映射到进程的地址空间中，同DONT_RESOLVE_DLL_REFERENCES一样，
        // 系统不会花费额外的时间来准备执行文件中的任何代码。这个标志用在一个Dll或exe文件只包含资源而不包含函数时。
        AsDatafile = LOAD_LIBRARY_AS_DATAFILE,

        // 这个标志用于改变LoadLibraryEx用来查找特定的Dll文件时使用的搜索算法。
        WithAlteredSerachPath = LOAD_WITH_ALTERED_SEARCH_PATH,

        // 用来关闭WinSafer所提供的验证，UAC特性已经取代了这项特性。
        IgnoreCodeAuthzLevel = LOAD_IGNORE_CODE_AUTHZ_LEVEL,

        // 该标志与LOAD_LIBRARY_AS_DATAFILE相似，但有一点略有不同，当系统载入Dll的时候，
        // 会对相对虚拟地址（Relative Virtual Address简称RVA）进行修复。
        AsImageResource = LOAD_LIBRARY_AS_IMAGE_RESOURCE,

        // 这个标志与LOAD_LIBRARY_AS_DATAFILE相似，唯一的不同之处在于Dll文件是以独占访问模式打开的，
        // 从而禁止任何其它应用程序在当前应用程序使用该Dll文件的时候对其进行修改。
        AsDatafileExclusive = LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE,

        RtldLazy = 0,
        RtldNow = 0,
        RtldGlobal = 0,
        RtldLocal = 0,
    };

    enum class DllMain
    {
        ProcessAttach = DLL_PROCESS_ATTACH,
        ThreadAttach = DLL_THREAD_ATTACH,
        ThreadDetach = DLL_THREAD_DETACH,
        ProcessDetach = DLL_PROCESS_DETACH,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class LoadLibraryType : uint32_t
    {
        Zero = 0,
        NoFlags = 0,
        DontResolveDllReferences = 0,
        AsDatafile = 0,
        WithAlteredSerachPath = 0,
        IgnoreCodeAuthzLevel = 0,
        AsImageResource = 0,
        AsDatafileExclusive = 0,

        // 在dlopen返回前，对于动态库中的未定义的符号不执行解析，（只对函数引用有效，对于变量引用总是立即解析）。
        RtldLazy = RTLD_LAZY,

        // 需要在dlopen返回前，解析出所有未定义符号，如果解析不出来，在dlopen会返回nullptr。
        RtldNow = RTLD_NOW,

        // 动态库中定义的符号可被其后打开的其它库解析。
        RtldGlobal = RTLD_GLOBAL,

        // 与RTLD_GLOBAL作用相反，动态库中定义的符号不能被其后打开的其它库重定位。
        // 如果没有指明是RTLD_GLOBAL还是RTLD_LOCAL，则缺省为RTLD_LOCAL。
        RtldLocal = RTLD_LOCAL,
    };

    enum class DllMain
    {
        ProcessAttach = 1,
        ThreadAttach = 2,
        ThreadDetach = 3,
        ProcessDetach = 0,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_FLAGS_H

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.1 (2021/03/24 14:53)

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

        // ��LoadLibrary��������Ϊ����ͬ�ġ�
        // NoFlags�����0xFFFFFFFF��������0����֤ö�ٰ�������ʱ��NoFlags��־��Ȼ��Ч��
        NoFlags = 0xFFFFFFFF,

        // ����ϵͳֻ�轫Dllӳ�䵽���ý��̵ĵ�ַ�ռ䡣ϵͳ�������DllMainΪ���̺��߳̽��г�ʼ������ֹ��
        // ���⣬��ϵͳ���������ָ��ģ�����ø��ӵĿ�ִ��ģ�顣
        DontResolveDllReferences = DONT_RESOLVE_DLL_REFERENCES,

        // ����ϵͳ��Dll��Ϊ�����ļ�ӳ�䵽���̵ĵ�ַ�ռ��У�ͬDONT_RESOLVE_DLL_REFERENCESһ����
        // ϵͳ���Ứ�Ѷ����ʱ����׼��ִ���ļ��е��κδ��롣�����־����һ��Dll��exe�ļ�ֻ������Դ������������ʱ��
        AsDatafile = LOAD_LIBRARY_AS_DATAFILE,

        // �����־���ڸı�LoadLibraryEx���������ض���Dll�ļ�ʱʹ�õ������㷨��
        WithAlteredSerachPath = LOAD_WITH_ALTERED_SEARCH_PATH,

        // �����ر�WinSafer���ṩ����֤��UAC�����Ѿ�ȡ�����������ԡ�
        IgnoreCodeAuthzLevel = LOAD_IGNORE_CODE_AUTHZ_LEVEL,

        // �ñ�־��LOAD_LIBRARY_AS_DATAFILE���ƣ�����һ�����в�ͬ����ϵͳ����Dll��ʱ��
        // �����������ַ��Relative Virtual Address���RVA�������޸���
        AsImageResource = LOAD_LIBRARY_AS_IMAGE_RESOURCE,

        // �����־��LOAD_LIBRARY_AS_DATAFILE���ƣ�Ψһ�Ĳ�֮ͬ������Dll�ļ����Զ�ռ����ģʽ�򿪵ģ�
        // �Ӷ���ֹ�κ�����Ӧ�ó����ڵ�ǰӦ�ó���ʹ�ø�Dll�ļ���ʱ���������޸ġ�
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

        // ��dlopen����ǰ�����ڶ�̬���е�δ����ķ��Ų�ִ�н�������ֻ�Ժ���������Ч�����ڱ�����������������������
        RtldLazy = RTLD_LAZY,

        // ��Ҫ��dlopen����ǰ������������δ������ţ������������������dlopen�᷵��nullptr��
        RtldNow = RTLD_NOW,

        // ��̬���ж���ķ��ſɱ����򿪵������������
        RtldGlobal = RTLD_GLOBAL,

        // ��RTLD_GLOBAL�����෴����̬���ж���ķ��Ų��ܱ����򿪵��������ض�λ��
        // ���û��ָ����RTLD_GLOBAL����RTLD_LOCAL����ȱʡΪRTLD_LOCAL��
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

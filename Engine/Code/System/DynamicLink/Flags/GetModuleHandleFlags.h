///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.1 (2021/03/24 14:53)

#ifndef SYSTEM_DYNAMIC_LINK_GET_MODULE_HANDLE_FLAGS_H
#define SYSTEM_DYNAMIC_LINK_GET_MODULE_HANDLE_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class GetModuleHandleType
    {
        Default = 0,  // �򵱵��øú���ʱ��ģ������ü����Զ�����
        Pin = GET_MODULE_HANDLE_EX_FLAG_PIN,  // ģ��һֱӳ���ڵ��øú����Ľ����У�ֱ���ý��̽���
        UnchangedRefcount = GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,  // ͬGetModuleHandle��ͬ�����������ü���
        FromAddress = GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS,  // moduleName��ģ���е�һ����ַ
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class GetModuleHandleType
    {
        Default = 0,
        Pin = 0x00000001,
        UnchangedRefcount = 0x00000002,
        FromAddress = 0x00000004,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_DYNAMIC_LINK_GET_MODULE_HANDLE_FLAGS_H

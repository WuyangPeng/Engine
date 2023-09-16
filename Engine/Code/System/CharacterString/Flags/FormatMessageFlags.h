///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/28 15:51)

#ifndef SYSTEM_CHARACTER_STRING_FORMAT_MESSAGE_FLAGS_H
#define SYSTEM_CHARACTER_STRING_FORMAT_MESSAGE_FLAGS_H

#include "System/Helper/EnumOperator.h"
#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class FormatMessageOption
    {
        /// �ú���������������ɸ�ʽ������Ϣ��������
        /// ������bufferָ���ĵ�ַ��ָ����õ�����Ļ�������
        /// �����߱���ʹ��LocalFree�ͷŻ�������
        AllocateBuffer = FORMAT_MESSAGE_ALLOCATE_BUFFER,

        /// ��Ϣ�����еĲ������лᱻһֱ���Ժ�����ֱ��������������ı䣬
        /// ����arguments�ᱻ���ԡ�
        IgnoreInserts = FORMAT_MESSAGE_IGNORE_INSERTS,

        /// source������ָ��һ��������Ϣ�������ֹ�ַ�����
        FromString = FORMAT_MESSAGE_FROM_STRING,

        /// source������һ��ģ�����������в�ѯ��Ϣ����Դ��
        /// �����source���Ϊnullptr��
        /// ��ǰ���̵�Ӧ�ó����ͼ���ļ�����������
        FromHModule = FORMAT_MESSAGE_FROM_HMODULE,

        /// �������������Ϣ�е�ϵͳ��Ϣ����Դ��
        /// �����־ͬʱҲָ����FORMAT_MESSAGE_FROM_HMODULE��
        /// ��ô����������sourceָ����ģ���������������Ϣ��
        /// ���������������ȥ����ϵͳ��Ϣ����Դ��
        FromSystem = FORMAT_MESSAGE_FROM_SYSTEM,

        /// ����arguments����va_list�Ľṹ��
        /// arguments����������һ��ָ�������ֵ��
        /// �����־������64λ����ֵһ��ʹ�á�
        ArgumentArray = FORMAT_MESSAGE_ARGUMENT_ARRAY,
    };

    enum class FormatMessageWidth
    {
        /// û������߿����ƣ�
        /// �ú�������Ϣ�����ı��еĻ��з��洢������������С�
        NoRestrictions = 0,

        /// �ú�����������Ϣ�����ı��еĳ��滻�з�,
        /// �ú�������Ϣ�����ı��е�Ӳ���뻻�з��洢������������У�
        /// �ú������������»��з���
        MaxWidthMask = FORMAT_MESSAGE_MAX_WIDTH_MASK,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class FormatMessageOption
    {
        AllocateBuffer = 0x00000100,
        IgnoreInserts = 0x00000200,
        FromString = 0x00000400,
        FromHModule = 0x00000800,
        FromSystem = 0x00001000,
        ArgumentArray = 0x00002000,
    };

    enum class FormatMessageWidth
    {
        NoRestrictions = 0,
        MaxWidthMask = 0x000000FF,
    };

#endif  // SYSTEM_PLATFORM_WIN32

}

#endif  // SYSTEM_CHARACTER_STRING_WINDOW_ERROR_FLAGS_H

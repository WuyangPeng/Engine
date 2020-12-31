//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/21 0:52)

#ifndef SYSTEM_HELPER_CONFIG_MACRO_H
#define SYSTEM_HELPER_CONFIG_MACRO_H

#include "StringizeMacro.h"

// �ض���ƽ̨����Ϣ��
#include "SelectPlatformConfig.h"

// �ض��ڱ���������Ϣ��
#include "SelectCompilerConfig.h"

// �ض��ڱ�׼�����Ϣ��
#include "SelectStdlibConfig.h"

#if !defined(SYSTEM_LITTLE_ENDIAN) && !defined(SYSTEM_BIG_ENDIAN)
    #define SYSTEM_LITTLE_ENDIAN
#endif  // !defined(SYSTEM_LITTLE_ENDIAN) && !defined(SYSTEM_BIG_ENDIAN)

#ifndef SYSTEM_CPP_STANDARD
    #define SYSTEM_CPP_STANDARD 3
#endif  // SYSTEM_CPP_STANDARD

#if SYSTEM_CPP_STANDARD < 17
    #error "ʹ��C++17��׼�����ټ���C++98��C++03��������"
#endif  // SYSTEM_CPP_STANDARD < 17

#ifndef SYSTEM_ATTRIBUTE_UNUSED
    #define SYSTEM_ATTRIBUTE_UNUSED
#endif  // SYSTEM_ATTRIBUTE_UNUSED

#ifndef TCRE_SYSTEM_PLATFORM
    #error "û�ж���ƽ̨��"
#endif  // TCRE_SYSTEM_PLATFORM

#ifndef TCRE_COMPILER_VERSION
    #error "û�ж���������汾��"
#endif  // TCRE_COMPILER_VERSION

#ifndef TCRE_SYSTEM_COMPILER
    #error "û�ж����������"
#endif  // TCRE_SYSTEM_COMPILER

#ifndef TCRE_CPPLIB_VERSION
    #error "û�ж����׼��汾��"
#endif  // TCRE_CPPLIB_VERSION

#ifndef TCRE_SYSTEM_STDLIB
    #error "û�ж����׼�⡣"
#endif  // TCRE_SYSTEM_STDLIB

#include "UserMacro.h"

#endif  // SYSTEM_HELPER_CONFIG_MACRO_H

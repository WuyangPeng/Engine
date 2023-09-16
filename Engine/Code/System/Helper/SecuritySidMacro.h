///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/28 17:51)

#ifndef SYSTEM_HELPER_SECURITY_SID_MACRO_H
#define SYSTEM_HELPER_SECURITY_SID_MACRO_H

#include "Platform.h"

#ifdef SYSTEM_USE_WINDOWS_MACRO

    #define SYSTEM_SECURITY_NULL_SID_AUTHORITY SECURITY_NULL_SID_AUTHORITY
    #define SYSTEM_SECURITY_WORLD_SID_AUTHORITY SECURITY_WORLD_SID_AUTHORITY
    #define SYSTEM_SECURITY_LOCAL_SID_AUTHORITY SECURITY_LOCAL_SID_AUTHORITY
    #define SYSTEM_SECURITY_CREATOR_SID_AUTHORITY SECURITY_CREATOR_SID_AUTHORITY
    #define SYSTEM_SECURITY_NON_UNIQUE_AUTHORITY SECURITY_NON_UNIQUE_AUTHORITY
    #define SYSTEM_SECURITY_RESOURCE_MANAGER_AUTHORITY SECURITY_RESOURCE_MANAGER_AUTHORITY
    #define SYSTEM_SECURITY_NT_AUTHORITY SECURITY_NT_AUTHORITY
    #define SYSTEM_SECURITY_MANDATORY_LABEL_AUTHORITY SECURITY_MANDATORY_LABEL_AUTHORITY

#else  // !SYSTEM_USE_WINDOWS_MACRO

    #define SYSTEM_SECURITY_NULL_SID_AUTHORITY { 0, 0, 0, 0, 0, 0 };
    #define SYSTEM_SECURITY_WORLD_SID_AUTHORITY { 0, 0, 0, 0, 0, 1 };
    #define SYSTEM_SECURITY_LOCAL_SID_AUTHORITY { 0, 0, 0, 0, 0, 2 };
    #define SYSTEM_SECURITY_CREATOR_SID_AUTHORITY { 0, 0, 0, 0, 0, 3 };
    #define SYSTEM_SECURITY_NON_UNIQUE_AUTHORITY { 0, 0, 0, 0, 0, 4 };
    #define SYSTEM_SECURITY_RESOURCE_MANAGER_AUTHORITY { 0, 0, 0, 0, 0, 9 };
    #define SYSTEM_SECURITY_NT_AUTHORITY { 0, 0, 0, 0, 0, 5 };
    #define SYSTEM_SECURITY_MANDATORY_LABEL_AUTHORITY { 0, 0, 0, 0, 0, 16 };

#endif  // SYSTEM_USE_WINDOWS_MACRO

#endif  // SYSTEM_HELPER_SECURITY_SID_MACRO_H

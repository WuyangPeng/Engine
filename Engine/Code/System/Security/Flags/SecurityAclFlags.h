///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.3 (2021/05/24 16:12)

#ifndef SYSTEM_SECURITY_SECURITY_ACL_FLAGS_H
#define SYSTEM_SECURITY_SECURITY_ACL_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class AccessControlListRevision
    {
        Revision = ACL_REVISION,
        RevisionDs = ACL_REVISION_DS,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class AccessControlListRevision
    {
        Revision = 2,
        RevisionDs = 4,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_SECURITY_SECURITY_ACL_FLAGS_H

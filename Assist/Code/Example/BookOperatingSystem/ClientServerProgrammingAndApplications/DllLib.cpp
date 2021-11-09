///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/02 8:44)

#include "Example/BookOperatingSystem/ClientServerProgrammingAndApplications/ClientServerProgrammingAndApplicationsExport.h"

#include "ClientServerProgrammingAndApplications.h"

#ifndef BUILDING_CLIENT_SERVER_PROGRAMMING_AND_APPLICATIONS_STATIC

    #include "DllLib.h"

#else  // !BUILDING_CLIENT_SERVER_PROGRAMMING_AND_APPLICATIONS_STATIC

namespace ClientServerProgrammingAndApplications
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_CLIENT_SERVER_PROGRAMMING_AND_APPLICATIONS_STATIC

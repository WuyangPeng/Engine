///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/02 8:44)

#include "Example/BookOperatingSystem/ClientServerProgrammingAndApplications/ClientServerProgrammingAndApplicationsExport.h"

#include "ClientServerProgrammingAndApplicationsFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CLIENT_SERVER_PROGRAMMING_AND_APPLICATIONS_STATIC

DLL_MAIN_FUNCTION(ClientServerProgrammingAndApplications);

#else  // !BUILDING_CLIENT_SERVER_PROGRAMMING_AND_APPLICATIONS_STATIC

CORE_TOOLS_MUTEX_INIT(ClientServerProgrammingAndApplications);

#endif  // BUILDING_CLIENT_SERVER_PROGRAMMING_AND_APPLICATIONS_STATIC

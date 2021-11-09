///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/22 21:06)

#include "Example/BookOperatingSystem/CryptographyAndNetworkSecurity/CryptographyAndNetworkSecurityExport.h"

#include "CryptographyAndNetworkSecurityFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CRYPTOGRAPHY_AND_NETWORK_SECURITY_STATIC

DLL_MAIN_FUNCTION(CryptographyAndNetworkSecurity);

#else  // !BUILDING_CRYPTOGRAPHY_AND_NETWORK_SECURITY_STATIC

CORE_TOOLS_MUTEX_INIT(CryptographyAndNetworkSecurity);

#endif  // BUILDING_CRYPTOGRAPHY_AND_NETWORK_SECURITY_STATIC

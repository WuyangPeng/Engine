///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/30 11:02)

#include "Example/BookCpp/CryptographyForDevelopers/CryptographyForDevelopersExport.h"

#include "CryptographyForDevelopersFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CRYPTOGRAPHY_FOR_DEVELOPERS_STATIC

DLL_MAIN_FUNCTION(CryptographyForDevelopers);

#else  // BUILDING_CRYPTOGRAPHY_FOR_DEVELOPERS_STATIC

CORE_TOOLS_MUTEX_INIT(CryptographyForDevelopers);

#endif  // !BUILDING_CRYPTOGRAPHY_FOR_DEVELOPERS_STATIC

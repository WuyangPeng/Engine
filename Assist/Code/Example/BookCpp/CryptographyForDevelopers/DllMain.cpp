///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.0 (2021/01/30 11:02)

#include "Example/BookCpp/CryptographyForDevelopers/CryptographyForDevelopersExport.h"

#include "CryptographyForDevelopersFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CRYPTOGRAPHY_FOR_DEVELOPERS_STATIC

DLL_MAIN_FUNCTION(CryptographyForDevelopers);

#else  // BUILDING_CRYPTOGRAPHY_FOR_DEVELOPERS_STATIC

CORE_TOOLS_MUTEX_INIT(CryptographyForDevelopers);

#endif  // !BUILDING_CRYPTOGRAPHY_FOR_DEVELOPERS_STATIC

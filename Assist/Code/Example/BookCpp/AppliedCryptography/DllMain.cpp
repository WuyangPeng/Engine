///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/03/28 12:57)

#include "Example/BookCpp/AppliedCryptography/AppliedCryptographyExport.h"

#include "AppliedCryptographyFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_APPLIED_CRYPTOGRAPHY_STATIC

DLL_MAIN_FUNCTION(AppliedCryptography);

#else  // BUILDING_APPLIED_CRYPTOGRAPHY_STATIC

CORE_TOOLS_MUTEX_INIT(AppliedCryptography);

#endif  // !BUILDING_APPLIED_CRYPTOGRAPHY_STATIC

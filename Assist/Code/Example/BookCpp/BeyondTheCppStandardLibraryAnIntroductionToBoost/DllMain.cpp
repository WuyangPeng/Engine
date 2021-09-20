///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/11 17:50)

#include "Example/BookCpp/BeyondTheCppStandardLibraryAnIntroductionToBoost/BeyondTheCppStandardLibraryAnIntroductionToBoostExport.h"

#include "BeyondTheCppStandardLibraryAnIntroductionToBoostFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_STATIC

DLL_MAIN_FUNCTION(BeyondTheCppStandardLibraryAnIntroductionToBoost);

#else  // BUILDING_BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_STATIC

CORE_TOOLS_MUTEX_INIT(BeyondTheCppStandardLibraryAnIntroductionToBoost);

#endif  // !BUILDING_BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_STATIC

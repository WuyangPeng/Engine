///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/10 18:02)

#include "System/SystemLib.h"
#include "CoreTools/CoreToolsLib.h"
#include "Mathematics/MathematicsLib.h" 

#include "Toolset/CoreTools/CSVConfigure/CSVConfigureLib.h"
#include "Toolset/CoreTools/ExportTest/ExportTestLib.h"
#include "Toolset/CoreTools/JsonConfigure/JsonConfigureLib.h"

#if defined(TCRE_USE_MSVC)

    #pragma comment(lib, "miniz.lib")

#endif  // TCRE_USE_MSVC

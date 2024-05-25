/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 18:14)

#include "System/SystemLib.h"
#include "CoreTools/CoreToolsLib.h"
#include "Mathematics/MathematicsLib.h"

#include "Toolset/CoreTools/CSVConfigure/CSVConfigureLib.h"
#include "Toolset/CoreTools/ExportTest/ExportTestLib.h"
#include "Toolset/CoreTools/JsonConfigure/JsonConfigureLib.h"

#if defined(TCRE_USE_MSVC)

    #pragma comment(lib, "miniz.lib")

#endif  // TCRE_USE_MSVC
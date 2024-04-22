/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/07 20:13)

#ifndef CORE_TOOLS_TEXT_PARSING_ZIP_HELPER_H
#define CORE_TOOLS_TEXT_PARSING_ZIP_HELPER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/SimpleZip/SimpleZipInternalFwd.h"

namespace CoreTools::SimpleZip
{
    constexpr auto forwardSlash = '/';

    NODISCARD System::String GetArchiveLastError(mz_zip_error lastError);

    NODISCARD std::string GetForwardSlashBack(const std::string& dir);
}

#endif  // CORE_TOOLS_TEXT_PARSING_ZIP_HELPER_H

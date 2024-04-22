/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/07 00:00)

#include "CoreTools/CoreToolsExport.h"

#include "ZipHelper.h"
#include "CoreTools/CharacterString/StringConversion.h"

System::String CoreTools::SimpleZip::GetArchiveLastError(mz_zip_error lastError)
{
    return StringConversion::MultiByteConversionStandard(mz_zip_get_error_string(lastError));
}

std::string CoreTools::SimpleZip::GetForwardSlashBack(const std::string& dir)
{
    if (dir.back() != forwardSlash)
    {
        return dir + forwardSlash;
    }

    return dir;
}

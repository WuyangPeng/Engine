/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 22:19)

#include "CoreTools/CoreToolsExport.h"

#include "Stream.h"
#include "StreamSize.h"
#include "System/CharacterString/FormatString.h"

int CoreTools::Stream::GetStreamingSize(const char* input)
{
    const auto length = boost::numeric_cast<int>(System::StringLength(input));

    return GetStreamingSize(length);
}

int CoreTools::Stream::GetStreamingSize(int length) noexcept
{
    /// 该字符串被写入到磁盘，首先是长度，接着是字符，但没有包括空终止字符。它被填充为四个字节的倍数。
    const auto padding = GetPadding(length);

    return GetStreamSize<int32_t>() + length * GetStreamSize<char>() + padding;
}

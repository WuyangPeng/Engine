//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/22 16:43)

#include "CoreTools/CoreToolsExport.h"

#include "Stream.h"
#include "StreamSize.h"
#include "System/Helper/PragmaWarning/NumericCast.h"

using std::string;

int CoreTools::Stream::GetStreamingSize(const string& input)
{
    // 该字符串被写入到磁盘，首先是长度，接着是字符，但没有包括空终止字符。它被填充为四个字节的倍数。

    auto length = boost::numeric_cast<int>(input.size());
    auto padding = 0;
    if (0 < length)
    {
        padding = (length % g_DefaultSize);
        if (0 < padding)
        {
            padding = g_DefaultSize - padding;
        }
    }

    return GetStreamSize<int>() + length * GetStreamSize<char>() + padding;
}

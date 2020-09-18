//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.2 (2020/09/11 16:47)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_STREAM_H
#define CORE_TOOLS_OBJECT_SYSTEMS_STREAM_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Stream
    {
    public:
        using ClassType = Stream;

    public:
        // 这个函数返回存储字符串所需的字节数。字符串长度首先作为一个int32被存储，后面跟着它的字符。
        // 该字符串用零填充，使总存储数使用四个字节的倍数。
        [[nodiscard]] static int GetStreamingSize(const std::string& input);
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_STREAM_H

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/28 15:51)

#ifndef SYSTEM_CHARACTER_STRING_FORMAT_MESSAGE_FLAGS_H
#define SYSTEM_CHARACTER_STRING_FORMAT_MESSAGE_FLAGS_H

#include "System/Helper/EnumOperator.h"
#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class FormatMessageOption
    {
        /// 该函数分配大到足以容纳格式化的消息缓冲区，
        /// 并在由buffer指定的地址的指针放置到分配的缓冲区，
        /// 调用者必须使用LocalFree释放缓冲区。
        AllocateBuffer = FORMAT_MESSAGE_ALLOCATE_BUFFER,

        /// 消息定义中的插入序列会被一直忽略和跳过直到输出缓冲区不改变，
        /// 并且arguments会被忽略。
        IgnoreInserts = FORMAT_MESSAGE_IGNORE_INSERTS,

        /// source参数是指向一个包含消息定义空终止字符串。
        FromString = FORMAT_MESSAGE_FROM_STRING,

        /// source参数是一个模块句柄包含进行查询消息表资源，
        /// 如果这source句柄为nullptr，
        /// 当前进程的应用程序的图像文件将被搜索。
        FromHModule = FORMAT_MESSAGE_FROM_HMODULE,

        /// 搜索所请求的消息中的系统信息表资源，
        /// 如果标志同时也指定了FORMAT_MESSAGE_FROM_HMODULE，
        /// 那么函数会先在source指定的模块中搜索请求的消息，
        /// 如果搜索不到，就去搜索系统消息表资源。
        FromSystem = FORMAT_MESSAGE_FROM_SYSTEM,

        /// 参数arguments不是va_list的结构，
        /// arguments代表了它是一个指针数组的值，
        /// 这个标志不能与64位整型值一起使用。
        ArgumentArray = FORMAT_MESSAGE_ARGUMENT_ARRAY,
    };

    enum class FormatMessageWidth
    {
        /// 没有输出线宽限制，
        /// 该函数将消息定义文本中的换行符存储到输出缓冲区中。
        NoRestrictions = 0,

        /// 该函数将忽略消息定义文本中的常规换行符,
        /// 该函数将消息定义文本中的硬编码换行符存储到输出缓冲区中，
        /// 该函数不会生成新换行符。
        MaxWidthMask = FORMAT_MESSAGE_MAX_WIDTH_MASK,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class FormatMessageOption
    {
        AllocateBuffer = 0x00000100,
        IgnoreInserts = 0x00000200,
        FromString = 0x00000400,
        FromHModule = 0x00000800,
        FromSystem = 0x00001000,
        ArgumentArray = 0x00002000,
    };

    enum class FormatMessageWidth
    {
        NoRestrictions = 0,
        MaxWidthMask = 0x000000FF,
    };

#endif  // SYSTEM_PLATFORM_WIN32

}

#endif  // SYSTEM_CHARACTER_STRING_WINDOW_ERROR_FLAGS_H

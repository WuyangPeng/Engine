///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 15:26)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_FILE_OUT_STREAM_H
#define CORE_TOOLS_OBJECT_SYSTEMS_FILE_OUT_STREAM_H

#include "CoreTools/CoreToolsDll.h"

#include "BufferOutStream.h"
#include "ObjectSystemsFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

/// 写objects到硬盘文件。版本号字符串在顶层对象之前，被首先写入。
/// 当操作失败时，抛出Error异常。
namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE FileOutStream final
    {
    public:
        using ClassType = FileOutStream;

        using ClassShareType = NonCopyClasses;
        using String = System::String;

    public:
        explicit FileOutStream(const OutTopLevel& topLevel);
        ~FileOutStream() noexcept = default;
        FileOutStream(const FileOutStream& rhs) noexcept = delete;
        FileOutStream& operator=(const FileOutStream& rhs) noexcept = delete;
        FileOutStream(FileOutStream&& rhs) noexcept = delete;
        FileOutStream& operator=(FileOutStream&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        void Save(const String& fileName);

    private:
        // 将场景图写入到缓冲器中。
        BufferOutStream bufferOutStream;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_FILE_OUT_STREAM_H

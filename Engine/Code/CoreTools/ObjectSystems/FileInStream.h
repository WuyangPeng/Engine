///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/24 15:58)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_FILE_IN_STREAM_H
#define CORE_TOOLS_OBJECT_SYSTEMS_FILE_IN_STREAM_H

#include "CoreTools/CoreToolsDll.h"

#include "InTopLevel.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace CoreTools
{
    // 从磁盘文件中读取对象。版本字符串首先被读取，并与参数version相比较，
    // 如果两个字符串相符，那么顶级对象被读取。
    class CORE_TOOLS_DEFAULT_DECLARE FileInStream final
    {
    public:
        using ClassType = FileInStream;
        using String = System::String;

    public:
        explicit FileInStream(const String& fileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD InTopLevel GetInTopLevel() const noexcept;

    private:
        void Load(const String& fileName);

    private:
        InTopLevel inTopLevel;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_FILE_IN_STREAM_H

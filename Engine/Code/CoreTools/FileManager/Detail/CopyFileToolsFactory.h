///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/08 14:40)

#ifndef CORE_TOOLS_FILE_MANAGER_COPY_FILE_TOOLS_FACTORY_H
#define CORE_TOOLS_FILE_MANAGER_COPY_FILE_TOOLS_FACTORY_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/FileManager/FileManagerInternalFwd.h"

#include <memory>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CopyFileToolsFactory final
    {
    public:
        using ClassType = CopyFileToolsFactory;
        using CopyFileToolsSharedPtr = std::shared_ptr<CopyFileToolsImpl>;
        using String = System::String;

    public:
        NODISCARD static CopyFileToolsSharedPtr Create(const String& inFileName, const String& outFileName);
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_COPY_FILE_TOOLS_FACTORY_H

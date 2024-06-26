/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 22:33)

#ifndef CORE_TOOLS_FILE_MANAGER_FILE_MANAGER_FACTORY_H
#define CORE_TOOLS_FILE_MANAGER_FILE_MANAGER_FACTORY_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/FileManager/FileManagerInternalFwd.h"

#include <memory>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE FileManagerFactory final
    {
    public:
        using ClassType = FileManagerFactory;

        using String = System::String;
        using ReadFileManagerSharedPtr = std::shared_ptr<ReadFileManagerInterface>;
        using WriteFileManagerSharedPtr = std::shared_ptr<WriteFileManagerInterface>;

    public:
        NODISCARD static ReadFileManagerSharedPtr CreateReadFileManager(const String& fileName);
        NODISCARD static WriteFileManagerSharedPtr CreateWriteFileManager(const String& fileName, bool addition);
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_FILE_MANAGER_FACTORY_H

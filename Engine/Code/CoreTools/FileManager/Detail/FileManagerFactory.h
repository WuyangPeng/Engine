///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.3 (2023/03/02 09:46)

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

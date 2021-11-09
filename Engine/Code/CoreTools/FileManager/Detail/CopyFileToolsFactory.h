///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.3 (2021/09/03 13:34)

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

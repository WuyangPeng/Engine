//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/13 18:12)

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
        using ReadFileManageInterfacePtr = std::shared_ptr<ReadFileManagerInterface>;
        using WriteFileManageInterfacePtr = std::shared_ptr<WriteFileManagerInterface>;

    public:
        [[nodiscard]] static ReadFileManageInterfacePtr CreateReadFileManage(const String& fileName);
        [[nodiscard]] static WriteFileManageInterfacePtr CreateWriteFileManage(const String& fileName);
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_FILE_MANAGER_FACTORY_H

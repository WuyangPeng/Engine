///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/08 23:42)

#ifndef CORE_TOOLS_FILE_MANAGER_READ_FILE_MANAGER_H
#define CORE_TOOLS_FILE_MANAGER_READ_FILE_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

#include <string>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(ReadFileManagerInterface);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ReadFileManager final
    {
    public:
        using ReadFileManagerImpl = ReadFileManagerInterface;
        NON_COPY_TYPE_DECLARE(ReadFileManager);
        using String = System::String;

    public:
        explicit ReadFileManager(const String& fileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetFileByteSize() const;

        // ���ҽ����������ֽ�������data�Ĵ�С�������ǳɹ��ġ������׳�Error�쳣��
        void Read(size_t itemSize, void* data);
        void Read(size_t itemSize, size_t itemsNumber, void* data);

        NODISCARD const std::string LoadStdString();

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_READ_FILE_MANAGER_H

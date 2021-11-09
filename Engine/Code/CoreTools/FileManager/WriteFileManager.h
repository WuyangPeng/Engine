///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.3 (2021/09/03 15:05)

#ifndef CORE_TOOLS_FILE_MANAGER_WRITE_FILE_MANAGER_H
#define CORE_TOOLS_FILE_MANAGER_WRITE_FILE_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

#include <string>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(WriteFileManagerInterface);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE WriteFileManager final
    {
    public:
        using WriteFileManagerImpl = WriteFileManagerInterface;
        NON_COPY_TYPE_DECLARE(WriteFileManager);
        using String = System::String;

    public:
        explicit WriteFileManager(const String& fileName, bool addition = false);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetFileByteSize() const;

        // ���ҽ���д����ֽ�������data�Ĵ�С�������ǳɹ��ġ������׳�Error�쳣��
        void Write(size_t itemSize, const void* data);
        void Write(size_t itemSize, size_t itemsNumber, const void* data);

        void SaveStdString(const std::string& name);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_WRITE_FILE_MANAGER_H

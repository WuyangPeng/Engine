//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/13 20:30)

#ifndef CORE_TOOLS_FILE_MANAGER_WRITE_FILE_MANAGER_H
#define CORE_TOOLS_FILE_MANAGER_WRITE_FILE_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(WriteFileManagerInterface);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE WriteFileManager final
    {
    public:
        using WriteFileManagerImpl = WriteFileManagerInterface;
        NON_COPY_CLASSES_TYPE_DECLARE(WriteFileManager);
        using String = System::String;

    public:
        explicit WriteFileManager(const String& fileName);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] int GetFileByteSize() const;

        // ���ҽ���д����ֽ�������data�Ĵ�С�������ǳɹ��ġ������׳�Error�쳣��
        void Write(size_t itemSize, const void* data);
        void Write(size_t itemSize, size_t itemsNumber, const void* data);

        void SaveStdString(const std::string& name);

    private:
        IMPL_TYPE_DECLARE(WriteFileManager);
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_WRITE_FILE_MANAGER_H

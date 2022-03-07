///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/08 23:27)

#ifndef CORE_TOOLS_FILE_MANAGER_IFSTREAM_MANAGER_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_IFSTREAM_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <fstream>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE IFStreamManagerImpl final
    {
    public:
        using ClassType = IFStreamManagerImpl;
        using String = System::String;
        using OStream = System::OStream;
        using IFileStream = System::IFileStream;

    public:
        explicit IFStreamManagerImpl(const String& fileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetFileContent() const;
        NODISCARD String BackupFile() const;

        void SetSimplifiedChinese();

    private:
        NODISCARD String GetBackupName() const;
        void CopyContentToStream(OStream* stream) const;

    private:
        IFileStream iStream;
        String fileName;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_IFSTREAM_MANAGER_IMPL_H

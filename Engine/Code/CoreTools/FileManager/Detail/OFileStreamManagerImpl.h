/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/10 21:40)

#ifndef CORE_TOOLS_FILE_MANAGER_O_FILE_STREAM_MANAGER_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_O_FILE_STREAM_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <fstream>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE OFileStreamManagerImpl final
    {
    public:
        using ClassType = OFileStreamManagerImpl;

        using String = System::String;
        using PosType = System::OFileStream::pos_type;
        using OFileStream = System::OFileStream;

    public:
        OFileStreamManagerImpl(const String& fileName, bool addition);

        CLASS_INVARIANT_DECLARE;

        NODISCARD PosType GetStreamSize() const;

        OFileStreamManagerImpl& operator<<(const String& message);
        void SetSimplifiedChinese();

    private:
        void SeekEnd();

        NODISCARD static std::ios_base::openmode GetOpenMode(const String& fileName, bool addition);

    private:
        OFileStream oStream;
        String fileName;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_O_FILE_STREAM_MANAGER_IMPL_H
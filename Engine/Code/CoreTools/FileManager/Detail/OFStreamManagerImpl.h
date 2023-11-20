///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/22 11:37)

#ifndef CORE_TOOLS_FILE_MANAGER_OF_STREAM_MANAGER_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_OF_STREAM_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/FileManager/Using/CFileUsing.h"
#include "System/Helper/UnicodeUsing.h"

#include <fstream>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE OFStreamManagerImpl final
    {
    public:
        using ClassType = OFStreamManagerImpl;

        using String = System::String;
        using PosType = System::PosType;
        using OFileStream = System::OFileStream;

    public:
        OFStreamManagerImpl(const String& fileName, bool addition);

        CLASS_INVARIANT_DECLARE;

        NODISCARD PosType GetStreamSize() const;

        OFStreamManagerImpl& operator<<(const String& message);
        void SetSimplifiedChinese();

    private:
        void SeekEnd();

        NODISCARD static int GetOpenMode(const String& fileName, bool addition);

    private:
        OFileStream oStream;
        String fileName;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_OF_STREAM_MANAGER_IMPL_H

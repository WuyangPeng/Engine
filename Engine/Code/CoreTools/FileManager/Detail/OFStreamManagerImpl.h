///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/08 23:28)

#ifndef CORE_TOOLS_FILE_MANAGER_OFSTREAM_MANAGER_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_OFSTREAM_MANAGER_IMPL_H

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

        NODISCARD PosType GetOFStreamSize() const;

        OFStreamManagerImpl& operator<<(const String& message);
        void SetSimplifiedChinese();

    private:
        void OpenFile(bool addition);
        void SeekEnd();

    private:
        OFileStream oStream;
        String fileName;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_OFSTREAM_MANAGER_IMPL_H

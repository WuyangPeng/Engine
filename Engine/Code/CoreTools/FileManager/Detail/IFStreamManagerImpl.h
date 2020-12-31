//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/13 18:13)

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

        [[nodiscard]] String GetFileContent() const;
        [[nodiscard]] String BackupFile() const;

        void SetSimplifiedChinese();

    private:
        [[nodiscard]] String GetBackupName() const;
        void CopyContentToStream(OStream* osPtr) const;

    private:
        IFileStream m_IStream;
        String m_FileName;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_IFSTREAM_MANAGER_IMPL_H

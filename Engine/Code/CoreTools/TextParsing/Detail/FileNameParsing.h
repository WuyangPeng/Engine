/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/02 18:05)

#ifndef CORE_TOOLS_TEXT_PARSING_FILE_NAME_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_FILE_NAME_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE FileNameParsing final
    {
    public:
        using ClassType = FileNameParsing;

        using String = System::String;

    public:
        explicit FileNameParsing(const String& fullFileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetWithSlashFileName() const;
        NODISCARD String GetFileName() const;
        NODISCARD String GetCSVClassName() const;

    private:
        String fullFileName;
        size_t slashPosition;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_FILE_NAME_PARSING_H
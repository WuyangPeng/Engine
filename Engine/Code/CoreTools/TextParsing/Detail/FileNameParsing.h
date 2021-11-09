///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/10/29 10:17)

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
        NODISCARD static size_t GetPostition(const String& fullFileName);

    private:
        String fullFileName;
        size_t slashPostition;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_FILE_NAME_PARSING_H
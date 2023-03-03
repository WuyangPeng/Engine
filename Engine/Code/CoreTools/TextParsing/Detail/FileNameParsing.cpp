///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 22:24)

#include "CoreTools/CoreToolsExport.h"

#include "FileNameParsing.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::FileNameParsing::FileNameParsing(const String& fullFileName)
    : fullFileName{ fullFileName }, slashPostition{ GetPostition(fullFileName) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

size_t CoreTools::FileNameParsing::GetPostition(const String& fullFileName)
{
    if (fullFileName.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�ļ���Ϊ�գ�\n"s));
    }

    const auto backSlashPosition = fullFileName.find_last_of(TextParsing::g_BackSlash);
    const auto forwardSlashPosition = fullFileName.find_last_of(TextParsing::g_ForwardSlash);

    if (backSlashPosition == String::npos && forwardSlashPosition == String::npos)
    {
        return String::npos;
    }
    else if (backSlashPosition == String::npos && forwardSlashPosition != String::npos)
    {
        return forwardSlashPosition;
    }
    else if (backSlashPosition != String::npos && forwardSlashPosition == String::npos)
    {
        return backSlashPosition;
    }
    else if (backSlashPosition < forwardSlashPosition)
    {
        return forwardSlashPosition;
    }
    else
    {
        return backSlashPosition;
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::FileNameParsing::IsValid() const noexcept
{
    if (!fullFileName.empty())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

System::String CoreTools::FileNameParsing::GetWithSlashFileName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (slashPostition == String::npos)
    {
        return TextParsing::g_ForwardSlash + fullFileName;
    }
    else
    {
        return fullFileName.substr(slashPostition);
    }
}

System::String CoreTools::FileNameParsing::GetFileName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (slashPostition == String::npos)
    {
        return fullFileName;
    }
    else
    {
        return fullFileName.substr(slashPostition + 1);
    }
}

System::String CoreTools::FileNameParsing::GetCSVClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto fileName = GetFileName();

    const auto dotPosition = fileName.find_first_of(TextParsing::g_Dot);

    if (dotPosition == String::npos)
    {
        return StringUtility::ToFirstLetterUpper(fileName);
    }
    else
    {
        return StringUtility::ToFirstLetterUpper(fileName.substr(0, dotPosition));
    }
}

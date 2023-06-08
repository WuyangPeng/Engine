/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "AncientBooksContainer.h"
#include "Article.h"
#include "ChapterContainer.h"
#include "VersionContainer.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVRowDetail.h"

using namespace std::literals;

AncientBooks::Article::Article(const CoreTools::CSVRow& csvRow)
    : ParentType{},
      id{ csvRow.GetInt64(SYSTEM_TEXT("id"s)) },
      version{ csvRow.GetInt(SYSTEM_TEXT("version"s)) },
      chapter{ csvRow.GetInt(SYSTEM_TEXT("chapter"s)) },
      chapterName{ csvRow.GetString(SYSTEM_TEXT("chapterName"s)) },
      volume{ csvRow.GetInt(SYSTEM_TEXT("volume"s)) },
      otherAuthor{ csvRow.GetIntArray(SYSTEM_TEXT("otherAuthor"s)) },
      authorDescribe{ csvRow.GetStringArray(SYSTEM_TEXT("authorDescribe"s)) },
      title{ csvRow.GetString(SYSTEM_TEXT("title"s)) },
      abbreviation{ csvRow.GetString(SYSTEM_TEXT("abbreviation"s)) },
      directory{ csvRow.GetString(SYSTEM_TEXT("directory"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, Article)

int64_t AncientBooks::Article::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int64_t AncientBooks::Article::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int AncientBooks::Article::GetVersion() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return version;
}

std::shared_ptr<const AncientBooks::VersionMappingType> AncientBooks::Article::GetVersion(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetVersionContainer()->GetVersion(version);
}

int AncientBooks::Article::GetChapter() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return chapter;
}

std::shared_ptr<const AncientBooks::ChapterMappingType> AncientBooks::Article::GetChapter(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetChapterContainer()->GetChapter(chapter);
}

System::String AncientBooks::Article::GetChapterName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return chapterName;
}

int AncientBooks::Article::GetVolume() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return volume;
}

std::vector<int> AncientBooks::Article::GetOtherAuthor() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return otherAuthor;
}

int AncientBooks::Article::GetOtherAuthorCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(otherAuthor.size());
}

int AncientBooks::Article::GetOtherAuthor(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return otherAuthor.at(index);
}

std::vector<int>::const_iterator AncientBooks::Article::GetOtherAuthorBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return otherAuthor.cbegin();
}

std::vector<int>::const_iterator AncientBooks::Article::GetOtherAuthorEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return otherAuthor.cend();
}

std::vector<System::String> AncientBooks::Article::GetAuthorDescribe() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return authorDescribe;
}

int AncientBooks::Article::GetAuthorDescribeCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(authorDescribe.size());
}

System::String AncientBooks::Article::GetAuthorDescribe(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return authorDescribe.at(index);
}

std::vector<System::String>::const_iterator AncientBooks::Article::GetAuthorDescribeBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return authorDescribe.cbegin();
}

std::vector<System::String>::const_iterator AncientBooks::Article::GetAuthorDescribeEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return authorDescribe.cend();
}

System::String AncientBooks::Article::GetTitle() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return title;
}

System::String AncientBooks::Article::GetAbbreviation() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return abbreviation;
}

System::String AncientBooks::Article::GetDirectory() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return directory;
}


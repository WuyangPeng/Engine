/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "ArticleEntity.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseDetail.h"
#include "Database/DatabaseInterface/BasisDatabaseManagerDetail.h"
#include "Database/DatabaseInterface/DatabaseEntityDetail.h"
#include "Database/DatabaseInterface/DatabaseField.h"
#include "Database/DatabaseInterface/EntityDetail.h"

DatabaseEntity::ArticleEntity DatabaseEntity::ArticleEntity::Create(const BasisDatabaseManager& entity, WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int64 id)
{
    return entity.IsModify() ? ArticleEntity{ entity } : ArticleEntity{ wrappersStrategy, id };
}

DatabaseEntity::ArticleEntity::ArticleEntity(const BasisDatabaseManager& entity)
    : ParentType{ entity },
      id{ entity.GetValue<DataType::Int64>(idDescribe) },
      version{ entity.GetValue<DataType::Int32>(versionDescribe) },
      chapter{ entity.GetValue<DataType::Int32>(chapterDescribe) },
      chapterName{ entity.GetValue<DataType::String>(chapterNameDescribe) },
      chapterVolume{ entity.GetValue<DataType::Int32>(chapterVolumeDescribe) },
      otherAuthor{ entity.GetValue<DataType::Int32Array>(otherAuthorDescribe) },
      authorNotes{ entity.GetValue<DataType::StringArray>(authorNotesDescribe) },
      title{ entity.GetValue<DataType::String>(titleDescribe) },
      abbreviation{ entity.GetValue<DataType::String>(abbreviationDescribe) },
      directory{ entity.GetValue<DataType::String>(directoryDescribe) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

DatabaseEntity::ArticleEntity::ArticleEntity(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int64 id)
    : ParentType{ wrappersStrategy, databaseName.data(), GetKeyBasisDatabaseContainer(id) },
      id{ id },
      version{ Database::Traits::Int32{} },
      chapter{ Database::Traits::Int32{} },
      chapterName{ Database::Traits::String{} },
      chapterVolume{ Database::Traits::Int32{} },
      otherAuthor{ Database::Traits::Int32Array{} },
      authorNotes{ Database::Traits::StringArray{} },
      title{ Database::Traits::String{} },
      abbreviation{ Database::Traits::String{} },
      directory{ Database::Traits::String{} }
{
    AddModify(idDescribe, id);

    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseEntity, ArticleEntity)

Database::Traits::Int64 DatabaseEntity::ArticleEntity::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id.GetValue();
}

Database::Traits::Int32 DatabaseEntity::ArticleEntity::GetVersion() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return version.GetValue();
}

Database::Traits::Int32 DatabaseEntity::ArticleEntity::GetChapter() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return chapter.GetValue();
}

Database::Traits::String DatabaseEntity::ArticleEntity::GetChapterName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return chapterName.GetValue();
}

Database::Traits::Int32 DatabaseEntity::ArticleEntity::GetChapterVolume() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return chapterVolume.GetValue();
}

Database::Traits::Int32Array DatabaseEntity::ArticleEntity::GetOtherAuthor() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return otherAuthor.GetValue();
}

Database::Traits::StringArray DatabaseEntity::ArticleEntity::GetAuthorNotes() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return authorNotes.GetValue();
}

Database::Traits::String DatabaseEntity::ArticleEntity::GetTitle() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return title.GetValue();
}

Database::Traits::String DatabaseEntity::ArticleEntity::GetAbbreviation() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return abbreviation.GetValue();
}

Database::Traits::String DatabaseEntity::ArticleEntity::GetDirectory() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return directory.GetValue();
}

void DatabaseEntity::ArticleEntity::SetId(Database::Traits::ParamType::Int64 aId)
{
    USER_CLASS_IS_VALID_9;

    if (aId != GetId())
    {
        id.SetValue(aId);

        AddModify(idDescribe, GetId());
    }
}

void DatabaseEntity::ArticleEntity::SetVersion(Database::Traits::ParamType::Int32 aVersion)
{
    USER_CLASS_IS_VALID_9;

    if (aVersion != GetVersion())
    {
        version.SetValue(aVersion);

        AddModify(versionDescribe, GetVersion());
    }
}

void DatabaseEntity::ArticleEntity::SetChapter(Database::Traits::ParamType::Int32 aChapter)
{
    USER_CLASS_IS_VALID_9;

    if (aChapter != GetChapter())
    {
        chapter.SetValue(aChapter);

        AddModify(chapterDescribe, GetChapter());
    }
}

void DatabaseEntity::ArticleEntity::SetChapterName(Database::Traits::ParamType::String aChapterName)
{
    USER_CLASS_IS_VALID_9;

    if (aChapterName != GetChapterName())
    {
        chapterName.SetValue(aChapterName);

        AddModify(chapterNameDescribe, GetChapterName());
    }
}

void DatabaseEntity::ArticleEntity::SetChapterVolume(Database::Traits::ParamType::Int32 aChapterVolume)
{
    USER_CLASS_IS_VALID_9;

    if (aChapterVolume != GetChapterVolume())
    {
        chapterVolume.SetValue(aChapterVolume);

        AddModify(chapterVolumeDescribe, GetChapterVolume());
    }
}

void DatabaseEntity::ArticleEntity::SetOtherAuthor(Database::Traits::ParamType::Int32Array aOtherAuthor)
{
    USER_CLASS_IS_VALID_9;

    if (aOtherAuthor != GetOtherAuthor())
    {
        otherAuthor.SetValue(aOtherAuthor);

        AddModify(otherAuthorDescribe, GetOtherAuthor());
    }
}

void DatabaseEntity::ArticleEntity::SetAuthorNotes(Database::Traits::ParamType::StringArray aAuthorNotes)
{
    USER_CLASS_IS_VALID_9;

    if (aAuthorNotes != GetAuthorNotes())
    {
        authorNotes.SetValue(aAuthorNotes);

        AddModify(authorNotesDescribe, GetAuthorNotes());
    }
}

void DatabaseEntity::ArticleEntity::SetTitle(Database::Traits::ParamType::String aTitle)
{
    USER_CLASS_IS_VALID_9;

    if (aTitle != GetTitle())
    {
        title.SetValue(aTitle);

        AddModify(titleDescribe, GetTitle());
    }
}

void DatabaseEntity::ArticleEntity::SetAbbreviation(Database::Traits::ParamType::String aAbbreviation)
{
    USER_CLASS_IS_VALID_9;

    if (aAbbreviation != GetAbbreviation())
    {
        abbreviation.SetValue(aAbbreviation);

        AddModify(abbreviationDescribe, GetAbbreviation());
    }
}

void DatabaseEntity::ArticleEntity::SetDirectory(Database::Traits::ParamType::String aDirectory)
{
    USER_CLASS_IS_VALID_9;

    if (aDirectory != GetDirectory())
    {
        directory.SetValue(aDirectory);

        AddModify(directoryDescribe, GetDirectory());
    }
}

const DatabaseEntity::ArticleEntity::DatabaseFieldContainer& DatabaseEntity::ArticleEntity::GetDatabaseFieldContainer()
{
    static const DatabaseFieldContainer fieldNameContainer{ decltype(id)::GetDatabaseField(),
                                                            decltype(version)::GetDatabaseField(),
                                                            decltype(chapter)::GetDatabaseField(),
                                                            decltype(chapterName)::GetDatabaseField(),
                                                            decltype(chapterVolume)::GetDatabaseField(),
                                                            decltype(otherAuthor)::GetDatabaseField(),
                                                            decltype(authorNotes)::GetDatabaseField(),
                                                            decltype(title)::GetDatabaseField(),
                                                            decltype(abbreviation)::GetDatabaseField(),
                                                            decltype(directory)::GetDatabaseField() };

    return fieldNameContainer;
}

DatabaseEntity::ArticleEntity::BasisDatabaseManager DatabaseEntity::ArticleEntity::GetSelect(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int64 id)
{
    return BasisDatabaseManager{ wrappersStrategy,
                                 databaseName,
                                 Database::ChangeType::Select,
                                 GetKeyBasisDatabaseContainer(id) };
}

Database::BasisDatabaseContainer DatabaseEntity::ArticleEntity::GetKeyBasisDatabaseContainer(Database::Traits::ParamType::Int64 id)
{
    BasisDatabaseContainer basisDatabaseContainer{ BasisDatabaseContainer::ObjectContainer{ Database::BasisDatabase{ idDescribe, id } } };

    return basisDatabaseContainer;
}

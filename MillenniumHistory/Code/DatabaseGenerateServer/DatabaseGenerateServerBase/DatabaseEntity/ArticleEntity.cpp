///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/30 23:23)

#include "ArticleEntity.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseManagerDetail.h"
#include "Database/DatabaseInterface/DatabaseEntityDetail.h"
#include "Database/DatabaseInterface/DatabaseField.h"
#include "Database/DatabaseInterface/EntityDetail.h"

AncientBooks::ArticleEntity::ArticleEntity(const BasisDatabaseManager& entity)
    : ParentType{ entity },
      id{ entity.GetValue<DataType::Int64>(idDescribe) },
      version{ entity.GetValue<DataType::Int32>(versionDescribe) },
      chapter{ entity.GetValue<DataType::Int32>(chapterDescribe) },
      chapterName{ entity.GetValue<DataType::String>(chapterNameDescribe) },
      volume{ entity.GetValue<DataType::Int32>(volumeDescribe) },
      chapterVolume{ entity.GetValue<DataType::Int32>(chapterVolumeDescribe) },
      otherAuthor{ entity.GetValue<DataType::Int32Array>(otherAuthorDescribe) },
      authorDescribe{ entity.GetValue<DataType::StringArray>(authorDescribeDescribe) },
      title{ entity.GetValue<DataType::String>(titleDescribe) },
      abbreviation{ entity.GetValue<DataType::String>(abbreviationDescribe) },
      directory{ entity.GetValue<DataType::String>(directoryDescribe) }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

AncientBooks::ArticleEntity::ArticleEntity(WrappersStrategy wrappersStrategy, boost::call_traits<Database::Traits::Int64>::param_type id)
    : ParentType{ wrappersStrategy, databaseName.data(), GetKeyBasisDatabaseContainer(id) },
      id{ id },
      version{ Database::Traits::Int32{} },
      chapter{ Database::Traits::Int32{} },
      chapterName{ Database::Traits::String{} },
      volume{ Database::Traits::Int32{} },
      chapterVolume{ Database::Traits::Int32{} },
      otherAuthor{ Database::Traits::Int32Array{} },
      authorDescribe{ Database::Traits::StringArray{} },
      title{ Database::Traits::String{} },
      abbreviation{ Database::Traits::String{} },
      directory{ Database::Traits::String{} }
{
    AddModify(idDescribe, id);

    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AncientBooks, ArticleEntity)

Database::Traits::Int64 AncientBooks::ArticleEntity::GetId() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return id.GetValue();
}

Database::Traits::Int32 AncientBooks::ArticleEntity::GetVersion() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return version.GetValue();
}

Database::Traits::Int32 AncientBooks::ArticleEntity::GetChapter() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return chapter.GetValue();
}

Database::Traits::String AncientBooks::ArticleEntity::GetChapterName() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return chapterName.GetValue();
}

Database::Traits::Int32 AncientBooks::ArticleEntity::GetVolume() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return volume.GetValue();
}

Database::Traits::Int32 AncientBooks::ArticleEntity::GetChapterVolume() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return chapterVolume.GetValue();
}

Database::Traits::Int32Array AncientBooks::ArticleEntity::GetOtherAuthor() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return otherAuthor.GetValue();
}

Database::Traits::StringArray AncientBooks::ArticleEntity::GetAuthorDescribe() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return authorDescribe.GetValue();
}

Database::Traits::String AncientBooks::ArticleEntity::GetTitle() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return title.GetValue();
}

Database::Traits::String AncientBooks::ArticleEntity::GetAbbreviation() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return abbreviation.GetValue();
}

Database::Traits::String AncientBooks::ArticleEntity::GetDirectory() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return directory.GetValue();
}

void AncientBooks::ArticleEntity::SetVersion(boost::call_traits<Database::Traits::Int32>::param_type aVersion)
{
    DATABASE_CLASS_IS_VALID_9;

    version.SetValue(aVersion);

    AddModify(versionDescribe, aVersion);
}

void AncientBooks::ArticleEntity::SetChapter(boost::call_traits<Database::Traits::Int32>::param_type aChapter)
{
    DATABASE_CLASS_IS_VALID_9;

    chapter.SetValue(aChapter);

    AddModify(chapterDescribe, aChapter);
}

void AncientBooks::ArticleEntity::SetChapterName(boost::call_traits<Database::Traits::String>::param_type aChapterName)
{
    DATABASE_CLASS_IS_VALID_9;

    chapterName.SetValue(aChapterName);

    AddModify(chapterNameDescribe, aChapterName);
}

void AncientBooks::ArticleEntity::SetVolume(boost::call_traits<Database::Traits::Int32>::param_type aVolume)
{
    DATABASE_CLASS_IS_VALID_9;

    volume.SetValue(aVolume);

    AddModify(volumeDescribe, aVolume);
}

void AncientBooks::ArticleEntity::SetChapterVolume(boost::call_traits<Database::Traits::Int32>::param_type aChapterVolume)
{
    DATABASE_CLASS_IS_VALID_9;

    chapterVolume.SetValue(aChapterVolume);

    AddModify(chapterVolumeDescribe, aChapterVolume);
}

void AncientBooks::ArticleEntity::SetOtherAuthor(boost::call_traits<Database::Traits::Int32Array>::param_type aOtherAuthor)
{
    DATABASE_CLASS_IS_VALID_9;

    otherAuthor.SetValue(aOtherAuthor);

    AddModify(otherAuthorDescribe, aOtherAuthor);
}

void AncientBooks::ArticleEntity::SetAuthorDescribe(boost::call_traits<Database::Traits::StringArray>::param_type aAuthorDescribe)
{
    DATABASE_CLASS_IS_VALID_9;

    authorDescribe.SetValue(aAuthorDescribe);

    AddModify(authorDescribeDescribe, aAuthorDescribe);
}

void AncientBooks::ArticleEntity::SetTitle(boost::call_traits<Database::Traits::String>::param_type aTitle)
{
    DATABASE_CLASS_IS_VALID_9;

    title.SetValue(aTitle);

    AddModify(titleDescribe, aTitle);
}

void AncientBooks::ArticleEntity::SetAbbreviation(boost::call_traits<Database::Traits::String>::param_type aAbbreviation)
{
    DATABASE_CLASS_IS_VALID_9;

    abbreviation.SetValue(aAbbreviation);

    AddModify(abbreviationDescribe, aAbbreviation);
}

void AncientBooks::ArticleEntity::SeDirectory(boost::call_traits<Database::Traits::String>::param_type aDirectory)
{
    DATABASE_CLASS_IS_VALID_9;

    directory.SetValue(aDirectory);

    AddModify(directoryDescribe, aDirectory);
}

const AncientBooks::ArticleEntity::DatabaseFieldContainer& AncientBooks::ArticleEntity::GetDatabaseFieldContainer()
{
    static const DatabaseFieldContainer fieldNameContainer{ decltype(id)::GetDatabaseField(),
                                                            decltype(version)::GetDatabaseField(),
                                                            decltype(chapter)::GetDatabaseField(),
                                                            decltype(chapterName)::GetDatabaseField(),
                                                            decltype(volume)::GetDatabaseField(),
                                                            decltype(chapterVolume)::GetDatabaseField() };

    return fieldNameContainer;
}

AncientBooks::ArticleEntity::BasisDatabaseManager AncientBooks::ArticleEntity::GetSelect(Database::WrappersStrategy wrappersStrategy,
                                                                                         boost::call_traits<Database::Traits::Int64>::param_type id)
{
    return BasisDatabaseManager{ wrappersStrategy,
                                 databaseName,
                                 Database::ChangeType::Select,
                                 GetKeyBasisDatabaseContainer(id) };
}

Database::BasisDatabaseContainer AncientBooks::ArticleEntity::GetKeyBasisDatabaseContainer(boost::call_traits<Database::Traits::Int64>::param_type id)
{
    BasisDatabaseContainer basisDatabaseContainer{ BasisDatabaseContainer::ObjectContainer{ Database::BasisDatabase{ idDescribe, id } } };

    return basisDatabaseContainer;
}

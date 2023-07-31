/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "BookEntity.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseDetail.h"
#include "Database/DatabaseInterface/BasisDatabaseManagerDetail.h"
#include "Database/DatabaseInterface/DatabaseEntityDetail.h"
#include "Database/DatabaseInterface/DatabaseField.h"
#include "Database/DatabaseInterface/EntityDetail.h"

DatabaseEntity::BookEntity DatabaseEntity::BookEntity::Create(const BasisDatabaseManager& entity, WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
{
    return entity.IsModify() ? BookEntity{ entity } : BookEntity{ wrappersStrategy, id };
}

DatabaseEntity::BookEntity::BookEntity(const BasisDatabaseManager& entity)
    : ParentType{ entity },
      id{ entity.GetValue<DataType::Int32>(idDescribe) },
      genus{ entity.GetValue<DataType::Int32>(genusDescribe) },
      name{ entity.GetValue<DataType::String>(nameDescribe) },
      alias{ entity.GetValue<DataType::StringArray>(aliasDescribe) },
      volume{ entity.GetValue<DataType::Int32>(volumeDescribe) },
      author{ entity.GetValue<DataType::Int32Array>(authorDescribe) },
      authorNotes{ entity.GetValue<DataType::StringArray>(authorNotesDescribe) },
      annotator{ entity.GetValue<DataType::Int32Array>(annotatorDescribe) },
      annotateNotes{ entity.GetValue<DataType::StringArray>(annotateNotesDescribe) },
      country{ entity.GetValue<DataType::Int32Array>(countryDescribe) },
      person{ entity.GetValue<DataType::Int32Array>(personDescribe) },
      unansweredQuestion{ entity.GetValue<DataType::StringArray>(unansweredQuestionDescribe) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

DatabaseEntity::BookEntity::BookEntity(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
    : ParentType{ wrappersStrategy, databaseName.data(), GetKeyBasisDatabaseContainer(id) },
      id{ id },
      genus{ Database::Traits::Int32{} },
      name{ Database::Traits::String{} },
      alias{ Database::Traits::StringArray{} },
      volume{ Database::Traits::Int32{} },
      author{ Database::Traits::Int32Array{} },
      authorNotes{ Database::Traits::StringArray{} },
      annotator{ Database::Traits::Int32Array{} },
      annotateNotes{ Database::Traits::StringArray{} },
      country{ Database::Traits::Int32Array{} },
      person{ Database::Traits::Int32Array{} },
      unansweredQuestion{ Database::Traits::StringArray{} }
{
    AddModify(idDescribe, id);

    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseEntity, BookEntity)

Database::Traits::Int32 DatabaseEntity::BookEntity::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id.GetValue();
}

Database::Traits::Int32 DatabaseEntity::BookEntity::GetGenus() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return genus.GetValue();
}

Database::Traits::String DatabaseEntity::BookEntity::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return name.GetValue();
}

Database::Traits::StringArray DatabaseEntity::BookEntity::GetAlias() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return alias.GetValue();
}

Database::Traits::Int32 DatabaseEntity::BookEntity::GetVolume() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return volume.GetValue();
}

Database::Traits::Int32Array DatabaseEntity::BookEntity::GetAuthor() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return author.GetValue();
}

Database::Traits::StringArray DatabaseEntity::BookEntity::GetAuthorNotes() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return authorNotes.GetValue();
}

Database::Traits::Int32Array DatabaseEntity::BookEntity::GetAnnotator() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return annotator.GetValue();
}

Database::Traits::StringArray DatabaseEntity::BookEntity::GetAnnotateNotes() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return annotateNotes.GetValue();
}

Database::Traits::Int32Array DatabaseEntity::BookEntity::GetCountry() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return country.GetValue();
}

Database::Traits::Int32Array DatabaseEntity::BookEntity::GetPerson() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return person.GetValue();
}

Database::Traits::StringArray DatabaseEntity::BookEntity::GetUnansweredQuestion() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return unansweredQuestion.GetValue();
}

void DatabaseEntity::BookEntity::SetId(Database::Traits::ParamType::Int32 aId)
{
    USER_CLASS_IS_VALID_9;

    if (aId != GetId())
    {
        id.SetValue(aId);

        AddModify(idDescribe, GetId());
    }
}

void DatabaseEntity::BookEntity::SetGenus(Database::Traits::ParamType::Int32 aGenus)
{
    USER_CLASS_IS_VALID_9;

    if (aGenus != GetGenus())
    {
        genus.SetValue(aGenus);

        AddModify(genusDescribe, GetGenus());
    }
}

void DatabaseEntity::BookEntity::SetName(Database::Traits::ParamType::String aName)
{
    USER_CLASS_IS_VALID_9;

    if (aName != GetName())
    {
        name.SetValue(aName);

        AddModify(nameDescribe, GetName());
    }
}

void DatabaseEntity::BookEntity::SetAlias(Database::Traits::ParamType::StringArray aAlias)
{
    USER_CLASS_IS_VALID_9;

    if (aAlias != GetAlias())
    {
        alias.SetValue(aAlias);

        AddModify(aliasDescribe, GetAlias());
    }
}

void DatabaseEntity::BookEntity::SetVolume(Database::Traits::ParamType::Int32 aVolume)
{
    USER_CLASS_IS_VALID_9;

    if (aVolume != GetVolume())
    {
        volume.SetValue(aVolume);

        AddModify(volumeDescribe, GetVolume());
    }
}

void DatabaseEntity::BookEntity::SetAuthor(Database::Traits::ParamType::Int32Array aAuthor)
{
    USER_CLASS_IS_VALID_9;

    if (aAuthor != GetAuthor())
    {
        author.SetValue(aAuthor);

        AddModify(authorDescribe, GetAuthor());
    }
}

void DatabaseEntity::BookEntity::SetAuthorNotes(Database::Traits::ParamType::StringArray aAuthorNotes)
{
    USER_CLASS_IS_VALID_9;

    if (aAuthorNotes != GetAuthorNotes())
    {
        authorNotes.SetValue(aAuthorNotes);

        AddModify(authorNotesDescribe, GetAuthorNotes());
    }
}

void DatabaseEntity::BookEntity::SetAnnotator(Database::Traits::ParamType::Int32Array aAnnotator)
{
    USER_CLASS_IS_VALID_9;

    if (aAnnotator != GetAnnotator())
    {
        annotator.SetValue(aAnnotator);

        AddModify(annotatorDescribe, GetAnnotator());
    }
}

void DatabaseEntity::BookEntity::SetAnnotateNotes(Database::Traits::ParamType::StringArray aAnnotateNotes)
{
    USER_CLASS_IS_VALID_9;

    if (aAnnotateNotes != GetAnnotateNotes())
    {
        annotateNotes.SetValue(aAnnotateNotes);

        AddModify(annotateNotesDescribe, GetAnnotateNotes());
    }
}

void DatabaseEntity::BookEntity::SetCountry(Database::Traits::ParamType::Int32Array aCountry)
{
    USER_CLASS_IS_VALID_9;

    if (aCountry != GetCountry())
    {
        country.SetValue(aCountry);

        AddModify(countryDescribe, GetCountry());
    }
}

void DatabaseEntity::BookEntity::SetPerson(Database::Traits::ParamType::Int32Array aPerson)
{
    USER_CLASS_IS_VALID_9;

    if (aPerson != GetPerson())
    {
        person.SetValue(aPerson);

        AddModify(personDescribe, GetPerson());
    }
}

void DatabaseEntity::BookEntity::SetUnansweredQuestion(Database::Traits::ParamType::StringArray aUnansweredQuestion)
{
    USER_CLASS_IS_VALID_9;

    if (aUnansweredQuestion != GetUnansweredQuestion())
    {
        unansweredQuestion.SetValue(aUnansweredQuestion);

        AddModify(unansweredQuestionDescribe, GetUnansweredQuestion());
    }
}

const DatabaseEntity::BookEntity::DatabaseFieldContainer& DatabaseEntity::BookEntity::GetDatabaseFieldContainer()
{
    static const DatabaseFieldContainer fieldNameContainer{ decltype(id)::GetDatabaseField(),
                                                            decltype(genus)::GetDatabaseField(),
                                                            decltype(name)::GetDatabaseField(),
                                                            decltype(alias)::GetDatabaseField(),
                                                            decltype(volume)::GetDatabaseField(),
                                                            decltype(author)::GetDatabaseField(),
                                                            decltype(authorNotes)::GetDatabaseField(),
                                                            decltype(annotator)::GetDatabaseField(),
                                                            decltype(annotateNotes)::GetDatabaseField(),
                                                            decltype(country)::GetDatabaseField(),
                                                            decltype(person)::GetDatabaseField(),
                                                            decltype(unansweredQuestion)::GetDatabaseField() };

    return fieldNameContainer;
}

DatabaseEntity::BookEntity::BasisDatabaseManager DatabaseEntity::BookEntity::GetSelect(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id)
{
    return BasisDatabaseManager{ wrappersStrategy,
                                 databaseName,
                                 Database::ChangeType::Select,
                                 GetKeyBasisDatabaseContainer(id) };
}

DatabaseEntity::BookEntity::BasisDatabaseManager DatabaseEntity::BookEntity::GetSelectAll(WrappersStrategy wrappersStrategy)
{
    return BasisDatabaseManager{ wrappersStrategy,
                                 databaseName,
                                 Database::ChangeType::Select,
                                 BasisDatabaseContainer::Create() };
}

Database::BasisDatabaseContainer DatabaseEntity::BookEntity::GetKeyBasisDatabaseContainer(Database::Traits::ParamType::Int32 id)
{
    BasisDatabaseContainer basisDatabaseContainer{ BasisDatabaseContainer::ObjectContainer{ Database::BasisDatabase{ idDescribe, id } } };

    return basisDatabaseContainer;
}

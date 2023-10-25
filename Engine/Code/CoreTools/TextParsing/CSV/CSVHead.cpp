///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/26 13:47)

#include "CoreTools/CoreToolsExport.h"

#include "CSVHead.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Detail/CSV/CSVHeadImpl.h"

CoreTools::CSVHead::CSVHead(const String& path, const FileContent& fileContent)
    : impl{ path, fileContent }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVHead)

CoreTools::CSVFormatType CoreTools::CSVHead::GetCSVFormatType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCSVFormatType();
}

CoreTools::CSVHead::String CoreTools::CSVHead::GetNameSpace() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetNameSpace();
}

CoreTools::CSVHead::String CoreTools::CSVHead::GetCSVClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCSVClassName();
}

CoreTools::CSVHead::String CoreTools::CSVHead::GetCompleteClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCompleteClassName();
}

CoreTools::CSVHead::String CoreTools::CSVHead::GetKey() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetKey();
}

CoreTools::CSVHead::KeyName CoreTools::CSVHead::GetKeyName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetKeyName();
}

int CoreTools::CSVHead::GetCount() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

CoreTools::CSVHead::String CoreTools::CSVHead::GetMapping(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetMapping(index);
}

bool CoreTools::CSVHead::HasMapping() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->HasMapping();
}

CoreTools::CSVHead::String CoreTools::CSVHead::GetScope(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetScope(index);
}

bool CoreTools::CSVHead::HasScope() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->HasScope();
}

CoreTools::CSVHead::String CoreTools::CSVHead::GetScopeExpression(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetScopeExpression(index);
}

CoreTools::CSVHead::String CoreTools::CSVHead::GetDefaultValue(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetDefaultValue(index);
}

CoreTools::CSVHead::String CoreTools::CSVHead::GetAnnotation(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetAnnotation(index);
}

CoreTools::CSVDataType CoreTools::CSVHead::GetDataType(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetDataType(index);
}

CoreTools::CSVDataType CoreTools::CSVHead::GetDataType(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetDataType(field);
}

CoreTools::CSVHead::String CoreTools::CSVHead::GetActualType(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetActualType(index);
}

CoreTools::CSVHead::String CoreTools::CSVHead::GetAbbreviation(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetAbbreviation(index);
}

CoreTools::CSVHead::String CoreTools::CSVHead::GetValueType(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetValueType(index);
}

CoreTools::CSVHead::String CoreTools::CSVHead::GetActualTypeByNameSpace(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetActualTypeByNameSpace(index);
}

bool CoreTools::CSVHead::HasDataField(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->HasDataField(field);
}

bool CoreTools::CSVHead::HasDataField(const StringView& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->HasDataField(field);
}

int CoreTools::CSVHead::GetDataIndex(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetDataIndex(field);
}

int CoreTools::CSVHead::GetDataIndex(const StringView& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetDataIndex(field);
}

CoreTools::CSVHead::String CoreTools::CSVHead::GetEnumTypeName(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetEnumTypeName(index);
}

CoreTools::CSVHead::String CoreTools::CSVHead::GetVariableName(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetVariableName(index);
}

CoreTools::CSVHead::String CoreTools::CSVHead::GetUpperVariableName(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetUpperVariableName(index);
}

CoreTools::CSVHead::String CoreTools::CSVHead::GetFunctionVariableName(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetFunctionVariableName(index);
}

CoreTools::CSVHead::String CoreTools::CSVHead::GetFunctionName(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetFunctionName(index);
}

bool CoreTools::CSVHead::HasDataType(CSVDataType csvDataType) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->HasDataType(csvDataType);
}

bool CoreTools::CSVHead::HasVectorArrayDataType() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->HasVectorArrayDataType();
}

bool CoreTools::CSVHead::HasArrayDataType() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->HasArrayDataType();
}

System::String CoreTools::CSVHead::GetAbbreviationByNameSpace(int index, const String& className) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetAbbreviationByNameSpace(index, className);
}

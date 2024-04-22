/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/03 00:13)

#include "CoreTools/CoreToolsExport.h"

#include "CSVHead.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Detail/CSV/CSVHeadImpl.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"

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

System::String CoreTools::CSVHead::GetNameSpace() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetNameSpace();
}

System::String CoreTools::CSVHead::GetCSVClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCSVClassName();
}

System::String CoreTools::CSVHead::GetKey() const
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

System::String CoreTools::CSVHead::GetMapping(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetMapping(index);
}

bool CoreTools::CSVHead::HasMapping() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->HasMapping();
}

System::String CoreTools::CSVHead::GetScope(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetScope(index);
}

bool CoreTools::CSVHead::HasScope() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->HasScope();
}

System::String CoreTools::CSVHead::GetScopeExpression(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetScopeExpression(index);
}

System::String CoreTools::CSVHead::GetDefaultValue(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetDefaultValue(index);
}

System::String CoreTools::CSVHead::GetAnnotation(int index) const
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

System::String CoreTools::CSVHead::GetActualType(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetActualType(index);
}

System::String CoreTools::CSVHead::GetAbbreviation(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetAbbreviation(index);
}

System::String CoreTools::CSVHead::GetValueType(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetValueType(index);
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

System::String CoreTools::CSVHead::GetEnumTypeName(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetEnumTypeName(index);
}

System::String CoreTools::CSVHead::GetVariableName(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetVariableName(index);
}

System::String CoreTools::CSVHead::GetUpperVariableName(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetUpperVariableName(index);
}

System::String CoreTools::CSVHead::GetFunctionVariableName(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetFunctionVariableName(index);
}

System::String CoreTools::CSVHead::GetFunctionName(int index) const
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

bool CoreTools::CSVHead::HasBase() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->HasBase();
}

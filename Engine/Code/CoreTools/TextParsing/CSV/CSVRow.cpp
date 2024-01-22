/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:54)

#include "CoreTools/CoreToolsExport.h"

#include "CSVRow.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Data/IntVector2.h"
#include "CoreTools/TextParsing/Data/IntVector3.h"
#include "CoreTools/TextParsing/Data/IntVector4.h"
#include "CoreTools/TextParsing/Data/Vector2.h"
#include "CoreTools/TextParsing/Data/Vector3.h"
#include "CoreTools/TextParsing/Data/Vector4.h"
#include "CoreTools/TextParsing/Detail/CSV/CSVRowImpl.h"

CoreTools::CSVRow::CSVRow(const CSVHead& csvHead, const String& rowContent)
    : impl{ csvHead, rowContent }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVRow)

int CoreTools::CSVRow::GetCount() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

CoreTools::CSVRow::String CoreTools::CSVRow::GetString(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetString(field);
}

bool CoreTools::CSVRow::GetBool(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetBool(field);
}

CoreTools::CSVRow::TChar CoreTools::CSVRow::GetChar(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetChar(field);
}

int CoreTools::CSVRow::GetInt(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetInt(field);
}

int64_t CoreTools::CSVRow::GetInt64(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetInt64(field);
}

double CoreTools::CSVRow::GetDouble(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetDouble(field);
}

CoreTools::Vector2 CoreTools::CSVRow::GetVector2(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetVector2(field);
}

CoreTools::Vector3 CoreTools::CSVRow::GetVector3(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetVector3(field);
}

CoreTools::Vector4 CoreTools::CSVRow::GetVector4(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetVector4(field);
}

CoreTools::IntVector2 CoreTools::CSVRow::GetIntVector2(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetIntVector2(field);
}

CoreTools::IntVector3 CoreTools::CSVRow::GetIntVector3(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetIntVector3(field);
}

CoreTools::IntVector4 CoreTools::CSVRow::GetIntVector4(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetIntVector4(field);
}

CoreTools::CSVRow::StringContainer CoreTools::CSVRow::GetStringArray(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetStringArray(field);
}

CoreTools::CSVRow::BoolContainer CoreTools::CSVRow::GetBoolArray(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetBoolArray(field);
}

CoreTools::CSVRow::CharContainer CoreTools::CSVRow::GetCharArray(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCharArray(field);
}

CoreTools::CSVRow::IntContainer CoreTools::CSVRow::GetIntArray(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetIntArray(field);
}

CoreTools::CSVRow::Int64Container CoreTools::CSVRow::GetInt64Array(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetInt64Array(field);
}

CoreTools::CSVRow::DoubleContainer CoreTools::CSVRow::GetDoubleArray(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetDoubleArray(field);
}

CoreTools::CSVRow::Vector2Container CoreTools::CSVRow::GetVector2Array(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetVector2Array(field);
}

CoreTools::CSVRow::Vector3Container CoreTools::CSVRow::GetVector3Array(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetVector3Array(field);
}

CoreTools::CSVRow::Vector4Container CoreTools::CSVRow::GetVector4Array(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetVector4Array(field);
}

CoreTools::CSVRow::IntVector2Container CoreTools::CSVRow::GetIntVector2Array(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetIntVector2Array(field);
}

CoreTools::CSVRow::IntVector3Container CoreTools::CSVRow::GetIntVector3Array(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetIntVector3Array(field);
}

CoreTools::CSVRow::IntVector4Container CoreTools::CSVRow::GetIntVector4Array(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetIntVector4Array(field);
}

CoreTools::CSVRow::String CoreTools::CSVRow::GetEnumString(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetEnumString(field);
}

CoreTools::CSVRow::StringContainer CoreTools::CSVRow::GetEnumStringArray(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetEnumStringArray(field);
}

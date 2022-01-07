///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/18 21:30)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_HEAD_H
#define CORE_TOOLS_TEXT_PARSING_CSV_HEAD_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <vector>

CORE_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(CSVHeadImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CSVHead final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(CSVHead);
        using String = System::String;
        using StringView = System::StringView;
        using FileContent = std::vector<String>;
        using KeyName = std::vector<String>;

    public:
        CSVHead(const String& path, const FileContent& fileContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD CSVFormatType GetCSVFormatType() const noexcept;
        NODISCARD String GetNameSpace() const;
        NODISCARD String GetCSVClassName() const;
        NODISCARD String GetCompleteClassName() const;
        NODISCARD String GetKey() const;
        NODISCARD KeyName GetKeyName() const;
        NODISCARD int GetCount() const;
        NODISCARD String GetMapping(int index) const;
        NODISCARD bool HasMapping() const noexcept;
        NODISCARD String GetScope(int index) const;
        NODISCARD bool HasScope() const noexcept;
        NODISCARD String GetScopeExpression(int index) const;
        NODISCARD String GetDefaultValue(int index) const;
        NODISCARD String GetAnnotation(int index) const;
        NODISCARD CSVDataType GetDataType(int index) const;
        NODISCARD CSVDataType GetDataType(const String& field) const;
        NODISCARD String GetActualType(int index) const;
        NODISCARD String GetValueType(int index) const;
        NODISCARD String GetActualTypeByNameSpace(int index) const;
        NODISCARD bool HasDataField(const String& field) const;
        NODISCARD bool HasDataField(const StringView& field) const;
        NODISCARD int GetDataIndex(const String& field) const;
        NODISCARD int GetDataIndex(const StringView& field) const;
        NODISCARD String GetEnumTypeName(int index) const;
        NODISCARD String GetVariableName(int index) const;
        NODISCARD String GetUpperVariableName(int index) const;
        NODISCARD String GetFunctionVariableName(int index) const;
        NODISCARD String GetFunctionName(int index) const;
        NODISCARD bool HasDataType(CSVDataType csvDataType) const;
        NODISCARD bool HasVectorArrayDataType() const;
        NODISCARD bool HasArrayDataType() const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_HEAD_H
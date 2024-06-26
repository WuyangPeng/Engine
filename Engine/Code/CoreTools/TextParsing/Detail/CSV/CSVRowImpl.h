/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 22:52)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_ROW_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_CSV_ROW_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <deque>
#include <map>
#include <vector>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVRowImpl final
    {
    public:
        using ClassType = CSVRowImpl;

        using TChar = System::TChar;
        using String = System::String;
        using BoolContainer = std::deque<bool>;
        using CharContainer = std::vector<TChar>;
        using IntContainer = std::vector<int>;
        using Int64Container = std::vector<int64_t>;
        using DoubleContainer = std::vector<double>;
        using StringContainer = std::vector<String>;
        using Vector2Container = std::vector<Vector2>;
        using Vector3Container = std::vector<Vector3>;
        using Vector4Container = std::vector<Vector4>;
        using IntVector2Container = std::vector<IntVector2>;
        using IntVector3Container = std::vector<IntVector3>;
        using IntVector4Container = std::vector<IntVector4>;

    public:
        CSVRowImpl(CSVHead csvHead, String rowContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const;

        NODISCARD String GetString(const String& field) const;
        NODISCARD bool GetBool(const String& field) const;
        NODISCARD TChar GetChar(const String& field) const;
        NODISCARD int GetInt(const String& field) const;
        NODISCARD int64_t GetInt64(const String& field) const;
        NODISCARD double GetDouble(const String& field) const;
        NODISCARD String GetEnumString(const String& field) const;
        NODISCARD Vector2 GetVector2(const String& field) const;
        NODISCARD Vector3 GetVector3(const String& field) const;
        NODISCARD Vector4 GetVector4(const String& field) const;
        NODISCARD IntVector2 GetIntVector2(const String& field) const;
        NODISCARD IntVector3 GetIntVector3(const String& field) const;
        NODISCARD IntVector4 GetIntVector4(const String& field) const;

        NODISCARD StringContainer GetStringArray(const String& field) const;
        NODISCARD BoolContainer GetBoolArray(const String& field) const;
        NODISCARD CharContainer GetCharArray(const String& field) const;
        NODISCARD IntContainer GetIntArray(const String& field) const;
        NODISCARD Int64Container GetInt64Array(const String& field) const;
        NODISCARD DoubleContainer GetDoubleArray(const String& field) const;
        NODISCARD StringContainer GetEnumStringArray(const String& field) const;
        NODISCARD Vector2Container GetVector2Array(const String& field) const;
        NODISCARD Vector3Container GetVector3Array(const String& field) const;
        NODISCARD Vector4Container GetVector4Array(const String& field) const;
        NODISCARD IntVector2Container GetIntVector2Array(const String& field) const;
        NODISCARD IntVector3Container GetIntVector3Array(const String& field) const;
        NODISCARD IntVector4Container GetIntVector4Array(const String& field) const;

    private:
        using RowType = std::map<String, String>;
        using VectorType = std::vector<String>;
        using ArrayType = std::vector<String>;

    private:
        void RowParsing();

        void StringNotExistCommaParsing();
        void StringExistCommaParsing();
        void StringNotExistCommaParsing(int index, String& element);
        void StringExistCommaParsing(String& lastCache, size_t& lastLocation, int& index, size_t location);
        void StringExistCommaParsing(int index, String& lastCache);

        NODISCARD VectorType GetVectorType(const String& field) const;
        NODISCARD ArrayType GetArrayType(const String& field) const;

        NODISCARD static VectorType GetSplit(const String& column);

        template <typename T>
        NODISCARD T GetValue(const String& field) const;

        template <typename T>
        NODISCARD std::vector<T> GetValueArray(const String& field) const;

    private:
        void TrimString(int index, String& remaining) const;

    private:
        CSVHead csvHead;
        String rowContent;
        RowType rowType;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_ROW_IMPL_H
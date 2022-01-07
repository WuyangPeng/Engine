///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 12:02)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_HEAD_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_JSON_HEAD_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/Json/JsonNodeContainer.h"
#include "CoreTools/TextParsing/TextParsingInternalFwd.h"

#include <memory>
#include <vector>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE JsonHeadImpl final
    {
    public:
        using ClassType = JsonHeadImpl;
        using String = System::String;
        using JsonNodeSharedPtr = std::shared_ptr<JsonNode>;
        using Container = std::vector<JsonNodeSharedPtr>;
        using ContainerConstIter = Container::const_iterator;

    public:
        explicit JsonHeadImpl(const String& path);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetNameSpace() const;
        NODISCARD String GetJsonClassName() const;
        NODISCARD String GetCompleteClassName() const;

        NODISCARD ContainerConstIter begin() const noexcept;
        NODISCARD ContainerConstIter end() const noexcept;

        NODISCARD bool HasNested() const noexcept;
        NODISCARD bool HasArray() const noexcept;
        NODISCARD bool HasBoolArray() const noexcept;

        NODISCARD int GetSize() const;

    private:
        using BasicTree = boost::property_tree::basic_ptree<String, String>;

    private:
        void Init();
        void Parsing();
        void ParsingNameSpace();
        void ParsingJsonNode();
        NODISCARD JsonNodeContainer ParsingJsonNode(const BasicTree& basicTree) const;

        NODISCARD JsonNodeSharedPtr GetJsonNode(const String& key, const String& jsonData) const;
        NODISCARD bool IsInt(const String& jsonData) const;
        NODISCARD bool IsInt64(const String& jsonData) const;
        NODISCARD bool IsDouble(const String& jsonData) const;

        NODISCARD JsonNodeSharedPtr GetArrayJsonNode(const String& key, const BasicTree& value) const;

    private:
        String path;
        String nameSpace;
        String className;
        JsonNodeContainer jsonNodeContainer;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_HEAD_IMPL_H
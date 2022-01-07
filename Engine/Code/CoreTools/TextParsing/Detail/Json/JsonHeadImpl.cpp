///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:49)

#include "CoreTools/CoreToolsExport.h"

#include "JsonHeadImpl.h"
#include "JsonNodeImpl.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
#include "CoreTools/TextParsing/Json/JsonNode.h"

#include <regex>

using std::make_shared;
using std::vector;
using namespace std::literals;

CoreTools::JsonHeadImpl::JsonHeadImpl(const String& path)
    : path{ path }, nameSpace{}, className{}, jsonNodeContainer{ JsonNodeContainer::Create() }
{
    Init();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

void CoreTools::JsonHeadImpl::Init()
{
    if (path.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("文件名为空。"s));
    }

    Parsing();
}

void CoreTools::JsonHeadImpl::Parsing()
{
    ParsingNameSpace();
    ParsingJsonNode();
}

void CoreTools::JsonHeadImpl::ParsingNameSpace()
{
    vector<String> pathSplit{};
    boost::algorithm::split(pathSplit, path, boost::is_any_of(TextParsing::g_FileSplit), boost::token_compress_on);

    if (1 < pathSplit.size())
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        nameSpace = StringConversion::ToFirstLetterUpper(pathSplit[pathSplit.size() - 2]);

#include STSTEM_WARNING_POP
    }

    auto fileName = pathSplit.at(pathSplit.size() - 1);
    const auto poistion = fileName.find(TextParsing::g_Dot);

    className = StringConversion::ToFirstLetterUpper(fileName.substr(0, poistion));
}

void CoreTools::JsonHeadImpl::ParsingJsonNode()
{
    BasicTree mainTree{};
    read_json(StringConversion::StandardConversionMultiByte(path), mainTree);

    jsonNodeContainer = ParsingJsonNode(mainTree);
}

CoreTools::JsonNodeContainer CoreTools::JsonHeadImpl::ParsingJsonNode(const BasicTree& basicTree) const
{
    auto container = JsonNodeContainer::Create();

    for (const auto& tree : basicTree)
    {
        const auto key = tree.first;
        const auto& value = tree.second;

        if (key.empty() && value.empty())
        {
            auto JsonNode = GetArrayJsonNode(key, value);

            container.SetJsonDataType(JsonNode->GetJsonDataType());
        }
        else
        {
            if (value.empty())
            {
                const auto jsonDataType = container.GetJsonDataType(key);
                if (jsonDataType == JsonDataType::Null)
                {
                    auto jsonData = value.get_value<>(String{});

                    container.AddJsonNode(GetJsonNode(key, jsonData));
                }
                else if (jsonDataType != JsonDataType::String)
                {
                    auto jsonData = value.get_value<>(String{});

                    auto jsonNode = GetJsonNode(key, jsonData);

                    container.SetNewJsonDataType(key, jsonNode->GetJsonDataType());
                }
            }
            else
            {
                const auto jsonDataType = container.GetJsonDataType(key);
                if (jsonDataType == JsonDataType::Null)
                {
                    auto result = ParsingJsonNode(value);
                    const auto resultJsonDataType = result.GetJsonDataType();
                    if (resultJsonDataType == JsonDataType::Nested || resultJsonDataType == JsonDataType::NestedArray)
                    {
                        auto jsonNode = make_shared<JsonNode>(key, resultJsonDataType);

                        jsonNode->AddJsonNode(result);

                        container.AddJsonNode(jsonNode);
                    }
                    else
                    {
                        auto jsonNode = make_shared<JsonNode>(key, result.GetJsonDataType());

                        container.AddJsonNode(jsonNode);
                    }
                }
                else
                {
                    container.SetNewJsonNodeContainer(key, ParsingJsonNode(value));
                }
            }
        }
    }

    return container;
}

CoreTools::JsonHeadImpl::JsonNodeSharedPtr CoreTools::JsonHeadImpl::GetArrayJsonNode(const String& key, const BasicTree& value) const
{
    auto jsonData = value.get_value<>(String{});

    return GetJsonNode(key, jsonData);
}

CoreTools::JsonHeadImpl::JsonNodeSharedPtr CoreTools::JsonHeadImpl::GetJsonNode(const String& key, const String& jsonData) const
{
    if (jsonData.empty())
    {
        return make_shared<JsonNode>(key, JsonDataType::Null);
    }
    else if (jsonData == SYSTEM_TEXT("true"s) || jsonData == SYSTEM_TEXT("false"s))
    {
        return make_shared<JsonNode>(key, JsonDataType::Bool);
    }
    else if (IsInt(jsonData))
    {
        return make_shared<JsonNode>(key, JsonDataType::Int);
    }
    else if (IsInt64(jsonData))
    {
        return make_shared<JsonNode>(key, JsonDataType::Int64);
    }
    else if (IsDouble(jsonData))
    {
        return make_shared<JsonNode>(key, JsonDataType::Double);
    }
    else
    {
        return make_shared<JsonNode>(key, JsonDataType::String);
    }
}

bool CoreTools::JsonHeadImpl::IsInt(const String& jsonData) const
{
    if (!IsInt64(jsonData))
    {
        return false;
    }

    auto value = boost::lexical_cast<int64_t>(jsonData);

    return std::numeric_limits<int>::min() <= value && value <= std::numeric_limits<int>::max();
}

bool CoreTools::JsonHeadImpl::IsInt64(const String& jsonData) const
{
    auto pattern = SYSTEM_TEXT("[-+]?[0-9]+"s);
    System::Regex regex{ pattern };

    return std::regex_match(jsonData, regex);
}

bool CoreTools::JsonHeadImpl::IsDouble(const String& jsonData) const
{
    if (jsonData.find(SYSTEM_TEXT('e')) != String::npos || jsonData.find(SYSTEM_TEXT('E')) != String::npos)
    {
        auto pattern = SYSTEM_TEXT("[-+]?[0-9]*.+[0-9]+[eE]+[-+]?[0-9]+[fF]?"s);
        System::Regex regex{ pattern };

        return std::regex_match(jsonData, regex);
    }
    else
    {
        auto pattern = SYSTEM_TEXT("[-+]?[0-9]*.+[0-9]+[fF]?"s);
        System::Regex regex{ pattern };

        return std::regex_match(jsonData, regex);
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::JsonHeadImpl::IsValid() const noexcept
{
    if (!path.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

System::String CoreTools::JsonHeadImpl::GetNameSpace() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return nameSpace;
}

System::String CoreTools::JsonHeadImpl::GetJsonClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return className;
}

System::String CoreTools::JsonHeadImpl::GetCompleteClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    auto completeClassName = nameSpace;

    completeClassName += TextParsing::g_DoubleColon;
    completeClassName += className;

    return completeClassName;
}

CoreTools::JsonHeadImpl::ContainerConstIter CoreTools::JsonHeadImpl::begin() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return jsonNodeContainer.begin();
}

CoreTools::JsonHeadImpl::ContainerConstIter CoreTools::JsonHeadImpl::end() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return jsonNodeContainer.end();
}

bool CoreTools::JsonHeadImpl::HasNested() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return jsonNodeContainer.HasNested();
}

bool CoreTools::JsonHeadImpl::HasArray() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return jsonNodeContainer.HasArray();
}

bool CoreTools::JsonHeadImpl::HasBoolArray() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return jsonNodeContainer.HasBoolArray();
}

int CoreTools::JsonHeadImpl::GetSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return jsonNodeContainer.GetSize();
}

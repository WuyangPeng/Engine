///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/12 14:10)

#include "CoreTools/CoreToolsExport.h"

#include "StringUtility.h"
#include "System/Helper/PragmaWarning/NumericCast.h"

#include <algorithm>
#include <iterator>
#include <locale>

using std::string;
using std::wstring;

wstring CoreTools::StringUtility::ConvertNarrowToWide(const string& input)
{
    wstring output{};

    std::transform(input.begin(), input.end(), std::back_inserter(output),
                   [](char c) {
                       return static_cast<wchar_t>(c);
                   });

    return output;
}

string CoreTools::StringUtility::ConvertWideToNarrow(const wstring& input)
{
    std::string output{};

    std::transform(input.begin(), input.end(), std::back_inserter(output),
                   [](wchar_t c) {
                       return boost::numeric_cast<char>(c);
                   });

    return output;
}

string CoreTools::StringUtility::ToLower(const string& input)
{
    string output{};

    const std::locale locale{};
    std::transform(input.begin(), input.end(), std::back_inserter(output),
                   [locale](char c) {
                       return std::tolower(c, locale);
                   });

    return output;
}

string CoreTools::StringUtility::ToUpper(const string& input)
{
    string output{};

    const std::locale locale{};
    std::transform(input.begin(), input.end(), std::back_inserter(output),
                   [locale](char c) {
                       return std::toupper(c, locale);
                   });

    return output;
}

CoreTools::StringUtility::TokensType CoreTools::StringUtility::GetTokens(const string& input, const string& whiteSpace)
{
    TokensType tokens{};
    string tokenString{ input };

    while (!tokenString.empty())
    {
        const auto begin = tokenString.find_first_not_of(whiteSpace);
        if (begin == string::npos)
        {
            break;
        }

        if (0 < begin)
        {
            tokenString = tokenString.substr(begin);
        }

        const auto end = tokenString.find_first_of(whiteSpace);
        if (end != string::npos)
        {
            auto token = tokenString.substr(0, end);
            tokens.emplace_back(token);
            tokenString = tokenString.substr(end);
        }
        else
        {
            tokens.emplace_back(tokenString);
            break;
        }
    }

    return tokens;
}

CoreTools::StringUtility::TokensType CoreTools::StringUtility::GetTextTokens(const string& input)
{
    static const auto whiteSpace = [] {
        string result{};

        for (auto i = 0; i <= 32; ++i)
        {
            result += boost::numeric_cast<char>(i);
        }

        for (auto i = 127; i < 255; ++i)
        {
            result += boost::numeric_cast<char>(i);
        }

        return result;
    }();

    return GetTokens(input, whiteSpace);
}

CoreTools::StringUtility::TokensType CoreTools::StringUtility::GetAdvancedTextTokens(const string& input)
{
    static const auto whiteSpace = [] {
        string result{};

        for (auto i = 0; i <= 32; ++i)
        {
            result += boost::numeric_cast<char>(i);
        }

        result += '\x7F';

        return result;
    }();

    return GetTokens(input, whiteSpace);
}
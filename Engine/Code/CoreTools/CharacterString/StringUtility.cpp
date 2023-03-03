///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.3 (2023/02/27 15:29)

#include "CoreTools/CoreToolsExport.h"

#include "StringUtility.h"
#include "System/Helper/PragmaWarning/NumericCast.h"

#include <gsl/util>
#include <algorithm>
#include <iterator>
#include <locale>

std::wstring CoreTools::StringUtility::ConvertNarrowToWide(const std::string& input)
{
    std::wstring output{};

    std::ranges::transform(input.begin(), input.end(), std::back_inserter(output),
                           [](const char c) {
                               return static_cast<wchar_t>(c);
                           });

    return output;
}

std::string CoreTools::StringUtility::ConvertWideToNarrow(const std::wstring& input)
{
    std::string output{};

    std::ranges::transform(input.begin(), input.end(), std::back_inserter(output),
                           [](const wchar_t c) {
                               return boost::numeric_cast<char>(c);
                           });

    return output;
}

std::string CoreTools::StringUtility::ToLower(const std::string& input)
{
    std::string output{};

    const std::locale locale{};
    std::ranges::transform(input.begin(), input.end(), std::back_inserter(output),
                           [locale](const char c) {
                               return std::tolower(c, locale);
                           });

    return output;
}

std::string CoreTools::StringUtility::ToUpper(const std::string& input)
{
    std::string output{};

    const std::locale locale{};
    std::ranges::transform(input.begin(), input.end(), std::back_inserter(output),
                           [locale](const char c) {
                               return std::toupper(c, locale);
                           });

    return output;
}

CoreTools::StringUtility::TokensType CoreTools::StringUtility::GetTokens(const std::string& input, const std::string& whiteSpace)
{
    TokensType tokens{};
    std::string tokenString{ input };

    while (!tokenString.empty())
    {
        const auto begin = tokenString.find_first_not_of(whiteSpace);
        if (begin == std::string::npos)
        {
            break;
        }

        if (0 < begin)
        {
            tokenString = tokenString.substr(begin);
        }

        if (const auto end = tokenString.find_first_of(whiteSpace); end != std::string::npos)
        {
            const auto token = tokenString.substr(0, end);
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

CoreTools::StringUtility::TokensType CoreTools::StringUtility::GetTextTokens(const std::string& input)
{
    static const auto whiteSpace = [] {
        std::string result{};

        for (auto i = 0; i <= 32; ++i)
        {
            result += gsl::narrow_cast<char>(i);
        }

        for (auto i = 127; i < 255; ++i)
        {
            result += gsl::narrow_cast<char>(i);
        }

        return result;
    }();

    return GetTokens(input, whiteSpace);
}

CoreTools::StringUtility::TokensType CoreTools::StringUtility::GetAdvancedTextTokens(const std::string& input)
{
    static const auto whiteSpace = [] {
        std::string result{};

        for (auto i = 0; i <= 32; ++i)
        {
            result += gsl::narrow_cast<char>(i);
        }

        result += '\x7F';

        return result;
    }();

    return GetTokens(input, whiteSpace);
}

System::String CoreTools::StringUtility::ToFirstLetterUpper(const String& character)
{
    auto result = character;

    if (result.empty())
    {
        return result;
    }

    const std::locale locale{};
    result.at(0) = std::toupper(result.at(0), locale);

    return result;
}

System::String CoreTools::StringUtility::ToFirstLetterLower(const String& character)
{
    auto result = character;

    if (result.empty())
    {
        return result;
    }

    const std::locale locale{};
    result.at(0) = std::tolower(result.at(0), locale);

    return result;
}

System::String CoreTools::StringUtility::ToUpperMacro(const String& character)
{
    String result{};

    const std::locale locale{};

    auto firstChar = true;
    for (const auto value : character)
    {
        if (value == SYSTEM_TEXT(' '))
        {
            continue;
        }

        if (!firstChar && std::isupper(value, locale))
        {
            result += SYSTEM_TEXT('_');
            result += value;
        }
        else if (value == SYSTEM_TEXT('.'))
        {
            result += SYSTEM_TEXT('_');
        }
        else
        {
            result += std::toupper(value, locale);
        }

        firstChar = false;
    }

    return result;
}

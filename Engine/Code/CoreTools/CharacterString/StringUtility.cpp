///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 10:46)

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

    std::ranges::transform(input, std::back_inserter(output),
                           [](const int c) noexcept {
                               const auto converted = std::btowc(c);

                               return (converted != WEOF ? static_cast<wchar_t>(c) : L' ');
                           });

    return output;
}

std::string CoreTools::StringUtility::ConvertWideToNarrow(const std::wstring& input)
{
    std::string output{};

    std::ranges::transform(input, std::back_inserter(output),
                           [](const std::wint_t c) {
                               const auto converted = std::wctob(c);

                               return (converted != EOF ? boost::numeric_cast<char>(c) : ' ');
                           });

    return output;
}

std::string CoreTools::StringUtility::ToLower(const std::string& input)
{
    std::string output{};

    const std::locale locale{};
    std::ranges::transform(input, std::back_inserter(output),
                           [locale](const char c) {
                               return std::tolower(c, locale);
                           });

    return output;
}

std::string CoreTools::StringUtility::ToUpper(const std::string& input)
{
    std::string output{};

    const std::locale locale{};
    std::ranges::transform(input, std::back_inserter(output),
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
        // 查找token的开始位置。
        const auto begin = tokenString.find_first_not_of(whiteSpace);
        if (begin == std::string::npos)
        {
            // 已找到所有令牌。
            break;
        }

        // 删除空白。
        if (0 < begin)
        {
            tokenString = tokenString.substr(begin);
        }

        // 查找token的结束位置。
        if (const auto end = tokenString.find_first_of(whiteSpace);
            end != std::string::npos)
        {
            const auto token = tokenString.substr(0, end);
            tokens.emplace_back(token);
            tokenString = tokenString.substr(end);
        }
        else
        {
            // 这是最后一个token。
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

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/29 23:10)

#include "CoreTools/CoreToolsExport.h"

#include "StringUtility.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <gsl/util>
#include <algorithm>
#include <iterator>
#include <locale>

using namespace std::literals;

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
        /// 查找token的开始位置。
        const auto begin = tokenString.find_first_not_of(whiteSpace);
        if (begin == std::string::npos)
        {
            /// 已找到所有令牌。
            break;
        }

        /// 删除空白。
        if (0 < begin)
        {
            tokenString = tokenString.substr(begin);
        }

        /// 查找token的结束位置。
        if (const auto end = tokenString.find_first_of(whiteSpace);
            end != std::string::npos)
        {
            const auto token = tokenString.substr(0, end);
            tokens.emplace_back(token);
            tokenString = tokenString.substr(end);
        }
        else
        {
            /// 这是最后一个token。
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
    return ChangeFirstLetter(character, std::toupper);
}

System::String CoreTools::StringUtility::ToFirstLetterLower(const String& character)
{
    return ChangeFirstLetter(character, std::tolower);
}

CoreTools::StringUtility::String CoreTools::StringUtility::ChangeFirstLetter(const String& character, ChangeFirstLetterFunction function)
{
    ASSERT_FAIL_THROW_EXCEPTION(function != nullptr, SYSTEM_TEXT("function指针为空。"));

    if (character.empty())
    {
        return character;
    }

    auto result = character;

    const std::locale locale{};
    result.at(0) = function(result.at(0), locale);

    return result;
}

System::String CoreTools::StringUtility::ToUpperMacro(const String& character)
{
    String result{};

    const std::locale locale{};

    auto firstChar = true;
    for (const auto element : character)
    {
        if (const auto upperCharacter = ToUpperMacro(element, locale, firstChar);
            !upperCharacter.empty())
        {
            result += upperCharacter;
            firstChar = false;
        }
    }

    return result;
}

CoreTools::StringUtility::String CoreTools::StringUtility::ToUpperMacro(const TChar& character, const std::locale& locale, bool isFirstChar)
{
    if (character == SYSTEM_TEXT(' '))
    {
        return SYSTEM_TEXT("");
    }
    else if (!isFirstChar && std::isupper(character, locale))
    {
        return SYSTEM_TEXT("_"s) + character;
    }
    else if (character == SYSTEM_TEXT('.'))
    {
        return SYSTEM_TEXT("_");
    }
    else
    {
        return String{ std::toupper(character, locale) };
    }
}

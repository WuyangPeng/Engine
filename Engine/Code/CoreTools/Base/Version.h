///	@copyright Copyright (c) 2010-2020
/// Threading Core Render Engine
///
///	@author 彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	@version 0.6.0.0
///	标准：std:c++17
/// 
/// @file Version.h
///	@date 2020/12/15 23:24
/// 
/// @ingroup group_CoreTools_Base
/// 
/// @brief 版本号  

#ifndef CORE_TOOLS_BASE_VERSION_H
#define CORE_TOOLS_BASE_VERSION_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/Version.h"

#include <string>

namespace CoreTools
{
    constexpr auto g_MaxSubversion = 100;

    /// @class Version
    /// @brief 访问引擎的版本信息。
    /// 静态类。
    class CORE_TOOLS_DEFAULT_DECLARE Version final
    {
    public:
        [[nodiscard]] static constexpr int GetTCREFullVersion() noexcept
        {
            return g_TCREVersion;
        }

        /// @return 返回主版本号，“1.2.3.4”中的1。
        /// @brief 具有相同名称但不同主版本号的程序集不可互换。例如，这适用于对产品的大量重写，这些重写使得无法实现向后兼容性。
        [[nodiscard]] static constexpr int GetMajor(int version) noexcept
        {
            return (version / (g_MaxSubversion * g_MaxSubversion * g_MaxSubversion)) % g_MaxSubversion;
        }

        [[nodiscard]] static constexpr int GetMajor() noexcept
        {
            return GetMajor(GetTCREFullVersion());
        }

        /// @return 返回次版本号，“1.2.3.4”中的2。
        /// @brief 如果两个程序集的名称和主版本号相同，而次版本号不同，这指示显著增强，但照顾到了向后兼容性。
        /// 例如，这适用于产品的修正版或完全向后兼容的新版本。
        [[nodiscard]] static constexpr int GetMinor(int version) noexcept
        {
            return (version / (g_MaxSubversion * g_MaxSubversion)) % g_MaxSubversion;
        }

        [[nodiscard]] static constexpr int GetMinor() noexcept
        {
            return GetMinor(GetTCREFullVersion());
        }

        /// @return 返回内部版本号，“1.2.3.4”中的3。
        /// @brief 内部版本号的不同表示对相同源所作的重新编译。这适合于更改处理器、平台或编译器的情况。
        [[nodiscard]] static constexpr int GetBuild(int version) noexcept
        {
            return (version / g_MaxSubversion) % g_MaxSubversion;
        }

        [[nodiscard]] static constexpr int GetBuild() noexcept
        {
            return GetBuild(GetTCREFullVersion());
        }

        /// @return 返回修订号，“1.2.3.4”中的4。
        /// @brief 名称、主版本号和次版本号都相同但修订号不同的程序集应是完全可互换的。这适用于修复以前发布的程序集中的安全漏洞。
        [[nodiscard]] static constexpr int GetRevision(int version) noexcept
        {
            return version % g_MaxSubversion;
        }

        [[nodiscard]] static constexpr int GetRevision() noexcept
        {
            return GetRevision(GetTCREFullVersion());
        }

        /// @return 返回一个完整的版本号为字符串，如“1.2.3.4”。
        [[nodiscard]] static std::string GetVersion(int version);
        [[nodiscard]] static std::string GetVersion();

        /// @return 如果当前版本号 >= (major, minor, build , revision)，返回true。
        [[nodiscard]] static bool IsAtLeast(int version, int major, int minor, int build, int revision) noexcept;
        [[nodiscard]] static bool IsAtLeast(int major, int minor, int build, int revision) noexcept;
    };
}

#endif  // CORE_TOOLS_BASE_VERSION_H

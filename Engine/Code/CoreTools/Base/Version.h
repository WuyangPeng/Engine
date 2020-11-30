///	@copyright Copyright (c) 2011-2020
/// Threading Core Render Engine
///
///	@author �����������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	@version 0.5.2.4
///	��׼��std:c++17
///
/// @date 2020/11/29 15:10

#ifndef CORE_TOOLS_BASE_VERSION_H
#define CORE_TOOLS_BASE_VERSION_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/Version.h"

#include <string>

namespace CoreTools
{
    constexpr auto g_MaxSubversion = 100;

    /// @class Version
    /// @brief ��������İ汾��Ϣ��
    /// ��̬�ࡣ
    class CORE_TOOLS_DEFAULT_DECLARE Version final
    {
    public:
        [[nodiscard]] static constexpr int GetTCREFullVersion() noexcept
        {
            return g_TCREVersion;
        }

        /// @return �������汾�ţ���1.2.3.4���е�1��
        /// @brief ������ͬ���Ƶ���ͬ���汾�ŵĳ��򼯲��ɻ��������磬�������ڶԲ�Ʒ�Ĵ�����д����Щ��дʹ���޷�ʵ���������ԡ�
        [[nodiscard]] static constexpr int GetMajor(int version) noexcept
        {
            return (version / (g_MaxSubversion * g_MaxSubversion * g_MaxSubversion)) % g_MaxSubversion;
        }

        [[nodiscard]] static constexpr int GetMajor() noexcept
        {
            return GetMajor(GetTCREFullVersion());
        }

        /// @return ���شΰ汾�ţ���1.2.3.4���е�2��
        /// @brief ����������򼯵����ƺ����汾����ͬ�����ΰ汾�Ų�ͬ����ָʾ������ǿ�����չ˵����������ԡ�
        /// ���磬�������ڲ�Ʒ�����������ȫ�����ݵ��°汾��
        [[nodiscard]] static constexpr int GetMinor(int version) noexcept
        {
            return (version / (g_MaxSubversion * g_MaxSubversion)) % g_MaxSubversion;
        }

        [[nodiscard]] static constexpr int GetMinor() noexcept
        {
            return GetMinor(GetTCREFullVersion());
        }

        /// @return �����ڲ��汾�ţ���1.2.3.4���е�3��
        /// @brief �ڲ��汾�ŵĲ�ͬ��ʾ����ͬԴ���������±��롣���ʺ��ڸ��Ĵ�������ƽ̨��������������
        [[nodiscard]] static constexpr int GetBuild(int version) noexcept
        {
            return (version / g_MaxSubversion) % g_MaxSubversion;
        }

        [[nodiscard]] static constexpr int GetBuild() noexcept
        {
            return GetBuild(GetTCREFullVersion());
        }

        /// @return �����޶��ţ���1.2.3.4���е�4��
        /// @brief ���ơ����汾�źʹΰ汾�Ŷ���ͬ���޶��Ų�ͬ�ĳ���Ӧ����ȫ�ɻ����ġ����������޸���ǰ�����ĳ����еİ�ȫ©����
        [[nodiscard]] static constexpr int GetRevision(int version) noexcept
        {
            return version % g_MaxSubversion;
        }

        [[nodiscard]] static constexpr int GetRevision() noexcept
        {
            return GetRevision(GetTCREFullVersion());
        }

        /// @return ����һ�������İ汾��Ϊ�ַ������硰1.2.3.4����
        [[nodiscard]] static std::string GetVersion(int version);
        [[nodiscard]] static std::string GetVersion();

        /// @return �����ǰ�汾�� >= (major, minor, build , revision)������true��
        [[nodiscard]] static bool IsAtLeast(int version, int major, int minor, int build, int revision) noexcept;
        [[nodiscard]] static bool IsAtLeast(int major, int minor, int build, int revision) noexcept;
    };
}

#endif  // CORE_TOOLS_BASE_VERSION_H

//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/12 11:04)

#ifndef CORE_TOOLS_BASE_VERSION_H
#define CORE_TOOLS_BASE_VERSION_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/Version.h"

#include <string>

namespace CoreTools
{
    constexpr auto g_MaxSubversion = 100;

    class CORE_TOOLS_DEFAULT_DECLARE Version final
    {
    public:
        [[nodiscard]] static constexpr int GetTCREFullVersion() noexcept
        {
            return g_TCREVersion;
        }

        // �������汾�ţ���1.2.3.4���е�1��������ͬ���Ƶ���ͬ���汾�ŵĳ��򼯲��ɻ�����
        // ���磬�������ڶԲ�Ʒ�Ĵ�����д����Щ��дʹ���޷�ʵ���������ԡ�
        [[nodiscard]] static constexpr int GetMajor(int version) noexcept
        {
            return (version / (g_MaxSubversion * g_MaxSubversion * g_MaxSubversion)) % g_MaxSubversion;
        }

        [[nodiscard]] static constexpr int GetMajor() noexcept
        {
            return GetMajor(GetTCREFullVersion());
        }

        // ���شΰ汾�ţ���1.2.3.4���е�2������������򼯵����ƺ����汾����ͬ�����ΰ汾�Ų�ͬ��
        // ��ָʾ������ǿ�����չ˵����������ԡ����磬�������ڲ�Ʒ�����������ȫ�����ݵ��°汾��
        [[nodiscard]] static constexpr int GetMinor(int version) noexcept
        {
            return (version / (g_MaxSubversion * g_MaxSubversion)) % g_MaxSubversion;
        }

        [[nodiscard]] static constexpr int GetMinor() noexcept
        {
            return GetMinor(GetTCREFullVersion());
        }

        // �����ڲ��汾�ţ���1.2.3.4���е�3���ڲ��汾�ŵĲ�ͬ��ʾ����ͬԴ���������±��롣
        // ���ʺ��ڸ��Ĵ�������ƽ̨��������������
        [[nodiscard]] static constexpr int GetBuild(int version) noexcept
        {
            return (version / g_MaxSubversion) % g_MaxSubversion;
        }

        [[nodiscard]] static constexpr int GetBuild() noexcept
        {
            return GetBuild(GetTCREFullVersion());
        }

        // �����޶��ţ���1.2.3.4���е�4�����ơ����汾�źʹΰ汾�Ŷ���ͬ���޶��Ų�ͬ�ĳ���Ӧ����ȫ�ɻ����ġ�
        // ���������޸���ǰ�����ĳ����еİ�ȫ©����
        [[nodiscard]] static constexpr int GetRevision(int version) noexcept
        {
            return version % g_MaxSubversion;
        }

        [[nodiscard]] static constexpr int GetRevision() noexcept
        {
            return GetRevision(GetTCREFullVersion());
        }

        // ����һ�������İ汾��Ϊ�ַ������硰1.2.3.4����
        [[nodiscard]] static std::string GetVersion(int version);
        [[nodiscard]] static std::string GetVersion();

        // �����ǰ�汾�� >= (major, minor, build , revision)������true��
        [[nodiscard]] static bool IsAtLeast(int version, int major, int minor, int build, int revision) noexcept;
        [[nodiscard]] static bool IsAtLeast(int major, int minor, int build, int revision) noexcept;
    };
}

#endif  // CORE_TOOLS_BASE_VERSION_H
// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/18 18:14)

#ifndef CORE_TOOLS_VERSION_INFORMATION_VERSION_H
#define CORE_TOOLS_VERSION_INFORMATION_VERSION_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/Version.h"

#include <string>

namespace CoreTools
{
	constexpr auto g_MaxSubversion = 100;

	class CORE_TOOLS_DEFAULT_DECLARE Version
	{
	public:
		static constexpr int GetTCREFullVersion() noexcept
		{
			return g_TCREVersion;
		}

		// �������汾�ţ���1.2.3.4���е�1��������ͬ���Ƶ���ͬ���汾�ŵĳ��򼯲��ɻ�����
		// ���磬�������ڶԲ�Ʒ�Ĵ�����д����Щ��дʹ���޷�ʵ���������ԡ�
		static constexpr int GetMajor(int version) noexcept
		{
			return (version / (g_MaxSubversion * g_MaxSubversion * g_MaxSubversion)) % g_MaxSubversion;
		}

		static constexpr int GetMajor() noexcept
		{
			return GetMajor(GetTCREFullVersion());
		}

		// ���شΰ汾�ţ���1.2.3.4���е�2������������򼯵����ƺ����汾����ͬ�����ΰ汾�Ų�ͬ��
		// ��ָʾ������ǿ�����չ˵����������ԡ����磬�������ڲ�Ʒ�����������ȫ�����ݵ��°汾��
		static constexpr int GetMinor(int version) noexcept
		{
			return (version / (g_MaxSubversion * g_MaxSubversion)) % g_MaxSubversion;
		}

		static constexpr int GetMinor() noexcept
		{
			return GetMinor(GetTCREFullVersion());
		}

		// �����ڲ��汾�ţ���1.2.3.4���е�3���ڲ��汾�ŵĲ�ͬ��ʾ����ͬԴ���������±��롣
		// ���ʺ��ڸ��Ĵ�������ƽ̨��������������
		static constexpr int GetBuild(int version) noexcept
		{
			return (version / g_MaxSubversion) % g_MaxSubversion;
		}

		static constexpr int GetBuild() noexcept
		{
			return GetBuild(GetTCREFullVersion());
		}

		// �����޶��ţ���1.2.3.4���е�4�����ơ����汾�źʹΰ汾�Ŷ���ͬ���޶��Ų�ͬ�ĳ���Ӧ����ȫ�ɻ����ġ�
		// ���������޸���ǰ�����ĳ����еİ�ȫ©����
		static constexpr int GetRevision(int version) noexcept
		{
			return version % g_MaxSubversion;
		}

		static constexpr int GetRevision() noexcept
		{
			return GetRevision(GetTCREFullVersion());
		}

		// ����һ�������İ汾��Ϊ�ַ������硰1.2.3.4����
		static std::string GetVersion(int version);
		static std::string GetVersion();		

		// �����ǰ�汾�� >= (major, minor, build , revision)������true��
		static bool IsAtLeast(int version, int major, int minor, int build, int revision) noexcept;
		static bool IsAtLeast(int major, int minor, int build, int revision) noexcept;			
	};
}

#endif // CORE_TOOLS_VERSION_INFORMATION_VERSION_H

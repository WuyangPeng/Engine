// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/20 16:42)

#ifndef CORE_TOOLS_MEMORY_TOOLS_RANDOM_H
#define CORE_TOOLS_MEMORY_TOOLS_RANDOM_H

// һ���򵥵�α������������������ٲ���32λ�����������rand()��15λ����

// ����ڹ�����û�и������ӣ�״̬������Ϊһ���̶�ֵ�������������������Ǻ����õġ�

#include "CoreTools/CoreToolsDll.h" 

#include <array>

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE Random
	{
	public:
		using ClassType = Random;

	public:
		Random() noexcept;
		explicit Random(uint32_t seed) noexcept;

		CLASS_INVARIANT_DECLARE;

		// ����һ��������32λ���������
		uint32_t Generate() noexcept;

		// ����һ������32λ�������
		int GeneratePositive() noexcept;

	private:
		void GenerateSeeds() noexcept;

		// ����һ���µ�������һ����������״̬�ļ�������������
		uint32_t GenerateSimple() noexcept;

	private:
		static constexpr auto sm_TableSize = 250;

		// �����һ�����ӱ����ڳ�ʼ��һ���򵥵ķ�������
		uint32_t m_State;

		int m_FirstIndex;
		int m_SecondIndex;
		std::array<uint32_t, sm_TableSize> m_Table;
	};
}

#endif // CORE_TOOLS_MEMORY_TOOLS_RANDOM_H

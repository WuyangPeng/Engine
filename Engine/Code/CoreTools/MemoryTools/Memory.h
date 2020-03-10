// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/20 16:41)

#ifndef CORE_TOOLS_MEMORY_TOOLS_MEMORY_H
#define CORE_TOOLS_MEMORY_TOOLS_MEMORY_H

#include "CoreTools/CoreToolsDll.h"

#include "MemoryManager.h"
#include "CoreTools/ClassInvariant/ClassInvariantFwd.h"

// �ڴ���ٵ��ԡ�
namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE Memory
	{
	public:
		using ClassType = Memory;

	public:
		explicit Memory(const FunctionDescribed& functionDescribed);

		CLASS_INVARIANT_DECLARE;

		// �� 1D ����:  data[bound1]
		template <typename T>
		T* New1DArray(const int bound);

		// �� 2D ����:  data[bound2][bound1]
		template <typename T>
		T** New2DArray(const int bound1, const int bound2);

		// �� 3D ����:  data[bound3][bound2][bound1]
		template <typename T>
		T*** New3DArray(const int bound1, const int bound2, const int bound3);

		// �� 4D ����:  data[bound4][bound3][bound2][bound1]
		template <typename T>
		T**** New4DArray(const int bound1, const int bound2, const int bound3, const int bound4);

		// �Ե���
		template <typename T>
		void DeleteSingle(T*& data);

		// �� 1D ����:  data[bound1]
		template <typename T>
		void Delete1DArray(T*& data);

		// �� 2D ����:  data[bound2][bound1]
		template <typename T>
		void Delete2DArray(T**& data);

		// �� 3D ����:  data[bound3][bound2][bound1]
		template <typename T>
		void Delete3DArray(T***& data);

		// �� 4D ����:  data[bound4][bound3][bound2][bound1]
		template <typename T>
		void Delete4DArray(T****& data);

		const FunctionDescribed& GetFunctionDescribed() const;

	private:
		template <typename T>
		void CallConstructor(T*& data,int bound);

		template <typename T>
		void CallConstructor(T**& data, int bound);

		template <typename T>
		void CallConstructor(T***& data, int bound);

		template <typename T>
		void CallConstructor(T****& data, int bound);

		template <typename T>
		void DeleteArray(T*& data,size_t constructorSuccess); 

	private:
		FunctionDescribed m_FunctionDescribed;
	};
}

inline void* operator new(size_t bytesNumber, const CoreTools::Memory& memory)
{
	return MEMORY_MANAGER_SINGLETON.CreateBlock(bytesNumber, 0, memory.GetFunctionDescribed());
}

inline void operator delete(void*, const CoreTools::Memory&)
{
	// ֻ���쳣������á�
}

#endif // CORE_TOOLS_MEMORY_TOOLS_MEMORY_H

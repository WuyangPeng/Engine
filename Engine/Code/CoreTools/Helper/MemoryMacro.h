// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/18 10:27)

#ifndef CORE_TOOLS_HELPER_MEMORY_MACRO_H
#define CORE_TOOLS_HELPER_MEMORY_MACRO_H

#include "UserMacro.h"
#include "System/Helper/PragmaWarning.h"

// �ڴ����ĺꡣ�����ڴ�й©������ļ�����Ϣ������������OPEN_USE_MEMORY��
// ���ú�������MEMORY_CREATE() �� MEMORY_DESTROY() �����Ӧ�ó���

#if defined(OPEN_USE_MEMORY) && !defined(CLOSE_USE_MEMORY) && !defined(CORE_TOOLS_USE_MEMORY)
	#define CORE_TOOLS_USE_MEMORY
#endif // OPEN_USE_MEMORY

#ifdef CORE_TOOLS_USE_MEMORY

	#include "FunctionDescribedMacro.h"
	#include "CoreTools/MemoryTools/MemoryDetail.h"
	#include "CoreTools/MemoryTools/MemoryManager.h"	

	#define NEW0 new (CoreTools::Memory{ CORE_TOOLS_FUNCTION_DESCRIBED })
	#define NEW1 CoreTools::Memory{ CORE_TOOLS_FUNCTION_DESCRIBED }.New1DArray
	#define NEW2 CoreTools::Memory{ CORE_TOOLS_FUNCTION_DESCRIBED }.New2DArray
	#define NEW3 CoreTools::Memory{ CORE_TOOLS_FUNCTION_DESCRIBED }.New3DArray
	#define NEW4 CoreTools::Memory{ CORE_TOOLS_FUNCTION_DESCRIBED }.New4DArray
	#define DELETE0 CoreTools::Memory{ CORE_TOOLS_FUNCTION_DESCRIBED }.DeleteSingle
	#define DELETE1 CoreTools::Memory{ CORE_TOOLS_FUNCTION_DESCRIBED }.Delete1DArray
	#define DELETE2 CoreTools::Memory{ CORE_TOOLS_FUNCTION_DESCRIBED }.Delete2DArray
	#define DELETE3 CoreTools::Memory{ CORE_TOOLS_FUNCTION_DESCRIBED }.Delete3DArray
	#define DELETE4 CoreTools::Memory{ CORE_TOOLS_FUNCTION_DESCRIBED }.Delete4DArray

#else // !CORE_TOOLS_USE_MEMORY

	#include "CoreTools/MemoryTools/DefaultMemoryDetail.h"

	// ��׼���ڴ����
	#define NEW0 new
	// �� 1D ���飺data[firstBound]
	#define NEW1 CoreTools::DefaultMemory::New1DArray
	// �� 2D ���飺data[secondBound][firstBound]
	#define NEW2 CoreTools::DefaultMemory::New2DArray
	// �� 3D ���飺data[thirdBound][secondBound][firstBound]
	#define NEW3 CoreTools::DefaultMemory::New3DArray
	// �� 4D ���飺data[fourthBound][thirdBound][secondBound][firstBound]
	#define NEW4 CoreTools::DefaultMemory::New4DArray
	// �Ե���
	#define DELETE0 CoreTools::DefaultMemory::DeleteSingle
	// �� 1D ���飺data[firstBound]
	#define DELETE1 CoreTools::DefaultMemory::Delete1DArray
	// �� 2D ���飺data[secondBound][firstBound]
	#define DELETE2 CoreTools::DefaultMemory::Delete2DArray
	// �� 3D ���飺data[thirdBound][secondBound][firstBound]
	#define DELETE3 CoreTools::DefaultMemory::Delete3DArray
	// �� 4D ���飺data[fourthBound][thirdBound][secondBound][firstBound]
	#define DELETE4 CoreTools::DefaultMemory::Delete4DArray

#endif // CORE_TOOLS_USE_MEMORY

#if defined(CORE_TOOLS_USE_MEMORY) || defined(CORE_TOOLS_MEMORY_ALWAYS_CREATE)

	#define MEMORY_CREATE \
			CoreTools::MemoryManager::Create()
	#define MEMORY_CREATE_WITH_ALLOCATOR_AND_DEALLOCATOR(allocator,deallocator) \
			CoreTools::MemoryManager::Create((allocator),(deallocator))
	#define MEMORY_DESTROY \
			CoreTools::MemoryManager::Destroy()

	namespace CoreTools
	{
		constexpr auto g_MemoryNoexcept = false;
	}	

#else // !defined(CORE_TOOLS_USE_MEMORY) && !defined(CORE_TOOLS_MEMORY_ALWAYS_CREATE)

	#define MEMORY_CREATE ((void)0)
	#define MEMORY_CREATE_WITH_ALLOCATOR_AND_DEALLOCATOR(allocator,deallocator) ((void)0)
	#define MEMORY_DESTROY ((void)0)
	
	namespace CoreTools
	{
		constexpr auto g_MemoryNoexcept = true;
	}

#endif // defined(CORE_TOOLS_USE_MEMORY) || defined(CORE_TOOLS_MEMORY_ALWAYS_CREATE)
	namespace CoreTools
	{
		template<typename T, typename... Types>
		static T* New0(Types&&... args)
		{
		#include STSTEM_WARNING_PUSH

		#include SYSTEM_WARNING_DISABLE(26409)  
		#include SYSTEM_WARNING_DISABLE(26402)  
			return NEW0 T(std::forward<Types>(args)...);

		#include STSTEM_WARNING_POP
		}
	}

#endif // CORE_TOOLS_HELPER_MEMORY_MACRO_H

// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 13:15)

#ifndef CORE_TOOLS_FRAME_MEMORY_SYSTEM_FRAME_MEMORY_SYSTEM_MANAGER_H
#define CORE_TOOLS_FRAME_MEMORY_SYSTEM_FRAME_MEMORY_SYSTEM_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "FrameMemorySystemFwd.h"
#include "FrameMemorySystemPointerShare.h"

#include <boost/noncopyable.hpp>

EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE FrameMemorySystemManager : private boost::noncopyable
	{
	public:
		using ClassType = FrameMemorySystemManager;

	public:
		FrameMemorySystemManager(BaseFrameMemorySystem& frameMemorySystem, int bytes, FrameMemorySystemHeap heapType);
		~FrameMemorySystemManager();

		CLASS_INVARIANT_DECLARE;

		const FrameMemorySystemPointerShare GetFrameMemorySystemPointer() const;

	private:
		BaseFrameMemorySystem& m_FrameMemorySystem;
		FrameMemorySystemPointerShare m_Pointer;
	};
}

#endif // CORE_TOOLS_FRAME_MEMORY_SYSTEM_FRAME_MEMORY_SYSTEM_MANAGER_H
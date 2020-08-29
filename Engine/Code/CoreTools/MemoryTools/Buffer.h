// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/20 16:40)

#ifndef CORE_TOOLS_MEMORY_TOOLS_BUFER_H
#define CORE_TOOLS_MEMORY_TOOLS_BUFER_H

#include "CoreTools/CoreToolsDll.h"

#include "MemoryToolsFwd.h"
#include "CoreTools/Helper/ExportMacro.h"

 

 

namespace CoreTools
{     
    class CORE_TOOLS_DEFAULT_DECLARE Buffer  
    {
    public:
        using ClassType = Buffer;
        
    public:        
        Buffer();
        explicit Buffer(int minSize);
        ~Buffer() noexcept;

        Buffer(const Buffer&) = delete;
      virtual  Buffer& operator=(const Buffer&) = delete;
		Buffer(Buffer&&) noexcept = delete;
      virtual Buffer& operator=(Buffer&&) noexcept = delete;
        
		CLASS_INVARIANT_DECLARE;
        
        static int GetMaxSize() noexcept;
        
        int GetSize() const noexcept;
        
        void ResetData() noexcept;
        uint8_t* GetMemory() noexcept;

		const uint8_t* GetMemory() const noexcept;
        
    private:
        // ���������������ӵ�е��ֽ�����
		static constexpr auto sm_MaxSize = 100;
        
        int m_MemoryLength;
        uint8_t* m_Memory;
    };
}

#endif // CORE_TOOLS_MEMORY_TOOLS_BUFER_H
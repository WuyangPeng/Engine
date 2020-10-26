//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/21 20:59)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_INIT_TERM_CONTAINER_H
#define CORE_TOOLS_OBJECT_SYSTEMS_INIT_TERM_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include <array>

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE InitTermContainer final
    {
    public:
        using ClassType = InitTermContainer;
        using ExecuteFunction = void (*)();

    public:
        InitTermContainer() noexcept;

        CLASS_INVARIANT_DECLARE;

        void AddExecuteFunction(ExecuteFunction function);
        void Execute();

    private:
        // �����Ŀ�����㹻����֧�����Ӧ�ó���������Ӧ�ó��򴥷��˶��ԣ��޸����ֵȻ�����±��롣
        // ��Ŀ���Ǳ���ִ���ڼ�premain��postmain�Ķ�̬���䣬�Ӷ�ʹ������׹���͸����ڴ�ʹ�������
        static constexpr auto sm_MaxElements = 256;
        static_assert(0 < sm_MaxElements);

        int m_NumFunction;
        std::array<ExecuteFunction, sm_MaxElements> m_ExecuteFunction;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_INIT_TERM_CONTAINER_H

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/24 16:07)

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
        static constexpr auto maxElements = 256;
        static_assert(0 < maxElements);

        int numFunction;
        std::array<ExecuteFunction, maxElements> executeFunction;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_INIT_TERM_CONTAINER_H

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/03/29 16:33)

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

    private:
        using Container = std::array<ExecuteFunction, maxElements>;

    private:
        int numFunction;
        Container executeFunction;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_INIT_TERM_CONTAINER_H

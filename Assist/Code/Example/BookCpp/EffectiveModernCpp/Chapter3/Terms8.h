///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/09/30 20:37)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER3_TERM8_H
#define EFFECTIVE_MODERN_CPP_CHAPTER3_TERM8_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <memory>
#include <mutex>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter3
        {
            namespace Terms8
            {
                void F(int);  // F���������ذ汾
                void F(bool);
                void F(void*);

                int* FindRecord() noexcept;

                class Widget
                {
                };

                // �����ʵ���Ϣ�����������ŵ����⼸������
                int F1(MAYBE_UNUSED std::shared_ptr<Widget> spw) noexcept;
                double F2(MAYBE_UNUSED std::unique_ptr<Widget> upw) noexcept;
                bool F3(MAYBE_UNUSED Widget* pw) noexcept;

                namespace Example1
                {
                    template <typename FuncType, typename MuxType, typename PtrType>
                    auto LockAndCall(FuncType func, MuxType& mutex, PtrType ptr) -> decltype(func(ptr))
                    {
                        using MuxGuard = std::lock_guard<std::mutex>;

                        MuxGuard g(mutex);
                        return func(ptr);
                    }
                }

                namespace Example2
                {
                    // C++14
                    template <typename FuncType, typename MuxType, typename PtrType>
                    decltype(auto) LockAndCall(FuncType func, MuxType& mutex, PtrType ptr)
                    {
                        using MuxGuard = std::lock_guard<std::mutex>;

                        MuxGuard g(mutex);
                        return func(ptr);
                    }
                }
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER3_TERM8_H

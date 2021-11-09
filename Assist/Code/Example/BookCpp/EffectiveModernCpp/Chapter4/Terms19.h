///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.5 (2021/10/20 21:21)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER4_TERM19_H
#define EFFECTIVE_MODERN_CPP_CHAPTER4_TERM19_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <vector>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter4
        {
            namespace Terms19
            {
                namespace Example0
                {
                    class Widget
                    {
                    };

                    void MakeLogEntry(MAYBE_UNUSED Widget* pw) noexcept;
                }

                namespace Example1
                {
                    class Widget
                    {
                        // ...
                        void Process();
                        // ...
                    };
                }

                namespace Example2
                {
                    class Widget : public std::enable_shared_from_this<Widget>
                    {
                        // ...
                        void Process();
                        // ...
                    };
                }

                namespace Example3
                {
                    class Widget : public std::enable_shared_from_this<Widget>
                    {
                    public:
                        // ��ʵ������ת����private���캯���Ĺ�������
                        template <typename... Ts>
                        static std::shared_ptr<Widget> Create(Ts&&... params);

                        // ...
                        void Process();  // ͬǰ
                        // ...

                    private:
                        // ...
                        // ���캯��
                    };
                }
            }
        }
    }
}
#endif  // EFFECTIVE_MODERN_CPP_CHAPTER4_TERM18_H

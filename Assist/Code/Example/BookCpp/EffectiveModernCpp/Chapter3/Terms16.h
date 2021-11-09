///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/09/30 20:37)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER3_TERM16_H
#define EFFECTIVE_MODERN_CPP_CHAPTER3_TERM16_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <mutex>
#include <vector>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter3
        {
            namespace Terms16
            {
                namespace Example0
                {
                    class Polynomial
                    {
                    public:
                        // ���е�ֵ�����ݽṹ����Щֵʹ�ö���ʽ���Ϊ��
                        using RootsType = std::vector<double>;

                        // ...
                        RootsType Roots() const;

                        // ...
                    };
                }

                namespace Example1
                {
                    class Polynomial
                    {
                    public:
                        using RootsType = std::vector<double>;

                        RootsType Roots() const;

                    private:
                        mutable bool rootsAreValid{ false };
                        mutable RootsType rootVals{};
                    };
                }

                namespace Example2
                {
                    class Polynomial
                    {
                    public:
                        using RootsType = std::vector<double>;

                        RootsType Roots() const;

                    private:
                        mutable std::mutex m;
                        mutable bool rootsAreValid{ false };
                        mutable RootsType rootVals{};
                    };
                }

                class Point  // ��ʾ2D��
                {
                public:
                    // ...
                    double DistanceFromOrgin() const noexcept;

                private:
                    mutable std::atomic<unsigned> callCount{ 0 };
                    double x, y;
                };

                int ExpensiveComputation1() noexcept;
                int ExpensiveComputation2() noexcept;

                namespace Example0
                {
                    class Widget
                    {
                    public:
                        // ...

                        int MagicValue() const noexcept;

                    private:
                        mutable std::atomic<bool> cacheValid{ false };
                        mutable std::atomic<int> cachedValue;
                    };
                }

                namespace Example1
                {
                    class Widget
                    {
                    public:
                        // ...

                        int MagicValue() const noexcept;

                    private:
                        mutable std::atomic<bool> cacheValid{ false };
                        mutable std::atomic<int> cachedValue;
                    };
                }

                namespace Example2
                {
                    class Widget
                    {
                    public:
                        // ...

                        int MagicValue() const;

                        // ...
                    private:
                        mutable std::mutex m;
                        mutable int cachedValue;  // ���߱�ԭ����
                        mutable bool cacheValid{ false };  // ���߱�ԭ����
                    };
                }
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER3_TERM16_H

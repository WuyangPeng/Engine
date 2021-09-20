///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/26 23:40)

#ifndef APPLIED_CPP_CHAPTER2_AP_IMAGE_H
#define APPLIED_CPP_CHAPTER2_AP_IMAGE_H

#include "Example/BookCpp/AppliedCpp/AppliedCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <string>

namespace BookIntermediate
{
    namespace AppliedCpp
    {
        ///  �򵥵Ķ�������ͼ����������

        /// ���
        ///       1         2         3         4         5         6    6
        ///345678901234567890123456789012345678901234567890123456789012345

        /// APImage��һ���򵥵�ͼ���࣬��Ϊ8λ��ɫͼ������ڴ棬�������������ͼ�����ݡ�
        class APPLIED_CPP_DEFAULT_DECLARE APImage final
        {
        public:
            using ClassType = APImage;

        public:
            CLASS_INVARIANT_DECLARE;

        public:
            // ����һ����ͼ���������Ժ�ķ���
            APImage() noexcept;

            // ����ָ����С��ͼ��
            APImage(int width, int height);

            ~APImage();

            // ������Ҫ�����Լ��ĸ��ƹ��캯���͸�ֵ���������Ϊ��Ա�����޷�����Ҫ��
            APImage(const APImage& src);
            APImage& operator=(const APImage& src);

            APImage(APImage&& src) noexcept;
            APImage& operator=(APImage&& src) noexcept;

            // �ڸ�ֵ�ڼ�ʹ�ã�Sutter��Exceptional C++����ʹ��ֵ������쳣��ȫ��
            void Swap(APImage& src) noexcept;

            // д��/��ȡ�������ء�
            // ���������Ч�����׳�rangeError��
            void SetPixel(int x, int y, unsigned char pixel);
            [[nodiscard]] unsigned char GetPixel(int x, int y) const;

            // ����ͼ�������Ƿ���ڣ����Ҵ����Ч��
            [[nodiscard]] bool IsImageValid() const noexcept;

            // ����ͼ��ķ�Χ
            [[nodiscard]] int Width() const noexcept;
            [[nodiscard]] int Height() const noexcept;

            // �����������ݲ���ͼ���У������������
            class RangeError
            {
            };

            APImage ArbitraryAlgorithm(const std::string& args);

        private:
            // ���³�ʼ�������ͷ��ѷ�����ڴ�
            void Cleanup() noexcept;

            // ��ʼ��ͼ������
            void Init();

            // ͼ����
            int width;
            // ͼ��߶�
            int height;
            // ͼ������
            unsigned char* pixels;
        };
    }
}

#endif  // APPLIED_CPP_CHAPTER2_AP_IMAGE_H

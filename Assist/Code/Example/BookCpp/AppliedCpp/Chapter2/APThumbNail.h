///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/26 23:49)

#ifndef APPLIED_CPP_CHAPTER2_AP_THUMB_NAIL_H
#define APPLIED_CPP_CHAPTER2_AP_THUMB_NAIL_H

#include "Example/BookCpp/AppliedCpp/AppliedCppDll.h"

#include "APImage.h"

namespace BookIntermediate
{
    namespace AppliedCpp
    {
        ///  �򵥵Ķ�������ͼ����������

        /// ���

        ///       1         2         3         4         5         6    6
        ///345678901234567890123456789012345678901234567890123456789012345

        /// APThumbNail��ȡ�����ļ�����������ļ������ļ���ԭʼ�ļ���ָ����С�汾��
        class APPLIED_CPP_DEFAULT_DECLARE APThumbNail final
        {
        public:
            using ClassType = APThumbNail;

        public:
            APThumbNail() noexcept;

        public:
            CLASS_INVARIANT_DECLARE;

            // Ĭ�ϵĸ��ƹ��캯���͸�ֵ�������ok��

            // ��������ָ����Сϵ����2,3,..��������ͼ
            void CreateThumbNail(const char* inputFile, const char* outputFile, int factor);

            // ��⵽����ʱ���׳��쳣
            class Invalid
            {
            };

        private:
            // ��ȡԭʼͼ��д������ͼ��
            void ReadImage(const char* inputFile);
            void WriteImage(const char* outputFile) const;

            // ������ͼͼ���в���һ���������
            [[nodiscard]] unsigned char AveragePixels(int x0, int y0, int factor);

            // ��������
            APImage image;
            // ����ͼ
            APImage thumbNail;
        };
    }
}

#endif  // APPLIED_CPP_CHAPTER2_AP_THUMB_NAIL_H

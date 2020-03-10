// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/08 15:40)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT_STORAGE_TYPE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT_STORAGE_TYPE_H

namespace Mathematics
{
    enum class Bisect2StorageType
    {
        BeginXAndBeginY,
        EndXAndBeginY,
        BeginXAndEndY,
        EndXAndEndY,
        BeginXAndMidY,
        EndXAndMidY,
        MidXAndBeginY,
        MidXAndEndY,
        MidXAndMidY,
    };
    
    enum class Bisect3StorageType
    {
       BeginXBeginYBeginZ,
       EndXBeginYBeginZ,
       BeginXEndYBeginZ,
       EndXEndYBeginZ,
       BeginXBeginYEndZ,
       EndXBeginYEndZ,
       BeginXEndYEndZ,
       EndXEndYEndZ,
       BeginXBeginYMidZ,
       EndXBeginYMidZ,
       BeginXEndYMidZ,
       EndXEndYMidZ,
       BeginXMidYBeginZ,
       EndXMidYBeginZ,
       BeginXMidYEndZ,
       EndXMidYEndZ,
       MidXBeginYBeginZ,
       MidXEndYBeginZ,
       MidXBeginYEndZ,
       MidXEndYEndZ,
       BeginXMidYMidZ,
       MidXBeginYMidZ,
       MidXMidYBeginZ,
       EndXMidYMidZ,
       MidXEndYMidZ,
       MidXMidYEndZ,
       MidXMidYMidZ,
    };    
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT_STORAGE_TYPE_H

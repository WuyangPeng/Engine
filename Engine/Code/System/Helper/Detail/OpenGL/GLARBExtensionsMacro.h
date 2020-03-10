// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:05)

#ifndef SYSTEM_HELPER_GL_ARB_EXTENSIONS_MACRO_H
#define SYSTEM_HELPER_GL_ARB_EXTENSIONS_MACRO_H

#include "System/Helper/GLExtensionsMacro.h"
 
// ARB ¿©’π

// (ARB 01) GL_ARB_multitexture

#define GL_TEXTURE0_ARB 0x84C0
#define GL_TEXTURE1_ARB 0x84C1
#define GL_TEXTURE2_ARB 0x84C2
#define GL_TEXTURE3_ARB 0x84C3
#define GL_TEXTURE4_ARB 0x84C4
#define GL_TEXTURE5_ARB 0x84C5
#define GL_TEXTURE6_ARB 0x84C6
#define GL_TEXTURE7_ARB 0x84C7
#define GL_TEXTURE8_ARB 0x84C8
#define GL_TEXTURE9_ARB 0x84C9
#define GL_TEXTURE10_ARB 0x84CA
#define GL_TEXTURE11_ARB 0x84CB
#define GL_TEXTURE12_ARB 0x84CC
#define GL_TEXTURE13_ARB 0x84CD
#define GL_TEXTURE14_ARB 0x84CE
#define GL_TEXTURE15_ARB 0x84CF
#define GL_TEXTURE16_ARB 0x84D0
#define GL_TEXTURE17_ARB 0x84D1
#define GL_TEXTURE18_ARB 0x84D2
#define GL_TEXTURE19_ARB 0x84D3
#define GL_TEXTURE20_ARB 0x84D4
#define GL_TEXTURE21_ARB 0x84D5
#define GL_TEXTURE22_ARB 0x84D6
#define GL_TEXTURE23_ARB 0x84D7
#define GL_TEXTURE24_ARB 0x84D8
#define GL_TEXTURE25_ARB 0x84D9
#define GL_TEXTURE26_ARB 0x84DA
#define GL_TEXTURE27_ARB 0x84DB
#define GL_TEXTURE28_ARB 0x84DC
#define GL_TEXTURE29_ARB 0x84DD
#define GL_TEXTURE30_ARB 0x84DE
#define GL_TEXTURE31_ARB 0x84DF
#define GL_ACTIVE_TEXTURE_ARB 0x84E0
#define GL_CLIENT_ACTIVE_TEXTURE_ARB 0x84E1
#define GL_MAX_TEXTURE_UNITS_ARB 0x84E2

#define glActiveTextureARB System::GlActiveTextureARB
#define glClientActiveTextureARB System::GlClientActiveTextureARB
#define glMultiTexCoord1dARB System::GlMultiTexCoord1dARB
#define glMultiTexCoord1dvARB System::GlMultiTexCoord1dvARB
#define glMultiTexCoord1fARB System::GlMultiTexCoord1fARB
#define glMultiTexCoord1fvARB System::GlMultiTexCoord1fvARB
#define glMultiTexCoord1iARB System::GlMultiTexCoord1iARB
#define glMultiTexCoord1ivARB System::GlMultiTexCoord1ivARB
#define glMultiTexCoord1sARB System::GlMultiTexCoord1sARB
#define glMultiTexCoord1svARB System::GlMultiTexCoord1svARB
#define glMultiTexCoord2dARB System::GlMultiTexCoord2dARB
#define glMultiTexCoord2dvARB System::GlMultiTexCoord2dvARB
#define glMultiTexCoord2fARB System::GlMultiTexCoord2fARB
#define glMultiTexCoord2fvARB System::GlMultiTexCoord2fvARB
#define glMultiTexCoord2iARB System::GlMultiTexCoord2iARB
#define glMultiTexCoord2ivARB System::GlMultiTexCoord2ivARB
#define glMultiTexCoord2sARB System::GlMultiTexCoord2sARB
#define glMultiTexCoord2svARB System::GlMultiTexCoord2svARB
#define glMultiTexCoord3dARB System::GlMultiTexCoord3dARB
#define glMultiTexCoord3dvARB System::GlMultiTexCoord3dvARB
#define glMultiTexCoord3fARB System::GlMultiTexCoord3fARB
#define glMultiTexCoord3fvARB System::GlMultiTexCoord3fvARB
#define glMultiTexCoord3iARB System::GlMultiTexCoord3iARB
#define glMultiTexCoord3ivARB System::GlMultiTexCoord3ivARB
#define glMultiTexCoord3sARB System::GlMultiTexCoord3sARB
#define glMultiTexCoord3svARB System::GlMultiTexCoord3svARB
#define glMultiTexCoord4dARB System::GlMultiTexCoord4dARB
#define glMultiTexCoord4dvARB System::GlMultiTexCoord4dvARB
#define glMultiTexCoord4fARB System::GlMultiTexCoord4fARB
#define glMultiTexCoord4fvARB System::GlMultiTexCoord4fvARB
#define glMultiTexCoord4iARB System::GlMultiTexCoord4iARB
#define glMultiTexCoord4ivARB System::GlMultiTexCoord4ivARB
#define glMultiTexCoord4sARB System::GlMultiTexCoord4sARB
#define glMultiTexCoord4svARB System::GlMultiTexCoord4svARB

// (ARB 03) GL_ARB_transpose_matrix

#define GL_TRANSPOSE_MODELVIEW_MATRIX_ARB 0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX_ARB 0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX_ARB 0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX_ARB 0x84E6

#define glLoadTransposeMatrixdARB System::GlLoadTransposeMatrixdARB
#define glLoadTransposeMatrixfARB System::GlLoadTransposeMatrixfARB
#define glMultTransposeMatrixdARB System::GlMultTransposeMatrixdARB
#define glMultTransposeMatrixfARB System::GlMultTransposeMatrixfARB

// (ARB 05) GL_ARB_multisample

#define GL_MULTISAMPLE_ARB 0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE_ARB 0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_ARB 0x809F
#define GL_SAMPLE_COVERAGE_ARB 0x80A0
#define GL_SAMPLE_BUFFERS_ARB 0x80A8
#define GL_SAMPLES_ARB 0x80A9
#define GL_SAMPLE_COVERAGE_VALUE_ARB 0x80AA
#define GL_SAMPLE_COVERAGE_INVERT_ARB 0x80AB
#define GL_MULTISAMPLE_BIT_ARB 0x20000000

#define glSampleCoverageARB System::GlSampleCoverageARB

// (ARB 07) GL_ARB_texture_cube_map

#define GL_NORMAL_MAP_ARB 0x8511
#define GL_REFLECTION_MAP_ARB 0x8512
#define GL_TEXTURE_CUBE_MAP_ARB 0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP_ARB 0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB 0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB 0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB 0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB 0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB 0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB 0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARB 0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB 0x851C

// (ARB 12) GL_ARB_texture_compression

#define GL_COMPRESSED_ALPHA_ARB 0x84E9
#define GL_COMPRESSED_LUMINANCE_ARB 0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA_ARB 0x84EB
#define GL_COMPRESSED_INTENSITY_ARB 0x84EC
#define GL_COMPRESSED_RGB_ARB 0x84ED
#define GL_COMPRESSED_RGBA_ARB 0x84EE
#define GL_TEXTURE_COMPRESSION_HINT_ARB 0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB 0x86A0
#define GL_TEXTURE_COMPRESSED_ARB 0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS_ARB 0x86A3

#define glCompressedTexImage1DARB System::GlCompressedTexImage1DARB
#define glCompressedTexImage2DARB System::GlCompressedTexImage2DARB
#define glCompressedTexImage3DARB System::GlCompressedTexImage3DARB
#define glCompressedTexSubImage1DARB System::GlCompressedTexSubImage1DARB
#define glCompressedTexSubImage2DARB System::GlCompressedTexSubImage2DARB
#define glCompressedTexSubImage3DARB System::GlCompressedTexSubImage3DARB
#define glGetCompressedTexImageARB System::GlGetCompressedTexImageARB

// (ARB 13) GL_ARB_texture_border_clamp

#define GL_CLAMP_TO_BORDER_ARB 0x812D

// (ARB 14) GL_ARB_point_parameters

#define GL_POINT_SIZE_MIN_ARB 0x8126
#define GL_POINT_SIZE_MAX_ARB 0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_ARB 0x8128
#define GL_POINT_DISTANCE_ATTENUATION_ARB 0x8129

#define glPointParameterfARB System::GlPointParameterfARB
#define glPointParameterfvARB System::GlPointParameterfvARB

// (ARB 15) GL_ARB_vertex_blend

#define GL_MAX_VERTEX_UNITS_ARB 0x86A4
#define GL_ACTIVE_VERTEX_UNITS_ARB 0x86A5
#define GL_WEIGHT_SUM_UNITY_ARB 0x86A6
#define GL_VERTEX_BLEND_ARB 0x86A7
#define GL_CURRENT_WEIGHT_ARB 0x86A8
#define GL_WEIGHT_ARRAY_TYPE_ARB 0x86A9
#define GL_WEIGHT_ARRAY_STRIDE_ARB 0x86AA
#define GL_WEIGHT_ARRAY_SIZE_ARB 0x86AB
#define GL_WEIGHT_ARRAY_POINTER_ARB 0x86AC
#define GL_WEIGHT_ARRAY_ARB 0x86AD
#define GL_MODELVIEW0_ARB 0x1700
#define GL_MODELVIEW1_ARB 0x850A
#define GL_MODELVIEW2_ARB 0x8722
#define GL_MODELVIEW3_ARB 0x8723
#define GL_MODELVIEW4_ARB 0x8724
#define GL_MODELVIEW5_ARB 0x8725
#define GL_MODELVIEW6_ARB 0x8726
#define GL_MODELVIEW7_ARB 0x8727
#define GL_MODELVIEW8_ARB 0x8728
#define GL_MODELVIEW9_ARB 0x8729
#define GL_MODELVIEW10_ARB 0x872A
#define GL_MODELVIEW11_ARB 0x872B
#define GL_MODELVIEW12_ARB 0x872C
#define GL_MODELVIEW13_ARB 0x872D
#define GL_MODELVIEW14_ARB 0x872E
#define GL_MODELVIEW15_ARB 0x872F
#define GL_MODELVIEW16_ARB 0x8730
#define GL_MODELVIEW17_ARB 0x8731
#define GL_MODELVIEW18_ARB 0x8732
#define GL_MODELVIEW19_ARB 0x8733
#define GL_MODELVIEW20_ARB 0x8734
#define GL_MODELVIEW21_ARB 0x8735
#define GL_MODELVIEW22_ARB 0x8736
#define GL_MODELVIEW23_ARB 0x8737
#define GL_MODELVIEW24_ARB 0x8738
#define GL_MODELVIEW25_ARB 0x8739
#define GL_MODELVIEW26_ARB 0x873A
#define GL_MODELVIEW27_ARB 0x873B
#define GL_MODELVIEW28_ARB 0x873C
#define GL_MODELVIEW29_ARB 0x873D
#define GL_MODELVIEW30_ARB 0x873E
#define GL_MODELVIEW31_ARB 0x873F

#define glWeightbvARB System::GlWeightbvARB
#define glWeightsvARB System::GlWeightsvARB
#define glWeightivARB System::GlWeightivARB
#define glWeightfvARB System::GlWeightfvARB
#define glWeightdvARB System::GlWeightdvARB
#define glWeightubvARB System::GlWeightubvARB
#define glWeightusvARB System::GlWeightusvARB
#define glWeightuivARB System::GlWeightuivARB
#define glWeightPointerARB System::GlWeightPointerARB
#define glVertexBlendARB System::GlVertexBlendARB

// (ARB 16) GL_ARB_matrix_palette

#define GL_MATRIX_PALETTE_ARB 0x8840
#define GL_MAX_MATRIX_PALETTE_STACK_DEPTH_ARB 0x8841
#define GL_MAX_PALETTE_MATRICES_ARB 0x8842
#define GL_CURRENT_PALETTE_MATRIX_ARB 0x8843
#define GL_MATRIX_INDEX_ARRAY_ARB 0x8844
#define GL_CURRENT_MATRIX_INDEX_ARB 0x8845
#define GL_MATRIX_INDEX_ARRAY_SIZE_ARB 0x8846
#define GL_MATRIX_INDEX_ARRAY_TYPE_ARB 0x8847
#define GL_MATRIX_INDEX_ARRAY_STRIDE_ARB 0x8848
#define GL_MATRIX_INDEX_ARRAY_POINTER_ARB 0x8849

#define glCurrentPaletteMatrixARB System::GlCurrentPaletteMatrixARB
#define glMatrixIndexubvARB System::GlMatrixIndexubvARB
#define glMatrixIndexusvARB System::GlMatrixIndexusvARB
#define glMatrixIndexuivARB System::GlMatrixIndexuivARB
#define glMatrixIndexPointerARB System::GlMatrixIndexPointerARB

// (ARB 17) GL_ARB_texture_env_combine

#define GL_SUBTRACT_ARB 0x84E7
#define GL_COMBINE_ARB 0x8570
#define GL_COMBINE_RGB_ARB 0x8571
#define GL_COMBINE_ALPHA_ARB 0x8572
#define GL_RGB_SCALE_ARB 0x8573
#define GL_ADD_SIGNED_ARB 0x8574
#define GL_INTERPOLATE_ARB 0x8575
#define GL_CONSTANT_ARB 0x8576
#define GL_PRIMARY_COLOR_ARB 0x8577
#define GL_PREVIOUS_ARB 0x8578
#define GL_SOURCE0_RGB_ARB 0x8580
#define GL_SOURCE1_RGB_ARB 0x8581
#define GL_SOURCE2_RGB_ARB 0x8582
#define GL_SOURCE0_ALPHA_ARB 0x8588
#define GL_SOURCE1_ALPHA_ARB 0x8589
#define GL_SOURCE2_ALPHA_ARB 0x858A
#define GL_OPERAND0_RGB_ARB 0x8590
#define GL_OPERAND1_RGB_ARB 0x8591
#define GL_OPERAND2_RGB_ARB 0x8592
#define GL_OPERAND0_ALPHA_ARB 0x8598
#define GL_OPERAND1_ALPHA_ARB 0x8599
#define GL_OPERAND2_ALPHA_ARB 0x859A

// (ARB 19) GL_ARB_texture_env_dot3

#define GL_DOT3_RGB_ARB 0x86AE
#define GL_DOT3_RGBA_ARB 0x86AF

// (ARB 21) GL_ARB_texture_mirrored_repeat

#define GL_MIRRORED_REPEAT_ARB 0x8370

// (ARB 22) GL_ARB_depth_texture

#define GL_DEPTH_COMPONENT16_ARB 0x81A5
#define GL_DEPTH_COMPONENT24_ARB 0x81A6
#define GL_DEPTH_COMPONENT32_ARB 0x81A7
#define GL_TEXTURE_DEPTH_SIZE_ARB 0x884A
#define GL_DEPTH_TEXTURE_MODE_ARB 0x884B

// (ARB 23) GL_ARB_shadow

#define GL_TEXTURE_COMPARE_MODE_ARB 0x884C
#define GL_TEXTURE_COMPARE_FUNC_ARB 0x884D
#define GL_COMPARE_R_TO_TEXTURE_ARB 0x884E

// (ARB 24) GL_ARB_shadow_ambient

#define GL_TEXTURE_COMPARE_FAIL_VALUE_ARB 0x80BF

// (ARB 25) GL_ARB_window_pos

#define glWindowPos2dARB System::GlWindowPos2dARB
#define glWindowPos2dvARB System::GlWindowPos2dvARB
#define glWindowPos2fARB System::GlWindowPos2fARB
#define glWindowPos2fvARB System::GlWindowPos2fvARB
#define glWindowPos2iARB System::GlWindowPos2iARB
#define glWindowPos2ivARB System::GlWindowPos2ivARB
#define glWindowPos2sARB System::GlWindowPos2sARB
#define glWindowPos2svARB System::GlWindowPos2svARB
#define glWindowPos3dARB System::GlWindowPos3dARB
#define glWindowPos3dvARB System::GlWindowPos3dvARB
#define glWindowPos3fARB System::GlWindowPos3fARB
#define glWindowPos3fvARB System::GlWindowPos3fvARB
#define glWindowPos3iARB System::GlWindowPos3iARB
#define glWindowPos3ivARB System::GlWindowPos3ivARB
#define glWindowPos3sARB System::GlWindowPos3sARB
#define glWindowPos3svARB System::GlWindowPos3svARB

// (ARB 26) GL_ARB_vertex_program

#define GL_COLOR_SUM_ARB 0x8458
#define GL_VERTEX_PROGRAM_ARB 0x8620
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB 0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB 0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB 0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB 0x8625
#define GL_CURRENT_VERTEX_ATTRIB_ARB 0x8626
#define GL_PROGRAM_LENGTH_ARB 0x8627
#define GL_PROGRAM_STRING_ARB 0x8628
#define GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB 0x862E
#define GL_MAX_PROGRAM_MATRICES_ARB 0x862F
#define GL_CURRENT_MATRIX_STACK_DEPTH_ARB 0x8640
#define GL_CURRENT_MATRIX_ARB 0x8641
#define GL_VERTEX_PROGRAM_POINT_SIZE_ARB 0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE_ARB 0x8643
#define GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB 0x8645
#define GL_PROGRAM_ERROR_POSITION_ARB 0x864B
#define GL_PROGRAM_BINDING_ARB 0x8677
#define GL_MAX_VERTEX_ATTRIBS_ARB 0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB 0x886A
#define GL_PROGRAM_ERROR_STRING_ARB 0x8874
#define GL_PROGRAM_FORMAT_ASCII_ARB 0x8875
#define GL_PROGRAM_FORMAT_ARB 0x8876
#define GL_PROGRAM_INSTRUCTIONS_ARB 0x88A0
#define GL_MAX_PROGRAM_INSTRUCTIONS_ARB 0x88A1
#define GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB 0x88A2
#define GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB 0x88A3
#define GL_PROGRAM_TEMPORARIES_ARB 0x88A4
#define GL_MAX_PROGRAM_TEMPORARIES_ARB 0x88A5
#define GL_PROGRAM_NATIVE_TEMPORARIES_ARB 0x88A6
#define GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB 0x88A7
#define GL_PROGRAM_PARAMETERS_ARB 0x88A8
#define GL_MAX_PROGRAM_PARAMETERS_ARB 0x88A9
#define GL_PROGRAM_NATIVE_PARAMETERS_ARB 0x88AA
#define GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB 0x88AB
#define GL_PROGRAM_ATTRIBS_ARB 0x88AC
#define GL_MAX_PROGRAM_ATTRIBS_ARB 0x88AD
#define GL_PROGRAM_NATIVE_ATTRIBS_ARB 0x88AE
#define GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB 0x88AF
#define GL_PROGRAM_ADDRESS_REGISTERS_ARB 0x88B0
#define GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB 0x88B1
#define GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB 0x88B2
#define GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB 0x88B3
#define GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB 0x88B4
#define GL_MAX_PROGRAM_ENV_PARAMETERS_ARB 0x88B5
#define GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB 0x88B6
#define GL_TRANSPOSE_CURRENT_MATRIX_ARB 0x88B7
#define GL_MATRIX0_ARB 0x88C0
#define GL_MATRIX1_ARB 0x88C1
#define GL_MATRIX2_ARB 0x88C2
#define GL_MATRIX3_ARB 0x88C3
#define GL_MATRIX4_ARB 0x88C4
#define GL_MATRIX5_ARB 0x88C5
#define GL_MATRIX6_ARB 0x88C6
#define GL_MATRIX7_ARB 0x88C7
#define GL_MATRIX8_ARB 0x88C8
#define GL_MATRIX9_ARB 0x88C9
#define GL_MATRIX10_ARB 0x88CA
#define GL_MATRIX11_ARB 0x88CB
#define GL_MATRIX12_ARB 0x88CC
#define GL_MATRIX13_ARB 0x88CD
#define GL_MATRIX14_ARB 0x88CE
#define GL_MATRIX15_ARB 0x88CF
#define GL_MATRIX16_ARB 0x88D0
#define GL_MATRIX17_ARB 0x88D1
#define GL_MATRIX18_ARB 0x88D2
#define GL_MATRIX19_ARB 0x88D3
#define GL_MATRIX20_ARB 0x88D4
#define GL_MATRIX21_ARB 0x88D5
#define GL_MATRIX22_ARB 0x88D6
#define GL_MATRIX23_ARB 0x88D7
#define GL_MATRIX24_ARB 0x88D8
#define GL_MATRIX25_ARB 0x88D9
#define GL_MATRIX26_ARB 0x88DA
#define GL_MATRIX27_ARB 0x88DB
#define GL_MATRIX28_ARB 0x88DC
#define GL_MATRIX29_ARB 0x88DD
#define GL_MATRIX30_ARB 0x88DE
#define GL_MATRIX31_ARB 0x88DF

#define glBindProgramARB System::GlBindProgramARB
#define glDeleteProgramsARB System::GlDeleteProgramsARB
#define glDisableVertexAttribArrayARB System::GlDisableVertexAttribArrayARB
#define glEnableVertexAttribArrayARB System::GlEnableVertexAttribArrayARB
#define glGenProgramsARB System::GlGenProgramsARB
#define glGetProgramivARB System::GlGetProgramivARB
#define glGetProgramEnvParameterdvARB System::GlGetProgramEnvParameterdvARB
#define glGetProgramEnvParameterfvARB System::GlGetProgramEnvParameterfvARB
#define glGetProgramLocalParameterdvARB System::GlGetProgramLocalParameterdvARB
#define glGetProgramLocalParameterfvARB System::GlGetProgramLocalParameterfvARB
#define glGetProgramStringARB System::GlGetProgramStringARB
#define glGetVertexAttribdvARB System::GlGetVertexAttribdvARB
#define glGetVertexAttribfvARB System::GlGetVertexAttribfvARB
#define glGetVertexAttribivARB System::GlGetVertexAttribivARB
#define glGetVertexAttribPointervARB System::GlGetVertexAttribPointervARB
#define glIsProgramARB System::GlIsProgramARB
#define glProgramEnvParameter4dARB System::GlProgramEnvParameter4dARB
#define glProgramEnvParameter4dvARB System::GlProgramEnvParameter4dvARB
#define glProgramEnvParameter4fARB System::GlProgramEnvParameter4fARB
#define glProgramEnvParameter4fvARB System::GlProgramEnvParameter4fvARB
#define glProgramLocalParameter4dARB System::GlProgramLocalParameter4dARB
#define glProgramLocalParameter4dvARB System::GlProgramLocalParameter4dvARB
#define glProgramLocalParameter4fARB System::GlProgramLocalParameter4fARB
#define glProgramLocalParameter4fvARB System::GlProgramLocalParameter4fvARB
#define glProgramStringARB System::GlProgramStringARB
#define glVertexAttrib1dARB System::GlVertexAttrib1dARB
#define glVertexAttrib1dvARB System::GlVertexAttrib1dvARB
#define glVertexAttrib1fARB System::GlVertexAttrib1fARB
#define glVertexAttrib1fvARB System::GlVertexAttrib1fvARB
#define glVertexAttrib1sARB System::GlVertexAttrib1sARB
#define glVertexAttrib1svARB System::GlVertexAttrib1svARB
#define glVertexAttrib2dARB System::GlVertexAttrib2dARB
#define glVertexAttrib2dvARB System::GlVertexAttrib2dvARB
#define glVertexAttrib2fARB System::GlVertexAttrib2fARB
#define glVertexAttrib2fvARB System::GlVertexAttrib2fvARB
#define glVertexAttrib2sARB System::GlVertexAttrib2sARB
#define glVertexAttrib2svARB System::GlVertexAttrib2svARB
#define glVertexAttrib3dARB System::GlVertexAttrib3dARB
#define glVertexAttrib3dvARB System::GlVertexAttrib3dvARB
#define glVertexAttrib3fARB System::GlVertexAttrib3fARB
#define glVertexAttrib3fvARB System::GlVertexAttrib3fvARB
#define glVertexAttrib3sARB System::GlVertexAttrib3sARB
#define glVertexAttrib3svARB System::GlVertexAttrib3svARB
#define glVertexAttrib4NbvARB System::GlVertexAttrib4NbvARB
#define glVertexAttrib4NivARB System::GlVertexAttrib4NivARB
#define glVertexAttrib4NsvARB System::GlVertexAttrib4NsvARB
#define glVertexAttrib4NubARB System::GlVertexAttrib4NubARB
#define glVertexAttrib4NubvARB System::GlVertexAttrib4NubvARB
#define glVertexAttrib4NuivARB System::GlVertexAttrib4NuivARB
#define glVertexAttrib4NusvARB System::GlVertexAttrib4NusvARB
#define glVertexAttrib4bvARB System::GlVertexAttrib4bvARB
#define glVertexAttrib4dARB System::GlVertexAttrib4dARB
#define glVertexAttrib4dvARB System::GlVertexAttrib4dvARB
#define glVertexAttrib4fARB System::GlVertexAttrib4fARB
#define glVertexAttrib4fvARB System::GlVertexAttrib4fvARB
#define glVertexAttrib4ivARB System::GlVertexAttrib4ivARB
#define glVertexAttrib4sARB System::GlVertexAttrib4sARB
#define glVertexAttrib4svARB System::GlVertexAttrib4svARB
#define glVertexAttrib4ubvARB System::GlVertexAttrib4ubvARB
#define glVertexAttrib4uivARB System::GlVertexAttrib4uivARB
#define glVertexAttrib4usvARB System::GlVertexAttrib4usvARB
#define glVertexAttribPointerARB System::GlVertexAttribPointerARB

// (ARB 27) GL_ARB_fragment_program

#define GL_FRAGMENT_PROGRAM_ARB 0x8804
#define GL_PROGRAM_ALU_INSTRUCTIONS_ARB 0x8805
#define GL_PROGRAM_TEX_INSTRUCTIONS_ARB 0x8806
#define GL_PROGRAM_TEX_INDIRECTIONS_ARB 0x8807
#define GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB 0x8808
#define GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB 0x8809
#define GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB 0x880A
#define GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB 0x880B
#define GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB 0x880C
#define GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB 0x880D
#define GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB 0x880E
#define GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB 0x880F
#define GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB 0x8810
#define GL_MAX_TEXTURE_COORDS_ARB 0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS_ARB 0x8872

// (ARB 28) GL_ARB_vertex_buffer_object

#define GL_BUFFER_SIZE_ARB 0x8764
#define GL_BUFFER_USAGE_ARB 0x8765
#define GL_ARRAY_BUFFER_ARB 0x8892
#define GL_ELEMENT_ARRAY_BUFFER_ARB 0x8893
#define GL_ARRAY_BUFFER_BINDING_ARB 0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB 0x8895
#define GL_VERTEX_ARRAY_BUFFER_BINDING_ARB 0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING_ARB 0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING_ARB 0x8898
#define GL_INDEX_ARRAY_BUFFER_BINDING_ARB 0x8899
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB 0x889A
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB 0x889B
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB 0x889C
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB 0x889D
#define GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB 0x889E
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB 0x889F
#define GL_READ_ONLY_ARB 0x88B8
#define GL_WRITE_ONLY_ARB 0x88B9
#define GL_READ_WRITE_ARB 0x88BA
#define GL_BUFFER_ACCESS_ARB 0x88BB
#define GL_BUFFER_MAPPED_ARB 0x88BC
#define GL_BUFFER_MAP_POINTER_ARB 0x88BD
#define GL_STREAM_DRAW_ARB 0x88E0
#define GL_STREAM_READ_ARB 0x88E1
#define GL_STREAM_COPY_ARB 0x88E2
#define GL_STATIC_DRAW_ARB 0x88E4
#define GL_STATIC_READ_ARB 0x88E5
#define GL_STATIC_COPY_ARB 0x88E6
#define GL_DYNAMIC_DRAW_ARB 0x88E8
#define GL_DYNAMIC_READ_ARB 0x88E9
#define GL_DYNAMIC_COPY_ARB 0x88EA

#define glBindBufferARB System::GlBindBufferARB
#define glDeleteBuffersARB System::GlDeleteBuffersARB
#define glGenBuffersARB System::GlGenBuffersARB
#define glIsBufferARB System::GlIsBufferARB
#define glBufferDataARB System::GlBufferDataARB
#define glBufferSubDataARB System::GlBufferSubDataARB
#define glGetBufferSubDataARB System::GlGetBufferSubDataARB
#define glMapBufferARB System::GlMapBufferARB
#define glUnmapBufferARB System::GlUnmapBufferARB
#define glGetBufferParameterivARB System::GlGetBufferParameterivARB
#define glGetBufferPointervARB System::GlGetBufferPointervARB

// (ARB 29) GL_ARB_occlusion_query

#define GL_QUERY_COUNTER_BITS_ARB 0x8864
#define GL_CURRENT_QUERY_ARB 0x8865
#define GL_QUERY_RESULT_ARB 0x8866
#define GL_QUERY_RESULT_AVAILABLE_ARB 0x8867
#define GL_SAMPLES_PASSED_ARB 0x8914

#define glGenQueriesARB System::GlGenQueriesARB
#define glDeleteQueriesARB System::GlDeleteQueriesARB
#define glIsQueryARB System::GlIsQueryARB
#define glBeginQueryARB System::GlBeginQueryARB
#define glEndQueryARB System::GlEndQueryARB
#define glGetQueryivARB System::GlGetQueryivARB
#define glGetQueryObjectivARB System::GlGetQueryObjectivARB
#define glGetQueryObjectuivARB System::GlGetQueryObjectuivARB

// (ARB 30) GL_ARB_shader_objects

#define GL_PROGRAM_OBJECT_ARB 0x8B40
#define GL_SHADER_OBJECT_ARB 0x8B48
#define GL_OBJECT_TYPE_ARB 0x8B4E
#define GL_OBJECT_SUBTYPE_ARB 0x8B4F
#define GL_FLOAT_VEC2_ARB 0x8B50
#define GL_FLOAT_VEC3_ARB 0x8B51
#define GL_FLOAT_VEC4_ARB 0x8B52
#define GL_INT_VEC2_ARB 0x8B53
#define GL_INT_VEC3_ARB 0x8B54
#define GL_INT_VEC4_ARB 0x8B55
#define GL_BOOL_ARB 0x8B56
#define GL_BOOL_VEC2_ARB 0x8B57
#define GL_BOOL_VEC3_ARB 0x8B58
#define GL_BOOL_VEC4_ARB 0x8B59
#define GL_FLOAT_MAT2_ARB 0x8B5A
#define GL_FLOAT_MAT3_ARB 0x8B5B
#define GL_FLOAT_MAT4_ARB 0x8B5C
#define GL_SAMPLER_1D_ARB 0x8B5D
#define GL_SAMPLER_2D_ARB 0x8B5E
#define GL_SAMPLER_3D_ARB 0x8B5F
#define GL_SAMPLER_CUBE_ARB 0x8B60
#define GL_SAMPLER_1D_SHADOW_ARB 0x8B61
#define GL_SAMPLER_2D_SHADOW_ARB 0x8B62
#define GL_SAMPLER_2D_RECT_ARB 0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW_ARB 0x8B64
#define GL_OBJECT_DELETE_STATUS_ARB 0x8B80
#define GL_OBJECT_COMPILE_STATUS_ARB 0x8B81
#define GL_OBJECT_LINK_STATUS_ARB 0x8B82
#define GL_OBJECT_VALIDATE_STATUS_ARB 0x8B83
#define GL_OBJECT_INFO_LOG_LENGTH_ARB 0x8B84
#define GL_OBJECT_ATTACHED_OBJECTS_ARB 0x8B85
#define GL_OBJECT_ACTIVE_UNIFORMS_ARB 0x8B86
#define GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB 0x8B87
#define GL_OBJECT_SHADER_SOURCE_LENGTH_ARB 0x8B88

#define glAttachObjectARB System::GlAttachObjectARB
#define glCompileShaderARB System::GlCompileShaderARB
#define glCreateProgramObjectARB System::GlCreateProgramObjectARB
#define glCreateShaderObjectARB System::GlCreateShaderObjectARB
#define glDeleteObjectARB System::GlDeleteObjectARB
#define glDetachObjectARB System::GlDetachObjectARB
#define glGetActiveUniformARB System::GlGetActiveUniformARB
#define glGetAttachedObjectsARB System::GlGetAttachedObjectsARB
#define glGetHandleARB System::GlGetHandleARB
#define glGetInfoLogARB System::GlGetInfoLogARB
#define glGetObjectParameterfvARB System::GlGetObjectParameterfvARB
#define glGetObjectParameterivARB System::GlGetObjectParameterivARB
#define glGetShaderSourceARB System::GlGetShaderSourceARB
#define glGetUniformfvARB System::GlGetUniformfvARB
#define glGetUniformivARB System::GlGetUniformivARB
#define glGetUniformLocationARB System::GlGetUniformLocationARB
#define glLinkProgramARB System::GlLinkProgramARB
#define glShaderSourceARB System::GlShaderSourceARB
#define glUniform1fARB System::GlUniform1fARB
#define glUniform2fARB System::GlUniform2fARB
#define glUniform3fARB System::GlUniform3fARB
#define glUniform4fARB System::GlUniform4fARB
#define glUniform1iARB System::GlUniform1iARB
#define glUniform2iARB System::GlUniform2iARB
#define glUniform3iARB System::GlUniform3iARB
#define glUniform4iARB System::GlUniform4iARB
#define glUniform1fvARB System::GlUniform1fvARB
#define glUniform2fvARB System::GlUniform2fvARB
#define glUniform3fvARB System::GlUniform3fvARB
#define glUniform4fvARB System::GlUniform4fvARB
#define glUniform1ivARB System::GlUniform1ivARB
#define glUniform2ivARB System::GlUniform2ivARB
#define glUniform3ivARB System::GlUniform3ivARB
#define glUniform4ivARB System::GlUniform4ivARB
#define glUniformMatrix2fvARB System::GlUniformMatrix2fvARB
#define glUniformMatrix3fvARB System::GlUniformMatrix3fvARB
#define glUniformMatrix4fvARB System::GlUniformMatrix4fvARB
#define glUseProgramObjectARB System::GlUseProgramObjectARB
#define glValidateProgramARB System::GlValidateProgramARB

// (ARB 31) GL_ARB_vertex_shader

#define GL_VERTEX_SHADER_ARB 0x8B31
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB 0x8B4A
#define GL_MAX_VARYING_FLOATS_ARB 0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB 0x8B4D
#define GL_OBJECT_ACTIVE_ATTRIBUTES_ARB 0x8B89
#define GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB 0x8B8A

#define glBindAttribLocationARB System::GlBindAttribLocationARB
#define glGetActiveAttribARB System::GlGetActiveAttribARB
#define glGetAttribLocationARB System::GlGetAttribLocationARB

// (ARB 32) GL_ARB_fragment_shader

#define GL_FRAGMENT_SHADER_ARB 0x8B30
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB 0x8B49
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT_ARB 0x8B8B

// (ARB 33) GL_ARB_shading_language_100

#define GL_SHADING_LANGUAGE_VERSION_ARB 0x8B8C

// (ARB 35) GL_ARB_point_sprite

#define GL_POINT_SPRITE_ARB 0x8861
#define GL_COORD_REPLACE_ARB 0x8862

// (ARB 37) GL_ARB_draw_buffers

#define GL_MAX_DRAW_BUFFERS_ARB 0x8824
#define GL_DRAW_BUFFER0_ARB 0x8825
#define GL_DRAW_BUFFER1_ARB 0x8826
#define GL_DRAW_BUFFER2_ARB 0x8827
#define GL_DRAW_BUFFER3_ARB 0x8828
#define GL_DRAW_BUFFER4_ARB 0x8829
#define GL_DRAW_BUFFER5_ARB 0x882A
#define GL_DRAW_BUFFER6_ARB 0x882B
#define GL_DRAW_BUFFER7_ARB 0x882C
#define GL_DRAW_BUFFER8_ARB 0x882D
#define GL_DRAW_BUFFER9_ARB 0x882E
#define GL_DRAW_BUFFER10_ARB 0x882F
#define GL_DRAW_BUFFER11_ARB 0x8830
#define GL_DRAW_BUFFER12_ARB 0x8831
#define GL_DRAW_BUFFER13_ARB 0x8832
#define GL_DRAW_BUFFER14_ARB 0x8833
#define GL_DRAW_BUFFER15_ARB 0x8834

#define glDrawBuffersARB System::GlDrawBuffersARB

// (ARB 38) GL_ARB_texture_rectangle

#define GL_TEXTURE_RECTANGLE_ARB 0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE_ARB 0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE_ARB 0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB 0x84F8

// (ARB 39) GL_ARB_color_buffer_float

#define GL_RGBA_FLOAT_MODE_ARB 0x8820
#define GL_CLAMP_VERTEX_COLOR_ARB 0x891A
#define GL_CLAMP_FRAGMENT_COLOR_ARB 0x891B
#define GL_CLAMP_READ_COLOR_ARB 0x891C
#define GL_FIXED_ONLY_ARB 0x891D

#define glClampColorARB System::GlClampColorARB

// (ARB 40) GL_ARB_half_float_pixel

#define GL_HALF_FLOAT_ARB 0x140B

// (ARB 41) GL_ARB_texture_float

#define GL_TEXTURE_RED_TYPE_ARB 0x8C10
#define GL_TEXTURE_GREEN_TYPE_ARB 0x8C11
#define GL_TEXTURE_BLUE_TYPE_ARB 0x8C12
#define GL_TEXTURE_ALPHA_TYPE_ARB 0x8C13
#define GL_TEXTURE_LUMINANCE_TYPE_ARB 0x8C14
#define GL_TEXTURE_INTENSITY_TYPE_ARB 0x8C15
#define GL_TEXTURE_DEPTH_TYPE_ARB 0x8C16
#define GL_UNSIGNED_NORMALIZED_ARB 0x8C17
#define GL_RGBA32F_ARB 0x8814
#define GL_RGB32F_ARB 0x8815
#define GL_ALPHA32F_ARB 0x8816
#define GL_INTENSITY32F_ARB 0x8817
#define GL_LUMINANCE32F_ARB 0x8818
#define GL_LUMINANCE_ALPHA32F_ARB 0x8819
#define GL_RGBA16F_ARB 0x881A
#define GL_RGB16F_ARB 0x881B
#define GL_ALPHA16F_ARB 0x881C
#define GL_INTENSITY16F_ARB 0x881D
#define GL_LUMINANCE16F_ARB 0x881E
#define GL_LUMINANCE_ALPHA16F_ARB 0x881F

// (ARB 42) GL_ARB_pixel_buffer_object

#define GL_PIXEL_PACK_BUFFER_ARB 0x88EB
#define GL_PIXEL_UNPACK_BUFFER_ARB 0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING_ARB 0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING_ARB 0x88EF

// (ARB 43) GL_ARB_depth_buffer_float

#define GL_DEPTH_COMPONENT32F 0x8CAC
#define GL_DEPTH32F_STENCIL8 0x8CAD
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV 0x8DAD

// (ARB 45) GL_ARB_framebuffer_object 

#define GL_INVALID_FRAMEBUFFER_OPERATION 0x0506
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING 0x8210
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE 0x8211
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE 0x8212
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE 0x8213
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE 0x8214
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE 0x8215
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE 0x8216
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE 0x8217
#define GL_FRAMEBUFFER_DEFAULT 0x8218
#define GL_FRAMEBUFFER_UNDEFINED 0x8219
#define GL_DEPTH_STENCIL_ATTACHMENT 0x821A
#define GL_INDEX 0x8222
#define GL_MAX_RENDERBUFFER_SIZE 0x84E8
#define GL_DEPTH_STENCIL 0x84F9
#define GL_UNSIGNED_INT_24_8 0x84FA
#define GL_DEPTH24_STENCIL8 0x88F0
#define GL_TEXTURE_STENCIL_SIZE 0x88F1
#define GL_UNSIGNED_NORMALIZED 0x8C17
#define GL_SRGB 0x8C40
#define GL_DRAW_FRAMEBUFFER_BINDING 0x8CA6
#define GL_FRAMEBUFFER_BINDING 0x8CA6
#define GL_RENDERBUFFER_BINDING 0x8CA7
#define GL_READ_FRAMEBUFFER 0x8CA8
#define GL_DRAW_FRAMEBUFFER 0x8CA9
#define GL_READ_FRAMEBUFFER_BINDING 0x8CAA
#define GL_RENDERBUFFER_SAMPLES 0x8CAB
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4
#define GL_FRAMEBUFFER_COMPLETE 0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER 0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER 0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED 0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS 0x8CDF
#define GL_COLOR_ATTACHMENT0 0x8CE0
#define GL_COLOR_ATTACHMENT1 0x8CE1
#define GL_COLOR_ATTACHMENT2 0x8CE2
#define GL_COLOR_ATTACHMENT3 0x8CE3
#define GL_COLOR_ATTACHMENT4 0x8CE4
#define GL_COLOR_ATTACHMENT5 0x8CE5
#define GL_COLOR_ATTACHMENT6 0x8CE6
#define GL_COLOR_ATTACHMENT7 0x8CE7
#define GL_COLOR_ATTACHMENT8 0x8CE8
#define GL_COLOR_ATTACHMENT9 0x8CE9
#define GL_COLOR_ATTACHMENT10 0x8CEA
#define GL_COLOR_ATTACHMENT11 0x8CEB
#define GL_COLOR_ATTACHMENT12 0x8CEC
#define GL_COLOR_ATTACHMENT13 0x8CED
#define GL_COLOR_ATTACHMENT14 0x8CEE
#define GL_COLOR_ATTACHMENT15 0x8CEF
#define GL_DEPTH_ATTACHMENT 0x8D00
#define GL_STENCIL_ATTACHMENT 0x8D20
#define GL_FRAMEBUFFER 0x8D40
#define GL_RENDERBUFFER 0x8D41
#define GL_RENDERBUFFER_WIDTH 0x8D42
#define GL_RENDERBUFFER_HEIGHT 0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT 0x8D44
#define GL_STENCIL_INDEX1 0x8D46
#define GL_STENCIL_INDEX4 0x8D47
#define GL_STENCIL_INDEX8 0x8D48
#define GL_STENCIL_INDEX16 0x8D49
#define GL_RENDERBUFFER_RED_SIZE 0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE 0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE 0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE 0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE 0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE 0x8D55
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE 0x8D56
#define GL_MAX_SAMPLES 0x8D57

#define glBindFramebuffer System::GlBindFramebuffer
#define glBindRenderbuffer System::GlBindRenderbuffer
#define glBlitFramebuffer System::GlBlitFramebuffer
#define glCheckFramebufferStatus System::GlCheckFramebufferStatus
#define glDeleteFramebuffers System::GlDeleteFramebuffers
#define glDeleteRenderbuffers System::GlDeleteRenderbuffers
#define glFramebufferRenderbuffer System::GlFramebufferRenderbuffer
#define glFramebufferTexture1D System::GlFramebufferTexture1D
#define glFramebufferTexture2D System::GlFramebufferTexture2D
#define glFramebufferTexture3D System::GlFramebufferTexture3D
#define glFramebufferTextureLayer System::GlFramebufferTextureLayer
#define glGenFramebuffers System::GlGenFramebuffers
#define glGenRenderbuffers System::GlGenRenderbuffers
#define glGenerateMipmap System::GlGenerateMipmap
#define glGetFramebufferAttachmentParameteriv System::GlGetFramebufferAttachmentParameteriv
#define glGetRenderbufferParameteriv System::GlGetRenderbufferParameteriv
#define glIsFramebuffer System::GlIsFramebuffer
#define glIsRenderbuffer System::GlIsRenderbuffer
#define glRenderbufferStorage System::GlRenderbufferStorage
#define glRenderbufferStorageMultisample System::GlRenderbufferStorageMultisample

// (ARB 46) GL_ARB_framebuffer_sRGB

#define GL_FRAMEBUFFER_SRGB 0x8DB9

// (ARB 47) GL_ARB_geometry_shader4

#define GL_LINES_ADJACENCY_ARB 0xA
#define GL_LINE_STRIP_ADJACENCY_ARB 0xB
#define GL_TRIANGLES_ADJACENCY_ARB 0xC
#define GL_TRIANGLE_STRIP_ADJACENCY_ARB 0xD
#define GL_PROGRAM_POINT_SIZE_ARB 0x8642
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB 0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_ARB 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_ARB 0x8DA8
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_ARB 0x8DA9
#define GL_GEOMETRY_SHADER_ARB 0x8DD9
#define GL_GEOMETRY_VERTICES_OUT_ARB 0x8DDA
#define GL_GEOMETRY_INPUT_TYPE_ARB 0x8DDB
#define GL_GEOMETRY_OUTPUT_TYPE_ARB 0x8DDC
#define GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB 0x8DDD
#define GL_MAX_VERTEX_VARYING_COMPONENTS_ARB 0x8DDE
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB 0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB 0x8DE1

#define glFramebufferTextureARB System::GlFramebufferTextureARB
#define glFramebufferTextureFaceARB System::GlFramebufferTextureFaceARB
#define glFramebufferTextureLayerARB System::GlFramebufferTextureLayerARB
#define glProgramParameteriARB System::GlProgramParameteriARB

// (ARB 48) GL_ARB_half_float_vertex

#define GL_HALF_FLOAT 0x140B

// (ARB 49) GL_ARB_instanced_arrays

#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR_ARB 0x88FE

#define glDrawArraysInstancedARB System::GlDrawArraysInstancedARB
#define glDrawElementsInstancedARB System::GlDrawElementsInstancedARB
#define glVertexAttribDivisorARB System::GlVertexAttribDivisorARB

// (ARB 50) GL_ARB_map_buffer_range

#define GL_MAP_READ_BIT 0x0001
#define GL_MAP_WRITE_BIT 0x0002
#define GL_MAP_INVALIDATE_RANGE_BIT 0x0004
#define GL_MAP_INVALIDATE_BUFFER_BIT 0x0008
#define GL_MAP_FLUSH_EXPLICIT_BIT 0x0010
#define GL_MAP_UNSYNCHRONIZED_BIT 0x0020

#define glMapBufferRange System::GlMapBufferRange
#define glFlushMappedBufferRange System::GlFlushMappedBufferRange

// (ARB 51) GL_ARB_texture_buffer_object

#define GL_TEXTURE_BUFFER_ARB 0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE_ARB 0x8C2B
#define GL_TEXTURE_BINDING_BUFFER_ARB 0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING_ARB 0x8C2D
#define GL_TEXTURE_BUFFER_FORMAT_ARB 0x8C2E

#define glTexBufferARB System::GlTexBufferARB

// (ARB 52) GL_ARB_texture_compression_rgtc 

#define GL_COMPRESSED_RED_RGTC1 0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1 0x8DBC
#define GL_COMPRESSED_RG_RGTC2 0x8DBD
#define GL_COMPRESSED_SIGNED_RG_RGTC2 0x8DBE

// (ARB 53) GL_ARB_texture_rg

#define GL_RG 0x8227
#define GL_RG_INTEGER 0x8228
#define GL_R8 0x8229
#define GL_R16 0x822A
#define GL_RG8 0x822B
#define GL_RG16 0x822C
#define GL_R16F 0x822D
#define GL_R32F 0x822E
#define GL_RG16F 0x822F
#define GL_RG32F 0x8230
#define GL_R8I 0x8231
#define GL_R8UI 0x8232
#define GL_R16I 0x8233
#define GL_R16UI 0x8234
#define GL_R32I 0x8235
#define GL_R32UI 0x8236
#define GL_RG8I 0x8237
#define GL_RG8UI 0x8238
#define GL_RG16I 0x8239
#define GL_RG16UI 0x823A
#define GL_RG32I 0x823B
#define GL_RG32UI 0x823C

// (ARB 54) GL_ARB_vertex_array_object

#define GL_VERTEX_ARRAY_BINDING 0x85B5

#define glBindVertexArray System::GlBindVertexArray
#define glDeleteVertexArrays System::GlDeleteVertexArrays
#define glGenVertexArrays System::GlGenVertexArrays
#define glIsVertexArray System::GlIsVertexArray

// (ARB 57) GL_ARB_uniform_buffer_object

#define GL_UNIFORM_BUFFER 0x8A11
#define GL_UNIFORM_BUFFER_BINDING 0x8A28
#define GL_UNIFORM_BUFFER_START 0x8A29
#define GL_UNIFORM_BUFFER_SIZE 0x8A2A
#define GL_MAX_VERTEX_UNIFORM_BLOCKS 0x8A2B
#define GL_MAX_GEOMETRY_UNIFORM_BLOCKS 0x8A2C
#define GL_MAX_FRAGMENT_UNIFORM_BLOCKS 0x8A2D
#define GL_MAX_COMBINED_UNIFORM_BLOCKS 0x8A2E
#define GL_MAX_UNIFORM_BUFFER_BINDINGS 0x8A2F
#define GL_MAX_UNIFORM_BLOCK_SIZE 0x8A30
#define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS 0x8A31
#define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS 0x8A32
#define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS 0x8A33
#define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT 0x8A34
#define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH 0x8A35
#define GL_ACTIVE_UNIFORM_BLOCKS 0x8A36
#define GL_UNIFORM_TYPE 0x8A37
#define GL_UNIFORM_SIZE 0x8A38
#define GL_UNIFORM_NAME_LENGTH 0x8A39
#define GL_UNIFORM_BLOCK_INDEX 0x8A3A
#define GL_UNIFORM_OFFSET 0x8A3B
#define GL_UNIFORM_ARRAY_STRIDE 0x8A3C
#define GL_UNIFORM_MATRIX_STRIDE 0x8A3D
#define GL_UNIFORM_IS_ROW_MAJOR 0x8A3E
#define GL_UNIFORM_BLOCK_BINDING 0x8A3F
#define GL_UNIFORM_BLOCK_DATA_SIZE 0x8A40
#define GL_UNIFORM_BLOCK_NAME_LENGTH 0x8A41
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS 0x8A42
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES 0x8A43
#define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER 0x8A44
#define GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER 0x8A45
#define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER 0x8A46
#define GL_INVALID_INDEX 0xFFFFFFFF

#define glGetActiveUniformBlockName System::GlGetActiveUniformBlockName
#define glGetActiveUniformBlockiv System::GlGetActiveUniformBlockiv
#define glGetActiveUniformName System::GlGetActiveUniformName
#define glGetActiveUniformsiv System::GlGetActiveUniformsiv
#define glGetUniformBlockIndex System::GlGetUniformBlockIndex
#define glGetUniformIndices System::GlGetUniformIndices
#define glUniformBlockBinding System::GlUniformBlockBinding

// (ARB 59) GL_ARB_copy_buffer

#define GL_COPY_READ_BUFFER 0x8F36
#define GL_COPY_WRITE_BUFFER 0x8F37

#define glCopyBufferSubData System::GlCopyBufferSubData

// (ARB 61) GL_ARB_depth_clamp 

#define GL_DEPTH_CLAMP 0x864F

// (ARB 62) GL_ARB_draw_elements_base_vertex 

#define glDrawElementsBaseVertex System::GlDrawElementsBaseVertex
#define glDrawElementsInstancedBaseVertex System::GlDrawElementsInstancedBaseVertex
#define glDrawRangeElementsBaseVertex System::GlDrawRangeElementsBaseVertex
#define glMultiDrawElementsBaseVertex System::GlMultiDrawElementsBaseVertex

// (ARB 64) GL_ARB_provoking_vertex

#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION 0x8E4C
#define GL_FIRST_VERTEX_CONVENTION 0x8E4D
#define GL_LAST_VERTEX_CONVENTION 0x8E4E
#define GL_PROVOKING_VERTEX 0x8E4F

#define glProvokingVertex System::GlProvokingVertex

// (ARB 65) GL_ARB_seamless_cube_map 

#define GL_TEXTURE_CUBE_MAP_SEAMLESS 0x884F

// (ARB 66) GL_ARB_sync 

#define GL_SYNC_FLUSH_COMMANDS_BIT 0x00000001
#define GL_MAX_SERVER_WAIT_TIMEOUT 0x9111
#define GL_OBJECT_TYPE 0x9112
#define GL_SYNC_CONDITION 0x9113
#define GL_SYNC_STATUS 0x9114
#define GL_SYNC_FLAGS 0x9115
#define GL_SYNC_FENCE 0x9116
#define GL_SYNC_GPU_COMMANDS_COMPLETE 0x9117
#define GL_UNSIGNALED 0x9118
#define GL_SIGNALED 0x9119
#define GL_ALREADY_SIGNALED 0x911A
#define GL_TIMEOUT_EXPIRED 0x911B
#define GL_CONDITION_SATISFIED 0x911C
#define GL_WAIT_FAILED 0x911D
#define GL_TIMEOUT_IGNORED 0xFFFFFFFFFFFFFFFF

#define glClientWaitSync System::GlClientWaitSync
#define glDeleteSync System::GlDeleteSync
#define glFenceSync System::GlFenceSync
#define glGetInteger64v System::GlGetInteger64v
#define glGetSynciv System::GlGetSynciv
#define glIsSync System::GlIsSync
#define glWaitSync System::GlWaitSync

// (ARB 67) GL_ARB_texture_multisample

#define GL_SAMPLE_POSITION 0x8E50
#define GL_SAMPLE_MASK 0x8E51
#define GL_SAMPLE_MASK_VALUE 0x8E52
#define GL_MAX_SAMPLE_MASK_WORDS 0x8E59
#define GL_TEXTURE_2D_MULTISAMPLE 0x9100
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE 0x9101
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9102
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9103
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE 0x9104
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY 0x9105
#define GL_TEXTURE_SAMPLES 0x9106
#define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS 0x9107
#define GL_SAMPLER_2D_MULTISAMPLE 0x9108
#define GL_INT_SAMPLER_2D_MULTISAMPLE 0x9109
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE 0x910A
#define GL_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910B
#define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910C
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910D
#define GL_MAX_COLOR_TEXTURE_SAMPLES 0x910E
#define GL_MAX_DEPTH_TEXTURE_SAMPLES 0x910F
#define GL_MAX_INTEGER_SAMPLES 0x9110

#define glGetMultisamplefv System::GlGetMultisamplefv
#define glSampleMaski System::GlSampleMaski
#define glTexImage2DMultisample System::GlTexImage2DMultisample
#define glTexImage3DMultisample System::GlTexImage3DMultisample

// (ARB 68) GL_ARB_vertex_array_bgra 

#define GL_BGRA 0x80E1

// (ARB 69) GL_ARB_draw_buffers_blend 

#define glBlendEquationSeparateiARB System::GlBlendEquationSeparateiARB
#define glBlendEquationiARB System::GlBlendEquationiARB
#define glBlendFuncSeparateiARB System::GlBlendFuncSeparateiARB
#define glBlendFunciARB System::GlBlendFunciARB

// (ARB 70) GL_ARB_sample_shading

#define GL_SAMPLE_SHADING_ARB 0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE_ARB 0x8C37

#define glMinSampleShadingARB System::GlMinSampleShadingARB

// (ARB 71) GL_ARB_texture_cube_map_array 

#define GL_TEXTURE_CUBE_MAP_ARRAY_ARB 0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB 0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB 0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900F

// (ARB 72) GL_ARB_texture_gather 

#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5F
#define GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS_ARB 0x8F9F

// (ARB 76) GL_ARB_shading_language_include 

#define GL_SHADER_INCLUDE_ARB 0x8DAE
#define GL_NAMED_STRING_LENGTH_ARB 0x8DE9
#define GL_NAMED_STRING_TYPE_ARB 0x8DEA

#define glCompileShaderIncludeARB System::GlCompileShaderIncludeARB
#define glDeleteNamedStringARB System::GlDeleteNamedStringARB
#define glGetNamedStringARB System::GlGetNamedStringARB
#define glGetNamedStringivARB System::GlGetNamedStringivARB
#define glIsNamedStringARB System::GlIsNamedStringARB
#define glNamedStringARB System::GlNamedStringARB

// (ARB 77) GL_ARB_texture_compression_bptc

#define GL_COMPRESSED_RGBA_BPTC_UNORM_ARB 0x8E8C
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB 0x8E8D
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB 0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB 0x8E8F

// (ARB 78) GL_ARB_blend_func_extended

#define GL_SRC1_COLOR 0x88F9
#define GL_ONE_MINUS_SRC1_COLOR 0x88FA
#define GL_ONE_MINUS_SRC1_ALPHA 0x88FB
#define GL_MAX_DUAL_SOURCE_DRAW_BUFFERS 0x88FC

#define glBindFragDataLocationIndexed System::GlBindFragDataLocationIndexed
#define glGetFragDataIndex System::GlGetFragDataIndex

// (ARB 80) GL_ARB_occlusion_query2 

#define GL_ANY_SAMPLES_PASSED 0x8C2F

// (ARB 81) GL_ARB_sampler_objects 

#define GL_SAMPLER_BINDING 0x8919

#define glBindSampler System::GlBindSampler
#define glDeleteSamplers System::GlDeleteSamplers
#define glGenSamplers System::GlGenSamplers
#define glGetSamplerParameterIiv System::GlGetSamplerParameterIiv
#define glGetSamplerParameterIuiv System::GlGetSamplerParameterIuiv
#define glGetSamplerParameterfv System::GlGetSamplerParameterfv
#define glGetSamplerParameteriv System::GlGetSamplerParameteriv
#define glIsSampler System::GlIsSampler
#define glSamplerParameterIiv System::GlSamplerParameterIiv
#define glSamplerParameterIuiv System::GlSamplerParameterIuiv
#define glSamplerParameterf System::GlSamplerParameterf
#define glSamplerParameterfv System::GlSamplerParameterfv
#define glSamplerParameteri System::GlSamplerParameteri
#define glSamplerParameteriv System::GlSamplerParameteriv

// (ARB 83) GL_ARB_texture_rgb10_a2ui 

#define GL_RGB10_A2UI 0x906F

// (ARB 84) GL_ARB_texture_swizzle 

#define GL_TEXTURE_SWIZZLE_R 0x8E42
#define GL_TEXTURE_SWIZZLE_G 0x8E43
#define GL_TEXTURE_SWIZZLE_B 0x8E44
#define GL_TEXTURE_SWIZZLE_A 0x8E45
#define GL_TEXTURE_SWIZZLE_RGBA 0x8E46

// (ARB 85) GL_ARB_timer_query 

#define GL_TIME_ELAPSED 0x88BF
#define GL_TIMESTAMP 0x8E28

#define glGetQueryObjecti64v System::GlGetQueryObjecti64v
#define glGetQueryObjectui64v System::GlGetQueryObjectui64v
#define glQueryCounter System::GlQueryCounter

// (ARB 86) GL_ARB_vertex_type_2_10_10_10_rev 

#define GL_UNSIGNED_INT_2_10_10_10_REV 0x8368
#define GL_INT_2_10_10_10_REV 0x8D9F

#define glColorP3ui System::GlColorP3ui
#define glColorP3uiv System::GlColorP3uiv
#define glColorP4ui System::GlColorP4ui
#define glColorP4uiv System::GlColorP4uiv
#define glMultiTexCoordP1ui System::GlMultiTexCoordP1ui
#define glMultiTexCoordP1uiv System::GlMultiTexCoordP1uiv
#define glMultiTexCoordP2ui System::GlMultiTexCoordP2ui
#define glMultiTexCoordP2uiv System::GlMultiTexCoordP2uiv
#define glMultiTexCoordP3ui System::GlMultiTexCoordP3ui
#define glMultiTexCoordP3uiv System::GlMultiTexCoordP3uiv
#define glMultiTexCoordP4ui System::GlMultiTexCoordP4ui
#define glMultiTexCoordP4uiv System::GlMultiTexCoordP4uiv
#define glNormalP3ui System::GlNormalP3ui
#define glNormalP3uiv System::GlNormalP3uiv
#define glSecondaryColorP3ui System::GlSecondaryColorP3ui
#define glSecondaryColorP3uiv System::GlSecondaryColorP3uiv
#define glTexCoordP1ui System::GlTexCoordP1ui
#define glTexCoordP1uiv System::GlTexCoordP1uiv
#define glTexCoordP2ui System::GlTexCoordP2ui
#define glTexCoordP2uiv System::GlTexCoordP2uiv
#define glTexCoordP3ui System::GlTexCoordP3ui
#define glTexCoordP3uiv System::GlTexCoordP3uiv
#define glTexCoordP4ui System::GlTexCoordP4ui
#define glTexCoordP4uiv System::GlTexCoordP4uiv
#define glVertexAttribP1ui System::GlVertexAttribP1ui
#define glVertexAttribP1uiv System::GlVertexAttribP1uiv
#define glVertexAttribP2ui System::GlVertexAttribP2ui
#define glVertexAttribP2uiv System::GlVertexAttribP2uiv
#define glVertexAttribP3ui System::GlVertexAttribP3ui
#define glVertexAttribP3uiv System::GlVertexAttribP3uiv
#define glVertexAttribP4ui System::GlVertexAttribP4ui
#define glVertexAttribP4uiv System::GlVertexAttribP4uiv
#define glVertexP2ui System::GlVertexP2ui
#define glVertexP2uiv System::GlVertexP2uiv
#define glVertexP3ui System::GlVertexP3ui
#define glVertexP3uiv System::GlVertexP3uiv
#define glVertexP4ui System::GlVertexP4ui
#define glVertexP4uiv System::GlVertexP4uiv

// (ARB 87) GL_ARB_draw_indirect 

#define GL_DRAW_INDIRECT_BUFFER 0x8F3F
#define GL_DRAW_INDIRECT_BUFFER_BINDING 0x8F43

#define glDrawArraysIndirect System::GlDrawArraysIndirect
#define glDrawElementsIndirect System::GlDrawElementsIndirect

// (ARB 88) GL_ARB_gpu_shader5 

#define GL_GEOMETRY_SHADER_INVOCATIONS 0x887F
#define GL_MAX_GEOMETRY_SHADER_INVOCATIONS 0x8E5A
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET 0x8E5B
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET 0x8E5C
#define GL_FRAGMENT_INTERPOLATION_OFFSET_BITS 0x8E5D
#define GL_MAX_VERTEX_STREAMS 0x8E71

// (ARB 89) GL_ARB_gpu_shader_fp64

#define GL_DOUBLE_MAT2 0x8F46
#define GL_DOUBLE_MAT3 0x8F47
#define GL_DOUBLE_MAT4 0x8F48
#define GL_DOUBLE_MAT2x3 0x8F49
#define GL_DOUBLE_MAT2x4 0x8F4A
#define GL_DOUBLE_MAT3x2 0x8F4B
#define GL_DOUBLE_MAT3x4 0x8F4C
#define GL_DOUBLE_MAT4x2 0x8F4D
#define GL_DOUBLE_MAT4x3 0x8F4E
#define GL_DOUBLE_VEC2 0x8FFC
#define GL_DOUBLE_VEC3 0x8FFD
#define GL_DOUBLE_VEC4 0x8FFE

#define glGetUniformdv System::GlGetUniformdv
#define glUniform1d System::GlUniform1d
#define glUniform1dv System::GlUniform1dv
#define glUniform2d System::GlUniform2d
#define glUniform2dv System::GlUniform2dv
#define glUniform3d System::GlUniform3d
#define glUniform3dv System::GlUniform3dv
#define glUniform4d System::GlUniform4d
#define glUniform4dv System::GlUniform4dv
#define glUniformMatrix2dv System::GlUniformMatrix2dv
#define glUniformMatrix2x3dv System::GlUniformMatrix2x3dv
#define glUniformMatrix2x4dv System::GlUniformMatrix2x4dv
#define glUniformMatrix3dv System::GlUniformMatrix3dv
#define glUniformMatrix3x2dv System::GlUniformMatrix3x2dv
#define glUniformMatrix3x4dv System::GlUniformMatrix3x4dv
#define glUniformMatrix4dv System::GlUniformMatrix4dv
#define glUniformMatrix4x2dv System::GlUniformMatrix4x2dv
#define glUniformMatrix4x3dv System::GlUniformMatrix4x3dv

// (ARB 90) GL_ARB_shader_subroutine 

#define GL_ACTIVE_SUBROUTINES 0x8DE5
#define GL_ACTIVE_SUBROUTINE_UNIFORMS 0x8DE6
#define GL_MAX_SUBROUTINES 0x8DE7
#define GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS 0x8DE8
#define GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS 0x8E47
#define GL_ACTIVE_SUBROUTINE_MAX_LENGTH 0x8E48
#define GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH 0x8E49
#define GL_NUM_COMPATIBLE_SUBROUTINES 0x8E4A
#define GL_COMPATIBLE_SUBROUTINES 0x8E4B

#define glGetActiveSubroutineName System::GlGetActiveSubroutineName
#define glGetActiveSubroutineUniformName System::GlGetActiveSubroutineUniformName
#define glGetActiveSubroutineUniformiv System::GlGetActiveSubroutineUniformiv
#define glGetProgramStageiv System::GlGetProgramStageiv
#define glGetSubroutineIndex System::GlGetSubroutineIndex
#define glGetSubroutineUniformLocation System::GlGetSubroutineUniformLocation
#define glGetUniformSubroutineuiv System::GlGetUniformSubroutineuiv
#define glUniformSubroutinesuiv System::GlUniformSubroutinesuiv

// (ARB 91) GL_ARB_tessellation_shader

#define GL_PATCHES 0xE
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER 0x84F0
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER 0x84F1
#define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS 0x886C
#define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS 0x886D
#define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E1E
#define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E1F
#define GL_PATCH_VERTICES 0x8E72
#define GL_PATCH_DEFAULT_INNER_LEVEL 0x8E73
#define GL_PATCH_DEFAULT_OUTER_LEVEL 0x8E74
#define GL_TESS_CONTROL_OUTPUT_VERTICES 0x8E75
#define GL_TESS_GEN_MODE 0x8E76
#define GL_TESS_GEN_SPACING 0x8E77
#define GL_TESS_GEN_VERTEX_ORDER 0x8E78
#define GL_TESS_GEN_POINT_MODE 0x8E79
#define GL_ISOLINES 0x8E7A
#define GL_FRACTIONAL_ODD 0x8E7B
#define GL_FRACTIONAL_EVEN 0x8E7C
#define GL_MAX_PATCH_VERTICES 0x8E7D
#define GL_MAX_TESS_GEN_LEVEL 0x8E7E
#define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E7F
#define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E80
#define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS 0x8E81
#define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS 0x8E82
#define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS 0x8E83
#define GL_MAX_TESS_PATCH_COMPONENTS 0x8E84
#define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS 0x8E85
#define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS 0x8E86
#define GL_TESS_EVALUATION_SHADER 0x8E87
#define GL_TESS_CONTROL_SHADER 0x8E88
#define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS 0x8E89
#define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS 0x8E8A

#define glPatchParameterfv System::GlPatchParameterfv
#define glPatchParameteri System::GlPatchParameteri

// (ARB 93) GL_ARB_transform_feedback2

#define GL_TRANSFORM_FEEDBACK 0x8E22
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED 0x8E23
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE 0x8E24
#define GL_TRANSFORM_FEEDBACK_BINDING 0x8E25

#define glBindTransformFeedback System::GlBindTransformFeedback
#define glDeleteTransformFeedbacks System::GlDeleteTransformFeedbacks
#define glDrawTransformFeedback System::GlDrawTransformFeedback
#define glGenTransformFeedbacks System::GlGenTransformFeedbacks
#define glIsTransformFeedback System::GlIsTransformFeedback
#define glPauseTransformFeedback System::GlPauseTransformFeedback
#define glResumeTransformFeedback System::GlResumeTransformFeedback

// (ARB 94) GL_ARB_transform_feedback3

#define GL_MAX_TRANSFORM_FEEDBACK_BUFFERS 0x8E70
#define GL_MAX_VERTEX_STREAMS 0x8E71

#define glBeginQueryIndexed System::GlBeginQueryIndexed
#define glDrawTransformFeedbackStream System::GlDrawTransformFeedbackStream
#define glEndQueryIndexed System::GlEndQueryIndexed
#define glGetQueryIndexediv System::GlGetQueryIndexediv

// (ARB 96) GL_ARB_get_program_binary

#define GL_PROGRAM_BINARY_RETRIEVABLE_HINT 0x8257
#define GL_PROGRAM_BINARY_LENGTH 0x8741
#define GL_NUM_PROGRAM_BINARY_FORMATS 0x87FE
#define GL_PROGRAM_BINARY_FORMATS 0x87FF

#define glGetProgramBinary System::GlGetProgramBinary
#define glProgramBinary System::GlProgramBinary

// (ARB 97) GL_ARB_separate_shader_objects

#define GL_VERTEX_SHADER_BIT 0x00000001
#define GL_FRAGMENT_SHADER_BIT 0x00000002
#define GL_GEOMETRY_SHADER_BIT 0x00000004
#define GL_TESS_CONTROL_SHADER_BIT 0x00000008
#define GL_TESS_EVALUATION_SHADER_BIT 0x00000010
#define GL_PROGRAM_SEPARABLE 0x8258
#define GL_ACTIVE_PROGRAM 0x8259
#define GL_PROGRAM_PIPELINE_BINDING 0x825A
#define GL_ALL_SHADER_BITS 0xFFFFFFFF

#define glActiveShaderProgram System::GlActiveShaderProgram
#define glBindProgramPipeline System::GlBindProgramPipeline
#define glCreateShaderProgramv System::GlCreateShaderProgramv
#define glDeleteProgramPipelines System::GlDeleteProgramPipelines
#define glGenProgramPipelines System::GlGenProgramPipelines
#define glGetProgramPipelineInfoLog System::GlGetProgramPipelineInfoLog
#define glGetProgramPipelineiv System::GlGetProgramPipelineiv
#define glIsProgramPipeline System::GlIsProgramPipeline
#define glProgramUniform1d System::GlProgramUniform1d
#define glProgramUniform1dv System::GlProgramUniform1dv
#define glProgramUniform1f System::GlProgramUniform1f
#define glProgramUniform1fv System::GlProgramUniform1fv
#define glProgramUniform1i System::GlProgramUniform1i
#define glProgramUniform1iv System::GlProgramUniform1iv
#define glProgramUniform1ui System::GlProgramUniform1ui
#define glProgramUniform1uiv System::GlProgramUniform1uiv
#define glProgramUniform2d System::GlProgramUniform2d
#define glProgramUniform2dv System::GlProgramUniform2dv
#define glProgramUniform2f System::GlProgramUniform2f
#define glProgramUniform2fv System::GlProgramUniform2fv
#define glProgramUniform2i System::GlProgramUniform2i
#define glProgramUniform2iv System::GlProgramUniform2iv
#define glProgramUniform2ui System::GlProgramUniform2ui
#define glProgramUniform2uiv System::GlProgramUniform2uiv
#define glProgramUniform3d System::GlProgramUniform3d
#define glProgramUniform3dv System::GlProgramUniform3dv
#define glProgramUniform3f System::GlProgramUniform3f
#define glProgramUniform3fv System::GlProgramUniform3fv
#define glProgramUniform3i System::GlProgramUniform3i
#define glProgramUniform3iv System::GlProgramUniform3iv
#define glProgramUniform3ui System::GlProgramUniform3ui
#define glProgramUniform3uiv System::GlProgramUniform3uiv
#define glProgramUniform4d System::GlProgramUniform4d
#define glProgramUniform4dv System::GlProgramUniform4dv
#define glProgramUniform4f System::GlProgramUniform4f
#define glProgramUniform4fv System::GlProgramUniform4fv
#define glProgramUniform4i System::GlProgramUniform4i
#define glProgramUniform4iv System::GlProgramUniform4iv
#define glProgramUniform4ui System::GlProgramUniform4ui
#define glProgramUniform4uiv System::GlProgramUniform4uiv
#define glProgramUniformMatrix2dv System::GlProgramUniformMatrix2dv
#define glProgramUniformMatrix2fv System::GlProgramUniformMatrix2fv
#define glProgramUniformMatrix2x3dv System::GlProgramUniformMatrix2x3dv
#define glProgramUniformMatrix2x3fv System::GlProgramUniformMatrix2x3fv
#define glProgramUniformMatrix2x4dv System::GlProgramUniformMatrix2x4dv
#define glProgramUniformMatrix2x4fv System::GlProgramUniformMatrix2x4fv
#define glProgramUniformMatrix3dv System::GlProgramUniformMatrix3dv
#define glProgramUniformMatrix3fv System::GlProgramUniformMatrix3fv
#define glProgramUniformMatrix3x2dv System::GlProgramUniformMatrix3x2dv
#define glProgramUniformMatrix3x2fv System::GlProgramUniformMatrix3x2fv
#define glProgramUniformMatrix3x4dv System::GlProgramUniformMatrix3x4dv
#define glProgramUniformMatrix3x4fv System::GlProgramUniformMatrix3x4fv
#define glProgramUniformMatrix4dv System::GlProgramUniformMatrix4dv
#define glProgramUniformMatrix4fv System::GlProgramUniformMatrix4fv
#define glProgramUniformMatrix4x2dv System::GlProgramUniformMatrix4x2dv
#define glProgramUniformMatrix4x2fv System::GlProgramUniformMatrix4x2fv
#define glProgramUniformMatrix4x3dv System::GlProgramUniformMatrix4x3dv
#define glProgramUniformMatrix4x3fv System::GlProgramUniformMatrix4x3fv
#define glUseProgramStages System::GlUseProgramStages
#define glValidateProgramPipeline System::GlValidateProgramPipeline

// (ARB 99) GL_ARB_vertex_attrib_64bit

#define glGetVertexAttribLdv System::GlGetVertexAttribLdv
#define glVertexAttribL1d System::GlVertexAttribL1d
#define glVertexAttribL1dv System::GlVertexAttribL1dv
#define glVertexAttribL2d System::GlVertexAttribL2d
#define glVertexAttribL2dv System::GlVertexAttribL2dv
#define glVertexAttribL3d System::GlVertexAttribL3d
#define glVertexAttribL3dv System::GlVertexAttribL3dv
#define glVertexAttribL4d System::GlVertexAttribL4d
#define glVertexAttribL4dv System::GlVertexAttribL4dv
#define glVertexAttribLPointer System::GlVertexAttribLPointer

// (ARB 100) GL_ARB_viewport_array

#define GL_DEPTH_RANGE 0x0B70
#define GL_VIEWPORT 0x0BA2
#define GL_SCISSOR_BOX 0x0C10
#define GL_SCISSOR_TEST 0x0C11
#define GL_MAX_VIEWPORTS 0x825B
#define GL_VIEWPORT_SUBPIXEL_BITS 0x825C
#define GL_VIEWPORT_BOUNDS_RANGE 0x825D
#define GL_LAYER_PROVOKING_VERTEX 0x825E
#define GL_VIEWPORT_INDEX_PROVOKING_VERTEX 0x825F
#define GL_UNDEFINED_VERTEX 0x8260
#define GL_FIRST_VERTEX_CONVENTION 0x8E4D
#define GL_LAST_VERTEX_CONVENTION 0x8E4E
#define GL_PROVOKING_VERTEX 0x8E4F

#define glDepthRangeArrayv System::GlDepthRangeArrayv
#define glDepthRangeIndexed System::GlDepthRangeIndexed
#define glGetDoublei_v System::GlGetDoublei_v
#define glGetFloati_v System::GlGetFloati_v
#define glScissorArrayv System::GlScissorArrayv
#define glScissorIndexed System::GlScissorIndexed
#define glScissorIndexedv System::GlScissorIndexedv
#define glViewportArrayv System::GlViewportArrayv
#define glViewportIndexedf System::GlViewportIndexedf
#define glViewportIndexedfv System::GlViewportIndexedfv

// (ARB 103) GL_ARB_cl_event

#define GL_SYNC_CL_EVENT_ARB 0x8240
#define GL_SYNC_CL_EVENT_COMPLETE_ARB 0x8241

#define glCreateSyncFromCLeventARB System::GlCreateSyncFromCLeventARB

// (ARB 104) GL_ARB_debug_output

#define GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB 0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_ARB 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION_ARB 0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM_ARB 0x8245
#define GL_DEBUG_SOURCE_API_ARB 0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB 0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER_ARB 0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY_ARB 0x8249
#define GL_DEBUG_SOURCE_APPLICATION_ARB 0x824A
#define GL_DEBUG_SOURCE_OTHER_ARB 0x824B
#define GL_DEBUG_TYPE_ERROR_ARB 0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB 0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB 0x824E
#define GL_DEBUG_TYPE_PORTABILITY_ARB 0x824F
#define GL_DEBUG_TYPE_PERFORMANCE_ARB 0x8250
#define GL_DEBUG_TYPE_OTHER_ARB 0x8251
#define GL_MAX_DEBUG_MESSAGE_LENGTH_ARB 0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES_ARB 0x9144
#define GL_DEBUG_LOGGED_MESSAGES_ARB 0x9145
#define GL_DEBUG_SEVERITY_HIGH_ARB 0x9146
#define GL_DEBUG_SEVERITY_MEDIUM_ARB 0x9147
#define GL_DEBUG_SEVERITY_LOW_ARB 0x9148

#define glDebugMessageCallbackARB System::GlDebugMessageCallbackARB
#define glDebugMessageControlARB System::GlDebugMessageControlARB
#define glDebugMessageInsertARB System::GlDebugMessageInsertARB
#define glGetDebugMessageLogARB System::GlGetDebugMessageLogARB

// (ARB 105) GL_ARB_robustness

#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB 0x00000004
#define GL_LOSE_CONTEXT_ON_RESET_ARB 0x8252
#define GL_GUILTY_CONTEXT_RESET_ARB 0x8253
#define GL_INNOCENT_CONTEXT_RESET_ARB 0x8254
#define GL_UNKNOWN_CONTEXT_RESET_ARB 0x8255
#define GL_RESET_NOTIFICATION_STRATEGY_ARB 0x8256
#define GL_NO_RESET_NOTIFICATION_ARB 0x8261

#define glGetGraphicsResetStatusARB System::GlGetGraphicsResetStatusARB
#define glGetnColorTableARB System::GlGetnColorTableARB
#define glGetnCompressedTexImageARB System::GlGetnCompressedTexImageARB
#define glGetnConvolutionFilterARB System::GlGetnConvolutionFilterARB
#define glGetnHistogramARB System::GlGetnHistogramARB
#define glGetnMapdvARB System::GlGetnMapdvARB
#define glGetnMapfvARB System::GlGetnMapfvARB
#define glGetnMapivARB System::GlGetnMapivARB
#define glGetnMinmaxARB System::GlGetnMinmaxARB
#define glGetnPixelMapfvARB System::GlGetnPixelMapfvARB
#define glGetnPixelMapuivARB System::GlGetnPixelMapuivARB
#define glGetnPixelMapusvARB System::GlGetnPixelMapusvARB
#define glGetnPolygonStippleARB System::GlGetnPolygonStippleARB
#define glGetnSeparableFilterARB System::GlGetnSeparableFilterARB
#define glGetnTexImageARB System::GlGetnTexImageARB
#define glGetnUniformdvARB System::GlGetnUniformdvARB
#define glGetnUniformfvARB System::GlGetnUniformfvARB
#define glGetnUniformivARB System::GlGetnUniformivARB
#define glGetnUniformuivARB System::GlGetnUniformuivARB
#define glReadnPixelsARB System::GlReadnPixelsARB

// (ARB 107) GL_ARB_base_instance

#define glDrawArraysInstancedBaseInstance System::GlDrawArraysInstancedBaseInstance
#define glDrawElementsInstancedBaseInstance System::GlDrawElementsInstancedBaseInstance
#define glDrawElementsInstancedBaseVertexBaseInstance System::GlDrawElementsInstancedBaseVertexBaseInstance

// (ARB 109) GL_ARB_transform_feedback_instanced 

#define glDrawTransformFeedbackInstanced System::GlDrawTransformFeedbackInstanced
#define glDrawTransformFeedbackStreamInstanced System::GlDrawTransformFeedbackStreamInstanced

// (ARB 110) GL_ARB_compressed_texture_pixel_storage

#define GL_UNPACK_COMPRESSED_BLOCK_WIDTH 0x9127
#define GL_UNPACK_COMPRESSED_BLOCK_HEIGHT 0x9128
#define GL_UNPACK_COMPRESSED_BLOCK_DEPTH 0x9129
#define GL_UNPACK_COMPRESSED_BLOCK_SIZE 0x912A
#define GL_PACK_COMPRESSED_BLOCK_WIDTH 0x912B
#define GL_PACK_COMPRESSED_BLOCK_HEIGHT 0x912C
#define GL_PACK_COMPRESSED_BLOCK_DEPTH 0x912D
#define GL_PACK_COMPRESSED_BLOCK_SIZE 0x912E

// (ARB 112) GL_ARB_internalformat_query

#define GL_NUM_SAMPLE_COUNTS 0x9380

#define glGetInternalformativ System::GlGetInternalformativ

// (ARB 113) GL_ARB_map_buffer_alignment

#define GL_MIN_MAP_BUFFER_ALIGNMENT 0x90BC

// (ARB 114) GL_ARB_shader_atomic_counters

#define GL_ATOMIC_COUNTER_BUFFER 0x92C0
#define GL_ATOMIC_COUNTER_BUFFER_BINDING 0x92C1
#define GL_ATOMIC_COUNTER_BUFFER_START 0x92C2
#define GL_ATOMIC_COUNTER_BUFFER_SIZE 0x92C3
#define GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE 0x92C4
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS 0x92C5
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES 0x92C6
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER 0x92C7
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER 0x92C8
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER 0x92C9
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER 0x92CA
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER 0x92CB
#define GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS 0x92CC
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS 0x92CD
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS 0x92CE
#define GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS 0x92CF
#define GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS 0x92D0
#define GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS 0x92D1
#define GL_MAX_VERTEX_ATOMIC_COUNTERS 0x92D2
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS 0x92D3
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS 0x92D4
#define GL_MAX_GEOMETRY_ATOMIC_COUNTERS 0x92D5
#define GL_MAX_FRAGMENT_ATOMIC_COUNTERS 0x92D6
#define GL_MAX_COMBINED_ATOMIC_COUNTERS 0x92D7
#define GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE 0x92D8
#define GL_ACTIVE_ATOMIC_COUNTER_BUFFERS 0x92D9
#define GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX 0x92DA
#define GL_UNSIGNED_INT_ATOMIC_COUNTER 0x92DB
#define GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS 0x92DC

#define glGetActiveAtomicCounterBufferiv System::GlGetActiveAtomicCounterBufferiv

// (ARB 115) GL_ARB_shader_image_load_store

#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT 0x00000001
#define GL_ELEMENT_ARRAY_BARRIER_BIT 0x00000002
#define GL_UNIFORM_BARRIER_BIT 0x00000004
#define GL_TEXTURE_FETCH_BARRIER_BIT 0x00000008
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT 0x00000020
#define GL_COMMAND_BARRIER_BIT 0x00000040
#define GL_PIXEL_BUFFER_BARRIER_BIT 0x00000080
#define GL_TEXTURE_UPDATE_BARRIER_BIT 0x00000100
#define GL_BUFFER_UPDATE_BARRIER_BIT 0x00000200
#define GL_FRAMEBUFFER_BARRIER_BIT 0x00000400
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT 0x00000800
#define GL_ATOMIC_COUNTER_BARRIER_BIT 0x00001000
#define GL_MAX_IMAGE_UNITS 0x8F38
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS 0x8F39
#define GL_IMAGE_BINDING_NAME 0x8F3A
#define GL_IMAGE_BINDING_LEVEL 0x8F3B
#define GL_IMAGE_BINDING_LAYERED 0x8F3C
#define GL_IMAGE_BINDING_LAYER 0x8F3D
#define GL_IMAGE_BINDING_ACCESS 0x8F3E
#define GL_IMAGE_1D 0x904C
#define GL_IMAGE_2D 0x904D
#define GL_IMAGE_3D 0x904E
#define GL_IMAGE_2D_RECT 0x904F
#define GL_IMAGE_CUBE 0x9050
#define GL_IMAGE_BUFFER 0x9051
#define GL_IMAGE_1D_ARRAY 0x9052
#define GL_IMAGE_2D_ARRAY 0x9053
#define GL_IMAGE_CUBE_MAP_ARRAY 0x9054
#define GL_IMAGE_2D_MULTISAMPLE 0x9055
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY 0x9056
#define GL_INT_IMAGE_1D 0x9057
#define GL_INT_IMAGE_2D 0x9058
#define GL_INT_IMAGE_3D 0x9059
#define GL_INT_IMAGE_2D_RECT 0x905A
#define GL_INT_IMAGE_CUBE 0x905B
#define GL_INT_IMAGE_BUFFER 0x905C
#define GL_INT_IMAGE_1D_ARRAY 0x905D
#define GL_INT_IMAGE_2D_ARRAY 0x905E
#define GL_INT_IMAGE_CUBE_MAP_ARRAY 0x905F
#define GL_INT_IMAGE_2D_MULTISAMPLE 0x9060
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x9061
#define GL_UNSIGNED_INT_IMAGE_1D 0x9062
#define GL_UNSIGNED_INT_IMAGE_2D 0x9063
#define GL_UNSIGNED_INT_IMAGE_3D 0x9064
#define GL_UNSIGNED_INT_IMAGE_2D_RECT 0x9065
#define GL_UNSIGNED_INT_IMAGE_CUBE 0x9066
#define GL_UNSIGNED_INT_IMAGE_BUFFER 0x9067
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY 0x9068
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY 0x9069
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY 0x906A
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE 0x906B
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x906C
#define GL_MAX_IMAGE_SAMPLES 0x906D
#define GL_IMAGE_BINDING_FORMAT 0x906E
#define GL_IMAGE_FORMAT_COMPATIBILITY_TYPE 0x90C7
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE 0x90C8
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS 0x90C9
#define GL_MAX_VERTEX_IMAGE_UNIFORMS 0x90CA
#define GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS 0x90CB
#define GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS 0x90CC
#define GL_MAX_GEOMETRY_IMAGE_UNIFORMS 0x90CD
#define GL_MAX_FRAGMENT_IMAGE_UNIFORMS 0x90CE
#define GL_MAX_COMBINED_IMAGE_UNIFORMS 0x90CF
#define GL_ALL_BARRIER_BITS 0xFFFFFFFF

#define glBindImageTexture System::GlBindImageTexture
#define glMemoryBarrier System::GlMemoryBarrier

// (ARB 117) GL_ARB_texture_storage

#define GL_TEXTURE_IMMUTABLE_FORMAT 0x912F

#define glTexStorage1D System::GlTexStorage1D
#define glTexStorage2D System::GlTexStorage2D
#define glTexStorage3D System::GlTexStorage3D
#define glTextureStorage1DEXT System::GlTextureStorage1DEXT
#define glTextureStorage2DEXT System::GlTextureStorage2DEXT
#define glTextureStorage3DEXT System::GlTextureStorage3DEXT

// (ARB 121) GL_ARB_clear_buffer_object

#define glClearBufferData System::GlClearBufferData
#define glClearBufferSubData System::GlClearBufferSubData
#define glClearNamedBufferDataEXT System::GlClearNamedBufferDataEXT
#define glClearNamedBufferSubDataEXT System::GlClearNamedBufferSubDataEXT

// (ARB 122) GL_ARB_compute_shader

#define GL_COMPUTE_SHADER_BIT 0x00000020
#define GL_MAX_COMPUTE_SHARED_MEMORY_SIZE 0x8262
#define GL_MAX_COMPUTE_UNIFORM_COMPONENTS 0x8263
#define GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS 0x8264
#define GL_MAX_COMPUTE_ATOMIC_COUNTERS 0x8265
#define GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS 0x8266
#define GL_COMPUTE_WORK_GROUP_SIZE 0x8267
#define GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS 0x90EB
#define GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER 0x90EC
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER 0x90ED
#define GL_DISPATCH_INDIRECT_BUFFER 0x90EE
#define GL_DISPATCH_INDIRECT_BUFFER_BINDING 0x90EF
#define GL_COMPUTE_SHADER 0x91B9
#define GL_MAX_COMPUTE_UNIFORM_BLOCKS 0x91BB
#define GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS 0x91BC
#define GL_MAX_COMPUTE_IMAGE_UNIFORMS 0x91BD
#define GL_MAX_COMPUTE_WORK_GROUP_COUNT 0x91BE
#define GL_MAX_COMPUTE_WORK_GROUP_SIZE 0x91BF

#define glDispatchCompute System::GlDispatchCompute
#define glDispatchComputeIndirect System::GlDispatchComputeIndirect

// (ARB 123) GL_ARB_copy_image

#define glCopyImageSubData System::GlCopyImageSubData

// (ARB 124) GL_ARB_texture_view

#define GL_TEXTURE_VIEW_MIN_LEVEL 0x82DB
#define GL_TEXTURE_VIEW_NUM_LEVELS 0x82DC
#define GL_TEXTURE_VIEW_MIN_LAYER 0x82DD
#define GL_TEXTURE_VIEW_NUM_LAYERS 0x82DE
#define GL_TEXTURE_IMMUTABLE_LEVELS 0x82DF

#define glTextureView System::GlTextureView

// (ARB 125) GL_ARB_vertex_attrib_binding

#define GL_VERTEX_ATTRIB_BINDING 0x82D4
#define GL_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D5
#define GL_VERTEX_BINDING_DIVISOR 0x82D6
#define GL_VERTEX_BINDING_OFFSET 0x82D7
#define GL_VERTEX_BINDING_STRIDE 0x82D8
#define GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D9
#define GL_MAX_VERTEX_ATTRIB_BINDINGS 0x82DA

#define glBindVertexBuffer System::GlBindVertexBuffer
#define glVertexAttribBinding System::GlVertexAttribBinding
#define glVertexAttribFormat System::GlVertexAttribFormat
#define glVertexAttribIFormat System::GlVertexAttribIFormat
#define glVertexAttribLFormat System::GlVertexAttribLFormat
#define glVertexBindingDivisor System::GlVertexBindingDivisor

// (ARB 128) GL_ARB_explicit_uniform_location

#define GL_MAX_UNIFORM_LOCATIONS 0x826E

// (ARB 130) GL_ARB_framebuffer_no_attachments

#define GL_FRAMEBUFFER_DEFAULT_WIDTH 0x9310
#define GL_FRAMEBUFFER_DEFAULT_HEIGHT 0x9311
#define GL_FRAMEBUFFER_DEFAULT_LAYERS 0x9312
#define GL_FRAMEBUFFER_DEFAULT_SAMPLES 0x9313
#define GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS 0x9314
#define GL_MAX_FRAMEBUFFER_WIDTH 0x9315
#define GL_MAX_FRAMEBUFFER_HEIGHT 0x9316
#define GL_MAX_FRAMEBUFFER_LAYERS 0x9317
#define GL_MAX_FRAMEBUFFER_SAMPLES 0x9318

#define glFramebufferParameteri System::GlFramebufferParameteri
#define glGetFramebufferParameteriv System::GlGetFramebufferParameteriv
#define glGetNamedFramebufferParameterivEXT System::GlGetNamedFramebufferParameterivEXT
#define glNamedFramebufferParameteriEXT System::GlNamedFramebufferParameteriEXT

// (ARB 131) GL_ARB_internalformat_query2

#define GL_INTERNALFORMAT_SUPPORTED 0x826F
#define GL_INTERNALFORMAT_PREFERRED 0x8270
#define GL_INTERNALFORMAT_RED_SIZE 0x8271
#define GL_INTERNALFORMAT_GREEN_SIZE 0x8272
#define GL_INTERNALFORMAT_BLUE_SIZE 0x8273
#define GL_INTERNALFORMAT_ALPHA_SIZE 0x8274
#define GL_INTERNALFORMAT_DEPTH_SIZE 0x8275
#define GL_INTERNALFORMAT_STENCIL_SIZE 0x8276
#define GL_INTERNALFORMAT_SHARED_SIZE 0x8277
#define GL_INTERNALFORMAT_RED_TYPE 0x8278
#define GL_INTERNALFORMAT_GREEN_TYPE 0x8279
#define GL_INTERNALFORMAT_BLUE_TYPE 0x827A
#define GL_INTERNALFORMAT_ALPHA_TYPE 0x827B
#define GL_INTERNALFORMAT_DEPTH_TYPE 0x827C
#define GL_INTERNALFORMAT_STENCIL_TYPE 0x827D
#define GL_MAX_WIDTH 0x827E
#define GL_MAX_HEIGHT 0x827F
#define GL_MAX_DEPTH 0x8280
#define GL_MAX_LAYERS 0x8281
#define GL_MAX_COMBINED_DIMENSIONS 0x8282
#define GL_COLOR_COMPONENTS 0x8283
#define GL_DEPTH_COMPONENTS 0x8284
#define GL_STENCIL_COMPONENTS 0x8285
#define GL_COLOR_RENDERABLE 0x8286
#define GL_DEPTH_RENDERABLE 0x8287
#define GL_STENCIL_RENDERABLE 0x8288
#define GL_FRAMEBUFFER_RENDERABLE 0x8289
#define GL_FRAMEBUFFER_RENDERABLE_LAYERED 0x828A
#define GL_FRAMEBUFFER_BLEND 0x828B
#define GL_READ_PIXELS 0x828C
#define GL_READ_PIXELS_FORMAT 0x828D
#define GL_READ_PIXELS_TYPE 0x828E
#define GL_TEXTURE_IMAGE_FORMAT 0x828F
#define GL_TEXTURE_IMAGE_TYPE 0x8290
#define GL_GET_TEXTURE_IMAGE_FORMAT 0x8291
#define GL_GET_TEXTURE_IMAGE_TYPE 0x8292
#define GL_MIPMAP 0x8293
#define GL_MANUAL_GENERATE_MIPMAP 0x8294
#define GL_AUTO_GENERATE_MIPMAP 0x8295
#define GL_COLOR_ENCODING 0x8296
#define GL_SRGB_READ 0x8297
#define GL_SRGB_WRITE 0x8298
#define GL_SRGB_DECODE_ARB 0x8299
#define GL_FILTER 0x829A
#define GL_VERTEX_TEXTURE 0x829B
#define GL_TESS_CONTROL_TEXTURE 0x829C
#define GL_TESS_EVALUATION_TEXTURE 0x829D
#define GL_GEOMETRY_TEXTURE 0x829E
#define GL_FRAGMENT_TEXTURE 0x829F
#define GL_COMPUTE_TEXTURE 0x82A0
#define GL_TEXTURE_SHADOW 0x82A1
#define GL_TEXTURE_GATHER 0x82A2
#define GL_TEXTURE_GATHER_SHADOW 0x82A3
#define GL_SHADER_IMAGE_LOAD 0x82A4
#define GL_SHADER_IMAGE_STORE 0x82A5
#define GL_SHADER_IMAGE_ATOMIC 0x82A6
#define GL_IMAGE_TEXEL_SIZE 0x82A7
#define GL_IMAGE_COMPATIBILITY_CLASS 0x82A8
#define GL_IMAGE_PIXEL_FORMAT 0x82A9
#define GL_IMAGE_PIXEL_TYPE 0x82AA
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST 0x82AC
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST 0x82AD
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE 0x82AE
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE 0x82AF
#define GL_TEXTURE_COMPRESSED_BLOCK_WIDTH 0x82B1
#define GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT 0x82B2
#define GL_TEXTURE_COMPRESSED_BLOCK_SIZE 0x82B3
#define GL_CLEAR_BUFFER 0x82B4
#define GL_TEXTURE_VIEW 0x82B5
#define GL_VIEW_COMPATIBILITY_CLASS 0x82B6
#define GL_FULL_SUPPORT 0x82B7
#define GL_CAVEAT_SUPPORT 0x82B8
#define GL_IMAGE_CLASS_4_X_32 0x82B9
#define GL_IMAGE_CLASS_2_X_32 0x82BA
#define GL_IMAGE_CLASS_1_X_32 0x82BB
#define GL_IMAGE_CLASS_4_X_16 0x82BC
#define GL_IMAGE_CLASS_2_X_16 0x82BD
#define GL_IMAGE_CLASS_1_X_16 0x82BE
#define GL_IMAGE_CLASS_4_X_8 0x82BF
#define GL_IMAGE_CLASS_2_X_8 0x82C0
#define GL_IMAGE_CLASS_1_X_8 0x82C1
#define GL_IMAGE_CLASS_11_11_10 0x82C2
#define GL_IMAGE_CLASS_10_10_10_2 0x82C3
#define GL_VIEW_CLASS_128_BITS 0x82C4
#define GL_VIEW_CLASS_96_BITS 0x82C5
#define GL_VIEW_CLASS_64_BITS 0x82C6
#define GL_VIEW_CLASS_48_BITS 0x82C7
#define GL_VIEW_CLASS_32_BITS 0x82C8
#define GL_VIEW_CLASS_24_BITS 0x82C9
#define GL_VIEW_CLASS_16_BITS 0x82CA
#define GL_VIEW_CLASS_8_BITS 0x82CB
#define GL_VIEW_CLASS_S3TC_DXT1_RGB 0x82CC
#define GL_VIEW_CLASS_S3TC_DXT1_RGBA 0x82CD
#define GL_VIEW_CLASS_S3TC_DXT3_RGBA 0x82CE
#define GL_VIEW_CLASS_S3TC_DXT5_RGBA 0x82CF
#define GL_VIEW_CLASS_RGTC1_RED 0x82D0
#define GL_VIEW_CLASS_RGTC2_RG 0x82D1
#define GL_VIEW_CLASS_BPTC_UNORM 0x82D2
#define GL_VIEW_CLASS_BPTC_FLOAT 0x82D3

#define glGetInternalformati64v System::GlGetInternalformati64v

// (ARB 132) GL_ARB_invalidate_subdata

#define glInvalidateBufferData System::GlInvalidateBufferData
#define glInvalidateBufferSubData System::GlInvalidateBufferSubData
#define glInvalidateFramebuffer System::GlInvalidateFramebuffer
#define glInvalidateSubFramebuffer System::GlInvalidateSubFramebuffer
#define glInvalidateTexImage System::GlInvalidateTexImage
#define glInvalidateTexSubImage System::GlInvalidateTexSubImage

// (ARB 133) GL_ARB_multi_draw_indirect

#define glMultiDrawArraysIndirect System::GlMultiDrawArraysIndirect
#define glMultiDrawElementsIndirect System::GlMultiDrawElementsIndirect

// (ARB 134) GL_ARB_program_interface_query

#define GL_UNIFORM 0x92E1
#define GL_UNIFORM_BLOCK 0x92E2
#define GL_PROGRAM_INPUT 0x92E3
#define GL_PROGRAM_OUTPUT 0x92E4
#define GL_BUFFER_VARIABLE 0x92E5
#define GL_SHADER_STORAGE_BLOCK 0x92E6
#define GL_IS_PER_PATCH 0x92E7
#define GL_VERTEX_SUBROUTINE 0x92E8
#define GL_TESS_CONTROL_SUBROUTINE 0x92E9
#define GL_TESS_EVALUATION_SUBROUTINE 0x92EA
#define GL_GEOMETRY_SUBROUTINE 0x92EB
#define GL_FRAGMENT_SUBROUTINE 0x92EC
#define GL_COMPUTE_SUBROUTINE 0x92ED
#define GL_VERTEX_SUBROUTINE_UNIFORM 0x92EE
#define GL_TESS_CONTROL_SUBROUTINE_UNIFORM 0x92EF
#define GL_TESS_EVALUATION_SUBROUTINE_UNIFORM 0x92F0
#define GL_GEOMETRY_SUBROUTINE_UNIFORM 0x92F1
#define GL_FRAGMENT_SUBROUTINE_UNIFORM 0x92F2
#define GL_COMPUTE_SUBROUTINE_UNIFORM 0x92F3
#define GL_TRANSFORM_FEEDBACK_VARYING 0x92F4
#define GL_ACTIVE_RESOURCES 0x92F5
#define GL_MAX_NAME_LENGTH 0x92F6
#define GL_MAX_NUM_ACTIVE_VARIABLES 0x92F7
#define GL_MAX_NUM_COMPATIBLE_SUBROUTINES 0x92F8
#define GL_NAME_LENGTH 0x92F9
#define GL_TYPE 0x92FA
#define GL_ARRAY_SIZE 0x92FB
#define GL_OFFSET 0x92FC
#define GL_BLOCK_INDEX 0x92FD
#define GL_ARRAY_STRIDE 0x92FE
#define GL_MATRIX_STRIDE 0x92FF
#define GL_IS_ROW_MAJOR 0x9300
#define GL_ATOMIC_COUNTER_BUFFER_INDEX 0x9301
#define GL_BUFFER_BINDING 0x9302
#define GL_BUFFER_DATA_SIZE 0x9303
#define GL_NUM_ACTIVE_VARIABLES 0x9304
#define GL_ACTIVE_VARIABLES 0x9305
#define GL_REFERENCED_BY_VERTEX_SHADER 0x9306
#define GL_REFERENCED_BY_TESS_CONTROL_SHADER 0x9307
#define GL_REFERENCED_BY_TESS_EVALUATION_SHADER 0x9308
#define GL_REFERENCED_BY_GEOMETRY_SHADER 0x9309
#define GL_REFERENCED_BY_FRAGMENT_SHADER 0x930A
#define GL_REFERENCED_BY_COMPUTE_SHADER 0x930B
#define GL_TOP_LEVEL_ARRAY_SIZE 0x930C
#define GL_TOP_LEVEL_ARRAY_STRIDE 0x930D
#define GL_LOCATION 0x930E
#define GL_LOCATION_INDEX 0x930F

#define glGetProgramInterfaceiv System::GlGetProgramInterfaceiv
#define glGetProgramResourceIndex System::GlGetProgramResourceIndex
#define glGetProgramResourceLocation System::GlGetProgramResourceLocation
#define glGetProgramResourceLocationIndex System::GlGetProgramResourceLocationIndex
#define glGetProgramResourceName System::GlGetProgramResourceName
#define glGetProgramResourceiv System::GlGetProgramResourceiv

// (ARB 137) GL_ARB_shader_storage_buffer_object

#define GL_SHADER_STORAGE_BARRIER_BIT 0x2000
#define GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES 0x8F39
#define GL_SHADER_STORAGE_BUFFER 0x90D2
#define GL_SHADER_STORAGE_BUFFER_BINDING 0x90D3
#define GL_SHADER_STORAGE_BUFFER_START 0x90D4
#define GL_SHADER_STORAGE_BUFFER_SIZE 0x90D5
#define GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS 0x90D6
#define GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS 0x90D7
#define GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS 0x90D8
#define GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS 0x90D9
#define GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS 0x90DA
#define GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS 0x90DB
#define GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS 0x90DC
#define GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS 0x90DD
#define GL_MAX_SHADER_STORAGE_BLOCK_SIZE 0x90DE
#define GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT 0x90DF

#define glShaderStorageBlockBinding System::GlShaderStorageBlockBinding

// (ARB 138) GL_ARB_stencil_texturing

#define GL_DEPTH_STENCIL_TEXTURE_MODE 0x90EA

// (ARB 139) GL_ARB_texture_buffer_range

#define GL_TEXTURE_BUFFER_OFFSET 0x919D
#define GL_TEXTURE_BUFFER_SIZE 0x919E
#define GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT 0x919F

#define glTexBufferRange System::GlTexBufferRange
#define glTextureBufferRangeEXT System::GlTextureBufferRangeEXT

// (ARB 141) GL_ARB_texture_storage_multisample

#define glTexStorage2DMultisample System::GlTexStorage2DMultisample
#define glTexStorage3DMultisample System::GlTexStorage3DMultisample
#define glTextureStorage2DMultisampleEXT System::GlTextureStorage2DMultisampleEXT
#define glTextureStorage3DMultisampleEXT System::GlTextureStorage3DMultisampleEXT

// (ARB 144) GL_ARB_buffer_storage

#define GL_MAP_READ_BIT 0x0001
#define GL_MAP_WRITE_BIT 0x0002
#define GL_MAP_PERSISTENT_BIT 0x00000040
#define GL_MAP_COHERENT_BIT 0x00000080
#define GL_DYNAMIC_STORAGE_BIT 0x0100
#define GL_CLIENT_STORAGE_BIT 0x0200
#define GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT 0x00004000
#define GL_BUFFER_IMMUTABLE_STORAGE 0x821F
#define GL_BUFFER_STORAGE_FLAGS 0x8220

#define glBufferStorage System::GlBufferStorage
#define glNamedBufferStorageEXT System::GlNamedBufferStorageEXT

// (ARB 145) GL_ARB_clear_texture

#define GL_CLEAR_TEXTURE 0x9365

#define glClearTexImage System::GlClearTexImage
#define glClearTexSubImage System::GlClearTexSubImage

// (ARB 146) GL_ARB_enhanced_layouts

#define GL_LOCATION_COMPONENT 0x934A
#define GL_TRANSFORM_FEEDBACK_BUFFER_INDEX 0x934B
#define GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE 0x934C

// (ARB 147) GL_ARB_multi_bind

#define glBindBuffersBase System::GlBindBuffersBase
#define glBindBuffersRange System::GlBindBuffersRange
#define glBindImageTextures System::GlBindImageTextures
#define glBindSamplers System::GlBindSamplers
#define glBindTextures System::GlBindTextures
#define glBindVertexBuffers System::GlBindVertexBuffers

// (ARB 148) GL_ARB_query_buffer_object

#define GL_QUERY_BUFFER_BARRIER_BIT 0x00008000
#define GL_QUERY_BUFFER 0x9192
#define GL_QUERY_BUFFER_BINDING 0x9193
#define GL_QUERY_RESULT_NO_WAIT 0x9194

// (ARB 149) GL_ARB_texture_mirror_clamp_to_edge

#define GL_MIRROR_CLAMP_TO_EDGE 0x8743

// (ARB 150) GL_ARB_texture_stencil8

#define GL_STENCIL_INDEX 0x1901
#define GL_STENCIL_INDEX8 0x8D48

// (ARB 151) GL_ARB_vertex_type_10f_11f_11f_rev

#define GL_UNSIGNED_INT_10F_11F_11F_REV 0x8C3B

// (ARB 152) GL_ARB_bindless_texture

#define GL_UNSIGNED_INT64_ARB 0x140F

#define glGetImageHandleARB System::GlGetImageHandleARB
#define glGetTextureHandleARB System::GlGetTextureHandleARB
#define glGetTextureSamplerHandleARB System::GlGetTextureSamplerHandleARB
#define glGetVertexAttribLui64vARB System::GlGetVertexAttribLui64vARB
#define glIsImageHandleResidentARB System::GlIsImageHandleResidentARB
#define glIsTextureHandleResidentARB System::GlIsTextureHandleResidentARB
#define glMakeImageHandleNonResidentARB System::GlMakeImageHandleNonResidentARB
#define glMakeImageHandleResidentARB System::GlMakeImageHandleResidentARB
#define glMakeTextureHandleNonResidentARB System::GlMakeTextureHandleNonResidentARB
#define glMakeTextureHandleResidentARB System::GlMakeTextureHandleResidentARB
#define glProgramUniformHandleui64ARB System::GlProgramUniformHandleui64ARB
#define glProgramUniformHandleui64vARB System::GlProgramUniformHandleui64vARB
#define glUniformHandleui64ARB System::GlUniformHandleui64ARB
#define glUniformHandleui64vARB System::GlUniformHandleui64vARB
#define glVertexAttribL1ui64ARB System::GlVertexAttribL1ui64ARB
#define glVertexAttribL1ui64vARB System::GlVertexAttribL1ui64vARB

// (ARB 153) GL_ARB_compute_variable_group_size

#define GL_MAX_COMPUTE_FIXED_GROUP_INVOCATIONS_ARB 0x90EB
#define GL_MAX_COMPUTE_FIXED_GROUP_SIZE_ARB 0x91BF
#define GL_MAX_COMPUTE_VARIABLE_GROUP_INVOCATIONS_ARB 0x9344
#define GL_MAX_COMPUTE_VARIABLE_GROUP_SIZE_ARB 0x9345

#define glDispatchComputeGroupSizeARB System::GlDispatchComputeGroupSizeARB

// (ARB 154) GL_ARB_indirect_parameters

#define GL_PARAMETER_BUFFER_ARB 0x80EE
#define GL_PARAMETER_BUFFER_BINDING_ARB 0x80EF

#define glMultiDrawArraysIndirectCountARB System::GlMultiDrawArraysIndirectCountARB
#define glMultiDrawElementsIndirectCountARB System::GlMultiDrawElementsIndirectCountARB

// (ARB 155) GL_ARB_seamless_cubemap_per_texture

#define GL_TEXTURE_CUBE_MAP_SEAMLESS 0x884F

// (ARB 158) GL_ARB_sparse_texture

#define GL_VIRTUAL_PAGE_SIZE_X_ARB 0x9195
#define GL_VIRTUAL_PAGE_SIZE_Y_ARB 0x9196
#define GL_VIRTUAL_PAGE_SIZE_Z_ARB 0x9197
#define GL_MAX_SPARSE_TEXTURE_SIZE_ARB 0x9198
#define GL_MAX_SPARSE_3D_TEXTURE_SIZE_ARB 0x9199
#define GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_ARB 0x919A
#define GL_TEXTURE_SPARSE_ARB 0x91A6
#define GL_VIRTUAL_PAGE_SIZE_INDEX_ARB 0x91A7
#define GL_NUM_VIRTUAL_PAGE_SIZES_ARB 0x91A8
#define GL_SPARSE_TEXTURE_FULL_ARRAY_CUBE_MIPMAPS_ARB 0x91A9
#define GL_NUM_SPARSE_LEVELS_ARB 0x91AA

#define glTexPageCommitmentARB System::GlTexPageCommitmentARB
#define glTexturePageCommitmentEXT System::GlTexturePageCommitmentEXT

// (ARB 160) GL_ARB_clip_control

#define GL_LOWER_LEFT 0x8CA1
#define GL_UPPER_LEFT 0x8CA2
#define GL_CLIP_ORIGIN 0x935C
#define GL_CLIP_DEPTH_MODE 0x935D
#define GL_NEGATIVE_ONE_TO_ONE 0x935E
#define GL_ZERO_TO_ONE 0x935F

#define glClipControl System::GlClipControl

// (ARB 161) GL_ARB_conditional_render_inverted

#define GL_QUERY_WAIT_INVERTED 0x8E17
#define GL_QUERY_NO_WAIT_INVERTED 0x8E18
#define GL_QUERY_BY_REGION_WAIT_INVERTED 0x8E19
#define GL_QUERY_BY_REGION_NO_WAIT_INVERTED 0x8E1A

// (ARB 162) GL_ARB_cull_distance

#define GL_MAX_CULL_DISTANCES 0x82F9
#define GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES 0x82FA

// (ARB 164) GL_ARB_direct_state_access

#define GL_TEXTURE_TARGET 0x1006
#define GL_QUERY_TARGET 0x82EA
#define GL_TEXTURE_BINDING 0x82EB

#define glBindTextureUnit System::GlBindTextureUnit
#define glBlitNamedFramebuffer System::GlBlitNamedFramebuffer
#define glCheckNamedFramebufferStatus System::GlCheckNamedFramebufferStatus
#define glClearNamedBufferData System::GlClearNamedBufferData
#define glClearNamedBufferSubData System::GlClearNamedBufferSubData
#define glClearNamedFramebufferfi System::GlClearNamedFramebufferfi
#define glClearNamedFramebufferfv System::GlClearNamedFramebufferfv
#define glClearNamedFramebufferiv System::GlClearNamedFramebufferiv
#define glClearNamedFramebufferuiv System::GlClearNamedFramebufferuiv
#define glCompressedTextureSubImage1D System::GlCompressedTextureSubImage1D
#define glCompressedTextureSubImage2D System::GlCompressedTextureSubImage2D
#define glCompressedTextureSubImage3D System::GlCompressedTextureSubImage3D
#define glCopyNamedBufferSubData System::GlCopyNamedBufferSubData
#define glCopyTextureSubImage1D System::GlCopyTextureSubImage1D
#define glCopyTextureSubImage2D System::GlCopyTextureSubImage2D
#define glCopyTextureSubImage3D System::GlCopyTextureSubImage3D
#define glCreateBuffers System::GlCreateBuffers
#define glCreateFramebuffers System::GlCreateFramebuffers
#define glCreateProgramPipelines System::GlCreateProgramPipelines
#define glCreateQueries System::GlCreateQueries
#define glCreateRenderbuffers System::GlCreateRenderbuffers
#define glCreateSamplers System::GlCreateSamplers
#define glCreateTextures System::GlCreateTextures
#define glCreateTransformFeedbacks System::GlCreateTransformFeedbacks
#define glCreateVertexArrays System::GlCreateVertexArrays
#define glDisableVertexArrayAttrib System::GlDisableVertexArrayAttrib
#define glEnableVertexArrayAttrib System::GlEnableVertexArrayAttrib
#define glFlushMappedNamedBufferRange System::GlFlushMappedNamedBufferRange
#define glGenerateTextureMipmap System::GlGenerateTextureMipmap
#define glGetCompressedTextureImage System::GlGetCompressedTextureImage
#define glGetNamedBufferParameteri64v System::GlGetNamedBufferParameteri64v
#define glGetNamedBufferParameteriv System::GlGetNamedBufferParameteriv
#define glGetNamedBufferPointerv System::GlGetNamedBufferPointerv
#define glGetNamedBufferSubData System::GlGetNamedBufferSubData
#define glGetNamedFramebufferAttachmentParameteriv System::GlGetNamedFramebufferAttachmentParameteriv
#define glGetNamedFramebufferParameteriv System::GlGetNamedFramebufferParameteriv
#define glGetNamedRenderbufferParameteriv System::GlGetNamedRenderbufferParameteriv
#define glGetQueryBufferObjecti64v System::GlGetQueryBufferObjecti64v
#define glGetQueryBufferObjectiv System::GlGetQueryBufferObjectiv
#define glGetQueryBufferObjectui64v System::GlGetQueryBufferObjectui64v
#define glGetQueryBufferObjectuiv System::GlGetQueryBufferObjectuiv
#define glGetTextureImage System::GlGetTextureImage
#define glGetTextureLevelParameterfv System::GlGetTextureLevelParameterfv
#define glGetTextureLevelParameteriv System::GlGetTextureLevelParameteriv
#define glGetTextureParameterIiv System::GlGetTextureParameterIiv
#define glGetTextureParameterIuiv System::GlGetTextureParameterIuiv
#define glGetTextureParameterfv System::GlGetTextureParameterfv
#define glGetTextureParameteriv System::GlGetTextureParameteriv
#define glGetTransformFeedbacki64_v System::GlGetTransformFeedbacki64_v
#define glGetTransformFeedbacki_v System::GlGetTransformFeedbacki_v
#define glGetTransformFeedbackiv System::GlGetTransformFeedbackiv
#define glGetVertexArrayIndexed64iv System::GlGetVertexArrayIndexed64iv
#define glGetVertexArrayIndexediv System::GlGetVertexArrayIndexediv
#define glGetVertexArrayiv System::GlGetVertexArrayiv
#define glInvalidateNamedFramebufferData System::GlInvalidateNamedFramebufferData
#define glInvalidateNamedFramebufferSubData System::GlInvalidateNamedFramebufferSubData
#define glMapNamedBuffer System::GlMapNamedBuffer
#define glMapNamedBufferRange System::GlMapNamedBufferRange
#define glNamedBufferData System::GlNamedBufferData
#define glNamedBufferStorage System::GlNamedBufferStorage
#define glNamedBufferSubData System::GlNamedBufferSubData
#define glNamedFramebufferDrawBuffer System::GlNamedFramebufferDrawBuffer
#define glNamedFramebufferDrawBuffers System::GlNamedFramebufferDrawBuffers
#define glNamedFramebufferParameteri System::GlNamedFramebufferParameteri
#define glNamedFramebufferReadBuffer System::GlNamedFramebufferReadBuffer
#define glNamedFramebufferRenderbuffer System::GlNamedFramebufferRenderbuffer
#define glNamedFramebufferTexture System::GlNamedFramebufferTexture
#define glNamedFramebufferTextureLayer System::GlNamedFramebufferTextureLayer
#define glNamedRenderbufferStorage System::GlNamedRenderbufferStorage
#define glNamedRenderbufferStorageMultisample System::GlNamedRenderbufferStorageMultisample
#define glTextureBuffer System::GlTextureBuffer
#define glTextureBufferRange System::GlTextureBufferRange
#define glTextureParameterIiv System::GlTextureParameterIiv
#define glTextureParameterIuiv System::GlTextureParameterIuiv
#define glTextureParameterf System::GlTextureParameterf
#define glTextureParameterfv System::GlTextureParameterfv
#define glTextureParameteri System::GlTextureParameteri
#define glTextureParameteriv System::GlTextureParameteriv
#define glTextureStorage1D System::GlTextureStorage1D
#define glTextureStorage2D System::GlTextureStorage2D
#define glTextureStorage2DMultisample System::GlTextureStorage2DMultisample
#define glTextureStorage3D System::GlTextureStorage3D
#define glTextureStorage3DMultisample System::GlTextureStorage3DMultisample
#define glTextureSubImage1D System::GlTextureSubImage1D
#define glTextureSubImage2D System::GlTextureSubImage2D
#define glTextureSubImage3D System::GlTextureSubImage3D
#define glTransformFeedbackBufferBase System::GlTransformFeedbackBufferBase
#define glTransformFeedbackBufferRange System::GlTransformFeedbackBufferRange
#define glUnmapNamedBuffer System::GlUnmapNamedBuffer
#define glVertexArrayAttribBinding System::GlVertexArrayAttribBinding
#define glVertexArrayAttribFormat System::GlVertexArrayAttribFormat
#define glVertexArrayAttribIFormat System::GlVertexArrayAttribIFormat
#define glVertexArrayAttribLFormat System::GlVertexArrayAttribLFormat
#define glVertexArrayBindingDivisor System::GlVertexArrayBindingDivisor
#define glVertexArrayElementBuffer System::GlVertexArrayElementBuffer
#define glVertexArrayVertexBuffer System::GlVertexArrayVertexBuffer
#define glVertexArrayVertexBuffers System::GlVertexArrayVertexBuffers

// (ARB 165) GL_ARB_get_texture_sub_image

#define glGetCompressedTextureSubImage System::GlGetCompressedTextureSubImage
#define glGetTextureSubImage System::GlGetTextureSubImage

// (ARB 167) GL_ARB_texture_barrier

#define glTextureBarrier System::GlTextureBarrier

// (ARB 171) GL_ARB_pipeline_statistics_query 

#define GL_VERTICES_SUBMITTED_ARB 0x82EE
#define GL_PRIMITIVES_SUBMITTED_ARB 0x82EF
#define GL_VERTEX_SHADER_INVOCATIONS_ARB 0x82F0
#define GL_TESS_CONTROL_SHADER_PATCHES_ARB 0x82F1
#define GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB 0x82F2
#define GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB 0x82F3
#define GL_FRAGMENT_SHADER_INVOCATIONS_ARB 0x82F4
#define GL_COMPUTE_SHADER_INVOCATIONS_ARB 0x82F5
#define GL_CLIPPING_INPUT_PRIMITIVES_ARB 0x82F6
#define GL_CLIPPING_OUTPUT_PRIMITIVES_ARB 0x82F7
#define GL_GEOMETRY_SHADER_INVOCATIONS 0x887F

// (ARB 172) GL_ARB_sparse_buffer 

#define GL_SPARSE_STORAGE_BIT_ARB 0x0400
#define GL_SPARSE_BUFFER_PAGE_SIZE_ARB 0x82F8

#define glBufferPageCommitmentARB System::GlBufferPageCommitmentARB

// (ARB 173) GL_ARB_transform_feedback_overflow_query 

#define GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB 0x82EC
#define GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB 0x82ED

#endif // SYSTEM_HELPER_GL_ARB_EXTENSIONS_MACRO_H


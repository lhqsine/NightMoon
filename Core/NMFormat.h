/*
-----------------------------------------------------------------
This source file is part of NightMoon

GNU LESSER GENERAL PUBLIC LICENSE
Version 3, 29 June 2007

Copyright (C) 2007 Free Software Foundation, Inc. <http://fsf.org/>
Everyone is permitted to copy and distribute verbatim copies
of this license document, but changing it is not allowed.


This version of the GNU Lesser General Public License incorporates
the terms and conditions of version 3 of the GNU General Public
License, supplemented by the additional permissions listed below.

0. Additional Definitions.

As used herein, "this License" refers to version 3 of the GNU Lesser
General Public License, and the "GNU GPL" refers to version 3 of the GNU
General Public License.

"The Library" refers to a covered work governed by this License,
other than an Application or a Combined Work as defined below.

An "Application" is any work that makes use of an interface provided
by the Library, but which is not otherwise based on the Library.
Defining a subclass of a class defined by the Library is deemed a mode
of using an interface provided by the Library.

A "Combined Work" is a work produced by combining or linking an
Application with the Library.  The particular version of the Library
with which the Combined Work was made is also called the "Linked
Version".

The "Minimal Corresponding Source" for a Combined Work means the
Corresponding Source for the Combined Work, excluding any source code
for portions of the Combined Work that, considered in isolation, are
based on the Application, and not on the Linked Version.

The "Corresponding Application Code" for a Combined Work means the
object code and/or source code for the Application, including any data
and utility programs needed for reproducing the Combined Work from the
Application, but excluding the System Libraries of the Combined Work.

1. Exception to Section 3 of the GNU GPL.

You may convey a covered work under sections 3 and 4 of this License
without being bound by section 3 of the GNU GPL.

2. Conveying Modified Versions.

If you modify a copy of the Library, and, in your modifications, a
facility refers to a function or data to be supplied by an Application
that uses the facility (other than as an argument passed when the
facility is invoked), then you may convey a copy of the modified
version:

a) under this License, provided that you make a good faith effort to
ensure that, in the event an Application does not supply the
function or data, the facility still operates, and performs
whatever part of its purpose remains meaningful, or

b) under the GNU GPL, with none of the additional permissions of
this License applicable to that copy.

3. Object Code Incorporating Material from Library Header Files.

The object code form of an Application may incorporate material from
a header file that is part of the Library.  You may convey such object
code under terms of your choice, provided that, if the incorporated
material is not limited to numerical parameters, data structure
layouts and accessors, or small macros, inline functions and templates
(ten or fewer lines in length), you do both of the following:

a) Give prominent notice with each copy of the object code that the
Library is used in it and that the Library and its use are
covered by this License.

b) Accompany the object code with a copy of the GNU GPL and this license
document.

4. Combined Works.

You may convey a Combined Work under terms of your choice that,
taken together, effectively do not restrict modification of the
portions of the Library contained in the Combined Work and reverse
engineering for debugging such modifications, if you also do each of
the following:

a) Give prominent notice with each copy of the Combined Work that
the Library is used in it and that the Library and its use are
covered by this License.

b) Accompany the Combined Work with a copy of the GNU GPL and this license
document.

c) For a Combined Work that displays copyright notices during
execution, include the copyright notice for the Library among
these notices, as well as a reference directing the user to the
copies of the GNU GPL and this license document.

d) Do one of the following:

0) Convey the Minimal Corresponding Source under the terms of this
License, and the Corresponding Application Code in a form
suitable for, and under terms that permit, the user to
recombine or relink the Application with a modified version of
the Linked Version to produce a modified Combined Work, in the
manner specified by section 6 of the GNU GPL for conveying
Corresponding Source.

1) Use a suitable shared library mechanism for linking with the
Library.  A suitable mechanism is one that (a) uses at run time
a copy of the Library already present on the user's computer
system, and (b) will operate properly with a modified version
of the Library that is interface-compatible with the Linked
Version.

e) Provide Installation Information, but only if you would otherwise
be required to provide such information under section 6 of the
GNU GPL, and only to the extent that such information is
necessary to install and execute a modified version of the
Combined Work produced by recombining or relinking the
Application with a modified version of the Linked Version. (If
you use option 4d0, the Installation Information must accompany
the Minimal Corresponding Source and Corresponding Application
Code. If you use option 4d1, you must provide the Installation
Information in the manner specified by section 6 of the GNU GPL
for conveying Corresponding Source.)

5. Combined Libraries.

You may place library facilities that are a work based on the
Library side by side in a single library together with other library
facilities that are not Applications and are not covered by this
License, and convey such a combined library under terms of your
choice, if you do both of the following:

a) Accompany the combined library with a copy of the same work based
on the Library, uncombined with any other library facilities,
conveyed under the terms of this License.

b) Give prominent notice with the combined library that part of it
is a work based on the Library, and explaining where to find the
accompanying uncombined form of the same work.

6. Revised Versions of the GNU Lesser General Public License.

The Free Software Foundation may publish revised and/or new versions
of the GNU Lesser General Public License from time to time. Such new
versions will be similar in spirit to the present version, but may
differ in detail to address new problems or concerns.

Each version is given a distinguishing version number. If the
Library as you received it specifies that a certain numbered version
of the GNU Lesser General Public License "or any later version"
applies to it, you have the option of following the terms and
conditions either of that published version or of any later version
published by the Free Software Foundation. If the Library as you
received it does not specify a version number of the GNU Lesser
General Public License, you may choose any version of the GNU Lesser
General Public License ever published by the Free Software Foundation.

If the Library as you received it specifies that a proxy can decide
whether future versions of the GNU Lesser General Public License shall
apply, that proxy's public statement of acceptance of any version is
permanent authorization for you to choose that version for the
Library.
-----------------------------------------------------------------
*/

#ifndef CORE_NMFORMAT_H_
#define CORE_NMFORMAT_H_

#include "NMPredeclare.h"

namespace NightMoon
{
    enum EPixelDataFormat
    {
        PDF_R = 0UL,    // Red
        PDF_G = 1UL,    // Green
        PDF_B = 2UL,    // Blue
        PDF_A = 3UL,    // Alpha
        PDF_D = 4UL,    // Depth
        PDF_S = 5UL,    // Stencil
        PDF_E = 6UL,    // exp
        PDF_C = 7UL,    // Compressed
    };

    enum EPixelDataType
    {
        PDT_UNorm = 0UL,  // Unsigned normalized byte
        PDT_SNorm = 1UL,  // Signed normalized byte
        PDT_UInt = 2UL,  // Unsigned integer
        PDT_SInt = 3UL,  // Signed integer
        PDT_Float = 4UL,  // Float and half float
        PDT_UNorm_SRGB = 5UL,  // SRGB only
        PDT_SharedEXP = 6UL,  // For shared exp format only
    };

    // template struct used to make constant values for format enumerations.
    template<UInt64 ch0, UInt64 ch1, UInt64 ch2, UInt64 ch3,     // Each channel type
        UInt64 size0, UInt64 size1, UInt64 size2, UInt64 size3,  // Number of bit in each channel
        UInt64 type0, UInt64 type1, UInt64 type2, UInt64 type3>  // The data type of the each channel
    struct MakeFormatValue4
    {
        // total format bits = (4 + 6 + 4) * 4 = 64 bit
        static UInt64 const value = (ch0 << 0) | (ch1 << 4) | (ch2 << 8) | (ch3 << 12)          // Each channel has 4 bit
        | (size0 << 16) | (size1 << 22) | (size2 << 28) | (size3 << 34)     // Each channel has 6 bit
        | (type0 << 40) | (type1 << 44) | (type2 << 48) | (type3 << 52);    // Each type has 4 bit
    };

    // template struct used to make constant values for format enumerations.
    template<UInt64 ch0, UInt64 ch1, UInt64 ch2,    // Each channel type
        UInt64 size0, UInt64 size1, UInt64 size2,   // Number of bit in each channel
        UInt64 type0, UInt64 type1, UInt64 type2>   // The data type of the each channel
    struct MakeFormatValue3
    {
        static UInt64 const value = MakeFormatValue4<ch0, ch1, ch2, 0, size0, size1, size2, 0, type0, type1, type2, 0>::value;
    };

    // template struct used to make constant values for format enumerations.
    template < UInt64 ch0, UInt64 ch1,  // Each channel type
        UInt64 size0, UInt64 size1,     // Number of bit in each channel
        UInt64 type0, UInt64 type1>     // The data type of the each channel
    struct MakeFormatValue2
    {
        static UInt64 const value = MakeFormatValue4<ch0, ch1, 0, 0, size0, size1, 0, 0, type0, type1, 0, 0>::value;
    };

    // template struct used to make constant values for format enumerations.
    template < UInt64 ch0, UInt64 size0, UInt64 type0>
    struct MakeFormatValue1
    {
        static UInt64 const value = MakeFormatValue4<ch0, 0, 0, 0, size0, 0, 0, 0, type0, 0, 0, 0>::value;
    };

    // Enumerations for texture and buffer.
    enum class EFormat : UInt64
    {
        Unknown = 0,

        R8_UNORM = MakeFormatValue1<PDF_R, 8, PDT_UNorm>::value,
        R8_SNORM = MakeFormatValue1<PDF_R, 8, PDT_SNorm>::value,
        R16_UNORM = MakeFormatValue1<PDF_R, 16, PDT_UNorm>::value,
        R16_SNOM = MakeFormatValue1<PDF_R, 16, PDT_SNorm>::value,

        R8G8_UNORM = MakeFormatValue2<PDF_R, PDF_G, 8, 8, PDT_UNorm, PDT_UNorm>::value,
        R8G8_SNORM = MakeFormatValue2<PDF_R, PDF_G, 8, 8, PDT_SNorm, PDT_SNorm>::value,
        R16G16_UNORM = MakeFormatValue2<PDF_R, PDF_G, 16, 16, PDT_UNorm, PDT_UNorm>::value,
        R16G16_SNORM = MakeFormatValue2<PDF_R, PDF_G, 16, 16, PDT_SNorm, PDT_SNorm>::value,

        R8G8B8A8_UNORM = MakeFormatValue4<PDF_R, PDF_G, PDF_B, PDF_A, 8, 8, 8, 8, PDT_UNorm, PDT_UNorm, PDT_UNorm, PDT_UNorm>::value,
        R8G8B8A8_SNORM = MakeFormatValue4<PDF_R, PDF_G, PDF_B, PDF_A, 8, 8, 8, 8, PDT_SNorm, PDT_SNorm, PDT_SNorm, PDT_SNorm>::value,

        R10G10B10A2_UNORM = MakeFormatValue4<PDF_R, PDF_G, PDF_B, PDF_A, 10, 10, 10, 2, PDT_UNorm, PDT_UNorm, PDT_UNorm, PDT_UNorm>::value,
        R10G10B10A2_UINT = MakeFormatValue4<PDF_R, PDF_G, PDF_B, PDF_A, 10, 10, 10, 2, PDT_UInt, PDT_UInt, PDT_UInt, PDT_UInt>::value,

        R16G16B16A16_UNORM = MakeFormatValue4<PDF_R, PDF_G, PDF_B, PDF_A, 16, 16, 16, 16, PDT_UNorm, PDT_UNorm, PDT_UNorm, PDT_UNorm>::value,
        R16G16B16A16_SNORM = MakeFormatValue4<PDF_R, PDF_G, PDF_B, PDF_A, 16, 16, 16, 16, PDT_SNorm, PDT_SNorm, PDT_SNorm, PDT_SNorm>::value,

        R8G8B8A8_UNORM_SRGB = MakeFormatValue4<PDF_R, PDF_G, PDF_B, PDF_A, 8, 8, 8, 8, PDT_UNorm_SRGB, PDT_UNorm_SRGB, PDT_UNorm_SRGB, PDT_UNorm_SRGB>::value,

        R16_FLOAT = MakeFormatValue1<PDF_R, 16, PDT_Float>::value,
        R16G16_FLOAT = MakeFormatValue2<PDF_R, PDF_G, 16, 16, PDT_Float, PDT_Float>::value,
        R16G16B16A16_FLOAT = MakeFormatValue4<PDF_R, PDF_G, PDF_B, PDF_A, 16, 16, 16, 16, PDT_Float, PDT_Float, PDT_Float, PDT_Float>::value,

        R32_FLOAT = MakeFormatValue1<PDF_R, 32, PDT_Float>::value,
        R32G32_FLOAT = MakeFormatValue2<PDF_R, PDF_G, 32, 32, PDT_Float, PDT_Float>::value,
        R32G32B32_FLOAT = MakeFormatValue3<PDF_R, PDF_G, PDF_B, 32, 32, 32, PDT_Float, PDT_Float, PDT_Float>::value,
        R32G32B32A32_FLOAT = MakeFormatValue4<PDF_R, PDF_G, PDF_B, PDF_A, 32, 32, 32, 32, PDT_Float, PDT_Float, PDT_Float, PDT_Float>::value,
        R11G11B10_FLOAT = MakeFormatValue3<PDF_R, PDF_G, PDF_B, 11, 11, 10, PDT_Float, PDT_Float, PDT_Float>::value,
        R9G9B9E5_SHAREDEXP = MakeFormatValue4<PDF_R, PDF_G, PDF_B, PDF_E, 9, 9, 9, 5, PDT_UInt, PDT_UInt, PDT_UInt, PDT_SharedEXP>::value,

        R8_INT = MakeFormatValue1<PDF_R, 8, PDT_SInt>::value,
        R8_UINT = MakeFormatValue1<PDF_R, 8, PDT_UInt>::value,
        R16_INT = MakeFormatValue1<PDF_R, 16, PDT_SInt>::value,
        R16_UINT = MakeFormatValue1<PDF_R, 16, PDT_UInt>::value,
        R32_INT = MakeFormatValue1<PDF_R, 32, PDT_SInt>::value,
        R32_UINT = MakeFormatValue1<PDF_R, 32, PDT_UInt>::value,

        R8G8_INT = MakeFormatValue2<PDF_R, PDF_G, 8, 8, PDT_SInt, PDT_SInt>::value,
        R8G8_UINT = MakeFormatValue2<PDF_R, PDF_G, 8, 8, PDT_UInt, PDT_UInt>::value,
        R16G16_INT = MakeFormatValue2<PDF_R, PDF_G, 16, 16, PDT_SInt, PDT_SInt>::value,
        R16G16_UINT = MakeFormatValue2<PDF_R, PDF_G, 16, 16, PDT_UInt, PDT_UInt>::value,
        R32G32_INT = MakeFormatValue2<PDF_R, PDF_G, 32, 32, PDT_SInt, PDT_SInt>::value,
        R32G32_UINT = MakeFormatValue2<PDF_R, PDF_G, 32, 32, PDT_UInt, PDT_UInt>::value,

        R32G32B32_INT = MakeFormatValue3<PDF_R, PDF_G, PDF_B, 32, 32, 32, PDT_SInt, PDT_SInt, PDT_SInt>::value,
        R32G32B32_UINT = MakeFormatValue3<PDF_R, PDF_G, PDF_B, 32, 32, 32, PDT_UInt, PDT_UInt, PDT_UInt>::value,
        R8G8B8A8_INT = MakeFormatValue4<PDF_R, PDF_G, PDF_B, PDF_A, 8, 8, 8, 8, PDT_SInt, PDT_SInt, PDT_SInt, PDT_SInt>::value,
        R8G8B8A8_UINT = MakeFormatValue4<PDF_R, PDF_G, PDF_B, PDF_A, 8, 8, 8, 8, PDT_UInt, PDT_UInt, PDT_UInt, PDT_UInt>::value,

        R16G16B16A16_INT = MakeFormatValue4<PDF_R, PDF_G, PDF_B, PDF_A, 16, 16, 16, 16, PDT_SInt, PDT_SInt, PDT_SInt, PDT_SInt>::value,
        R16G16B16A16_UINT = MakeFormatValue4<PDF_R, PDF_G, PDF_B, PDF_A, 16, 16, 16, 16, PDT_UInt, PDT_UInt, PDT_UInt, PDT_UInt>::value,
        R32G32B32A32_INT = MakeFormatValue4<PDF_R, PDF_G, PDF_B, PDF_A, 32, 32, 32, 32, PDT_SInt, PDT_SInt, PDT_SInt, PDT_SInt>::value,
        R32G32B32A32_UINT = MakeFormatValue4<PDF_R, PDF_G, PDF_B, PDF_A, 32, 32, 32, 32, PDT_UInt, PDT_UInt, PDT_UInt, PDT_UInt>::value,
        R8G8B8_UNORM = MakeFormatValue3<PDF_R, PDF_G, PDF_B, 8, 8, 8, PDT_UNorm, PDT_UNorm, PDT_UNorm>::value,

        B8G8R8_UNORM = MakeFormatValue3<PDF_B, PDF_G, PDF_R, 8, 8, 8, PDT_UNorm, PDT_UNorm, PDT_UNorm>::value,
        B8G8R8A8_UNORM = MakeFormatValue4<PDF_B, PDF_G, PDF_R, PDF_A, 8, 8, 8, 8, PDT_UNorm, PDT_UNorm, PDT_UNorm, PDT_UNorm>::value,

        // Block compression format.
        // The size in the compressed format only used to distinguish each other.
        BC1_UNORM = MakeFormatValue1<PDF_C, 1, PDT_UNorm>::value,
        BC1_UNORM_SRGB = MakeFormatValue1<PDF_C, 1, PDT_UNorm_SRGB>::value,
        BC2_UNORM = MakeFormatValue1<PDF_C, 2, PDT_UNorm>::value,
        BC2_UNORM_SRGB = MakeFormatValue1<PDF_C, 2, PDT_UNorm_SRGB>::value,
        BC3_UNORM = MakeFormatValue1<PDF_C, 3, PDT_UNorm>::value,
        BC3_UNORM_SRGB = MakeFormatValue1<PDF_C, 3, PDT_UNorm_SRGB>::value,
        BC4_UNORM = MakeFormatValue1<PDF_C, 4, PDT_UNorm>::value,
        BC4_SNORM = MakeFormatValue1<PDF_C, 4, PDT_SNorm>::value,
        BC5_UNORM = MakeFormatValue1<PDF_C, 5, PDT_UNorm>::value,
        BC5_SNORM = MakeFormatValue1<PDF_C, 5, PDT_SNorm>::value,
        BC6H_UF16 = MakeFormatValue1<PDF_C, 6, PDT_UNorm>::value,
        BC6H_SF16 = MakeFormatValue1<PDF_C, 6, PDT_SNorm>::value,
        BC7_UNORM = MakeFormatValue1<PDF_C, 7, PDT_UNorm>::value,
        BC7_UNORM_SRGB = MakeFormatValue1<PDF_C, 7, PDT_UNorm_SRGB>::value,

        // ETC1
        ETC1_RGB8 = MakeFormatValue1<PDF_C, 10, PDT_UNorm>::value,

        // PVRTC1
        // PVRTC1_RGB_4BPPV1 = MakeFormatValue1<PDF_C, 11, PDT_UNorm>::value,
        // PVRTC1_RGB_2BPPV1 = MakeFormatValue1<PDF_C, 12, PDT_UNorm>::value,
        // PVRTC1_RGBA_4BPPV1 = MakeFormatValue1<PDF_C, 13, PDT_UNorm>::value,
        // PVRTC1_RGBA_2BPPV1 = MakeFormatValue1<PDF_C, 14, PDT_UNorm>::value,

        // Depth stencil format.
        D16_UNORM = MakeFormatValue1<PDF_D, 16, PDT_UNorm>::value,
        D32_FLOAT = MakeFormatValue1<PDF_D, 32, PDT_Float>::value,
        D24_UNORM_S8_UINT = MakeFormatValue2<PDF_D, PDF_S, 24, 8, PDT_UNorm, PDT_UInt>::value,
        D32_FLOAT_S8X24_UINT = MakeFormatValue2<PDF_D, PDF_S, 32, 8, PDT_Float, PDT_UInt>::value,
    };

    class FormatUtils
    {
    public:
        // Get the pixel data format with the specified channel.
        template<int channel>
        static EPixelDataFormat GetPixelDataFormat(const EFormat & format)
        {
            return static_cast<EPixelDataFormat>((static_cast<UInt64>(format) >> (4 * channel)) & 0xF);  // decode and only need last 4 bit (1111)
        }

        // Get the channel size with the specified channel, but in compressed format, it only means the index.
        template<int channel>
        static UInt8 GetPixelDataSize(const EFormat & format)
        {
            return (static_cast<UInt64>(format) >> (16 + 6 * channel)) & 0x3F;  // decode and only need last 6 bit
        }

        // Get the pixel data type with the specified channel
        template<int channel>
        static EPixelDataType GetPixelDataType(const EFormat & format)
        {
            return static_cast<EPixelDataType>((static_cast<UInt64>(format) >> (40 + 4 * channel)) & 0xF);  // decode and only need last 4 bit
        }

        // If one of the channel's pixel data is float, return true.
        static Bool IsFloat(const EFormat &format)
        {
            return PDT_Float == GetPixelDataType<0>(format);
        }

        // If one of the channel's pixel data is depth, return true.
        static Bool IsDepth(const EFormat &format)
        {
            return PDF_D == GetPixelDataFormat<0>(format);
        }

        // If one of the channel's pixel data is stencil, return true.
        static Bool IsStencil(const EFormat &format)
        {
            return PDF_S == GetPixelDataFormat<1>(format);
        }

        // If one of the channel's pixel data is SRGB, return true.
        static Bool IsSRGB(const EFormat &format)
        {
            return PDT_UNorm_SRGB == GetPixelDataType<0>(format);
        }

        // If one of the channel's pixel data is unsigned, return true.
        static Bool IsUnsigned(const EFormat &format)
        {
            return PDT_UInt == GetPixelDataType<0>(format);
        }

        // If one of the channel's pixel data is compressed, return true.
        static Bool IsCompressed(const EFormat &format)
        {
            return PDF_C == GetPixelDataFormat<1>(format);
        }

        // Get the size of depth channel in bits.
        static UInt8 NumDepthBits(const EFormat &format)
        {
            return IsDepth(format) ? GetPixelDataSize<0>(format) : 0;
        }

        // Get the size of stencil channel in bits.
        static UInt8 NumStencilBits(const EFormat &format)
        {
            return IsStencil(format) ? GetPixelDataSize<1>(format) : 0;
        }

        // Get the total size of the format (per pixel) in bits.
        static UInt32 NumFormatBits(const EFormat &format)
        {
            if (IsCompressed(format))
            {
                switch (GetPixelDataSize<0>(format))
                {
                    // Block Compression
                    case 1:  // BC1
                    case 4:  // BC4
                        return 16;
                    case 2:  // BC2
                    case 3:  // BC3
                    case 5:  // BC5
                    case 6:  // BC6
                    case 7:  // BC7
                        return 32;

                        // Android Formats
                    case 10:  // ETC1_RGB
                        return 8;
                    default:
                        NM_DEBUG_LOG("Invalid type for NumFormatBits.");
                        return 0;
                }
            }
            else
            {
                return GetPixelDataSize<0>(format) +GetPixelDataSize<1>(format)
                    +GetPixelDataSize<2>(format) +GetPixelDataSize<3>(format);
            }
        }

        // Get the total size of the format.
        static UInt32 NumFormatBytes(const EFormat &format)
        {
            return NumFormatBits(format) / 8;
        }

        // Get the number of channels.
        static UInt8 NumComponents(const EFormat &format)
        {
            if (IsCompressed(format))
            {
                switch (GetPixelDataSize<0>(format))
                {
                    // Block Compression
                    case 1:  // BC1
                    case 2:  // BC2
                    case 3:  // BC3
                        return 4;
                    case 4:  // BC4
                        return 1;
                    case 5:  // BC5
                        return 2;
                    case 6:  // BC6
                    case 7:  // BC7
                        return 3;

                        // Android Formats
                    case 10:  // ETC1_RGB
                        return 4;
                }
            }
            else
            {
                return (GetPixelDataSize<0>(format) != 0) + (GetPixelDataSize<1>(format) != 0)
                    + (GetPixelDataSize<2>(format) != 0) + (GetPixelDataSize<3>(format) != 0);
            }
        }

        static Bool IsRenderTargetCompatible(const EFormat &format0, const EFormat &format1)
        {
            return ((IsCompatible128Bit(format0) && IsCompatibleCompressed128Bit(format1))
                || (IsCompatible128Bit(format1) && IsCompatibleCompressed128Bit(format0))
                || (IsCompatible64Bit(format0) && IsCompatibleCompressed64Bit(format1))
                || (IsCompatible64Bit(format1) && IsCompatibleCompressed64Bit(format0)));
        }

    protected:
        static Bool IsCompatibleCompressed128Bit(const EFormat &format)
        {
            switch (format)
            {
                case EFormat::BC2_UNORM:
                case EFormat::BC2_UNORM_SRGB:
                case EFormat::BC3_UNORM:
                case EFormat::BC3_UNORM_SRGB:
                case EFormat::BC5_UNORM:
                case EFormat::BC5_SNORM:
                case EFormat::BC7_UNORM:
                case EFormat::BC7_UNORM_SRGB:
                case EFormat::BC6H_UF16:
                case EFormat::BC6H_SF16:
                    return true;
                default:
                    return false;
            }
        }

        static Bool IsCompatible128Bit(const EFormat &format)
        {
            switch (format)
            {
                case EFormat::R32G32B32A32_UINT:
                case EFormat::R32G32B32A32_INT:
                case EFormat::R32G32B32A32_FLOAT:
                    return true;
                default:
                    return false;
            }
        }

        static Bool IsCompatibleCompressed64Bit(const EFormat &format)
        {
            switch (format)
            {
                case EFormat::BC1_UNORM:
                case EFormat::BC1_UNORM_SRGB:
                case EFormat::BC4_SNORM:
                case EFormat::BC4_UNORM:
                    return true;
                default:
                    return false;
            }
        }

        static Bool IsCompatible64Bit(const EFormat &format)
        {
            switch (format)
            {
                case EFormat::R16G16B16A16_FLOAT:
                case EFormat::R16G16B16A16_UINT:
                case EFormat::R16G16B16A16_INT:
                case EFormat::R16G16B16A16_UNORM:
                case EFormat::R16G16B16A16_SNORM:
                case EFormat::R32G32_FLOAT:
                case EFormat::R32G32_INT:
                case EFormat::R32G32_UINT:
                    return true;
                default:
                    return false;
            }
        }
    };
}  // namespace NightMoon
#endif  // CORE_NMFORMAT_H_

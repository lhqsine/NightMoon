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
#ifndef CORE_NMENUMS_H_
#define CORE_NMENUMS_H_

namespace NightMoon
{
    enum class EDebugFilter
    {
        Unknown = 1,
        GraphicAPI = 2,
        Client = 4,
        All = 7,
    };

    enum class EDebugSeverity
    {
        Message = 1,
        Warning = 2,
        Error = 4,
        Undef = 8,
        All = 15,
    };

    enum class EDeviceType
    {
        Unknown = 0,
        Mobile = 1,
        Desktop = 2,
    };

    enum class ENPOTSupport
    {
        None = 0,
        Limited = 1,
        Full = 2,
    };

    enum class EBufferUsage
    {
        Static = 0,
        Dynamic = 1,
        Stream = 2,
    };

    enum class EAccess
    {
        Read = 1,
        Write = 2,
        ReadAndWrite = 3,
    };

    enum class ETexType
    {
        Tex1D = 0,
        Tex1DArray = 1,
        Tex2D = 2,
        Tex2DArray = 3,
        Tex3D = 4,
        TexCube = 5,
        TexCubeArray = 6,
    };

    enum class EFrontFace
    {
        CCW = 0,
        CW = 1,
    };

    enum class ECullMode
    {
        None = 0,
        Front = 1,
        Back = 2,
        FrontAndBack = 3,
    };

    enum class EPolygonMode
    {
        Point = 0,
        Line = 1,
        Fill = 2,
    };

    enum class EFace
    {
        Front = 0,
        Back = 1,
        FrontAndBack = 2,
    };

    enum class ECompareFunc
    {
        Never = 0,
        Less = 1,
        LEqual = 2,
        Greater = 3,
        GEqual = 4,
        Equal = 5,
        NotEqual = 6,
        Always = 7,
    };

    enum class EStencilOperation
    {
        Keep = 0,
        Zero = 1,
        Replace = 2,
        Incr = 3,
        IncWrap = 4,
        Decr = 5,
        DecrWrap = 6,
        Invert = 7,
    };

    enum class EBlendFactor
    {
        Zero = 0,
        One = 1,
        Src = 2,
        OneMinusSrc = 3,
        Dst = 4,
        OneMinusDst = 5,
        SrcAlpha = 6,
        OneMinusSrcAlpha = 7,
        DstAlpha = 8,
        OneMinusDstAlpha = 9,
        ConstantAlpha = 10,
        OneMinusConstantAlpha = 11,
        SrcAlphaSaturate = 12,
        Src1 = 13,
        OneMinusSrc1 = 14,
        Src1Alpha = 15,
        OneMinusSrc1Alpha = 16,
    };

    enum class EBlendOperation
    {
        Add = 0,
        Subtract = 1,
        ReverseSubtract = 2,
        Min = 3,
        Max = 4,
    };

    enum class ETexFilter
    {
        Nearst = 0,
        Linear = 1,
        NearstMipmapNearst = 2,
        LinearMipmapNearst = 3,
        NearstMipmapLinear = 4,
        LinearMipmapLinear = 5,
        Anisotropy = 6,
    };

    enum class ETexAddressMode
    {
        Repeat = 0,
        MirroredRepeat = 1,
        ClampToEdge = 2,
        ClampToBorder = 3,
        MirrorClampToEdge = 4,
    };

    enum class EColorMask
    {
        Red = 1,
        Green = 2,
        Blue = 4,
        Alpha = 8,
        All = 15,
    };

    enum class EUniformType
    {
        Unknown = 0,
        Float = 1,
        Vec2 = 2,
        Vec3 = 3,
        Vec4 = 4,
        Mat4 = 7,
        Tex2D = 13,
        Tex2DArray = 14,
        Tex3D = 15,
        TexCube = 16,
        TexCubeArray = 17,
    };

    enum class EShaderLevel
    {
        ShaderLevel30 = 30,
        ShaderLevel31 = 31,
        ShaderLevel32 = 32,
        ShaderLevel33 = 33,
        ShaderLevel40 = 40,
        ShaderLevel41 = 41,
        ShaderLevel42 = 42,
        ShaderLevel43 = 43,
        ShaderLevel44 = 44,
        ShaderLevel45 = 45,
    };

    enum class EShaderType
    {
        Unknown = 0,
        VertexShader = 1,
        GeometryShader = 2,
        TessControlShader = 3,
        TessEvaluationShader = 4,
        FragmentShader = 5,
        ComputeShader = 6,
    };

    enum class ERenderOrder
    {
        Background = 0,
        Geometry = 1000,
        AlphaTest = 2000,
        Transparent = 3000,
        Overlay = 4000,
    };

    enum class EDisplayMode
    {
        FullScreen = 0,
        WindowedFullScreen = 1,
        Windowed = 2,
    };

    enum class EMultiSampleMode
    {
        None = 0,
        MSAA = 1,
        FXAA = 2,
    };

    enum class ESolutionType
    {
        Fast = 1,
        Low = 2,
        Middle = 3,
        High = 4,
        VeryHigh = 5,
    };

    enum class ETextureFilterMode
    {
        Nearest = 1,
        Bilinear = 2,
        Trilinear = 3,
        Anisotropic = 4,
    };

    enum class EGraphicInterface
    {
        OpenGL4 = 0,
        Direct3D11 = 1,
    };
}  // namespace NightMoon
#endif  // CORE_NMENUMS_H_

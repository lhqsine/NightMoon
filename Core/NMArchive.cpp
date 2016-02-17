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

#include "NMTypes.h"
#include "NMArchive.h"
#include "NMObject.h"
#include "NMMemConfig.h"

namespace NightMoon
{
    NMArchive::NMArchive(FStream *file, EArchiveMode mode)
        :mFile(file), mMode(mode)
    {
        if (nullptr == file)
        {
            NM_DEBUG_LOG("The file stream of this archive should not be null, create the stream first.");
        }
    }

    NMArchive::~NMArchive(void)
    {
        if (mFile != nullptr)
        {
            mFile->close();
        }
    }

    EArchiveMode NMArchive::GetArchiveMode(void) const
    {
        return this->mMode;
    }

    FStream* NMArchive::GetFile(void) const
    {
        return this->mFile;
    }

    UInt64 NMArchive::Read(void* buf, UInt64 maxNumOfBytes)
    {
        if (nullptr == buf)
        {
            NM_DEBUG_LOG("The pointer of output buffer should not be null.");
            return 0;
        }

        if (mFile == nullptr || false == mFile->is_open())
        {
            NM_DEBUG_LOG("The archive is not initialized or the file stream is not opened.");
            return 0;
        }

        // Get the max length of the file length from start to end.
        UInt64 curPos = mFile->tellg();
        mFile->seekg(0, std::ios::end);
        UInt64 maxLen = mFile->tellg();
        UInt64 remain = maxLen - curPos;
        UInt64 count = maxNumOfBytes > remain ? remain : maxNumOfBytes;  // should not larger than the file size.
        mFile->seekg(curPos);  // must seek to the old position.

        mFile->read(reinterpret_cast<Char*>(buf), count);

        // return bytes actually read.
        return count;
    }

    void NMArchive::Write(const void* buf, UInt64 maxNumOfBytes)
    {
        if (nullptr == buf)
        {
            NM_DEBUG_LOG("The pointer of output buffer should not be null.");
            return;
        }

        if (mFile == nullptr || false == mFile->is_open())
        {
            NM_DEBUG_LOG("The archive is not initialized or the file stream is not opened.");
            return;
        }

        mFile->write(reinterpret_cast<const Char*>(buf), maxNumOfBytes);
    }

    NMClassInfo* NMArchive::ReadClass(void)
    {
        // Load the class name, and find the class info from the linked list.
        // Read the length first, then read the string.
        NMClassInfo* re = nullptr;

        // Read the length of the name and then alloc the temporary memory.
        UInt32 len = 0;
        this->Read(&len, sizeof(UInt32));
        UInt32 lenInBytes = len * sizeof(Char);
        Char* className = (Char*)(NM_MALLOC_T(lenInBytes));
        std::memset(className, 0, lenInBytes);

        // Then read the string, assign to the string;
        this->Read(className, lenInBytes);

        // Get the class information by name.
        re = NMClassInfo::GetClassInfoByName(className);

        // Must free the temporary memory.
        NM_FREE_T(className);

        return re;
    }

    void NMArchive::WriteClass(const NMClassInfo *info)
    {
        if (info == nullptr)
        {
            NM_DEBUG_LOG("Write the class information to this archive failed, the information should not be null.");
            return;
        }

        // The class name should not be null.
        if (info->className == nullptr)
            return;

        // class name is enough to identify the class.
        // Get the size of the class first, then save the string.
        UInt32 len = sizeof(info->className);
        this->Write(&len, sizeof(UInt32));
        this->Write(info->className, sizeof(Char)* len);
    }

    NMObject* NMArchive::ReadObject(void)
    {
        NMObject* re = nullptr;

        // Read the class information from this archive.
        NMClassInfo *classRef = ReadClass();

        // If the class information is null, could not create
        // the class, must be returned.
        if (classRef == nullptr)
        {
            NM_DEBUG_LOG("The class information for NMObject is null.");
            return re;
        }

        // Create the class by class info, and then serialize it.
        re = classRef->CreateObject();
        re->Serialize(*this);

        return re;
    }

    void NMArchive::WriteObject(const NMObject *obj)
    {
        if (obj == nullptr)
        {
            NM_DEBUG_LOG("The NMObject should not be null, returned.");
            return;
        }

        // Write class information to this archive.
        NMClassInfo *info = obj->GetClassInfo();
        this->WriteClass(info);

        // Then serialize the data to this archive.
        (const_cast<NMObject*>(obj))->Serialize(*this);
    }

    void NMArchive::Flush(void)
    {
        if (mFile != nullptr)
            mFile->flush();
    }

    void NMArchive::Close(void)
    {
        if (mFile != nullptr)
            mFile->close();
    }

    NMArchive& NMArchive::operator<<(String &value)
    {
        // Write the length first;
        UInt32 len = value.length();
        this->Write(&len, sizeof(UInt32));

        // Then write the buffer.
        this->Write(value.c_str(), len * sizeof(String::value_type));
        return *this;
    }

    NMArchive& operator<<(NMArchive& ar, const NMObject* value)
    {
        ar.WriteObject(value);
        return ar;
    }

    NMArchive& NMArchive::operator<<(Int8 &value)
    {
        this->Write(&value, sizeof(Int8));
        return *this;
    }

    NMArchive& NMArchive::operator<<(UInt8 &value)
    {
        this->Write(&value, sizeof(UInt8));
        return *this;
    }

    NMArchive& NMArchive::operator<<(Int16 &value)
    {
        this->Write(&value, sizeof(Int16));
        return *this;
    }

    NMArchive& NMArchive::operator<<(UInt16 &value)
    {
        this->Write(&value, sizeof(UInt16));
        return *this;
    }

    NMArchive& NMArchive::operator<<(Int32 &value)
    {
        this->Write(&value, sizeof(Int32));
        return *this;
    }

    NMArchive& NMArchive::operator<<(UInt32 &value)
    {
        this->Write(&value, sizeof(UInt8));
        return *this;
    }

    NMArchive& NMArchive::operator<<(Float &value)
    {
        this->Write(&value, sizeof(Float));
        return *this;
    }

    NMArchive& NMArchive::operator<<(Double &value)
    {
        this->Write(&value, sizeof(Double));
        return *this;
    }

    NMArchive& NMArchive::operator>>(String &value)
    {
        // Read the length first;
        UInt32 len = 0;
        this->Read(&len, sizeof(UInt32));

        // Allocate the memory, and reset the content;
        UInt32 lenInBytes = len * sizeof(String::value_type);

        String::value_type* tmpStr = (String::value_type*)(NM_MALLOC_T(lenInBytes));
        std::memset(tmpStr, 0, lenInBytes);

        // Then read the string, assign to the string;
        this->Read(tmpStr, lenInBytes);
        value.assign(tmpStr);

        // Must free the temporary memory.
        NM_FREE_T(tmpStr);

        return *this;
    }

    NMArchive& operator>>(NMArchive& ar, NMObject *value)
    {
        value = ar.ReadObject();
        return ar;
    }

    NMArchive& NMArchive::operator>>(Int8 &value)
    {
        this->Read(&value, sizeof(Int8));
        return *this;
    }

    NMArchive& NMArchive::operator>>(UInt8 &value)
    {
        this->Read(&value, sizeof(UInt8));
        return *this;
    }

    NMArchive& NMArchive::operator>>(Int16 &value)
    {
        this->Read(&value, sizeof(Int16));
        return *this;
    }

    NMArchive& NMArchive::operator>>(UInt16 &value)
    {
        this->Read(&value, sizeof(UInt16));
        return *this;
    }

    NMArchive& NMArchive::operator>>(Int32 &value)
    {
        this->Read(&value, sizeof(Int32));
        return *this;
    }

    NMArchive& NMArchive::operator>>(UInt32 &value)
    {
        this->Read(&value, sizeof(UInt32));
        return *this;
    }

    NMArchive& NMArchive::operator>>(Float &value)
    {
        this->Read(&value, sizeof(Float));
        return *this;
    }

    NMArchive& NMArchive::operator>>(Double &value)
    {
        this->Read(&value, sizeof(Double));
        return *this;
    }

    NMArchive::NMArchive(const NMArchive &)
    {
        // Invalid operation, Should not implement.
        NM_ASSERT_MSG(false, "Invalid operation");
    }

    NMArchive& NMArchive::operator= (const NMArchive&)
    {
        // Invalid operation, Should not implement.
        NM_ASSERT_MSG(false, "Invalid operation");
        return *this;
    }
}  // namespace NightMoon

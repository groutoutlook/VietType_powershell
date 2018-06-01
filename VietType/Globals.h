// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved

#pragma once

#include "stdafx.h"

void DllAddRef();
void DllRelease();

namespace Global {

//---------------------------------------------------------------------
// extern
//---------------------------------------------------------------------
extern HINSTANCE dllInstanceHandle;

extern LONG dllRefCount;

extern CRITICAL_SECTION CS;
extern HFONT defaultlFontHandle; // Global font object we use everywhere

extern const CLSID SampleIMECLSID;
extern const CLSID SampleIMEGuidProfile;
extern const CLSID SampleIMEGuidImeModePreserveKey;
extern const CLSID SampleIMEGuidDoubleSingleBytePreserveKey;
extern const CLSID SampleIMEGuidPunctuationPreserveKey;

} // namespace Global

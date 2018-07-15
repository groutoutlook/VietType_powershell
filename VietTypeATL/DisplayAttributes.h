// Copyright (c) Dinh Ngoc Tu.
// 
// This file is part of VietType.
// 
// VietType is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// VietType is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with VietType.  If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Common.h"

namespace VietType {

extern std::tuple<GUID, std::wstring, TF_DISPLAYATTRIBUTE> const ComposingAttributeData;

class DisplayAttributeInfo :
    public CComObjectRootEx<CComSingleThreadModel>,
    public ITfDisplayAttributeInfo {
public:
    DisplayAttributeInfo();
    ~DisplayAttributeInfo();

    DECLARE_NOT_AGGREGATABLE(DisplayAttributeInfo)
    BEGIN_COM_MAP(DisplayAttributeInfo)
        COM_INTERFACE_ENTRY(ITfDisplayAttributeInfo)
    END_COM_MAP()
    DECLARE_PROTECT_FINAL_CONSTRUCT()

public:
    // Inherited via ITfDisplayAttributeInfo
    virtual HRESULT GetGUID(GUID * pguid) override;
    virtual HRESULT GetDescription(BSTR * pbstrDesc) override;
    virtual HRESULT GetAttributeInfo(TF_DISPLAYATTRIBUTE * pda) override;
    virtual HRESULT SetAttributeInfo(const TF_DISPLAYATTRIBUTE * pda) override;
    virtual HRESULT Reset(void) override;

public:
    void Initialize(GUID const& guid, std::wstring description, TF_DISPLAYATTRIBUTE attr);

private:
    GUID _guid;
    std::wstring _description;
    TF_DISPLAYATTRIBUTE _attr;
    TF_DISPLAYATTRIBUTE _attrOrig;

private:
    DISALLOW_COPY_AND_ASSIGN(DisplayAttributeInfo);
};

}

// Copyright (c) 2018 Dinh Ngoc Tu.
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
namespace VirtualDocument {

_Check_return_ HRESULT GetVirtualDocumentMgr(_In_ ITfDocumentMgr* dim, _COM_Outptr_ ITfDocumentMgr** pdim);
_Check_return_ HRESULT GetVirtualDocumentContext(_In_ ITfContext* context, _COM_Outptr_ ITfContext** pContext);

}
}

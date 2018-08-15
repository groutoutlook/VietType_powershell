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

#include "TextEditSink.h"
#include "CompositionManager.h"
#include "EngineController.h"

namespace VietType {

STDMETHODIMP TextEditSink::OnEndEdit(__RPC__in_opt ITfContext* pic, _In_ TfEditCookie ecReadOnly, __RPC__in_opt ITfEditRecord* pEditRecord) {
    DBG_DPRINT(L"%s", L"");

    return S_OK;
}

_Check_return_ HRESULT TextEditSink::Initialize(_In_ ITfDocumentMgr* documentMgr, _In_ CompositionManager* compMgr, _In_ EngineController* controller) {
    HRESULT hr;

    _compMgr = compMgr;
    _controller = controller;

    hr = _textEditSinkAdvisor.Unadvise();
    DBG_HRESULT_CHECK(hr, L"%s", L"_textEditSinkAdvisor.Unadvise failed");

    if (!documentMgr) {
        // caller just wanted to clear the previous sink
        return S_OK;
    }

    hr = documentMgr->GetTop(&_editContext);
    HRESULT_CHECK_RETURN(hr, L"%s", L"documentMgr->GetTop failed");

    if (!_editContext) {
        // empty document, no sink possible
        return S_OK;
    }

    CComPtr<ITfSource> source;
    hr = _editContext->QueryInterface(&source);
    HRESULT_CHECK_RETURN(hr, L"%s", L"_editContext->QueryInterface failed");

    hr = _textEditSinkAdvisor.Advise(source, this);
    HRESULT_CHECK_RETURN(hr, L"%s", L"_textEditSinkAdvisor.Advise failed");

    return S_OK;
}

HRESULT TextEditSink::Uninitialize() {
    HRESULT hr;

    hr = _textEditSinkAdvisor.Unadvise();
    DBG_HRESULT_CHECK(hr, L"%s", L"_textEditSinkAdvisor.Unadvise failed");

    _editContext.Release();

    _controller.Release();
    _compMgr.Release();

    return S_OK;
}

}
